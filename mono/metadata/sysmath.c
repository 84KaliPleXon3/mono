/* math.c - these are based on bob smith's csharp routines */

#define __USE_ISOC99
#include <math.h>
#include <mono/metadata/sysmath.h>

#ifndef NAN
# if G_BYTE_ORDER == G_BIG_ENDIAN
#  define __nan_bytes           { 0x7f, 0xc0, 0, 0 }
# endif
# if G_BYTE_ORDER == G_LITTLE_ENDIAN
#  define __nan_bytes           { 0, 0, 0xc0, 0x7f }
# endif

static union { unsigned char __c[4]; float __d; } __nan_union = { __nan_bytes };
# define NAN    (__nan_union.__d)
#endif

#ifndef HUGE_VAL
#define __huge_val_t   union { unsigned char __c[8]; double __d; }
# if G_BYTE_ORDER == G_BIG_ENDIAN
#  define __HUGE_VAL_bytes       { 0x7f, 0xf0, 0, 0, 0, 0, 0, 0 }
# endif
# if G_BYTE_ORDER == G_LITTLE_ENDIAN
#  define __HUGE_VAL_bytes       { 0, 0, 0, 0, 0, 0, 0xf0, 0x7f }
# endif
static __huge_val_t __huge_val = { __HUGE_VAL_bytes };
#  define HUGE_VAL      (__huge_val.__d)
#endif

gdouble 
ves_icall_System_Math_Sin (gdouble x)
{
	return sin (x);
}

gdouble 
ves_icall_System_Math_Cos (gdouble x)
{
	return cos (x);
}

gdouble 
ves_icall_System_Math_Tan (gdouble x)
{
	return tan (x);
}

gdouble 
ves_icall_System_Math_Sinh (gdouble x)
{
	return sinh (x);
}

gdouble 
ves_icall_System_Math_Cosh (gdouble x)
{
	return cosh (x);
}

gdouble 
ves_icall_System_Math_Tanh (gdouble x)
{
	return tanh (x);
}

gdouble 
ves_icall_System_Math_Acos (gdouble x)
{
	if (x < -1 || x > 1)
		return NAN;

	return acos (x);
}

gdouble 
ves_icall_System_Math_Asin (gdouble x)
{
	if (x < -1 || x > 1)
		return NAN;

	return asin (x);
}

gdouble 
ves_icall_System_Math_Atan (gdouble x)
{
	return atan (x);
}

gdouble 
ves_icall_System_Math_Atan2 (gdouble y, gdouble x)
{
	return atan2 (y, x);
}

gdouble 
ves_icall_System_Math_Exp (gdouble x)
{
	return exp (x);
}

gdouble 
ves_icall_System_Math_Log (gdouble x)
{
	if (x == 0)
		return -HUGE_VAL;
	else if (x < 0)
		return NAN;

	return log (x);
}

gdouble 
ves_icall_System_Math_Log10 (gdouble x)
{
	if (x == 0)
		return -HUGE_VAL;
	else if (x < 0)
		return NAN;

	return log10 (x);
}

gdouble 
ves_icall_System_Math_Pow (gdouble x, gdouble y)
{
	return pow (x, y);
}

gdouble 
ves_icall_System_Math_Sqrt (gdouble x)
{
	if (x < 0)
		return NAN;

	return sqrt (x);
}
