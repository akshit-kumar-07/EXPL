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
       	#include "symboltable.h"
        #include "symboltable.c"
		#include "ast.c"
        #include "codegen.c"
        #include "initialize.c"
        #include "typecheck.h"
        #include "typecheck.c"

		int yylex(void);
        extern FILE *yyin;
        extern int lineno;
        FILE *fp;
        FILE *intermediate;
        void print(int);
        struct Paramstruct *argList1, *argList2;
        int declCount = 0, defCount = 0; // Definition and Declaration count of functions
	int testing = 0;
	struct ASTNode *tempASTNode;

#line 95 "y.tab.c"

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
    START = 258,                   /* START  */
    END = 259,                     /* END  */
    READ = 260,                    /* READ  */
    WRITE = 261,                   /* WRITE  */
    PLUS = 262,                    /* PLUS  */
    MINUS = 263,                   /* MINUS  */
    MUL = 264,                     /* MUL  */
    DIV = 265,                     /* DIV  */
    MOD = 266,                     /* MOD  */
    ASSGN = 267,                   /* ASSGN  */
    NUM = 268,                     /* NUM  */
    ID = 269,                      /* ID  */
    IF = 270,                      /* IF  */
    THEN = 271,                    /* THEN  */
    ELSE = 272,                    /* ELSE  */
    ENDIF = 273,                   /* ENDIF  */
    WHILE = 274,                   /* WHILE  */
    DO = 275,                      /* DO  */
    ENDWHILE = 276,                /* ENDWHILE  */
    EQ = 277,                      /* EQ  */
    NEQ = 278,                     /* NEQ  */
    LE = 279,                      /* LE  */
    GE = 280,                      /* GE  */
    LT = 281,                      /* LT  */
    GT = 282,                      /* GT  */
    BREAK = 283,                   /* BREAK  */
    CONT = 284,                    /* CONT  */
    DECL = 285,                    /* DECL  */
    ENDDECL = 286,                 /* ENDDECL  */
    INT = 287,                     /* INT  */
    STR = 288,                     /* STR  */
    STRVAL = 289,                  /* STRVAL  */
    MAIN = 290,                    /* MAIN  */
    RETURN = 291,                  /* RETURN  */
    TYPE = 292,                    /* TYPE  */
    ENDTYPE = 293,                 /* ENDTYPE  */
    NILL = 294,                    /* NILL  */
    DEQNILL = 295,                 /* DEQNILL  */
    NEQNILL = 296,                 /* NEQNILL  */
    FREE = 297,                    /* FREE  */
    ALLOC = 298,                   /* ALLOC  */
    INIT = 299                     /* INIT  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define START 258
#define END 259
#define READ 260
#define WRITE 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
#define MOD 266
#define ASSGN 267
#define NUM 268
#define ID 269
#define IF 270
#define THEN 271
#define ELSE 272
#define ENDIF 273
#define WHILE 274
#define DO 275
#define ENDWHILE 276
#define EQ 277
#define NEQ 278
#define LE 279
#define GE 280
#define LT 281
#define GT 282
#define BREAK 283
#define CONT 284
#define DECL 285
#define ENDDECL 286
#define INT 287
#define STR 288
#define STRVAL 289
#define MAIN 290
#define RETURN 291
#define TYPE 292
#define ENDTYPE 293
#define NILL 294
#define DEQNILL 295
#define NEQNILL 296
#define FREE 297
#define ALLOC 298
#define INIT 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "exprtree.y"

    struct ASTNode *nptr;

#line 240 "y.tab.c"

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
  YYSYMBOL_45_ = 45,                       /* '{'  */
  YYSYMBOL_46_ = 46,                       /* '}'  */
  YYSYMBOL_47_ = 47,                       /* ';'  */
  YYSYMBOL_48_ = 48,                       /* ','  */
  YYSYMBOL_49_ = 49,                       /* '('  */
  YYSYMBOL_50_ = 50,                       /* ')'  */
  YYSYMBOL_51_ = 51,                       /* '['  */
  YYSYMBOL_52_ = 52,                       /* ']'  */
  YYSYMBOL_53_ = 53,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_TypeDefBlock = 56,              /* TypeDefBlock  */
  YYSYMBOL_TypeDefList = 57,               /* TypeDefList  */
  YYSYMBOL_TypeDef = 58,                   /* TypeDef  */
  YYSYMBOL_UserDefinedType = 59,           /* UserDefinedType  */
  YYSYMBOL_FieldDeclList = 60,             /* FieldDeclList  */
  YYSYMBOL_FieldDecl = 61,                 /* FieldDecl  */
  YYSYMBOL_GDeclBlock = 62,                /* GDeclBlock  */
  YYSYMBOL_GDeclList = 63,                 /* GDeclList  */
  YYSYMBOL_GDecl = 64,                     /* GDecl  */
  YYSYMBOL_FieldType = 65,                 /* FieldType  */
  YYSYMBOL_Type = 66,                      /* Type  */
  YYSYMBOL_FType = 67,                     /* FType  */
  YYSYMBOL_GIdList = 68,                   /* GIdList  */
  YYSYMBOL_GId = 69,                       /* GId  */
  YYSYMBOL_FDefBlock = 70,                 /* FDefBlock  */
  YYSYMBOL_FDef = 71,                      /* FDef  */
  YYSYMBOL_ParamList = 72,                 /* ParamList  */
  YYSYMBOL_Param = 73,                     /* Param  */
  YYSYMBOL_MainBlock = 74,                 /* MainBlock  */
  YYSYMBOL_LDeclBlock = 75,                /* LDeclBlock  */
  YYSYMBOL_LDecList = 76,                  /* LDecList  */
  YYSYMBOL_LDecl = 77,                     /* LDecl  */
  YYSYMBOL_IdList = 78,                    /* IdList  */
  YYSYMBOL_LId = 79,                       /* LId  */
  YYSYMBOL_Body = 80,                      /* Body  */
  YYSYMBOL_RetStmt = 81,                   /* RetStmt  */
  YYSYMBOL_Field = 82,                     /* Field  */
  YYSYMBOL_Slist = 83,                     /* Slist  */
  YYSYMBOL_Stmt = 84,                      /* Stmt  */
  YYSYMBOL_IfStmt = 85,                    /* IfStmt  */
  YYSYMBOL_WhileStmt = 86,                 /* WhileStmt  */
  YYSYMBOL_BrkStmt = 87,                   /* BrkStmt  */
  YYSYMBOL_ContStmt = 88,                  /* ContStmt  */
  YYSYMBOL_InputStmt = 89,                 /* InputStmt  */
  YYSYMBOL_OutputStmt = 90,                /* OutputStmt  */
  YYSYMBOL_AsgStmt = 91,                   /* AsgStmt  */
  YYSYMBOL_ExprList = 92,                  /* ExprList  */
  YYSYMBOL_expr = 93,                      /* expr  */
  YYSYMBOL_func = 94,                      /* func  */
  YYSYMBOL_id = 95                         /* id  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   422

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  114
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  239

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
      49,    50,     2,     2,    48,     2,    53,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    47,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    51,     2,    52,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    54,    54,    55,    56,    59,    60,    61,    64,    65,
      68,    71,    77,    78,    81,    90,    97,   104,   113,   114,
     117,   120,   121,   122,   135,   136,   137,   146,   147,   148,
     158,   159,   162,   169,   173,   183,   184,   187,   249,   250,
     251,   254,   260,   294,   295,   296,   299,   300,   303,   306,
     307,   310,   316,   317,   320,   330,   335,   340,   341,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   360,   367,
     370,   374,   380,   385,   388,   391,   398,   407,   410,   414,
     419,   426,   434,   439,   447,   456,   460,   461,   464,   468,
     472,   476,   480,   484,   488,   492,   496,   500,   504,   508,
     512,   516,   520,   524,   525,   529,   534,   538,   539,   540,
     543,   574,   578,   583,   587
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
  "NEQNILL", "FREE", "ALLOC", "INIT", "'{'", "'}'", "';'", "','", "'('",
  "')'", "'['", "']'", "'.'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "UserDefinedType", "FieldDeclList",
  "FieldDecl", "GDeclBlock", "GDeclList", "GDecl", "FieldType", "Type",
  "FType", "GIdList", "GId", "FDefBlock", "FDef", "ParamList", "Param",
  "MainBlock", "LDeclBlock", "LDecList", "LDecl", "IdList", "LId", "Body",
  "RetStmt", "Field", "Slist", "Stmt", "IfStmt", "WhileStmt", "BrkStmt",
  "ContStmt", "InputStmt", "OutputStmt", "AsgStmt", "ExprList", "expr",
  "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-122)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      43,    65,    -1,    21,   -28,   101,  -122,  -122,  -122,  -122,
      94,  -122,    18,  -122,  -122,     9,  -122,   -20,  -122,   101,
      13,  -122,  -122,  -122,   181,   115,  -122,  -122,  -122,   110,
       1,   101,  -122,  -122,    46,   185,    54,  -122,    18,  -122,
    -122,  -122,    -5,  -122,    95,    89,  -122,  -122,   102,  -122,
    -122,  -122,   133,     2,  -122,   130,  -122,  -122,  -122,   154,
     185,   157,  -122,   185,  -122,  -122,  -122,    66,   183,  -122,
     171,    97,   222,   183,  -122,   220,   152,  -122,   307,   191,
     222,  -122,   121,  -122,  -122,  -122,   198,   207,     0,   223,
     224,   232,   233,    32,   248,   257,   266,    -9,   307,  -122,
    -122,  -122,  -122,  -122,  -122,  -122,  -122,   234,   298,  -122,
     265,  -122,   220,   303,    32,   190,    32,   127,   306,    32,
      32,  -122,  -122,   314,  -122,   187,  -122,    32,    59,   235,
    -122,  -122,   316,   278,  -122,   192,   319,   333,  -122,  -122,
      32,  -122,  -122,   168,   -31,   291,    67,   293,   295,   241,
     221,   365,   296,    61,   301,  -122,    96,   164,  -122,  -122,
    -122,   170,  -122,  -122,    32,    32,    32,    32,    32,    32,
      32,    32,    32,    32,    32,  -122,    86,   162,   315,   317,
     312,   267,  -122,  -122,   276,   318,   321,   330,  -122,   292,
    -122,    32,  -122,  -122,  -122,  -122,   329,   343,  -122,   244,
     244,  -122,  -122,  -122,   200,   200,   390,   390,   390,   390,
     331,   332,  -122,  -122,   300,  -122,  -122,  -122,  -122,  -122,
     335,   365,   352,   352,  -122,  -122,   337,  -122,   290,   310,
    -122,   352,   339,   346,   341,  -122,  -122,   348,  -122
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       7,     0,     0,     0,    17,     0,    26,    16,    24,    25,
       0,    19,     0,    11,     6,     0,     9,     0,     1,     0,
       0,     4,    15,    18,    33,     0,    31,     5,     8,     0,
       0,     0,    36,     3,     0,    40,     0,    20,     0,    23,
      21,    22,     0,    13,     0,     0,    35,     2,     0,    29,
      27,    28,     0,     0,    39,     0,    30,    10,    12,     0,
      40,     0,    41,     0,    32,    34,    14,     0,    45,    38,
       0,     0,     0,    45,    44,     0,     0,    47,     0,     0,
       0,    51,     0,    50,    43,    46,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    58,
      62,    63,    64,    65,    59,    60,    61,     0,     0,    42,
       0,    48,     0,     0,     0,     0,    87,     0,     0,     0,
       0,    73,    74,     0,   104,   111,   106,     0,   109,     0,
     108,   107,     0,     0,    53,     0,     0,     0,    57,    66,
       0,    37,    49,   111,     0,     0,     0,     0,     0,     0,
       0,    86,   104,     0,   107,    55,     0,     0,   105,   101,
     102,     0,    99,   100,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    54,     0,     0,     0,     0,
       0,     0,    56,    52,     0,     0,     0,     0,    83,     0,
      79,     0,   110,   112,   114,   113,     0,     0,   103,    88,
      89,    90,    91,    92,    98,    97,    95,    96,    93,    94,
       0,     0,    69,    84,     0,    82,    78,    76,    75,    77,
       0,    85,     0,     0,    67,    68,     0,    81,     0,     0,
      80,     0,     0,     0,     0,    71,    72,     0,    70
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -122,  -122,  -122,  -122,   387,  -122,  -122,   361,   400,  -122,
     395,  -122,    11,   -38,  -122,   368,  -122,   376,   349,   345,
      -2,   338,  -122,   334,  -122,   308,   342,   320,   -78,  -121,
     -97,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -122,  -109,
     -64,   -74
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    15,    16,    17,    42,    43,     5,    10,
      11,    44,    12,    52,    25,    26,    31,    32,    53,    54,
      21,    72,    76,    77,    82,    83,    79,    96,   128,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   150,   129,
     130,   131
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      97,   138,     1,   135,   108,   146,   149,   151,   153,    39,
     156,   157,   115,    13,   107,    45,    20,    33,   161,   185,
      97,    18,   136,    13,   108,    29,   181,    40,    41,    47,
      30,   184,    24,    75,   107,   144,    34,    14,    75,   145,
     123,    57,    30,   154,   136,   124,   125,    27,    34,   116,
      63,   117,    64,   118,   177,   199,   200,   201,   202,   203,
     204,   205,   206,   207,   208,   209,   126,    55,   164,   165,
     166,   167,   168,     1,   164,   165,   166,   167,   168,     6,
       2,   127,   221,   169,   170,   171,   172,   173,   174,   169,
     170,   171,   172,   173,   174,    48,     7,     8,     9,   162,
     163,   228,   229,   164,   165,   166,   167,   168,     6,    59,
     234,    49,   136,   194,    63,     6,    70,   187,   169,   170,
     171,   172,   173,   174,    39,    22,     8,     9,    74,    50,
      51,   138,   138,     8,     9,   123,   210,   138,    60,   118,
     152,   125,    40,    41,    97,    97,   196,    62,   108,   108,
      97,    97,    61,    97,   108,   108,    97,   108,   107,   107,
     108,   126,    37,    38,   107,   107,    49,   107,   111,   112,
     107,   164,   165,   166,   167,   168,   127,   164,   165,   166,
     167,   168,    65,    84,    50,    51,   169,   170,   171,   172,
     173,   174,   169,   170,   171,   172,   173,   174,   123,    49,
     123,    66,    68,   124,   125,   124,   125,   164,   165,   166,
     167,   168,   211,    71,   197,   136,    73,    50,    51,   117,
     198,   118,   169,   170,   126,    78,   126,   159,   160,   147,
      35,   179,    36,   148,    81,   180,   116,   109,   117,   127,
     118,   127,   164,   165,   166,   167,   168,   113,   164,   165,
     166,   167,   168,   166,   167,   168,   114,   169,   170,   171,
     172,   173,   174,   169,   170,   171,   172,   173,   174,   191,
     134,   192,   119,   120,   164,   165,   166,   167,   168,   121,
     122,   139,   175,   164,   165,   166,   167,   168,   190,   169,
     170,   171,   172,   173,   174,    86,    87,   132,   169,   170,
     171,   172,   173,   174,    88,    89,   133,   231,   232,    90,
     140,   141,    86,    87,   215,    86,    87,   143,    91,    92,
     155,    88,    89,   216,    88,    89,    90,   158,   178,    90,
     176,   233,    94,   182,    95,    91,    92,   183,    91,    92,
     188,   186,   220,    93,   189,   222,    86,    87,   193,    94,
     226,    95,    94,   195,    95,    88,    89,    86,    87,   237,
      90,   214,   212,   223,   213,   217,    88,    89,   218,    91,
      92,    90,   164,   165,   166,   167,   168,   219,   224,   225,
      91,    92,   227,    94,   230,    95,   235,   169,   170,   171,
     172,   173,   174,   236,    94,   238,    95,   164,   165,   166,
     167,   168,    28,    58,    19,    23,    56,    46,    69,    67,
      85,    80,   169,   170,    -1,    -1,    -1,    -1,   137,     0,
     142,     0,   110
};

static const yytype_int16 yycheck[] =
{
      78,    98,    30,    12,    78,   114,   115,   116,   117,    14,
     119,   120,    12,    14,    78,    14,     5,    19,   127,    50,
      98,     0,    53,    14,    98,    45,   135,    32,    33,    31,
      19,   140,    14,    71,    98,   113,    35,    38,    76,   113,
       8,    46,    31,   117,    53,    13,    14,    38,    35,    49,
      48,    51,    50,    53,   132,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,    34,    13,     7,     8,
       9,    10,    11,    30,     7,     8,     9,    10,    11,    14,
      37,    49,   191,    22,    23,    24,    25,    26,    27,    22,
      23,    24,    25,    26,    27,    49,    31,    32,    33,    40,
      41,   222,   223,     7,     8,     9,    10,    11,    14,    14,
     231,    14,    53,    52,    48,    14,    50,    50,    22,    23,
      24,    25,    26,    27,    14,    31,    32,    33,    31,    32,
      33,   228,   229,    32,    33,     8,    50,   234,    49,    53,
      13,    14,    32,    33,   222,   223,    50,    14,   222,   223,
     228,   229,    50,   231,   228,   229,   234,   231,   222,   223,
     234,    34,    47,    48,   228,   229,    14,   231,    47,    48,
     234,     7,     8,     9,    10,    11,    49,     7,     8,     9,
      10,    11,    52,    31,    32,    33,    22,    23,    24,    25,
      26,    27,    22,    23,    24,    25,    26,    27,     8,    14,
       8,    47,    45,    13,    14,    13,    14,     7,     8,     9,
      10,    11,    50,    30,    50,    53,    45,    32,    33,    51,
      50,    53,    22,    23,    34,     3,    34,    40,    41,    39,
      49,    39,    51,    43,    14,    43,    49,    46,    51,    49,
      53,    49,     7,     8,     9,    10,    11,    49,     7,     8,
       9,    10,    11,     9,    10,    11,    49,    22,    23,    24,
      25,    26,    27,    22,    23,    24,    25,    26,    27,    48,
       4,    50,    49,    49,     7,     8,     9,    10,    11,    47,
      47,    47,    47,     7,     8,     9,    10,    11,    47,    22,
      23,    24,    25,    26,    27,     5,     6,    49,    22,    23,
      24,    25,    26,    27,    14,    15,    49,    17,    18,    19,
      12,    46,     5,     6,    47,     5,     6,    14,    28,    29,
      14,    14,    15,    47,    14,    15,    19,    13,    50,    19,
      14,    21,    42,    14,    44,    28,    29,     4,    28,    29,
      47,    50,    50,    36,    49,    16,     5,     6,    52,    42,
      50,    44,    42,    52,    44,    14,    15,     5,     6,    18,
      19,    49,    47,    20,    47,    47,    14,    15,    47,    28,
      29,    19,     7,     8,     9,    10,    11,    47,    47,    47,
      28,    29,    47,    42,    47,    44,    47,    22,    23,    24,
      25,    26,    27,    47,    42,    47,    44,     7,     8,     9,
      10,    11,    15,    42,     4,    10,    38,    31,    63,    60,
      76,    73,    22,    23,    24,    25,    26,    27,    98,    -1,
     112,    -1,    80
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    37,    55,    56,    62,    14,    31,    32,    33,
      63,    64,    66,    14,    38,    57,    58,    59,     0,    62,
      66,    74,    31,    64,    14,    68,    69,    38,    58,    45,
      66,    70,    71,    74,    35,    49,    51,    47,    48,    14,
      32,    33,    60,    61,    65,    14,    71,    74,    49,    14,
      32,    33,    67,    72,    73,    13,    69,    46,    61,    14,
      49,    50,    14,    48,    50,    52,    47,    72,    45,    73,
      50,    30,    75,    45,    31,    67,    76,    77,     3,    80,
      75,    14,    78,    79,    31,    77,     5,     6,    14,    15,
      19,    28,    29,    36,    42,    44,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    94,    95,    46,
      80,    47,    48,    49,    49,    12,    49,    51,    53,    49,
      49,    47,    47,     8,    13,    14,    34,    49,    82,    93,
      94,    95,    49,    49,     4,    12,    53,    81,    84,    47,
      12,    46,    79,    14,    82,    95,    93,    39,    43,    93,
      92,    93,    13,    93,    95,    14,    93,    93,    13,    40,
      41,    93,    40,    41,     7,     8,     9,    10,    11,    22,
      23,    24,    25,    26,    27,    47,    14,    82,    50,    39,
      43,    93,    14,     4,    93,    50,    50,    50,    47,    49,
      47,    48,    50,    52,    52,    52,    50,    50,    50,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      50,    50,    47,    47,    49,    47,    47,    47,    47,    47,
      50,    93,    16,    20,    47,    47,    50,    47,    83,    83,
      47,    17,    18,    21,    83,    47,    47,    18,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    55,    56,    56,    56,    57,    57,
      58,    59,    60,    60,    61,    62,    62,    62,    63,    63,
      64,    65,    65,    65,    66,    66,    66,    67,    67,    67,
      68,    68,    69,    69,    69,    70,    70,    71,    72,    72,
      72,    73,    74,    75,    75,    75,    76,    76,    77,    78,
      78,    79,    80,    80,    81,    82,    82,    83,    83,    84,
      84,    84,    84,    84,    84,    84,    84,    84,    84,    84,
      85,    85,    86,    87,    88,    89,    89,    90,    91,    91,
      91,    91,    91,    91,    91,    92,    92,    92,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      94,    95,    95,    95,    95
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     3,     2,     3,     2,     0,     2,     1,
       4,     1,     2,     1,     3,     3,     2,     0,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     1,     4,     2,     1,     9,     3,     1,
       0,     2,     8,     3,     2,     0,     2,     1,     3,     3,
       1,     1,     4,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     5,     5,     4,
      10,     8,     8,     2,     2,     5,     5,     5,     4,     4,
       6,     6,     4,     4,     4,     3,     1,     0,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     2,     3,     1,     2,     1,     1,     1,     1,
       4,     1,     4,     4,     4
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
  case 2: /* program: TypeDefBlock GDeclBlock FDefBlock MainBlock  */
#line 54 "exprtree.y"
                                                     {fclose(intermediate);}
#line 1510 "y.tab.c"
    break;

  case 3: /* program: TypeDefBlock GDeclBlock MainBlock  */
#line 55 "exprtree.y"
                                                     {fclose(intermediate);}
#line 1516 "y.tab.c"
    break;

  case 4: /* program: GDeclBlock MainBlock  */
#line 56 "exprtree.y"
                                                                         {fclose(intermediate);}
#line 1522 "y.tab.c"
    break;

  case 10: /* TypeDef: UserDefinedType '{' FieldDeclList '}'  */
#line 68 "exprtree.y"
                                                { TInstall((yyvsp[-3].nptr)->name, Fhead); }
#line 1528 "y.tab.c"
    break;

  case 11: /* UserDefinedType: ID  */
#line 71 "exprtree.y"
                    {
                        tempASTNode = (yyvsp[0].nptr);
                        (yyval.nptr) = (yyvsp[0].nptr);
                    }
#line 1537 "y.tab.c"
    break;

  case 14: /* FieldDecl: FieldType ID ';'  */
#line 81 "exprtree.y"
                            {
                                if(FLookup((yyvsp[-1].nptr)->name, Fhead) != NULL) {
                                    yyerror("Re-declaration of Field element %s\n", (yyvsp[-1].nptr)->name);
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].nptr)->name, declarationType);
                            }
#line 1549 "y.tab.c"
    break;

  case 15: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 90 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1561 "y.tab.c"
    break;

  case 16: /* GDeclBlock: DECL ENDDECL  */
#line 97 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1573 "y.tab.c"
    break;

  case 17: /* GDeclBlock: %empty  */
#line 104 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1585 "y.tab.c"
    break;

  case 21: /* FieldType: INT  */
#line 120 "exprtree.y"
                {declarationType = TLookup("integer");}
#line 1591 "y.tab.c"
    break;

  case 22: /* FieldType: STR  */
#line 121 "exprtree.y"
                {declarationType = TLookup("string");}
#line 1597 "y.tab.c"
    break;

  case 23: /* FieldType: ID  */
#line 122 "exprtree.y"
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
#line 1613 "y.tab.c"
    break;

  case 24: /* Type: INT  */
#line 135 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1619 "y.tab.c"
    break;

  case 25: /* Type: STR  */
#line 136 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1625 "y.tab.c"
    break;

  case 26: /* Type: ID  */
#line 137 "exprtree.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL) {
                    yyerror("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1637 "y.tab.c"
    break;

  case 27: /* FType: INT  */
#line 146 "exprtree.y"
            {FDeclarationType = TLookup("integer");}
#line 1643 "y.tab.c"
    break;

  case 28: /* FType: STR  */
#line 147 "exprtree.y"
            {FDeclarationType = TLookup("string");}
#line 1649 "y.tab.c"
    break;

  case 29: /* FType: ID  */
#line 148 "exprtree.y"
            {
                FDeclarationType = TLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL) {
                    yyerror("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1661 "y.tab.c"
    break;

  case 32: /* GId: ID '(' ParamList ')'  */
#line 162 "exprtree.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1673 "y.tab.c"
    break;

  case 33: /* GId: ID  */
#line 169 "exprtree.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType, 1, NULL);
                            }
#line 1682 "y.tab.c"
    break;

  case 34: /* GId: ID '[' NUM ']'  */
#line 173 "exprtree.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) {
                                    yyerror("Invalid array size", NULL);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1695 "y.tab.c"
    break;

  case 37: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 187 "exprtree.y"
                                                        {
                                                            defCount++;
                                                            Gtemp = GLookup((yyvsp[-7].nptr)->name);

                                                            if(Gtemp == NULL) {
                                                                yyerror("Function %s not declared", (yyvsp[-7].nptr)->name);
                                                                exit(1);
                                                            }

                                                            if(Gtemp->type != declarationType) {
                                                               yyerror("%s : Function type does not match declaration", (yyvsp[-7].nptr)->name);
                                                               exit(1);
                                                            }

                                                            argList1 = Phead;
                                                            argList2 = Gtemp->paramlist;

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
                                                                fprintf(intermediate, "F%d:\n",Gtemp->flabel);
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
#line 1760 "y.tab.c"
    break;

  case 41: /* Param: FType ID  */
#line 254 "exprtree.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1769 "y.tab.c"
    break;

  case 42: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 260 "exprtree.y"
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
#line 1806 "y.tab.c"
    break;

  case 43: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 294 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1812 "y.tab.c"
    break;

  case 44: /* LDeclBlock: DECL ENDDECL  */
#line 295 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1818 "y.tab.c"
    break;

  case 45: /* LDeclBlock: %empty  */
#line 296 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1824 "y.tab.c"
    break;

  case 51: /* LId: ID  */
#line 310 "exprtree.y"
        {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
        }
#line 1833 "y.tab.c"
    break;

  case 52: /* Body: START Slist RetStmt END  */
#line 316 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 1839 "y.tab.c"
    break;

  case 53: /* Body: START RetStmt END  */
#line 317 "exprtree.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1845 "y.tab.c"
    break;

  case 54: /* RetStmt: RETURN expr ';'  */
#line 320 "exprtree.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 1858 "y.tab.c"
    break;

  case 55: /* Field: ID '.' ID  */
#line 330 "exprtree.y"
                        {
                            assignType((yyvsp[-2].nptr), 0);
                            assignTypeField((yyvsp[0].nptr), (yyvsp[-2].nptr)->type->fields);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_FIELD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 1868 "y.tab.c"
    break;

  case 56: /* Field: Field '.' ID  */
#line 335 "exprtree.y"
                        {
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 1876 "y.tab.c"
    break;

  case 57: /* Slist: Slist Stmt  */
#line 340 "exprtree.y"
                        {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 1882 "y.tab.c"
    break;

  case 58: /* Slist: Stmt  */
#line 341 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1888 "y.tab.c"
    break;

  case 59: /* Stmt: InputStmt  */
#line 344 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1894 "y.tab.c"
    break;

  case 60: /* Stmt: OutputStmt  */
#line 345 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1900 "y.tab.c"
    break;

  case 61: /* Stmt: AsgStmt  */
#line 346 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1906 "y.tab.c"
    break;

  case 62: /* Stmt: IfStmt  */
#line 347 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1912 "y.tab.c"
    break;

  case 63: /* Stmt: WhileStmt  */
#line 348 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1918 "y.tab.c"
    break;

  case 64: /* Stmt: BrkStmt  */
#line 349 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1924 "y.tab.c"
    break;

  case 65: /* Stmt: ContStmt  */
#line 350 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 1930 "y.tab.c"
    break;

  case 66: /* Stmt: func ';'  */
#line 351 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 1936 "y.tab.c"
    break;

  case 67: /* Stmt: FREE '(' ID ')' ';'  */
#line 352 "exprtree.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 1949 "y.tab.c"
    break;

  case 68: /* Stmt: FREE '(' Field ')' ';'  */
#line 360 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 1961 "y.tab.c"
    break;

  case 69: /* Stmt: INIT '(' ')' ';'  */
#line 367 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 1967 "y.tab.c"
    break;

  case 70: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 370 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TLookup("boolean"), 'e');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 1976 "y.tab.c"
    break;

  case 71: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 374 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'i');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1985 "y.tab.c"
    break;

  case 72: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 380 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'w');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 1994 "y.tab.c"
    break;

  case 73: /* BrkStmt: BREAK ';'  */
#line 385 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2000 "y.tab.c"
    break;

  case 74: /* ContStmt: CONT ';'  */
#line 388 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2006 "y.tab.c"
    break;

  case 75: /* InputStmt: READ '(' id ')' ';'  */
#line 391 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2018 "y.tab.c"
    break;

  case 76: /* InputStmt: READ '(' Field ')' ';'  */
#line 398 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2030 "y.tab.c"
    break;

  case 77: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 407 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2036 "y.tab.c"
    break;

  case 78: /* AsgStmt: id ASSGN expr ';'  */
#line 410 "exprtree.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2045 "y.tab.c"
    break;

  case 79: /* AsgStmt: ID ASSGN expr ';'  */
#line 414 "exprtree.y"
                                    {
                                        assignType((yyvsp[-3].nptr), 0);
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2055 "y.tab.c"
    break;

  case 80: /* AsgStmt: Field ASSGN ALLOC '(' ')' ';'  */
#line 419 "exprtree.y"
                                        {
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2067 "y.tab.c"
    break;

  case 81: /* AsgStmt: ID ASSGN ALLOC '(' ')' ';'  */
#line 426 "exprtree.y"
                                        {
                                            assignType((yyvsp[-5].nptr), 0);
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2080 "y.tab.c"
    break;

  case 82: /* AsgStmt: Field ASSGN expr ';'  */
#line 434 "exprtree.y"
                                        {
                                            typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                    
                                        }
#line 2090 "y.tab.c"
    break;

  case 83: /* AsgStmt: ID ASSGN NILL ';'  */
#line 439 "exprtree.y"
                                        {
                                            assignType((yyvsp[-3].nptr), 0);
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2103 "y.tab.c"
    break;

  case 84: /* AsgStmt: Field ASSGN NILL ';'  */
#line 447 "exprtree.y"
                                        {
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2115 "y.tab.c"
    break;

  case 85: /* ExprList: ExprList ',' expr  */
#line 456 "exprtree.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2124 "y.tab.c"
    break;

  case 86: /* ExprList: expr  */
#line 460 "exprtree.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2130 "y.tab.c"
    break;

  case 87: /* ExprList: %empty  */
#line 461 "exprtree.y"
                            {(yyval.nptr) = NULL;}
#line 2136 "y.tab.c"
    break;

  case 88: /* expr: expr PLUS expr  */
#line 464 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2145 "y.tab.c"
    break;

  case 89: /* expr: expr MINUS expr  */
#line 468 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2154 "y.tab.c"
    break;

  case 90: /* expr: expr MUL expr  */
#line 472 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2163 "y.tab.c"
    break;

  case 91: /* expr: expr DIV expr  */
#line 476 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2172 "y.tab.c"
    break;

  case 92: /* expr: expr MOD expr  */
#line 480 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2181 "y.tab.c"
    break;

  case 93: /* expr: expr LT expr  */
#line 484 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2190 "y.tab.c"
    break;

  case 94: /* expr: expr GT expr  */
#line 488 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2199 "y.tab.c"
    break;

  case 95: /* expr: expr LE expr  */
#line 492 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2208 "y.tab.c"
    break;

  case 96: /* expr: expr GE expr  */
#line 496 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2217 "y.tab.c"
    break;

  case 97: /* expr: expr NEQ expr  */
#line 500 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2226 "y.tab.c"
    break;

  case 98: /* expr: expr EQ expr  */
#line 504 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2235 "y.tab.c"
    break;

  case 99: /* expr: Field DEQNILL  */
#line 508 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2244 "y.tab.c"
    break;

  case 100: /* expr: Field NEQNILL  */
#line 512 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2253 "y.tab.c"
    break;

  case 101: /* expr: ID DEQNILL  */
#line 516 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2262 "y.tab.c"
    break;

  case 102: /* expr: ID NEQNILL  */
#line 520 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2271 "y.tab.c"
    break;

  case 103: /* expr: '(' expr ')'  */
#line 524 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2277 "y.tab.c"
    break;

  case 104: /* expr: NUM  */
#line 525 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2286 "y.tab.c"
    break;

  case 105: /* expr: MINUS NUM  */
#line 529 "exprtree.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2296 "y.tab.c"
    break;

  case 106: /* expr: STRVAL  */
#line 534 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("string");
                        }
#line 2305 "y.tab.c"
    break;

  case 107: /* expr: id  */
#line 538 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2311 "y.tab.c"
    break;

  case 108: /* expr: func  */
#line 539 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2317 "y.tab.c"
    break;

  case 109: /* expr: Field  */
#line 540 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2323 "y.tab.c"
    break;

  case 110: /* func: ID '(' ExprList ')'  */
#line 543 "exprtree.y"
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
#line 2358 "y.tab.c"
    break;

  case 111: /* id: ID  */
#line 574 "exprtree.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2367 "y.tab.c"
    break;

  case 112: /* id: ID '[' NUM ']'  */
#line 578 "exprtree.y"
                        {
                            (yyvsp[-1].nptr)->type = TLookup("integer");
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2377 "y.tab.c"
    break;

  case 113: /* id: ID '[' id ']'  */
#line 583 "exprtree.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2386 "y.tab.c"
    break;

  case 114: /* id: ID '[' expr ']'  */
#line 588 "exprtree.y"
    {
        if((yyvsp[-1].nptr)->type!=TLookup("integer"))
        {
        	fprintf(stderr,"Expected an arithmetic expression in the index for array %s\n",(yyvsp[-3].nptr)->name);
        	exit(1);
        }
        assignType((yyvsp[-3].nptr), 2);
        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
       }
#line 2400 "y.tab.c"
    break;


#line 2404 "y.tab.c"

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

#line 599 "exprtree.y"


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

