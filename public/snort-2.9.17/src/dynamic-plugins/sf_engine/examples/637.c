/*
 * VRT RULES
 *
 * Copyright (C) 2014-2020 Cisco and/or its affiliates. All rights reserved.
 * Copyright (C) 2005-2013 Sourcefire, Inc.
 *
 * This file is autogenerated via rules2c, by Brian Caswell <bmc@sourcefire.com>
 */


#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "sf_snort_plugin_api.h"
#include "sf_snort_packet.h"


/* declare detection functions */
int rule637eval(void *p);

/* declare rule data structures */
/* precompile the stuff that needs pre-compiled */
// content:"|0A|help|0A|quite|0A|";
static ContentInfo rule637content0 =
{
    (u_int8_t *)("|0A|help|0A|quite|0A|"), /* pattern (now in snort content format) */
    0, /* depth */
    0, /* offset */
    CONTENT_BUF_NORMALIZED, /* flags */ // XXX - need to add CONTENT_FAST_PATTERN support
    NULL, /* holder for boyer/moore PTR */
    NULL, /* more holder info - byteform */
    0, /* byteform length */
    0, /* increment length*/
    0,                      /* holder for fp offset */
    0,                      /* holder for fp length */
    0,                      /* holder for fp only */
    NULL, // offset_refId
    NULL, // depth_refId
    NULL, // offset_location
    NULL  // depth_location
};

static RuleOption rule637option0 =
{
    OPTION_TYPE_CONTENT,
    { &rule637content0 }
};

/* references for sid 637 */
/* reference: arachnids "308"; */
static RuleReference rule637ref1 =
{
    "arachnids", /* type */
    "308" /* value */
};

static RuleReference *rule637refs[] =
{
    &rule637ref1,
    NULL
};
RuleOption *rule637options[] =
{
    &rule637option0,
    NULL
};

Rule rule637 = {

   /* rule header, akin to => tcp any any -> any any               */{
       IPPROTO_UDP, /* proto */
       "$EXTERNAL_NET", /* SRCIP     */
       "any", /* SRCPORT   */
       1, /* DIRECTION */
       "$HOME_NET", /* DSTIP     */
       "any", /* DSTPORT   */
   },
   /* metadata */
   {
       3,  /* genid (HARDCODED!!!) */
       637, /* sigid */
       3, /* revision */

       "attempted-recon", /* classification */
       0,  /* hardcoded priority XXX NOT PROVIDED BY GRAMMAR YET! */
       "SCAN Webtrends Scanner UDP Probe",     /* message */
       rule637refs, /* ptr to references */
       NULL /* Meta data */
   },
   rule637options, /* ptr to rule options */
   NULL, // &rule637eval, /* use the built in detection function */
   0, /* am I initialized yet? */
   0, /* num options */
   0, /* no alert */
   NULL /* ptr to internal data... setup during rule registration */
};


/* detection functions */
int rule637eval(void *p) {
    //const u_int8_t *cursor_uri = 0;
    //const u_int8_t *cursor_raw = 0;
    const u_int8_t *cursor_normal = 0;


    // content:"|0A|help|0A|quite|0A|";
    if (contentMatch(p, rule637options[0]->option_u.content, &cursor_normal) > 0) {
        return RULE_MATCH;
    }
    return RULE_NOMATCH;
}
