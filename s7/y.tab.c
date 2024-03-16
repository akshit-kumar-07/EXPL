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
        #include "typetable.h"
        #include "typetable.c"
        #include "classtable.h"
        #include "classtable.c"
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
	    int testing = 1;
	    struct ASTNode *tempASTNode;

#line 100 "y.tab.c"

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
    AND = 283,                     /* AND  */
    OR = 284,                      /* OR  */
    BREAK = 285,                   /* BREAK  */
    CONT = 286,                    /* CONT  */
    DECL = 287,                    /* DECL  */
    ENDDECL = 288,                 /* ENDDECL  */
    INT = 289,                     /* INT  */
    STR = 290,                     /* STR  */
    STRVAL = 291,                  /* STRVAL  */
    MAIN = 292,                    /* MAIN  */
    RETURN = 293,                  /* RETURN  */
    TYPE = 294,                    /* TYPE  */
    ENDTYPE = 295,                 /* ENDTYPE  */
    NILL = 296,                    /* NILL  */
    DEQNILL = 297,                 /* DEQNILL  */
    NEQNILL = 298,                 /* NEQNILL  */
    FREE = 299,                    /* FREE  */
    ALLOC = 300,                   /* ALLOC  */
    INIT = 301,                    /* INIT  */
    SELF = 302,                    /* SELF  */
    CLASS = 303,                   /* CLASS  */
    ENDCLASS = 304,                /* ENDCLASS  */
    NEW = 305,                     /* NEW  */
    DELETE = 306,                  /* DELETE  */
    BREAKPOINT = 307               /* BREAKPOINT  */
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
#define AND 283
#define OR 284
#define BREAK 285
#define CONT 286
#define DECL 287
#define ENDDECL 288
#define INT 289
#define STR 290
#define STRVAL 291
#define MAIN 292
#define RETURN 293
#define TYPE 294
#define ENDTYPE 295
#define NILL 296
#define DEQNILL 297
#define NEQNILL 298
#define FREE 299
#define ALLOC 300
#define INIT 301
#define SELF 302
#define CLASS 303
#define ENDCLASS 304
#define NEW 305
#define DELETE 306
#define BREAKPOINT 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 31 "exprtree.y"

    struct ASTNode *nptr;

#line 261 "y.tab.c"

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
  YYSYMBOL_SELF = 47,                      /* SELF  */
  YYSYMBOL_CLASS = 48,                     /* CLASS  */
  YYSYMBOL_ENDCLASS = 49,                  /* ENDCLASS  */
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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   509

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  62
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  136
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
       0,    64,    64,    65,    66,    69,    70,    71,    74,    75,
      78,    81,    87,    88,    91,   100,   101,   104,   105,   108,
     122,   125,   126,   129,   135,   144,   145,   149,   157,   165,
     175,   176,   179,   182,   183,   184,   201,   202,   203,   226,
     227,   228,   238,   239,   242,   249,   253,   263,   264,   267,
     366,   367,   368,   371,   377,   415,   416,   417,   420,   421,
     424,   427,   428,   431,   437,   438,   441,   451,   456,   459,
     472,   488,   502,   516,   517,   520,   521,   522,   523,   524,
     525,   526,   527,   528,   529,   530,   538,   545,   546,   554,
     563,   567,   573,   578,   581,   584,   591,   600,   603,   607,
     612,   619,   627,   635,   642,   647,   655,   664,   668,   669,
     672,   676,   680,   684,   688,   692,   696,   700,   704,   708,
     712,   716,   720,   724,   728,   732,   733,   737,   742,   746,
     747,   748,   751,   782,   786,   791,   795
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
  "DEQNILL", "NEQNILL", "FREE", "ALLOC", "INIT", "SELF", "CLASS",
  "ENDCLASS", "NEW", "DELETE", "BREAKPOINT", "'{'", "'}'", "';'", "'('",
  "')'", "','", "'['", "']'", "'.'", "$accept", "program", "TypeDefBlock",
  "TypeDefList", "TypeDef", "UserDefinedType", "FieldDeclList",
  "FieldDecl", "ClassDefBlock", "ClassDefList", "ClassDef", "Cname",
  "ClassFieldDeclList", "ClassFieldDecl", "ClassMethodDefns", "GDeclBlock",
  "GDeclList", "GDecl", "FieldType", "Type", "LType", "GIdList", "GId",
  "FDefBlock", "FDef", "ParamList", "Param", "MainBlock", "LDeclBlock",
  "LDecList", "LDecl", "IdList", "LId", "Body", "RetStmt", "Field",
  "FieldFunction", "Slist", "Stmt", "IfStmt", "WhileStmt", "BrkStmt",
  "ContStmt", "InputStmt", "OutputStmt", "AsgStmt", "ExprList", "expr",
  "func", "id", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-140)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  ((Yyn) == YYTABLE_NINF)

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -24,   111,    69,    17,   -21,    52,  -140,  -140,  -140,  -140,
     213,  -140,    58,  -140,  -140,    70,  -140,   -30,  -140,  -140,
      45,    52,    53,  -140,  -140,  -140,   194,    23,  -140,  -140,
    -140,   296,   -10,    52,  -140,    56,   313,   128,  -140,    58,
    -140,  -140,  -140,   104,  -140,   121,  -140,  -140,  -140,   134,
     145,    52,  -140,   107,  -140,  -140,  -140,   167,    91,  -140,
     144,  -140,  -140,  -140,   156,   186,   223,    74,  -140,  -140,
     234,  -140,  -140,   313,  -140,  -140,  -140,   313,   294,  -140,
     231,   116,   235,   302,  -140,  -140,   321,   286,  -140,   327,
     238,  -140,   340,   288,   126,   247,   294,  -140,   196,  -140,
    -140,  -140,   295,   300,    -3,   305,   309,   289,   307,     5,
     312,   318,   299,   319,   314,   372,    -2,   326,   340,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -140,   335,   370,  -140,
    -140,  -140,  -140,   313,   302,  -140,   327,    20,     5,    35,
       5,     8,   379,     5,     5,  -140,  -140,   381,  -140,   324,
    -140,   334,     5,   243,   212,  -140,  -140,    22,   339,   383,
      26,  -140,  -140,   293,   386,  -140,   397,  -140,  -140,     5,
     204,   349,  -140,   165,   -32,   356,   106,   351,   359,   362,
     233,   251,   424,   354,    97,   360,   363,   143,   168,  -140,
    -140,  -140,   407,   408,   206,  -140,  -140,   413,     5,     5,
       5,     5,     5,     5,     5,     5,     5,     5,     5,  -140,
      13,    18,   373,   380,    86,   149,   374,   382,   387,   267,
     396,  -140,   273,   398,  -140,   399,   401,   404,  -140,   403,
     447,  -140,  -140,     5,  -140,  -140,  -140,     5,   453,   455,
    -140,  -140,  -140,  -140,   304,   304,  -140,  -140,  -140,   463,
     463,   457,   457,   457,   457,   421,   422,  -140,     5,   423,
     432,  -140,   431,   475,  -140,     5,  -140,  -140,  -140,  -140,
    -140,   435,   434,   424,   259,   411,   411,  -140,  -140,   261,
    -140,  -140,   437,   436,   275,  -140,   439,  -140,   306,   358,
    -140,  -140,   440,  -140,  -140,   411,   441,   442,  -140,   393,
    -140,  -140,   443,  -140
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       7,     0,     0,     0,    16,     0,    38,    28,    36,    37,
       0,    31,     0,    11,     6,     0,     9,     0,     1,    18,
      29,     0,     0,     4,    27,    30,    45,     0,    43,     5,
       8,     0,     0,     0,     3,     0,    52,     0,    32,     0,
      35,    33,    34,     0,    13,     0,    20,    15,    17,     0,
       0,     0,    48,     0,    41,    39,    40,     0,     0,    51,
       0,    42,    10,    12,     0,     0,     0,     0,    47,     2,
       0,    53,    44,     0,    46,    14,    22,    52,    57,    50,
       0,     0,     0,     0,    26,    21,     0,     0,    56,     0,
       0,    59,     0,     0,     0,     0,    57,    63,     0,    62,
      55,    58,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    74,
      78,    79,    80,    81,    75,    76,    77,     0,     0,    54,
      19,    25,    23,    52,     0,    60,     0,     0,     0,     0,
     109,     0,     0,     0,     0,    93,    94,     0,   126,   133,
     128,     0,     0,   131,     0,   130,   129,     0,     0,     0,
       0,    84,    65,     0,     0,    83,     0,    73,    82,     0,
       0,     0,    61,   133,     0,     0,     0,     0,     0,     0,
       0,     0,   108,   126,     0,   129,    67,     0,     0,   127,
     123,   124,     0,     0,     0,   121,   122,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    66,
       0,     0,     0,    69,     0,     0,     0,     0,     0,     0,
      68,    64,     0,     0,    49,     0,     0,     0,   105,     0,
       0,    99,   132,     0,   134,   136,   135,   109,     0,     0,
      67,    69,   125,    68,   110,   111,   112,   113,   114,   120,
     119,   117,   118,   115,   116,     0,     0,    87,   109,     0,
       0,   106,     0,     0,   104,   109,    98,    24,    96,    95,
      97,     0,     0,   107,     0,     0,     0,    85,    86,     0,
      88,    89,     0,     0,     0,   101,     0,    71,     0,     0,
      70,   100,     0,    72,   102,     0,     0,     0,   103,     0,
      91,    92,     0,    90
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -140,  -140,  -140,  -140,   484,  -140,  -140,   458,  -140,  -140,
    -140,  -140,  -140,  -140,  -140,   122,  -140,   490,  -140,     9,
     -70,  -140,   464,  -140,   -44,   -71,   429,     3,   409,  -140,
     414,  -140,   371,   375,   388,   -92,  -140,  -139,  -117,  -140,
    -140,  -140,  -140,  -140,  -140,  -140,  -103,  -106,   -87,   -90
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,     4,    15,    16,    17,    43,    44,    20,    32,
      48,    49,    80,    85,    94,     5,    10,    11,    45,    12,
      57,    27,    28,    51,    52,    58,    59,    23,    83,    90,
      91,    98,    99,    93,   115,   153,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   181,   182,   155,   156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     116,   167,   128,   154,    46,   127,    81,    68,     1,   139,
     163,     1,    89,   147,    22,     2,   147,    18,   148,   149,
      89,   183,   149,    31,    34,   225,   116,    19,   128,   197,
      22,   127,   176,   180,   173,   184,   210,   187,   188,    47,
     214,   150,    50,   147,   150,   174,   194,   175,   148,   149,
     131,   185,   151,   140,    69,   151,   141,   219,   142,   164,
      67,   152,   170,   222,   152,   211,     6,   151,   215,   151,
     255,   150,    26,   151,   192,   256,   177,     1,    38,   197,
     178,    39,   151,    13,    13,   179,     8,     9,    66,    86,
      35,   152,   244,   245,   246,   247,   248,   249,   250,   251,
     252,   253,   254,    50,   198,   199,   200,   201,   202,    14,
      29,    35,    53,   198,   199,   200,   201,   202,    40,   203,
     204,   205,   206,   207,   208,     6,    21,   273,   203,   204,
     205,   206,   207,   208,   274,    64,   288,   289,    41,    42,
       6,    60,    33,   259,     7,     8,     9,   192,    72,    73,
     198,   199,   200,   201,   202,   279,   299,   235,    62,    66,
       8,     9,   284,   227,    70,   203,   204,   205,   206,   207,
     208,   167,   167,    87,    73,   198,   199,   200,   201,   202,
     130,    71,   167,   116,   116,   128,   128,    65,   127,   127,
     203,   204,   205,   206,   207,   208,   116,   116,   128,   128,
     238,   127,   127,   116,    74,   128,   260,   116,   127,   128,
     197,    75,   127,   198,   199,   200,   201,   202,    76,   198,
     199,   200,   201,   202,   141,   239,   192,     6,   203,   204,
     205,   206,   207,   208,   203,   204,   205,   206,   207,   208,
     198,   199,   200,   201,   202,     6,    24,     8,     9,    54,
      36,   135,    54,    37,   136,   203,   204,   205,   206,   207,
     208,   223,    73,   242,    84,     8,     9,   209,    88,    55,
      56,   100,    55,    56,   198,   199,   200,   201,   202,    77,
     198,   199,   200,   201,   202,   195,   196,    78,   231,   203,
     204,   205,   206,   207,   208,   203,   204,   205,   206,   207,
     208,   147,   132,   133,   197,    92,   148,   149,   232,   233,
      40,   102,   103,   200,   201,   202,   287,   233,   290,   233,
     104,   105,   264,   295,   296,   106,    82,    54,   266,   150,
      41,    42,   293,   233,   216,    95,   107,   108,   217,    96,
     151,    97,   129,   218,   145,   102,   103,    55,    56,   152,
     110,   137,   111,   112,   104,   105,   138,   113,   114,   106,
     159,   143,   146,   102,   103,   144,   190,   191,   157,   161,
     107,   108,   104,   105,   158,   160,   162,   106,   109,   297,
     140,   165,   169,   141,   110,   192,   111,   112,   107,   108,
     168,   113,   114,   186,   189,   193,   212,   213,   102,   103,
     220,   221,   110,   224,   111,   112,   228,   104,   105,   113,
     114,   302,   106,   226,   234,   229,   102,   103,   230,   237,
     236,   240,   241,   107,   108,   104,   105,   243,   257,   261,
     106,   198,   199,   200,   201,   202,   258,   110,   262,   111,
     112,   107,   108,   263,   113,   114,   203,   204,   205,   206,
     207,   208,   265,   267,   268,   110,   269,   111,   112,   270,
     271,   272,   113,   114,   198,   199,   200,   201,   202,   275,
     198,   199,   200,   201,   202,   276,   277,   278,   280,   203,
     204,    -1,    -1,    -1,    -1,   203,   204,   281,   282,   283,
     285,   286,   291,   292,   294,   298,   300,   301,   303,    30,
      25,    63,    79,    61,   101,   134,   166,   172,     0,   171
};

static const yytype_int16 yycheck[] =
{
      92,   118,    92,   109,    14,    92,    77,    51,    32,    12,
      12,    32,    82,     8,     5,    39,     8,     0,    13,    14,
      90,    13,    14,    53,    21,    57,   118,    48,   118,    61,
      21,   118,   138,   139,    14,   141,    14,   143,   144,    49,
      14,    36,    33,     8,    36,   137,   152,   137,    13,    14,
      94,   141,    47,    56,    51,    47,    59,   163,    61,    61,
      51,    56,   133,   169,    56,   157,    14,    47,   160,    47,
      57,    36,    14,    47,    61,    57,    41,    32,    55,    61,
      45,    58,    47,    14,    14,    50,    34,    35,    14,    80,
      37,    56,   198,   199,   200,   201,   202,   203,   204,   205,
     206,   207,   208,    94,     7,     8,     9,    10,    11,    40,
      40,    37,    56,     7,     8,     9,    10,    11,    14,    22,
      23,    24,    25,    26,    27,    14,     4,   233,    22,    23,
      24,    25,    26,    27,   237,    14,   275,   276,    34,    35,
      14,    13,    20,    57,    33,    34,    35,    61,    57,    58,
       7,     8,     9,    10,    11,   258,   295,    60,    54,    14,
      34,    35,   265,    57,    57,    22,    23,    24,    25,    26,
      27,   288,   289,    57,    58,     7,     8,     9,    10,    11,
      54,    14,   299,   275,   276,   275,   276,    53,   275,   276,
      22,    23,    24,    25,    26,    27,   288,   289,   288,   289,
      57,   288,   289,   295,    60,   295,    57,   299,   295,   299,
      61,    55,   299,     7,     8,     9,    10,    11,    32,     7,
       8,     9,    10,    11,    59,    57,    61,    14,    22,    23,
      24,    25,    26,    27,    22,    23,    24,    25,    26,    27,
       7,     8,     9,    10,    11,    14,    33,    34,    35,    14,
      56,    55,    14,    59,    58,    22,    23,    24,    25,    26,
      27,    57,    58,    57,    33,    34,    35,    55,    33,    34,
      35,    33,    34,    35,     7,     8,     9,    10,    11,    56,
       7,     8,     9,    10,    11,    42,    43,    53,    55,    22,
      23,    24,    25,    26,    27,    22,    23,    24,    25,    26,
      27,     8,    55,    56,    61,     3,    13,    14,    57,    58,
      14,     5,     6,     9,    10,    11,    57,    58,    57,    58,
      14,    15,    55,    17,    18,    19,    32,    14,    55,    36,
      34,    35,    57,    58,    41,    14,    30,    31,    45,    53,
      47,    14,    54,    50,    55,     5,     6,    34,    35,    56,
      44,    56,    46,    47,    14,    15,    56,    51,    52,    19,
      61,    56,    55,     5,     6,    56,    42,    43,    56,    55,
      30,    31,    14,    15,    56,    56,     4,    19,    38,    21,
      56,    55,    12,    59,    44,    61,    46,    47,    30,    31,
      55,    51,    52,    14,    13,    61,    57,    14,     5,     6,
      14,     4,    44,    54,    46,    47,    55,    14,    15,    51,
      52,    18,    19,    57,    60,    56,     5,     6,    56,    56,
      60,    14,    14,    30,    31,    14,    15,    14,    55,    55,
      19,     7,     8,     9,    10,    11,    56,    44,    56,    46,
      47,    30,    31,    56,    51,    52,    22,    23,    24,    25,
      26,    27,    56,    55,    55,    44,    55,    46,    47,    55,
      57,    14,    51,    52,     7,     8,     9,    10,    11,    16,
       7,     8,     9,    10,    11,    20,    55,    55,    55,    22,
      23,    24,    25,    26,    27,    22,    23,    55,    57,    14,
      55,    57,    55,    57,    55,    55,    55,    55,    55,    15,
      10,    43,    73,    39,    90,    96,   118,   136,    -1,   134
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    39,    63,    64,    77,    14,    33,    34,    35,
      78,    79,    81,    14,    40,    65,    66,    67,     0,    48,
      70,    77,    81,    89,    33,    79,    14,    83,    84,    40,
      66,    53,    71,    77,    89,    37,    56,    59,    55,    58,
      14,    34,    35,    68,    69,    80,    14,    49,    72,    73,
      81,    85,    86,    56,    14,    34,    35,    82,    87,    88,
      13,    84,    54,    69,    14,    53,    14,    81,    86,    89,
      57,    14,    57,    58,    60,    55,    32,    56,    53,    88,
      74,    87,    32,    90,    33,    75,    81,    57,    33,    82,
      91,    92,     3,    95,    76,    14,    53,    14,    93,    94,
      33,    92,     5,     6,    14,    15,    19,    30,    31,    38,
      44,    46,    47,    51,    52,    96,    97,    98,    99,   100,
     101,   102,   103,   104,   105,   106,   107,   110,   111,    54,
      54,    86,    55,    56,    90,    55,    58,    56,    56,    12,
      56,    59,    61,    56,    56,    55,    55,     8,    13,    14,
      36,    47,    56,    97,   109,   110,   111,    56,    56,    61,
      56,    55,     4,    12,    61,    55,    96,   100,    55,    12,
      87,    95,    94,    14,    97,   111,   109,    41,    45,    50,
     109,   108,   109,    13,   109,   111,    14,   109,   109,    13,
      42,    43,    61,    61,   109,    42,    43,    61,     7,     8,
       9,    10,    11,    22,    23,    24,    25,    26,    27,    55,
      14,    97,    57,    14,    14,    97,    41,    45,    50,   109,
      14,     4,   109,    57,    54,    57,    57,    57,    55,    56,
      56,    55,    57,    58,    60,    60,    60,    56,    57,    57,
      14,    14,    57,    14,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,    57,    57,    55,    56,    57,
      57,    55,    56,    56,    55,    56,    55,    55,    55,    55,
      55,    57,    14,   109,   108,    16,    20,    55,    55,   108,
      55,    55,    57,    14,   108,    55,    57,    57,    99,    99,
      57,    55,    57,    57,    55,    17,    18,    21,    55,    99,
      55,    55,    18,    55
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    62,    63,    63,    63,    64,    64,    64,    65,    65,
      66,    67,    68,    68,    69,    70,    70,    71,    71,    72,
      73,    74,    74,    75,    75,    76,    76,    77,    77,    77,
      78,    78,    79,    80,    80,    80,    81,    81,    81,    82,
      82,    82,    83,    83,    84,    84,    84,    85,    85,    86,
      87,    87,    87,    88,    89,    90,    90,    90,    91,    91,
      92,    93,    93,    94,    95,    95,    96,    97,    97,    97,
      98,    98,    98,    99,    99,   100,   100,   100,   100,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   102,   103,   104,   105,   105,   106,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   109,   109,   109,
     109,   109,   110,   111,   111,   111,   111
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     2,     3,     2,     0,     2,     1,
       4,     1,     2,     1,     3,     3,     0,     2,     0,     7,
       1,     2,     0,     3,     6,     2,     0,     3,     2,     0,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     4,     1,     4,     2,     1,     9,
       3,     1,     0,     2,     8,     3,     2,     0,     2,     1,
       3,     3,     1,     1,     4,     3,     3,     3,     3,     3,
       6,     6,     6,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     5,     5,     4,     5,     5,
      10,     8,     8,     2,     2,     5,     5,     5,     4,     4,
       6,     6,     7,     7,     4,     4,     4,     3,     1,     0,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     2,     2,     3,     1,     2,     1,     1,
       1,     1,     4,     1,     4,     4,     4
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
#line 1594 "y.tab.c"
    break;

  case 3: /* program: TypeDefBlock GDeclBlock MainBlock  */
#line 65 "exprtree.y"
                                                     {fclose(intermediate);}
#line 1600 "y.tab.c"
    break;

  case 4: /* program: GDeclBlock MainBlock  */
#line 66 "exprtree.y"
                                                                         {fclose(intermediate);}
#line 1606 "y.tab.c"
    break;

  case 10: /* TypeDef: UserDefinedType '{' FieldDeclList '}'  */
#line 78 "exprtree.y"
                                                { TInstall((yyvsp[-3].nptr)->name, Fhead); }
#line 1612 "y.tab.c"
    break;

  case 11: /* UserDefinedType: ID  */
#line 81 "exprtree.y"
                    {
                        tempASTNode = (yyvsp[0].nptr);
                        (yyval.nptr) = (yyvsp[0].nptr);
                    }
#line 1621 "y.tab.c"
    break;

  case 14: /* FieldDecl: FieldType ID ';'  */
#line 91 "exprtree.y"
                            {
                                if(FLookup((yyvsp[-1].nptr)->name, Fhead) != NULL) {
                                    yyerror("Re-declaration of Field element %s\n", (yyvsp[-1].nptr)->name);
                                    exit(1);
                                }
                                FInstall((yyvsp[-1].nptr)->name, declarationType, NULL);
                            }
#line 1633 "y.tab.c"
    break;

  case 19: /* ClassDef: Cname '{' DECL ClassFieldDeclList ENDDECL ClassMethodDefns '}'  */
#line 109 "exprtree.y"
              {
                CCurrent = NULL;
                if(defCount != declCount)
                {
                    yyerror("All functions declared must be defined\n");
                    exit(1);
                }

                declCount = 0;
                defCount = 0;
              }
#line 1649 "y.tab.c"
    break;

  case 20: /* Cname: ID  */
#line 122 "exprtree.y"
           {CCurrent = CInstall((yyvsp[0].nptr)->name, NULL);}
#line 1655 "y.tab.c"
    break;

  case 23: /* ClassFieldDecl: Type ID ';'  */
#line 130 "exprtree.y"
                {
                    checkAvailability((yyvsp[-1].nptr)->name, 2);
                    Class_Finstall(CCurrent, declarationType, declarationCType, (yyvsp[-1].nptr)->name);
                }
#line 1664 "y.tab.c"
    break;

  case 24: /* ClassFieldDecl: Type ID '(' ParamList ')' ';'  */
#line 136 "exprtree.y"
                {
                    declCount++ ;
                    checkAvailability((yyvsp[-4].nptr)->name, 2);
                    Class_Minstall(CCurrent, (yyvsp[-4].nptr)->name, declarationType, Phead);
                    Phead = NULL;
                    Ptail = NULL;
                }
#line 1676 "y.tab.c"
    break;

  case 27: /* GDeclBlock: DECL GDeclList ENDDECL  */
#line 149 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) 
                                            {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1689 "y.tab.c"
    break;

  case 28: /* GDeclBlock: DECL ENDDECL  */
#line 157 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) 
                                            {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1702 "y.tab.c"
    break;

  case 29: /* GDeclBlock: %empty  */
#line 165 "exprtree.y"
                                        {
                                            initialize();
                                            if(testing) 
                                            {
                                                printTypeTable();
                                                printGSymbolTable();
                                            }
                                        }
#line 1715 "y.tab.c"
    break;

  case 33: /* FieldType: INT  */
#line 182 "exprtree.y"
                {declarationType = TLookup("integer");}
#line 1721 "y.tab.c"
    break;

  case 34: /* FieldType: STR  */
#line 183 "exprtree.y"
                {declarationType = TLookup("string");}
#line 1727 "y.tab.c"
    break;

  case 35: /* FieldType: ID  */
#line 184 "exprtree.y"
                {
                    declarationType = TLookup((yyvsp[0].nptr)->name);
                    if(declarationType == NULL) 
                    {
                        if(strcmp(tempASTNode->name, (yyvsp[0].nptr)->name) != 0) 
                        {
                            yyerror("Undefined User Defined Type %s\n", (yyvsp[0].nptr)->name);
                            exit(1);
                        } 
                        else 
                        {
                            declarationType = TLookup("dummy");
                        }
                    }
                }
#line 1747 "y.tab.c"
    break;

  case 36: /* Type: INT  */
#line 201 "exprtree.y"
            {declarationType = TLookup("integer");}
#line 1753 "y.tab.c"
    break;

  case 37: /* Type: STR  */
#line 202 "exprtree.y"
            {declarationType = TLookup("string");}
#line 1759 "y.tab.c"
    break;

  case 38: /* Type: ID  */
#line 203 "exprtree.y"
            {
                declarationType = TLookup((yyvsp[0].nptr)->name);
                declarationCType = CLookup((yyvsp[0].nptr)->name);
                if(declarationType == NULL && declarationCType == NULL) 
                {
                    yyerror("Unknown user-defined type / Class  %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1773 "y.tab.c"
    break;

  case 39: /* LType: INT  */
#line 226 "exprtree.y"
            {FDeclarationType = TLookup("integer");}
#line 1779 "y.tab.c"
    break;

  case 40: /* LType: STR  */
#line 227 "exprtree.y"
            {FDeclarationType = TLookup("string");}
#line 1785 "y.tab.c"
    break;

  case 41: /* LType: ID  */
#line 228 "exprtree.y"
            {
                FDeclarationType = TLookup((yyvsp[0].nptr)->name);
                if(FDeclarationType == NULL) 
                {
                    yyerror("Unknown user-defined type %s\n", (yyvsp[0].nptr)->name);
                    exit(1);
                }
            }
#line 1798 "y.tab.c"
    break;

  case 44: /* GId: ID '(' ParamList ')'  */
#line 242 "exprtree.y"
                            {
                                declCount++;
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                GInstall((yyvsp[-3].nptr)->name, declarationType,NULL, -1, Phead);
                                Phead = NULL;
                                Ptail = NULL;
                            }
#line 1810 "y.tab.c"
    break;

  case 45: /* GId: ID  */
#line 249 "exprtree.y"
                            {
                                checkAvailability((yyvsp[0].nptr)->name, 1);
                                GInstall((yyvsp[0].nptr)->name, declarationType,declarationCType, 1, NULL);
                            }
#line 1819 "y.tab.c"
    break;

  case 46: /* GId: ID '[' NUM ']'  */
#line 253 "exprtree.y"
                            {
                                checkAvailability((yyvsp[-3].nptr)->name, 1);
                                if((yyvsp[-1].nptr)->value.intval < 1) {
                                    yyerror("Invalid array size", NULL);
                                    exit(1);
                                }
                                GInstall((yyvsp[-3].nptr)->name, declarationType,NULL, (yyvsp[-1].nptr)->value.intval, NULL);
                            }
#line 1832 "y.tab.c"
    break;

  case 49: /* FDef: Type ID '(' ParamList ')' '{' LDeclBlock Body '}'  */
#line 268 "exprtree.y"
    {
        defCount++;
        if(CCurrent == NULL)   //Class is not involved
        {
            Gtemp = GLookup((yyvsp[-7].nptr)->name);
            if(Gtemp == NULL) //Not defined in global scope as well
            {
                yyerror("Function %s is not declared\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            if(Gtemp->type != declarationType)
            {
                yyerror("%s : Type mismatch\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            //declared and typecheck ok
            argList2 = Gtemp->paramlist;
        }

        else //The function is a method of a class
        {
            Mtemp = Class_MLookup(CCurrent, (yyvsp[-7].nptr)->name);
            if(Mtemp == NULL)
            {
                yyerror("%s: Function not declared in class %s\n",(yyvsp[-7].nptr)->name, CCurrent->name);
                exit(1);
            }

            if(Mtemp->type != declarationType)
            {
                yyerror("%s : Function type mismatch\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            //declaration and typecheck ok
            argList2 = Mtemp->paramlist;
        }                               

        argList1 = Phead;
        //Now check the function declarations and definitions

        while(argList1 != NULL && argList2 != NULL)
        {
            //type checking of the argumnets
            if(argList1->type != argList2->type)
            {
                yyerror("%s : Type mismatch in arguments\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            //name checking
            if(strcmp(argList1->name, argList2->name))
            {
                yyerror("%s : Name mismatch in arguments\n", (yyvsp[-7].nptr)->name);
                exit(1);
            }

            argList1 = argList1->next;
            argList2 = argList2->next;
        }          

        if((argList1 != NULL) || (argList2 != NULL))
        {
            yyerror("%s : Not enough arguments\n", (yyvsp[-7].nptr)->name);
            exit(1);
        }

        if(testing)
            printLSymbolTable((yyvsp[-7].nptr)->name);
        else
        {
            if(Gtemp != NULL)
                fprintf(intermediate, "F%d:\n", Gtemp->flabel);
            else
                fprintf(intermediate, "M%d:\n", Mtemp->flabel);
            fprintf(intermediate, "PUSH BP\n");
            fprintf(intermediate, "MOV BP,SP\n");

            Ltemp = Lhead;
            while(Ltemp != NULL) //Push arguments
            {
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
#line 1933 "y.tab.c"
    break;

  case 53: /* Param: LType ID  */
#line 371 "exprtree.y"
                 {
                    checkAvailability((yyvsp[0].nptr)->name, 0);
                    PInstall((yyvsp[0].nptr)->name, FDeclarationType);
                }
#line 1942 "y.tab.c"
    break;

  case 54: /* MainBlock: Type MAIN '(' ')' '{' LDeclBlock Body '}'  */
#line 377 "exprtree.y"
                                                       {
                                                            if(defCount != declCount) 
                                                            {
                                                                yyerror("All functions declared need to be defined\n", NULL);
                                                                exit(1);
                                                            }

                                                            if(declarationType != TLookup("integer")) 
                                                            {
                                                                yyerror("Main return type should be of integer type\n");
                                                                exit(1);
                                                            }

                                                            if(testing) 
                                                            {
                                                                printLSymbolTable("main");
                                                                //print_dot($7, "main");
                                                            } else 
                                                            {
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
#line 1983 "y.tab.c"
    break;

  case 55: /* LDeclBlock: DECL LDecList ENDDECL  */
#line 415 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1989 "y.tab.c"
    break;

  case 56: /* LDeclBlock: DECL ENDDECL  */
#line 416 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 1995 "y.tab.c"
    break;

  case 57: /* LDeclBlock: %empty  */
#line 417 "exprtree.y"
                                    {InstallParamsInLocal();}
#line 2001 "y.tab.c"
    break;

  case 63: /* LId: ID  */
#line 431 "exprtree.y"
        {
            checkAvailability((yyvsp[0].nptr)->name, 0);
            LInstall((yyvsp[0].nptr)->name, FDeclarationType);
        }
#line 2010 "y.tab.c"
    break;

  case 64: /* Body: START Slist RetStmt END  */
#line 437 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[-1].nptr), NULL);}
#line 2016 "y.tab.c"
    break;

  case 65: /* Body: START RetStmt END  */
#line 438 "exprtree.y"
                                {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2022 "y.tab.c"
    break;

  case 66: /* RetStmt: RETURN expr ';'  */
#line 441 "exprtree.y"
                            {
                                if(declarationType == (yyvsp[-1].nptr)->type) {
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_RET, NULL, NULL, NULL, (yyvsp[-1].nptr), NULL, NULL);
                                } else {
                                    yyerror("Return type mismatch", NULL);
                                    exit(1);
                                }
                            }
#line 2035 "y.tab.c"
    break;

  case 67: /* Field: ID '.' ID  */
#line 451 "exprtree.y"
                        {
                            assignType((yyvsp[-2].nptr), 0);
                            assignTypeField((yyvsp[0].nptr), (yyvsp[-2].nptr)->type->fields);
                            (yyval.nptr) = TreeCreate((yyvsp[0].nptr)->type, NODE_FIELD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2045 "y.tab.c"
    break;

  case 68: /* Field: Field '.' ID  */
#line 456 "exprtree.y"
                        {
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 2053 "y.tab.c"
    break;

  case 69: /* Field: SELF '.' ID  */
#line 459 "exprtree.y"
                        {
                            if(CCurrent == NULL)
                            {
                                yyerror("Self cannot be used outside class\n");
                                exit(1);
                            }

                            (yyvsp[-2].nptr)->Ctype = CCurrent;
                            (yyvsp[-2].nptr)->Lentry = LLookup("self");
                            (yyval.nptr) = insertFieldId((yyvsp[-2].nptr), (yyvsp[0].nptr));
                        }
#line 2069 "y.tab.c"
    break;

  case 70: /* FieldFunction: SELF '.' ID '(' ExprList ')'  */
#line 473 "exprtree.y"
              {
                if(CCurrent == NULL)
                {
                    yyerror("SELF cannot be used outside a class\n");
                    exit(1);
                }

                (yyvsp[-5].nptr)->Ctype = CCurrent;
                (yyvsp[-5].nptr)->Lentry = LLookup("void");
                (yyvsp[-5].nptr)->nodetype = NODE_FUNC;
                (yyvsp[-5].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                assignType((yyval.nptr), 3);
              }
#line 2088 "y.tab.c"
    break;

  case 71: /* FieldFunction: ID '.' ID '(' ExprList ')'  */
#line 489 "exprtree.y"
              {
                assignType((yyvsp[-5].nptr), 0);
                if((yyvsp[-5].nptr)->Ctype == NULL)
                {
                    yyerror("%s : Must be a class object for access modifier\n",(yyvsp[-5].nptr)->name);
                    exit(1);
                }

                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                assignType((yyval.nptr), 3);
              }
#line 2106 "y.tab.c"
    break;

  case 72: /* FieldFunction: Field '.' ID '(' ExprList ')'  */
#line 503 "exprtree.y"
              {
                if((yyvsp[-5].nptr)->Ctype == NULL)
                {
                    yyerror("Memberfield is not a class object\n");
                    exit(1);
                }

                (yyvsp[-3].nptr)->nodetype = NODE_FUNC;
                (yyvsp[-3].nptr)->ptr1 = reverseList((yyvsp[-1].nptr));
                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FIELDFUNC, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                assignType((yyval.nptr), 3);
              }
#line 2123 "y.tab.c"
    break;

  case 73: /* Slist: Slist Stmt  */
#line 516 "exprtree.y"
                        {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONNECTOR, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);}
#line 2129 "y.tab.c"
    break;

  case 74: /* Slist: Stmt  */
#line 517 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2135 "y.tab.c"
    break;

  case 75: /* Stmt: InputStmt  */
#line 520 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2141 "y.tab.c"
    break;

  case 76: /* Stmt: OutputStmt  */
#line 521 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2147 "y.tab.c"
    break;

  case 77: /* Stmt: AsgStmt  */
#line 522 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2153 "y.tab.c"
    break;

  case 78: /* Stmt: IfStmt  */
#line 523 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2159 "y.tab.c"
    break;

  case 79: /* Stmt: WhileStmt  */
#line 524 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2165 "y.tab.c"
    break;

  case 80: /* Stmt: BrkStmt  */
#line 525 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2171 "y.tab.c"
    break;

  case 81: /* Stmt: ContStmt  */
#line 526 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2177 "y.tab.c"
    break;

  case 82: /* Stmt: func ';'  */
#line 527 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2183 "y.tab.c"
    break;

  case 83: /* Stmt: FieldFunction ';'  */
#line 528 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2189 "y.tab.c"
    break;

  case 84: /* Stmt: BREAKPOINT ';'  */
#line 529 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2195 "y.tab.c"
    break;

  case 85: /* Stmt: FREE '(' ID ')' ';'  */
#line 530 "exprtree.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2208 "y.tab.c"
    break;

  case 86: /* Stmt: FREE '(' Field ')' ';'  */
#line 538 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->type == TLookup("integer") || (yyvsp[-2].nptr)->type == TLookup("string")) {
                                        yyerror("Cannot FREE a string or integer variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_FREE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2220 "y.tab.c"
    break;

  case 87: /* Stmt: INIT '(' ')' ';'  */
#line 545 "exprtree.y"
                                {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_INIT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2226 "y.tab.c"
    break;

  case 88: /* Stmt: DELETE '(' ID ')' ';'  */
#line 546 "exprtree.y"
                                {
                                    assignType((yyvsp[-2].nptr), 0);
                                    if((yyvsp[-2].nptr)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_DELETE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2239 "y.tab.c"
    break;

  case 89: /* Stmt: DELETE '(' Field ')' ';'  */
#line 554 "exprtree.y"
                                {
                                    if((yyvsp[-2].nptr)->Ctype == NULL) {
                                        yyerror("Cannot DELETE a non class variable\n", NULL);
                                        exit(1);
                                    }
                                    (yyval.nptr) = TreeCreate(TLookup("void"), NODE_DELETE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                }
#line 2251 "y.tab.c"
    break;

  case 90: /* IfStmt: IF '(' expr ')' THEN Slist ELSE Slist ENDIF ';'  */
#line 563 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-7].nptr)->type, TLookup("boolean"), 'e');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF_ELSE, NULL, NULL, NULL, (yyvsp[-7].nptr), (yyvsp[-2].nptr), (yyvsp[-4].nptr));
                                                            }
#line 2260 "y.tab.c"
    break;

  case 91: /* IfStmt: IF '(' expr ')' THEN Slist ENDIF ';'  */
#line 567 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'i');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_IF, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2269 "y.tab.c"
    break;

  case 92: /* WhileStmt: WHILE '(' expr ')' DO Slist ENDWHILE ';'  */
#line 573 "exprtree.y"
                                                            {
                                                                typecheck((yyvsp[-5].nptr)->type, TLookup("boolean"), 'w');
                                                                (yyval.nptr) = TreeCreate(TLookup("void"), NODE_WHILE, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-2].nptr), NULL);
                                                            }
#line 2278 "y.tab.c"
    break;

  case 93: /* BrkStmt: BREAK ';'  */
#line 578 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_BREAK, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2284 "y.tab.c"
    break;

  case 94: /* ContStmt: CONT ';'  */
#line 581 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_CONT, NULL, NULL, NULL, NULL, NULL, NULL);}
#line 2290 "y.tab.c"
    break;

  case 95: /* InputStmt: READ '(' id ')' ';'  */
#line 584 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2302 "y.tab.c"
    break;

  case 96: /* InputStmt: READ '(' Field ')' ';'  */
#line 591 "exprtree.y"
                                    {
                                        if((yyvsp[-2].nptr)->type != TLookup("integer") && (yyvsp[-2].nptr)->type != TLookup("string")) {
                                            yyerror("Cannot READ a udt type\n", NULL);
                                            exit(1);
                                        }
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_READ, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);
                                    }
#line 2314 "y.tab.c"
    break;

  case 97: /* OutputStmt: WRITE '(' expr ')' ';'  */
#line 600 "exprtree.y"
                                    {(yyval.nptr) = TreeCreate(TLookup("void"), NODE_WRITE, NULL, NULL, NULL, (yyvsp[-2].nptr), NULL, NULL);}
#line 2320 "y.tab.c"
    break;

  case 98: /* AsgStmt: id ASSGN expr ';'  */
#line 603 "exprtree.y"
                                    {
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2329 "y.tab.c"
    break;

  case 99: /* AsgStmt: ID ASSGN expr ';'  */
#line 607 "exprtree.y"
                                    {
                                        assignType((yyvsp[-3].nptr), 0);
                                        typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                        (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                    }
#line 2339 "y.tab.c"
    break;

  case 100: /* AsgStmt: Field ASSGN ALLOC '(' ')' ';'  */
#line 612 "exprtree.y"
                                        {
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2351 "y.tab.c"
    break;

  case 101: /* AsgStmt: ID ASSGN ALLOC '(' ')' ';'  */
#line 619 "exprtree.y"
                                        {
                                            assignType((yyvsp[-5].nptr), 0);
                                            if((yyvsp[-5].nptr)->type == TLookup("integer") || (yyvsp[-5].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot ALLOC to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-5].nptr), (yyvsp[-3].nptr), NULL);
                                        }
#line 2364 "y.tab.c"
    break;

  case 102: /* AsgStmt: ID ASSGN NEW '(' ID ')' ';'  */
#line 627 "exprtree.y"
                                        {
                                            assignType((yyvsp[-6].nptr), 0);
                                            if((yyvsp[-6].nptr)->Ctype != CLookup((yyvsp[-2].nptr)->name)) {
                                                yyerror("Type mismatch\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2377 "y.tab.c"
    break;

  case 103: /* AsgStmt: Field ASSGN NEW '(' ID ')' ';'  */
#line 635 "exprtree.y"
                                        {
                                            if((yyvsp[-6].nptr)->Ctype != CLookup((yyvsp[-2].nptr)->name)) {
                                                yyerror("Type mismatch\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-6].nptr), (yyvsp[-4].nptr), NULL);
                                        }
#line 2389 "y.tab.c"
    break;

  case 104: /* AsgStmt: Field ASSGN expr ';'  */
#line 642 "exprtree.y"
                                        {
                                            typecheck((yyvsp[-3].nptr)->type, (yyvsp[-1].nptr)->type, '=');
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                    
                                        }
#line 2399 "y.tab.c"
    break;

  case 105: /* AsgStmt: ID ASSGN NILL ';'  */
#line 647 "exprtree.y"
                                        {
                                            assignType((yyvsp[-3].nptr), 0);
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2412 "y.tab.c"
    break;

  case 106: /* AsgStmt: Field ASSGN NILL ';'  */
#line 655 "exprtree.y"
                                        {
                                            if((yyvsp[-3].nptr)->type == TLookup("integer") || (yyvsp[-3].nptr)->type == TLookup("string")) {
                                                yyerror("Cannot assign NULL to string or integer variable\n", NULL);
                                                exit(1);
                                            }
                                            (yyval.nptr) = TreeCreate(TLookup("void"), NODE_ASSGN, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                                        }
#line 2424 "y.tab.c"
    break;

  case 107: /* ExprList: ExprList ',' expr  */
#line 664 "exprtree.y"
                            {
                                (yyvsp[0].nptr)->arglist = (yyvsp[-2].nptr);
                                (yyval.nptr) = (yyvsp[0].nptr);
                            }
#line 2433 "y.tab.c"
    break;

  case 108: /* ExprList: expr  */
#line 668 "exprtree.y"
                            {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2439 "y.tab.c"
    break;

  case 109: /* ExprList: %empty  */
#line 669 "exprtree.y"
                            {(yyval.nptr) = NULL;}
#line 2445 "y.tab.c"
    break;

  case 110: /* expr: expr PLUS expr  */
#line 672 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_PLUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2454 "y.tab.c"
    break;

  case 111: /* expr: expr MINUS expr  */
#line 676 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MINUS, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2463 "y.tab.c"
    break;

  case 112: /* expr: expr MUL expr  */
#line 680 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MUL, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2472 "y.tab.c"
    break;

  case 113: /* expr: expr DIV expr  */
#line 684 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_DIV, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2481 "y.tab.c"
    break;

  case 114: /* expr: expr MOD expr  */
#line 688 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'a');
                            (yyval.nptr) = TreeCreate(TLookup("integer"), NODE_MOD, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2490 "y.tab.c"
    break;

  case 115: /* expr: expr LT expr  */
#line 692 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2499 "y.tab.c"
    break;

  case 116: /* expr: expr GT expr  */
#line 696 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GT, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2508 "y.tab.c"
    break;

  case 117: /* expr: expr LE expr  */
#line 700 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_LE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2517 "y.tab.c"
    break;

  case 118: /* expr: expr GE expr  */
#line 704 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_GE, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2526 "y.tab.c"
    break;

  case 119: /* expr: expr NEQ expr  */
#line 708 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2535 "y.tab.c"
    break;

  case 120: /* expr: expr EQ expr  */
#line 712 "exprtree.y"
                        {
                            typecheck((yyvsp[-2].nptr)->type, (yyvsp[0].nptr)->type, 'b');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-2].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2544 "y.tab.c"
    break;

  case 121: /* expr: Field DEQNILL  */
#line 716 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2553 "y.tab.c"
    break;

  case 122: /* expr: Field NEQNILL  */
#line 720 "exprtree.y"
                        {
                            typecheck((yyvsp[-1].nptr)->type, NULL, '!');
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2562 "y.tab.c"
    break;

  case 123: /* expr: ID DEQNILL  */
#line 724 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_EQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2571 "y.tab.c"
    break;

  case 124: /* expr: ID NEQNILL  */
#line 728 "exprtree.y"
                        {
                            assignType((yyvsp[-1].nptr), 0);
                            (yyval.nptr) = TreeCreate(TLookup("boolean"), NODE_NEQ, NULL, NULL, NULL, (yyvsp[-1].nptr), (yyvsp[0].nptr), NULL);
                        }
#line 2580 "y.tab.c"
    break;

  case 125: /* expr: '(' expr ')'  */
#line 732 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[-1].nptr);}
#line 2586 "y.tab.c"
    break;

  case 126: /* expr: NUM  */
#line 733 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2595 "y.tab.c"
    break;

  case 127: /* expr: MINUS NUM  */
#line 737 "exprtree.y"
                        {
                            (yyvsp[0].nptr)->value.intval = -1*((yyvsp[0].nptr)->value.intval);
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("integer");
                        }
#line 2605 "y.tab.c"
    break;

  case 128: /* expr: STRVAL  */
#line 742 "exprtree.y"
                        {
                            (yyval.nptr) = (yyvsp[0].nptr);
                            (yyval.nptr)->type = TLookup("string");
                        }
#line 2614 "y.tab.c"
    break;

  case 129: /* expr: id  */
#line 746 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2620 "y.tab.c"
    break;

  case 130: /* expr: func  */
#line 747 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2626 "y.tab.c"
    break;

  case 131: /* expr: Field  */
#line 748 "exprtree.y"
                        {(yyval.nptr) = (yyvsp[0].nptr);}
#line 2632 "y.tab.c"
    break;

  case 132: /* func: ID '(' ExprList ')'  */
#line 751 "exprtree.y"
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
#line 2667 "y.tab.c"
    break;

  case 133: /* id: ID  */
#line 782 "exprtree.y"
                        {
                            assignType((yyvsp[0].nptr), 0);
                            (yyval.nptr) = (yyvsp[0].nptr);
                        }
#line 2676 "y.tab.c"
    break;

  case 134: /* id: ID '[' NUM ']'  */
#line 786 "exprtree.y"
                        {
                            (yyvsp[-1].nptr)->type = TLookup("integer");
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2686 "y.tab.c"
    break;

  case 135: /* id: ID '[' id ']'  */
#line 791 "exprtree.y"
                        {
                            assignType((yyvsp[-3].nptr), 2);
                            (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
                        }
#line 2695 "y.tab.c"
    break;

  case 136: /* id: ID '[' expr ']'  */
#line 796 "exprtree.y"
    {
        if((yyvsp[-1].nptr)->type!=TLookup("integer"))
        {
        	fprintf(stderr,"Expected an arithmetic expression in the index for array %s\n",(yyvsp[-3].nptr)->name);
        	exit(1);
        }
        assignType((yyvsp[-3].nptr), 2);
        (yyval.nptr) = TreeCreate((yyvsp[-3].nptr)->type, NODE_ARRAY, NULL, NULL, NULL, (yyvsp[-3].nptr), (yyvsp[-1].nptr), NULL);
       }
#line 2709 "y.tab.c"
    break;


#line 2713 "y.tab.c"

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

#line 807 "exprtree.y"


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

