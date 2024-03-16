/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

#line 175 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
