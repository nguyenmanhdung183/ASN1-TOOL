import os

# Create directory
os.makedirs("templates", exist_ok=True)

files = {
    "integer_no_ext.h.j2": r'''/* e2ap_{{name}}.h */
typedef {{type}} e2ap_{{name}};

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value);
EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue);
EXTERN void asn1Print_e2ap_{{name}} (const char* name, const e2ap_{{name}}* pvalue);
EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_{{name}} (OSCTXT* pctxt, const char* name, const e2ap_{{name}}* pvalue);
''',

    "integer_no_ext.c.j2": r'''/* e2ap_{{name}}.c */
#include "e2ap_{{name}}.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   stat = pe_ConsUnsigned (pctxt, value, {{min}}, {{max}});
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   if (pctxt->buffer.aligned) {
      int stat2 = pd_ByteAlign (pctxt);
      if (stat2 != 0) return LOG_RTERR (pctxt, stat2);
   }
   stat = rtxDecBitsToByte (pctxt, pvalue, {{bits}});
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
''',

    "integer_with_ext.h.j2": r'''/* e2ap_{{name}}.h */
typedef OSUINT32 e2ap_{{name}};

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value);
EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue);
EXTERN void asn1Print_e2ap_{{name}} (const char* name, const e2ap_{{name}}* pvalue);
EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize);
EXTERN int asn1PrtToStrm_e2ap_{{name}} (OSCTXT* pctxt, const char* name, const e2ap_{{name}}* pvalue);
''',

    "integer_with_ext.c.j2": r'''/* e2ap_{{name}}.c */
#include "e2ap_{{name}}.h"
#include "rtxsrc/rtxErrCodes.h"

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value)
{
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   OSBOOL exbit = (value > {{max_root}}) ? TRUE : FALSE;
   int stat = rtxEncBit (pctxt, exbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!exbit) {
      stat = pe_ConsUnsigned (pctxt, value, {{min_root}}, {{max_root}});
   } else {
      stat = pe_UnconsUnsigned (pctxt, value);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue)
{
   int stat = 0;
   OSBOOL extbit = FALSE;
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   stat = rtxDecBit (pctxt, &extbit);
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   if (!extbit) {
      stat = pd_ConsUnsigned (pctxt, pvalue, {{min_root}}, {{max_root}});
   } else {
      stat = pd_UnconsUnsigned (pctxt, pvalue);
   }
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return 0;
}

EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize)
{
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToStringUnsigned (name, *pvalue, buffer, bufSize) < 0) return -1;
   return 0;
}
''',

    "enumerated.h.j2": r'''/* e2ap_{{name}}.h */
typedef enum {
{% for item in items %}
   e2ap_{{name}}_{{item.name}} = {{item.value}}{% if not loop.last %},{% endif %}
{% endfor %}
} e2ap_{{name}};

#define e2ap_{{name}}_ENUMTABSIZE {{items|length}}
extern const OSUTF8CHAR* const e2ap_{{name}}_ENUMTAB[e2ap_{{name}}_ENUMTABSIZE];

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value);
EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue);
EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize);
''',

    "enumerated.c.j2": r'''/* e2ap_{{name}}.c */
#include "e2ap_{{name}}.h"
#include "rtxsrc/rtxErrCodes.h"

const OSUTF8CHAR* const e2ap_{{name}}_ENUMTAB[e2ap_{{name}}_ENUMTABSIZE] = {
{% for item in items %}
   (OSUTF8CHAR*)"{{item.string}}"{% if not loop.last %},{% endif %}
{% endfor %}
};

EXTERN int asn1PE_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}} value)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   if (value >= {{items|length}}) {
      rtxErrAddIntParm (pctxt, value);
      return LOG_RTERR (pctxt, RTERR_INVENUM);
   }
   stat = pe_ConsUnsigned (pctxt, value, 0, OSUINTCONST({{items|length - 1}}));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PD_e2ap_{{name}} (OSCTXT* pctxt, e2ap_{{name}}* pvalue)
{
   int stat = 0;
   RTXCTXPUSHTYPENAME (pctxt, "{{name}}");
   stat = pd_ConsUnsigned (pctxt, pvalue, 0, OSUINTCONST({{items|length - 1}}));
   if (stat != 0) return LOG_RTERR (pctxt, stat);
   RTXCTXPOPEXTNAME (pctxt);
   return stat;
}

EXTERN int asn1PrtToStr_e2ap_{{name}} (const char* name, e2ap_{{name}}* pvalue, char* buffer, OSSIZE bufSize)
{
   int stat;
   if (rtPrintToStringIndent (buffer, bufSize) < 0) return -1;
   if (rtPrintToString (name, buffer, bufSize) < 0) return -1;
   switch (*pvalue) {
{% for item in items %}
      case {{item.value}}:
         stat = rtPrintToString (" = {{item.string}}\n", buffer, bufSize);
         break;
{% endfor %}
      default:
         stat = rtPrintToString (" = ???\n", buffer, bufSize);
   }
   return (stat < 0) ? -1 : 0;
}
'''
}

# Write each file
for filename, content in files.items():
    path = os.path.join("templates", filename)
    with open(path, "w", encoding="utf-8") as f:
        f.write(content)

print("All template files have been generated successfully!")
