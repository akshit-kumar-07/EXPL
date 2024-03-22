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
        int testing = 1; // can use to test ASTree
        struct ASTNode *tempASTNode;

#line 101 "exprtree.tab.c"

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
  YYSYMBOL_BREAK = 28,                     /* BREAK  */
  YYSYMBOL_CONT = 29,                      /* CONT  */
  YYSYMBOL_DECL = 30,                      /* DECL  */
  YYSYMBOL_ENDDECL = 31,                   /* ENDDECL  */
  YYSYMBOL_INT = 32,                       /* INT  */
  YYSYMBOL_STR = 33,                       /* STR  */
  YYSYMBOL_STRVAL = 34,                    /* STRVAL  */
  YYSYMBOL_MAIN = 35,                      /* MAIN  */
  YYSYMBOL_RETURN = 36,                    /* RETURN  */
  YYSYMBOL_TYPE = 37,                      /* TYPE  */
  YYSYMBOL_ENDTYPE = 38,                   /* ENDTYPE  */
  YYSYMBOL_NILL = 39,                      /* NILL  */
  YYSYMBOL_DEQNILL = 40,                   /* DEQNILL  */
  YYSYMBOL_NEQNILL = 41,                   /* NEQNILL  */
  YYSYMBOL_FREE = 42,                      /* FREE  */
  YYSYMBOL_ALLOC = 43,                     /* ALLOC  */
  YYSYMBOL_INIT = 44,                      /* INIT  */
  YYSYMBOL_CLASS = 45,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 46,                  /* ENDCLASS  */
  YYSYMBOL_SELF = 47,                      /* SELF  */
  YYSYMBOL_NEW = 48,                       /* NEW  */
  YYSYMBOL_DELETE = 49,                    /* DELETE  */
  YYSYMBOL_BREAKPOINT = 50,                /* BREAKPOINT  */
  YYSYMBOL_EXTENDS = 51,                   /* EXTENDS  */
  YYSYMBOL_52_ = 52,                       /* '{'  */
  YYSYMBOL_53_ = 53,                       /* '}'  */
  YYSYMBOL_54_ = 54,                       /* ';'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ','  */
  YYSYMBOL_58_ = 58,                       /* '['  */
  YYSYMBOL_59_ = 59,                       /* ']'  */
  YYSYMBOL_60_ = 60,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_program = 62,                   /* program  */
  YYSYMBOL_TypeDefBlock = 63,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 64,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 65,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 66,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 67,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 68,                 /* FieldDecl  */
  YYSYMBOL_ClassDefBlock = 69,             /* ClassDefBlock  */
  YYSYMBOL_ClassDefList = 70,              /* ClassDefList  */
  YYSYMBOL_ClassDef = 71,                  /* ClassDef  */
  YYSYMBOL_Cname = 72,                     /* Cname  */
  YYSYMBOL_ClassFieldDeclList = 73,        /* ClassFieldDeclList  */
  YYSYMBOL_ClassFieldDecl = 74,            /* ClassFieldDecl  */
  YYSYMBOL_ClassMethodDefns = 75,          /* ClassMethodDefns  */
  YYSYMBOL_GDeclBlock = 76,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 77,                 /* GDeclList  */
  YYSYMBOL_GDecl = 78,                     /* GDecl  */
  YYSYMBOL_FieldType = 79,                 /* FieldType  */
  YYSYMBOL_Type = 80,                      /* Type  */
  YYSYMBOL_FType = 81,                     /* FType  */
  YYSYMBOL_LType = 82,                     /* LType  */
  YYSYMBOL_GIdList = 83,                   /* GIdList  */
  YYSYMBOL_GId = 84,                       /* GId  */
  YYSYMBOL_FDefBlock = 85,                 /* FDefBlock  */
  YYSYMBOL_FDef = 86,                      /* FDef  */
  YYSYMBOL_ParamList = 87,                 /* ParamList  */
  YYSYMBOL_Param = 88,                     /* Param  */
  YYSYMBOL_MainBlock = 89,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 90,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 91,                  /* LDecList  */
  YYSYMBOL_LDecl = 92,                     /* LDecl  */
  YYSYMBOL_IdList = 93,                    /* IdList  */
  YYSYMBOL_LId = 94,                       /* LId  */
  YYSYMBOL_Body = 95,                      /* Body  */
  YYSYMBOL_RetStmt = 96,                   /* RetStmt  */
  YYSYMBOL_Field = 97,                     /* Field  */
  YYSYMBOL_FieldFunction = 98,             /* FieldFunction  */
  YYSYMBOL_Slist = 99,                     /* Slist  */
  YYSYMBOL_Stmt = 100,                     /* Stmt  */
  YYSYMBOL_IfStmt = 101,                   /* IfStmt  */
  YYSYMBOL_WhileStmt = 102,                /* WhileStmt  */
  YYSYMBOL_BrkStmt = 103,                  /* BrkStmt  */
  YYSYMBOL_ContStmt = 104,                 /* ContStmt  */
  YYSYMBOL_InputStmt = 105,                /* InputStmt  */
  YYSYMBOL_OutputStmt = 106,               /* OutputStmt  */
  YYSYMBOL_AsgStmt = 107,                  /* AsgStmt  */
  YYSYMBOL_ExprList = 108,                 /* ExprList  */
  YYSYMBOL_expr = 109,                     /* expr  */
  YYSYMBOL_func = 110,                     /* func  */
  YYSYMBOL_id = 111                        /* id  */
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
#define YYLAST   516

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  51
/* YYNRULES -- Number of rules.  */
#define YYNRULES  139
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  307

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


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
      55,    56,     2,     2,    57,     2,    60,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    54,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    58,     2,    59,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    52,     2,    53,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    64,    64,    67,    68,    69,    72,    73,    76,    79,
      85,    86,    89,    98,    99,   102,   103,   106,   117,   118,
     121,   122,   125,   129,   137,   138,   141,   148,   155,   164,
     165,   168,   171,   172,   173,   186,   187,   188,   198,   199,
     200,   209,   210,   211,   221,   222,   225,   232,   236,   246,
     247,   250,   332,   333,   334,   337,   343,   377,   378,   379,
     382,   383,   386,   389,   390,   393,   399,   400,   403,   413,
     417,   420,   431,   443,   454,   466,   467,   470,   471,   472,
     473,   474,   475,   476,   477,   478,   479,   480,   488,   495,
     496,   504,   513,   517,   523,   528,   531,   534,   541,   550,
     553,   558,   564,   571,   579,   586,   592,   597,   605,   614,
     618,   619,   622,   626,   630,   634,   638,   642,   646,   650,
     654,   658,   662,   666,   670,   674,   678,   682,   683,   687,
     692,   696,   697,   698,   699,   702,   733,   737,   742,   746
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
  "LE", "GE", "LT", "GT", "BREAK", "CONT", "DECL", "ENDDECL", "INT", "STR",
  "STRVAL", "MAIN", "RETURN", "TYPE", "ENDTYPE", "NILL", "DEQNILL",
  "NEQNILL", "FREE", "ALLOC", "INIT", "CLASS", "ENDCLASS", "SELF", "NEW",
  "DELETE", "BREAKPOINT", "EXTENDS", "'{'", "'}'", "';'", "'('", "')'",
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

#define YYPACT_NINF (-239)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-41)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -21,    -4,    24,     3,  -239,  -239,     1,  -239,   -23,  -239,
    -239,    52,  -239,  -239,   185,   -10,    45,  -239,  -239,  -239,
    -239,    48,  -239,   110,    83,  -239,  -239,    93,  -239,  -239,
    -239,  -239,   183,  -239,   137,   300,  -239,  -239,   105,   157,
     145,  -239,  -239,   -32,    78,  -239,   166,   170,   196,   178,
     205,  -239,  -239,  -239,  -239,  -239,   329,   233,  -239,   137,
     201,   223,   197,  -239,  -239,  -239,   239,    87,  -239,   211,
    -239,   230,   329,  -239,  -239,   274,  -239,  -239,   329,  -239,
     248,   147,   153,   189,  -239,   273,   254,  -239,  -239,  -239,
    -239,  -239,  -239,   329,   231,   320,   273,   198,  -239,   311,
     276,  -239,   353,   282,   320,   285,  -239,   155,  -239,  -239,
    -239,   294,   301,     0,   302,   305,   286,   309,   283,   316,
     318,   277,   319,   312,   371,   -11,   322,   353,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,   323,   367,  -239,   331,
    -239,  -239,   311,    -7,   283,   279,   283,   297,   373,   283,
     283,  -239,  -239,   375,  -239,   261,  -239,   283,    76,  -239,
     139,  -239,  -239,    -5,   334,   377,    -3,  -239,  -239,   281,
     378,  -239,   389,  -239,  -239,   283,  -239,  -239,    25,   341,
     -43,   338,    96,   342,   349,   350,   225,   242,   458,   347,
      43,   354,   360,   104,   131,  -239,  -239,  -239,   215,  -239,
    -239,   283,   283,   283,   283,   283,   283,   283,   283,   283,
     283,   283,  -239,   -38,    28,   355,   361,    77,   114,   363,
     370,   372,   250,   374,  -239,   258,   404,   412,   376,   414,
     382,   384,  -239,   383,   417,  -239,  -239,   283,  -239,  -239,
    -239,   283,   416,   421,  -239,    99,    99,  -239,  -239,  -239,
      64,    64,   489,   489,   489,   489,   390,   391,  -239,   283,
     392,   394,  -239,   397,   442,  -239,   283,  -239,  -239,  -239,
    -239,  -239,  -239,  -239,   403,   402,   458,   289,   445,   445,
    -239,  -239,   291,  -239,  -239,   407,   406,   313,  -239,   409,
    -239,   336,   393,  -239,  -239,   418,  -239,  -239,   445,   422,
     423,  -239,   405,  -239,  -239,   424,  -239
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       5,     0,     0,    14,     9,     4,     0,     7,     0,     1,
      16,    28,     3,     6,     0,     0,     0,    50,    34,    32,
      33,     0,    11,     0,    18,    13,    15,     0,    37,    27,
      35,    36,     0,    30,     0,     0,     8,    10,     0,     0,
       0,    26,    29,    47,     0,    45,    37,    35,    36,     0,
       0,    49,     2,    12,    19,    21,    54,     0,    31,     0,
       0,     0,     0,    43,    41,    42,     0,     0,    53,     0,
      44,     0,    54,    25,    20,     0,    55,    46,     0,    48,
       0,     0,     0,     0,    52,    59,     0,    40,    38,    39,
      17,    24,    22,    54,     0,     0,    59,     0,    58,     0,
       0,    61,     0,     0,     0,     0,    65,     0,    64,    57,
      60,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    76,    80,
      81,    82,    83,    77,    78,    79,     0,     0,    56,     0,
      23,    62,     0,     0,     0,     0,   111,     0,     0,     0,
       0,    95,    96,     0,   128,   136,   130,     0,   133,   134,
       0,   132,   131,     0,     0,     0,     0,    86,    67,     0,
       0,    85,     0,    75,    84,     0,    51,    63,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   110,   128,
       0,   131,    69,     0,     0,   129,   125,   126,     0,   123,
     124,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,     0,     0,     0,    71,     0,     0,     0,
       0,     0,     0,    70,    66,     0,     0,     0,     0,     0,
       0,     0,   107,     0,     0,   101,   135,     0,   137,   139,
     138,   111,     0,     0,   127,   112,   113,   114,   115,   116,
     122,   121,   119,   120,   117,   118,     0,     0,    89,   111,
       0,     0,   108,     0,     0,   106,   111,   100,    69,    71,
      98,    70,    97,    99,     0,     0,   109,     0,     0,     0,
      87,    88,     0,    90,    91,     0,     0,     0,   103,     0,
      73,     0,     0,    72,   102,     0,    74,   104,     0,     0,
       0,   105,     0,    93,    94,     0,    92
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -239,  -239,  -239,  -239,   464,  -239,  -239,   450,  -239,  -239,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,   443,  -239,   -16,
    -239,   -80,  -239,   420,  -239,   408,     7,   410,  -239,   395,
    -239,   386,  -239,   351,   398,   379,  -102,   -97,  -110,  -119,
    -239,  -239,  -239,  -239,  -239,  -239,  -239,  -238,  -112,   -71,
    -100
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,     6,     7,     8,    21,    22,    11,    15,
      26,    27,    62,    74,    82,    17,    32,    33,    23,    34,
      50,    66,    44,    45,    35,    51,    67,    68,    52,    95,
     100,   101,   107,   108,   103,   124,   158,   159,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   187,   188,   161,
     162
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     125,   169,   137,   277,    24,   126,   160,   178,   173,   213,
       4,   217,   145,   228,    99,     4,     1,   229,   256,    49,
      99,   282,   226,    56,     9,   125,    57,   137,   287,    14,
     126,   136,   182,   186,     5,   190,    25,   193,   194,    12,
     179,   180,   179,   181,   179,   198,    75,   191,    10,   170,
     201,   202,   203,   204,   205,   146,   136,   222,   147,    28,
     148,   214,    18,   225,   218,   206,   207,   208,   209,   210,
     211,   201,   202,   203,   204,   205,    29,    30,    31,    81,
      19,    20,    16,   147,   257,   226,   206,   207,   229,   245,
     246,   247,   248,   249,   250,   251,   252,   253,   254,   255,
      97,    36,   239,   201,   202,   203,   204,   205,   203,   204,
     205,   201,   202,   203,   204,   205,   199,   200,   206,   207,
     208,   209,   210,   211,    38,   276,   206,   207,   208,   209,
     210,   211,    58,   260,    39,    59,   170,   226,   201,   202,
     203,   204,   205,    77,    78,    40,   201,   202,   203,   204,
     205,    43,   231,   206,   207,   208,   209,   210,   211,    53,
     242,   206,   207,   208,   209,   210,   211,    87,   291,   292,
     261,    54,   173,   173,   229,    55,   125,   125,   137,   137,
     -40,   126,   126,   173,   -38,    88,    89,   243,   302,   125,
     125,   137,   137,   212,   126,   126,   125,    28,   137,    18,
     125,   126,   137,    86,    78,   126,    90,   136,   136,   141,
     -39,    28,   142,    60,    41,    30,    31,    19,    20,    61,
     136,   136,   201,   202,   203,   204,   205,   136,    73,    30,
      31,   136,   201,   202,   203,   204,   205,   206,   207,   208,
     209,   210,   211,    92,    93,    63,    69,   206,   207,   208,
     209,   210,   211,    76,   105,    78,    71,   201,   202,   203,
     204,   205,    98,    64,    65,   201,   202,   203,   204,   205,
      79,   244,   206,   207,   208,   209,   210,   211,    72,   235,
     206,   207,   208,   209,   210,   211,    80,   153,    83,   153,
      63,   153,   154,   155,   154,   155,   154,   155,   236,   237,
      85,   196,   197,    94,   265,   153,    96,   109,    64,    65,
     189,   155,   267,   156,    46,   156,   146,   156,   183,   147,
     219,   148,   184,   102,   220,   106,   121,   185,   121,   221,
     121,   156,    47,    48,   157,   138,   157,   165,   157,   140,
     151,   111,   112,    63,   121,   290,   237,   293,   237,   143,
     113,   114,   157,   298,   299,   115,   144,   149,   111,   112,
     150,    64,    65,   152,   116,   117,   167,   113,   114,   296,
     237,   163,   115,   164,   166,   168,   171,   174,   119,   175,
     120,   116,   117,   121,   176,   122,   123,   192,   195,   118,
     215,   216,   223,   224,   230,   119,   232,   120,   111,   112,
     121,   227,   122,   123,   233,   234,   238,   113,   114,   258,
     111,   112,   115,   240,   300,   241,   259,   262,   268,   113,
     114,   116,   117,   305,   115,   263,   269,   264,   271,   266,
     270,   275,   278,   116,   117,   119,   272,   120,   273,   274,
     121,   279,   122,   123,   280,   281,   283,   119,   284,   120,
     111,   112,   121,   285,   122,   123,   286,   288,   289,   113,
     114,   294,   295,   297,   115,   201,   202,   203,   204,   205,
      13,    37,   301,   116,   117,    42,   303,   304,   306,    70,
     206,   207,   208,   209,   210,   211,   110,   119,    84,   120,
      91,   104,   121,   177,   122,   123,   201,   202,   203,   204,
     205,     0,   139,     0,     0,     0,   172,     0,     0,     0,
       0,   206,   207,   -41,   -41,   -41,   -41
};

static const yytype_int16 yycheck[] =
{
     102,    12,   102,   241,    14,   102,   118,    14,   127,    14,
      14,    14,    12,    56,    94,    14,    37,    60,    56,    35,
     100,   259,    60,    55,     0,   127,    58,   127,   266,    52,
     127,   102,   144,   145,    38,   147,    46,   149,   150,    38,
      47,   143,    47,   143,    47,   157,    62,   147,    45,    60,
       7,     8,     9,    10,    11,    55,   127,   169,    58,    14,
      60,   163,    14,   175,   166,    22,    23,    24,    25,    26,
      27,     7,     8,     9,    10,    11,    31,    32,    33,    72,
      32,    33,    30,    58,    56,    60,    22,    23,    60,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   210,   211,
      93,    53,    59,     7,     8,     9,    10,    11,     9,    10,
      11,     7,     8,     9,    10,    11,    40,    41,    22,    23,
      24,    25,    26,    27,    14,   237,    22,    23,    24,    25,
      26,    27,    54,    56,    51,    57,    60,    60,     7,     8,
       9,    10,    11,    56,    57,    52,     7,     8,     9,    10,
      11,    14,    56,    22,    23,    24,    25,    26,    27,    54,
      56,    22,    23,    24,    25,    26,    27,    14,   278,   279,
      56,    14,   291,   292,    60,    30,   278,   279,   278,   279,
      14,   278,   279,   302,    14,    32,    33,    56,   298,   291,
     292,   291,   292,    54,   291,   292,   298,    14,   298,    14,
     302,   298,   302,    56,    57,   302,    53,   278,   279,    54,
      14,    14,    57,    35,    31,    32,    33,    32,    33,    14,
     291,   292,     7,     8,     9,    10,    11,   298,    31,    32,
      33,   302,     7,     8,     9,    10,    11,    22,    23,    24,
      25,    26,    27,    54,    55,    14,    13,    22,    23,    24,
      25,    26,    27,    14,    56,    57,    55,     7,     8,     9,
      10,    11,    31,    32,    33,     7,     8,     9,    10,    11,
      59,    56,    22,    23,    24,    25,    26,    27,    55,    54,
      22,    23,    24,    25,    26,    27,    56,     8,    14,     8,
      14,     8,    13,    14,    13,    14,    13,    14,    56,    57,
      52,    40,    41,    30,    54,     8,    52,    31,    32,    33,
      13,    14,    54,    34,    14,    34,    55,    34,    39,    58,
      39,    60,    43,     3,    43,    14,    47,    48,    47,    48,
      47,    34,    32,    33,    55,    53,    55,    60,    55,    54,
      54,     5,     6,    14,    47,    56,    57,    56,    57,    55,
      14,    15,    55,    17,    18,    19,    55,    55,     5,     6,
      55,    32,    33,    54,    28,    29,    54,    14,    15,    56,
      57,    55,    19,    55,    55,     4,    54,    54,    42,    12,
      44,    28,    29,    47,    53,    49,    50,    14,    13,    36,
      56,    14,    14,     4,    56,    42,    54,    44,     5,     6,
      47,    60,    49,    50,    55,    55,    59,    14,    15,    54,
       5,     6,    19,    59,    21,    55,    55,    54,    14,    14,
      15,    28,    29,    18,    19,    55,    14,    55,    14,    55,
      54,    14,    16,    28,    29,    42,    54,    44,    54,    56,
      47,    20,    49,    50,    54,    54,    54,    42,    54,    44,
       5,     6,    47,    56,    49,    50,    14,    54,    56,    14,
      15,    54,    56,    54,    19,     7,     8,     9,    10,    11,
       6,    21,    54,    28,    29,    32,    54,    54,    54,    59,
      22,    23,    24,    25,    26,    27,   100,    42,    78,    44,
      82,    96,    47,   142,    49,    50,     7,     8,     9,    10,
      11,    -1,   104,    -1,    -1,    -1,   127,    -1,    -1,    -1,
      -1,    22,    23,    24,    25,    26,    27
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    37,    62,    63,    14,    38,    64,    65,    66,     0,
      45,    69,    38,    65,    52,    70,    30,    76,    14,    32,
      33,    67,    68,    79,    14,    46,    71,    72,    14,    31,
      32,    33,    77,    78,    80,    85,    53,    68,    14,    51,
      52,    31,    78,    14,    83,    84,    14,    32,    33,    80,
      81,    86,    89,    54,    14,    30,    55,    58,    54,    57,
      35,    14,    73,    14,    32,    33,    82,    87,    88,    13,
      84,    55,    55,    31,    74,    80,    14,    56,    57,    59,
      56,    87,    75,    14,    88,    52,    56,    14,    32,    33,
      53,    86,    54,    55,    30,    90,    52,    87,    31,    82,
      91,    92,     3,    95,    90,    56,    14,    93,    94,    31,
      92,     5,     6,    14,    15,    19,    28,    29,    36,    42,
      44,    47,    49,    50,    96,    97,    98,    99,   100,   101,
     102,   103,   104,   105,   106,   107,   110,   111,    53,    95,
      54,    54,    57,    55,    55,    12,    55,    58,    60,    55,
      55,    54,    54,     8,    13,    14,    34,    55,    97,    98,
     109,   110,   111,    55,    55,    60,    55,    54,     4,    12,
      60,    54,    96,   100,    54,    12,    53,    94,    14,    47,
      97,   111,   109,    39,    43,    48,   109,   108,   109,    13,
     109,   111,    14,   109,   109,    13,    40,    41,   109,    40,
      41,     7,     8,     9,    10,    11,    22,    23,    24,    25,
      26,    27,    54,    14,    97,    56,    14,    14,    97,    39,
      43,    48,   109,    14,     4,   109,    60,    60,    56,    60,
      56,    56,    54,    55,    55,    54,    56,    57,    59,    59,
      59,    55,    56,    56,    56,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,    56,    56,    54,    55,
      56,    56,    54,    55,    55,    54,    55,    54,    14,    14,
      54,    14,    54,    54,    56,    14,   109,   108,    16,    20,
      54,    54,   108,    54,    54,    56,    14,   108,    54,    56,
      56,    99,    99,    56,    54,    56,    56,    54,    17,    18,
      21,    54,    99,    54,    54,    18,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    63,    63,    63,    64,    64,    65,    66,
      67,    67,    68,    69,    69,    70,    70,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    76,    77,
      77,    78,    79,    79,    79,    80,    80,    80,    81,    81,
      81,    82,    82,    82,    83,    83,    84,    84,    84,    85,
      85,    86,    87,    87,    87,    88,    89,    90,    90,    90,
      91,    91,    92,    93,    93,    94,    95,    95,    96,    97,
      97,    97,    98,    98,    98,    99,    99,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   103,   104,   105,   105,   106,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   108,
     108,   108,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   110,   111,   111,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     0,     2,     1,     4,     1,
       2,     1,     3,     3,     0,     2,     0,     7,     1,     3,
       2,     0,     3,     6,     2,     0,     3,     2,     0,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     4,     1,     4,     2,
       0,     9,     3,     1,     0,     2,     8,     3,     2,     0,
       2,     1,     3,     3,     1,     1,     4,     3,     3,     3,
       3,     3,     6,     6,     6,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     2,     5,     5,     4,
       5,     5,    10,     8,     8,     2,     2,     5,     5,     5,
       4,     4,     6,     6,     7,     7,     4,     4,     4,     3,
       1,     0,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     2,     3,     1,     2,
       1,     1,     1,     1,     1,     4,     1,     4,     4,     4
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
#line 64 "exprtree.y"
                                                                   {fclose(intermediate);}
#line 1446 "exprtree.tab.c"
    break;

  case 8: /* TypeDef: UserDefinedType '{' FieldDeclList '}'  */
#line 76 "exprtree.y"
                                                { TInstall((yyvsp[-3].nptr)->name, Fhead); }
#line 1452 "exprtree.tab.c"
    break;

  case 9: /* UserDefinedType: ID  */
#line 79 "exprtree.y"
                    {
                        tempASTNode = (yyvsp[0].nptr);
                        (yyval.nptr) = (yyvsp[0].nptr);
                    }
#line 1461 "exprtree.tab.c"
    break;

  case 12: /* FieldDecl: FieldType ID ';'  */
#line 89 "exprtree.y"
                            {
                                if(FLookup((yyvsp[-1].nptr)->name, Fhead) != NULL) {
                                    yyerror("Re-declaration of Field element %s\n", (yyvsp[-1].nptr)->name);
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].nptr)->name, declarationType, NULL);
                            }
#line 1473 "exprtree.tab.c"
    break;

  case 13: /* ClassDefBlock: CLASS ClassDefList ENDCLASS  */
#line 98 "exprtree.y"
                                           {initialize();}
#line 1479 "exprtree.tab.c"
    break;

  case 14: /* ClassDefBlock: %empty  */
#line 99 "exprtree.y"
                                           {initialize();}
#line 1485 "exprtree.tab.c"
    break;

  case 17: /* ClassDef: Cname '{' DECL ClassFieldDeclList ENDDECL ClassMethodDefns '}'  */
#line 106 "exprtree.y"
                                                                         {
                                        CCurrent = NULL;
                                        if(defCount != declCount) {
                                            yyerror("All functions declared in class need to be defined\n", NULL);
                                            exit(1);
                                        }
                                        declCount = 0;
                                        defCount = 0;
                                    }
#line 1499 "exprtree.tab.c"
    break;

  case 18: /* Cname: ID  */
#line 117 "exprtree.y"
          {CCurrent = CInstall((yyvsp[0].nptr)->name, NULL);}
#line 1505 "exprtree.tab.c"
    break;

  case 19: /* Cname: ID EXTENDS ID  */
#line 118 "exprtree.y"
                     {CCurrent = CInstall((yyvsp[-2].nptr)->name, (yyvsp[0].nptr)->name);}
#line 1511 "exprtree.tab.c"
    break;

  case 22: /* ClassFieldDecl: Type ID ';'  */
#line 125 "exprtree.y"
                              {
                                checkAvailability((yyvsp[-1].nptr)->name, 2);
                                Class_Finstall(CCurrent, declarationType, declarationCType, (yyvsp[-1].nptr)->name);
                              }
#line 1520 "exprtree.tab.c"
    break;

  case 23: /* ClassFieldDecl: Type ID '(' ParamList ')' ';'  */
#line 129 "exprtree.y"
                                               {
                                                    declCount++;
                                                    Class_Minstall(CCurrent, (yyvsp[-4].nptr)->name, declarationType, Phead);
                                                    Phead = NULL;
                                                    Ptail = NULL;
                                                }
#line 1531 "exprtree.tab.c"
    break;

  case 26: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 141 "exprtree.y"
                                        {
                                            start();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1543 "exprtree.tab.c"
    break;

  case 27: /* GDeclBlock: DECL ENDDECL  */
#line 148 "exprtree.y"
                                        {
                                            start();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1555 "exprtree.tab.c"
    break;

  case 28: /* GDeclBlock: %empty  */
#line 155 "exprtree.y"
                                        {
                                            start();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1567 "exprtree.tab.c"
    break;

  case 32: /* FieldType: INT  */
#line 171 "exprtree.y"
                {declarationType = TLookup("integer");}
#line 1573 "exprtree.tab.c"
    break;

  case 33: /* FieldType: STR  */
#line 172 "exprtree.y"
                {declarationType = TLookup("string");}
#line 1579 "exprtree.tab.c"
    break;

  case 34: /* FieldType: ID  */
#line 173 "exprtree.y"
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

  case 35: /* Type: INT  */
#line 186 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1601 "exprtree.tab.c"
    break;

  case 36: /* Type: STR  */
#line 187 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1607 "exprtree.tab.c"
    break;

  case 37: /* Type: ID  */
#line 188 "exprtree.y"
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

  case 38: /* FType: INT  */
#line 198 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1626 "exprtree.tab.c"
    break;

  case 39: /* FType: STR  */
#line 199 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1632 "exprtree.tab.c"
    break;

  case 40: /* FType: ID  */
#line 200 "exprtree.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL) {
                    yyerror("Unknown return type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1644 "exprtree.tab.c"
    break;

  case 41: /* LType: INT  */
#line 209 "exprtree.y"
            {FDeclarationType = TLookup("integer");}
#line 1650 "exprtree.tab.c"
    break;

  case 42: /* LType: STR  */
#line 210 "exprtree.y"
            {FDeclarationType = TLookup("string");}
#line 1656 "exprtree.tab.c"
    break;

  case 43: /* LType: ID  */
#line 211 "exprtree.y"
            {
                FDeclarationType = TLookup((yyvsp[0].nptr)->name);
                if(FDeclarationType == NULL) {
                    yyerror("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1668 "exprtree.tab.c"
    break;

  case 46: /* GId: ID '(' ParamList ')'  */
#line 225 "exprtree.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, NULL, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1680 "exprtree.tab.c"
    break;

  case 47: /* GId: ID  */
#line 232 "exprtree.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, declarationCType, 1, NULL);
                            }
#line 1689 "exprtree.tab.c"
    break;

  case 48: /* GId: ID '[' NUM ']'  */
#line 236 "exprtree.y"
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

  case 51: /* FDef: FType ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 250 "exprtree.y"
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
                                            Mtemp = Class_Mlookup(CCurrent, (yyvsp[-7].nptr)->name);

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

  case 55: /* Param: LType ID  */
#line 337 "exprtree.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1796 "exprtree.tab.c"
    break;

  case 56: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 343 "exprtree.y"
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

  case 57: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 377 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1839 "exprtree.tab.c"
    break;

  case 58: /* LDeclBlock: DECL ENDDECL  */
#line 378 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1845 "exprtree.tab.c"
    break;

  case 59: /* LDeclBlock: %empty  */
#line 379 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1851 "exprtree.tab.c"
    break;

  case 65: /* LId: ID  */
#line 393 "exprtree.y"
        {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
        }
#line 1860 "exprtree.tab.c"
    break;

  case 66: /* Body: START Slist RetStmt END  */
#line 399 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1866 "exprtree.tab.c"
    break;

  case 67: /* Body: START RetStmt END  */
#line 400 "exprtree.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1872 "exprtree.tab.c"
    break;

  case 68: /* RetStmt: RETURN expr ';'  */
#line 403 "exprtree.y"
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

  case 69: /* Field: ID '.' ID  */
#line 413 "exprtree.y"
                        {
                            assignType((yyvsp[-2].nptr), 0);
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1894 "exprtree.tab.c"
    break;

  case 70: /* Field: Field '.' ID  */
#line 417 "exprtree.y"
                        {
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1902 "exprtree.tab.c"
    break;

  case 71: /* Field: SELF '.' ID  */
#line 420 "exprtree.y"
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

  case 72: /* FieldFunction: SELF '.' ID '(' ExprList ')'  */
#line 431 "exprtree.y"
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

  case 73: /* FieldFunction: ID '.' ID '(' ExprList ')'  */
#line 443 "exprtree.y"
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

  case 74: /* FieldFunction: Field '.' ID '(' ExprList ')'  */
#line 454 "exprtree.y"
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

  case 75: /* Slist: Slist Stmt  */
#line 466 "exprtree.y"
                        {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1970 "exprtree.tab.c"
    break;

  case 76: /* Slist: Stmt  */
#line 467 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1976 "exprtree.tab.c"
    break;

  case 77: /* Stmt: InputStmt  */
#line 470 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1982 "exprtree.tab.c"
    break;

  case 78: /* Stmt: OutputStmt  */
#line 471 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1988 "exprtree.tab.c"
    break;

  case 79: /* Stmt: AsgStmt  */
#line 472 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1994 "exprtree.tab.c"
    break;

  case 80: /* Stmt: IfStmt  */
#line 473 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2000 "exprtree.tab.c"
    break;

  case 81: /* Stmt: WhileStmt  */
#line 474 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2006 "exprtree.tab.c"
    break;

  case 82: /* Stmt: BrkStmt  */
#line 475 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2012 "exprtree.tab.c"
    break;

  case 83: /* Stmt: ContStmt  */
#line 476 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2018 "exprtree.tab.c"
    break;

  case 84: /* Stmt: func ';'  */
#line 477 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2024 "exprtree.tab.c"
    break;

  case 85: /* Stmt: FieldFunction ';'  */
#line 478 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2030 "exprtree.tab.c"
    break;

  case 86: /* Stmt: BREAKPOINT ';'  */
#line 479 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2036 "exprtree.tab.c"
    break;

  case 87: /* Stmt: FREE '(' ID ')' ';'  */
#line 480 "exprtree.y"
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

  case 88: /* Stmt: FREE '(' Field ')' ';'  */
#line 488 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2061 "exprtree.tab.c"
    break;

  case 89: /* Stmt: INIT '(' ')' ';'  */
#line 495 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2067 "exprtree.tab.c"
    break;

  case 90: /* Stmt: DELETE '(' ID ')' ';'  */
#line 496 "exprtree.y"
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

  case 91: /* Stmt: DELETE '(' Field ')' ';'  */
#line 504 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_DELETE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2092 "exprtree.tab.c"
    break;

  case 92: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 513 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TLookup("boolean"), 'e');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 2101 "exprtree.tab.c"
    break;

  case 93: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 517 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'i');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2110 "exprtree.tab.c"
    break;

  case 94: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 523 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'w');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2119 "exprtree.tab.c"
    break;

  case 95: /* BrkStmt: BREAK ';'  */
#line 528 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2125 "exprtree.tab.c"
    break;

  case 96: /* ContStmt: CONT ';'  */
#line 531 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2131 "exprtree.tab.c"
    break;

  case 97: /* InputStmt: READ '(' id ')' ';'  */
#line 534 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2143 "exprtree.tab.c"
    break;

  case 98: /* InputStmt: READ '(' Field ')' ';'  */
#line 541 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2155 "exprtree.tab.c"
    break;

  case 99: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 550 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2161 "exprtree.tab.c"
    break;

  case 100: /* AsgStmt: id ASSGN expr ';'  */
#line 553 "exprtree.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        classTypecheck((yyvsp[-3].nptr)->Ctype, (yyvsp[-1].nptr)->Ctype);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2171 "exprtree.tab.c"
    break;

  case 101: /* AsgStmt: ID ASSGN expr ';'  */
#line 558 "exprtree.y"
                                    {
                                        assignType((yyvsp[-3].nptr), 0);
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        classTypecheck((yyvsp[-3].nptr)->Ctype, (yyvsp[-1].nptr)->Ctype);
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2182 "exprtree.tab.c"
    break;

  case 102: /* AsgStmt: Field ASSGN ALLOC '(' ')' ';'  */
#line 564 "exprtree.y"
                                        {
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2194 "exprtree.tab.c"
    break;

  case 103: /* AsgStmt: ID ASSGN ALLOC '(' ')' ';'  */
#line 571 "exprtree.y"
                                        {
                                            assignType((yyvsp[-5].nptr), 0);
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2207 "exprtree.tab.c"
    break;

  case 104: /* AsgStmt: ID ASSGN NEW '(' ID ')' ';'  */
#line 579 "exprtree.y"
                                        {
                                            assignType((yyvsp[-6].nptr), 0);
                                            classTypecheck((yyvsp[-6].nptr)->Ctype, CLookup((yyvsp[-2].nptr)->name)); //check if the assignment is compatible with the type check
                                            (yyvsp[-2].nptr)->Ctype = CLookup((yyvsp[-2].nptr)->name);
                                            (yyvsp[-4].nptr)->ptr1 = (yyvsp[-2].nptr);
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2219 "exprtree.tab.c"
    break;

  case 105: /* AsgStmt: Field ASSGN NEW '(' ID ')' ';'  */
#line 586 "exprtree.y"
                                        {
                                            classTypecheck((yyvsp[-6].nptr)->Ctype, CLookup((yyvsp[-2].nptr)->name));
                                            (yyvsp[-2].nptr)->Ctype = CLookup((yyvsp[-2].nptr)->name);
                                            (yyvsp[-4].nptr)->ptr1 = (yyvsp[-2].nptr);
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2230 "exprtree.tab.c"
    break;

  case 106: /* AsgStmt: Field ASSGN expr ';'  */
#line 592 "exprtree.y"
                                        {
                                            typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                    
                                        }
#line 2240 "exprtree.tab.c"
    break;

  case 107: /* AsgStmt: ID ASSGN NILL ';'  */
#line 597 "exprtree.y"
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

  case 108: /* AsgStmt: Field ASSGN NILL ';'  */
#line 605 "exprtree.y"
                                        {
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2265 "exprtree.tab.c"
    break;

  case 109: /* ExprList: ExprList ',' expr  */
#line 614 "exprtree.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2274 "exprtree.tab.c"
    break;

  case 110: /* ExprList: expr  */
#line 618 "exprtree.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2280 "exprtree.tab.c"
    break;

  case 111: /* ExprList: %empty  */
#line 619 "exprtree.y"
                            {(yyval.nptr) = NULL;}
#line 2286 "exprtree.tab.c"
    break;

  case 112: /* expr: expr PLUS expr  */
#line 622 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2295 "exprtree.tab.c"
    break;

  case 113: /* expr: expr MINUS expr  */
#line 626 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2304 "exprtree.tab.c"
    break;

  case 114: /* expr: expr MUL expr  */
#line 630 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2313 "exprtree.tab.c"
    break;

  case 115: /* expr: expr DIV expr  */
#line 634 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2322 "exprtree.tab.c"
    break;

  case 116: /* expr: expr MOD expr  */
#line 638 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2331 "exprtree.tab.c"
    break;

  case 117: /* expr: expr LT expr  */
#line 642 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2340 "exprtree.tab.c"
    break;

  case 118: /* expr: expr GT expr  */
#line 646 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2349 "exprtree.tab.c"
    break;

  case 119: /* expr: expr LE expr  */
#line 650 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2358 "exprtree.tab.c"
    break;

  case 120: /* expr: expr GE expr  */
#line 654 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2367 "exprtree.tab.c"
    break;

  case 121: /* expr: expr NEQ expr  */
#line 658 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2376 "exprtree.tab.c"
    break;

  case 122: /* expr: expr EQ expr  */
#line 662 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2385 "exprtree.tab.c"
    break;

  case 123: /* expr: Field DEQNILL  */
#line 666 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2394 "exprtree.tab.c"
    break;

  case 124: /* expr: Field NEQNILL  */
#line 670 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2403 "exprtree.tab.c"
    break;

  case 125: /* expr: ID DEQNILL  */
#line 674 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2412 "exprtree.tab.c"
    break;

  case 126: /* expr: ID NEQNILL  */
#line 678 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2421 "exprtree.tab.c"
    break;

  case 127: /* expr: '(' expr ')'  */
#line 682 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2427 "exprtree.tab.c"
    break;

  case 128: /* expr: NUM  */
#line 683 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2436 "exprtree.tab.c"
    break;

  case 129: /* expr: MINUS NUM  */
#line 687 "exprtree.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2446 "exprtree.tab.c"
    break;

  case 130: /* expr: STRVAL  */
#line 692 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("string");
                        }
#line 2455 "exprtree.tab.c"
    break;

  case 131: /* expr: id  */
#line 696 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2461 "exprtree.tab.c"
    break;

  case 132: /* expr: func  */
#line 697 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2467 "exprtree.tab.c"
    break;

  case 133: /* expr: Field  */
#line 698 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2473 "exprtree.tab.c"
    break;

  case 134: /* expr: FieldFunction  */
#line 699 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2479 "exprtree.tab.c"
    break;

  case 135: /* func: ID '(' ExprList ')'  */
#line 702 "exprtree.y"
                            {
                                if((yyvsp[-1].nptr)->type == TLookup("boolean"))
                                {
                                    yyerror("Type INT Expression expected in function argument in line %d\n",lineno);
                                    exit(1);

                                }
                                assignType((yyvsp[-3].nptr), 1);
                                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                                (yyvsp[-3].nptr)->ptr3 = (GLookup((yyvsp[-3].nptr)->name))->paramlist;
                                struct ASTNode *args = (yyvsp[-3].nptr)->ptr1;
                                struct Paramstruct *params = (yyvsp[-3].nptr)->ptr3;
                                while(args != NULL && params != NULL)
                                {
                                    if(args->type != params->type)
                                    {
                                        yyerror("Type mismatch\n");
                                        exit(1);
                                    }
                                    args = args->arglist;
                                    params = params->next;
                                }
                                if(args != NULL || params != NULL)
                                {
                                    yyerror("Incorrect number of arguments on function invocation\n");
                                    exit(1);
                                }
                                (yyval.nptr) = (yyvsp[-3].nptr);
                            }
#line 2514 "exprtree.tab.c"
    break;

  case 136: /* id: ID  */
#line 733 "exprtree.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2523 "exprtree.tab.c"
    break;

  case 137: /* id: ID '[' NUM ']'  */
#line 737 "exprtree.y"
                        {
                            (yyvsp[-1].nptr)->type = TLookup("integer");
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2533 "exprtree.tab.c"
    break;

  case 138: /* id: ID '[' id ']'  */
#line 742 "exprtree.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2542 "exprtree.tab.c"
    break;

  case 139: /* id: ID '[' expr ']'  */
#line 747 "exprtree.y"
    {
        if((yyvsp[-1].nptr)->type!=TLookup("integer"))
        {
        	fprintf(stderr,"Expected an arithmetic expression in the index for array %s\n",(yyvsp[-3].nptr)->name);
        	exit(1);
        }
        assignType((yyvsp[-3].nptr), 2);
        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
       }
#line 2556 "exprtree.tab.c"
    break;


#line 2560 "exprtree.tab.c"

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

#line 758 "exprtree.y"


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

    intermediate = fopen("machinecode.xsm", "w");

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

