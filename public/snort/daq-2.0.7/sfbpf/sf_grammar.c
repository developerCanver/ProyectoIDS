/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         sfbpf_parse
#define yylex           sfbpf_lex
#define yyerror         sfbpf_error
#define yydebug         sfbpf_debug
#define yynerrs         sfbpf_nerrs
#define yylval          sfbpf_lval
#define yychar          sfbpf_char

/* First part of user prologue.  */
#line 1 "./grammar.y"

/*
 * Copyright (c) 1988, 1989, 1990, 1991, 1992, 1993, 1994, 1995, 1996
 *	The Regents of the University of California.  All rights reserved.
 *
 * Some Portions Copyright (C) 2014-2021 Cisco and/or its affiliates. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that: (1) source code distributions
 * retain the above copyright notice and this paragraph in its entirety, (2)
 * distributions including binary code include the above copyright notice and
 * this paragraph in its entirety in the documentation or other materials
 * provided with the distribution, and (3) all advertising materials mentioning
 * features or use of this software display the following acknowledgement:
 * ``This product includes software developed by the University of California,
 * Lawrence Berkeley Laboratory and its contributors.'' Neither the name of
 * the University nor the names of its contributors may be used to endorse
 * or promote products derived from this software without specific prior
 * written permission.
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTIES, INCLUDING, WITHOUT LIMITATION, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 */
#ifndef lint
static const char rcsid[] =
    "@(#) $Header: /usr/cvsroot/sfeng/ims/src/libraries/daq/daq/sfbpf/grammar.y,v 1.1 2010/04/15 19:18:35 maltizer Exp $ (LBL)";
#endif

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>

#if __STDC__
struct mbuf;
struct rtentry;
#endif

#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>

#include "sfbpf-int.h"

#include "gencode.h"
#ifdef HAVE_NET_PFVAR_H
#include <net/if.h>
#include <net/pfvar.h>
#include <net/if_pflog.h>
#endif
#include "ieee80211.h"
#include "namedb.h"

#define QSET(q, p, d, a) (q).proto = (p),\
			 (q).dir = (d),\
			 (q).addr = (a)

struct tok {
	int v;			/* value */
	const char *s;		/* string */
};

static const struct tok ieee80211_types[] = {
	{ IEEE80211_FC0_TYPE_DATA, "data" },
	{ IEEE80211_FC0_TYPE_MGT, "mgt" },
	{ IEEE80211_FC0_TYPE_MGT, "management" },
	{ IEEE80211_FC0_TYPE_CTL, "ctl" },
	{ IEEE80211_FC0_TYPE_CTL, "control" },
	{ 0, NULL }
};
static const struct tok ieee80211_mgt_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assocreq" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_REQ, "assoc-req" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assocresp" },
	{ IEEE80211_FC0_SUBTYPE_ASSOC_RESP, "assoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassocreq" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_REQ, "reassoc-req" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassocresp" },
	{ IEEE80211_FC0_SUBTYPE_REASSOC_RESP, "reassoc-resp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probereq" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_REQ, "probe-req" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "proberesp" },
	{ IEEE80211_FC0_SUBTYPE_PROBE_RESP, "probe-resp" },
	{ IEEE80211_FC0_SUBTYPE_BEACON, "beacon" },
	{ IEEE80211_FC0_SUBTYPE_ATIM, "atim" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassoc" },
	{ IEEE80211_FC0_SUBTYPE_DISASSOC, "disassociation" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "auth" },
	{ IEEE80211_FC0_SUBTYPE_AUTH, "authentication" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauth" },
	{ IEEE80211_FC0_SUBTYPE_DEAUTH, "deauthentication" },
	{ 0, NULL }
};
static const struct tok ieee80211_ctl_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_PS_POLL, "ps-poll" },
	{ IEEE80211_FC0_SUBTYPE_RTS, "rts" },
	{ IEEE80211_FC0_SUBTYPE_CTS, "cts" },
	{ IEEE80211_FC0_SUBTYPE_ACK, "ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_END, "cf-end" },
	{ IEEE80211_FC0_SUBTYPE_CF_END_ACK, "cf-end-ack" },
	{ 0, NULL }
};
static const struct tok ieee80211_data_subtypes[] = {
	{ IEEE80211_FC0_SUBTYPE_DATA, "data" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACK, "data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_CF_POLL, "data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_CF_ACPL, "data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_NODATA, "null" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACK, "cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "cf-poll"  },
	{ IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_DATA, "qos-data" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACK, "qos-data-cf-ack" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_POLL, "qos-data-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_CF_ACPL, "qos-data-cf-ack-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA, "qos" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_POLL, "qos-cf-poll" },
	{ IEEE80211_FC0_SUBTYPE_QOS|IEEE80211_FC0_SUBTYPE_NODATA_CF_ACPL, "qos-cf-ack-poll" },
	{ 0, NULL }
};
struct type2tok {
	int type;
	const struct tok *tok;
};
static const struct type2tok ieee80211_type_subtypes[] = {
	{ IEEE80211_FC0_TYPE_MGT, ieee80211_mgt_subtypes },
	{ IEEE80211_FC0_TYPE_CTL, ieee80211_ctl_subtypes },
	{ IEEE80211_FC0_TYPE_DATA, ieee80211_data_subtypes },
	{ 0, NULL }
};

static int
str2tok(const char *str, const struct tok *toks)
{
	int i;

	for (i = 0; toks[i].s != NULL; i++) {
		if (sfbpf_strcasecmp(toks[i].s, str) == 0)
			return (toks[i].v);
	}
	return (-1);
}

int n_errors = 0;

static struct qual qerr = { Q_UNDEF, Q_UNDEF, Q_UNDEF, Q_UNDEF };

static void
yyerror(const char *msg)
{
	++n_errors;
	bpf_error("%s", msg);
	/* NOTREACHED */
}

#ifndef YYBISON
int yyparse(void);

int
sfbpf_parse()
{
	return (yyparse());
}
#endif

#ifdef HAVE_NET_PFVAR_H
static int
pfreason_to_num(const char *reason)
{
	const char *reasons[] = PFRES_NAMES;
	int i;

	for (i = 0; reasons[i]; i++) {
		if (sfbpf_strcasecmp(reason, reasons[i]) == 0)
			return (i);
	}
	bpf_error("unknown PF reason");
	/*NOTREACHED*/
}

static int
pfaction_to_num(const char *action)
{
	if (sfbpf_strcasecmp(action, "pass") == 0 ||
	    sfbpf_strcasecmp(action, "accept") == 0)
		return (PF_PASS);
	else if (sfbpf_strcasecmp(action, "drop") == 0 ||
		sfbpf_strcasecmp(action, "block") == 0)
		return (PF_DROP);
#if HAVE_PF_NAT_THROUGH_PF_NORDR
	else if (sfbpf_strcasecmp(action, "rdr") == 0)
		return (PF_RDR);
	else if (sfbpf_strcasecmp(action, "nat") == 0)
		return (PF_NAT);
	else if (sfbpf_strcasecmp(action, "binat") == 0)
		return (PF_BINAT);
	else if (sfbpf_strcasecmp(action, "nordr") == 0)
		return (PF_NORDR);
#endif
	else {
		bpf_error("unknown PF action");
		/*NOTREACHED*/
	}
}
#else /* !HAVE_NET_PFVAR_H */
static int
pfreason_to_num(const char *reason)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}

static int
pfaction_to_num(const char *action)
{
	bpf_error("libpcap was compiled on a machine without pf support");
	/*NOTREACHED*/

	/* this is to make the VC compiler happy */
	return -1;
}
#endif /* HAVE_NET_PFVAR_H */

#line 309 "y.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_SFBPF_Y_TAB_H_INCLUDED
# define YY_SFBPF_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int sfbpf_debug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    DST = 258,
    SRC = 259,
    HOST = 260,
    GATEWAY = 261,
    NET = 262,
    NETMASK = 263,
    PORT = 264,
    PORTRANGE = 265,
    LESS = 266,
    GREATER = 267,
    PROTO = 268,
    PROTOCHAIN = 269,
    CBYTE = 270,
    ARP = 271,
    RARP = 272,
    IP = 273,
    SCTP = 274,
    TCP = 275,
    UDP = 276,
    ICMP = 277,
    IGMP = 278,
    IGRP = 279,
    PIM = 280,
    VRRP = 281,
    ATALK = 282,
    AARP = 283,
    DECNET = 284,
    LAT = 285,
    SCA = 286,
    MOPRC = 287,
    MOPDL = 288,
    TK_BROADCAST = 289,
    TK_MULTICAST = 290,
    NUM = 291,
    INBOUND = 292,
    OUTBOUND = 293,
    PF_IFNAME = 294,
    PF_RSET = 295,
    PF_RNR = 296,
    PF_SRNR = 297,
    PF_REASON = 298,
    PF_ACTION = 299,
    TYPE = 300,
    SUBTYPE = 301,
    DIR = 302,
    ADDR1 = 303,
    ADDR2 = 304,
    ADDR3 = 305,
    ADDR4 = 306,
    LINK = 307,
    GEQ = 308,
    LEQ = 309,
    NEQ = 310,
    ID = 311,
    EID = 312,
    HID = 313,
    HID6 = 314,
    AID = 315,
    LSH = 316,
    RSH = 317,
    LEN = 318,
    IPV6 = 319,
    ICMPV6 = 320,
    AH = 321,
    ESP = 322,
    VLAN = 323,
    MPLS = 324,
    PPPOED = 325,
    PPPOES = 326,
    ISO = 327,
    ESIS = 328,
    CLNP = 329,
    ISIS = 330,
    L1 = 331,
    L2 = 332,
    IIH = 333,
    LSP = 334,
    SNP = 335,
    CSNP = 336,
    PSNP = 337,
    STP = 338,
    IPX = 339,
    NETBEUI = 340,
    LANE = 341,
    LLC = 342,
    METAC = 343,
    BCC = 344,
    SC = 345,
    ILMIC = 346,
    OAMF4EC = 347,
    OAMF4SC = 348,
    OAM = 349,
    OAMF4 = 350,
    CONNECTMSG = 351,
    METACONNECT = 352,
    VPI = 353,
    VCI = 354,
    RADIO = 355,
    FISU = 356,
    LSSU = 357,
    MSU = 358,
    SIO = 359,
    OPC = 360,
    DPC = 361,
    SLS = 362,
    OR = 363,
    AND = 364,
    UMINUS = 365
  };
#endif
/* Tokens.  */
#define DST 258
#define SRC 259
#define HOST 260
#define GATEWAY 261
#define NET 262
#define NETMASK 263
#define PORT 264
#define PORTRANGE 265
#define LESS 266
#define GREATER 267
#define PROTO 268
#define PROTOCHAIN 269
#define CBYTE 270
#define ARP 271
#define RARP 272
#define IP 273
#define SCTP 274
#define TCP 275
#define UDP 276
#define ICMP 277
#define IGMP 278
#define IGRP 279
#define PIM 280
#define VRRP 281
#define ATALK 282
#define AARP 283
#define DECNET 284
#define LAT 285
#define SCA 286
#define MOPRC 287
#define MOPDL 288
#define TK_BROADCAST 289
#define TK_MULTICAST 290
#define NUM 291
#define INBOUND 292
#define OUTBOUND 293
#define PF_IFNAME 294
#define PF_RSET 295
#define PF_RNR 296
#define PF_SRNR 297
#define PF_REASON 298
#define PF_ACTION 299
#define TYPE 300
#define SUBTYPE 301
#define DIR 302
#define ADDR1 303
#define ADDR2 304
#define ADDR3 305
#define ADDR4 306
#define LINK 307
#define GEQ 308
#define LEQ 309
#define NEQ 310
#define ID 311
#define EID 312
#define HID 313
#define HID6 314
#define AID 315
#define LSH 316
#define RSH 317
#define LEN 318
#define IPV6 319
#define ICMPV6 320
#define AH 321
#define ESP 322
#define VLAN 323
#define MPLS 324
#define PPPOED 325
#define PPPOES 326
#define ISO 327
#define ESIS 328
#define CLNP 329
#define ISIS 330
#define L1 331
#define L2 332
#define IIH 333
#define LSP 334
#define SNP 335
#define CSNP 336
#define PSNP 337
#define STP 338
#define IPX 339
#define NETBEUI 340
#define LANE 341
#define LLC 342
#define METAC 343
#define BCC 344
#define SC 345
#define ILMIC 346
#define OAMF4EC 347
#define OAMF4SC 348
#define OAM 349
#define OAMF4 350
#define CONNECTMSG 351
#define METACONNECT 352
#define VPI 353
#define VCI 354
#define RADIO 355
#define FISU 356
#define LSSU 357
#define MSU 358
#define SIO 359
#define OPC 360
#define DPC 361
#define SLS 362
#define OR 363
#define AND 364
#define UMINUS 365

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 233 "./grammar.y"

	int i;
	sfbpf_u_int32 h;
	u_char *e;
	char *s;
	struct stmt *stmt;
	struct arth *a;
	struct {
		struct qual q;
		int atmfieldtype;
		int mtp3fieldtype;
		struct block *b;
	} blk;
	struct block *rblk;

#line 597 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE sfbpf_lval;

int sfbpf_parse (void);

#endif /* !YY_SFBPF_Y_TAB_H_INCLUDED  */



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

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


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
#define YYLAST   669

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  126
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  202
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  274

#define YYUNDEFTOK  2
#define YYMAXUTOK   365


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   110,     2,     2,     2,     2,   112,     2,
     119,   118,   115,   113,     2,   114,     2,   116,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   125,     2,
     122,   121,   120,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   123,     2,   124,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,   111,     2,     2,     2,     2,     2,
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
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   117
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   306,   306,   310,   312,   314,   315,   316,   317,   318,
     320,   322,   324,   325,   327,   329,   330,   332,   334,   347,
     356,   365,   374,   383,   385,   387,   389,   390,   391,   393,
     395,   397,   398,   400,   401,   402,   403,   404,   405,   407,
     408,   409,   410,   412,   414,   415,   416,   417,   418,   419,
     422,   423,   426,   427,   428,   429,   430,   431,   432,   433,
     434,   435,   438,   439,   440,   441,   444,   446,   447,   448,
     449,   450,   451,   452,   453,   454,   455,   456,   457,   458,
     459,   460,   461,   462,   463,   464,   465,   466,   467,   468,
     469,   470,   471,   472,   473,   474,   475,   476,   477,   478,
     479,   480,   481,   482,   483,   485,   486,   487,   488,   489,
     490,   491,   492,   493,   494,   495,   496,   497,   498,   499,
     502,   503,   504,   505,   506,   507,   510,   515,   518,   522,
     525,   526,   532,   533,   553,   569,   570,   583,   584,   587,
     590,   591,   592,   594,   595,   596,   598,   599,   601,   602,
     603,   604,   605,   606,   607,   608,   609,   610,   611,   612,
     613,   615,   616,   617,   618,   619,   621,   622,   624,   625,
     626,   627,   628,   629,   630,   631,   633,   634,   635,   636,
     639,   640,   642,   643,   644,   645,   647,   654,   655,   658,
     659,   660,   663,   664,   665,   666,   668,   669,   670,   671,
     673,   682,   683
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "DST", "SRC", "HOST", "GATEWAY", "NET",
  "NETMASK", "PORT", "PORTRANGE", "LESS", "GREATER", "PROTO", "PROTOCHAIN",
  "CBYTE", "ARP", "RARP", "IP", "SCTP", "TCP", "UDP", "ICMP", "IGMP",
  "IGRP", "PIM", "VRRP", "ATALK", "AARP", "DECNET", "LAT", "SCA", "MOPRC",
  "MOPDL", "TK_BROADCAST", "TK_MULTICAST", "NUM", "INBOUND", "OUTBOUND",
  "PF_IFNAME", "PF_RSET", "PF_RNR", "PF_SRNR", "PF_REASON", "PF_ACTION",
  "TYPE", "SUBTYPE", "DIR", "ADDR1", "ADDR2", "ADDR3", "ADDR4", "LINK",
  "GEQ", "LEQ", "NEQ", "ID", "EID", "HID", "HID6", "AID", "LSH", "RSH",
  "LEN", "IPV6", "ICMPV6", "AH", "ESP", "VLAN", "MPLS", "PPPOED", "PPPOES",
  "ISO", "ESIS", "CLNP", "ISIS", "L1", "L2", "IIH", "LSP", "SNP", "CSNP",
  "PSNP", "STP", "IPX", "NETBEUI", "LANE", "LLC", "METAC", "BCC", "SC",
  "ILMIC", "OAMF4EC", "OAMF4SC", "OAM", "OAMF4", "CONNECTMSG",
  "METACONNECT", "VPI", "VCI", "RADIO", "FISU", "LSSU", "MSU", "SIO",
  "OPC", "DPC", "SLS", "OR", "AND", "'!'", "'|'", "'&'", "'+'", "'-'",
  "'*'", "'/'", "UMINUS", "')'", "'('", "'>'", "'='", "'<'", "'['", "']'",
  "':'", "$accept", "prog", "null", "expr", "and", "or", "id", "nid",
  "not", "paren", "pid", "qid", "term", "head", "rterm", "pqual", "dqual",
  "aqual", "ndaqual", "pname", "other", "pfvar", "p80211", "type",
  "subtype", "type_subtype", "dir", "reason", "action", "relop", "irelop",
  "arth", "narth", "byteop", "pnum", "atmtype", "atmmultitype", "atmfield",
  "atmvalue", "atmfieldvalue", "atmlistvalue", "mtp2type", "mtp3field",
  "mtp3value", "mtp3fieldvalue", "mtp3listvalue", YY_NULLPTR
};
#endif

# ifdef YYPRINT
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
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
      33,   124,    38,    43,    45,    42,    47,   365,    41,    40,
      62,    61,    60,    91,    93,    58
};
# endif

#define YYPACT_NINF (-198)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-42)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -198,    34,   216,  -198,     1,    48,    61,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,    46,    54,
      81,    82,   -13,    58,  -198,  -198,  -198,  -198,  -198,  -198,
     -24,   -24,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,   530,  -198,   -54,   426,   426,  -198,   151,  -198,   618,
      13,  -198,  -198,   525,  -198,  -198,  -198,  -198,    52,  -198,
     102,  -198,  -198,   -90,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,   -24,  -198,  -198,   530,   -19,  -198,  -198,
    -198,   321,   321,  -198,   -60,    12,    17,  -198,  -198,    -4,
      33,  -198,  -198,  -198,   151,   151,  -198,   -33,   -29,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,   -12,    67,
     -11,  -198,  -198,  -198,  -198,   170,  -198,  -198,  -198,   530,
    -198,  -198,  -198,   530,   530,   530,   530,   530,   530,   530,
     530,  -198,  -198,  -198,   530,   530,  -198,   114,   115,   118,
    -198,  -198,  -198,   122,   123,   128,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,   129,    17,   -44,  -198,   321,   321,  -198,
      16,  -198,  -198,  -198,  -198,  -198,   110,   133,   134,  -198,
    -198,    60,   -54,    17,   172,   181,   183,   185,  -198,  -198,
     143,  -198,  -198,  -198,  -198,  -198,  -198,   -51,    68,    68,
      78,    99,    -7,    -7,  -198,  -198,   -44,   -44,  -198,   -89,
    -198,  -198,  -198,    -5,  -198,  -198,  -198,   -52,  -198,  -198,
    -198,  -198,   151,   151,  -198,  -198,  -198,  -198,    -9,  -198,
     161,  -198,   114,  -198,   122,  -198,  -198,  -198,  -198,  -198,
      74,  -198,  -198,  -198
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,    51,     1,     0,     0,     0,    69,    70,    68,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    85,    84,   166,   110,   111,     0,     0,
       0,     0,     0,     0,    67,   160,    86,    87,    88,    89,
     113,   115,   116,   117,    90,    91,   100,    92,    93,    94,
      95,    96,    97,    99,    98,   101,   102,   103,   168,   169,
     170,   171,   174,   175,   172,   173,   176,   177,   178,   179,
     180,   181,   104,   189,   190,   191,   192,   193,   194,   195,
      24,     0,    25,     2,    51,    51,     5,     0,    31,     0,
      50,    44,   118,     0,   147,   146,    45,    46,     0,    48,
       0,   107,   108,     0,   120,   121,   122,   123,   137,   138,
     124,   139,   125,     0,   112,   114,     0,     0,   158,    11,
      10,    51,    51,    32,     0,   147,   146,    15,    21,    18,
      20,    22,    39,    12,     0,     0,    13,    53,    52,    62,
      66,    63,    64,    65,    36,    37,   105,   106,     0,     0,
       0,    58,    59,    60,    61,    34,    35,    38,   119,     0,
     141,   143,   145,     0,     0,     0,     0,     0,     0,     0,
       0,   140,   142,   144,     0,     0,   186,     0,     0,     0,
      47,   182,   200,     0,     0,     0,    49,   196,   162,   161,
     164,   165,   163,     0,     0,     0,     7,    51,    51,     6,
     146,     9,     8,    40,   159,   167,     0,     0,     0,    23,
      26,    30,     0,    29,     0,     0,     0,     0,   130,   131,
     127,   134,   128,   135,   136,   129,    33,     0,   156,   157,
     155,   154,   150,   151,   152,   153,    42,    43,   187,     0,
     183,   184,   201,     0,   197,   198,   109,   146,    17,    16,
      19,    14,     0,     0,    55,    57,    54,    56,     0,   148,
       0,   185,     0,   199,     0,    27,    28,   132,   133,   126,
       0,   188,   202,   149
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -198,  -198,  -198,   197,    -6,  -197,   -86,  -121,     5,    -2,
    -198,  -198,   -81,  -198,  -198,  -198,  -198,    45,  -198,     7,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,  -198,   -72,
     -47,   -22,   -83,  -198,   -35,  -198,  -198,  -198,  -198,  -169,
    -198,  -198,  -198,  -198,  -163,  -198
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,   124,   121,   122,   209,   133,   134,   116,
     211,   212,    86,    87,    88,    89,   155,   156,   157,   117,
      91,    92,   158,   220,   269,   222,   225,   110,   112,   174,
     175,    93,    94,   193,    95,    96,    97,    98,   180,   181,
     239,    99,   100,   186,   187,   243
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      85,   132,   125,   123,   206,   114,   115,    84,   238,    90,
     163,   164,    25,   -41,   210,   253,   -13,   163,   164,   119,
     242,   188,   189,   108,   218,   223,   178,   267,   184,   261,
     190,   191,   192,   125,     3,   196,   201,   101,   113,   113,
     199,   202,   262,   109,   219,   224,   264,   268,   119,   120,
     126,   179,   136,   185,   119,   120,   -29,   -29,   203,   118,
     165,   166,   167,   168,   169,   170,   205,   165,   166,   167,
     168,   169,   170,   259,   260,   214,   215,   210,   194,   216,
     217,   126,    85,    85,   102,   135,   200,   200,   176,    84,
      84,    90,    90,   271,   195,    82,   177,   103,   183,   136,
     213,   272,   104,   119,   159,   160,   161,   162,   169,   170,
     105,   113,   207,   263,   111,   125,   123,   106,   107,   198,
     198,   -41,   -41,   221,   -13,   -13,   197,   197,    90,    90,
     204,   -41,   135,   113,   -13,   205,   159,   227,   182,   163,
     164,   228,   229,   230,   231,   232,   233,   234,   235,   208,
     176,   240,   236,   237,   241,   160,   161,   162,   182,   244,
     163,   164,   200,   247,   245,   246,   265,   266,   248,   249,
     250,    82,   171,   172,   173,   139,   254,   141,   251,   142,
     143,   167,   168,   169,   170,   255,   256,    25,   257,   258,
     166,   167,   168,   169,   170,   198,    85,   270,   273,    83,
     226,     0,   197,   197,    90,    90,   252,   127,   128,   129,
     130,   131,   167,   168,   169,   170,    -3,   136,   136,     0,
       0,    82,   171,   172,   173,     0,     0,     4,     5,     0,
       0,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
     135,   135,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    80,     0,     0,     0,     0,     0,     0,    34,     0,
      82,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,     0,     0,     0,
      81,     0,     4,     5,     0,    82,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,     0,     0,    25,    26,    27,
      28,    29,    30,    31,    32,    33,     0,     0,     0,     0,
       0,     0,     0,    34,     0,     0,     0,   127,   128,   129,
     130,   131,     0,     0,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,    80,     0,     0,     0,    81,     0,     4,     5,     0,
      82,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       0,     0,    25,    26,    27,    28,    29,    30,    31,    32,
      33,     0,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,    80,     0,     0,     0,
      81,     0,     0,     0,     0,    82,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     0,     0,    25,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   160,   161,
     162,     0,    34,     0,     0,     0,   163,   164,     0,     0,
       0,     0,     0,    35,    36,    37,    38,    39,     0,     0,
       0,     0,    44,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,     0,     0,     0,     0,
       0,   137,   138,   139,   140,   141,     0,   142,   143,     0,
      72,   144,   145,     0,     0,     0,   165,   166,   167,   168,
     169,   170,     0,     0,    81,   171,   172,   173,     0,    82,
       0,     0,   146,   147,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   148,   149,   150,   151,   152,   153,   154
};

static const yytype_int16 yycheck[] =
{
       2,    87,    85,    84,     8,    40,    41,     2,   177,     2,
      61,    62,    36,     0,   135,   212,     0,    61,    62,   108,
     183,   111,   112,    36,    36,    36,    98,    36,   100,   118,
     120,   121,   122,   116,     0,   121,   122,    36,    40,    41,
     121,   122,   239,    56,    56,    56,   243,    56,   108,   109,
      85,    98,    87,   100,   108,   109,   108,   109,   118,    81,
     111,   112,   113,   114,   115,   116,   118,   111,   112,   113,
     114,   115,   116,   124,   125,   108,   109,   198,   113,   108,
     109,   116,    84,    85,    36,    87,   121,   122,    36,    84,
      85,    84,    85,   262,   116,   119,    98,    36,   100,   134,
     135,   264,    56,   108,   123,    53,    54,    55,   115,   116,
      56,   113,   116,   118,    56,   198,   197,    36,    36,   121,
     122,   108,   109,    56,   108,   109,   121,   122,   121,   122,
     118,   118,   134,   135,   118,   118,   123,   159,    36,    61,
      62,   163,   164,   165,   166,   167,   168,   169,   170,   116,
      36,    36,   174,   175,    36,    53,    54,    55,    36,    36,
      61,    62,   197,   198,    36,    36,   252,   253,    58,    36,
      36,   119,   120,   121,   122,     5,     4,     7,   118,     9,
      10,   113,   114,   115,   116,     4,     3,    36,     3,    46,
     112,   113,   114,   115,   116,   197,   198,    36,   124,     2,
     155,    -1,   197,   198,   197,   198,   212,    56,    57,    58,
      59,    60,   113,   114,   115,   116,     0,   252,   253,    -1,
      -1,   119,   120,   121,   122,    -1,    -1,    11,    12,    -1,
      -1,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
     252,   253,    36,    37,    38,    39,    40,    41,    42,    43,
      44,   110,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
     119,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,
     114,    -1,    11,    12,    -1,   119,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    -1,    -1,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    52,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    -1,    -1,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,    -1,
      -1,   110,    -1,    -1,    -1,   114,    -1,    11,    12,    -1,
     119,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,    -1,    -1,   110,    -1,    -1,    -1,
     114,    -1,    -1,    -1,    -1,   119,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    -1,    -1,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    54,
      55,    -1,    52,    -1,    -1,    -1,    61,    62,    -1,    -1,
      -1,    -1,    -1,    63,    64,    65,    66,    67,    -1,    -1,
      -1,    -1,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,     9,    10,    -1,
     100,    13,    14,    -1,    -1,    -1,   111,   112,   113,   114,
     115,   116,    -1,    -1,   114,   120,   121,   122,    -1,   119,
      -1,    -1,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,   127,   128,     0,    11,    12,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    52,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,   104,   105,   106,   107,
     110,   114,   119,   129,   134,   135,   138,   139,   140,   141,
     145,   146,   147,   157,   158,   160,   161,   162,   163,   167,
     168,    36,    36,    36,    56,    56,    36,    36,    36,    56,
     153,    56,   154,   135,   160,   160,   135,   145,   157,   108,
     109,   130,   131,   138,   129,   158,   160,    56,    57,    58,
      59,    60,   132,   133,   134,   135,   160,     3,     4,     5,
       6,     7,     9,    10,    13,    14,    34,    35,    45,    46,
      47,    48,    49,    50,    51,   142,   143,   144,   148,   123,
      53,    54,    55,    61,    62,   111,   112,   113,   114,   115,
     116,   120,   121,   122,   155,   156,    36,   135,   155,   156,
     164,   165,    36,   135,   155,   156,   169,   170,   111,   112,
     120,   121,   122,   159,   160,   157,   132,   134,   135,   138,
     160,   132,   138,   118,   118,   118,     8,   116,   116,   132,
     133,   136,   137,   160,   108,   109,   108,   109,    36,    56,
     149,    56,   151,    36,    56,   152,   143,   157,   157,   157,
     157,   157,   157,   157,   157,   157,   157,   157,   165,   166,
      36,    36,   170,   171,    36,    36,    36,   160,    58,    36,
      36,   118,   130,   131,     4,     4,     3,     3,    46,   124,
     125,   118,   131,   118,   131,   132,   132,    36,    56,   150,
      36,   165,   170,   124
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,   126,   127,   127,   128,   129,   129,   129,   129,   129,
     130,   131,   132,   132,   132,   133,   133,   133,   133,   133,
     133,   133,   133,   133,   134,   135,   136,   136,   136,   137,
     137,   138,   138,   139,   139,   139,   139,   139,   139,   140,
     140,   140,   140,   140,   140,   140,   140,   140,   140,   140,
     141,   141,   142,   142,   142,   142,   142,   142,   142,   142,
     142,   142,   143,   143,   143,   143,   144,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   146,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   146,   146,   146,
     147,   147,   147,   147,   147,   147,   148,   148,   148,   148,
     149,   149,   150,   150,   151,   152,   152,   153,   153,   154,
     155,   155,   155,   156,   156,   156,   157,   157,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   159,   159,   159,   159,   159,   160,   160,   161,   161,
     161,   161,   161,   161,   161,   161,   162,   162,   162,   162,
     163,   163,   164,   164,   164,   164,   165,   166,   166,   167,
     167,   167,   168,   168,   168,   168,   169,   169,   169,   169,
     170,   171,   171
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     0,     1,     3,     3,     3,     3,
       1,     1,     1,     1,     3,     1,     3,     3,     1,     3,
       1,     1,     1,     2,     1,     1,     1,     3,     3,     1,
       1,     1,     2,     3,     2,     2,     2,     2,     2,     2,
       3,     1,     3,     3,     1,     1,     1,     2,     1,     2,
       1,     0,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     4,
       1,     1,     2,     1,     2,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     2,     2,     4,     2,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     6,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     2,     3,
       1,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
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
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
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
# undef YYSTACK_RELOCATE
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
  case 2:
#line 307 "./grammar.y"
{
	finish_parse((yyvsp[0].blk).b);
}
#line 2085 "y.tab.c"
    break;

  case 4:
#line 312 "./grammar.y"
                                { (yyval.blk).q = qerr; }
#line 2091 "y.tab.c"
    break;

  case 6:
#line 315 "./grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2097 "y.tab.c"
    break;

  case 7:
#line 316 "./grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2103 "y.tab.c"
    break;

  case 8:
#line 317 "./grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2109 "y.tab.c"
    break;

  case 9:
#line 318 "./grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2115 "y.tab.c"
    break;

  case 10:
#line 320 "./grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2121 "y.tab.c"
    break;

  case 11:
#line 322 "./grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2127 "y.tab.c"
    break;

  case 13:
#line 325 "./grammar.y"
                                { (yyval.blk).b = gen_ncode(NULL, (sfbpf_u_int32)(yyvsp[0].i),
						   (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2134 "y.tab.c"
    break;

  case 14:
#line 327 "./grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2140 "y.tab.c"
    break;

  case 15:
#line 329 "./grammar.y"
                                { (yyval.blk).b = gen_scode((yyvsp[0].s), (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2146 "y.tab.c"
    break;

  case 16:
#line 330 "./grammar.y"
                                { (yyval.blk).b = gen_mcode((yyvsp[-2].s), NULL, (yyvsp[0].i),
				    (yyval.blk).q = (yyvsp[-3].blk).q); }
#line 2153 "y.tab.c"
    break;

  case 17:
#line 332 "./grammar.y"
                                { (yyval.blk).b = gen_mcode((yyvsp[-2].s), (yyvsp[0].s), 0,
				    (yyval.blk).q = (yyvsp[-3].blk).q); }
#line 2160 "y.tab.c"
    break;

  case 18:
#line 334 "./grammar.y"
                                {
				  /* Decide how to parse HID based on proto */
				  (yyval.blk).q = (yyvsp[-1].blk).q;
				  if ((yyval.blk).q.addr == Q_PORT)
				  	bpf_error("'port' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PORTRANGE)
				  	bpf_error("'portrange' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PROTO)
				  	bpf_error("'proto' modifier applied to ip host");
				  else if ((yyval.blk).q.addr == Q_PROTOCHAIN)
				  	bpf_error("'protochain' modifier applied to ip host");
				  (yyval.blk).b = gen_ncode((yyvsp[0].s), 0, (yyval.blk).q);
				}
#line 2178 "y.tab.c"
    break;

  case 19:
#line 347 "./grammar.y"
                                {
#ifdef INET6
				  (yyval.blk).b = gen_mcode6((yyvsp[-2].s), NULL, (yyvsp[0].i),
				    (yyval.blk).q = (yyvsp[-3].blk).q);
#else
				  bpf_error("'ip6addr/prefixlen' not supported "
					"in this configuration");
#endif /*INET6*/
				}
#line 2192 "y.tab.c"
    break;

  case 20:
#line 356 "./grammar.y"
                                {
#ifdef INET6
				  (yyval.blk).b = gen_mcode6((yyvsp[0].s), 0, 128,
				    (yyval.blk).q = (yyvsp[-1].blk).q);
#else
				  bpf_error("'ip6addr' not supported "
					"in this configuration");
#endif /*INET6*/
				}
#line 2206 "y.tab.c"
    break;

  case 21:
#line 365 "./grammar.y"
                                { 
				  (yyval.blk).b = gen_ecode((yyvsp[0].e), (yyval.blk).q = (yyvsp[-1].blk).q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free((yyvsp[0].e));
				}
#line 2220 "y.tab.c"
    break;

  case 22:
#line 374 "./grammar.y"
                                {
				  (yyval.blk).b = gen_acode((yyvsp[0].e), (yyval.blk).q = (yyvsp[-1].blk).q);
				  /*
				   * $1 was allocated by "pcap_ether_aton()",
				   * so we must free it now that we're done
				   * with it.
				   */
				  free((yyvsp[0].e));
				}
#line 2234 "y.tab.c"
    break;

  case 23:
#line 383 "./grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2240 "y.tab.c"
    break;

  case 24:
#line 385 "./grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2246 "y.tab.c"
    break;

  case 25:
#line 387 "./grammar.y"
                                { (yyval.blk) = (yyvsp[-1].blk); }
#line 2252 "y.tab.c"
    break;

  case 27:
#line 390 "./grammar.y"
                                { gen_and((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2258 "y.tab.c"
    break;

  case 28:
#line 391 "./grammar.y"
                                { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2264 "y.tab.c"
    break;

  case 29:
#line 393 "./grammar.y"
                                { (yyval.blk).b = gen_ncode(NULL, (sfbpf_u_int32)(yyvsp[0].i),
						   (yyval.blk).q = (yyvsp[-1].blk).q); }
#line 2271 "y.tab.c"
    break;

  case 32:
#line 398 "./grammar.y"
                                { gen_not((yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 2277 "y.tab.c"
    break;

  case 33:
#line 400 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-2].i), (yyvsp[-1].i), (yyvsp[0].i)); }
#line 2283 "y.tab.c"
    break;

  case 34:
#line 401 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), (yyvsp[0].i), Q_DEFAULT); }
#line 2289 "y.tab.c"
    break;

  case 35:
#line 402 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2295 "y.tab.c"
    break;

  case 36:
#line 403 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTO); }
#line 2301 "y.tab.c"
    break;

  case 37:
#line 404 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, Q_PROTOCHAIN); }
#line 2307 "y.tab.c"
    break;

  case 38:
#line 405 "./grammar.y"
                                { QSET((yyval.blk).q, (yyvsp[-1].i), Q_DEFAULT, (yyvsp[0].i)); }
#line 2313 "y.tab.c"
    break;

  case 39:
#line 407 "./grammar.y"
                                { (yyval.blk) = (yyvsp[0].blk); }
#line 2319 "y.tab.c"
    break;

  case 40:
#line 408 "./grammar.y"
                                { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = (yyvsp[-2].blk).q; }
#line 2325 "y.tab.c"
    break;

  case 41:
#line 409 "./grammar.y"
                                { (yyval.blk).b = gen_proto_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2331 "y.tab.c"
    break;

  case 42:
#line 410 "./grammar.y"
                                { (yyval.blk).b = gen_relation((yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 0);
				  (yyval.blk).q = qerr; }
#line 2338 "y.tab.c"
    break;

  case 43:
#line 412 "./grammar.y"
                                { (yyval.blk).b = gen_relation((yyvsp[-1].i), (yyvsp[-2].a), (yyvsp[0].a), 1);
				  (yyval.blk).q = qerr; }
#line 2345 "y.tab.c"
    break;

  case 44:
#line 414 "./grammar.y"
                                { (yyval.blk).b = (yyvsp[0].rblk); (yyval.blk).q = qerr; }
#line 2351 "y.tab.c"
    break;

  case 45:
#line 415 "./grammar.y"
                                { (yyval.blk).b = gen_atmtype_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2357 "y.tab.c"
    break;

  case 46:
#line 416 "./grammar.y"
                                { (yyval.blk).b = gen_atmmulti_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2363 "y.tab.c"
    break;

  case 47:
#line 417 "./grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2369 "y.tab.c"
    break;

  case 48:
#line 418 "./grammar.y"
                                { (yyval.blk).b = gen_mtp2type_abbrev((yyvsp[0].i)); (yyval.blk).q = qerr; }
#line 2375 "y.tab.c"
    break;

  case 49:
#line 419 "./grammar.y"
                                { (yyval.blk).b = (yyvsp[0].blk).b; (yyval.blk).q = qerr; }
#line 2381 "y.tab.c"
    break;

  case 51:
#line 423 "./grammar.y"
                                { (yyval.i) = Q_DEFAULT; }
#line 2387 "y.tab.c"
    break;

  case 52:
#line 426 "./grammar.y"
                                { (yyval.i) = Q_SRC; }
#line 2393 "y.tab.c"
    break;

  case 53:
#line 427 "./grammar.y"
                                { (yyval.i) = Q_DST; }
#line 2399 "y.tab.c"
    break;

  case 54:
#line 428 "./grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2405 "y.tab.c"
    break;

  case 55:
#line 429 "./grammar.y"
                                { (yyval.i) = Q_OR; }
#line 2411 "y.tab.c"
    break;

  case 56:
#line 430 "./grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2417 "y.tab.c"
    break;

  case 57:
#line 431 "./grammar.y"
                                { (yyval.i) = Q_AND; }
#line 2423 "y.tab.c"
    break;

  case 58:
#line 432 "./grammar.y"
                                { (yyval.i) = Q_ADDR1; }
#line 2429 "y.tab.c"
    break;

  case 59:
#line 433 "./grammar.y"
                                { (yyval.i) = Q_ADDR2; }
#line 2435 "y.tab.c"
    break;

  case 60:
#line 434 "./grammar.y"
                                { (yyval.i) = Q_ADDR3; }
#line 2441 "y.tab.c"
    break;

  case 61:
#line 435 "./grammar.y"
                                { (yyval.i) = Q_ADDR4; }
#line 2447 "y.tab.c"
    break;

  case 62:
#line 438 "./grammar.y"
                                { (yyval.i) = Q_HOST; }
#line 2453 "y.tab.c"
    break;

  case 63:
#line 439 "./grammar.y"
                                { (yyval.i) = Q_NET; }
#line 2459 "y.tab.c"
    break;

  case 64:
#line 440 "./grammar.y"
                                { (yyval.i) = Q_PORT; }
#line 2465 "y.tab.c"
    break;

  case 65:
#line 441 "./grammar.y"
                                { (yyval.i) = Q_PORTRANGE; }
#line 2471 "y.tab.c"
    break;

  case 66:
#line 444 "./grammar.y"
                                { (yyval.i) = Q_GATEWAY; }
#line 2477 "y.tab.c"
    break;

  case 67:
#line 446 "./grammar.y"
                                { (yyval.i) = Q_LINK; }
#line 2483 "y.tab.c"
    break;

  case 68:
#line 447 "./grammar.y"
                                { (yyval.i) = Q_IP; }
#line 2489 "y.tab.c"
    break;

  case 69:
#line 448 "./grammar.y"
                                { (yyval.i) = Q_ARP; }
#line 2495 "y.tab.c"
    break;

  case 70:
#line 449 "./grammar.y"
                                { (yyval.i) = Q_RARP; }
#line 2501 "y.tab.c"
    break;

  case 71:
#line 450 "./grammar.y"
                                { (yyval.i) = Q_SCTP; }
#line 2507 "y.tab.c"
    break;

  case 72:
#line 451 "./grammar.y"
                                { (yyval.i) = Q_TCP; }
#line 2513 "y.tab.c"
    break;

  case 73:
#line 452 "./grammar.y"
                                { (yyval.i) = Q_UDP; }
#line 2519 "y.tab.c"
    break;

  case 74:
#line 453 "./grammar.y"
                                { (yyval.i) = Q_ICMP; }
#line 2525 "y.tab.c"
    break;

  case 75:
#line 454 "./grammar.y"
                                { (yyval.i) = Q_IGMP; }
#line 2531 "y.tab.c"
    break;

  case 76:
#line 455 "./grammar.y"
                                { (yyval.i) = Q_IGRP; }
#line 2537 "y.tab.c"
    break;

  case 77:
#line 456 "./grammar.y"
                                { (yyval.i) = Q_PIM; }
#line 2543 "y.tab.c"
    break;

  case 78:
#line 457 "./grammar.y"
                                { (yyval.i) = Q_VRRP; }
#line 2549 "y.tab.c"
    break;

  case 79:
#line 458 "./grammar.y"
                                { (yyval.i) = Q_ATALK; }
#line 2555 "y.tab.c"
    break;

  case 80:
#line 459 "./grammar.y"
                                { (yyval.i) = Q_AARP; }
#line 2561 "y.tab.c"
    break;

  case 81:
#line 460 "./grammar.y"
                                { (yyval.i) = Q_DECNET; }
#line 2567 "y.tab.c"
    break;

  case 82:
#line 461 "./grammar.y"
                                { (yyval.i) = Q_LAT; }
#line 2573 "y.tab.c"
    break;

  case 83:
#line 462 "./grammar.y"
                                { (yyval.i) = Q_SCA; }
#line 2579 "y.tab.c"
    break;

  case 84:
#line 463 "./grammar.y"
                                { (yyval.i) = Q_MOPDL; }
#line 2585 "y.tab.c"
    break;

  case 85:
#line 464 "./grammar.y"
                                { (yyval.i) = Q_MOPRC; }
#line 2591 "y.tab.c"
    break;

  case 86:
#line 465 "./grammar.y"
                                { (yyval.i) = Q_IPV6; }
#line 2597 "y.tab.c"
    break;

  case 87:
#line 466 "./grammar.y"
                                { (yyval.i) = Q_ICMPV6; }
#line 2603 "y.tab.c"
    break;

  case 88:
#line 467 "./grammar.y"
                                { (yyval.i) = Q_AH; }
#line 2609 "y.tab.c"
    break;

  case 89:
#line 468 "./grammar.y"
                                { (yyval.i) = Q_ESP; }
#line 2615 "y.tab.c"
    break;

  case 90:
#line 469 "./grammar.y"
                                { (yyval.i) = Q_ISO; }
#line 2621 "y.tab.c"
    break;

  case 91:
#line 470 "./grammar.y"
                                { (yyval.i) = Q_ESIS; }
#line 2627 "y.tab.c"
    break;

  case 92:
#line 471 "./grammar.y"
                                { (yyval.i) = Q_ISIS; }
#line 2633 "y.tab.c"
    break;

  case 93:
#line 472 "./grammar.y"
                                { (yyval.i) = Q_ISIS_L1; }
#line 2639 "y.tab.c"
    break;

  case 94:
#line 473 "./grammar.y"
                                { (yyval.i) = Q_ISIS_L2; }
#line 2645 "y.tab.c"
    break;

  case 95:
#line 474 "./grammar.y"
                                { (yyval.i) = Q_ISIS_IIH; }
#line 2651 "y.tab.c"
    break;

  case 96:
#line 475 "./grammar.y"
                                { (yyval.i) = Q_ISIS_LSP; }
#line 2657 "y.tab.c"
    break;

  case 97:
#line 476 "./grammar.y"
                                { (yyval.i) = Q_ISIS_SNP; }
#line 2663 "y.tab.c"
    break;

  case 98:
#line 477 "./grammar.y"
                                { (yyval.i) = Q_ISIS_PSNP; }
#line 2669 "y.tab.c"
    break;

  case 99:
#line 478 "./grammar.y"
                                { (yyval.i) = Q_ISIS_CSNP; }
#line 2675 "y.tab.c"
    break;

  case 100:
#line 479 "./grammar.y"
                                { (yyval.i) = Q_CLNP; }
#line 2681 "y.tab.c"
    break;

  case 101:
#line 480 "./grammar.y"
                                { (yyval.i) = Q_STP; }
#line 2687 "y.tab.c"
    break;

  case 102:
#line 481 "./grammar.y"
                                { (yyval.i) = Q_IPX; }
#line 2693 "y.tab.c"
    break;

  case 103:
#line 482 "./grammar.y"
                                { (yyval.i) = Q_NETBEUI; }
#line 2699 "y.tab.c"
    break;

  case 104:
#line 483 "./grammar.y"
                                { (yyval.i) = Q_RADIO; }
#line 2705 "y.tab.c"
    break;

  case 105:
#line 485 "./grammar.y"
                                { (yyval.rblk) = gen_broadcast((yyvsp[-1].i)); }
#line 2711 "y.tab.c"
    break;

  case 106:
#line 486 "./grammar.y"
                                { (yyval.rblk) = gen_multicast((yyvsp[-1].i)); }
#line 2717 "y.tab.c"
    break;

  case 107:
#line 487 "./grammar.y"
                                { (yyval.rblk) = gen_less((yyvsp[0].i)); }
#line 2723 "y.tab.c"
    break;

  case 108:
#line 488 "./grammar.y"
                                { (yyval.rblk) = gen_greater((yyvsp[0].i)); }
#line 2729 "y.tab.c"
    break;

  case 109:
#line 489 "./grammar.y"
                                { (yyval.rblk) = gen_byteop((yyvsp[-1].i), (yyvsp[-2].i), (yyvsp[0].i)); }
#line 2735 "y.tab.c"
    break;

  case 110:
#line 490 "./grammar.y"
                                { (yyval.rblk) = gen_inbound(0); }
#line 2741 "y.tab.c"
    break;

  case 111:
#line 491 "./grammar.y"
                                { (yyval.rblk) = gen_inbound(1); }
#line 2747 "y.tab.c"
    break;

  case 112:
#line 492 "./grammar.y"
                                { (yyval.rblk) = gen_vlan((yyvsp[0].i)); }
#line 2753 "y.tab.c"
    break;

  case 113:
#line 493 "./grammar.y"
                                { (yyval.rblk) = gen_vlan(-1); }
#line 2759 "y.tab.c"
    break;

  case 114:
#line 494 "./grammar.y"
                                { (yyval.rblk) = gen_mpls((yyvsp[0].i)); }
#line 2765 "y.tab.c"
    break;

  case 115:
#line 495 "./grammar.y"
                                { (yyval.rblk) = gen_mpls(-1); }
#line 2771 "y.tab.c"
    break;

  case 116:
#line 496 "./grammar.y"
                                { (yyval.rblk) = gen_pppoed(); }
#line 2777 "y.tab.c"
    break;

  case 117:
#line 497 "./grammar.y"
                                { (yyval.rblk) = gen_pppoes(); }
#line 2783 "y.tab.c"
    break;

  case 118:
#line 498 "./grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2789 "y.tab.c"
    break;

  case 119:
#line 499 "./grammar.y"
                                { (yyval.rblk) = (yyvsp[0].rblk); }
#line 2795 "y.tab.c"
    break;

  case 120:
#line 502 "./grammar.y"
                                { (yyval.rblk) = gen_pf_ifname((yyvsp[0].s)); }
#line 2801 "y.tab.c"
    break;

  case 121:
#line 503 "./grammar.y"
                                { (yyval.rblk) = gen_pf_ruleset((yyvsp[0].s)); }
#line 2807 "y.tab.c"
    break;

  case 122:
#line 504 "./grammar.y"
                                { (yyval.rblk) = gen_pf_rnr((yyvsp[0].i)); }
#line 2813 "y.tab.c"
    break;

  case 123:
#line 505 "./grammar.y"
                                { (yyval.rblk) = gen_pf_srnr((yyvsp[0].i)); }
#line 2819 "y.tab.c"
    break;

  case 124:
#line 506 "./grammar.y"
                                { (yyval.rblk) = gen_pf_reason((yyvsp[0].i)); }
#line 2825 "y.tab.c"
    break;

  case 125:
#line 507 "./grammar.y"
                                { (yyval.rblk) = gen_pf_action((yyvsp[0].i)); }
#line 2831 "y.tab.c"
    break;

  case 126:
#line 511 "./grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[-2].i) | (yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
#line 2840 "y.tab.c"
    break;

  case 127:
#line 515 "./grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK);
				}
#line 2848 "y.tab.c"
    break;

  case 128:
#line 518 "./grammar.y"
                                { (yyval.rblk) = gen_p80211_type((yyvsp[0].i),
					IEEE80211_FC0_TYPE_MASK |
					IEEE80211_FC0_SUBTYPE_MASK);
				}
#line 2857 "y.tab.c"
    break;

  case 129:
#line 522 "./grammar.y"
                                { (yyval.rblk) = gen_p80211_fcdir((yyvsp[0].i)); }
#line 2863 "y.tab.c"
    break;

  case 131:
#line 526 "./grammar.y"
                                { (yyval.i) = str2tok((yyvsp[0].s), ieee80211_types);
				  if ((yyval.i) == -1)
				  	bpf_error("unknown 802.11 type name");
				}
#line 2872 "y.tab.c"
    break;

  case 133:
#line 533 "./grammar.y"
                                { const struct tok *types = NULL;
				  int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type");
						break;
					}
					if ((yyvsp[(-1) - (1)].i) == ieee80211_type_subtypes[i].type) {
						types = ieee80211_type_subtypes[i].tok;
						break;
					}
				  }

				  (yyval.i) = str2tok((yyvsp[0].s), types);
				  if ((yyval.i) == -1)
					bpf_error("unknown 802.11 subtype name");
				}
#line 2895 "y.tab.c"
    break;

  case 134:
#line 553 "./grammar.y"
                                { int i;
				  for (i = 0;; i++) {
				  	if (ieee80211_type_subtypes[i].tok == NULL) {
				  		/* Ran out of types */
						bpf_error("unknown 802.11 type name");
						break;
					}
					(yyval.i) = str2tok((yyvsp[0].s), ieee80211_type_subtypes[i].tok);
					if ((yyval.i) != -1) {
						(yyval.i) |= ieee80211_type_subtypes[i].type;
						break;
					}
				  }
				}
#line 2914 "y.tab.c"
    break;

  case 136:
#line 570 "./grammar.y"
                                { if (sfbpf_strcasecmp((yyvsp[0].s), "nods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_NODS;
				  else if (sfbpf_strcasecmp((yyvsp[0].s), "tods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_TODS;
				  else if (sfbpf_strcasecmp((yyvsp[0].s), "fromds") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_FROMDS;
				  else if (sfbpf_strcasecmp((yyvsp[0].s), "dstods") == 0)
					(yyval.i) = IEEE80211_FC1_DIR_DSTODS;
				  else
					bpf_error("unknown 802.11 direction");
				}
#line 2930 "y.tab.c"
    break;

  case 137:
#line 583 "./grammar.y"
                                { (yyval.i) = (yyvsp[0].i); }
#line 2936 "y.tab.c"
    break;

  case 138:
#line 584 "./grammar.y"
                                { (yyval.i) = pfreason_to_num((yyvsp[0].s)); }
#line 2942 "y.tab.c"
    break;

  case 139:
#line 587 "./grammar.y"
                                { (yyval.i) = pfaction_to_num((yyvsp[0].s)); }
#line 2948 "y.tab.c"
    break;

  case 140:
#line 590 "./grammar.y"
                                { (yyval.i) = SFBPF_JGT; }
#line 2954 "y.tab.c"
    break;

  case 141:
#line 591 "./grammar.y"
                                { (yyval.i) = SFBPF_JGE; }
#line 2960 "y.tab.c"
    break;

  case 142:
#line 592 "./grammar.y"
                                { (yyval.i) = SFBPF_JEQ; }
#line 2966 "y.tab.c"
    break;

  case 143:
#line 594 "./grammar.y"
                                { (yyval.i) = SFBPF_JGT; }
#line 2972 "y.tab.c"
    break;

  case 144:
#line 595 "./grammar.y"
                                { (yyval.i) = SFBPF_JGE; }
#line 2978 "y.tab.c"
    break;

  case 145:
#line 596 "./grammar.y"
                                { (yyval.i) = SFBPF_JEQ; }
#line 2984 "y.tab.c"
    break;

  case 146:
#line 598 "./grammar.y"
                                { (yyval.a) = gen_loadi((yyvsp[0].i)); }
#line 2990 "y.tab.c"
    break;

  case 148:
#line 601 "./grammar.y"
                                        { (yyval.a) = gen_load((yyvsp[-3].i), (yyvsp[-1].a), 1); }
#line 2996 "y.tab.c"
    break;

  case 149:
#line 602 "./grammar.y"
                                        { (yyval.a) = gen_load((yyvsp[-5].i), (yyvsp[-3].a), (yyvsp[-1].i)); }
#line 3002 "y.tab.c"
    break;

  case 150:
#line 603 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_ADD, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3008 "y.tab.c"
    break;

  case 151:
#line 604 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_SUB, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3014 "y.tab.c"
    break;

  case 152:
#line 605 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_MUL, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3020 "y.tab.c"
    break;

  case 153:
#line 606 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_DIV, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3026 "y.tab.c"
    break;

  case 154:
#line 607 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_AND, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3032 "y.tab.c"
    break;

  case 155:
#line 608 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_OR, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3038 "y.tab.c"
    break;

  case 156:
#line 609 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_LSH, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3044 "y.tab.c"
    break;

  case 157:
#line 610 "./grammar.y"
                                        { (yyval.a) = gen_arth(SFBPF_RSH, (yyvsp[-2].a), (yyvsp[0].a)); }
#line 3050 "y.tab.c"
    break;

  case 158:
#line 611 "./grammar.y"
                                        { (yyval.a) = gen_neg((yyvsp[0].a)); }
#line 3056 "y.tab.c"
    break;

  case 159:
#line 612 "./grammar.y"
                                        { (yyval.a) = (yyvsp[-1].a); }
#line 3062 "y.tab.c"
    break;

  case 160:
#line 613 "./grammar.y"
                                        { (yyval.a) = gen_loadlen(); }
#line 3068 "y.tab.c"
    break;

  case 161:
#line 615 "./grammar.y"
                                { (yyval.i) = '&'; }
#line 3074 "y.tab.c"
    break;

  case 162:
#line 616 "./grammar.y"
                                { (yyval.i) = '|'; }
#line 3080 "y.tab.c"
    break;

  case 163:
#line 617 "./grammar.y"
                                { (yyval.i) = '<'; }
#line 3086 "y.tab.c"
    break;

  case 164:
#line 618 "./grammar.y"
                                { (yyval.i) = '>'; }
#line 3092 "y.tab.c"
    break;

  case 165:
#line 619 "./grammar.y"
                                { (yyval.i) = '='; }
#line 3098 "y.tab.c"
    break;

  case 167:
#line 622 "./grammar.y"
                                { (yyval.i) = (yyvsp[-1].i); }
#line 3104 "y.tab.c"
    break;

  case 168:
#line 624 "./grammar.y"
                                { (yyval.i) = A_LANE; }
#line 3110 "y.tab.c"
    break;

  case 169:
#line 625 "./grammar.y"
                                { (yyval.i) = A_LLC; }
#line 3116 "y.tab.c"
    break;

  case 170:
#line 626 "./grammar.y"
                                { (yyval.i) = A_METAC;	}
#line 3122 "y.tab.c"
    break;

  case 171:
#line 627 "./grammar.y"
                                { (yyval.i) = A_BCC; }
#line 3128 "y.tab.c"
    break;

  case 172:
#line 628 "./grammar.y"
                                { (yyval.i) = A_OAMF4EC; }
#line 3134 "y.tab.c"
    break;

  case 173:
#line 629 "./grammar.y"
                                { (yyval.i) = A_OAMF4SC; }
#line 3140 "y.tab.c"
    break;

  case 174:
#line 630 "./grammar.y"
                                { (yyval.i) = A_SC; }
#line 3146 "y.tab.c"
    break;

  case 175:
#line 631 "./grammar.y"
                                { (yyval.i) = A_ILMIC; }
#line 3152 "y.tab.c"
    break;

  case 176:
#line 633 "./grammar.y"
                                { (yyval.i) = A_OAM; }
#line 3158 "y.tab.c"
    break;

  case 177:
#line 634 "./grammar.y"
                                { (yyval.i) = A_OAMF4; }
#line 3164 "y.tab.c"
    break;

  case 178:
#line 635 "./grammar.y"
                                { (yyval.i) = A_CONNECTMSG; }
#line 3170 "y.tab.c"
    break;

  case 179:
#line 636 "./grammar.y"
                                { (yyval.i) = A_METACONNECT; }
#line 3176 "y.tab.c"
    break;

  case 180:
#line 639 "./grammar.y"
                                { (yyval.blk).atmfieldtype = A_VPI; }
#line 3182 "y.tab.c"
    break;

  case 181:
#line 640 "./grammar.y"
                                { (yyval.blk).atmfieldtype = A_VCI; }
#line 3188 "y.tab.c"
    break;

  case 183:
#line 643 "./grammar.y"
                                { (yyval.blk).b = gen_atmfield_code((yyvsp[-2].blk).atmfieldtype, (sfbpf_int32)(yyvsp[0].i), (sfbpf_u_int32)(yyvsp[-1].i), 0); }
#line 3194 "y.tab.c"
    break;

  case 184:
#line 644 "./grammar.y"
                                { (yyval.blk).b = gen_atmfield_code((yyvsp[-2].blk).atmfieldtype, (sfbpf_int32)(yyvsp[0].i), (sfbpf_u_int32)(yyvsp[-1].i), 1); }
#line 3200 "y.tab.c"
    break;

  case 185:
#line 645 "./grammar.y"
                                 { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3206 "y.tab.c"
    break;

  case 186:
#line 647 "./grammar.y"
                   {
	(yyval.blk).atmfieldtype = (yyvsp[-1].blk).atmfieldtype;
	if ((yyval.blk).atmfieldtype == A_VPI ||
	    (yyval.blk).atmfieldtype == A_VCI)
		(yyval.blk).b = gen_atmfield_code((yyval.blk).atmfieldtype, (sfbpf_int32) (yyvsp[0].i), SFBPF_JEQ, 0);
	}
#line 3217 "y.tab.c"
    break;

  case 188:
#line 655 "./grammar.y"
                                        { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3223 "y.tab.c"
    break;

  case 189:
#line 658 "./grammar.y"
                                { (yyval.i) = M_FISU; }
#line 3229 "y.tab.c"
    break;

  case 190:
#line 659 "./grammar.y"
                                { (yyval.i) = M_LSSU; }
#line 3235 "y.tab.c"
    break;

  case 191:
#line 660 "./grammar.y"
                                { (yyval.i) = M_MSU; }
#line 3241 "y.tab.c"
    break;

  case 192:
#line 663 "./grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SIO; }
#line 3247 "y.tab.c"
    break;

  case 193:
#line 664 "./grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_OPC; }
#line 3253 "y.tab.c"
    break;

  case 194:
#line 665 "./grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_DPC; }
#line 3259 "y.tab.c"
    break;

  case 195:
#line 666 "./grammar.y"
                                { (yyval.blk).mtp3fieldtype = M_SLS; }
#line 3265 "y.tab.c"
    break;

  case 197:
#line 669 "./grammar.y"
                                { (yyval.blk).b = gen_mtp3field_code((yyvsp[-2].blk).mtp3fieldtype, (u_int)(yyvsp[0].i), (u_int)(yyvsp[-1].i), 0); }
#line 3271 "y.tab.c"
    break;

  case 198:
#line 670 "./grammar.y"
                                { (yyval.blk).b = gen_mtp3field_code((yyvsp[-2].blk).mtp3fieldtype, (u_int)(yyvsp[0].i), (u_int)(yyvsp[-1].i), 1); }
#line 3277 "y.tab.c"
    break;

  case 199:
#line 671 "./grammar.y"
                                  { (yyval.blk).b = (yyvsp[-1].blk).b; (yyval.blk).q = qerr; }
#line 3283 "y.tab.c"
    break;

  case 200:
#line 673 "./grammar.y"
                    {
	(yyval.blk).mtp3fieldtype = (yyvsp[-1].blk).mtp3fieldtype;
	if ((yyval.blk).mtp3fieldtype == M_SIO ||
	    (yyval.blk).mtp3fieldtype == M_OPC ||
	    (yyval.blk).mtp3fieldtype == M_DPC ||
	    (yyval.blk).mtp3fieldtype == M_SLS )
		(yyval.blk).b = gen_mtp3field_code((yyval.blk).mtp3fieldtype, (u_int) (yyvsp[0].i), SFBPF_JEQ, 0);
	}
#line 3296 "y.tab.c"
    break;

  case 202:
#line 683 "./grammar.y"
                                          { gen_or((yyvsp[-2].blk).b, (yyvsp[0].blk).b); (yyval.blk) = (yyvsp[0].blk); }
#line 3302 "y.tab.c"
    break;


#line 3306 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

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
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
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
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 685 "./grammar.y"

