// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2 -G0 -msoft-float -ffunction-sections -fno-common
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

typedef float DFtype __attribute__ ((mode (DF)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
#define INLINE __inline__
#define CMPtype int
#define NGARDS 8L
#define GARDROUND 0x7f
#define GARDMASK  0xff
#define GARDMSB   0x80
#define EXPBITS 11
#define FRACBITS 52
#define FRACHIGH  0x8000000000000000LL
typedef UDItype fractype;
typedef USItype halffractype;
typedef DFtype FLO_type;
#define IMPLICIT_1 (1LL<<(FRACBITS+NGARDS))
#define IMPLICIT_2 (1LL<<(FRACBITS+1+NGARDS))
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct { fp_class_type class; unsigned int sign; int normal_exp; union { fractype ll; halffractype l[2]; } fraction; } fp_number_type;
typedef union { FLO_type value; fractype value_raw; halffractype words[2]; struct { fractype fraction:FRACBITS __attribute__ ((packed)); unsigned int exp:EXPBITS __attribute__ ((packed)); unsigned int sign:1 __attribute__ ((packed)); } bits; } FLO_union_type;

#define pack_d func_0031DE78
#define unpack_d func_0031DFA8
#define multiply func_0031E348
#define __fpcmp_parts func_0031E758
#define compare func_0031E870
extern fp_number_type D_00755BD0; /* the static `thenan` of nan () */
INLINE static fp_number_type * nan () { return &D_00755BD0; }
INLINE static int isnan (fp_number_type * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf (fp_number_type * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero (fp_number_type * x) { return x->class == CLASS_ZERO; }

extern FLO_type pack_d (fp_number_type *);
extern void unpack_d (FLO_union_type *, fp_number_type *);
#define ALIAS(n, a) __asm__ (".globl " #n "\n\t" #n " = " #a)
ALIAS (dpmul, func_0031E348);
ALIAS (dpcmp, func_0031E870);

static INLINE fp_number_type *
_fpmul_parts ( fp_number_type *  a,
	       fp_number_type *  b,
	       fp_number_type * tmp)
{
  fractype low = 0;
  fractype high = 0;
  if (isnan (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isnan (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }
  if (isinf (a))
    {
      if (iszero (b))
	return nan ();
      a->sign = a->sign != b->sign;
      return a;
    }
  if (isinf (b))
    {
      if (iszero (a))
	{
	  return nan ();
	}
      b->sign = a->sign != b->sign;
      return b;
    }
  if (iszero (a))
    {
      a->sign = a->sign != b->sign;
      return a;
    }
  if (iszero (b))
    {
      b->sign = a->sign != b->sign;
      return b;
    }
  {
    {
      UDItype nl = a->fraction.ll & 0xffffffff;
      UDItype nh = a->fraction.ll >> 32;
      UDItype ml = b->fraction.ll & 0xffffffff;
      UDItype mh = b->fraction.ll >>32;
      UDItype pp_ll = ml * nl;
      UDItype pp_hl = mh * nl;
      UDItype pp_lh = ml * nh;
      UDItype pp_hh = mh * nh;
      UDItype res2 = 0;
      UDItype res0 = 0;
      UDItype ps_hh__ = pp_hl + pp_lh;
      if (ps_hh__ < pp_hl)
	res2 += 0x100000000LL;
      pp_hl = (ps_hh__ << 32) & 0xffffffff00000000LL;
      res0 = pp_ll + pp_hl;
      if (res0 < pp_ll)
	res2++;
      res2 += ((ps_hh__ >> 32) & 0xffffffffL) + pp_hh;
      high = res2;
      low = res0;
    }
  }
  tmp->normal_exp = a->normal_exp + b->normal_exp;
  tmp->sign = a->sign != b->sign;
  tmp->normal_exp += 4;
  while (high >= IMPLICIT_2)
    {
      tmp->normal_exp++;
      if (high & 1)
	{
	  low >>= 1;
	  low |= FRACHIGH;
	}
      high >>= 1;
    }
  while (high < IMPLICIT_1)
    {
      tmp->normal_exp--;
      high <<= 1;
      if (low & FRACHIGH)
	high |= 1;
      low <<= 1;
    }
  if ((high & GARDMASK) == GARDMSB)
    {
      if (high & (1 << NGARDS))
	{
	  high += GARDROUND + 1;
	}
      else if (low)
	{
	  high += GARDROUND + 1;
	}
    }
  tmp->fraction.ll = high;
  tmp->class = CLASS_NUMBER;
  return tmp;
}

// FUNCTION: GAME 0x31E348
FLO_type
multiply (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);
  res = _fpmul_parts (&a, &b, &tmp);
  return pack_d (res);
}

// FUNCTION: GAME 0x31E758
int
__fpcmp_parts (fp_number_type * a, fp_number_type * b)
{
  if (isnan (a) || isnan (b))
    {
      return 1;
    }
  if (isinf (a) && isinf (b))
    {
      return b->sign - a->sign;
    }
  if (isinf (a))
    {
      return a->sign ? -1 : 1;
    }
  if (isinf (b))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (a) && iszero (b))
    {
      return 0;
    }
  if (iszero (a))
    {
      return b->sign ? 1 : -1;
    }
  if (iszero (b))
    {
      return a->sign ? -1 : 1;
    }
  if (a->sign != b->sign)
    {
      return a->sign ? -1 : 1;
    }
  if (a->normal_exp > b->normal_exp)
    {
      return a->sign ? -1 : 1;
    }
  if (a->normal_exp < b->normal_exp)
    {
      return a->sign ? 1 : -1;
    }
  if (a->fraction.ll > b->fraction.ll)
    {
      return a->sign ? -1 : 1;
    }
  if (a->fraction.ll < b->fraction.ll)
    {
      return a->sign ? 1 : -1;
    }
  return 0;
}

// FUNCTION: GAME 0x31E870
CMPtype
compare (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);
  return __fpcmp_parts (&a, &b);
}

