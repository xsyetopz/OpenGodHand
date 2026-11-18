// COMPILER: ee-gcc2.9-991111
/* Software floating point and DImode conversions linked into the game.
   Derived from fp-bit.c and libgcc2.c of GCC 2.95.2
   (https://ftp.gnu.org/gnu/gcc/gcc-2.95.2/), built with the US_SOFTWARE_GOFAST
   names and FLOAT_BIT_ORDER_MISMATCH. Only the routines needed here appear.

   Copyright (C) 1994, 1995, 1996, 1997, 1998 Free Software Foundation, Inc.

   This file is free software; you can redistribute it and/or modify it under
   the terms of the GNU General Public License as published by the Free
   Software Foundation; either version 2, or (at your option) any later
   version.

   In addition to the permissions in the GNU General Public License, the Free
   Software Foundation gives you unlimited permission to link the compiled
   version of this file with other programs, and to distribute those programs
   without any restriction coming from the use of this file.  (The General
   Public License restrictions do apply in other respects; for example, they
   cover modification of the file, and distribution when not linked into
   another program.)

   This file is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
   FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
   more details.

   You should have received a copy of the GNU General Public License along
   with this program; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
   USA.  */

typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
typedef unsigned int UHItype __attribute__ ((mode (HI)));

#define MAX_USI_INT ((USItype) ~0)
#define BITS_PER_UNIT 8

/* Names the compiler emits for the helpers defined elsewhere in this unit
   range, mapped to the original symbols. */
#define ALIAS(n, a) __asm__ (".globl " #n "\n\t" #n " = " #a)
ALIAS (__pack_d, func_0031DE78);
ALIAS (__unpack_d, func_0031DFA8);
ALIAS (dpadd, func_0031E288);
ALIAS (dpsub, func_0031E2E0);
ALIAS (dpmul, func_0031E348);
ALIAS (dpcmp, func_0031E870);
ALIAS (litodp, func_0031E8C0);
ALIAS (dptoul, func_0031EA10);
ALIAS (dptofp, func_0031EAE0);
ALIAS (__unpack_f, func_0031EC48);
ALIAS (fptodp, func_0031EDD0);
ALIAS (__floatdidf, func_0031DC98);
ALIAS (__fixunssfdi, func_0031DBA0);

#define NGARDS 8L
#define GARDROUND 0x7f
#define GARDMASK 0xff
#define GARDMSB 0x80
#define FRACBITS 52
#define IMPLICIT_1 (1LL << (FRACBITS + NGARDS))

typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;

typedef struct
{
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union { UDItype ll; USItype l[2]; } fraction;
} fp_number_type;

typedef union
{
  DFtype value;
  UDItype value_raw;
} FLO_union_type;

extern fp_number_type D_00755BD0; /* the static `thenan` of nan () */
extern void __unpack_d (FLO_union_type *, fp_number_type *);
extern DFtype __pack_d (fp_number_type *);

#define INLINE __inline__

INLINE static fp_number_type * nan () { return &D_00755BD0; }
INLINE static int isnan (fp_number_type * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf (fp_number_type * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero (fp_number_type * x) { return x->class == CLASS_ZERO; }

static __inline__ fp_number_type *
_fpdiv_parts (fp_number_type * a, fp_number_type * b)
{
  UDItype bit;
  UDItype numerator;
  UDItype denominator;
  UDItype quotient;

  if (isnan (a))
    return a;
  if (isnan (b))
    return b;

  a->sign = a->sign ^ b->sign;

  if (isinf (a) || iszero (a))
    {
      if (a->class == b->class)
	return nan ();
      return a;
    }

  if (isinf (b))
    {
      a->fraction.ll = 0;
      a->normal_exp = 0;
      return a;
    }
  if (iszero (b))
    {
      a->class = CLASS_INFINITY;
      return a;
    }

  {
    a->normal_exp = a->normal_exp - b->normal_exp;
    numerator = a->fraction.ll;
    denominator = b->fraction.ll;

    if (numerator < denominator)
      {
	numerator *= 2;
	a->normal_exp--;
      }
    bit = IMPLICIT_1;
    quotient = 0;
    while (bit)
      {
	if (numerator >= denominator)
	  {
	    quotient |= bit;
	    numerator -= denominator;
	  }
	bit >>= 1;
	numerator *= 2;
      }

    if ((quotient & GARDMASK) == GARDMSB)
      {
	if (quotient & (1 << NGARDS))
	  quotient += GARDROUND + 1;
	else if (numerator)
	  quotient += GARDROUND + 1;
      }

    a->fraction.ll = quotient;
    return (a);
  }
}

// FUNCTION: GAME 0x31E5F0
DFtype
func_0031E5F0 (DFtype arg_a, DFtype arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type *res;

  __unpack_d ((FLO_union_type *) & arg_a, &a);
  __unpack_d ((FLO_union_type *) & arg_b, &b);

  res = _fpdiv_parts (&a, &b);

  return __pack_d (res);
}

#define WORD_SIZE (sizeof (SItype) * BITS_PER_UNIT)
#define HIGH_WORD_COEFF (((UDItype) 1) << WORD_SIZE)
#define HIGH_HALFWORD_COEFF (((UDItype) 1) << (WORD_SIZE / 2))

/* Single precision: unpack_d is __unpack_f with a 32-bit fraction. */
#undef NGARDS
#undef FRACBITS
#define NGARDS 7L
#define FRACBITS 23

typedef struct
{
  fp_class_type class;
  unsigned int sign;
  int normal_exp;
  union { USItype ll; UHItype l[2]; } fraction;
} fp_number_type_f;

typedef union
{
  SFtype value;
  USItype value_raw;
} FLO_union_type_f;

extern void __unpack_f (FLO_union_type_f *, fp_number_type_f *);

INLINE static int isnan_f (fp_number_type_f * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf_f (fp_number_type_f * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero_f (fp_number_type_f * x) { return x->class == CLASS_ZERO; }
// FUNCTION: GAME 0x31ED08
USItype
func_0031ED08 (SFtype arg_a)
{
  fp_number_type_f a;

  __unpack_f ((FLO_union_type_f *) & arg_a, &a);
  if (iszero_f (&a))
    return 0;
  if (isnan_f (&a))
    return 0;
  if (a.sign)
    return 0;
  if (isinf_f (&a))
    return MAX_USI_INT;
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 31)
    return MAX_USI_INT;
  else if (a.normal_exp > (FRACBITS + NGARDS))
    return a.fraction.ll << (a.normal_exp - (FRACBITS + NGARDS));
  else
    return a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
}

#define DI_SIZE (sizeof (DItype) * BITS_PER_UNIT)
#define DF_SIZE 53
#define SF_SIZE 24

// FUNCTION: GAME 0x31DBA0
DItype
func_0031DBA0 (SFtype original_a)
{
  DFtype a = original_a;
  DFtype b;
  UDItype v;

  if (a < 0)
    return 0;

  b = (a / HIGH_WORD_COEFF);
  v = (USItype) b;
  v <<= WORD_SIZE;
  a -= (DFtype)v;
  if (a < 0)
    v -= (USItype) (- a);
  else
    v += (USItype) a;
  return v;
}

// FUNCTION: GAME 0x31DC98
DFtype
func_0031DC98 (DItype u)
{
  DFtype d;

  d = (SItype) (u >> WORD_SIZE);
  d *= HIGH_HALFWORD_COEFF;
  d *= HIGH_HALFWORD_COEFF;
  d += (USItype) (u & (HIGH_WORD_COEFF - 1));

  return d;
}

// FUNCTION: GAME 0x31DD30
SFtype
func_0031DD30 (DItype u)
{
  DFtype f;

  if (DF_SIZE < DI_SIZE
      && DF_SIZE > (DI_SIZE - DF_SIZE + SF_SIZE))
    {
#define REP_BIT ((USItype) 1 << (DI_SIZE - DF_SIZE))
      if (! (- ((DItype) 1 << DF_SIZE) < u
	     && u < ((DItype) 1 << DF_SIZE)))
	{
	  if ((USItype) u & (REP_BIT - 1))
	    u |= REP_BIT;
	}
    }
  f = (SItype) (u >> WORD_SIZE);
  f *= HIGH_HALFWORD_COEFF;
  f *= HIGH_HALFWORD_COEFF;
  f += (USItype) (u & (HIGH_WORD_COEFF - 1));

  return (SFtype) f;
}
