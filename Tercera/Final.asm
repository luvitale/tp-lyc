include macros2.asm
include number.asm

.MODEL LARGE
.386
.STACK 200h

.DATA
; Table of symbols
@act                                     dd    ?                                                                                                      
@result_121                              dd    ?                                                                                                      
@result_26                               dd    ?                                                                                                      
@result_27                               dd    ?                                                                                                      
@result_32                               dd    ?                                                                                                      
@result_6                                dd    ?                                                                                                      
@result_85                               dd    ?                                                                                                      
_i_0                                     dd    0                                                                                                      
_i_1                                     dd    1                                                                                                      
_i_10                                    dd    10                                                                                                     
_i_2                                     dd    2                                                                                                      
_i_3                                     dd    3                                                                                                      
_i_30                                    dd    30                                                                                                     
_r_0_000000                              dd    0.000000                                                                                               
_r_10_000000                             dd    10.000000                                                                                              
_r_1_140000                              dd    1.140000                                                                                               
_r_30_000000                             dd    30.000000                                                                                              
_s_Enigu_nomon@_                         db    "Enigu nomon: "                                                                                        , '$', 13 dup (?)
_s_Korekte                               db    "Korekte"                                                                                              , '$', 7 dup (?)
_s_Luno                                  db    "Luno"                                                                                                 , '$', 4 dup (?)
_s_Marso                                 db    "Marso"                                                                                                , '$', 5 dup (?)
_s_Saluton_                              db    "Saluton "                                                                                             , '$', 8 dup (?)
_s_Saluton_Mondo                         db    "Saluton Mondo"                                                                                        , '$', 13 dup (?)
_s_Tero                                  db    "Tero"                                                                                                 , '$', 4 dup (?)
_s_akum_10_but_total_30                  db    "akum 10 but total 30"                                                                                 , '$', 20 dup (?)
_s_akum_10_but_total_not                 db    "akum 10 but total not"                                                                                , '$', 21 dup (?)
_s_total_and_akum_equal_10               db    "total and akum equal 10"                                                                              , '$', 23 dup (?)
akum                                     dd    ?                                                                                                      
nomo                                     db    ""                                                                                                     , '$', 100 dup (?)
rezult                                   db    ""                                                                                                     , '$', 100 dup (?)
total                                    dd    ?                                                                                                      

.CODE

START:
	MOV AX, @DATA
	MOV DS, AX
	MOV es, AX
	FINIT ; Initialize coprocessor

	; Assign to variable
	FLD _i_0
	FSTP akum

	FLD akum
	FLD _i_1
	FADD ; Add
	FSTP @result_6 ; Assign result of operation

	; Assign to variable
	FLD @result_6
	FSTP akum

	; Assign to variable
	FLD _r_0_000000
	FSTP total


@ET12:
	; Compare
	FLD total
	FCOMP _r_0_000000
	FSTSW ax
	SAHF
	JNE @ET37 ; Jump if not equal

	; Compare
	FLD akum
	FCOMP _i_1
	FSTSW ax
	SAHF
	JNAE @ET37 ; Jump if not above or equal

	FLD _i_2
	FLD _r_1_140000
	FADD ; Add
	FSTP @result_26 ; Assign result of operation

	FLD akum
	FLD @result_26
	FMUL ; Multiplication
	FSTP @result_27 ; Assign result of operation

	; Assign to variable
	FLD @result_27
	FSTP total

	FLD akum
	FLD _i_1
	FADD ; Add
	FSTP @result_32 ; Assign result of operation

	; Assign to variable
	FLD @result_32
	FSTP akum

	displayString _s_Korekte ; Print string

@ET37:
	newLine
	newLine

@ET41:
	; Compare
	FLD akum
	FCOMP _i_10
	FSTSW ax
	SAHF
	JNB @ET52 ; Jump if not below

	; Compare
	FLD akum
	FCOMP _i_30
	FSTSW ax
	SAHF
	JNAE @ET77 ; Jump if not above or equal


@ET52:
	; Compare
	FLD total
	FCOMP _r_10_000000
	FSTSW ax
	SAHF
	JNE @ET63 ; Jump if not equal

	; Assign string to variable
	MOV SI, OFFSET _s_total_and_akum_equal_10
	MOV DI, OFFSET rezult
	CALL strcpy

	JMP @ET77 ; Inconditional jump


@ET63:
	; Compare
	FLD total
	FCOMP _r_30_000000
	FSTSW ax
	SAHF
	JNE @ET74 ; Jump if not equal

	; Assign string to variable
	MOV SI, OFFSET _s_akum_10_but_total_30
	MOV DI, OFFSET rezult
	CALL strcpy

	JMP @ET77 ; Inconditional jump


@ET74:
	; Assign string to variable
	MOV SI, OFFSET _s_akum_10_but_total_not
	MOV DI, OFFSET rezult
	CALL strcpy


@ET77:
	; Compare
	FLD akum
	FCOMP _i_10
	FSTSW ax
	SAHF
	JNBE @ET90 ; Jump if not below or equal

	FLD akum
	FLD _i_2
	FADD ; Add
	FSTP @result_85 ; Assign result of operation

	; Assign to variable
	FLD @result_85
	FSTP akum

	JMP @ET77 ; Inconditional jump


@ET90:
	; Assign to variable
	FLD _i_1
	FSTP @act


@ET93:

@ET94:
	; Assign string to variable
	MOV SI, OFFSET _s_Tero
	MOV DI, OFFSET nomo
	CALL strcpy

	; Compare
	FLD @act
	FCOMP _i_1
	FSTSW ax
	SAHF
	JE @ET113 ; Jump if equal

	; Assign string to variable
	MOV SI, OFFSET _s_Luno
	MOV DI, OFFSET nomo
	CALL strcpy

	; Compare
	FLD @act
	FCOMP _i_2
	FSTSW ax
	SAHF
	JE @ET113 ; Jump if equal

	; Assign string to variable
	MOV SI, OFFSET _s_Marso
	MOV DI, OFFSET nomo
	CALL strcpy


@ET113:
	displayString _s_Saluton_ ; Print string
	displayString nomo ; Print string
	newLine
	FLD @act
	FLD _i_1
	FADD ; Add
	FSTP @result_121 ; Assign result of operation

	; Assign to variable
	FLD @result_121
	FSTP @act

	; Compare
	FLD @act
	FCOMP _i_3
	FSTSW ax
	SAHF
	JNA @ET94 ; Jump if not above

	displayString _s_Saluton_Mondo ; Print string
	newLine
	newLine
	displayString _s_Enigu_nomon@_ ; Print string
	getString nomo ; Get string
	newLine
	displayString _s_Saluton_ ; Print string
	displayString nomo ; Print string

; End
@ET145:

FINAL:
	MOV AX, 4C00h ; Exit
	INT 21h ; Send interrupt
	FFREE
	strlen proc near
		mov bx, 0
		@strl01:
		cmp BYTE PTR [si+bx],'$'
		je @strend
		inc bx
		jmp @strl01
		@strend:
		ret
	strlen endp
	strcpy proc near
		call strlen
		cmp bx , 100
		jle @ok_size_copy
		mov bx , 100
		@ok_size_copy:
		mov cx , bx
		cld
		rep movsb
		mov al , '$'
		mov byte ptr[di],al
		ret
	strcpy endp

END START ;