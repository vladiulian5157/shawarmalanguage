/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstdlib>

using namespace std;

extern int yylex();
extern int yylineno;
void yyerror(const char* s);

#line 86 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NUMEVAR = 3,                    /* NUMEVAR  */
  YYSYMBOL_INT_VAL = 4,                    /* INT_VAL  */
  YYSYMBOL_FLOAT_VAL = 5,                  /* FLOAT_VAL  */
  YYSYMBOL_STRING_VAL = 6,                 /* STRING_VAL  */
  YYSYMBOL_BOOL_VAL = 7,                   /* BOOL_VAL  */
  YYSYMBOL_CLASS = 8,                      /* CLASS  */
  YYSYMBOL_MAIN = 9,                       /* MAIN  */
  YYSYMBOL_IF = 10,                        /* IF  */
  YYSYMBOL_ELSE = 11,                      /* ELSE  */
  YYSYMBOL_WHILE = 12,                     /* WHILE  */
  YYSYMBOL_PRINT = 13,                     /* PRINT  */
  YYSYMBOL_NEW = 14,                       /* NEW  */
  YYSYMBOL_RETURN = 15,                    /* RETURN  */
  YYSYMBOL_TIPDATA_INT = 16,               /* TIPDATA_INT  */
  YYSYMBOL_TIPDATA_FLOAT = 17,             /* TIPDATA_FLOAT  */
  YYSYMBOL_TIPDATA_STRING = 18,            /* TIPDATA_STRING  */
  YYSYMBOL_TIPDATA_BOOL = 19,              /* TIPDATA_BOOL  */
  YYSYMBOL_TIPDATA_VOID = 20,              /* TIPDATA_VOID  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_LE = 23,                        /* LE  */
  YYSYMBOL_GE = 24,                        /* GE  */
  YYSYMBOL_AND = 25,                       /* AND  */
  YYSYMBOL_OR = 26,                        /* OR  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '+'  */
  YYSYMBOL_30_ = 30,                       /* '-'  */
  YYSYMBOL_31_ = 31,                       /* '*'  */
  YYSYMBOL_32_ = 32,                       /* '/'  */
  YYSYMBOL_33_ = 33,                       /* '.'  */
  YYSYMBOL_34_ = 34,                       /* '{'  */
  YYSYMBOL_35_ = 35,                       /* '}'  */
  YYSYMBOL_36_ = 36,                       /* '('  */
  YYSYMBOL_37_ = 37,                       /* ')'  */
  YYSYMBOL_38_ = 38,                       /* ','  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* ';'  */
  YYSYMBOL_YYACCEPT = 41,                  /* $accept  */
  YYSYMBOL_program = 42,                   /* program  */
  YYSYMBOL_lista_top = 43,                 /* lista_top  */
  YYSYMBOL_top_item = 44,                  /* top_item  */
  YYSYMBOL_class_decl = 45,                /* class_decl  */
  YYSYMBOL_46_1 = 46,                      /* $@1  */
  YYSYMBOL_interior_clasa = 47,            /* interior_clasa  */
  YYSYMBOL_element_clasa = 48,             /* element_clasa  */
  YYSYMBOL_functie_decl = 49,              /* functie_decl  */
  YYSYMBOL_50_2 = 50,                      /* $@2  */
  YYSYMBOL_51_3 = 51,                      /* $@3  */
  YYSYMBOL_52_4 = 52,                      /* $@4  */
  YYSYMBOL_53_5 = 53,                      /* $@5  */
  YYSYMBOL_lista_parametri = 54,           /* lista_parametri  */
  YYSYMBOL_parametru = 55,                 /* parametru  */
  YYSYMBOL_interior_functie = 56,          /* interior_functie  */
  YYSYMBOL_element_functie = 57,           /* element_functie  */
  YYSYMBOL_functie_main = 58,              /* functie_main  */
  YYSYMBOL_59_6 = 59,                      /* $@6  */
  YYSYMBOL_interior_main = 60,             /* interior_main  */
  YYSYMBOL_element_main = 61,              /* element_main  */
  YYSYMBOL_sintaxa_conditie = 62,          /* sintaxa_conditie  */
  YYSYMBOL_interior_conditie = 63,         /* interior_conditie  */
  YYSYMBOL_instructiuni = 64,              /* instructiuni  */
  YYSYMBOL_if_structura = 65,              /* if_structura  */
  YYSYMBOL_while_structura = 66,           /* while_structura  */
  YYSYMBOL_atribuiri_apeluri = 67,         /* atribuiri_apeluri  */
  YYSYMBOL_68_7 = 68,                      /* $@7  */
  YYSYMBOL_69_8 = 69,                      /* $@8  */
  YYSYMBOL_variabila_decl = 70,            /* variabila_decl  */
  YYSYMBOL_obiect_decl = 71,               /* obiect_decl  */
  YYSYMBOL_print_structura = 72,           /* print_structura  */
  YYSYMBOL_return_structura = 73,          /* return_structura  */
  YYSYMBOL_arg_lista = 74,                 /* arg_lista  */
  YYSYMBOL_tipul_variabilei = 75,          /* tipul_variabilei  */
  YYSYMBOL_expresie = 76,                  /* expresie  */
  YYSYMBOL_77_9 = 77,                      /* $@9  */
  YYSYMBOL_78_10 = 78                      /* $@10  */
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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_uint8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   379

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  41
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  38
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   281


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
      36,    37,    31,    29,    38,    30,    33,    32,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    40,
      27,    39,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    34,     2,    35,     2,     2,     2,     2,
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
      25,    26
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   328,   328,   332,   333,   337,   338,   339,   340,   345,
     344,   357,   357,   358,   358,   358,   361,   362,   361,   378,
     379,   378,   391,   391,   391,   393,   394,   397,   397,   398,
     398,   398,   402,   401,   424,   429,   433,   434,   435,   439,
     447,   452,   456,   457,   458,   459,   460,   465,   473,   486,
     496,   502,   525,   525,   530,   530,   538,   545,   556,   561,
     570,   573,   576,   577,   578,   581,   582,   583,   584,   585,
     589,   613,   638,   662,   686,   708,   729,   750,   771,   788,
     805,   819,   833,   835,   847,   869,   870,   871,   872,   874,
     874,   881,   886,   886
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
  "\"end of file\"", "error", "\"invalid token\"", "NUMEVAR", "INT_VAL",
  "FLOAT_VAL", "STRING_VAL", "BOOL_VAL", "CLASS", "MAIN", "IF", "ELSE",
  "WHILE", "PRINT", "NEW", "RETURN", "TIPDATA_INT", "TIPDATA_FLOAT",
  "TIPDATA_STRING", "TIPDATA_BOOL", "TIPDATA_VOID", "EQ", "NE", "LE", "GE",
  "AND", "OR", "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'.'", "'{'",
  "'}'", "'('", "')'", "','", "'='", "';'", "$accept", "program",
  "lista_top", "top_item", "class_decl", "$@1", "interior_clasa",
  "element_clasa", "functie_decl", "$@2", "$@3", "$@4", "$@5",
  "lista_parametri", "parametru", "interior_functie", "element_functie",
  "functie_main", "$@6", "interior_main", "element_main",
  "sintaxa_conditie", "interior_conditie", "instructiuni", "if_structura",
  "while_structura", "atribuiri_apeluri", "$@7", "$@8", "variabila_decl",
  "obiect_decl", "print_structura", "return_structura", "arg_lista",
  "tipul_variabilei", "expresie", "$@9", "$@10", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-130)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -130,     9,   244,  -130,    26,    46,    18,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,    54,   -28,
      25,    29,    16,  -130,    14,  -130,  -130,  -130,  -130,    14,
    -130,     7,   -30,  -130,  -130,  -130,  -130,    66,    14,   134,
    -130,    51,     7,   154,    80,    24,  -130,    84,   106,  -130,
      63,   245,    14,    14,    14,    14,    14,    14,    14,    14,
      14,    14,    14,    14,  -130,   105,  -130,    40,  -130,  -130,
    -130,     7,  -130,    78,    14,    91,  -130,   347,   347,   140,
     140,   337,   325,   140,   140,    49,    49,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,    55,  -130,   103,  -130,  -130,    60,
     313,  -130,    12,    94,   108,   111,    14,  -130,  -130,  -130,
    -130,  -130,  -130,  -130,  -130,  -130,  -130,   151,   139,  -130,
      14,  -130,    14,    62,   164,  -130,    14,    14,    14,    14,
     174,    87,  -130,    76,    96,   313,     8,    14,   194,   262,
     279,   296,  -130,   100,  -130,  -130,  -130,  -130,  -130,  -130,
    -130,    14,   101,  -130,   155,   155,   152,  -130,    14,   214,
     153,  -130,   179,  -130,  -130,   150,  -130,  -130,   133,   155,
     167,  -130,  -130,  -130,  -130
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       4,     0,     0,     1,     0,     0,     0,    65,    66,    67,
      68,    69,     3,     5,     6,     2,     7,     8,     0,     0,
       0,     0,     0,    19,     0,    58,     9,    32,    16,     0,
      56,    24,    83,    85,    86,    87,    88,     0,     0,     0,
      12,     0,    24,     0,     0,     0,    23,     0,     0,    89,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    59,     0,    35,     0,    57,    26,
      20,     0,    25,    84,    64,     0,    82,    78,    79,    76,
      77,    80,    81,    74,    75,    70,    71,    72,    73,    10,
      11,    15,    13,    14,     0,    17,     0,    22,    92,     0,
      63,    91,     0,     0,     0,     0,     0,    33,    34,    36,
      42,    43,    46,    37,    38,    44,    45,     0,     0,    28,
      64,    90,     0,     0,     0,    52,     0,     0,     0,     0,
       0,     0,    28,     0,     0,    62,     0,    64,     0,     0,
       0,     0,    61,     0,    21,    27,    29,    30,    31,    93,
      54,     0,     0,    50,     0,     0,     0,    18,    64,     0,
       0,    41,    47,    49,    60,     0,    51,    53,     0,     0,
       0,    39,    40,    48,    55
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -130,  -130,  -130,  -130,  -130,  -130,  -130,  -130,   126,  -130,
    -130,  -130,  -130,   166,   138,    79,  -130,  -130,  -130,  -130,
      42,  -109,  -130,  -129,  -130,  -130,  -130,  -130,  -130,    -2,
      -1,  -130,  -130,  -115,    11,   -22,  -130,  -130
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     2,    12,    13,    40,    65,    90,    14,    42,
     118,    31,    96,    45,    46,   133,   145,    15,    41,    94,
     108,   162,   168,   109,   110,   111,   112,   137,   158,   113,
     114,   115,   116,    99,   117,   100,    74,   120
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    17,    39,    48,   146,   134,    49,    43,    23,     3,
      44,    24,    25,    18,   146,   123,    51,    32,    33,    34,
      35,    36,   152,     7,     8,     9,    10,    11,    37,    19,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    47,   165,   150,   124,   163,   151,   125,    20,
      38,   126,    28,    47,    21,    29,    30,    22,   102,    26,
     173,    70,    71,    92,    93,   103,    27,   104,   105,    50,
     106,     7,     8,     9,    10,    11,    18,    95,    71,   102,
      62,    63,    47,    69,   130,    66,   103,    72,   104,   105,
     107,   106,     7,     8,     9,    10,    11,   121,   122,    75,
     135,    24,    25,   102,   138,   139,   140,   141,     4,    73,
     103,   144,   104,   105,    98,   106,     7,     8,     9,    10,
      11,     7,     8,     9,    10,    11,    29,    30,   101,   159,
     127,   147,   148,   149,   122,   157,   102,   119,   160,   122,
      89,   147,   148,   103,   128,   104,   105,   129,   106,     7,
       8,     9,    10,    11,   131,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   136,   171,    60,
      61,    62,    63,   132,    64,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   170,   122,   161,
     169,    91,   164,   167,    68,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,   174,    67,    97,
     172,   143,     0,     0,   142,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     0,     0,     0,
       0,     0,     0,     0,   153,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,     4,     0,     0,
       0,     0,     5,     6,   166,     0,     0,     0,     0,     0,
       7,     8,     9,    10,    11,     0,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,     0,     0,
       0,     0,    76,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,     0,     0,     0,     0,   154,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,     0,     0,     0,     0,   155,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,     0,
       0,     0,     0,   156,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    52,    53,    54,    55,
      56,     0,    58,    59,    60,    61,    62,    63,    52,    53,
      54,    55,     0,     0,    58,    59,    60,    61,    62,    63,
      54,    55,     0,     0,    58,    59,    60,    61,    62,    63
};

static const yytype_int16 yycheck[] =
{
       2,     2,    24,    33,   133,   120,    36,    29,    36,     0,
       3,    39,    40,     2,   143,     3,    38,     3,     4,     5,
       6,     7,   137,    16,    17,    18,    19,    20,    14,     3,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    31,   158,    36,    33,   155,    39,    36,     3,
      36,    39,    36,    42,    36,    39,    40,     3,     3,    34,
     169,    37,    38,    65,    65,    10,    37,    12,    13,     3,
      15,    16,    17,    18,    19,    20,    65,    37,    38,     3,
      31,    32,    71,     3,   106,    34,    10,     3,    12,    13,
      35,    15,    16,    17,    18,    19,    20,    37,    38,    36,
     122,    39,    40,     3,   126,   127,   128,   129,     3,     3,
      10,    35,    12,    13,    36,    15,    16,    17,    18,    19,
      20,    16,    17,    18,    19,    20,    39,    40,    37,   151,
      36,   133,   133,    37,    38,    35,     3,    34,    37,    38,
      35,   143,   143,    10,    36,    12,    13,    36,    15,    16,
      17,    18,    19,    20,     3,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     3,    35,    29,
      30,    31,    32,    34,    40,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    37,    38,    34,
      11,    65,    40,    40,    40,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    40,    42,    71,
     168,   132,    -1,    -1,    40,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,     3,    -1,    -1,
      -1,    -1,     8,     9,    40,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    -1,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    37,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    -1,    -1,    -1,    -1,    37,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    21,    22,    23,    24,
      25,    -1,    27,    28,    29,    30,    31,    32,    21,    22,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    32,
      23,    24,    -1,    -1,    27,    28,    29,    30,    31,    32
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,     0,     3,     8,     9,    16,    17,    18,
      19,    20,    44,    45,    49,    58,    70,    71,    75,     3,
       3,    36,     3,    36,    39,    40,    34,    37,    36,    39,
      40,    52,     3,     4,     5,     6,     7,    14,    36,    76,
      46,    59,    50,    76,     3,    54,    55,    75,    33,    36,
       3,    76,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    40,    47,    34,    54,    40,     3,
      37,    38,     3,     3,    77,    36,    37,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    35,
      48,    49,    70,    71,    60,    37,    53,    55,    36,    74,
      76,    37,     3,    10,    12,    13,    15,    35,    61,    64,
      65,    66,    67,    70,    71,    72,    73,    75,    51,    34,
      78,    37,    38,     3,    33,    36,    39,    36,    36,    36,
      76,     3,    34,    56,    74,    76,     3,    68,    76,    76,
      76,    76,    40,    56,    35,    57,    64,    70,    71,    37,
      36,    39,    74,    40,    37,    37,    37,    35,    69,    76,
      37,    34,    62,    62,    40,    74,    40,    40,    63,    11,
      37,    35,    61,    62,    40
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    41,    42,    43,    43,    44,    44,    44,    44,    46,
      45,    47,    47,    48,    48,    48,    50,    51,    49,    52,
      53,    49,    54,    54,    54,    55,    55,    56,    56,    57,
      57,    57,    59,    58,    60,    60,    61,    61,    61,    62,
      63,    63,    64,    64,    64,    64,    64,    65,    65,    66,
      67,    67,    68,    67,    69,    67,    70,    70,    71,    71,
      72,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    76,
      76,    76,    76,    76,    76,    76,    76,    76,    76,    77,
      76,    76,    78,    76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     0,     1,     1,     1,     1,     0,
       6,     2,     0,     1,     1,     1,     0,     0,    10,     0,
       0,    10,     3,     1,     0,     2,     2,     2,     0,     1,
       1,     1,     0,     7,     2,     0,     1,     1,     1,     3,
       2,     0,     1,     1,     1,     1,     1,     5,     7,     5,
       4,     6,     0,     6,     0,     8,     3,     5,     3,     5,
       5,     3,     3,     1,     0,     1,     1,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     3,     1,     1,     1,     1,     0,
       5,     4,     0,     7
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
  case 2: /* program: lista_top functie_main  */
#line 328 "parser.y"
                           { cout << "Validare Semantica reusita.\n"; }
#line 1310 "parser.tab.c"
    break;

  case 9: /* $@1: %empty  */
#line 345 "parser.y"
    {
        string className = "class " + *(yyvsp[-1].stringvalue);
        SymbolTable* classTable = new SymbolTable(className, currentTable);
        currentTable->addChild(classTable);
        allTables.push_back(classTable);
        currentTable = classTable;
    }
#line 1322 "parser.tab.c"
    break;

  case 10: /* class_decl: CLASS NUMEVAR '{' $@1 interior_clasa '}'  */
#line 354 "parser.y"
    { currentTable = currentTable->parinte; }
#line 1328 "parser.tab.c"
    break;

  case 16: /* $@2: %empty  */
#line 361 "parser.y"
                                 { currentParams.clear(); }
#line 1334 "parser.tab.c"
    break;

  case 17: /* $@3: %empty  */
#line 362 "parser.y"
    {
        string funcName = *(yyvsp[-4].stringvalue); string retType = *(yyvsp[-5].stringvalue);
        currentTable->addFunction(funcName, retType, currentParams);
        SymbolTable* funcTable = new SymbolTable("function " + funcName, currentTable);
        string parentName = currentTable->scopeName;
            if (parentName.rfind("class ", 0) == 0) {
                string clsType = parentName.substr(6);
                funcTable->addVariable("self", clsType, "null");
            }
        currentTable->addChild(funcTable);
        allTables.push_back(funcTable);
        for (auto& p : currentParams) funcTable->addVariable(p.name, p.type, "0");
        currentTable = funcTable;
    }
#line 1353 "parser.tab.c"
    break;

  case 18: /* functie_decl: tipul_variabilei NUMEVAR '(' $@2 lista_parametri ')' $@3 '{' interior_functie '}'  */
#line 376 "parser.y"
                             { currentTable = currentTable->parinte; }
#line 1359 "parser.tab.c"
    break;

  case 19: /* $@4: %empty  */
#line 378 "parser.y"
                        { currentParams.clear(); }
#line 1365 "parser.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 379 "parser.y"
    {
        string retType = *(yyvsp[-5].stringvalue); string funcName = *(yyvsp[-4].stringvalue);
        currentTable->addFunction(funcName, retType, currentParams);
        SymbolTable* funcTable = new SymbolTable("function " + funcName, currentTable);
        currentTable->addChild(funcTable);
        allTables.push_back(funcTable);
        for (auto& p : currentParams) funcTable->addVariable(p.name, p.type, "0");
        currentTable = funcTable;
    }
#line 1379 "parser.tab.c"
    break;

  case 21: /* functie_decl: NUMEVAR NUMEVAR '(' $@4 lista_parametri ')' $@5 '{' interior_functie '}'  */
#line 388 "parser.y"
                             { currentTable = currentTable->parinte; }
#line 1385 "parser.tab.c"
    break;

  case 25: /* parametru: tipul_variabilei NUMEVAR  */
#line 393 "parser.y"
                             { currentParams.push_back(ParamInfo{ *(yyvsp[-1].stringvalue), *(yyvsp[0].stringvalue) }); }
#line 1391 "parser.tab.c"
    break;

  case 26: /* parametru: NUMEVAR NUMEVAR  */
#line 394 "parser.y"
                      { currentParams.push_back(ParamInfo{ *(yyvsp[-1].stringvalue), *(yyvsp[0].stringvalue) }); }
#line 1397 "parser.tab.c"
    break;

  case 32: /* $@6: %empty  */
#line 402 "parser.y"
    {
        if(!globalTable) initSymbolTables();
        globalTable->addFunction("main", "void", {});
        SymbolTable* mainTable = new SymbolTable("function main", globalTable);
        globalTable->addChild(mainTable);
        allTables.push_back(mainTable);
        currentTable = mainTable;
    }
#line 1410 "parser.tab.c"
    break;

  case 33: /* functie_main: MAIN '(' ')' $@6 '{' interior_main '}'  */
#line 411 "parser.y"
    {
        cout << "\n--- Executie Program (Evaluare AST) ---\n";
        vector<ASTNode*>* vectorStatement = (yyvsp[-1].vectorStatement); /* $6=interior_main */
        if(vectorStatement) {
            for (ASTNode* node : *vectorStatement) {
                if (node) node->evaluate();
            }
        }
        currentTable = currentTable->parinte;
    }
#line 1425 "parser.tab.c"
    break;

  case 34: /* interior_main: interior_main element_main  */
#line 425 "parser.y"
    {
        (yyval.vectorStatement) = (yyvsp[-1].vectorStatement);  /* $$ interior main = interior main */
        if ((yyvsp[0].node) != nullptr) (yyval.vectorStatement)->push_back((yyvsp[0].node));
    }
#line 1434 "parser.tab.c"
    break;

  case 35: /* interior_main: %empty  */
#line 429 "parser.y"
      { (yyval.vectorStatement) = new vector<ASTNode*>(); }
#line 1440 "parser.tab.c"
    break;

  case 36: /* element_main: instructiuni  */
#line 433 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1446 "parser.tab.c"
    break;

  case 37: /* element_main: variabila_decl  */
#line 434 "parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1452 "parser.tab.c"
    break;

  case 38: /* element_main: obiect_decl  */
#line 435 "parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1458 "parser.tab.c"
    break;

  case 39: /* sintaxa_conditie: '{' interior_conditie '}'  */
#line 440 "parser.y"
    {
        // Impachetam vectorul de instructiuni intr-un nod BLOCK
        (yyval.node) = new ASTNode(NODE_BLOCK, *(yyvsp[-1].vectorStatement));
    }
#line 1467 "parser.tab.c"
    break;

  case 40: /* interior_conditie: interior_conditie element_main  */
#line 448 "parser.y"
    {
        (yyval.vectorStatement) = (yyvsp[-1].vectorStatement);
        if ((yyvsp[0].node) != nullptr) (yyval.vectorStatement)->push_back((yyvsp[0].node));
    }
#line 1476 "parser.tab.c"
    break;

  case 41: /* interior_conditie: %empty  */
#line 452 "parser.y"
                  { (yyval.vectorStatement) = new vector<ASTNode*>(); }
#line 1482 "parser.tab.c"
    break;

  case 42: /* instructiuni: if_structura  */
#line 456 "parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1488 "parser.tab.c"
    break;

  case 43: /* instructiuni: while_structura  */
#line 457 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1494 "parser.tab.c"
    break;

  case 44: /* instructiuni: print_structura  */
#line 458 "parser.y"
                      { (yyval.node) = (yyvsp[0].node); }
#line 1500 "parser.tab.c"
    break;

  case 45: /* instructiuni: return_structura  */
#line 459 "parser.y"
                       { (yyval.node) = nullptr; }
#line 1506 "parser.tab.c"
    break;

  case 46: /* instructiuni: atribuiri_apeluri  */
#line 460 "parser.y"
                        { (yyval.node) = (yyvsp[0].node); }
#line 1512 "parser.tab.c"
    break;

  case 47: /* if_structura: IF '(' expresie ')' sintaxa_conditie  */
#line 466 "parser.y"
    {
        // if fara else: 2 copii (cond, then)
        vector<ASTNode*> copii;
        copii.push_back((yyvsp[-2].node)); // conditie
        copii.push_back((yyvsp[0].node)); // bloc then
        (yyval.node) = new ASTNode(NODE_IF, copii);
    }
#line 1524 "parser.tab.c"
    break;

  case 48: /* if_structura: IF '(' expresie ')' sintaxa_conditie ELSE sintaxa_conditie  */
#line 474 "parser.y"
    {
        // if cu else: 3 copii (cond, then, else)
        vector<ASTNode*> copii;
        copii.push_back((yyvsp[-4].node)); // if conditie
        copii.push_back((yyvsp[-2].node)); // then
        copii.push_back((yyvsp[0].node)); // else
        (yyval.node) = new ASTNode(NODE_IF, copii);
    }
#line 1537 "parser.tab.c"
    break;

  case 49: /* while_structura: WHILE '(' expresie ')' sintaxa_conditie  */
#line 487 "parser.y"
    {
        vector<ASTNode*> copii;
        copii.push_back((yyvsp[-2].node)); // conditie
        copii.push_back((yyvsp[0].node)); // blocul care se repeta
        (yyval.node) = new ASTNode(NODE_WHILE, copii);
    }
#line 1548 "parser.tab.c"
    break;

  case 50: /* atribuiri_apeluri: NUMEVAR '=' expresie ';'  */
#line 497 "parser.y"
    {
        VarInfo* v = lookupVar(*(yyvsp[-3].stringvalue), currentTable);
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].stringvalue));
        (yyval.node) = new ASTNode("=", idNode, (yyvsp[-1].node), NODE_ASSIGN);
    }
#line 1558 "parser.tab.c"
    break;

  case 51: /* atribuiri_apeluri: NUMEVAR '.' NUMEVAR '=' expresie ';'  */
#line 503 "parser.y"
    {
        VarInfo* obj = lookupVar(*(yyvsp[-5].stringvalue), currentTable);
        if (!obj) {
            semanticError("Obiectul '" + *(yyvsp[-5].stringvalue) + "' nu este declarat.");
        } else {
            SymbolTable* cls = findClassScope(obj->type);
            if (!cls) {
                semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *(yyvsp[-5].stringvalue) + "').");
            } else {
                auto it = cls->vars.find(*(yyvsp[-3].stringvalue));
                if (it == cls->vars.end()) {
                    semanticError("Campul '" + *(yyvsp[-3].stringvalue) + "' nu exista in clasa '" + obj->type + "'.");
                } else {
                    if ((yyvsp[-1].node) && (yyvsp[-1].node)->tipNod != "unknown" && it->second.type != (yyvsp[-1].node)->tipNod) {
                        semanticError("Asignare incompatibila: campul '" + *(yyvsp[-3].stringvalue) + "' are tip "
                            + it->second.type + " dar expresia are tip " + (yyvsp[-1].node)->tipNod + ".");
                    }
                }
            }
        }
        (yyval.node) = nullptr; // conform cerintei: AST NULL pentru alte statement-uri
    }
#line 1585 "parser.tab.c"
    break;

  case 52: /* $@7: %empty  */
#line 525 "parser.y"
                  { argTypeVector.push_back(vector<string>()); }
#line 1591 "parser.tab.c"
    break;

  case 53: /* atribuiri_apeluri: NUMEVAR '(' $@7 arg_lista ')' ';'  */
#line 526 "parser.y"
    {
        string temp; checkFuncCall(*(yyvsp[-5].stringvalue), temp); 
        (yyval.node) = new ASTNode(Value(), NODE_OTHER);
    }
#line 1600 "parser.tab.c"
    break;

  case 54: /* $@8: %empty  */
#line 530 "parser.y"
                              { argTypeVector.push_back(vector<string>()); }
#line 1606 "parser.tab.c"
    break;

  case 55: /* atribuiri_apeluri: NUMEVAR '.' NUMEVAR '(' $@8 arg_lista ')' ';'  */
#line 531 "parser.y"
    {
        if(!argTypeVector.empty()) argTypeVector.pop_back();
        (yyval.node) = new ASTNode(Value(), NODE_OTHER);
    }
#line 1615 "parser.tab.c"
    break;

  case 56: /* variabila_decl: tipul_variabilei NUMEVAR ';'  */
#line 539 "parser.y"
    {
        string initVal = "0";
        if (*(yyvsp[-2].stringvalue) == "string" || *(yyvsp[-2].stringvalue) == "sos") initVal = "";
        currentTable->addVariable(*(yyvsp[-1].stringvalue), *(yyvsp[-2].stringvalue), initVal);
        (yyval.node) = nullptr;
    }
#line 1626 "parser.tab.c"
    break;

  case 57: /* variabila_decl: tipul_variabilei NUMEVAR '=' expresie ';'  */
#line 546 "parser.y"
    {
        string initVal = "0";
        if (*(yyvsp[-4].stringvalue) == "string" || *(yyvsp[-4].stringvalue) == "sos") initVal = "";
        currentTable->addVariable(*(yyvsp[-3].stringvalue), *(yyvsp[-4].stringvalue), initVal);
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].stringvalue));
        (yyval.node) = new ASTNode("=", idNode, (yyvsp[-1].node), NODE_ASSIGN);
    }
#line 1638 "parser.tab.c"
    break;

  case 58: /* obiect_decl: NUMEVAR NUMEVAR ';'  */
#line 557 "parser.y"
    {
        currentTable->addVariable(*(yyvsp[-1].stringvalue), *(yyvsp[-2].stringvalue), "null");
        (yyval.node) = nullptr;
    }
#line 1647 "parser.tab.c"
    break;

  case 59: /* obiect_decl: NUMEVAR NUMEVAR '=' expresie ';'  */
#line 562 "parser.y"
    {
        currentTable->addVariable(*(yyvsp[-3].stringvalue), *(yyvsp[-4].stringvalue), "null");
        ASTNode* idNode = new ASTNode(*(yyvsp[-3].stringvalue));
        (yyval.node) = new ASTNode("=", idNode, (yyvsp[-1].node), NODE_ASSIGN);
    }
#line 1657 "parser.tab.c"
    break;

  case 60: /* print_structura: PRINT '(' expresie ')' ';'  */
#line 570 "parser.y"
                               { (yyval.node) = new ASTNode(NODE_PRINT, (yyvsp[-2].node)); }
#line 1663 "parser.tab.c"
    break;

  case 62: /* arg_lista: arg_lista ',' expresie  */
#line 576 "parser.y"
                             { if (!argTypeVector.empty()) argTypeVector.back().push_back((yyvsp[0].node)->tipNod); }
#line 1669 "parser.tab.c"
    break;

  case 63: /* arg_lista: expresie  */
#line 577 "parser.y"
               { if (!argTypeVector.empty()) argTypeVector.back().push_back((yyvsp[0].node)->tipNod); }
#line 1675 "parser.tab.c"
    break;

  case 65: /* tipul_variabilei: TIPDATA_INT  */
#line 581 "parser.y"
                     { (yyval.stringvalue) = new string("int"); }
#line 1681 "parser.tab.c"
    break;

  case 66: /* tipul_variabilei: TIPDATA_FLOAT  */
#line 582 "parser.y"
                     { (yyval.stringvalue) = new string("float"); }
#line 1687 "parser.tab.c"
    break;

  case 67: /* tipul_variabilei: TIPDATA_STRING  */
#line 583 "parser.y"
                     { (yyval.stringvalue) = new string("string"); }
#line 1693 "parser.tab.c"
    break;

  case 68: /* tipul_variabilei: TIPDATA_BOOL  */
#line 584 "parser.y"
                     { (yyval.stringvalue) = new string("bool"); }
#line 1699 "parser.tab.c"
    break;

  case 69: /* tipul_variabilei: TIPDATA_VOID  */
#line 585 "parser.y"
                     { (yyval.stringvalue) = new string("void"); }
#line 1705 "parser.tab.c"
    break;

  case 70: /* expresie: expresie '+' expresie  */
#line 590 "parser.y"
        {
            (yyval.node) = new ASTNode("+", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '+' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
                (yyval.node)->tipNod = "unknown";
            } else {
                if (t1 == "bool") {
                    semanticError("Operatia '+' nu este permisa pe bool.");
                    (yyval.node)->tipNod = "unknown";
                } else {
                    (yyval.node)->tipNod = (yyvsp[-2].node)->tipNod;
                }
            }
        }
#line 1732 "parser.tab.c"
    break;

  case 71: /* expresie: expresie '-' expresie  */
#line 614 "parser.y"
        {
            (yyval.node) = new ASTNode("-", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '-' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
                (yyval.node)->tipNod = "unknown";
            } else {
                // '-' permis doar pe numeric
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '-' este permisa doar pe int/float.");
                    (yyval.node)->tipNod = "unknown";
                } else {
                    (yyval.node)->tipNod = (yyvsp[-2].node)->tipNod;
                }
            }
        }
#line 1760 "parser.tab.c"
    break;

  case 72: /* expresie: expresie '*' expresie  */
#line 639 "parser.y"
        {
            (yyval.node) = new ASTNode("*", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '*' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
                (yyval.node)->tipNod = "unknown";
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '*' este permisa doar pe int/float.");
                    (yyval.node)->tipNod = "unknown";
                } else {
                    (yyval.node)->tipNod = (yyvsp[-2].node)->tipNod;
                }
            }
        }
#line 1787 "parser.tab.c"
    break;

  case 73: /* expresie: expresie '/' expresie  */
#line 663 "parser.y"
        {
            (yyval.node) = new ASTNode("/", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Operatie '/' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
                (yyval.node)->tipNod = "unknown";
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Operatia '/' este permisa doar pe int/float.");
                    (yyval.node)->tipNod = "unknown";
                } else {
                    (yyval.node)->tipNod = (yyvsp[-2].node)->tipNod;
                }
            }
        }
#line 1814 "parser.tab.c"
    break;

  case 74: /* expresie: expresie '<' expresie  */
#line 687 "parser.y"
        {
            (yyval.node) = new ASTNode("<", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '<' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            } else {
                // optional: permiti doar numeric la < >
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '<' este permisa doar pe int/float.");
                }
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1839 "parser.tab.c"
    break;

  case 75: /* expresie: expresie '>' expresie  */
#line 709 "parser.y"
        {
            (yyval.node) = new ASTNode(">", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '>' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '>' este permisa doar pe int/float.");
                }
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1863 "parser.tab.c"
    break;

  case 76: /* expresie: expresie LE expresie  */
#line 730 "parser.y"
        {
            (yyval.node) = new ASTNode("<=", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '<=' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '<=' este permisa doar pe int/float.");
                }
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1887 "parser.tab.c"
    break;

  case 77: /* expresie: expresie GE expresie  */
#line 751 "parser.y"
        {
            (yyval.node) = new ASTNode(">=", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '>=' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            } else {
                if (t1 != "int" && t1 != "float") {
                    semanticError("Comparatia '>=' este permisa doar pe int/float.");
                }
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1911 "parser.tab.c"
    break;

  case 78: /* expresie: expresie EQ expresie  */
#line 772 "parser.y"
        {
            (yyval.node) = new ASTNode("==", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '==' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1931 "parser.tab.c"
    break;

  case 79: /* expresie: expresie NE expresie  */
#line 789 "parser.y"
        {
            (yyval.node) = new ASTNode("!=", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="carne") return "int";
                if (t=="cartofi") return "float";
                if (t=="salata") return "bool";
                if (t=="sos") return "string";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != t2) {
                semanticError("Comparatie '!=' intre tipuri diferite: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1951 "parser.tab.c"
    break;

  case 80: /* expresie: expresie AND expresie  */
#line 806 "parser.y"
        {
            (yyval.node) = new ASTNode("&&", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="salata") return "bool";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != "bool" || t2 != "bool") {
                semanticError("Operatie '&&' necesita bool && bool, dar ai: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1968 "parser.tab.c"
    break;

  case 81: /* expresie: expresie OR expresie  */
#line 820 "parser.y"
        {
            (yyval.node) = new ASTNode("||", (yyvsp[-2].node), (yyvsp[0].node));
            auto norm = [](const string& t)->string{
                if (t=="salata") return "bool";
                return t;
            };
            string t1 = norm((yyvsp[-2].node)->tipNod), t2 = norm((yyvsp[0].node)->tipNod);
            if (t1 != "bool" || t2 != "bool") {
                semanticError("Operatie '||' necesita bool || bool, dar ai: " + (yyvsp[-2].node)->tipNod + " si " + (yyvsp[0].node)->tipNod + ".");
            }
            (yyval.node)->tipNod = "bool";
        }
#line 1985 "parser.tab.c"
    break;

  case 82: /* expresie: '(' expresie ')'  */
#line 833 "parser.y"
                           { (yyval.node) = (yyvsp[-1].node); }
#line 1991 "parser.tab.c"
    break;

  case 83: /* expresie: NUMEVAR  */
#line 836 "parser.y"
        {
            (yyval.node) = new ASTNode(*(yyvsp[0].stringvalue));
            VarInfo* v = lookupVar(*(yyvsp[0].stringvalue), currentTable);
            if (!v) {
                semanticError("Identificatorul '" + *(yyvsp[0].stringvalue) + "' nu este declarat.");
                (yyval.node)->tipNod = "unknown";
            } else {
                (yyval.node)->tipNod = v->type;
            }
        }
#line 2006 "parser.tab.c"
    break;

  case 84: /* expresie: NUMEVAR '.' NUMEVAR  */
#line 848 "parser.y"
        {
            (yyval.node) = new ASTNode(Value(), NODE_OTHER);
            (yyval.node)->tipNod = "unknown";

            VarInfo* obj = lookupVar(*(yyvsp[-2].stringvalue), currentTable);
            if (!obj) {
                semanticError("Obiectul '" + *(yyvsp[-2].stringvalue) + "' nu este declarat.");
            } else {
                SymbolTable* cls = findClassScope(obj->type);
                if (!cls) {
                    semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *(yyvsp[-2].stringvalue) + "').");
                } else {
                    auto it = cls->vars.find(*(yyvsp[0].stringvalue));
                    if (it == cls->vars.end()) {
                        semanticError("Campul '" + *(yyvsp[0].stringvalue) + "' nu exista in clasa '" + obj->type + "'.");
                    } else {
                        (yyval.node)->tipNod = it->second.type;
                    }
                }
            }
        }
#line 2032 "parser.tab.c"
    break;

  case 85: /* expresie: INT_VAL  */
#line 869 "parser.y"
                    { (yyval.node) = new ASTNode(Value((yyvsp[0].intvalue)), NODE_INT);   (yyval.node)->tipNod = "int"; }
#line 2038 "parser.tab.c"
    break;

  case 86: /* expresie: FLOAT_VAL  */
#line 870 "parser.y"
                    { (yyval.node) = new ASTNode(Value((yyvsp[0].floatvalue)), NODE_FLOAT); (yyval.node)->tipNod = "float"; }
#line 2044 "parser.tab.c"
    break;

  case 87: /* expresie: STRING_VAL  */
#line 871 "parser.y"
                    { (yyval.node) = new ASTNode(Value(*(yyvsp[0].stringvalue)), NODE_STRING); (yyval.node)->tipNod = "string"; }
#line 2050 "parser.tab.c"
    break;

  case 88: /* expresie: BOOL_VAL  */
#line 872 "parser.y"
                    { (yyval.node) = new ASTNode(Value((bool)(yyvsp[0].intvalue)), NODE_BOOL); (yyval.node)->tipNod = "bool"; }
#line 2056 "parser.tab.c"
    break;

  case 89: /* $@9: %empty  */
#line 874 "parser.y"
                      { argTypeVector.push_back(vector<string>()); }
#line 2062 "parser.tab.c"
    break;

  case 90: /* expresie: NUMEVAR '(' $@9 arg_lista ')'  */
#line 875 "parser.y"
        {
            string temp; checkFuncCall(*(yyvsp[-4].stringvalue), temp);
            (yyval.node) = new ASTNode(Value(), NODE_OTHER);
            (yyval.node)->tipNod = temp;
        }
#line 2072 "parser.tab.c"
    break;

  case 91: /* expresie: NEW NUMEVAR '(' ')'  */
#line 882 "parser.y"
        {
            (yyval.node) = new ASTNode(Value(), NODE_OTHER);
            (yyval.node)->tipNod = *(yyvsp[-2].stringvalue); // tipul este numele clasei
        }
#line 2081 "parser.tab.c"
    break;

  case 92: /* $@10: %empty  */
#line 886 "parser.y"
                                  { argTypeVector.push_back(vector<string>()); }
#line 2087 "parser.tab.c"
    break;

  case 93: /* expresie: NUMEVAR '.' NUMEVAR '(' $@10 arg_lista ')'  */
#line 887 "parser.y"
        {
            vector<string> args;
            if (!argTypeVector.empty()) args = argTypeVector.back();
            if (!argTypeVector.empty()) argTypeVector.pop_back();

            (yyval.node) = new ASTNode(Value(), NODE_OTHER);
            (yyval.node)->tipNod = "unknown";

            VarInfo* obj = lookupVar(*(yyvsp[-6].stringvalue), currentTable);
            if (!obj) {
                semanticError("Obiectul '" + *(yyvsp[-6].stringvalue) + "' nu este declarat.");
            } else {
                SymbolTable* cls = findClassScope(obj->type);
                if (!cls) {
                    semanticError("Tipul '" + obj->type + "' nu este o clasa definita (pentru '" + *(yyvsp[-6].stringvalue) + "').");
                } else {
                    auto itf = cls->funcs.find(*(yyvsp[-4].stringvalue));
                    if (itf == cls->funcs.end()) {
                        semanticError("Metoda '" + *(yyvsp[-4].stringvalue) + "' nu exista in clasa '" + obj->type + "'.");
                    } else {
                        FuncInfo& mf = itf->second;
                        if (args.size() != mf.params.size()) {
                            semanticError("Apel invalid la metoda '" + obj->type + "." + *(yyvsp[-4].stringvalue)
                                + "': nr parametri asteptat " + to_string(mf.params.size())
                                + ", primit " + to_string(args.size()) + ".");
                        } else {
                            for (size_t i = 0; i < args.size(); i++) {
                                if (args[i] != "unknown" && args[i] != mf.params[i].type) {
                                    semanticError("Apel invalid la metoda '" + obj->type + "." + *(yyvsp[-4].stringvalue)
                                        + "': parametrul " + to_string(i+1) + " asteapta "
                                        + mf.params[i].type + ", primit " + args[i] + ".");
                                }
                            }
                        }
                        (yyval.node)->tipNod = mf.returnType;
                    }
                }
            }
        }
#line 2131 "parser.tab.c"
    break;


#line 2135 "parser.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 929 "parser.y"


void yyerror(const char* s) { cout << "Eroare de sintaxa la linia " << yylineno << ": " << s << endl; }

SymbolTable* globalTable = nullptr;
SymbolTable* currentTable = nullptr;
vector<SymbolTable*> allTables;
vector<ParamInfo> currentParams;
vector<vector<string>> argTypeVector;
bool semanticOk = true;

void semanticError(const string& msg) {
    semanticOk = false;
    cout << "Eroare semantica la linia " << yylineno << ": " << msg << endl;
}


SymbolTable* findClassScope(const string& className) {
    string scopeName = "class " + className;
    if (!globalTable) return nullptr;
    auto it = globalTable->children.find(scopeName);
    if (it != globalTable->children.end()) return it->second;
    return nullptr;
}

VarInfo* lookupVar(const string& name, SymbolTable* start) {
    SymbolTable* t = start;
    while (t) {
        auto it = t->vars.find(name);
        if (it != t->vars.end()) return &it->second;
        t = t->parinte;
    }
    return nullptr;
}

FuncInfo* lookupFunc(const string& name, SymbolTable* start) {
    SymbolTable* t = start;
    while (t) {
        auto it = t->funcs.find(name);
        if (it != t->funcs.end()) return &it->second;
        t = t->parinte;
    }
    return nullptr;
}

void checkFuncCall(const string& funcName, string& retType) {
    FuncInfo* f = lookupFunc(funcName, currentTable);
    if (!f) {
        semanticError("Functia '" + funcName + "' nu este declarata.");
        if(!argTypeVector.empty()) argTypeVector.pop_back();
        retType = "unknown";
        return;
    }

    vector<string> args;
    if (!argTypeVector.empty()) args = argTypeVector.back();
    if(!argTypeVector.empty()) argTypeVector.pop_back();

    if (args.size() != f->params.size()) {
        semanticError("Apel invalid la '" + funcName + "': nr parametri asteptat "
            + to_string(f->params.size()) + ", primit " + to_string(args.size()) + ".");
        retType = f->returnType;
        return;
    }

    for (size_t i = 0; i < args.size(); i++) {
        if (args[i] != "unknown" && args[i] != f->params[i].type) {
            semanticError("Apel invalid la '" + funcName + "': parametrul " + to_string(i+1)
                + " asteapta " + f->params[i].type + ", primit " + args[i] + ".");
        }
    }
    retType = f->returnType;
}

void initSymbolTables() {
    globalTable = new SymbolTable("global", nullptr);
    currentTable = globalTable;
    allTables.push_back(globalTable);
}

void printAllTables(const string& filename) {
    ofstream out(filename);
    if(globalTable) globalTable->print(out);
    out.close();
}
