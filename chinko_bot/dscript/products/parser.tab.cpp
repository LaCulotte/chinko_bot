/* A Bison parser, made by GNU Bison 3.7.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 2

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 19 "chinko_bot/dscript/parser.y"

#include <unordered_map>
#include <stdexcept>
#include <stdio.h>
#include <iostream>
#include <string>
#include <math.h>
#include "std.h"
#include "../../../Var/Var.h"
#include "gramm_funcs.h"

using namespace std; 

#line 85 "chinko_bot/dscript/products/parser.tab.cpp"

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
  YYSYMBOL_NATURAL = 3,                    /* NATURAL  */
  YYSYMBOL_REAL = 4,                       /* REAL  */
  YYSYMBOL_CHARACT = 5,                    /* CHARACT  */
  YYSYMBOL_STR = 6,                        /* STR  */
  YYSYMBOL_TBOOL = 7,                      /* TBOOL  */
  YYSYMBOL_TCHAR = 8,                      /* TCHAR  */
  YYSYMBOL_TINT8 = 9,                      /* TINT8  */
  YYSYMBOL_TUINT8 = 10,                    /* TUINT8  */
  YYSYMBOL_TINT32 = 11,                    /* TINT32  */
  YYSYMBOL_TUINT32 = 12,                   /* TUINT32  */
  YYSYMBOL_TDOUBLE = 13,                   /* TDOUBLE  */
  YYSYMBOL_TSTR = 14,                      /* TSTR  */
  YYSYMBOL_TRUE = 15,                      /* TRUE  */
  YYSYMBOL_FALSE = 16,                     /* FALSE  */
  YYSYMBOL_IDENT = 17,                     /* IDENT  */
  YYSYMBOL_COMMA = 18,                     /* COMMA  */
  YYSYMBOL_LOR = 19,                       /* LOR  */
  YYSYMBOL_LAND = 20,                      /* LAND  */
  YYSYMBOL_BOR = 21,                       /* BOR  */
  YYSYMBOL_BXOR = 22,                      /* BXOR  */
  YYSYMBOL_BAND = 23,                      /* BAND  */
  YYSYMBOL_EQ = 24,                        /* EQ  */
  YYSYMBOL_NEQ = 25,                       /* NEQ  */
  YYSYMBOL_GT = 26,                        /* GT  */
  YYSYMBOL_LT = 27,                        /* LT  */
  YYSYMBOL_GTEQ = 28,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 29,                      /* LTEQ  */
  YYSYMBOL_LSHIFT = 30,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 31,                    /* RSHIFT  */
  YYSYMBOL_PLUS = 32,                      /* PLUS  */
  YYSYMBOL_MINUS = 33,                     /* MINUS  */
  YYSYMBOL_MULT = 34,                      /* MULT  */
  YYSYMBOL_DIV = 35,                       /* DIV  */
  YYSYMBOL_MOD = 36,                       /* MOD  */
  YYSYMBOL_POW = 37,                       /* POW  */
  YYSYMBOL_LNOT = 38,                      /* LNOT  */
  YYSYMBOL_BNOT = 39,                      /* BNOT  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_UNARY_MINUS = 41,               /* UNARY_MINUS  */
  YYSYMBOL_LPAREN = 42,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 43,                    /* RPAREN  */
  YYSYMBOL_LET = 44,                       /* LET  */
  YYSYMBOL_FUNC = 45,                      /* FUNC  */
  YYSYMBOL_INIT_ARGS = 46,                 /* INIT_ARGS  */
  YYSYMBOL_INIT_FUNC = 47,                 /* INIT_FUNC  */
  YYSYMBOL_IF = 48,                        /* IF  */
  YYSYMBOL_ELSE = 49,                      /* ELSE  */
  YYSYMBOL_LBRACK = 50,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 51,                    /* RBRACK  */
  YYSYMBOL_PTV = 52,                       /* PTV  */
  YYSYMBOL_ASSIGN = 53,                    /* ASSIGN  */
  YYSYMBOL_WHILE = 54,                     /* WHILE  */
  YYSYMBOL_FOR = 55,                       /* FOR  */
  YYSYMBOL_TO = 56,                        /* TO  */
  YYSYMBOL_IFELSE = 57,                    /* IFELSE  */
  YYSYMBOL_CREATEVAR = 58,                 /* CREATEVAR  */
  YYSYMBOL_CREATEASSIGN = 59,              /* CREATEASSIGN  */
  YYSYMBOL_TYPE = 60,                      /* TYPE  */
  YYSYMBOL_PLUSASS = 61,                   /* PLUSASS  */
  YYSYMBOL_MINUSASS = 62,                  /* MINUSASS  */
  YYSYMBOL_MULTASS = 63,                   /* MULTASS  */
  YYSYMBOL_DIVASS = 64,                    /* DIVASS  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_Program = 66,                   /* Program  */
  YYSYMBOL_Functions = 67,                 /* Functions  */
  YYSYMBOL_Args = 68,                      /* Args  */
  YYSYMBOL_ArgsRec = 69,                   /* ArgsRec  */
  YYSYMBOL_Sequence = 70,                  /* Sequence  */
  YYSYMBOL_Instruction = 71,               /* Instruction  */
  YYSYMBOL_Assignment = 72,                /* Assignment  */
  YYSYMBOL_Type = 73,                      /* Type  */
  YYSYMBOL_Expression = 74,                /* Expression  */
  YYSYMBOL_Ops = 75,                       /* Ops  */
  YYSYMBOL_Paren = 76,                     /* Paren  */
  YYSYMBOL_Nat = 77,                       /* Nat  */
  YYSYMBOL_Real = 78,                      /* Real  */
  YYSYMBOL_Char = 79,                      /* Char  */
  YYSYMBOL_Bool = 80,                      /* Bool  */
  YYSYMBOL_Str = 81,                       /* Str  */
  YYSYMBOL_Var = 82                        /* Var  */
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
#define YYFINAL  46
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   493

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  144

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   319


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    75,    75,    77,    78,    80,    81,    83,    84,    86,
      87,    88,    90,    91,    92,    93,    94,    95,    96,    97,
      99,   100,   101,   102,   103,   104,   105,   107,   108,   109,
     110,   111,   112,   113,   114,   116,   116,   116,   116,   116,
     116,   116,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   137,   138,   139,   140,   141,   143,   144,
     145,   146,   147,   148,   149,   150
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
  "\"end of file\"", "error", "\"invalid token\"", "NATURAL", "REAL",
  "CHARACT", "STR", "TBOOL", "TCHAR", "TINT8", "TUINT8", "TINT32",
  "TUINT32", "TDOUBLE", "TSTR", "TRUE", "FALSE", "IDENT", "COMMA", "LOR",
  "LAND", "BOR", "BXOR", "BAND", "EQ", "NEQ", "GT", "LT", "GTEQ", "LTEQ",
  "LSHIFT", "RSHIFT", "PLUS", "MINUS", "MULT", "DIV", "MOD", "POW", "LNOT",
  "BNOT", "RETURN", "UNARY_MINUS", "LPAREN", "RPAREN", "LET", "FUNC",
  "INIT_ARGS", "INIT_FUNC", "IF", "ELSE", "LBRACK", "RBRACK", "PTV",
  "ASSIGN", "WHILE", "FOR", "TO", "IFELSE", "CREATEVAR", "CREATEASSIGN",
  "TYPE", "PLUSASS", "MINUSASS", "MULTASS", "DIVASS", "$accept", "Program",
  "Functions", "Args", "ArgsRec", "Sequence", "Instruction", "Assignment",
  "Type", "Expression", "Ops", "Paren", "Nat", "Real", "Char", "Bool",
  "Str", "Var", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319
};
#endif

#define YYPACT_NINF (-48)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-7)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      16,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -48,   -30,
     141,   141,   141,   265,    18,   -24,   -48,    16,   -31,     5,
     -14,    -1,   -48,   -48,   -48,   -48,   -48,   -48,   -11,   141,
     141,   141,   141,   166,   -48,   -48,   -48,   -48,   -48,   -48,
     -48,   -48,   201,   234,   -48,   -20,   -48,    26,   -48,   -48,
     -13,   141,   141,   141,   141,   141,    -7,   300,   110,    24,
     378,   378,   326,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   141,   141,
     141,   141,   141,   -48,    16,    16,   141,     4,   141,   378,
     378,   378,   378,   378,   -48,    10,   -48,   352,   -48,   397,
     415,   432,   448,   136,   180,   213,   213,   275,   275,   275,
     275,   -26,   -26,    24,    24,    14,    14,    14,    14,     6,
      12,   267,    22,   378,   -48,   -48,    17,   -48,    16,    29,
     479,    30,    28,    32,     5,    16,   -48,    16,    49,    55,
      56,   -48,   -48,   -48
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,    27,    28,    29,    30,    31,    32,    33,    34,    75,
       0,     0,     0,     0,     0,     2,     3,    10,     0,     0,
       0,     0,    69,    70,    71,    74,    72,    73,    75,     0,
       0,     0,     0,     0,    41,    42,    35,    36,    37,    38,
      39,    40,     0,     0,    75,     0,     1,     0,     9,    16,
      26,     0,     0,     0,     0,     0,     0,     0,     0,    65,
      63,    64,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    11,    11,     0,     0,     0,    20,
      21,    22,    23,    24,    18,     0,    67,     0,    68,    62,
      56,    55,    59,    58,    57,    43,    44,    45,    46,    47,
      48,    60,    61,    49,    50,    51,    52,    53,    54,     0,
       0,     0,     8,    25,    17,    66,    12,    14,    11,     0,
       0,     0,     0,     0,     0,    11,    15,    11,     5,     0,
       0,     7,    13,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -48,   -48,   -48,   -48,   -48,   -16,   -48,    60,   -47,    23,
     -48,   -48,   -48,   -48,   -48,   -48,   -48,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    14,    15,   129,   130,    16,    17,    18,    19,    33,
      34,    35,    36,    37,    38,    39,    40,    41
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      20,    48,    22,    23,    24,    25,    77,    78,    79,    80,
      81,    82,    21,    20,    26,    27,    28,    20,    46,    50,
      47,    49,    44,     1,     2,     3,     4,     5,     6,     7,
       8,    58,    29,     9,    42,    43,    86,    30,    31,    51,
      88,    32,    56,    87,    57,    94,   122,    52,    53,    54,
      55,    82,    59,    60,    61,    62,    10,   126,    79,    80,
      81,    82,   124,   127,    11,    -6,   131,   141,   119,   120,
      12,    13,   133,    45,    89,    90,    91,    92,    93,   136,
     135,    97,   137,   134,    20,    20,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,   111,   112,
     113,   114,   115,   116,   117,   118,   142,   143,     0,   121,
       0,   123,   132,    22,    23,    24,    25,     0,     0,   139,
       0,   140,     0,     0,     0,    26,    27,    28,    20,     0,
       0,     0,     0,     0,   138,    20,     0,    20,     0,     0,
       0,     0,     0,    29,    22,    23,    24,    25,    30,    31,
       0,     0,    32,    96,     0,     0,    26,    27,    28,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    29,     0,     0,     0,     0,    30,
      31,     0,     0,    32,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    84,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,     1,     2,     3,     4,     5,     6,     7,     8,
       0,     0,    44,     0,    85,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    75,    76,    77,    78,    79,
      80,    81,    82,     0,     0,     0,     0,   128,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,     0,     0,
       0,     0,     0,    95,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,     0,     0,     0,     0,     0,    98,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
       0,     0,     0,     0,     0,   125,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,     1,     2,     3,     4,
       5,     6,     7,     8
};

static const yytype_int16 yycheck[] =
{
       0,    17,     3,     4,     5,     6,    32,    33,    34,    35,
      36,    37,    42,    13,    15,    16,    17,    17,     0,    19,
      44,    52,    17,     7,     8,     9,    10,    11,    12,    13,
      14,    42,    33,    17,    11,    12,    56,    38,    39,    53,
      53,    42,    43,    17,    21,    52,    42,    61,    62,    63,
      64,    37,    29,    30,    31,    32,    40,    51,    34,    35,
      36,    37,    52,    51,    48,    43,    49,    18,    84,    85,
      54,    55,    43,    13,    51,    52,    53,    54,    55,    51,
      50,    58,    50,   130,    84,    85,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    51,    51,    -1,    86,
      -1,    88,   128,     3,     4,     5,     6,    -1,    -1,   135,
      -1,   137,    -1,    -1,    -1,    15,    16,    17,   128,    -1,
      -1,    -1,    -1,    -1,   134,   135,    -1,   137,    -1,    -1,
      -1,    -1,    -1,    33,     3,     4,     5,     6,    38,    39,
      -1,    -1,    42,    43,    -1,    -1,    15,    16,    17,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    33,    -1,    -1,    -1,    -1,    38,
      39,    -1,    -1,    42,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    52,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    50,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,     7,     8,     9,    10,    11,    12,    13,    14,
      -1,    -1,    17,    -1,    50,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    30,    31,    32,    33,    34,
      35,    36,    37,    -1,    -1,    -1,    -1,    50,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    -1,    -1,
      -1,    -1,    -1,    43,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    -1,    -1,    -1,    -1,    -1,    43,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      -1,    -1,    -1,    -1,    -1,    43,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,     7,     8,     9,    10,
      11,    12,    13,    14
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    12,    13,    14,    17,
      40,    48,    54,    55,    66,    67,    70,    71,    72,    73,
      82,    42,     3,     4,     5,     6,    15,    16,    17,    33,
      38,    39,    42,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    74,    74,    17,    72,     0,    44,    70,    52,
      82,    53,    61,    62,    63,    64,    43,    74,    42,    74,
      74,    74,    74,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    52,    50,    50,    56,    17,    53,    74,
      74,    74,    74,    74,    52,    43,    43,    74,    43,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    70,
      70,    74,    42,    74,    52,    43,    51,    51,    50,    68,
      69,    49,    70,    43,    73,    50,    51,    50,    82,    70,
      70,    18,    51,    51
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    67,    67,    68,    68,    69,    69,    70,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    74,    74,    74,    74,    74,
      74,    74,    74,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    75,    75,    75,    76,    77,
      78,    79,    80,    80,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     9,     3,     0,     4,     0,     2,
       1,     0,     5,     9,     5,     7,     2,     5,     4,     3,
       3,     3,     3,     3,     3,     4,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     4,     3,     3,     1,
       1,     1,     1,     1,     1,     1
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
        yyerror (scanner, data, YY_("syntax error: cannot back up")); \
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
                  Kind, Value, scanner, data); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t scanner, parser_data_t *data)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (scanner);
  YYUSE (data);
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
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, yyscan_t scanner, parser_data_t *data)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep, scanner, data);
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
                 int yyrule, yyscan_t scanner, parser_data_t *data)
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
                       &yyvsp[(yyi + 1) - (yynrhs)], scanner, data);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule, scanner, data); \
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
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, yyscan_t scanner, parser_data_t *data)
{
  YYUSE (yyvaluep);
  YYUSE (scanner);
  YYUSE (data);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (yyscan_t scanner, parser_data_t *data)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

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
      yychar = yylex (&yylval, scanner);
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
  case 2: /* Program: Functions  */
#line 75 "chinko_bot/dscript/parser.y"
                                                                                        { execute(data, (yyvsp[0].instr)); }
#line 1330 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 3: /* Functions: Sequence  */
#line 77 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1336 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 4: /* Functions: Functions LET IDENT LPAREN Args RPAREN LBRACK Sequence RBRACK  */
#line 78 "chinko_bot/dscript/parser.y"
                                                                                              { declarefunc(data, (yyvsp[-6].strval), (yyvsp[-4].instr), (yyvsp[-1].instr)); (yyval.instr) = (yyvsp[-8].instr); }
#line 1342 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 5: /* Args: ArgsRec Type Var  */
#line 80 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = seq(createvar(data, (yyvsp[-1].intval), (yyvsp[0].instr)), (yyvsp[-2].instr)); }
#line 1348 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 6: /* Args: %empty  */
#line 81 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1354 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 7: /* ArgsRec: ArgsRec Type Var COMMA  */
#line 83 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = seq(createvar(data, (yyvsp[-2].intval), (yyvsp[-1].instr)), (yyvsp[-3].instr)); }
#line 1360 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 8: /* ArgsRec: %empty  */
#line 84 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1366 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 9: /* Sequence: Instruction Sequence  */
#line 86 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = seq((yyvsp[-1].instr), (yyvsp[0].instr)); }
#line 1372 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 10: /* Sequence: Instruction  */
#line 87 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = (yyvsp[0].instr); }
#line 1378 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 11: /* Sequence: %empty  */
#line 88 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1384 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 12: /* Instruction: IF Expression LBRACK Sequence RBRACK  */
#line 90 "chinko_bot/dscript/parser.y"
                                                    { (yyval.instr) = ifinst(data, (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1390 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 13: /* Instruction: IF Expression LBRACK Sequence RBRACK ELSE LBRACK Sequence RBRACK  */
#line 91 "chinko_bot/dscript/parser.y"
                                                                                                        { (yyval.instr) = ifelseinst(data, (yyvsp[-7].instr), (yyvsp[-5].instr), (yyvsp[-1].instr)); }
#line 1396 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 14: /* Instruction: WHILE Expression LBRACK Sequence RBRACK  */
#line 92 "chinko_bot/dscript/parser.y"
                                                                                                                                { (yyval.instr) = whileinst(data, (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1402 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 15: /* Instruction: FOR Assignment TO Expression LBRACK Sequence RBRACK  */
#line 93 "chinko_bot/dscript/parser.y"
                                                                                                                        { (yyval.instr) = forinst(data, (yyvsp[-5].instr), (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1408 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 16: /* Instruction: Assignment PTV  */
#line 94 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[-1].instr); }
#line 1414 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 17: /* Instruction: IDENT LPAREN Expression RPAREN PTV  */
#line 95 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-4].strval), (yyvsp[-2].instr)); }
#line 1420 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 18: /* Instruction: IDENT LPAREN RPAREN PTV  */
#line 96 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = loadfunction(data, (yyvsp[-3].strval), NULL); }
#line 1426 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 19: /* Instruction: RETURN Expression PTV  */
#line 97 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = unary_operator(data, (yyvsp[-1].instr), RETURN); }
#line 1432 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 20: /* Assignment: Var ASSIGN Expression  */
#line 99 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = assignment(data, (yyvsp[-2].instr), (yyvsp[0].instr)); }
#line 1438 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 21: /* Assignment: Var PLUSASS Expression  */
#line 100 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), PLUSASS); }
#line 1444 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 22: /* Assignment: Var MINUSASS Expression  */
#line 101 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MINUSASS); }
#line 1450 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 23: /* Assignment: Var MULTASS Expression  */
#line 102 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MULTASS); }
#line 1456 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 24: /* Assignment: Var DIVASS Expression  */
#line 103 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), DIVASS); }
#line 1462 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 25: /* Assignment: Type Var ASSIGN Expression  */
#line 104 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = create_assign(data, (yyvsp[-3].intval), (yyvsp[-2].instr), (yyvsp[0].instr)); }
#line 1468 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 26: /* Assignment: Type Var  */
#line 105 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = createvar(data, (yyvsp[-1].intval), (yyvsp[0].instr)); }
#line 1474 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 27: /* Type: TBOOL  */
#line 107 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.intval) = BOOL; }
#line 1480 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 28: /* Type: TCHAR  */
#line 108 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = CHAR; }
#line 1486 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 29: /* Type: TINT8  */
#line 109 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = INT8; }
#line 1492 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 30: /* Type: TUINT8  */
#line 110 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = UINT8; }
#line 1498 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 31: /* Type: TINT32  */
#line 111 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = INT32; }
#line 1504 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 32: /* Type: TUINT32  */
#line 112 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = UINT32; }
#line 1510 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 33: /* Type: TDOUBLE  */
#line 113 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = DOUBLE; }
#line 1516 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 34: /* Type: TSTR  */
#line 114 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.intval) = STRING; }
#line 1522 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 42: /* Expression: Paren  */
#line 116 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = (yyvsp[0].instr); }
#line 1528 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 43: /* Ops: Expression EQ Expression  */
#line 117 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), EQ); }
#line 1534 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 44: /* Ops: Expression NEQ Expression  */
#line 118 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), NEQ); }
#line 1540 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 45: /* Ops: Expression GT Expression  */
#line 119 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), GT); }
#line 1546 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 46: /* Ops: Expression LT Expression  */
#line 120 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LT); }
#line 1552 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 47: /* Ops: Expression GTEQ Expression  */
#line 121 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), GTEQ); }
#line 1558 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 48: /* Ops: Expression LTEQ Expression  */
#line 122 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LTEQ); }
#line 1564 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 49: /* Ops: Expression PLUS Expression  */
#line 123 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), PLUS); }
#line 1570 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 50: /* Ops: Expression MINUS Expression  */
#line 124 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MINUS); }
#line 1576 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 51: /* Ops: Expression MULT Expression  */
#line 125 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MULT); }
#line 1582 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 52: /* Ops: Expression DIV Expression  */
#line 126 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), DIV); }
#line 1588 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 53: /* Ops: Expression MOD Expression  */
#line 127 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MOD); }
#line 1594 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 54: /* Ops: Expression POW Expression  */
#line 128 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), POW); }
#line 1600 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 55: /* Ops: Expression LAND Expression  */
#line 129 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LAND); }
#line 1606 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 56: /* Ops: Expression LOR Expression  */
#line 130 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LOR); }
#line 1612 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 57: /* Ops: Expression BAND Expression  */
#line 131 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BAND); }
#line 1618 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 58: /* Ops: Expression BXOR Expression  */
#line 132 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BXOR); }
#line 1624 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 59: /* Ops: Expression BOR Expression  */
#line 133 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BOR); }
#line 1630 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 60: /* Ops: Expression LSHIFT Expression  */
#line 134 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LSHIFT); }
#line 1636 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 61: /* Ops: Expression RSHIFT Expression  */
#line 135 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), RSHIFT); }
#line 1642 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 62: /* Ops: Expression COMMA Expression  */
#line 136 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), COMMA); }
#line 1648 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 63: /* Ops: LNOT Expression  */
#line 137 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), LNOT); }
#line 1654 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 64: /* Ops: BNOT Expression  */
#line 138 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), BNOT); }
#line 1660 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 65: /* Ops: MINUS Expression  */
#line 139 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), UNARY_MINUS); }
#line 1666 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 66: /* Ops: IDENT LPAREN Expression RPAREN  */
#line 140 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-3].strval), (yyvsp[-1].instr)); }
#line 1672 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 67: /* Ops: IDENT LPAREN RPAREN  */
#line 141 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-2].strval), NULL); }
#line 1678 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 68: /* Paren: LPAREN Expression RPAREN  */
#line 143 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = (yyvsp[-1].instr); }
#line 1684 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 69: /* Nat: NATURAL  */
#line 144 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadnatural(data, (yyvsp[0].intval)); }
#line 1690 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 70: /* Real: REAL  */
#line 145 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadreal(data, (yyvsp[0].doubleval)); }
#line 1696 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 71: /* Char: CHARACT  */
#line 146 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadnatural(data, (yyvsp[0].intval)); }
#line 1702 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 72: /* Bool: TRUE  */
#line 147 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadnatural(data, 1); }
#line 1708 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 73: /* Bool: FALSE  */
#line 148 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = loadnatural(data, 0); }
#line 1714 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 74: /* Str: STR  */
#line 149 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = loadstr(data, (yyvsp[0].strval)); }
#line 1720 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 75: /* Var: IDENT  */
#line 150 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadvar(data, (yyvsp[0].strval)); }
#line 1726 "chinko_bot/dscript/products/parser.tab.cpp"
    break;


#line 1730 "chinko_bot/dscript/products/parser.tab.cpp"

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
      yyerror (scanner, data, YY_("syntax error"));
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
                      yytoken, &yylval, scanner, data);
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, scanner, data);
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
  yyerror (scanner, data, YY_("memory exhausted"));
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
                  yytoken, &yylval, scanner, data);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, scanner, data);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 152 "chinko_bot/dscript/parser.y"


#include "products/parser.tab.h"
#include "products/lexer.h"


void throw_exception(const string err, int nl) {
	string error;
	if(nl>0)
		error = "Error on line "+to_string(nl)+": "+err;
	else
		error = "Error: "+err;
	throw runtime_error(error);
}

int yyerror(yyscan_t scanner, parser_data_t *data, const char *s) {
	throw_exception(string(s), data->nline);
}


void dscript_cmd(const char *code) {
	parser_data_t data = {};
	data.nline = 1;
	data.fst_el = NULL;
	data.variables = {};
	initstd(&data);

	yyscan_t scanner;
	if(yylex_init(&scanner)) {
		throw runtime_error("Error while initializing the parser.");
	}
	yylex_init_extra(&data, &scanner);
	YY_BUFFER_STATE buf = yy_scan_string(code, scanner);
	try {
		yyparse(scanner, &data);
	} catch(const exception& e) {
		yy_delete_buffer(buf, scanner);
		yylex_destroy(scanner);
		free_list(data.fst_el);
		// SI TU VEUX CHANGER LA MANIÈRE DONT SONT GÉRÉES LES EXCEPTIONS C'EST ICI...
		throw runtime_error(e.what());
	}
	yy_delete_buffer(buf, scanner);
	yylex_destroy(scanner);
	free_list(data.fst_el);
}

void dscript(const char *file) {
	FILE *fp = fopen(file, "r");
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);
	char code[size+1];
	
	fread(code, 1, size, fp);
	code[size] = 0x0;
	try {
		dscript_cmd(code);
	} catch(const exception& e) {
		fclose(fp);
		// ...ET ICI
		throw runtime_error(e.what());
	}
	
	fclose(fp);
}


void free_list(el_alloced_t *list) {
	el_alloced_t *cur = list;
	while(cur!=NULL) {
		el_alloced_t *tmp = cur->next;
		if(cur->type==0)
			free(cur->el);
		else
			delete (string*)cur->el;
		free(cur);
		cur = tmp;
	}
}


void disp_recur(ast *x, int nbsp) {
	for(int i=0; i<nbsp; i++)
		printf(" ");
	switch(x->token) {
		case COMMA:
			printf(",\n");
			break;
		case IFELSE:
			printf("IFELSE\n");
			break;
		case IF:
			printf("IF\n");
			break;
		case ELSE:
			printf("ELSE\n");
			break;
		case WHILE:
			printf("WHILE\n");
			break;
		case FOR:
			printf("FOR\n");
			break;
		case NATURAL:
			cout << x->intvalue << endl;
			break;
		case REAL:
			cout << x->doublevalue << endl;
			break;
		case MULT:
			printf("*\n");
			break;
		case DIV:
			printf("/\n");
			break;
		case EQ:
			printf("==\n");
			break;
		case LT:
			printf("<\n");
			break;
		case ASSIGN:
			printf("=\n");
			break;
		case PLUS:
			printf("+\n");
			break;
		case MINUS:
		case UNARY_MINUS:
			printf("-\n");
			break;
		case FUNC:
			cout << "f ";
		case IDENT:
			cout << *x->strvalue << endl;
			break;
		default:
			printf("%d\n", x->token);

	}
	if(x->fst_child)
		disp_recur(x->fst_child, nbsp+2);
	if(x->next_sibling)
		disp_recur(x->next_sibling, nbsp);
}


void execute(parser_data_t *data, ast *x) {
	cout << endl;
	disp_recur(x, 0);
	cout << endl;
	run(data, x, true);
}


void parse_params(parser_data_t *data, vector<sp<IVar>> *dst, ast *ast) {
	if(ast->token == COMMA) {
		dst->insert(dst->begin(), parse_expr(data, ast->fst_child->next_sibling));
		parse_params(data, dst, ast->fst_child);
	} else
		dst->insert(dst->begin(), parse_expr(data, ast));
}


sp<IVar> parse_expr(parser_data_t *data, ast *ast) {
	/* CHECKING TYPES COMPATIBILITY */
	sp<IVar> expr1;
	sp<IVar> expr2;
	if(ast->fst_child != NULL && ast->token != FUNC) {
		expr1 = parse_expr(data, ast->fst_child);
		if(ast->token != COMMA && ast->fst_child->next_sibling != NULL) {
			expr2 = parse_expr(data, ast->fst_child->next_sibling);
			watchdog_type(expr1->get_type(), expr2->get_type(), ast);
		}
	}

	switch(ast->token) {
		case COMMA:
			throw_exception("syntax error ','", ast->nline);
		case FUNC: {
			sp<IVar> ret = runfunc(data, *ast->strvalue, ast);
			if(ret==NULL)
				throw_exception("void function in expression", ast->nline);
			return ret;
		} case PLUS:
			return *expr1+(*expr2);
		case MINUS:
			return *expr1-(*expr2);
		case MULT:
			return *expr1*(*expr2);
		case DIV:
			return *expr1/(*expr2);
		case MOD:
			return *expr1%(*expr2);
		case POW: {
			vector<sp<IVar>> args = {expr1, expr2};
			return stdpow(args);
		} case UNARY_MINUS: {
			const sp<IVar> ZERO = make_shared<Var<int>>(0);
			return *ZERO - *parse_expr(data, ast->fst_child);
		} case EQ:
			return make_shared<Var<bool>>(*expr1==(*expr2));
		case LT:
			return make_shared<Var<bool>>(*expr1<(*expr2));
		case GT:
			return make_shared<Var<bool>>(*expr1>(*expr2));
		case LTEQ:
			return make_shared<Var<bool>>(*expr1<=(*expr2));
		case GTEQ:
			return make_shared<Var<bool>>(*expr1>=(*expr2));
		//case LAND:
		//	return *expr1 && (*expr2);
		//case LOR:
		//	return *expr1 || (*expr2);
		//case LNOT:
		//	return !*expr1;
		case BAND:
			return *expr1 & (*expr2);
		case BXOR:
			return *expr1 ^ (*expr2);
		case BOR:
			return *expr1 | (*expr2);
		//case BNOT:
		//	return ~ *expr1;
		case NATURAL:
			return make_shared<Var<uint32_t>>(ast->intvalue);
		case REAL:
			return make_shared<Var<double>>(ast->doublevalue);
		case STR:
			return make_shared<Var<string>>(*ast->strvalue);
		case IDENT:
			string varname = *ast->strvalue;
			if(data->variables.find(varname) == data->variables.end())
				throw_exception("unknown variable!", ast->nline);
			return data->variables.at(varname);
	}
	return 0;
}


sp<IVar> run(parser_data_t *data, ast *ast, bool recur) {
	if(ast==NULL)
		return NULL;
	switch(ast->token) {
		case IF:
			if(parse_expr(data, ast->fst_child))
				run(data, ast->fst_child->next_sibling, true);
			break;
		case IFELSE:
			if(parse_expr(data, ast->fst_child))
				run(data, ast->fst_child->next_sibling->fst_child, true);
			else
				run(data, ast->fst_child->next_sibling->next_sibling->fst_child, true);
			break;
		case WHILE:
			while(*(bool*)(*parse_expr(data, ast->fst_child)).value)
				run(data, ast->fst_child->next_sibling, true);
			break;
		case FOR: {
			run(data, ast->fst_child, false);
			string varname = *ast->fst_child->next_sibling->fst_child->strvalue;
			const IVar ONE = Var<int>(1);
			while(*(bool*)(*parse_expr(data, ast->fst_child->next_sibling)).value) {
				run(data, ast->fst_child->next_sibling->next_sibling, true);
				data->variables.at(varname) = cast_type(data->variables.at(varname)->get_type(), *data->variables.at(varname)+ONE);
			}
			break;
		} case CREATEVAR: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(data->variables.find(varname) != data->variables.end())
				throw_exception("variable initialized twice!", ast->nline);
			const sp<IVar> ZERO = cast_type(ast->fst_child->intvalue, make_shared<Var<int>>(0));
			data->variables.insert({varname, ZERO});
			break;
		} case CREATEASSIGN: {
			string varname = *ast->fst_child->next_sibling->strvalue;
			if(data->variables.find(varname) != data->variables.end())
				throw_exception("variable initialized twice!", ast->nline);
			sp<IVar> val = cast_type(ast->fst_child->intvalue, parse_expr(data, ast->fst_child->next_sibling->next_sibling));
			data->variables.insert({varname, val});
			break;
		} case ASSIGN: {
			string varname = *ast->fst_child->strvalue;
			if(data->variables.find(varname) == data->variables.end())
				throw_exception("unknown variable!", ast->nline);
			sp<IVar> val = cast_type(data->variables.at(varname)->get_type(), parse_expr(data, ast->fst_child->next_sibling));
			data->variables.at(varname) = val;
			break;
		}
		case PLUSASS:
		case MINUSASS:
		case MULTASS:
		case DIVASS: {
			string varname = *ast->fst_child->strvalue;
			if(data->variables.find(varname) == data->variables.end())
				throw_exception("unknown variable!", ast->nline);
			const sp<IVar> expr = parse_expr(data, ast->fst_child->next_sibling);
			watchdog_type(data->variables.at(varname)->get_type(), expr->get_type(), ast);
			sp<IVar> val;
			if(ast->token==PLUSASS)
				val = *data->variables.at(varname) + *expr;
			else if(ast->token==MINUSASS)
				val = *data->variables.at(varname) - *expr;
			else if(ast->token==MULTASS)
				val = *data->variables.at(varname) * *expr;
			else if(ast->token==DIVASS)
				val = *data->variables.at(varname) / *expr;
			
			data->variables.at(varname) = cast_type(data->variables.at(varname)->get_type(), val);
			break;
		} case FUNC: {
			runfunc(data, *ast->strvalue, ast);
			break;
		} case RETURN:
			return parse_expr(data, ast->fst_child);
			break;
		default:
			throw_exception("unrecognized token!", ast->nline);
	}
	if(recur)
		return run(data, ast->next_sibling, true);
	return NULL;
}


sp<IVar> runfunc(parser_data_t *data, string funcname, ast *ast) {
	vector<sp<IVar>> params{};
	if(ast->fst_child!=NULL)
		parse_params(data, &params, ast->fst_child);

	if(data->stdfuncs.find(funcname) != data->stdfuncs.end())
		return data->stdfuncs[funcname](params);

	if(data->usrfuncs.find(funcname) != data->usrfuncs.end()) {

		// A FAIRE MAINTENANT : LA PORTÉE DES VARIABLES
		// SUR LE COUP JE ME SUIS DIT QUE JE METTRAIS EN PARAM DE RUN ET DES PARSE_*** LA THASH DES VARS
		// SAUF QU'IL FAUT PAS OUBLIER LE CONTEXTE PRINCIPAL
		// + EST-CE QU'ON PEUT IMBRIQUER LES DÉCLARATIONS DE FONCTIONS ?
		//			-> SI OUI FAUT TROUVER UN MOYEN DE METTRE EN PLACE ÇA
		// Idée, je peux mettre en place une structure de cette sorte (un peu cheloue avec pas forcément un pointeur 
		// vers le fils mais plutôt un pointeur vers le père)

		return run(data, data->usrfuncs[funcname]->next_sibling, true);
	}

	throw_exception("function not found...", ast->nline);
}


bool castable(int type1, int type2) {
	return (type1!=STRING && type2!=STRING) || type1==type2;
}


sp<IVar> cast_type(int type, sp<IVar> value) {
	if(!castable(type, value->get_type()))
		throw_exception("conversion from number to string!", 0);
	switch(type) {
		case BOOL:
			return make_shared<Var<bool>>(*value);
		case CHAR:
			return make_shared<Var<char>>(*value);
		case INT8:
			return make_shared<Var<int8_t>>(*value);
		case UINT8:
			return make_shared<Var<uint8_t>>(*value);
		case INT32:
			return make_shared<Var<int32_t>>(*value);
		case UINT32:
			return make_shared<Var<uint32_t>>(*value);
		case DOUBLE:
			return make_shared<Var<double>>(*value);
		case STRING:
			return make_shared<Var<string>>(*value);
	}
	return NULL;
}


void watchdog_type(int typedst, int typesrc, ast *op) {
	const int nl = op->nline;
	if(typesrc==STRING && op->token!=PLUS && op->token!=PLUSASS)
		throw_exception("operation undefined for string objects.", nl);
	if((typedst==STRING && typesrc!=STRING) || (typedst!=STRING && typesrc==STRING))
		throw_exception("cannont convert STRING to a canonical type!", nl);
}
