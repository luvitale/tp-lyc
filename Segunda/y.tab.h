/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    id = 258,                      /* id  */
    int_constant = 259,            /* int_constant  */
    real_constant = 260,           /* real_constant  */
    string_constant = 261,         /* string_constant  */
    op_assign = 262,               /* op_assign  */
    op_sum = 263,                  /* op_sum  */
    op_sub = 264,                  /* op_sub  */
    op_mult = 265,                 /* op_mult  */
    op_div = 266,                  /* op_div  */
    separator = 267,               /* separator  */
    op_eq = 268,                   /* op_eq  */
    op_lt = 269,                   /* op_lt  */
    op_le = 270,                   /* op_le  */
    op_gt = 271,                   /* op_gt  */
    op_ge = 272,                   /* op_ge  */
    op_ne = 273,                   /* op_ne  */
    op_and = 274,                  /* op_and  */
    op_or = 275,                   /* op_or  */
    op_if = 276,                   /* op_if  */
    op_else = 277,                 /* op_else  */
    op_endif = 278,                /* op_endif  */
    op_while = 279,                /* op_while  */
    op_endwhile = 280,             /* op_endwhile  */
    open_parenthesis = 281,        /* open_parenthesis  */
    close_parenthesis = 282,       /* close_parenthesis  */
    op_dim = 283,                  /* op_dim  */
    op_as = 284,                   /* op_as  */
    open_bracket = 285,            /* open_bracket  */
    close_bracket = 286,           /* close_bracket  */
    comma = 287,                   /* comma  */
    int_type = 288,                /* int_type  */
    real_type = 289,               /* real_type  */
    string_type = 290,             /* string_type  */
    op_display = 291,              /* op_display  */
    op_get = 292,                  /* op_get  */
    fun_long = 293,                /* fun_long  */
    op_in = 294,                   /* op_in  */
    op_do = 295                    /* op_do  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define id 258
#define int_constant 259
#define real_constant 260
#define string_constant 261
#define op_assign 262
#define op_sum 263
#define op_sub 264
#define op_mult 265
#define op_div 266
#define separator 267
#define op_eq 268
#define op_lt 269
#define op_le 270
#define op_gt 271
#define op_ge 272
#define op_ne 273
#define op_and 274
#define op_or 275
#define op_if 276
#define op_else 277
#define op_endif 278
#define op_while 279
#define op_endwhile 280
#define open_parenthesis 281
#define close_parenthesis 282
#define op_dim 283
#define op_as 284
#define open_bracket 285
#define close_bracket 286
#define comma 287
#define int_type 288
#define real_type 289
#define string_type 290
#define op_display 291
#define op_get 292
#define fun_long 293
#define op_in 294
#define op_do 295

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 130 "Sintactico.y"

  int int_val;
  double real_val;
  char *str_val;

#line 153 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
