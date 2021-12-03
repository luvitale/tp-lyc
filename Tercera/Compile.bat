flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c rpn.c utils/*.c -o tradukaten.exe -fcommon
mv tradukaten.exe Grupo15.exe