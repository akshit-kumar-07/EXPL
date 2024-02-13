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

    #include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
    #include "symboltable.h"
	#include "ast.c"
    #include "symboltable.c"
    #include "initialize.c"
    #include "typecheck.h"
    #include "typecheck.c"
    #include "codegen.c"

	int yylex(void);
    extern FILE *yyin;
    extern int lineno;
    FILE *fp;
    FILE *intermediate;
    void print(int);
    struct Paramstruct *argList1, *argList2;
    int declCount = 0, defCount = 0; // Definition and Declaration count of functions
    int testing = 0; // can use to test ASTree

#line 94 "parser.tab.c"

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
  YYSYMBOL_START = 3,                      /* START  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_READ = 5,                       /* READ  */
  YYSYMBOL_WRITE = 6,                      /* WRITE  */
  YYSYMBOL_PLUS = 7,                       /* PLUS  */
  YYSYMBOL_MINUS = 8,                      /* MINUS  */
  YYSYMBOL_MUL = 9,                        /* MUL  */
  YYSYMBOL_DIV = 10,                       /* DIV  */
  YYSYMBOL_MOD = 11,                       /* MOD  */
  YYSYMBOL_ASSGN = 12,                     /* ASSGN  */
  YYSYMBOL_NUM = 13,                       /* NUM  */
  YYSYMBOL_ID = 14,                        /* ID  */
  YYSYMBOL_IF = 15,                        /* IF  */
  YYSYMBOL_THEN = 16,                      /* THEN  */
  YYSYMBOL_ELSE = 17,                      /* ELSE  */
  YYSYMBOL_ENDIF = 18,                     /* ENDIF  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_DO = 20,                        /* DO  */
  YYSYMBOL_ENDWHILE = 21,                  /* ENDWHILE  */
  YYSYMBOL_EQ = 22,                        /* EQ  */
  YYSYMBOL_NEQ = 23,                       /* NEQ  */
  YYSYMBOL_LE = 24,                        /* LE  */
  YYSYMBOL_GE = 25,                        /* GE  */
  YYSYMBOL_LT = 26,                        /* LT  */
  YYSYMBOL_GT = 27,                        /* GT  */
  YYSYMBOL_AND = 28,                       /* AND  */
  YYSYMBOL_OR = 29,                        /* OR  */
  YYSYMBOL_BREAK = 30,                     /* BREAK  */
  YYSYMBOL_CONT = 31,                      /* CONT  */
  YYSYMBOL_DECL = 32,                      /* DECL  */
  YYSYMBOL_ENDDECL = 33,                   /* ENDDECL  */
  YYSYMBOL_INT = 34,                       /* INT  */
  YYSYMBOL_STR = 35,                       /* STR  */
  YYSYMBOL_STRVAL = 36,                    /* STRVAL  */
  YYSYMBOL_MAIN = 37,                      /* MAIN  */
  YYSYMBOL_RETURN = 38,                    /* RETURN  */
  YYSYMBOL_39_ = 39,                       /* ';'  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '('  */
  YYSYMBOL_42_ = 42,                       /* ')'  */
  YYSYMBOL_43_ = 43,                       /* '['  */
  YYSYMBOL_44_ = 44,                       /* ']'  */
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_YYACCEPT = 47,                  /* $accept  */
  YYSYMBOL_program = 48,                   /* program  */
  YYSYMBOL_GDeclBlock = 49,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 50,                 /* GDeclList  */
  YYSYMBOL_GDecl = 51,                     /* GDecl  */
  YYSYMBOL_Type = 52,                      /* Type  */
  YYSYMBOL_FType = 53,                     /* FType  */
  YYSYMBOL_GIdList = 54,                   /* GIdList  */
  YYSYMBOL_GId = 55,                       /* GId  */
  YYSYMBOL_FDefBlock = 56,                 /* FDefBlock  */
  YYSYMBOL_FDef = 57,                      /* FDef  */
  YYSYMBOL_ParamList = 58,                 /* ParamList  */
  YYSYMBOL_Param = 59,                     /* Param  */
  YYSYMBOL_MainBlock = 60,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 61,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 62,                  /* LDecList  */
  YYSYMBOL_LDecl = 63,                     /* LDecl  */
  YYSYMBOL_IdList = 64,                    /* IdList  */
  YYSYMBOL_Body = 65,                      /* Body  */
  YYSYMBOL_RetStmt = 66,                   /* RetStmt  */
  YYSYMBOL_Slist = 67,                     /* Slist  */
  YYSYMBOL_Stmt = 68,                      /* Stmt  */
  YYSYMBOL_IfStmt = 69,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 70,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 71,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 72,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 73,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 74,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 75,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 76,                  /* ExprList  */
  YYSYMBOL_expr = 77,                      /* expr  */
  YYSYMBOL_func = 78,                      /* func  */
  YYSYMBOL_id = 79                         /* id  */
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
#define YYFINAL  12
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   331

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  175

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      41,    42,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    39,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    43,     2,    44,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,    46,     2,     2,     2,     2,
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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    50,    50,    51,    52,    55,    56,    59,    60,    63,
      66,    67,    70,    71,    74,    75,    78,    86,    91,   103,
     104,   107,   185,   186,   187,   190,   197,   236,   237,   238,
     241,   242,   245,   248,   249,   255,   256,   259,   269,   270,
     273,   274,   275,   276,   277,   278,   279,   280,   283,   287,
     293,   298,   301,   304,   307,   310,   316,   320,   321,   324,
     328,   332,   336,   340,   344,   348,   352,   356,   360,   364,
     368,   372,   376,   377,   378,   382,   383,   384,   387,   394,
     398,   402,   406
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
  "\"end of file\"", "error", "\"invalid token\"", "START", "END", "READ",
  "WRITE", "PLUS", "MINUS", "MUL", "DIV", "MOD", "ASSGN", "NUM", "ID",
  "IF", "THEN", "ELSE", "ENDIF", "WHILE", "DO", "ENDWHILE", "EQ", "NEQ",
  "LE", "GE", "LT", "GT", "AND", "OR", "BREAK", "CONT", "DECL", "ENDDECL",
  "INT", "STR", "STRVAL", "MAIN", "RETURN", "';'", "','", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "$accept", "program", "GDeclBlock",
  "GDeclList", "GDecl", "Type", "FType", "GIdList", "GId", "FDefBlock",
  "FDef", "ParamList", "Param", "MainBlock", "LDeclBlock", "LDecList",
  "LDecl", "IdList", "Body", "RetStmt", "Slist", "Stmt", "IfStmt",
  "WhileStmt", "BrkStmt", "ContStmt", "InputStmt", "OutputStmt", "AsgStmt",
  "ExprList", "expr", "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-86)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,    96,   -86,   -86,    79,    -9,   -15,   -86,   -86,   122,
     -86,    70,   -86,    -7,    -9,   -86,   -86,    51,   -86,   -86,
     -24,    15,   -86,    52,   -86,   -86,    55,    -2,    85,   -86,
      70,    -2,    58,   -86,   -86,    90,   152,   -86,    63,   -86,
     178,    82,   -86,    -2,   -86,   -86,    76,   150,   119,   -86,
      82,   -86,   123,   182,   -86,    75,    92,   119,   -86,    22,
     -86,   -86,   128,   131,   156,   145,   159,   127,   183,   157,
     154,    75,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     185,   221,   -86,   190,   -86,   123,   223,   157,   157,   160,
     157,   157,   -86,   -86,   225,   -86,   -86,   157,   180,   -86,
     -86,   -86,   241,   -86,   -86,   157,   -86,   199,   208,   210,
      49,   181,   271,   209,    41,   211,   117,   125,   -86,   153,
     157,   157,   157,   157,   157,   157,   157,   157,   157,   157,
     157,   157,   157,   -86,   -86,   203,   218,   219,   157,   -86,
     -86,   -86,   -86,   251,   248,   -86,     0,     0,    59,    59,
      59,   302,   302,   294,   294,   294,   294,   271,   271,   -86,
     -86,   -86,   271,   258,   258,   229,   235,   258,   230,   237,
     256,   -86,   -86,   244,   -86
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    10,    11,     0,     0,     0,     4,     6,     0,
       8,     0,     1,     0,     0,    20,     3,     0,     5,     7,
      17,     0,    15,     0,    19,     2,     0,    24,     0,     9,
       0,    24,     0,    12,    13,     0,     0,    23,     0,    14,
       0,    29,    25,     0,    16,    18,     0,     0,     0,    22,
      29,    28,     0,     0,    31,     0,     0,     0,    34,     0,
      27,    30,     0,     0,    79,     0,     0,     0,     0,     0,
       0,     0,    39,    43,    44,    45,    46,    40,    41,    42,
       0,     0,    26,     0,    32,     0,     0,     0,    58,     0,
       0,     0,    51,    52,     0,    73,    75,     0,     0,    77,
      76,    36,     0,    38,    47,     0,    21,    33,    79,     0,
       0,     0,    57,    73,     0,    76,     0,     0,    74,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    37,    35,     0,     0,     0,     0,    78,
      80,    82,    81,     0,     0,    72,    59,    60,    61,    62,
      63,    69,    68,    66,    67,    64,    65,    70,    71,    55,
      53,    54,    56,     0,     0,     0,     0,     0,     0,     0,
       0,    49,    50,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -86,   -86,   -86,   -86,   275,    13,   -32,   -86,   255,   -86,
     276,   260,   249,     9,   257,   -86,   253,   242,   269,   243,
     -81,   -70,   -86,   -86,   -86,   -86,   -86,   -86,   -86,   -86,
     -85,   -47,   -55
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     4,     5,     9,    10,    11,    35,    21,    22,    14,
      15,    36,    37,     7,    48,    53,    54,    59,    56,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,   111,
      98,    99,   100
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      81,   103,   110,   112,   114,   116,   117,    23,    80,   122,
     123,   124,   119,     6,    16,    52,    81,    27,    13,    28,
     135,    52,    17,    25,    80,     2,     3,    13,   131,   132,
      17,   109,    33,    34,   115,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   120,   121,
     122,   123,   124,   162,    29,    30,   120,   121,   122,   123,
     124,    84,    85,   125,   126,   127,   128,   129,   130,   131,
     132,   125,   126,   127,   128,   129,   130,   131,   132,    12,
      62,    63,   165,   166,    20,   141,   170,   131,   132,    64,
      65,   137,    26,    31,    66,   103,   103,    32,    38,     1,
     103,     2,     3,    41,    42,    67,    68,    45,    81,    81,
      81,    81,    81,    69,    47,    81,    80,    80,    80,    80,
      80,    50,    55,    80,   120,   121,   122,   123,   124,     8,
       2,     3,   120,   121,   122,   123,   124,    58,    82,   125,
     126,   127,   128,   129,   130,   131,   132,   125,   126,   127,
     128,   129,   130,   131,   132,    18,     2,     3,   101,   143,
     120,   121,   122,   123,   124,    94,    92,   144,    94,    86,
      95,    64,    87,   113,    64,   125,   126,   127,   128,   129,
     130,   131,   132,    51,    33,    34,    90,   120,   121,   122,
     123,   124,    43,    96,    44,   145,    96,    88,    97,    89,
      91,    97,   125,   126,   127,   128,   129,   130,   131,   132,
     120,   121,   122,   123,   124,    60,    33,    34,    43,   133,
      46,   138,    93,   139,   104,   125,   126,   127,   128,   129,
     130,   131,   132,   105,    62,    63,   106,   108,   118,    85,
      62,    63,   159,    64,    65,   134,   167,   168,    66,    64,
      65,    89,   136,   140,    66,   142,   169,   160,   161,    67,
      68,    62,    63,    62,    63,    67,    68,   163,   164,   171,
      64,    65,    64,    65,   173,    66,   172,    66,   120,   121,
     122,   123,   124,   174,    19,    39,    67,    68,    67,    68,
      24,    40,    49,   125,   126,   127,   128,   129,   130,   131,
     132,   120,   121,   122,   123,   124,    61,    57,     0,   120,
     121,   122,   123,   124,   102,     0,   125,   126,    -1,    -1,
      -1,    -1,   131,   132,   125,   126,    83,   107,     0,     0,
     131,   132
};

static const yytype_int16 yycheck[] =
{
      55,    71,    87,    88,    89,    90,    91,    14,    55,     9,
      10,    11,    97,     0,     5,    47,    71,    41,     5,    43,
     105,    53,    37,    14,    71,    34,    35,    14,    28,    29,
      37,    86,    34,    35,    89,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,     7,     8,
       9,    10,    11,   138,    39,    40,     7,     8,     9,    10,
      11,    39,    40,    22,    23,    24,    25,    26,    27,    28,
      29,    22,    23,    24,    25,    26,    27,    28,    29,     0,
       5,     6,   163,   164,    14,    44,   167,    28,    29,    14,
      15,    42,    41,    41,    19,   165,   166,    42,    13,    32,
     170,    34,    35,    45,    14,    30,    31,    44,   163,   164,
     165,   166,   167,    38,    32,   170,   163,   164,   165,   166,
     167,    45,     3,   170,     7,     8,     9,    10,    11,    33,
      34,    35,     7,     8,     9,    10,    11,    14,    46,    22,
      23,    24,    25,    26,    27,    28,    29,    22,    23,    24,
      25,    26,    27,    28,    29,    33,    34,    35,     4,    42,
       7,     8,     9,    10,    11,     8,    39,    42,     8,    41,
      13,    14,    41,    13,    14,    22,    23,    24,    25,    26,
      27,    28,    29,    33,    34,    35,    41,     7,     8,     9,
      10,    11,    40,    36,    42,    42,    36,    41,    41,    43,
      41,    41,    22,    23,    24,    25,    26,    27,    28,    29,
       7,     8,     9,    10,    11,    33,    34,    35,    40,    39,
      42,    40,    39,    42,    39,    22,    23,    24,    25,    26,
      27,    28,    29,    12,     5,     6,    46,    14,    13,    40,
       5,     6,    39,    14,    15,     4,    17,    18,    19,    14,
      15,    43,    42,    44,    19,    44,    21,    39,    39,    30,
      31,     5,     6,     5,     6,    30,    31,    16,    20,    39,
      14,    15,    14,    15,    18,    19,    39,    19,     7,     8,
       9,    10,    11,    39,     9,    30,    30,    31,    30,    31,
      14,    31,    43,    22,    23,    24,    25,    26,    27,    28,
      29,     7,     8,     9,    10,    11,    53,    50,    -1,     7,
       8,     9,    10,    11,    71,    -1,    22,    23,    24,    25,
      26,    27,    28,    29,    22,    23,    57,    85,    -1,    -1,
      28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    34,    35,    48,    49,    52,    60,    33,    50,
      51,    52,     0,    52,    56,    57,    60,    37,    33,    51,
      14,    54,    55,    14,    57,    60,    41,    41,    43,    39,
      40,    41,    42,    34,    35,    53,    58,    59,    13,    55,
      58,    45,    14,    40,    42,    44,    42,    32,    61,    59,
      45,    33,    53,    62,    63,     3,    65,    61,    14,    64,
      33,    63,     5,     6,    14,    15,    19,    30,    31,    38,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      78,    79,    46,    65,    39,    40,    41,    41,    41,    43,
      41,    41,    39,    39,     8,    13,    36,    41,    77,    78,
      79,     4,    66,    68,    39,    12,    46,    64,    14,    79,
      77,    76,    77,    13,    77,    79,    77,    77,    13,    77,
       7,     8,     9,    10,    11,    22,    23,    24,    25,    26,
      27,    28,    29,    39,     4,    77,    42,    42,    40,    42,
      44,    44,    44,    42,    42,    42,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    39,
      39,    39,    77,    16,    20,    67,    67,    17,    18,    21,
      67,    39,    39,    18,    39
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    48,    48,    49,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    56,
      56,    57,    58,    58,    58,    59,    60,    61,    61,    61,
      62,    62,    63,    64,    64,    65,    65,    66,    67,    67,
      68,    68,    68,    68,    68,    68,    68,    68,    69,    69,
      70,    71,    72,    73,    74,    75,    76,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    77,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    79,    79
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     2,     1,     3,     2,     2,     1,     3,
       1,     1,     1,     1,     3,     1,     4,     1,     4,     2,
       1,     9,     3,     1,     0,     2,     8,     3,     2,     0,
       2,     1,     3,     3,     1,     4,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,    10,     8,
       8,     2,     2,     5,     5,     4,     3,     1,     0,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     1,     2,     1,     1,     1,     4,     1,
       4,     4,     4
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
  case 2: /* program: GDeclBlock FDefBlock MainBlock  */
#line 50 "parser.y"
                                         {fclose(intermediate);}
#line 1306 "parser.tab.c"
    break;

  case 3: /* program: GDeclBlock MainBlock  */
#line 51 "parser.y"
                               {fclose(intermediate);}
#line 1312 "parser.tab.c"
    break;

  case 4: /* program: MainBlock  */
#line 52 "parser.y"
                    {fclose(intermediate);}
#line 1318 "parser.tab.c"
    break;

  case 5: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 55 "parser.y"
                                    {initialize();}
#line 1324 "parser.tab.c"
    break;

  case 6: /* GDeclBlock: DECL ENDDECL  */
#line 56 "parser.y"
                           {initialize();}
#line 1330 "parser.tab.c"
    break;

  case 10: /* Type: INT  */
#line 66 "parser.y"
           { declarationType = TYPE_INT;}
#line 1336 "parser.tab.c"
    break;

  case 11: /* Type: STR  */
#line 67 "parser.y"
           { declarationType = TYPE_STR;}
#line 1342 "parser.tab.c"
    break;

  case 12: /* FType: INT  */
#line 70 "parser.y"
            { FDeclarationType = TYPE_INT;}
#line 1348 "parser.tab.c"
    break;

  case 13: /* FType: STR  */
#line 71 "parser.y"
            { FDeclarationType = TYPE_STR;}
#line 1354 "parser.tab.c"
    break;

  case 16: /* GId: ID '(' ParamList ')'  */
#line 79 "parser.y"
    {
        declCount++; //keeps track of the number of functions declared
        checkAvailability((yyvsp[-3].nptr)->name,1); //check if the name is valid in the global scope
        GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
        Phead = NULL;
        Ptail = NULL;
    }
#line 1366 "parser.tab.c"
    break;

  case 17: /* GId: ID  */
#line 87 "parser.y"
    {
        checkAvailability((yyvsp[0].nptr)->name,1); //check availability in glbl scope
        GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
    }
#line 1375 "parser.tab.c"
    break;

  case 18: /* GId: ID '[' NUM ']'  */
#line 92 "parser.y"
    {
        checkAvailability((yyvsp[-3].nptr)->name, 1);
        if((yyvsp[-1].nptr)->value.intval < 1)
        {
            yyerror("Invalid array size\n", NULL);
            exit(1);
        }
        GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
    }
#line 1389 "parser.tab.c"
    break;

  case 21: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 108 "parser.y"
     {
        defCount++; //count the number of functions defined
        Gtemp = GLookup((yyvsp[-7].nptr)->name);

        //Check if function is declared

        if(Gtemp == NULL)
        {
            yyerror("Function %s is not declared\n", (yyvsp[-7].nptr)->name);
            exit(1);
        }

        //type check the function

        if(Gtemp->type != declarationType)
        {
            yyerror("%s : Function type does not match declaration", (yyvsp[-7].nptr)->name);
            exit(1);
        }

        //Check for parameters and arguments
        argList1 = Phead; //arguments
        argList2 = Gtemp->paramlist; //formal parameters

        //check for type compatibility
        while(argList1 != NULL && argList2 != NULL)
        {
            if(argList1->type != argList2->type)
            {
                yyerror("%s : Conflict in argument type for the function", (yyvsp[-7].nptr)->name);
                exit(1);
            }


            if(strcmp(argList1->name,argList2->name)!=0)
            {
                yyerror("%s : Conflict in argument names\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            argList1 = argList1->next;
            argList2 = argList2->next;
       }
        if((argList1 != NULL ) || (argList2 != NULL))
        {
            yyerror("%s : Insufficient arguments ", (yyvsp[-7].nptr)->name);
            exit(1);
        }

        if(testing)
        {
            printLSymbolTable();
        }

        else
        {
            fprintf(intermediate, "F%d:\n",Gtemp->flabel);
            fprintf(intermediate, "PUSH BP\n");
            fprintf(intermediate, "MOV BP,SP\n");

            Ltemp = Lhead;
            while(Ltemp != NULL)
            {
                if(Ltemp->binding > 0)
                    fprintf(intermediate,"PUSH R0\n");
                Ltemp = Ltemp->next;
            }
            codegen((yyvsp[-1].nptr));
        }

        Phead = NULL;
        Ptail = NULL;
        Lhead = NULL;
        Ltail = NULL;
     }
#line 1469 "parser.tab.c"
    break;

  case 25: /* Param: FType ID  */
#line 191 "parser.y"
      {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            PInstall((yyvsp[0].nptr)->name, FDeclarationType);
      }
#line 1478 "parser.tab.c"
    break;

  case 26: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 198 "parser.y"
          {
            if(defCount != declCount)
            {
                yyerror("all declared functions must be defined\n");
                exit(1);
            }

            if(declarationType != TYPE_INT)
            {
                yyerror("Main should return a type int value\n");
                exit(1);
            }

            if(testing)
            {
                printGSymbolTable();
                printLSymbolTable();
            }
            else
            {
                fprintf(intermediate, "MAIN:\n");
                fprintf(intermediate, "PUSH BP\n");
                fprintf(intermediate, "MOV BP,SP\n");

                Ltemp = Lhead;
                while(Ltemp != NULL)
                {
                    fprintf(intermediate,"PUSH R0\n");
                    Ltemp = Ltemp->next;
                }

                codegen((yyvsp[-1].nptr));
            }

            Lhead = NULL;
            Ltail = NULL;
          }
#line 1520 "parser.tab.c"
    break;

  case 27: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 236 "parser.y"
                                    {InstallParamsInLocal();}
#line 1526 "parser.tab.c"
    break;

  case 28: /* LDeclBlock: DECL ENDDECL  */
#line 237 "parser.y"
                                    {InstallParamsInLocal();}
#line 1532 "parser.tab.c"
    break;

  case 29: /* LDeclBlock: %empty  */
#line 238 "parser.y"
                                    {InstallParamsInLocal();}
#line 1538 "parser.tab.c"
    break;

  case 34: /* IdList: ID  */
#line 249 "parser.y"
                {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    LInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1547 "parser.tab.c"
    break;

  case 35: /* Body: START Slist RetStmt END  */
#line 255 "parser.y"
                                {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1553 "parser.tab.c"
    break;

  case 36: /* Body: START RetStmt END  */
#line 256 "parser.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1559 "parser.tab.c"
    break;

  case 37: /* RetStmt: RETURN expr ';'  */
#line 259 "parser.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1572 "parser.tab.c"
    break;

  case 38: /* Slist: Slist Stmt  */
#line 269 "parser.y"
                        {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1578 "parser.tab.c"
    break;

  case 39: /* Slist: Stmt  */
#line 270 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1584 "parser.tab.c"
    break;

  case 40: /* Stmt: InputStmt  */
#line 273 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1590 "parser.tab.c"
    break;

  case 41: /* Stmt: OutputStmt  */
#line 274 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1596 "parser.tab.c"
    break;

  case 42: /* Stmt: AsgStmt  */
#line 275 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1602 "parser.tab.c"
    break;

  case 43: /* Stmt: IfStmt  */
#line 276 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1608 "parser.tab.c"
    break;

  case 44: /* Stmt: WhileStmt  */
#line 277 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1614 "parser.tab.c"
    break;

  case 45: /* Stmt: BrkStmt  */
#line 278 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1620 "parser.tab.c"
    break;

  case 46: /* Stmt: ContStmt  */
#line 279 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1626 "parser.tab.c"
    break;

  case 47: /* Stmt: func ';'  */
#line 280 "parser.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1632 "parser.tab.c"
    break;

  case 48: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 283 "parser.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TYPE_BOOL, 'e');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 1641 "parser.tab.c"
    break;

  case 49: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 287 "parser.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'i');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1650 "parser.tab.c"
    break;

  case 50: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 293 "parser.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TYPE_BOOL, 'w');
                                                                (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1659 "parser.tab.c"
    break;

  case 51: /* BrkStmt: BREAK ';'  */
#line 298 "parser.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1665 "parser.tab.c"
    break;

  case 52: /* ContStmt: CONT ';'  */
#line 301 "parser.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1671 "parser.tab.c"
    break;

  case 53: /* InputStmt: READ '(' id ')' ';'  */
#line 304 "parser.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1677 "parser.tab.c"
    break;

  case 54: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 307 "parser.y"
                                    {(yyval.nptr) = TreeCreate(TYPE_VOID, NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 1683 "parser.tab.c"
    break;

  case 55: /* AsgStmt: id ASSGN expr ';'  */
#line 310 "parser.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TYPE_VOID, NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 1692 "parser.tab.c"
    break;

  case 56: /* ExprList: ExprList ',' expr  */
#line 316 "parser.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 1701 "parser.tab.c"
    break;

  case 57: /* ExprList: expr  */
#line 320 "parser.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1707 "parser.tab.c"
    break;

  case 58: /* ExprList: %empty  */
#line 321 "parser.y"
                            {(yyval.nptr) = NULL;}
#line 1713 "parser.tab.c"
    break;

  case 59: /* expr: expr PLUS expr  */
#line 324 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1722 "parser.tab.c"
    break;

  case 60: /* expr: expr MINUS expr  */
#line 328 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1731 "parser.tab.c"
    break;

  case 61: /* expr: expr MUL expr  */
#line 332 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1740 "parser.tab.c"
    break;

  case 62: /* expr: expr DIV expr  */
#line 336 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1749 "parser.tab.c"
    break;

  case 63: /* expr: expr MOD expr  */
#line 340 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TYPE_INT, NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1758 "parser.tab.c"
    break;

  case 64: /* expr: expr LT expr  */
#line 344 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1767 "parser.tab.c"
    break;

  case 65: /* expr: expr GT expr  */
#line 348 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1776 "parser.tab.c"
    break;

  case 66: /* expr: expr LE expr  */
#line 352 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1785 "parser.tab.c"
    break;

  case 67: /* expr: expr GE expr  */
#line 356 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1794 "parser.tab.c"
    break;

  case 68: /* expr: expr NEQ expr  */
#line 360 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1803 "parser.tab.c"
    break;

  case 69: /* expr: expr EQ expr  */
#line 364 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);					}
#line 1811 "parser.tab.c"
    break;

  case 70: /* expr: expr AND expr  */
#line 368 "parser.y"
                         {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_AND, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);					}
#line 1819 "parser.tab.c"
    break;

  case 71: /* expr: expr OR expr  */
#line 372 "parser.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'l');
                            (yyval.nptr) = TreeCreate(TYPE_BOOL, NODE_OR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1828 "parser.tab.c"
    break;

  case 72: /* expr: '(' expr ')'  */
#line 376 "parser.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1834 "parser.tab.c"
    break;

  case 73: /* expr: NUM  */
#line 377 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1840 "parser.tab.c"
    break;

  case 74: /* expr: MINUS NUM  */
#line 378 "parser.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 1849 "parser.tab.c"
    break;

  case 75: /* expr: STRVAL  */
#line 382 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1855 "parser.tab.c"
    break;

  case 76: /* expr: id  */
#line 383 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1861 "parser.tab.c"
    break;

  case 77: /* expr: func  */
#line 384 "parser.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1867 "parser.tab.c"
    break;

  case 78: /* func: ID '(' ExprList ')'  */
#line 387 "parser.y"
                            {
                                assignType((yyvsp[-3].nptr), 1);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                (yyval.nptr) = (yyvsp[-3].nptr);
                            }
#line 1878 "parser.tab.c"
    break;

  case 79: /* id: ID  */
#line 394 "parser.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 1887 "parser.tab.c"
    break;

  case 80: /* id: ID '[' NUM ']'  */
#line 398 "parser.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 1896 "parser.tab.c"
    break;

  case 81: /* id: ID '[' id ']'  */
#line 402 "parser.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 1905 "parser.tab.c"
    break;

  case 82: /* id: ID '[' expr ']'  */
#line 407 "parser.y"
    {
        if((yyvsp[-1].nptr)->type!=TYPE_INT)
        {
        	fprintf(stderr,"Expected an arithmetic expression in the index for array %s\n",(yyvsp[-3].nptr)->name);
        	exit(1);
        }
        assignType((yyvsp[-3].nptr), 2);
        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
       }
#line 1919 "parser.tab.c"
    break;


#line 1923 "parser.tab.c"

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

#line 418 "parser.y"


yyerror(char const *s, char const *var) {
    printf("\033[0;31mERR:%d\033[0m : ", lineno);
    printf(s, var);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        yyerror("Please provide an input filename\n", NULL);
        exit(1);
    } else {
        fp = fopen(argv[1], "r");
        if (!fp) {
            yyerror("Invalid input file specified\n", NULL);
            exit(1);
        } else {
            yyin = fp;
        }
    }
    yyparse();
    return 0;
}
