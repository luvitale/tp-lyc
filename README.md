# Trabajo Práctico de Lenguajes y Compiladores

## Tradukaten


[Tradukaten](https://github.com/luvitale/tradukaten) (del esperanto Traduka Kateno, cadena de traducciones) es un compilador hecho para la materia de [Lenguajes y Compiladores](https://polr.luvitale.net/unlam-languages-and-compilers) de la carrera de [Ingeniería en Informática](https://polr.luvitale.net/unlam-informatics-engineering) de la [Universidad Nacional de La Matanza](https://www.unlam.edu.ar).

> [![compilador](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ef/CompilationScheme-Spanish.png/300px-CompilationScheme-Spanish.png)](https://es.wikipedia.org/wiki/Compilador)

## [Primera entrega](Primera)

* [Compile.bat](Primera/Compile.bat)
* [Execute.bat](Primera/Execute.bat)

## [Segunda entrega](Segunda)

* [Compile.bat](Segunda/Compile.bat)
* [Execute.bat](Segunda/Execute.bat)

## [Tercera entrega](Tercera)

* [Compile.bat](Tercera/Compile.bat)
* [Execute.bat](Tercera/Execute.bat)
* [Grupo15.bat](Tercera/Grupo15.bat)

## Instalar dependencias

* [GCC](https://gcc.gnu.org/)
* [Flex](https://github.com/westes/flex)
* [Bison](https://www.gnu.org/software/bison/)

### APT

```
sudo apt-get update
sudo apt-get -y install flex bison
```

### Chocolatey

```
choco upgrade chocolatey
choco install --verbose mingw make winflexbison3
```

## Compilar

### Makefile

```
make
```

### Manualmente

```
flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c rpn.c utils/*.c -o tradukaten.exe -fcommon
```

O

```
flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c rpn.c utils/*.c -o tradukaten.app -fcommon
```

### Test

```
make test
```

### Ensamblar

```
tasm Final.asm
tlink /3 /x /v Final.obj numbers.obj
pause
Final.exe
```
