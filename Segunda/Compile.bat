flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c queue.c rpn.c stack.c -o tradukaten.exe -fcommon
mv tradukaten.exe Segunda.exe