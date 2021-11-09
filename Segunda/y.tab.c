/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "Sintactico.y"

  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include "ts.h"
  #include "queue.h"
  #include "stack.h"
  #include "rpn.h"

  #define COLOR_RED "\033[1;31m"
  #define COLOR_RESET "\033[0m"

  #define FALSE 0
  #define TRUE 1

  int lineno;

  int yystopparser = 0;

  FILE *yyin;

  char *yyltext;
  char *yytext;

  // Rules
  char *rule[56] = {
    "R0. PROGRAM -> CODE",
    "R1. CODE -> CODE BLOCK",
    "R2. CODE -> BLOCK",
    "R3. BLOCK -> DECLARATION;",
    "R4. BLOCK -> ASSIGNMENT;",
    "R5. BLOCK -> INPUT;",
    "R6. BLOCK -> OUTPUT;",
    "R7. BLOCK -> LENGTH;",
    "R8. BLOCK -> DECISION",
    "R9. BLOCK -> ITERATION",
    "R10. DECLARATION -> dim [VARIABLES] as [DATATYPES]",
    "R11. VARIABLES -> VARIABLES, id",
    "R12. VARIABLES -> id",
    "R13. DATATYPES -> DATATYPES, DATATYPE",
    "R14. DATATYPES -> DATATYPE",
    "R15. DATATYPE -> int_type",
    "R16. DATATYPE -> real_type",
    "R17. DATATYPE -> string_type",
    "R18. ASSIGNMENT -> id := ASSIGNMENT",
    "R19. ASSIGNMENT -> id := EXPRESSION",
    "R20. EXPRESSION -> EXPRESSION + TERM",
    "R21. EXPRESSION -> EXPRESSION - TERM",
    "R22. EXPRESSION -> TERM",
    "R23. TERM -> TERM * FACTOR",
    "R24. TERM -> TERM / FACTOR",
    "R25. TERM -> FACTOR",
    "R26. FACTOR -> ( EXPRESSION )",
    "R27. FACTOR -> id",
    "R28. FACTOR -> CONSTANT",
    "R29. FACTOR -> LENGTH",
    "R30. CONSTANT -> int_constant",
    "R31. CONSTANT -> real_constant",
    "R32. CONSTANT -> string_constant",
    "R33. LENGTH -> long ( LIST )",
    "R34. LIST -> [ ITEMS ]",
    "R35. ITEMS -> ITEMS, ITEM",
    "R36. ITEMS -> ITEM",
    "R37. ITEM -> CONSTANT",
    "R38. ITEM -> id",
    "R39. INPUT -> get id",
    "R40. OUTPUT -> display EXPRESSION",
    "R41. DECISION -> IF_EVALUATOR CODE endif",
    "R41. DECISION -> IF_EVALUATOR CODE else CODE endif",
    "R42. CONDITION -> CONDITION && comparator",
    "R43. IF_EVALUATOR -> if ( CONDITION )",
    "R44. CONDITION -> CONDITION || comparator",
    "R45. CONDITION -> comparator",
    "R46. comparator -> ITEM COMPARATOR ITEM",
    "R47. COMPARATOR -> ==",
    "R48. COMPARATOR -> <",
    "R49. COMPARATOR -> <=",
    "R50. COMPARATOR -> >",
    "R51. COMPARATOR -> >=",
    "R52. COMPARATOR -> !=",
    "R53. ITERATION -> while ( CONDITION ) CODE endwhile",
    "R54. ITERATION -> while id in LIST do CODE endwhile",
  };

  // Symbol Table
  list_t symbol_table;

  // Actual Item
  char actual_item[30];
  char identifier[30];

  // Reverse Polish Notation
  rpn_t *rpn;

  // Counters
  unsigned int item_quantity;

  // Util variables
  int is_while_loop = FALSE;
  char logical_operator[3];
  char comparator[3];
  char comparator1[3];
  char comparator2[3];
  char branch[3];
  int first_condition_jump_cell;
  int show = TRUE;

  // Queues
  queue_str_t* variable_queue;
  queue_str_t* datatype_queue;
  queue_str_t* branch_queue;
  queue_str_t* while_queue;

  // Stack
  stack_str_t* cell_stack;
  stack_str_t* is_and_stack;

  int yylex();
  int yyerror(char *);

  void show_help(char *);

  char *delete_quotes(char *);

  char *get_corresponding_branch(char *);
  char *get_opposite_branch(char *);

#line 200 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
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

#line 339 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_id = 3,                         /* id  */
  YYSYMBOL_int_constant = 4,               /* int_constant  */
  YYSYMBOL_real_constant = 5,              /* real_constant  */
  YYSYMBOL_string_constant = 6,            /* string_constant  */
  YYSYMBOL_op_assign = 7,                  /* op_assign  */
  YYSYMBOL_op_sum = 8,                     /* op_sum  */
  YYSYMBOL_op_sub = 9,                     /* op_sub  */
  YYSYMBOL_op_mult = 10,                   /* op_mult  */
  YYSYMBOL_op_div = 11,                    /* op_div  */
  YYSYMBOL_separator = 12,                 /* separator  */
  YYSYMBOL_op_eq = 13,                     /* op_eq  */
  YYSYMBOL_op_lt = 14,                     /* op_lt  */
  YYSYMBOL_op_le = 15,                     /* op_le  */
  YYSYMBOL_op_gt = 16,                     /* op_gt  */
  YYSYMBOL_op_ge = 17,                     /* op_ge  */
  YYSYMBOL_op_ne = 18,                     /* op_ne  */
  YYSYMBOL_op_and = 19,                    /* op_and  */
  YYSYMBOL_op_or = 20,                     /* op_or  */
  YYSYMBOL_op_if = 21,                     /* op_if  */
  YYSYMBOL_op_else = 22,                   /* op_else  */
  YYSYMBOL_op_endif = 23,                  /* op_endif  */
  YYSYMBOL_op_while = 24,                  /* op_while  */
  YYSYMBOL_op_endwhile = 25,               /* op_endwhile  */
  YYSYMBOL_open_parenthesis = 26,          /* open_parenthesis  */
  YYSYMBOL_close_parenthesis = 27,         /* close_parenthesis  */
  YYSYMBOL_op_dim = 28,                    /* op_dim  */
  YYSYMBOL_op_as = 29,                     /* op_as  */
  YYSYMBOL_open_bracket = 30,              /* open_bracket  */
  YYSYMBOL_close_bracket = 31,             /* close_bracket  */
  YYSYMBOL_comma = 32,                     /* comma  */
  YYSYMBOL_int_type = 33,                  /* int_type  */
  YYSYMBOL_real_type = 34,                 /* real_type  */
  YYSYMBOL_string_type = 35,               /* string_type  */
  YYSYMBOL_op_display = 36,                /* op_display  */
  YYSYMBOL_op_get = 37,                    /* op_get  */
  YYSYMBOL_fun_long = 38,                  /* fun_long  */
  YYSYMBOL_op_in = 39,                     /* op_in  */
  YYSYMBOL_op_do = 40,                     /* op_do  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_PROGRAM = 42,                   /* PROGRAM  */
  YYSYMBOL_CODE = 43,                      /* CODE  */
  YYSYMBOL_BLOCK = 44,                     /* BLOCK  */
  YYSYMBOL_DECLARATION = 45,               /* DECLARATION  */
  YYSYMBOL_VARIABLES = 46,                 /* VARIABLES  */
  YYSYMBOL_DATATYPES = 47,                 /* DATATYPES  */
  YYSYMBOL_DATATYPE = 48,                  /* DATATYPE  */
  YYSYMBOL_ASSIGNMENT = 49,                /* ASSIGNMENT  */
  YYSYMBOL_EXPRESSION = 50,                /* EXPRESSION  */
  YYSYMBOL_TERM = 51,                      /* TERM  */
  YYSYMBOL_FACTOR = 52,                    /* FACTOR  */
  YYSYMBOL_CONSTANT = 53,                  /* CONSTANT  */
  YYSYMBOL_LENGTH = 54,                    /* LENGTH  */
  YYSYMBOL_LIST = 55,                      /* LIST  */
  YYSYMBOL_56_1 = 56,                      /* $@1  */
  YYSYMBOL_ITEMS = 57,                     /* ITEMS  */
  YYSYMBOL_ITEM = 58,                      /* ITEM  */
  YYSYMBOL_INPUT = 59,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 60,                    /* OUTPUT  */
  YYSYMBOL_DECISION = 61,                  /* DECISION  */
  YYSYMBOL_62_2 = 62,                      /* $@2  */
  YYSYMBOL_IF_EVALUATOR = 63,              /* IF_EVALUATOR  */
  YYSYMBOL_CONDITION = 64,                 /* CONDITION  */
  YYSYMBOL_65_3 = 65,                      /* $@3  */
  YYSYMBOL_66_4 = 66,                      /* $@4  */
  YYSYMBOL_COMPARATION = 67,               /* COMPARATION  */
  YYSYMBOL_COMPARATOR = 68,                /* COMPARATOR  */
  YYSYMBOL_ITERATION = 69,                 /* ITERATION  */
  YYSYMBOL_70_5 = 70,                      /* $@5  */
  YYSYMBOL_71_6 = 71,                      /* $@6  */
  YYSYMBOL_72_7 = 72,                      /* $@7  */
  YYSYMBOL_73_8 = 73                       /* $@8  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  36
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   140

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  119

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   295


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   165,   165,   167,   169,   173,   175,   177,   179,   181,
     183,   185,   190,   211,   218,   227,   229,   233,   238,   243,
     251,   258,   267,   271,   275,   279,   283,   287,   291,   293,
     298,   300,   304,   315,   326,   340,   349,   349,   357,   365,
     375,   377,   388,   394,   401,   420,   420,   450,   470,   470,
     495,   495,   528,   532,   536,   540,   544,   548,   552,   556,
     563,   568,   563,   610,   612,   610
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "id", "int_constant",
  "real_constant", "string_constant", "op_assign", "op_sum", "op_sub",
  "op_mult", "op_div", "separator", "op_eq", "op_lt", "op_le", "op_gt",
  "op_ge", "op_ne", "op_and", "op_or", "op_if", "op_else", "op_endif",
  "op_while", "op_endwhile", "open_parenthesis", "close_parenthesis",
  "op_dim", "op_as", "open_bracket", "close_bracket", "comma", "int_type",
  "real_type", "string_type", "op_display", "op_get", "fun_long", "op_in",
  "op_do", "$accept", "PROGRAM", "CODE", "BLOCK", "DECLARATION",
  "VARIABLES", "DATATYPES", "DATATYPE", "ASSIGNMENT", "EXPRESSION", "TERM",
  "FACTOR", "CONSTANT", "LENGTH", "LIST", "$@1", "ITEMS", "ITEM", "INPUT",
  "OUTPUT", "DECISION", "$@2", "IF_EVALUATOR", "CONDITION", "$@3", "$@4",
  "COMPARATION", "COMPARATOR", "ITERATION", "$@5", "$@6", "$@7", "$@8", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295
};
#endif

#define YYPACT_NINF (-53)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      88,    -5,     5,    34,    12,     3,    41,    21,    50,    88,
     -53,    43,    65,    67,    76,    78,   -53,    88,   -53,     7,
      70,    27,    66,    80,   -53,   -53,   -53,   -53,     3,     6,
      54,   -53,   -53,   -53,   -53,    73,   -53,   -53,   -53,   -53,
     -53,   -53,   -53,     2,    -5,   -53,     6,   -53,   -53,   104,
      69,    49,   -53,    70,   -53,    68,     8,     3,     3,     3,
       3,   -53,    81,   -53,   -53,   -53,   -53,   -53,   -53,   -53,
     -53,    70,   -53,   -53,   -53,    73,    96,    98,   127,   -53,
      54,    54,   -53,   -53,    70,   -53,    88,   -53,    70,    70,
      95,   -53,   106,   -53,    75,   -53,    25,   -53,   -53,   -53,
      88,   -13,   -53,    70,   -53,    88,    57,   -53,   -53,   -53,
      79,   -53,   -53,    77,   -53,   -53,   -13,   -53,   -53
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,    60,     0,     0,     0,     0,     0,     2,
       4,     0,     0,     0,     0,     0,    10,     0,    11,     0,
       0,     0,     0,     0,    29,    32,    33,    34,     0,    43,
      24,    27,    30,    31,    42,     0,     1,     3,     5,     6,
       7,     8,     9,     0,    29,    20,    21,    41,    40,     0,
       0,    52,    63,     0,    14,     0,     0,     0,     0,     0,
       0,    36,     0,    45,    44,    54,    55,    56,    57,    58,
      59,     0,    47,    48,    50,     0,     0,     0,     0,    28,
      22,    23,    25,    26,     0,    35,     0,    53,     0,     0,
       0,    61,     0,    13,     0,    39,     0,    49,    51,    64,
       0,     0,    37,     0,    46,     0,     0,    17,    18,    19,
       0,    16,    38,     0,    62,    12,     0,    65,    15
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -53,   -53,   -16,    -9,   -53,   -53,   -53,    22,   118,    24,
      71,    72,   -17,    -1,    64,   -53,   -53,   -52,   -53,   -53,
     -53,   -53,   -53,    87,   -53,   -53,    45,   -53,   -53,   -53,
     -53,   -53,   -53
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    11,    55,   110,   111,    12,    29,
      30,    31,    32,    13,    62,    84,    94,    49,    14,    15,
      16,    86,    17,    50,    88,    89,    51,    71,    18,    22,
     100,    75,   105
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      37,    43,    19,    48,    33,     1,    24,    25,    26,    27,
      44,    25,    26,    27,    57,    58,    57,    58,    33,    87,
     107,   108,   109,     2,    63,    64,     3,    33,     1,    28,
       4,    20,    95,    28,    37,    79,    48,    21,     5,     6,
       7,     7,    23,    46,    34,     7,     2,    35,   104,     3,
      36,   112,    56,     4,    48,    38,    33,    33,    33,    33,
       1,     5,     6,     7,    59,    60,    52,    48,    73,    74,
      96,    48,    48,    47,    25,    26,    27,    39,     2,    40,
       1,     3,   114,    54,   106,     4,    48,    37,    41,   113,
      42,     1,    53,     5,     6,     7,    72,    37,     2,    77,
      78,     3,   117,    61,    37,     4,   102,   103,    85,     2,
     115,   116,     3,     5,     6,     7,     4,    65,    66,    67,
      68,    69,    70,    91,     5,     6,     7,    92,    80,    81,
      93,    82,    83,    97,    98,    99,   101,    45,   118,    90,
      76
};

static const yytype_int8 yycheck[] =
{
       9,    17,     7,    20,     5,     3,     3,     4,     5,     6,
       3,     4,     5,     6,     8,     9,     8,     9,    19,    71,
      33,    34,    35,    21,    22,    23,    24,    28,     3,    26,
      28,    26,    84,    26,    43,    27,    53,     3,    36,    37,
      38,    38,    30,    19,     3,    38,    21,    26,    23,    24,
       0,   103,    28,    28,    71,    12,    57,    58,    59,    60,
       3,    36,    37,    38,    10,    11,    39,    84,    19,    20,
      86,    88,    89,     3,     4,     5,     6,    12,    21,    12,
       3,    24,    25,     3,   100,    28,   103,    96,    12,   105,
      12,     3,    26,    36,    37,    38,    27,   106,    21,    31,
      32,    24,    25,    30,   113,    28,    31,    32,    27,    21,
      31,    32,    24,    36,    37,    38,    28,    13,    14,    15,
      16,    17,    18,    27,    36,    37,    38,    29,    57,    58,
       3,    59,    60,    88,    89,    40,    30,    19,   116,    75,
      53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    21,    24,    28,    36,    37,    38,    42,    43,
      44,    45,    49,    54,    59,    60,    61,    63,    69,     7,
      26,     3,    70,    30,     3,     4,     5,     6,    26,    50,
      51,    52,    53,    54,     3,    26,     0,    44,    12,    12,
      12,    12,    12,    43,     3,    49,    50,     3,    53,    58,
      64,    67,    39,    26,     3,    46,    50,     8,     9,    10,
      11,    30,    55,    22,    23,    13,    14,    15,    16,    17,
      18,    68,    27,    19,    20,    72,    64,    31,    32,    27,
      51,    51,    52,    52,    56,    27,    62,    58,    65,    66,
      55,    27,    29,     3,    57,    58,    43,    67,    67,    40,
      71,    30,    31,    32,    23,    73,    43,    33,    34,    35,
      47,    48,    58,    43,    25,    31,    32,    25,    48
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    44,
      44,    44,    45,    46,    46,    47,    47,    48,    48,    48,
      49,    49,    50,    50,    50,    51,    51,    51,    52,    52,
      52,    52,    53,    53,    53,    54,    56,    55,    57,    57,
      58,    58,    59,    60,    61,    62,    61,    63,    65,    64,
      66,    64,    64,    67,    68,    68,    68,    68,    68,    68,
      70,    71,    69,    72,    73,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     2,     2,     2,     2,     2,
       1,     1,     8,     3,     1,     3,     1,     1,     1,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     3,     1,
       1,     1,     1,     1,     1,     4,     0,     4,     3,     1,
       1,     1,     2,     2,     3,     0,     6,     4,     0,     4,
       0,     4,     1,     3,     1,     1,     1,     1,     1,     1,
       0,     0,     8,     0,     0,     9
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 3: /* CODE: CODE BLOCK  */
#line 167 "Sintactico.y"
                 {
  puts(rule[1]);
}
#line 1475 "y.tab.c"
    break;

  case 4: /* CODE: BLOCK  */
#line 169 "Sintactico.y"
          {
  puts(rule[2]);
}
#line 1483 "y.tab.c"
    break;

  case 5: /* BLOCK: DECLARATION separator  */
#line 173 "Sintactico.y"
                             {
  puts(rule[3]);
}
#line 1491 "y.tab.c"
    break;

  case 6: /* BLOCK: ASSIGNMENT separator  */
#line 175 "Sintactico.y"
                         {
  puts(rule[4]);
}
#line 1499 "y.tab.c"
    break;

  case 7: /* BLOCK: LENGTH separator  */
#line 177 "Sintactico.y"
                     {
  puts(rule[5]);
}
#line 1507 "y.tab.c"
    break;

  case 8: /* BLOCK: INPUT separator  */
#line 179 "Sintactico.y"
                    {
  puts(rule[6]);
}
#line 1515 "y.tab.c"
    break;

  case 9: /* BLOCK: OUTPUT separator  */
#line 181 "Sintactico.y"
                     {
  puts(rule[7]);
}
#line 1523 "y.tab.c"
    break;

  case 10: /* BLOCK: DECISION  */
#line 183 "Sintactico.y"
             {
  puts(rule[8]);
}
#line 1531 "y.tab.c"
    break;

  case 11: /* BLOCK: ITERATION  */
#line 185 "Sintactico.y"
              {
  puts(rule[9]);
}
#line 1539 "y.tab.c"
    break;

  case 12: /* DECLARATION: op_dim open_bracket VARIABLES close_bracket op_as open_bracket DATATYPES close_bracket  */
#line 190 "Sintactico.y"
                                                                                                    {
  char* variable_elem, *str_datatype;
  type_t datatype;

  // load variable type
  while(!queue_is_empty(variable_queue)) {
    // dequeue variable
    variable_elem = dequeue(variable_queue);
    strcpy(identifier, variable_elem);

    // dequeue datatype as enum type
    str_datatype = dequeue(datatype_queue);
    datatype = get_enum_type(str_datatype);

    // insert variable to symbol table
    insert_variable(&symbol_table, identifier, datatype);
  }
  
  puts(rule[10]);
}
#line 1564 "y.tab.c"
    break;

  case 13: /* VARIABLES: VARIABLES comma id  */
#line 211 "Sintactico.y"
                              {
  strcpy(identifier, strdup((yyvsp[0].str_val)));

  // enqueue identifier
  enqueue(variable_queue, strdup(identifier));

  puts(rule[11]);
}
#line 1577 "y.tab.c"
    break;

  case 14: /* VARIABLES: id  */
#line 218 "Sintactico.y"
       {
  strcpy(identifier, strdup((yyvsp[0].str_val)));

  // enqueue identifier
  enqueue(variable_queue, strdup(identifier));

  puts(rule[12]);
}
#line 1590 "y.tab.c"
    break;

  case 15: /* DATATYPES: DATATYPES comma DATATYPE  */
#line 227 "Sintactico.y"
                                    {
  puts(rule[13]);
}
#line 1598 "y.tab.c"
    break;

  case 16: /* DATATYPES: DATATYPE  */
#line 229 "Sintactico.y"
             {
  puts(rule[14]);
}
#line 1606 "y.tab.c"
    break;

  case 17: /* DATATYPE: int_type  */
#line 233 "Sintactico.y"
                   {
  // enqueue integer type
  enqueue(datatype_queue, get_string_type(integer));

  puts(rule[15]);
}
#line 1617 "y.tab.c"
    break;

  case 18: /* DATATYPE: real_type  */
#line 238 "Sintactico.y"
              {
  // enqueue real type
  enqueue(datatype_queue, get_string_type(real));

  puts(rule[16]);
}
#line 1628 "y.tab.c"
    break;

  case 19: /* DATATYPE: string_type  */
#line 243 "Sintactico.y"
                {
  // enqueue string type
  enqueue(datatype_queue, get_string_type(str));

  puts(rule[17]);
}
#line 1639 "y.tab.c"
    break;

  case 20: /* ASSIGNMENT: id op_assign ASSIGNMENT  */
#line 251 "Sintactico.y"
                                    {
  strcpy(identifier, strdup((yyvsp[-2].str_val)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(identifier));
  add_lexeme_to_rpn(rpn, (lexeme_t*)":=");

  puts(rule[18]);
}
#line 1652 "y.tab.c"
    break;

  case 21: /* ASSIGNMENT: id op_assign EXPRESSION  */
#line 258 "Sintactico.y"
                            {
  strcpy(identifier, strdup((yyvsp[-2].str_val)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(identifier));
  add_lexeme_to_rpn(rpn, (lexeme_t*)":=");

  puts(rule[19]);
}
#line 1665 "y.tab.c"
    break;

  case 22: /* EXPRESSION: EXPRESSION op_sum TERM  */
#line 267 "Sintactico.y"
                                   {
  add_lexeme_to_rpn(rpn, (lexeme_t*)"+");

  puts(rule[20]);
}
#line 1675 "y.tab.c"
    break;

  case 23: /* EXPRESSION: EXPRESSION op_sub TERM  */
#line 271 "Sintactico.y"
                           {
  add_lexeme_to_rpn(rpn, (lexeme_t*)"-");

  puts(rule[21]);
}
#line 1685 "y.tab.c"
    break;

  case 24: /* EXPRESSION: TERM  */
#line 275 "Sintactico.y"
         {
  puts(rule[22]);
}
#line 1693 "y.tab.c"
    break;

  case 25: /* TERM: TERM op_mult FACTOR  */
#line 279 "Sintactico.y"
                          {
  add_lexeme_to_rpn(rpn, (lexeme_t*)"*");

  puts(rule[23]);
}
#line 1703 "y.tab.c"
    break;

  case 26: /* TERM: TERM op_div FACTOR  */
#line 283 "Sintactico.y"
                       {
  add_lexeme_to_rpn(rpn, (lexeme_t*)"/");

  puts(rule[24]);
}
#line 1713 "y.tab.c"
    break;

  case 27: /* TERM: FACTOR  */
#line 287 "Sintactico.y"
           {
  puts(rule[25]);
}
#line 1721 "y.tab.c"
    break;

  case 28: /* FACTOR: open_parenthesis EXPRESSION close_parenthesis  */
#line 291 "Sintactico.y"
                                                      {
  puts(rule[26]);
}
#line 1729 "y.tab.c"
    break;

  case 29: /* FACTOR: id  */
#line 293 "Sintactico.y"
       {
  strcpy(identifier, strdup((yyvsp[0].str_val)));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(identifier));

  puts(rule[27]);
}
#line 1740 "y.tab.c"
    break;

  case 30: /* FACTOR: CONSTANT  */
#line 298 "Sintactico.y"
             {
  puts(rule[28]);
}
#line 1748 "y.tab.c"
    break;

  case 31: /* FACTOR: LENGTH  */
#line 300 "Sintactico.y"
           {
  puts(rule[29]);
}
#line 1756 "y.tab.c"
    break;

  case 32: /* CONSTANT: int_constant  */
#line 304 "Sintactico.y"
                       {
  int integer = (yyvsp[0].int_val);
  insert_integer(&symbol_table, integer);

  sprintf(actual_item, "%d", integer);

  if (show == TRUE) {
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(actual_item));
  }

  puts(rule[30]);
}
#line 1773 "y.tab.c"
    break;

  case 33: /* CONSTANT: real_constant  */
#line 315 "Sintactico.y"
                  {
  double real = (yyvsp[0].real_val);
  insert_real(&symbol_table, real);

  sprintf(actual_item, "%f", real);

  if (show == TRUE) {
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(actual_item));
  }

  puts(rule[31]);
}
#line 1790 "y.tab.c"
    break;

  case 34: /* CONSTANT: string_constant  */
#line 326 "Sintactico.y"
                    {
  char identifier[30];
  strcpy(identifier, delete_quotes((yyvsp[0].str_val)));
  strcpy(actual_item, strdup(identifier));
  insert_string(&symbol_table, strdup(identifier));

  if (show == TRUE) {
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(identifier));
  }

  puts(rule[32]);
}
#line 1807 "y.tab.c"
    break;

  case 35: /* LENGTH: fun_long open_parenthesis LIST close_parenthesis  */
#line 340 "Sintactico.y"
                                                         {
  char item_quantity_str[100];
  sprintf(item_quantity_str, "%d", item_quantity);

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(item_quantity_str));

  puts(rule[33]);
}
#line 1820 "y.tab.c"
    break;

  case 36: /* $@1: %empty  */
#line 349 "Sintactico.y"
                   {
  show = FALSE;
}
#line 1828 "y.tab.c"
    break;

  case 37: /* LIST: open_bracket $@1 ITEMS close_bracket  */
#line 351 "Sintactico.y"
                      {
  show = TRUE;

  puts(rule[34]);
}
#line 1838 "y.tab.c"
    break;

  case 38: /* ITEMS: ITEMS comma ITEM  */
#line 357 "Sintactico.y"
                        {
  ++item_quantity;

  if (is_while_loop) {
    enqueue(while_queue, strdup(actual_item));
  }

  puts(rule[35]);
}
#line 1852 "y.tab.c"
    break;

  case 39: /* ITEMS: ITEM  */
#line 365 "Sintactico.y"
         {
  item_quantity = 1;

  if (is_while_loop) {
    enqueue(while_queue, strdup(actual_item));
  }

  puts(rule[36]);
}
#line 1866 "y.tab.c"
    break;

  case 40: /* ITEM: CONSTANT  */
#line 375 "Sintactico.y"
               {
  puts(rule[37]);
}
#line 1874 "y.tab.c"
    break;

  case 41: /* ITEM: id  */
#line 377 "Sintactico.y"
       {
  strcpy(actual_item, strdup((yyvsp[0].str_val)));

  if (show == TRUE) {
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(actual_item));
  }

  puts(rule[38]);
}
#line 1888 "y.tab.c"
    break;

  case 42: /* INPUT: op_get id  */
#line 388 "Sintactico.y"
                 {
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("GET"));

  puts(rule[39]);
}
#line 1898 "y.tab.c"
    break;

  case 43: /* OUTPUT: op_display EXPRESSION  */
#line 394 "Sintactico.y"
                              {
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("DSP"));

  puts(rule[40]);
}
#line 1908 "y.tab.c"
    break;

  case 44: /* DECISION: IF_EVALUATOR CODE op_endif  */
#line 401 "Sintactico.y"
                                     {
  // define jump to end of if statement
  int condition_jump_cell = pop_from_stack(cell_stack);
  int actual_cell = get_actual_cell_from_rpn(rpn);

  char target_cell[5];

  sprintf(target_cell, "#%d", actual_cell + 1);

  set_lexeme_from_rpn(rpn, condition_jump_cell, (lexeme_t*)strdup(target_cell));

  // when there is AND operator
  if (pop_from_stack(is_and_stack) == TRUE) {
    condition_jump_cell = pop_from_stack(cell_stack);
    sprintf(target_cell, "#%d", actual_cell + 1);
    set_lexeme_from_rpn(rpn, condition_jump_cell, (lexeme_t*)strdup(target_cell));
  }

  puts(rule[41]);
}
#line 1933 "y.tab.c"
    break;

  case 45: /* $@2: %empty  */
#line 420 "Sintactico.y"
                              {
  // add jump to end of if statement
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("BI"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  // define jump to else statement
  int start_cell = pop_from_stack(cell_stack);
  int actual_cell = get_actual_cell_from_rpn(rpn);

  char target_cell[5];

  sprintf(target_cell, "#%d", actual_cell + 1);

  set_lexeme_from_rpn(rpn, start_cell, (lexeme_t*)strdup(target_cell));

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));
}
#line 1955 "y.tab.c"
    break;

  case 46: /* DECISION: IF_EVALUATOR CODE op_else $@2 CODE op_endif  */
#line 436 "Sintactico.y"
                {
  // define jump to end of if statement
  int start_cell = pop_from_stack(cell_stack);
  int actual_cell = get_actual_cell_from_rpn(rpn);

  char target_cell[5];

  sprintf(target_cell, "#%d", actual_cell + 1);

  set_lexeme_from_rpn(rpn, start_cell, (lexeme_t*)strdup(target_cell));

  puts(rule[42]);
}
#line 1973 "y.tab.c"
    break;

  case 47: /* IF_EVALUATOR: op_if open_parenthesis CONDITION close_parenthesis  */
#line 450 "Sintactico.y"
                                                                 {
  // Single condition
  if (strcmp(logical_operator, "\0") == 0) {
    char branch[3];
    strcpy(branch, strdup(get_opposite_branch(comparator)));
    
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

    push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));

    push_to_stack(is_and_stack, FALSE);
  }

  strcpy(logical_operator, "\0");

  puts(rule[43]);
}
#line 1997 "y.tab.c"
    break;

  case 48: /* $@3: %empty  */
#line 470 "Sintactico.y"
                              {
  strcpy(comparator1, comparator);
  strcpy(logical_operator, "&&");
  
  strcpy(branch, strdup(get_opposite_branch(comparator1)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));
}
#line 2014 "y.tab.c"
    break;

  case 49: /* CONDITION: COMPARATION op_and $@3 COMPARATION  */
#line 481 "Sintactico.y"
              {
  strcpy(comparator2, comparator);

  strcpy(branch, strdup(get_opposite_branch(comparator2)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));
  
  push_to_stack(is_and_stack, TRUE);

  puts(rule[44]);
}
#line 2034 "y.tab.c"
    break;

  case 50: /* $@4: %empty  */
#line 495 "Sintactico.y"
                      {
  strcpy(comparator1, comparator);
  
  strcpy(logical_operator, "||");

  // Comparator 1
  strcpy(branch, strdup(get_corresponding_branch(comparator1)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  first_condition_jump_cell = get_actual_cell_from_rpn(rpn);
}
#line 2053 "y.tab.c"
    break;

  case 51: /* CONDITION: COMPARATION op_or $@4 COMPARATION  */
#line 508 "Sintactico.y"
              {
  strcpy(comparator2, comparator);

  // Comparator 2
  strcpy(branch, strdup(get_opposite_branch(comparator2)));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));

  // Change jump of first condition
  char target_cell[5];
  sprintf(target_cell, "#%d", get_actual_cell_from_rpn(rpn) + 1);
  set_lexeme_from_rpn(rpn, first_condition_jump_cell, (lexeme_t*)strdup(target_cell));

  push_to_stack(is_and_stack, FALSE);

  puts(rule[45]);
}
#line 2079 "y.tab.c"
    break;

  case 52: /* CONDITION: COMPARATION  */
#line 528 "Sintactico.y"
                {
  puts(rule[46]);
}
#line 2087 "y.tab.c"
    break;

  case 53: /* COMPARATION: ITEM COMPARATOR ITEM  */
#line 532 "Sintactico.y"
                                  {
  puts(rule[47]);
}
#line 2095 "y.tab.c"
    break;

  case 54: /* COMPARATOR: op_eq  */
#line 536 "Sintactico.y"
                  {
  strcpy(comparator, strdup("=="));

  puts(rule[48]);
}
#line 2105 "y.tab.c"
    break;

  case 55: /* COMPARATOR: op_lt  */
#line 540 "Sintactico.y"
          {
  strcpy(comparator, strdup("<"));

  puts(rule[49]);
}
#line 2115 "y.tab.c"
    break;

  case 56: /* COMPARATOR: op_le  */
#line 544 "Sintactico.y"
          {
  strcpy(comparator, strdup("<="));

  puts(rule[50]);
}
#line 2125 "y.tab.c"
    break;

  case 57: /* COMPARATOR: op_gt  */
#line 548 "Sintactico.y"
          {
  strcpy(comparator, strdup(">"));

  puts(rule[51]);
}
#line 2135 "y.tab.c"
    break;

  case 58: /* COMPARATOR: op_ge  */
#line 552 "Sintactico.y"
          {
  strcpy(comparator, strdup(">="));

  puts(rule[52]);
}
#line 2145 "y.tab.c"
    break;

  case 59: /* COMPARATOR: op_ne  */
#line 556 "Sintactico.y"
          {
  strcpy(comparator, strdup("!="));

  puts(rule[53]);
}
#line 2155 "y.tab.c"
    break;

  case 60: /* $@5: %empty  */
#line 563 "Sintactico.y"
                    {
  // add start etiquete
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("ET"));
  int actual_cell = get_actual_cell_from_rpn(rpn);
  push_to_stack(cell_stack, actual_cell);
}
#line 2166 "y.tab.c"
    break;

  case 61: /* $@6: %empty  */
#line 568 "Sintactico.y"
                                               {
  // Single condition
  if (strcmp(logical_operator, "\0") == 0) {
    strcpy(branch, strdup(get_opposite_branch(comparator)));
    
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(branch));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

    push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));

    push_to_stack(is_and_stack, FALSE);
  }

  puts(rule[54]);
}
#line 2187 "y.tab.c"
    break;

  case 62: /* ITERATION: op_while $@5 open_parenthesis CONDITION close_parenthesis $@6 CODE op_endwhile  */
#line 583 "Sintactico.y"
                   {
  // define jump to start of while statement
  char target_cell[5];

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("BI"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

  int actual_cell = get_actual_cell_from_rpn(rpn);

  // change jump to end of while statement
  int condition_jump_cell = pop_from_stack(cell_stack);
  sprintf(target_cell, "#%d", actual_cell + 1);
  set_lexeme_from_rpn(rpn, condition_jump_cell, (lexeme_t*)strdup(target_cell));

  // when there is AND operator
  if (pop_from_stack(is_and_stack) == TRUE) {
    condition_jump_cell = pop_from_stack(cell_stack);
    sprintf(target_cell, "#%d", actual_cell + 1);
    set_lexeme_from_rpn(rpn, condition_jump_cell, (lexeme_t*)strdup(target_cell));
  }

  // change jump to start of while statement
  int start_jump_cell = pop_from_stack(cell_stack);
  sprintf(target_cell, "#%d", start_jump_cell);
  set_lexeme_from_rpn(rpn, actual_cell, (lexeme_t*)strdup(target_cell));

  puts(rule[54]);
}
#line 2220 "y.tab.c"
    break;

  case 63: /* $@7: %empty  */
#line 610 "Sintactico.y"
                      {
  is_while_loop = TRUE;
}
#line 2228 "y.tab.c"
    break;

  case 64: /* $@8: %empty  */
#line 612 "Sintactico.y"
             {
  is_while_loop = FALSE;

  int actual_item_num = 1;
  char actual_item_num_str[100];
  char* identifier = strdup((yyvsp[-4].str_val));

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("1"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("@act"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(":="));

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));

  while (!queue_is_empty(while_queue)) {
    char item[30];
    strcpy(item, strdup(dequeue(while_queue)));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(item));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(identifier));
    add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(":="));

    if (actual_item_num < item_quantity) {
      sprintf(actual_item_num_str, "%d", actual_item_num);
      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("@act"));
      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(actual_item_num_str));

      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("BEQ"));
      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("JMP"));

      push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));
    }
    
    actual_item_num++;
  }

  push_to_stack(cell_stack, get_actual_cell_from_rpn(rpn));
}
#line 2270 "y.tab.c"
    break;

  case 65: /* ITERATION: op_while id op_in $@7 LIST op_do $@8 CODE op_endwhile  */
#line 648 "Sintactico.y"
                   {
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("@act"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("1"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("+"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("@act"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(":="));

  char item_quantity_str[100];

  sprintf(item_quantity_str, "%d", item_quantity);

  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("@act"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(item_quantity_str));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("CMP"));
  add_lexeme_to_rpn(rpn, (lexeme_t*)strdup("BLE"));

  int code_cell = pop_from_stack(cell_stack);

  char target_cell[100];

  while(!stack_is_empty(cell_stack)) {
    int cell = pop_from_stack(cell_stack);

    if (stack_is_empty(cell_stack)) {
      sprintf(target_cell, "#%d", cell + 1);
      add_lexeme_to_rpn(rpn, (lexeme_t*)strdup(target_cell));
    }
    else {
      sprintf(target_cell, "#%d", code_cell + 1);
      set_lexeme_from_rpn(rpn, cell, (lexeme_t*)strdup(target_cell));
    }
  }

  puts(rule[55]);
}
#line 2310 "y.tab.c"
    break;


#line 2314 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 683 "Sintactico.y"


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

  create_list(&symbol_table);
  variable_queue = create_queue();
  datatype_queue = create_queue();
  branch_queue = create_queue();
  while_queue = create_queue();
  cell_stack = create_stack();
  is_and_stack = create_stack();

  rpn = create_rpn();

  yyparse();

  save_table_in_file(&symbol_table);

  save_lexemes_in_file(rpn);

  delete_list(&symbol_table);
  free_rpn(rpn);

  fclose(yyin);

  return EXIT_SUCCESS;
}

// Help
void show_help(char* app_name) {
  printf("%s [code_file]\n\n", app_name);
  printf("Example: %s %s\n\n", app_name, "./tests/prueba.txt");
}

// Error
int yyerror(char *error) {
  fprintf(stderr, COLOR_RED "\nline %d: %s\n" COLOR_RESET, lineno, error);
  fclose(yyin);
  exit(1);
}

char *delete_quotes(char *lex)
{
  char *str = lex;
  char *start_str = str;
  while (*lex)
  {
    if (*lex != '"')
    {
      (*str) = (*lex);
      str++;
    }
    lex++;
  }
  *str = '\0';
  return start_str;
}

char *get_corresponding_branch(char *comparator) {
  if (strcmp(comparator, "==") == 0) {
    return "BEQ";
  }
  else if (strcmp(comparator, "!=") == 0) {
    return "BNE";
  }
  else if (strcmp(comparator, "<") == 0) {
    return "BLT";
  }
  else if (strcmp(comparator, ">") == 0) {
    return "BGT";
  }
  else if (strcmp(comparator, "<=") == 0) {
    return "BLE";
  }
  else if (strcmp(comparator, ">=") == 0) {
    return "BGE";
  }
  else {
    return "\0";
  }
}

char *get_opposite_branch(char *comparator) {
  if (strcmp(comparator, "==") == 0) {
    return "BNE";
  }
  else if (strcmp(comparator, "!=") == 0) {
    return "BEQ";
  }
  else if (strcmp(comparator, "<") == 0) {
    return "BGE";
  }
  else if (strcmp(comparator, "<=") == 0) {
    return "BGT";
  }
  else if (strcmp(comparator, ">") == 0) {
    return "BLE";
  }
  else if (strcmp(comparator, ">=") == 0) {
    return "BLT";
  }
  else {
    return "\0";
  }
}
