flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c -o tradukaten.exe -fcommon
mv tradukaten.exe Primera.exe