# Trabajo Práctico de Lenguajes y Compiladores

## Tradukaten


[Tradukaten](https://github.com/luvitale/tradukaten) (del esperanto Traduka Kateno, cadena de traducciones) es un compilador hecho para la materia de [Lenguajes y Compiladores](https://polr.luvitale.net/unlam-languages-and-compilers) de la carrera de [Ingeniería en Informática](https://polr.luvitale.net/unlam-informatics-engineering) de la [Universidad Nacional de La Matanza](https://www.unlam.edu.ar).

> [![compilador](https://upload.wikimedia.org/wikipedia/commons/thumb/e/ef/CompilationScheme-Spanish.png/300px-CompilationScheme-Spanish.png)](https://es.wikipedia.org/wiki/Compilador)

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
gcc lex.yy.c y.tab.c ts.c queue.c rpn.c stack.c -o tradukaten.exe -fcommon
```

O

```
flex -o lex.yy.c Lexico.l
bison -dyv Sintactico.y
gcc lex.yy.c y.tab.c ts.c queue.c rpn.c stack.c -o tradukaten.app -fcommon
```

### Test

```
make test
```
