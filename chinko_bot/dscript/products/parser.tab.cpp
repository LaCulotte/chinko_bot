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
  YYSYMBOL_TRUE = 7,                       /* TRUE  */
  YYSYMBOL_FALSE = 8,                      /* FALSE  */
  YYSYMBOL_IDENT = 9,                      /* IDENT  */
  YYSYMBOL_COMMA = 10,                     /* COMMA  */
  YYSYMBOL_LOR = 11,                       /* LOR  */
  YYSYMBOL_LAND = 12,                      /* LAND  */
  YYSYMBOL_BOR = 13,                       /* BOR  */
  YYSYMBOL_BXOR = 14,                      /* BXOR  */
  YYSYMBOL_BAND = 15,                      /* BAND  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_NEQ = 17,                       /* NEQ  */
  YYSYMBOL_GT = 18,                        /* GT  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_GTEQ = 20,                      /* GTEQ  */
  YYSYMBOL_LTEQ = 21,                      /* LTEQ  */
  YYSYMBOL_LSHIFT = 22,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 23,                    /* RSHIFT  */
  YYSYMBOL_PLUS = 24,                      /* PLUS  */
  YYSYMBOL_MINUS = 25,                     /* MINUS  */
  YYSYMBOL_MULT = 26,                      /* MULT  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_MOD = 28,                       /* MOD  */
  YYSYMBOL_POW = 29,                       /* POW  */
  YYSYMBOL_LNOT = 30,                      /* LNOT  */
  YYSYMBOL_GLOBAL = 31,                    /* GLOBAL  */
  YYSYMBOL_RETURN = 32,                    /* RETURN  */
  YYSYMBOL_UNARY_MINUS = 33,               /* UNARY_MINUS  */
  YYSYMBOL_LPAREN = 34,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 35,                    /* RPAREN  */
  YYSYMBOL_LET = 36,                       /* LET  */
  YYSYMBOL_FUNC = 37,                      /* FUNC  */
  YYSYMBOL_INIT_ARGS = 38,                 /* INIT_ARGS  */
  YYSYMBOL_INIT_VAR = 39,                  /* INIT_VAR  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_ELSE = 41,                      /* ELSE  */
  YYSYMBOL_LBRACK = 42,                    /* LBRACK  */
  YYSYMBOL_RBRACK = 43,                    /* RBRACK  */
  YYSYMBOL_PTV = 44,                       /* PTV  */
  YYSYMBOL_ASSIGN = 45,                    /* ASSIGN  */
  YYSYMBOL_WHILE = 46,                     /* WHILE  */
  YYSYMBOL_FOR = 47,                       /* FOR  */
  YYSYMBOL_TO = 48,                        /* TO  */
  YYSYMBOL_IFELSE = 49,                    /* IFELSE  */
  YYSYMBOL_CREATEVAR = 50,                 /* CREATEVAR  */
  YYSYMBOL_CREATEASSIGN = 51,              /* CREATEASSIGN  */
  YYSYMBOL_TYPE = 52,                      /* TYPE  */
  YYSYMBOL_PLUSASS = 53,                   /* PLUSASS  */
  YYSYMBOL_MINUSASS = 54,                  /* MINUSASS  */
  YYSYMBOL_MULTASS = 55,                   /* MULTASS  */
  YYSYMBOL_DIVASS = 56,                    /* DIVASS  */
  YYSYMBOL_YYACCEPT = 57,                  /* $accept  */
  YYSYMBOL_Program = 58,                   /* Program  */
  YYSYMBOL_Functions = 59,                 /* Functions  */
  YYSYMBOL_Args = 60,                      /* Args  */
  YYSYMBOL_ArgsRec = 61,                   /* ArgsRec  */
  YYSYMBOL_Sequence = 62,                  /* Sequence  */
  YYSYMBOL_Instruction = 63,               /* Instruction  */
  YYSYMBOL_Assignment = 64,                /* Assignment  */
  YYSYMBOL_Expression = 65,                /* Expression  */
  YYSYMBOL_Ops = 66,                       /* Ops  */
  YYSYMBOL_Paren = 67,                     /* Paren  */
  YYSYMBOL_Nat = 68,                       /* Nat  */
  YYSYMBOL_Real = 69,                      /* Real  */
  YYSYMBOL_Char = 70,                      /* Char  */
  YYSYMBOL_Bool = 71,                      /* Bool  */
  YYSYMBOL_Str = 72,                       /* Str  */
  YYSYMBOL_Var = 73,                       /* Var  */
  YYSYMBOL_ExtendedVar = 74                /* ExtendedVar  */
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
#define YYFINAL  39
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   537

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  57
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  143

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   311


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
      55,    56
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    76,    76,    78,    79,    81,    82,    84,    85,    87,
      88,    89,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   106,   107,   108,   109,
     110,   112,   112,   112,   112,   112,   112,   112,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147
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
  "CHARACT", "STR", "TRUE", "FALSE", "IDENT", "COMMA", "LOR", "LAND",
  "BOR", "BXOR", "BAND", "EQ", "NEQ", "GT", "LT", "GTEQ", "LTEQ", "LSHIFT",
  "RSHIFT", "PLUS", "MINUS", "MULT", "DIV", "MOD", "POW", "LNOT", "GLOBAL",
  "RETURN", "UNARY_MINUS", "LPAREN", "RPAREN", "LET", "FUNC", "INIT_ARGS",
  "INIT_VAR", "IF", "ELSE", "LBRACK", "RBRACK", "PTV", "ASSIGN", "WHILE",
  "FOR", "TO", "IFELSE", "CREATEVAR", "CREATEASSIGN", "TYPE", "PLUSASS",
  "MINUSASS", "MULTASS", "DIVASS", "$accept", "Program", "Functions",
  "Args", "ArgsRec", "Sequence", "Instruction", "Assignment", "Expression",
  "Ops", "Paren", "Nat", "Real", "Char", "Bool", "Str", "Var",
  "ExtendedVar", YY_NULLPTR
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
     305,   306,   307,   308,   309,   310,   311
};
#endif

#define YYPACT_NINF (-78)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      55,   -29,    26,   294,   294,   294,    26,     7,   -28,   -78,
      55,   -35,   -78,     5,   279,   -78,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,     6,   294,   294,   294,   252,   -78,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,     2,   175,    -7,   -78,
      30,   -78,   -78,   294,   294,   294,   294,   294,    -1,   319,
     286,    70,   397,   345,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   294,   294,   294,   294,   294,   294,
     294,   294,   294,   294,   -78,    55,     4,    55,   -78,   294,
      12,   397,   397,   397,   397,   397,   -78,     3,   -78,   371,
     -78,   416,   434,   451,   467,   482,   496,   508,   508,   115,
     115,   115,   115,   184,   184,    70,    70,    27,    27,    27,
      27,     9,    23,    19,   214,    58,   -78,   -78,    31,    55,
     -78,   -78,    55,   -78,    36,    66,    42,    35,    37,    41,
      58,   -78,    55,   -78,   -78,   -78,    55,    66,    47,    48,
     -78,   -78,   -78
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      11,    70,     0,     0,     0,     0,     0,     0,     2,     3,
      10,     0,    71,     0,     0,    70,    72,    64,    65,    66,
      69,    67,    68,    70,     0,     0,     0,     0,    37,    38,
      31,    32,    33,    34,    35,    36,     0,     0,     0,     1,
       0,     9,    22,     0,     0,     0,     0,     0,     0,     0,
       0,    60,    59,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    25,    11,    13,    11,    19,     0,
       0,    26,    27,    28,    29,    30,    24,     0,    62,     0,
      63,    58,    52,    51,    55,    54,    53,    39,    40,    41,
      42,    43,    44,    56,    57,    45,    46,    47,    48,    49,
      50,     0,     0,     0,     0,     6,    23,    61,    12,    11,
      17,    18,    11,    21,     0,     8,     0,     0,     0,     0,
       0,     5,    11,    16,    15,    20,    11,     8,     0,     0,
       7,    14,     4
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -78,   -78,   -78,   -78,   -52,    -9,   -33,    86,   104,   -78,
     -78,   -78,   -78,   -78,   -78,   -78,   -77,     0
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     7,     8,   124,   131,     9,    10,    11,    27,    28,
      29,    30,    31,    32,    33,    34,    12,    35
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      13,    41,    16,    76,    78,    14,    13,    39,    40,    42,
      13,     1,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,     1,     2,     3,    15,    13,    13,   125,    80,
      50,    79,     4,    86,    75,   112,   115,   116,     5,     6,
      43,     1,   118,   137,     2,     3,    73,     2,    44,    45,
      46,    47,   121,     4,     1,   119,   111,    15,   113,     5,
       6,   129,   126,     2,     3,    13,   130,    13,   134,   120,
     135,   123,     4,   136,   132,   140,     2,     3,     5,     6,
     141,   142,    38,   133,     0,     4,    70,    71,    72,    73,
       0,     5,     6,     0,     0,     0,     0,     0,    36,    37,
     127,     0,    13,   128,    13,     0,     0,     0,    49,    13,
       0,     0,    13,   138,     0,     0,    13,   139,    51,    52,
      53,     0,    13,     0,     0,     0,    13,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,    81,    82,    83,
      84,    85,     0,     0,    89,     0,     0,     0,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,   104,   105,   106,   107,   108,   109,   110,     0,     0,
       0,     0,     0,   114,     1,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     2,     3,    68,    69,
      70,    71,    72,    73,     0,     4,     0,    77,     0,     0,
       0,     5,     6,     1,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,     0,     2,     3,     0,     0,     0,
       0,     0,     0,     0,     4,     0,   122,     0,     0,     0,
       5,     6,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    17,    18,    19,    20,    21,    22,    23,    17,
      18,    19,    20,    21,    22,    23,    74,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,     0,     0,    25,
       2,    24,     0,    26,    48,     0,    25,     2,     0,    24,
      26,    88,     0,     0,    25,     2,     0,     0,    26,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,     0,
       0,     0,     0,     0,    87,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,     0,     0,     0,     0,     0,
      90,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,     0,     0,     0,     0,     0,   117,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73
};

static const yytype_int16 yycheck[] =
{
       0,    10,     2,    36,    37,    34,     6,     0,    36,    44,
      10,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     9,    31,    32,     9,    36,    37,   115,     9,
      34,    48,    40,    44,    42,    41,    34,    44,    46,    47,
      45,     9,    43,   130,    31,    32,    29,    31,    53,    54,
      55,    56,    43,    40,     9,    42,    75,     9,    77,    46,
      47,    35,    41,    31,    32,    75,    10,    77,    43,   112,
      43,   114,    40,    42,    42,   137,    31,    32,    46,    47,
      43,    43,     6,   126,    -1,    40,    26,    27,    28,    29,
      -1,    46,    47,    -1,    -1,    -1,    -1,    -1,     4,     5,
     119,    -1,   112,   122,   114,    -1,    -1,    -1,    14,   119,
      -1,    -1,   122,   132,    -1,    -1,   126,   136,    24,    25,
      26,    -1,   132,    -1,    -1,    -1,   136,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    -1,    50,    -1,    -1,    -1,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    79,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    31,    32,    24,    25,
      26,    27,    28,    29,    -1,    40,    -1,    42,    -1,    -1,
      -1,    46,    47,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    -1,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    -1,    -1,    -1,
      46,    47,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     3,     4,     5,     6,     7,     8,     9,     3,
       4,     5,     6,     7,     8,     9,    44,     3,     4,     5,
       6,     7,     8,     9,    25,    -1,    -1,    -1,    -1,    30,
      31,    25,    -1,    34,    35,    -1,    30,    31,    -1,    25,
      34,    35,    -1,    -1,    30,    31,    -1,    -1,    34,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,    35,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      35,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,    35,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    31,    32,    40,    46,    47,    58,    59,    62,
      63,    64,    73,    74,    34,     9,    74,     3,     4,     5,
       6,     7,     8,     9,    25,    30,    34,    65,    66,    67,
      68,    69,    70,    71,    72,    74,    65,    65,    64,     0,
      36,    62,    44,    45,    53,    54,    55,    56,    35,    65,
      34,    65,    65,    65,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    44,    42,    63,    42,    63,    48,
       9,    65,    65,    65,    65,    65,    44,    35,    35,    65,
      35,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    62,    41,    62,    65,    34,    44,    35,    43,    42,
      63,    43,    42,    63,    60,    73,    41,    62,    62,    35,
      10,    61,    42,    63,    43,    43,    42,    73,    62,    62,
      61,    43,    43
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    57,    58,    59,    59,    60,    60,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    63,    63,    63,
      63,    63,    63,    63,    63,    63,    64,    64,    64,    64,
      64,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    66,    66,    66,    66,    66,    66,    66,
      66,    66,    66,    67,    68,    69,    70,    71,    71,    72,
      73,    74,    74
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     9,     2,     0,     3,     0,     2,
       1,     0,     5,     3,     9,     7,     7,     5,     5,     3,
       7,     5,     2,     5,     4,     3,     3,     3,     3,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     4,     3,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     2
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
#line 76 "chinko_bot/dscript/parser.y"
                                                                                        { execute(data, (yyvsp[0].instr)); }
#line 1312 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 3: /* Functions: Sequence  */
#line 78 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1318 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 4: /* Functions: Functions LET IDENT LPAREN Args RPAREN LBRACK Sequence RBRACK  */
#line 79 "chinko_bot/dscript/parser.y"
                                                                                              { declarefunc(data, (yyvsp[-6].strval), (yyvsp[-4].instr), (yyvsp[-1].instr)); (yyval.instr) = (yyvsp[-8].instr); }
#line 1324 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 5: /* Args: Var ArgsRec  */
#line 81 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = seq(unary_operator(data, (yyvsp[-1].instr), INIT_VAR), (yyvsp[0].instr)); }
#line 1330 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 6: /* Args: %empty  */
#line 82 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1336 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 7: /* ArgsRec: COMMA Var ArgsRec  */
#line 84 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = seq(unary_operator(data, (yyvsp[-1].instr), INIT_VAR), (yyvsp[0].instr)); }
#line 1342 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 8: /* ArgsRec: %empty  */
#line 85 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1348 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 9: /* Sequence: Instruction Sequence  */
#line 87 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = seq((yyvsp[-1].instr), (yyvsp[0].instr)); }
#line 1354 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 10: /* Sequence: Instruction  */
#line 88 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = (yyvsp[0].instr); }
#line 1360 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 11: /* Sequence: %empty  */
#line 89 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = NULL; }
#line 1366 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 12: /* Instruction: IF Expression LBRACK Sequence RBRACK  */
#line 91 "chinko_bot/dscript/parser.y"
                                                                                                                { (yyval.instr) = ifinst(data, (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1372 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 13: /* Instruction: IF Expression Instruction  */
#line 92 "chinko_bot/dscript/parser.y"
                                                                                                                                                { (yyval.instr) = ifinst(data, (yyvsp[-1].instr), (yyvsp[0].instr)); }
#line 1378 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 14: /* Instruction: IF Expression LBRACK Sequence RBRACK ELSE LBRACK Sequence RBRACK  */
#line 93 "chinko_bot/dscript/parser.y"
                                                                                                        { (yyval.instr) = ifelseinst(data, (yyvsp[-7].instr), (yyvsp[-5].instr), (yyvsp[-1].instr)); }
#line 1384 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 15: /* Instruction: IF Expression Instruction ELSE LBRACK Sequence RBRACK  */
#line 94 "chinko_bot/dscript/parser.y"
                                                                                                                { (yyval.instr) = ifelseinst(data, (yyvsp[-5].instr), (yyvsp[-4].instr), (yyvsp[-1].instr)); }
#line 1390 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 16: /* Instruction: IF Expression LBRACK Sequence RBRACK ELSE Instruction  */
#line 95 "chinko_bot/dscript/parser.y"
                                                                                                                { (yyval.instr) = ifelseinst(data, (yyvsp[-5].instr), (yyvsp[-3].instr), (yyvsp[0].instr)); }
#line 1396 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 17: /* Instruction: IF Expression Instruction ELSE Instruction  */
#line 96 "chinko_bot/dscript/parser.y"
                                                                                                                                { (yyval.instr) = ifelseinst(data, (yyvsp[-3].instr), (yyvsp[-2].instr), (yyvsp[0].instr)); }
#line 1402 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 18: /* Instruction: WHILE Expression LBRACK Sequence RBRACK  */
#line 97 "chinko_bot/dscript/parser.y"
                                                                                                                                { (yyval.instr) = whileinst(data, (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1408 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 19: /* Instruction: WHILE Expression Instruction  */
#line 98 "chinko_bot/dscript/parser.y"
                                                                                                                                        { (yyval.instr) = whileinst(data, (yyvsp[-1].instr), (yyvsp[0].instr)); }
#line 1414 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 20: /* Instruction: FOR Assignment TO Expression LBRACK Sequence RBRACK  */
#line 99 "chinko_bot/dscript/parser.y"
                                                                                                                        { (yyval.instr) = forinst(data, (yyvsp[-5].instr), (yyvsp[-3].instr), (yyvsp[-1].instr)); }
#line 1420 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 21: /* Instruction: FOR Assignment TO Expression Instruction  */
#line 100 "chinko_bot/dscript/parser.y"
                                                                                                                                { (yyval.instr) = forinst(data, (yyvsp[-3].instr), (yyvsp[-1].instr), (yyvsp[0].instr)); }
#line 1426 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 22: /* Instruction: Assignment PTV  */
#line 101 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[-1].instr); }
#line 1432 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 23: /* Instruction: IDENT LPAREN Expression RPAREN PTV  */
#line 102 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-4].strval), (yyvsp[-2].instr)); }
#line 1438 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 24: /* Instruction: IDENT LPAREN RPAREN PTV  */
#line 103 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = loadfunction(data, (yyvsp[-3].strval), NULL); }
#line 1444 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 25: /* Instruction: RETURN Expression PTV  */
#line 104 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = unary_operator(data, (yyvsp[-1].instr), RETURN); }
#line 1450 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 26: /* Assignment: ExtendedVar ASSIGN Expression  */
#line 106 "chinko_bot/dscript/parser.y"
                                                                { (yyval.instr) = assignment(data, (yyvsp[-2].instr), (yyvsp[0].instr)); }
#line 1456 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 27: /* Assignment: ExtendedVar PLUSASS Expression  */
#line 107 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), PLUSASS); }
#line 1462 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 28: /* Assignment: ExtendedVar MINUSASS Expression  */
#line 108 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MINUSASS); }
#line 1468 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 29: /* Assignment: ExtendedVar MULTASS Expression  */
#line 109 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MULTASS); }
#line 1474 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 30: /* Assignment: ExtendedVar DIVASS Expression  */
#line 110 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), DIVASS); }
#line 1480 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 38: /* Expression: Paren  */
#line 112 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1486 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 39: /* Ops: Expression EQ Expression  */
#line 113 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), EQ); }
#line 1492 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 40: /* Ops: Expression NEQ Expression  */
#line 114 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), NEQ); }
#line 1498 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 41: /* Ops: Expression GT Expression  */
#line 115 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), GT); }
#line 1504 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 42: /* Ops: Expression LT Expression  */
#line 116 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LT); }
#line 1510 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 43: /* Ops: Expression GTEQ Expression  */
#line 117 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), GTEQ); }
#line 1516 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 44: /* Ops: Expression LTEQ Expression  */
#line 118 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LTEQ); }
#line 1522 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 45: /* Ops: Expression PLUS Expression  */
#line 119 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), PLUS); }
#line 1528 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 46: /* Ops: Expression MINUS Expression  */
#line 120 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MINUS); }
#line 1534 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 47: /* Ops: Expression MULT Expression  */
#line 121 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MULT); }
#line 1540 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 48: /* Ops: Expression DIV Expression  */
#line 122 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), DIV); }
#line 1546 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 49: /* Ops: Expression MOD Expression  */
#line 123 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), MOD); }
#line 1552 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 50: /* Ops: Expression POW Expression  */
#line 124 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), POW); }
#line 1558 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 51: /* Ops: Expression LAND Expression  */
#line 125 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LAND); }
#line 1564 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 52: /* Ops: Expression LOR Expression  */
#line 126 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LOR); }
#line 1570 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 53: /* Ops: Expression BAND Expression  */
#line 127 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BAND); }
#line 1576 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 54: /* Ops: Expression BXOR Expression  */
#line 128 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BXOR); }
#line 1582 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 55: /* Ops: Expression BOR Expression  */
#line 129 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), BOR); }
#line 1588 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 56: /* Ops: Expression LSHIFT Expression  */
#line 130 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), LSHIFT); }
#line 1594 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 57: /* Ops: Expression RSHIFT Expression  */
#line 131 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), RSHIFT); }
#line 1600 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 58: /* Ops: Expression COMMA Expression  */
#line 132 "chinko_bot/dscript/parser.y"
                                                                                { (yyval.instr) = binary_operator(data, (yyvsp[-2].instr), (yyvsp[0].instr), COMMA); }
#line 1606 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 59: /* Ops: LNOT Expression  */
#line 133 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), LNOT); }
#line 1612 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 60: /* Ops: MINUS Expression  */
#line 134 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), UNARY_MINUS); }
#line 1618 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 61: /* Ops: IDENT LPAREN Expression RPAREN  */
#line 135 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-3].strval), (yyvsp[-1].instr)); }
#line 1624 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 62: /* Ops: IDENT LPAREN RPAREN  */
#line 136 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadfunction(data, (yyvsp[-2].strval), NULL); }
#line 1630 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 63: /* Paren: LPAREN Expression RPAREN  */
#line 138 "chinko_bot/dscript/parser.y"
                                                                        { (yyval.instr) = (yyvsp[-1].instr); }
#line 1636 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 64: /* Nat: NATURAL  */
#line 139 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadnatural(data, (yyvsp[0].intval)); }
#line 1642 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 65: /* Real: REAL  */
#line 140 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadreal(data, (yyvsp[0].doubleval)); }
#line 1648 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 66: /* Char: CHARACT  */
#line 141 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadchar(data, (yyvsp[0].charval)); }
#line 1654 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 67: /* Bool: TRUE  */
#line 142 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadnatural(data, 1); }
#line 1660 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 68: /* Bool: FALSE  */
#line 143 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = loadnatural(data, 0); }
#line 1666 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 69: /* Str: STR  */
#line 144 "chinko_bot/dscript/parser.y"
                                                                                                { (yyval.instr) = loadstr(data, (yyvsp[0].strval)); }
#line 1672 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 70: /* Var: IDENT  */
#line 145 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = loadvar(data, (yyvsp[0].strval)); }
#line 1678 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 71: /* ExtendedVar: Var  */
#line 146 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = (yyvsp[0].instr); }
#line 1684 "chinko_bot/dscript/products/parser.tab.cpp"
    break;

  case 72: /* ExtendedVar: GLOBAL ExtendedVar  */
#line 147 "chinko_bot/dscript/parser.y"
                                                                                        { (yyval.instr) = unary_operator(data, (yyvsp[0].instr), GLOBAL); }
#line 1690 "chinko_bot/dscript/products/parser.tab.cpp"
    break;


#line 1694 "chinko_bot/dscript/products/parser.tab.cpp"

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

#line 149 "chinko_bot/dscript/parser.y"


#include "products/parser.tab.h"
#include "products/lexer.h"


void throw_exception(const string err, int nl) {
	// SI TU VEUX CHANGER LA MANIÈRE DONT SONT GÉRÉES LES EXCEPTIONS C'EST ICI...
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

void fatal_error(const char* msg, yyscan_t yyscanner) {
	throw_exception(string(msg), 0);
}


void dscript_cmd(string code, bool *stop) {
	ctx_vars_t glob_ctx = {};
	glob_ctx.variables = {};

	parser_data_t data = {};
	data.nline = 1;
	data.fst_el = NULL;
	data.ctx = &glob_ctx;
	data.stop = stop;
	initstd(&data);

	yyscan_t scanner;
	if(yylex_init(&scanner))
		throw_exception("unable to initialize the parser.", 0);
	yylex_init_extra(&data, &scanner);
	YY_BUFFER_STATE buf = yy_scan_string(code.c_str(), scanner);
	try {
		yyparse(scanner, &data);
	} catch(const exception& e) {
		yy_delete_buffer(buf, scanner);
		yylex_destroy(scanner);
		free_list(data.fst_el);
		throw runtime_error(e.what());
	}
	yy_delete_buffer(buf, scanner);
	yylex_destroy(scanner);
	free_list(data.fst_el);
}

void dscript(string file, bool *stop) {
	FILE *fp = fopen(file.c_str(), "r");
	if(fp==NULL)
		throw_exception(file+" not found!", 0);
	fseek(fp, 0L, SEEK_END);
	size_t size = ftell(fp);
	rewind(fp);
	char code[size+1];
	
	fread(code, 1, size, fp);
	code[size] = 0x0;
	try {
		dscript_cmd(code, stop);
	} catch(const exception& e) {
		fclose(fp);
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
	if(ast->fst_child != NULL && ast->token != FUNC && ast->token != LAND && ast->token != LOR && ast->token != GLOBAL) {
		expr1 = parse_expr(data, ast->fst_child);
		if(ast->token != COMMA && ast->fst_child->next_sibling != NULL) {
			expr2 = parse_expr(data, ast->fst_child->next_sibling);
			watchdog_type(expr1->get_type(), expr2->get_type(), ast->token, ast->nline);
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
			return stdpow(data, args, ast->nline);
		} case UNARY_MINUS: {
			const sp<IVar> ZERO = make_shared<Var<int>>(0);
			return *ZERO - *parse_expr(data, ast->fst_child);
		} case EQ:
			return make_shared<Var<bool>>(*expr1==(*expr2));
		case NEQ:
			return make_shared<Var<bool>>(!(*expr1==(*expr2)));
		case LT:
			return make_shared<Var<bool>>(*expr1<(*expr2));
		case GT:
			return make_shared<Var<bool>>(*expr1>(*expr2));
		case LTEQ:
			return make_shared<Var<bool>>(*expr1<=(*expr2));
		case GTEQ:
			return make_shared<Var<bool>>(*expr1>=(*expr2));
		case LAND:
			if(*(bool*)parse_expr(data, ast->fst_child)->value)
				return parse_expr(data, ast->fst_child->next_sibling);
			return make_shared<Var<bool>>(false);
		case LOR:
			if(*(bool*)parse_expr(data, ast->fst_child)->value)
				return make_shared<Var<bool>>(true);
			return parse_expr(data, ast->fst_child->next_sibling);
		case LNOT: {
			const sp<IVar> ZERO = make_shared<Var<int>>(0);
			if(*ZERO==*expr1)
				return make_shared<Var<bool>>(true);
			else
				return make_shared<Var<bool>>(false);
		} case BAND:
			return *expr1 & (*expr2);
		case BXOR:
			return *expr1 ^ (*expr2);
		case BOR:
			return *expr1 | (*expr2);
		case NATURAL:
			return make_shared<Var<int32_t>>(ast->intvalue);
		case CHARACT:
			return make_shared<Var<char>>(ast->charvalue);
		case REAL:
			return make_shared<Var<double>>(ast->doublevalue);
		case STR:
			return make_shared<Var<string>>(*ast->strvalue);
		case GLOBAL: {
			ctx_vars_t *old_ctx = data->ctx;
			if(data->ctx->parent==NULL)
				throw_exception("cannot access to the upper context (@)", ast->nline);
			data->ctx = data->ctx->parent;
			sp<IVar> retval = parse_expr(data, ast->fst_child);
			data->ctx = old_ctx;
			return retval;
		} case IDENT:
			string varname = *ast->strvalue;
			ctx_vars_t *ctx = find_ctx(data->ctx, varname, ast->nline);
			return ctx->variables.at(varname);
	}
	return 0;
}

ctx_vars_t *find_ctx(ctx_vars_t *ctx, string varname, int nline) {
	/**
	 * @returns the context structure from which varname belongs
	 * @throws an error if this context does not exist
	 */
	ctx_vars_t *cur_ctx = ctx;
	while(cur_ctx != NULL) {
		if(cur_ctx->variables.find(varname) != cur_ctx->variables.end())
			return cur_ctx;
		cur_ctx = cur_ctx->parent;
	}
	throw_exception("unknown variable!", nline);
}


void assign_var(ctx_vars_t *ctx, sp<IVar> expr, ast *node, int op) {
	if(node->token==GLOBAL) {
		if(ctx->parent==NULL)
			throw_exception("cannot access to the upper context (@)", node->nline);
		assign_var(ctx->parent, expr, node->fst_child, op);
		return;
	}

	string varname = *node->strvalue;
	if(op==ASSIGN) {
		if(ctx->variables.find(varname) != ctx->variables.end())
			ctx->variables.at(varname) = expr;
		else
			ctx->variables.insert({varname, expr});
	} else {
		ctx_vars_t *var_ctx = find_ctx(ctx, varname, node->nline);
		watchdog_type(var_ctx->variables.at(varname)->get_type(), expr->get_type(), op, node->nline);

		if(op==PLUSASS)
			var_ctx->variables.at(varname) = *var_ctx->variables.at(varname) + *expr;
		else if(op==MINUSASS)
			var_ctx->variables.at(varname) = *var_ctx->variables.at(varname) - *expr;
		else if(op==MULTASS)
			var_ctx->variables.at(varname) = *var_ctx->variables.at(varname) * *expr;
		else if(op==DIVASS)
			var_ctx->variables.at(varname) = *var_ctx->variables.at(varname) / *expr;
	}
}


sp<IVar> run(parser_data_t *data, ast *ast, bool recur) {
	if(data->stop != NULL)
		while(*data->stop) {}
	if(ast==NULL)
		return NULL;
	switch(ast->token) {
		case IF:
			if(*(bool*)parse_expr(data, ast->fst_child)->value)
				run(data, ast->fst_child->next_sibling, true);
			break;
		case IFELSE:
			if(*(bool*)parse_expr(data, ast->fst_child)->value)
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
				data->ctx->variables.at(varname) = cast_type(data->ctx->variables.at(varname)->get_type(), *data->ctx->variables.at(varname)+ONE, ast->nline);
			}
			break;
		} case ASSIGN: {
			// Par défaut, si on assigne une variable qui a le nom d'une variable globale (ie. de contexte supérieur), on en crée une nouvelle
			// Pour assigner une valeur à une variable globale, ou plus généralement pour l'accéder, on utilise l'opérateur @
			sp<IVar> expr = parse_expr(data, ast->fst_child->next_sibling);
			assign_var(data->ctx, expr, ast->fst_child, ASSIGN);
			break;
		}
		case PLUSASS:
		case MINUSASS:
		case MULTASS:
		case DIVASS: {
			const sp<IVar> expr = parse_expr(data, ast->fst_child->next_sibling);
			assign_var(data->ctx, expr, ast->fst_child, ast->token);
			break;
		} case FUNC: {
			runfunc(data, *ast->strvalue, ast);
			break;
		} case RETURN:
			return parse_expr(data, ast->fst_child);
			break;
		case IDENT: {
			string varname = *ast->strvalue;
			if(data->ctx->variables.find(varname) != data->ctx->variables.end())
				return data->ctx->variables.at(varname);
			else
				return NULL; 
		} default:
			throw_exception("unrecognized token!", ast->nline);
	}
	if(recur)
		return run(data, ast->next_sibling, true);
	return NULL;
}


sp<IVar> runfunc(parser_data_t *data, string funcname, ast *node) {
	vector<sp<IVar>> params{};
	if(node->fst_child!=NULL)
		parse_params(data, &params, node->fst_child);

	if(data->stdfuncs.find(funcname) != data->stdfuncs.end())
		return data->stdfuncs[funcname](data, params, node->nline);

	if(data->usrfuncs.find(funcname) != data->usrfuncs.end()) {
		ctx_vars_t child_ctx = {};
		child_ctx.variables = {};
		// Adding argument variables
		ast *curvar;
		curvar = data->usrfuncs[funcname]->fst_child;
		int i=0;
		while(curvar != NULL) {
			string varname = *curvar->fst_child->strvalue;
			if(child_ctx.variables.find(varname) != data->ctx->variables.end())
				throw_exception("name used for two different arguments", data->usrfuncs[funcname]->nline);
			child_ctx.variables.insert({varname, params[i]});
			curvar = curvar->next_sibling;
			i++;
		}

		// switching context
		ctx_vars_t *old_ctx = data->ctx;
		if(old_ctx->parent==NULL) // il n'existe que 2 niveaux de contextes : le global et le local (comme les fonctions ne peuvent pas être imbriquées)
			child_ctx.parent = old_ctx;
		else
			child_ctx.parent = old_ctx->parent;
		data->ctx = &child_ctx;


		sp<IVar> retval = run(data, data->usrfuncs[funcname]->next_sibling, true);
		
		data->ctx = old_ctx;
		return retval;
	}

	throw_exception("function not found...", node->nline);
}


bool castable(int type1, int type2) {
	return (type1!=STRING && type2!=STRING) || type1==type2;
}


sp<IVar> cast_type(int type, sp<IVar> value, int nline) {
	if(!castable(type, value->get_type()))
		throw_exception("invalid types!", nline);
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


void watchdog_type(int typedst, int typesrc, int token, int nl) {
	if(typesrc==STRING && token!=PLUS && token!=PLUSASS && token!=EQ && token!=NEQ)
		throw_exception("operation undefined for string objects.", nl);
	if((typedst==STRING && typesrc!=STRING) || (typedst!=STRING && typesrc==STRING))
		throw_exception("cannot convert STRING to a canonical type!", nl);
}
