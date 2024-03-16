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
#line 1 "exprtree.y"

		#include <stdlib.h>
		#include <stdio.h> 
        #include "exprtree.h"
        #include "typetable.h"
        #include "symboltable.h"
        #include "classtable.h"
        #include "typetable.c"
        #include "symboltable.c"
        #include "classtable.c"
        #include "typecheck.h"
        #include "typecheck.c"
		#include "ast.c"
        #include "codegen.c"
        #include "initialize.c"

		int yylex(void);
        extern FILE *yyin;
        extern int lineno;
        FILE *fp;
        FILE *intermediate;
        void print(int);
        struct Paramstruct *argList1, *argList2;
        int declCount = 0, defCount = 0; // Definition and Declaration count of functions
		struct ASTNode *tempASTNode;
        // For testing
        int testing = 0; // can use to test ASTree

#line 100 "exprtree.tab.c"

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

#include "exprtree.tab.h"
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
  YYSYMBOL_TYPE = 39,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 40,                   /* ENDTYPE  */
  YYSYMBOL_NILL = 41,                      /* NILL  */
  YYSYMBOL_DEQNILL = 42,                   /* DEQNILL  */
  YYSYMBOL_NEQNILL = 43,                   /* NEQNILL  */
  YYSYMBOL_FREE = 44,                      /* FREE  */
  YYSYMBOL_ALLOC = 45,                     /* ALLOC  */
  YYSYMBOL_INIT = 46,                      /* INIT  */
  YYSYMBOL_CLASS = 47,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 48,                  /* ENDCLASS  */
  YYSYMBOL_SELF = 49,                      /* SELF  */
  YYSYMBOL_NEW = 50,                       /* NEW  */
  YYSYMBOL_DELETE = 51,                    /* DELETE  */
  YYSYMBOL_BREAKPOINT = 52,                /* BREAKPOINT  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* ';'  */
  YYSYMBOL_56_ = 56,                       /* '('  */
  YYSYMBOL_57_ = 57,                       /* ')'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '['  */
  YYSYMBOL_60_ = 60,                       /* ']'  */
  YYSYMBOL_61_ = 61,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 62,                  /* $accept  */
  YYSYMBOL_program = 63,                   /* program  */
  YYSYMBOL_TypeDefBlock = 64,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 65,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 66,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 67,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 68,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 69,                 /* FieldDecl  */
  YYSYMBOL_ClassDefBlock = 70,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 71,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 72,                  /* ClassDef  */
  YYSYMBOL_Cname = 73,                     /* Cname  */
  YYSYMBOL_ClassFieldDeclList = 74,        /* ClassFieldDeclList  */
  YYSYMBOL_ClassFieldDecl = 75,            /* ClassFieldDecl  */
  YYSYMBOL_ClassMethodDefns = 76,          /* ClassMethodDefns  */
  YYSYMBOL_GDeclBlock = 77,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 78,                 /* GDeclList  */
  YYSYMBOL_GDecl = 79,                     /* GDecl  */
  YYSYMBOL_FieldType = 80,                 /* FieldType  */
  YYSYMBOL_Type = 81,                      /* Type  */
  YYSYMBOL_FType = 82,                     /* FType  */
  YYSYMBOL_LType = 83,                     /* LType  */
  YYSYMBOL_GIdList = 84,                   /* GIdList  */
  YYSYMBOL_GId = 85,                       /* GId  */
  YYSYMBOL_FDefBlock = 86,                 /* FDefBlock  */
  YYSYMBOL_FDef = 87,                      /* FDef  */
  YYSYMBOL_ParamList = 88,                 /* ParamList  */
  YYSYMBOL_Param = 89,                     /* Param  */
  YYSYMBOL_MainBlock = 90,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 91,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 92,                  /* LDecList  */
  YYSYMBOL_LDecl = 93,                     /* LDecl  */
  YYSYMBOL_IdList = 94,                    /* IdList  */
  YYSYMBOL_LId = 95,                       /* LId  */
  YYSYMBOL_Body = 96,                      /* Body  */
  YYSYMBOL_RetStmt = 97,                   /* RetStmt  */
  YYSYMBOL_Field = 98,                     /* Field  */
  YYSYMBOL_FieldFunction = 99,             /* FieldFunction  */
  YYSYMBOL_Slist = 100,                    /* Slist  */
  YYSYMBOL_Stmt = 101,                     /* Stmt  */
  YYSYMBOL_IfStmt = 102,                   /* IfStmt  */
  YYSYMBOL_WhileStmt = 103,                /* WhileStmt  */
  YYSYMBOL_BrkStmt = 104,                  /* BrkStmt  */
  YYSYMBOL_ContStmt = 105,                 /* ContStmt  */
  YYSYMBOL_InputStmt = 106,                /* InputStmt  */
  YYSYMBOL_OutputStmt = 107,               /* OutputStmt  */
  YYSYMBOL_AsgStmt = 108,                  /* AsgStmt  */
  YYSYMBOL_ExprList = 109,                 /* ExprList  */
  YYSYMBOL_expr = 110,                     /* expr  */
  YYSYMBOL_func = 111,                     /* func  */
  YYSYMBOL_id = 112                        /* id  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   521

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  137
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  304

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
      56,    57,     2,     2,    58,     2,    61,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    55,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    59,     2,    60,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    63,    63,    66,    67,    68,    71,    72,    75,    78,
      84,    85,    88,    97,    98,   101,   102,   105,   116,   119,
     120,   123,   127,   136,   137,   140,   146,   152,   160,   161,
     164,   167,   168,   169,   182,   183,   184,   194,   195,   196,
     205,   206,   207,   217,   218,   221,   228,   232,   242,   243,
     246,   328,   329,   330,   333,   339,   373,   374,   375,   378,
     379,   382,   385,   386,   389,   395,   396,   399,   409,   413,
     416,   427,   439,   450,   462,   463,   466,   467,   468,   469,
     470,   471,   472,   473,   474,   475,   476,   484,   491,   492,
     500,   509,   513,   519,   524,   527,   530,   537,   546,   549,
     553,   558,   565,   573,   581,   588,   593,   601,   610,   614,
     615,   618,   622,   626,   630,   634,   638,   642,   646,   650,
     654,   658,   662,   666,   670,   674,   678,   679,   683,   688,
     692,   693,   694,   695,   698,   705,   709,   714
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
  "INT", "STR", "STRVAL", "MAIN", "RETURN", "TYPE", "ENDTYPE", "NILL",
  "DEQNILL", "NEQNILL", "FREE", "ALLOC", "INIT", "CLASS", "ENDCLASS",
  "SELF", "NEW", "DELETE", "BREAKPOINT", "'{'", "'}'", "';'", "'('", "')'",
  "','", "'['", "']'", "'.'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "UserDefinedType", "FieldDeclList",
  "FieldDecl", "ClassDefBlock", "ClassDefList", "ClassDef", "Cname",
  "ClassFieldDeclList", "ClassFieldDecl", "ClassMethodDefns", "GDeclBlock",
  "GDeclList", "GDecl", "FieldType", "Type", "FType", "LType", "GIdList",
  "GId", "FDefBlock", "FDef", "ParamList", "Param", "MainBlock",
  "LDeclBlock", "LDecList", "LDecl", "IdList", "LId", "Body", "RetStmt",
  "Field", "FieldFunction", "Slist", "Stmt", "IfStmt", "WhileStmt",
  "BrkStmt", "ContStmt", "InputStmt", "OutputStmt", "AsgStmt", "ExprList",
  "expr", "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-261)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -18,   -11,     4,    32,  -261,  -261,     6,  -261,    57,  -261,
    -261,   118,  -261,  -261,   194,     0,    73,  -261,  -261,  -261,
    -261,   108,  -261,   109,  -261,  -261,  -261,   107,  -261,  -261,
    -261,  -261,   135,  -261,   149,   228,  -261,  -261,   112,   142,
    -261,  -261,    21,    23,  -261,   165,   169,   184,   168,   200,
    -261,  -261,  -261,  -261,   230,   205,  -261,   149,   171,   187,
     151,  -261,  -261,  -261,   231,    27,  -261,   206,  -261,   197,
     230,  -261,  -261,   264,  -261,  -261,   230,  -261,   234,    78,
     110,    91,  -261,   257,   239,  -261,  -261,  -261,  -261,  -261,
    -261,   230,   178,   298,   257,   101,  -261,   288,   182,  -261,
     349,   255,   298,   256,  -261,    28,  -261,  -261,  -261,   254,
     258,    -1,   259,   261,   268,   269,    26,   281,   282,   251,
     283,   287,   342,    -2,   294,   349,  -261,  -261,  -261,  -261,
    -261,  -261,  -261,  -261,   295,   335,  -261,   304,  -261,  -261,
     288,   -13,    26,   277,    26,   189,   338,    26,    26,  -261,
    -261,   346,  -261,   292,  -261,    26,   225,  -261,   214,  -261,
    -261,    -7,   303,   347,    -5,  -261,  -261,   280,   348,  -261,
     361,  -261,  -261,    26,  -261,  -261,    12,   305,   -44,   310,
      43,   314,   315,   317,   224,   152,   473,   316,   322,   323,
     318,    94,   104,  -261,  -261,  -261,   130,  -261,  -261,    26,
      26,    26,    26,    26,    26,    26,    26,    26,    26,    26,
    -261,   -38,   -35,   327,   328,   -33,    15,   330,   332,   333,
     248,   334,  -261,   273,   372,   377,   337,   380,   344,   352,
    -261,   345,   389,  -261,  -261,    26,  -261,  -261,    26,   388,
     393,  -261,   123,   123,  -261,  -261,  -261,   297,   297,   494,
     494,   494,   494,   353,   354,  -261,    26,   356,   359,  -261,
     358,   402,  -261,    26,  -261,  -261,  -261,  -261,  -261,  -261,
    -261,   362,   366,   473,   195,   442,   442,  -261,  -261,   203,
    -261,  -261,   363,   367,   219,  -261,   370,  -261,   326,   391,
    -261,  -261,   371,  -261,  -261,   442,   375,   376,  -261,   414,
    -261,  -261,   379,  -261
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    14,     9,     4,     0,     7,     0,     1,
      16,    27,     3,     6,     0,     0,     0,    49,    33,    31,
      32,     0,    11,     0,    18,    13,    15,     0,    36,    26,
      34,    35,     0,    29,     0,     0,     8,    10,     0,     0,
      25,    28,    46,     0,    44,    36,    34,    35,     0,     0,
      48,     2,    12,    20,    53,     0,    30,     0,     0,     0,
       0,    42,    40,    41,     0,     0,    52,     0,    43,     0,
      53,    24,    19,     0,    54,    45,     0,    47,     0,     0,
       0,     0,    51,    58,     0,    39,    37,    38,    17,    23,
      21,    53,     0,     0,    58,     0,    57,     0,     0,    60,
       0,     0,     0,     0,    64,     0,    63,    56,    59,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    75,    79,    80,    81,
      82,    76,    77,    78,     0,     0,    55,     0,    22,    61,
       0,     0,     0,     0,   110,     0,     0,     0,     0,    94,
      95,     0,   127,   135,   129,     0,   132,   133,     0,   131,
     130,     0,     0,     0,     0,    85,    66,     0,     0,    84,
       0,    74,    83,     0,    50,    62,   135,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   109,     0,   135,     0,
      68,     0,     0,   128,   124,   125,     0,   122,   123,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      67,     0,     0,     0,    70,     0,     0,     0,     0,     0,
       0,    69,    65,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,   100,   134,     0,   136,   137,   110,     0,
       0,   126,   111,   112,   113,   114,   115,   121,   120,   118,
     119,   116,   117,     0,     0,    88,   110,     0,     0,   107,
       0,     0,   105,   110,    99,    68,    70,    97,    69,    96,
      98,     0,     0,   108,     0,     0,     0,    86,    87,     0,
      89,    90,     0,     0,     0,   102,     0,    72,     0,     0,
      71,   101,     0,    73,   103,     0,     0,     0,   104,     0,
      92,    93,     0,    91
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -261,  -261,  -261,  -261,   421,  -261,  -261,   415,  -261,  -261,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,   406,  -261,    14,
    -261,   -80,  -261,   382,  -261,   369,    18,   365,  -261,   357,
    -261,   355,  -261,   306,   350,   325,  -100,   -95,  -260,  -117,
    -261,  -261,  -261,  -261,  -261,  -261,  -261,   -90,  -110,   -69,
     -98
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     7,     8,    21,    22,    11,    15,
      26,    27,    60,    72,    80,    17,    32,    33,    23,    34,
      49,    64,    43,    44,    35,    50,    65,    66,    51,    93,
      98,    99,   105,   106,   101,   122,   156,   157,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   185,   186,   159,
     160
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     123,   176,   135,     4,     9,   124,   158,   211,   171,   215,
     167,   143,    97,   226,    24,   288,   289,   227,    97,   253,
       4,     1,   254,   224,   257,   123,   227,   135,   224,     5,
     124,   134,   180,   184,   151,   299,   177,   191,   192,   152,
     153,   178,   177,   179,   177,   196,    12,   189,    25,    48,
     199,   200,   201,   202,   203,   144,   134,   220,   145,   168,
     146,   212,   154,   223,   216,   204,   205,   206,   207,   208,
     209,   145,   258,   224,    73,   119,   227,    54,    56,    10,
      55,    57,   155,   139,    75,    76,   140,    28,    79,   242,
     243,   244,   245,   246,   247,   248,   249,   250,   251,   252,
     229,   199,   200,   201,   202,   203,    29,    30,    31,    95,
      14,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    18,    38,    85,   273,   204,   205,   206,   207,
     208,   209,   201,   202,   203,    84,    76,   199,   200,   201,
     202,   203,    19,    20,    86,    87,    90,    91,   274,    28,
      16,   239,   204,   205,   206,   207,   208,   209,   103,    76,
      39,   240,    36,    42,    88,    28,   279,    52,    40,    30,
      31,   171,   171,   284,    53,   123,   123,   135,   135,   -39,
     124,   124,   171,   -37,    71,    30,    31,   241,   123,   123,
     135,   135,    61,   124,   124,   123,    61,   135,   -38,   123,
     124,   135,   187,   188,   124,    58,   134,   134,    18,   234,
     235,    96,    62,    63,    59,   107,    62,    63,    67,   134,
     134,   199,   200,   201,   202,   203,   134,    69,    19,    20,
     134,   199,   200,   201,   202,   203,   204,   205,   206,   207,
     208,   209,    45,    70,    61,    74,   204,   205,   206,   207,
     208,   209,   287,   235,    78,   199,   200,   201,   202,   203,
     290,   235,    46,    47,    62,    63,    77,   197,   198,   210,
     204,   205,   206,   207,   208,   209,   293,   235,    81,   233,
     199,   200,   201,   202,   203,   151,   168,    83,   151,    92,
     152,   153,    94,   152,   153,   204,   205,   206,   207,   208,
     209,   100,   104,   262,   199,   200,   201,   202,   203,   136,
     141,   138,   163,   154,   142,   147,   154,   148,   181,   204,
     205,   217,   182,   149,   150,   218,   119,   183,   264,   119,
     219,   109,   110,   155,   194,   195,   155,   161,   162,   164,
     111,   112,   165,   295,   296,   113,   166,   173,   144,   169,
     172,   145,   190,   146,   109,   110,   114,   115,   174,   193,
     213,   214,   221,   111,   112,   222,   225,   228,   113,   230,
     117,   231,   118,   232,   238,   119,   236,   120,   121,   114,
     115,   145,   255,   237,   256,   259,   265,   116,   260,   261,
     263,   266,   267,   117,   268,   118,   109,   110,   119,   269,
     120,   121,   271,   272,   275,   111,   112,   270,   277,   278,
     113,   280,   297,   276,   281,   282,   283,   285,   291,   109,
     110,   114,   115,   286,   292,   294,   298,    13,   111,   112,
     300,   301,   302,   113,   303,   117,    37,   118,    41,    68,
     119,    82,   120,   121,   114,   115,   175,   109,   110,    89,
     170,   102,   137,   108,     0,     0,   111,   112,   117,     0,
     118,   113,     0,   119,     0,   120,   121,     0,     0,     0,
       0,     0,   114,   115,     0,     0,     0,     0,     0,     0,
     199,   200,   201,   202,   203,     0,   117,     0,   118,     0,
       0,   119,     0,   120,   121,   204,   205,   206,   207,   208,
     209,   199,   200,   201,   202,   203,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   204,   205,   -40,   -40,
     -40,   -40
};

static const yytype_int16 yycheck[] =
{
     100,    14,   100,    14,     0,   100,   116,    14,   125,    14,
      12,    12,    92,    57,    14,   275,   276,    61,    98,    57,
      14,    39,    57,    61,    57,   125,    61,   125,    61,    40,
     125,   100,   142,   143,     8,   295,    49,   147,   148,    13,
      14,   141,    49,   141,    49,   155,    40,   145,    48,    35,
       7,     8,     9,    10,    11,    56,   125,   167,    59,    61,
      61,   161,    36,   173,   164,    22,    23,    24,    25,    26,
      27,    59,    57,    61,    60,    49,    61,    56,    55,    47,
      59,    58,    56,    55,    57,    58,    58,    14,    70,   199,
     200,   201,   202,   203,   204,   205,   206,   207,   208,   209,
      57,     7,     8,     9,    10,    11,    33,    34,    35,    91,
      53,     7,     8,     9,    10,    11,    22,    23,    24,    25,
      26,    27,    14,    14,    14,   235,    22,    23,    24,    25,
      26,    27,     9,    10,    11,    57,    58,     7,     8,     9,
      10,    11,    34,    35,    34,    35,    55,    56,   238,    14,
      32,    57,    22,    23,    24,    25,    26,    27,    57,    58,
      53,    57,    54,    14,    54,    14,   256,    55,    33,    34,
      35,   288,   289,   263,    32,   275,   276,   275,   276,    14,
     275,   276,   299,    14,    33,    34,    35,    57,   288,   289,
     288,   289,    14,   288,   289,   295,    14,   295,    14,   299,
     295,   299,    13,    14,   299,    37,   275,   276,    14,    57,
      58,    33,    34,    35,    14,    33,    34,    35,    13,   288,
     289,     7,     8,     9,    10,    11,   295,    56,    34,    35,
     299,     7,     8,     9,    10,    11,    22,    23,    24,    25,
      26,    27,    14,    56,    14,    14,    22,    23,    24,    25,
      26,    27,    57,    58,    57,     7,     8,     9,    10,    11,
      57,    58,    34,    35,    34,    35,    60,    42,    43,    55,
      22,    23,    24,    25,    26,    27,    57,    58,    14,    55,
       7,     8,     9,    10,    11,     8,    61,    53,     8,    32,
      13,    14,    53,    13,    14,    22,    23,    24,    25,    26,
      27,     3,    14,    55,     7,     8,     9,    10,    11,    54,
      56,    55,    61,    36,    56,    56,    36,    56,    41,    22,
      23,    41,    45,    55,    55,    45,    49,    50,    55,    49,
      50,     5,     6,    56,    42,    43,    56,    56,    56,    56,
      14,    15,    55,    17,    18,    19,     4,    12,    56,    55,
      55,    59,    14,    61,     5,     6,    30,    31,    54,    13,
      57,    14,    14,    14,    15,     4,    61,    57,    19,    55,
      44,    56,    46,    56,    56,    49,    60,    51,    52,    30,
      31,    59,    55,    60,    56,    55,    14,    38,    56,    56,
      56,    14,    55,    44,    14,    46,     5,     6,    49,    55,
      51,    52,    57,    14,    16,    14,    15,    55,    55,    55,
      19,    55,    21,    20,    55,    57,    14,    55,    55,     5,
       6,    30,    31,    57,    57,    55,    55,     6,    14,    15,
      55,    55,    18,    19,    55,    44,    21,    46,    32,    57,
      49,    76,    51,    52,    30,    31,   140,     5,     6,    80,
     125,    94,   102,    98,    -1,    -1,    14,    15,    44,    -1,
      46,    19,    -1,    49,    -1,    51,    52,    -1,    -1,    -1,
      -1,    -1,    30,    31,    -1,    -1,    -1,    -1,    -1,    -1,
       7,     8,     9,    10,    11,    -1,    44,    -1,    46,    -1,
      -1,    49,    -1,    51,    52,    22,    23,    24,    25,    26,
      27,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    22,    23,    24,    25,
      26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    39,    63,    64,    14,    40,    65,    66,    67,     0,
      47,    70,    40,    66,    53,    71,    32,    77,    14,    34,
      35,    68,    69,    80,    14,    48,    72,    73,    14,    33,
      34,    35,    78,    79,    81,    86,    54,    69,    14,    53,
      33,    79,    14,    84,    85,    14,    34,    35,    81,    82,
      87,    90,    55,    32,    56,    59,    55,    58,    37,    14,
      74,    14,    34,    35,    83,    88,    89,    13,    85,    56,
      56,    33,    75,    81,    14,    57,    58,    60,    57,    88,
      76,    14,    89,    53,    57,    14,    34,    35,    54,    87,
      55,    56,    32,    91,    53,    88,    33,    83,    92,    93,
       3,    96,    91,    57,    14,    94,    95,    33,    93,     5,
       6,    14,    15,    19,    30,    31,    38,    44,    46,    49,
      51,    52,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   111,   112,    54,    96,    55,    55,
      58,    56,    56,    12,    56,    59,    61,    56,    56,    55,
      55,     8,    13,    14,    36,    56,    98,    99,   110,   111,
     112,    56,    56,    61,    56,    55,     4,    12,    61,    55,
      97,   101,    55,    12,    54,    95,    14,    49,    98,   112,
     110,    41,    45,    50,   110,   109,   110,    13,    14,   112,
      14,   110,   110,    13,    42,    43,   110,    42,    43,     7,
       8,     9,    10,    11,    22,    23,    24,    25,    26,    27,
      55,    14,    98,    57,    14,    14,    98,    41,    45,    50,
     110,    14,     4,   110,    61,    61,    57,    61,    57,    57,
      55,    56,    56,    55,    57,    58,    60,    60,    56,    57,
      57,    57,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,    57,    57,    55,    56,    57,    57,    55,
      56,    56,    55,    56,    55,    14,    14,    55,    14,    55,
      55,    57,    14,   110,   109,    16,    20,    55,    55,   109,
      55,    55,    57,    14,   109,    55,    57,    57,   100,   100,
      57,    55,    57,    57,    55,    17,    18,    21,    55,   100,
      55,    55,    18,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    64,    64,    64,    65,    65,    66,    67,
      68,    68,    69,    70,    70,    71,    71,    72,    73,    74,
      74,    75,    75,    76,    76,    77,    77,    77,    78,    78,
      79,    80,    80,    80,    81,    81,    81,    82,    82,    82,
      83,    83,    83,    84,    84,    85,    85,    85,    86,    86,
      87,    88,    88,    88,    89,    90,    91,    91,    91,    92,
      92,    93,    94,    94,    95,    96,    96,    97,    98,    98,
      98,    99,    99,    99,   100,   100,   101,   101,   101,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   102,   102,   103,   104,   105,   106,   106,   107,   108,
     108,   108,   108,   108,   108,   108,   108,   108,   109,   109,
     109,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   110,   110,   110,   110,   110,   110,
     110,   110,   110,   110,   111,   112,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     1,     4,     1,
       2,     1,     3,     3,     0,     2,     0,     7,     1,     2,
       0,     3,     6,     2,     0,     3,     2,     0,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     4,     1,     4,     2,     0,
       9,     3,     1,     0,     2,     8,     3,     2,     0,     2,
       1,     3,     3,     1,     1,     4,     3,     3,     3,     3,
       3,     6,     6,     6,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     2,     5,     5,     4,     5,
       5,    10,     8,     8,     2,     2,     5,     5,     5,     4,
       4,     6,     6,     7,     7,     4,     4,     4,     3,     1,
       0,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     2,     2,     2,     3,     1,     2,     1,
       1,     1,     1,     1,     4,     1,     4,     4
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
  case 2: /* program: TypeDefBlock ClassDefBlock GDeclBlock FDefBlock MainBlock  */
#line 63 "exprtree.y"
                                                                   {fclose(intermediate);}
#line 1448 "exprtree.tab.c"
    break;

  case 3: /* TypeDefBlock: TYPE TypeDefList ENDTYPE  */
#line 66 "exprtree.y"
                                        {initialize();}
#line 1454 "exprtree.tab.c"
    break;

  case 4: /* TypeDefBlock: TYPE ENDTYPE  */
#line 67 "exprtree.y"
                                        {initialize();}
#line 1460 "exprtree.tab.c"
    break;

  case 5: /* TypeDefBlock: %empty  */
#line 68 "exprtree.y"
                                        {initialize();}
#line 1466 "exprtree.tab.c"
    break;

  case 8: /* TypeDef: UserDefinedType '{' FieldDeclList '}'  */
#line 75 "exprtree.y"
                                                { TInstall((yyvsp[-3].nptr)->name, Fhead); }
#line 1472 "exprtree.tab.c"
    break;

  case 9: /* UserDefinedType: ID  */
#line 78 "exprtree.y"
                    {
                        tempASTNode = (yyvsp[0].nptr);
                        (yyval.nptr) = (yyvsp[0].nptr);
                    }
#line 1481 "exprtree.tab.c"
    break;

  case 12: /* FieldDecl: FieldType ID ';'  */
#line 88 "exprtree.y"
                            {
                                if(FLookup((yyvsp[-1].nptr)->name, Fhead) != NULL) {
                                    yyerror("Re-declaration of Field element %s\n", (yyvsp[-1].nptr)->name);
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].nptr)->name, declarationType, NULL);
                            }
#line 1493 "exprtree.tab.c"
    break;

  case 17: /* ClassDef: Cname '{' DECL ClassFieldDeclList ENDDECL ClassMethodDefns '}'  */
#line 105 "exprtree.y"
                                                                         {
                                        CCurrent = NULL;
                                        if(defCount != declCount) {
                                            yyerror("All functions declared in class need to be defined\n", NULL);
                                            exit(1);
                                        }
                                        declCount = 0;
                                        defCount = 0;
                                    }
#line 1507 "exprtree.tab.c"
    break;

  case 18: /* Cname: ID  */
#line 116 "exprtree.y"
          {CCurrent = CInstall((yyvsp[0].nptr)->name, NULL);}
#line 1513 "exprtree.tab.c"
    break;

  case 21: /* ClassFieldDecl: Type ID ';'  */
#line 123 "exprtree.y"
                              {
                                checkAvailability((yyvsp[-1].nptr)->name, 2);
                                Class_Finstall(CCurrent, declarationType, declarationCType, (yyvsp[-1].nptr)->name);
                              }
#line 1522 "exprtree.tab.c"
    break;

  case 22: /* ClassFieldDecl: Type ID '(' ParamList ')' ';'  */
#line 127 "exprtree.y"
                                               {
                                                    declCount++;
                                                    checkAvailability((yyvsp[-4].nptr)->name, 2);
                                                    Class_Minstall(CCurrent, (yyvsp[-4].nptr)->name, declarationType, Phead);
                                                    Phead = NULL;
                                                    Ptail = NULL;
                                                }
#line 1534 "exprtree.tab.c"
    break;

  case 25: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 140 "exprtree.y"
                                        {
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1545 "exprtree.tab.c"
    break;

  case 26: /* GDeclBlock: DECL ENDDECL  */
#line 146 "exprtree.y"
                                        {
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1556 "exprtree.tab.c"
    break;

  case 27: /* GDeclBlock: %empty  */
#line 152 "exprtree.y"
                                        {
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1567 "exprtree.tab.c"
    break;

  case 31: /* FieldType: INT  */
#line 167 "exprtree.y"
                {declarationType = TLookup("integer");}
#line 1573 "exprtree.tab.c"
    break;

  case 32: /* FieldType: STR  */
#line 168 "exprtree.y"
                {declarationType = TLookup("string");}
#line 1579 "exprtree.tab.c"
    break;

  case 33: /* FieldType: ID  */
#line 169 "exprtree.y"
                {
                    declarationType = TLookup((yyvsp[0].nptr)->name);
                    if(declarationType == NULL) {
                        if(strcmp(tempASTNode->name, (yyvsp[0].nptr)->name) != 0) {
                            yyerror("Undefined User Defined Type %s\n", (yyvsp[0].nptr)->name);
                            exit(1);
                        } else {
                            declarationType = TLookup("dummy");
                        }
                    }
                }
#line 1595 "exprtree.tab.c"
    break;

  case 34: /* Type: INT  */
#line 182 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1601 "exprtree.tab.c"
    break;

  case 35: /* Type: STR  */
#line 183 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1607 "exprtree.tab.c"
    break;

  case 36: /* Type: ID  */
#line 184 "exprtree.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                declarationCType = CLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL && declarationCType == NULL) {
                    yyerror("Unknown Class/UDT %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1620 "exprtree.tab.c"
    break;

  case 37: /* FType: INT  */
#line 194 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1626 "exprtree.tab.c"
    break;

  case 38: /* FType: STR  */
#line 195 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1632 "exprtree.tab.c"
    break;

  case 39: /* FType: ID  */
#line 196 "exprtree.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL) {
                    yyerror("Unknown return type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1644 "exprtree.tab.c"
    break;

  case 40: /* LType: INT  */
#line 205 "exprtree.y"
            {FDeclarationType = TLookup("integer");}
#line 1650 "exprtree.tab.c"
    break;

  case 41: /* LType: STR  */
#line 206 "exprtree.y"
            {FDeclarationType = TLookup("string");}
#line 1656 "exprtree.tab.c"
    break;

  case 42: /* LType: ID  */
#line 207 "exprtree.y"
            {
                FDeclarationType = TLookup((yyvsp[0].nptr)->name);
                if(FDeclarationType == NULL) {
                    yyerror("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1668 "exprtree.tab.c"
    break;

  case 45: /* GId: ID '(' ParamList ')'  */
#line 221 "exprtree.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, NULL, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1680 "exprtree.tab.c"
    break;

  case 46: /* GId: ID  */
#line 228 "exprtree.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, declarationCType, 1, NULL);
                            }
#line 1689 "exprtree.tab.c"
    break;

  case 47: /* GId: ID '[' NUM ']'  */
#line 232 "exprtree.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) {
                                    yyerror("Invalid array size", NULL);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, NULL, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1702 "exprtree.tab.c"
    break;

  case 50: /* FDef: FType ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 246 "exprtree.y"
                                                         {
                                        defCount++;
                                        if(CCurrent == NULL) {
                                            Gtemp = GLookup((yyvsp[-7].nptr)->name);

                                            if(Gtemp == NULL) {
                                                yyerror("Function %s not declared", (yyvsp[-7].nptr)->name);
                                                exit(1);
                                            }
                                            
                                            if(Gtemp->type != declarationType) {
                                               yyerror("%s : Function type does not match declaration", (yyvsp[-7].nptr)->name);
                                               exit(1);
                                            }

                                            argList2 = Gtemp->paramlist;
                                        } else {
                                            Mtemp = Class_MLookup(CCurrent, (yyvsp[-7].nptr)->name);

                                            if(Mtemp == NULL) {
                                                yyerror("Function %s not declared in class", (yyvsp[-7].nptr)->name);
                                                exit(1);
                                            }

                                            if(Mtemp->type != declarationType) {
                                               yyerror("%s : Function type does not match declaration", (yyvsp[-7].nptr)->name);
                                               exit(1);
                                            }

                                            argList2 = Mtemp->paramlist;
                                        }

                                        argList1 = Phead;

                                        while(argList1 != NULL && argList2 != NULL) {
                                            if(argList1->type != argList2->type) {
                                                yyerror("%s : Conflict in argument types", (yyvsp[-7].nptr)->name);
                                                exit(1);
                                            }

                                            if(strcmp(argList1->name, argList2->name)) {
                                                yyerror("%s : Conflict in argument names", (yyvsp[-7].nptr)->name);
                                                exit(1);
                                            }

                                            argList1 = argList1->next;
                                            argList2 = argList2->next;
                                        }

                                        if ((argList1 != NULL) || (argList2 != NULL)) {
                                            yyerror("Not enough arguments", NULL);
                                            exit(1);
                                        }

                                        if(testing) {
                                            printLSymbolTable((yyvsp[-7].nptr)->name);
                                            //print_dot($8, $2->name);
                                        } else {
                                            if(Gtemp != NULL)
                                                fprintf(intermediate, "F%d:\n",Gtemp->flabel);
                                            else
                                                fprintf(intermediate, "M%d:\n",Mtemp->flabel);
                                            fprintf(intermediate, "PUSH BP\n");
                                            fprintf(intermediate, "MOV BP,SP\n");

                                            Ltemp = Lhead;
                                            while(Ltemp != NULL) {
                                                if(Ltemp->binding > 0)
                                                    fprintf(intermediate, "PUSH R0\n");
                                                Ltemp = Ltemp->next;
                                            }

                                            codegen((yyvsp[-1].nptr));
                                        }

                                        Phead = NULL;
                                        Ptail = NULL;
                                        Lhead = NULL;
                                        Ltail = NULL;
                                    }
#line 1787 "exprtree.tab.c"
    break;

  case 54: /* Param: LType ID  */
#line 333 "exprtree.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1796 "exprtree.tab.c"
    break;

  case 55: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 339 "exprtree.y"
                                                       {
                                                            if(defCount != declCount) {
                                                                yyerror("All functions declared need to be defined\n", NULL);
                                                                exit(1);
                                                            }

                                                            if(declarationType != TLookup("integer")) {
                                                                yyerror("Main return type should be of integer type\n");
                                                                exit(1);
                                                            }

                                                            if(testing) {
                                                                printLSymbolTable("main");
                                                                //print_dot($7, "main");
                                                            } else {
                                                                fprintf(intermediate, "MAIN:\n");
                                                                fprintf(intermediate, "PUSH BP\n");
                                                                fprintf(intermediate, "MOV BP,SP\n");

                                                                Ltemp = Lhead;
                                                                while (Ltemp != NULL)
                                                                {
                                                                    fprintf(intermediate, "PUSH R0\n");
                                                                    Ltemp = Ltemp->next;
                                                                }

                                                                codegen((yyvsp[-1].nptr));
                                                            }

                                                            Lhead = NULL;
                                                            Ltail = NULL;
                                                        }
#line 1833 "exprtree.tab.c"
    break;

  case 56: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 373 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1839 "exprtree.tab.c"
    break;

  case 57: /* LDeclBlock: DECL ENDDECL  */
#line 374 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1845 "exprtree.tab.c"
    break;

  case 58: /* LDeclBlock: %empty  */
#line 375 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1851 "exprtree.tab.c"
    break;

  case 64: /* LId: ID  */
#line 389 "exprtree.y"
        {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
        }
#line 1860 "exprtree.tab.c"
    break;

  case 65: /* Body: START Slist RetStmt END  */
#line 395 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1866 "exprtree.tab.c"
    break;

  case 66: /* Body: START RetStmt END  */
#line 396 "exprtree.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1872 "exprtree.tab.c"
    break;

  case 67: /* RetStmt: RETURN expr ';'  */
#line 399 "exprtree.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1885 "exprtree.tab.c"
    break;

  case 68: /* Field: ID '.' ID  */
#line 409 "exprtree.y"
                        {
                            assignType((yyvsp[-2].nptr), 0);
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1894 "exprtree.tab.c"
    break;

  case 69: /* Field: Field '.' ID  */
#line 413 "exprtree.y"
                        {
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1902 "exprtree.tab.c"
    break;

  case 70: /* Field: SELF '.' ID  */
#line 416 "exprtree.y"
                        {
                            if(CCurrent == NULL) {
                                yyerror("SELF cannot be used outside a class\n", NULL);
                                exit(1);
                            }
                            (yyvsp[-2].nptr)->Ctype = CCurrent;
                            (yyvsp[-2].nptr)->Lentry = LLookup("self");
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1916 "exprtree.tab.c"
    break;

  case 71: /* FieldFunction: SELF '.' ID '(' ExprList ')'  */
#line 427 "exprtree.y"
                                            {
                        if(CCurrent == NULL) {
                            yyerror("SELF cannot be used outside a class\n", NULL);
                            exit(1);
                        }
                        (yyvsp[-5].nptr)->Ctype = CCurrent;
                        (yyvsp[-5].nptr)->Lentry = LLookup("self");
                        (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                        (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                        assignType((yyval.nptr), 3);
                    }
#line 1933 "exprtree.tab.c"
    break;

  case 72: /* FieldFunction: ID '.' ID '(' ExprList ')'  */
#line 439 "exprtree.y"
                                          {
                        assignType((yyvsp[-5].nptr), 0);
                        if((yyvsp[-5].nptr)->Ctype == NULL) {
                            yyerror("%s is not a class object\n", (yyvsp[-5].nptr)->name);
                            exit(1);
                        }
                        (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                        (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                        assignType((yyval.nptr), 3);
                    }
#line 1949 "exprtree.tab.c"
    break;

  case 73: /* FieldFunction: Field '.' ID '(' ExprList ')'  */
#line 450 "exprtree.y"
                                             {
                        if((yyvsp[-5].nptr)->Ctype == NULL) {
                            yyerror("Memberfield is not a class object\n", NULL);
                            exit(1);
                        }
                        (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                        (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                        assignType((yyval.nptr), 3);
                    }
#line 1964 "exprtree.tab.c"
    break;

  case 74: /* Slist: Slist Stmt  */
#line 462 "exprtree.y"
                        {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1970 "exprtree.tab.c"
    break;

  case 75: /* Slist: Stmt  */
#line 463 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1976 "exprtree.tab.c"
    break;

  case 76: /* Stmt: InputStmt  */
#line 466 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1982 "exprtree.tab.c"
    break;

  case 77: /* Stmt: OutputStmt  */
#line 467 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1988 "exprtree.tab.c"
    break;

  case 78: /* Stmt: AsgStmt  */
#line 468 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1994 "exprtree.tab.c"
    break;

  case 79: /* Stmt: IfStmt  */
#line 469 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2000 "exprtree.tab.c"
    break;

  case 80: /* Stmt: WhileStmt  */
#line 470 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2006 "exprtree.tab.c"
    break;

  case 81: /* Stmt: BrkStmt  */
#line 471 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2012 "exprtree.tab.c"
    break;

  case 82: /* Stmt: ContStmt  */
#line 472 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2018 "exprtree.tab.c"
    break;

  case 83: /* Stmt: func ';'  */
#line 473 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2024 "exprtree.tab.c"
    break;

  case 84: /* Stmt: FieldFunction ';'  */
#line 474 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2030 "exprtree.tab.c"
    break;

  case 85: /* Stmt: BREAKPOINT ';'  */
#line 475 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2036 "exprtree.tab.c"
    break;

  case 86: /* Stmt: FREE '(' ID ')' ';'  */
#line 476 "exprtree.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2049 "exprtree.tab.c"
    break;

  case 87: /* Stmt: FREE '(' Field ')' ';'  */
#line 484 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2061 "exprtree.tab.c"
    break;

  case 88: /* Stmt: INIT '(' ')' ';'  */
#line 491 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2067 "exprtree.tab.c"
    break;

  case 89: /* Stmt: DELETE '(' ID ')' ';'  */
#line 492 "exprtree.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_DELETE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2080 "exprtree.tab.c"
    break;

  case 90: /* Stmt: DELETE '(' Field ')' ';'  */
#line 500 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_DELETE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2092 "exprtree.tab.c"
    break;

  case 91: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 509 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TLookup("boolean"), 'e');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 2101 "exprtree.tab.c"
    break;

  case 92: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 513 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'i');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2110 "exprtree.tab.c"
    break;

  case 93: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 519 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'w');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2119 "exprtree.tab.c"
    break;

  case 94: /* BrkStmt: BREAK ';'  */
#line 524 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2125 "exprtree.tab.c"
    break;

  case 95: /* ContStmt: CONT ';'  */
#line 527 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2131 "exprtree.tab.c"
    break;

  case 96: /* InputStmt: READ '(' id ')' ';'  */
#line 530 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2143 "exprtree.tab.c"
    break;

  case 97: /* InputStmt: READ '(' Field ')' ';'  */
#line 537 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2155 "exprtree.tab.c"
    break;

  case 98: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 546 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2161 "exprtree.tab.c"
    break;

  case 99: /* AsgStmt: id ASSGN expr ';'  */
#line 549 "exprtree.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2170 "exprtree.tab.c"
    break;

  case 100: /* AsgStmt: ID ASSGN expr ';'  */
#line 553 "exprtree.y"
                                    {
                                        assignType((yyvsp[-3].nptr), 0);
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2180 "exprtree.tab.c"
    break;

  case 101: /* AsgStmt: Field ASSGN ALLOC '(' ')' ';'  */
#line 558 "exprtree.y"
                                        {
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2192 "exprtree.tab.c"
    break;

  case 102: /* AsgStmt: ID ASSGN ALLOC '(' ')' ';'  */
#line 565 "exprtree.y"
                                        {
                                            assignType((yyvsp[-5].nptr), 0);
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2205 "exprtree.tab.c"
    break;

  case 103: /* AsgStmt: ID ASSGN NEW '(' ID ')' ';'  */
#line 573 "exprtree.y"
                                        {
                                            assignType((yyvsp[-6].nptr), 0);
                                            if((yyvsp[-6].nptr)->Ctype != CLookup((yyvsp[-2].nptr)->name)) {
                                                yyerror("Type mismatch\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2218 "exprtree.tab.c"
    break;

  case 104: /* AsgStmt: Field ASSGN NEW '(' ID ')' ';'  */
#line 581 "exprtree.y"
                                        {
                                            if((yyvsp[-6].nptr)->Ctype != CLookup((yyvsp[-2].nptr)->name)) {
                                                yyerror("Type mismatch\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2230 "exprtree.tab.c"
    break;

  case 105: /* AsgStmt: Field ASSGN expr ';'  */
#line 588 "exprtree.y"
                                        {
                                            typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                    
                                        }
#line 2240 "exprtree.tab.c"
    break;

  case 106: /* AsgStmt: ID ASSGN NILL ';'  */
#line 593 "exprtree.y"
                                        {
                                            assignType((yyvsp[-3].nptr), 0);
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2253 "exprtree.tab.c"
    break;

  case 107: /* AsgStmt: Field ASSGN NILL ';'  */
#line 601 "exprtree.y"
                                        {
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2265 "exprtree.tab.c"
    break;

  case 108: /* ExprList: ExprList ',' expr  */
#line 610 "exprtree.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2274 "exprtree.tab.c"
    break;

  case 109: /* ExprList: expr  */
#line 614 "exprtree.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2280 "exprtree.tab.c"
    break;

  case 110: /* ExprList: %empty  */
#line 615 "exprtree.y"
                            {(yyval.nptr) = NULL;}
#line 2286 "exprtree.tab.c"
    break;

  case 111: /* expr: expr PLUS expr  */
#line 618 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2295 "exprtree.tab.c"
    break;

  case 112: /* expr: expr MINUS expr  */
#line 622 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2304 "exprtree.tab.c"
    break;

  case 113: /* expr: expr MUL expr  */
#line 626 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2313 "exprtree.tab.c"
    break;

  case 114: /* expr: expr DIV expr  */
#line 630 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2322 "exprtree.tab.c"
    break;

  case 115: /* expr: expr MOD expr  */
#line 634 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2331 "exprtree.tab.c"
    break;

  case 116: /* expr: expr LT expr  */
#line 638 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2340 "exprtree.tab.c"
    break;

  case 117: /* expr: expr GT expr  */
#line 642 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2349 "exprtree.tab.c"
    break;

  case 118: /* expr: expr LE expr  */
#line 646 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2358 "exprtree.tab.c"
    break;

  case 119: /* expr: expr GE expr  */
#line 650 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2367 "exprtree.tab.c"
    break;

  case 120: /* expr: expr NEQ expr  */
#line 654 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2376 "exprtree.tab.c"
    break;

  case 121: /* expr: expr EQ expr  */
#line 658 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2385 "exprtree.tab.c"
    break;

  case 122: /* expr: Field DEQNILL  */
#line 662 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2394 "exprtree.tab.c"
    break;

  case 123: /* expr: Field NEQNILL  */
#line 666 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2403 "exprtree.tab.c"
    break;

  case 124: /* expr: ID DEQNILL  */
#line 670 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2412 "exprtree.tab.c"
    break;

  case 125: /* expr: ID NEQNILL  */
#line 674 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2421 "exprtree.tab.c"
    break;

  case 126: /* expr: '(' expr ')'  */
#line 678 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2427 "exprtree.tab.c"
    break;

  case 127: /* expr: NUM  */
#line 679 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2436 "exprtree.tab.c"
    break;

  case 128: /* expr: MINUS NUM  */
#line 683 "exprtree.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2446 "exprtree.tab.c"
    break;

  case 129: /* expr: STRVAL  */
#line 688 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("string");
                        }
#line 2455 "exprtree.tab.c"
    break;

  case 130: /* expr: id  */
#line 692 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2461 "exprtree.tab.c"
    break;

  case 131: /* expr: func  */
#line 693 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2467 "exprtree.tab.c"
    break;

  case 132: /* expr: Field  */
#line 694 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2473 "exprtree.tab.c"
    break;

  case 133: /* expr: FieldFunction  */
#line 695 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2479 "exprtree.tab.c"
    break;

  case 134: /* func: ID '(' ExprList ')'  */
#line 698 "exprtree.y"
                            {
                                assignType((yyvsp[-3].nptr), 1);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                (yyval.nptr) = (yyvsp[-3].nptr);
                            }
#line 2490 "exprtree.tab.c"
    break;

  case 135: /* id: ID  */
#line 705 "exprtree.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2499 "exprtree.tab.c"
    break;

  case 136: /* id: ID '[' NUM ']'  */
#line 709 "exprtree.y"
                        {
                            (yyvsp[-1].nptr)->type = TLookup("integer");
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2509 "exprtree.tab.c"
    break;

  case 137: /* id: ID '[' id ']'  */
#line 714 "exprtree.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2518 "exprtree.tab.c"
    break;


#line 2522 "exprtree.tab.c"

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

#line 720 "exprtree.y"


yyerror(char const *s, char const *var) {
    printf("\033[0;31mERR:%d\033[0m : ", lineno);
    printf(s, var);
}

int main(int argc, char *argv[]) {
    TInstall("integer", NULL);
    TInstall("string", NULL);
    TInstall("boolean", NULL);
    TInstall("void", NULL);
    TInstall("dummy", NULL); // This is for creating the fieldlist in case of udt

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

