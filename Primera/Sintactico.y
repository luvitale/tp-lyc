%{
  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "ts.h"

  #define COLOR_RED "\033[1;31m"
  #define COLOR_RESET "\033[0m"

  int lineno;

  int yystopparser = 0;

  FILE *yyin;

  char *yyltext;
  char *yytext;

  int yylex();
  int yyerror(char *);

  void show_help(char *);
%}

%union {
  int int_val;
  double real_val;
  char *str_val;
}

%token id
%token int_constant real_constant
%token string_constant

%token op_assign
%token op_sum op_sub op_mult op_div
%token separator

%token op_eq op_lt op_le op_gt op_ge op_ne
%token op_and op_or

%token op_if op_endif
%token op_while op_endwhile
%token open_parenthesis close_parenthesis

%token op_dim op_as
%token open_dec close_dec
%token dec_separator
%token int_type real_type string_type

%token op_display op_get

%token fun_long
%token op_in op_do

%%
PROGRAM: CODE;

CODE: CODE BLOCK | BLOCK;

BLOCK: DECLARATION separator
| ASSIGNMENT separator
| INPUT separator
| OUTPUT separator
| LENGTH separator
| DECISION
| ITERATION;

LENGTH: fun_long open_parenthesis LIST close_parenthesis {
  printf("long(LIST);\n");
};

LIST: open_dec ITEMS close_dec;

ITEMS: ITEMS dec_separator ITEM | ITEM;

ITEM: CONSTANT | id;

INPUT: op_get id {
  printf("get id;\n");
};

OUTPUT: op_display EXPRESSION {
  printf("display EXPRESSION;\n");
};

ASSIGNMENT: id op_assign EXPRESSION {
  printf("id <- EXPRESSION;\n");
} | id op_assign ASSIGNMENT {
  printf("id <- ASSIGNMENT;\n");
};

DECISION: op_if open_parenthesis CONDITION close_parenthesis CODE op_endif {
  printf("if ( CONDITION ) CODE endif\n");
};

CONDITION: CONDITION op_and COMPARATION {
  printf("CONDITION && COMPARATION\n");
} | CONDITION op_or COMPARATION {
  printf("CONDITION || COMPARATION\n");
} | open_parenthesis CONDITION close_parenthesis {
  printf("( CONDITION )\n");
} | COMPARATION;

COMPARATION: EXPRESSION COMPARATOR EXPRESSION {
  printf("EXPRESSION COMPARATOR EXPRESSION\n");
};

COMPARATOR: op_eq | op_lt | op_le | op_gt | op_ge | op_ne;

ITERATION: op_while open_parenthesis CONDITION close_parenthesis CODE op_endwhile {
  printf("while ( CONDITION ) CODE endwhile\n");
} | op_while id op_in LIST op_do CODE op_endwhile {
  printf("while id in LIST do CODE endwhile\n");
};

DECLARATION: op_dim open_dec VARIABLES close_dec op_as open_dec DATATYPES close_dec {
  printf("dim [VARIABLES] as [DATATYPES];\n");
};

EXPRESSION: EXPRESSION op_sum TERM
| EXPRESSION op_sub TERM
| TERM;

TERM: TERM op_mult FACTOR
| TERM op_div FACTOR
| FACTOR;

FACTOR: open_parenthesis EXPRESSION close_parenthesis
| LENGTH
| id
| CONSTANT;

VARIABLES: VARIABLES dec_separator id
| id;
DATATYPES: DATATYPES dec_separator DATATYPE
| DATATYPE;

DATATYPE: int_type | real_type | string_type;

CONSTANT: int_constant | real_constant | string_constant;
%%

int main(int argc,char *argv[]) {
  const char* filename = argv[1];

  if( filename && (
      strcmp(filename, "-h") == 0 || strcmp(filename, "--help") == 0
    )
  ) {
    show_help(argv[0]);

    return EXIT_SUCCESS;
  }

  FILE* arg_file = fopen(filename, "rt");

  if (arg_file == NULL) {
    show_help(argv[0]);

    printf("File cannot be opened: %s\n", filename);
    printf("Using standard input\n\n");
  }
  else {
    yyin = arg_file;
  }

  yyparse();
  assignConstantValue();
  saveFileTS();

  fclose(yyin);

  return EXIT_SUCCESS;
}

void show_help(char* app_name) {
  printf("%s [code_file]\n\n", app_name);
  printf("Example: %s %s\n\n", app_name, "./tests/prueba.txt");
}

int yyerror(char *error) {
  fprintf(stderr, COLOR_RED "\nline %d: %s\n" COLOR_RESET, lineno, error);
  fclose(yyin);
  exit(1);
}