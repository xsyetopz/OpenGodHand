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
typedef int DItype __attribute__ ((mode (DI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
#define INLINE __inline__
#define NGARDS 8L
#define EXPBITS 11
#define FRACBITS 52
#define FRAC_NBITS 64
typedef UDItype fractype;
typedef USItype halffractype;
typedef DFtype FLO_type;
typedef DItype intfrac;
#define LSHIFT(a) { a = (a & 1) | (a >> 1); }
#define IMPLICIT_1 (1LL<<(FRACBITS+NGARDS))
#define IMPLICIT_2 (1LL<<(FRACBITS+1+NGARDS))
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct { fp_class_type class; unsigned int sign; int normal_exp; union { fractype ll; halffractype l[2]; } fraction; } fp_number_type;
typedef union { FLO_type value; fractype value_raw; halffractype words[2]; struct { fractype fraction:FRACBITS __attribute__ ((packed)); unsigned int exp:EXPBITS __attribute__ ((packed)); unsigned int sign:1 __attribute__ ((packed)); } bits; } FLO_union_type;

#define pack_d func_0031DE78
#define unpack_d func_0031DFA8
#define add func_0031E288
#define sub func_0031E2E0
#define _fpadd_parts func_0031E048
extern fp_number_type D_00755BD0; /* the static `thenan` of nan () */
INLINE static fp_number_type * nan () { return &D_00755BD0; }
INLINE static int isnan (fp_number_type * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf (fp_number_type * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero (fp_number_type * x) { return x->class == CLASS_ZERO; }

extern FLO_type pack_d (fp_number_type *);
extern void unpack_d (FLO_union_type *, fp_number_type *);
#define ALIAS(n, a) __asm__ (".globl " #n "\n\t" #n " = " #a)
ALIAS (dpadd, func_0031E288);
ALIAS (dpsub, func_0031E2E0);

// FUNCTION: GAME 0x31E048
fp_number_type *
_fpadd_parts (fp_number_type * a,
	      fp_number_type * b,
	      fp_number_type * tmp)
{
  intfrac tfraction;
  int a_normal_exp;
  int b_normal_exp;
  fractype a_fraction;
  fractype b_fraction;
  if (isnan (a))
    {
      return a;
    }
  if (isnan (b))
    {
      return b;
    }
  if (isinf (a))
    {
      if (isinf (b) && a->sign != b->sign)
	return nan ();
      return a;
    }
  if (isinf (b))
    {
      return b;
    }
  if (iszero (b))
    {
      if (iszero (a))
	{
	  *tmp = *a;
	  tmp->sign = a->sign & b->sign;
	  return tmp;
	}
      return a;
    }
  if (iszero (a))
    {
      return b;
    }
  {
    int diff;
    a_normal_exp = a->normal_exp;
    b_normal_exp = b->normal_exp;
    a_fraction = a->fraction.ll;
    b_fraction = b->fraction.ll;
    diff = a_normal_exp - b_normal_exp;
    if (diff < 0)
      diff = -diff;
    if (diff < FRAC_NBITS)
      {
	while (a_normal_exp > b_normal_exp)
	  {
	    b_normal_exp++;
	    LSHIFT (b_fraction);
	  }
	while (b_normal_exp > a_normal_exp)
	  {
	    a_normal_exp++;
	    LSHIFT (a_fraction);
	  }
      }
    else
      {
	if (a_normal_exp > b_normal_exp)
	  {
	    b_normal_exp = a_normal_exp;
	    b_fraction = 0;
	  }
	else
	  {
	    a_normal_exp = b_normal_exp;
	    a_fraction = 0;
	  }
      }
  }
  if (a->sign != b->sign)
    {
      if (a->sign)
	{
	  tfraction = -a_fraction + b_fraction;
	}
      else
	{
	  tfraction = a_fraction - b_fraction;
	}
      if (tfraction >= 0)
	{
	  tmp->sign = 0;
	  tmp->normal_exp = a_normal_exp;
	  tmp->fraction.ll = tfraction;
	}
      else
	{
	  tmp->sign = 1;
	  tmp->normal_exp = a_normal_exp;
	  tmp->fraction.ll = -tfraction;
	}
      while (tmp->fraction.ll < IMPLICIT_1 && tmp->fraction.ll)
	{
	  tmp->fraction.ll <<= 1;
	  tmp->normal_exp--;
	}
    }
  else
    {
      tmp->sign = a->sign;
      tmp->normal_exp = a_normal_exp;
      tmp->fraction.ll = a_fraction + b_fraction;
    }
  tmp->class = CLASS_NUMBER;
  if (tmp->fraction.ll >= IMPLICIT_2)
    {
      LSHIFT (tmp->fraction.ll);
      tmp->normal_exp++;
    }
  return tmp;
}

// FUNCTION: GAME 0x31E288
FLO_type
add (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);
  res = _fpadd_parts (&a, &b, &tmp);
  return pack_d (res);
}

// FUNCTION: GAME 0x31E2E0
FLO_type
sub (FLO_type arg_a, FLO_type arg_b)
{
  fp_number_type a;
  fp_number_type b;
  fp_number_type tmp;
  fp_number_type *res;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  unpack_d ((FLO_union_type *) & arg_b, &b);
  b.sign ^= 1;
  res = _fpadd_parts (&a, &b, &tmp);
  return pack_d (res);
}

