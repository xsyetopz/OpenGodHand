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

typedef float SFtype __attribute__ ((mode (SF)));
typedef float DFtype __attribute__ ((mode (DF)));
typedef int SItype __attribute__ ((mode (SI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
#define INLINE __inline__
#define F_D_BITOFF (52+8-(23+7))
#define MAX_SI_INT ((int) ((unsigned) (~0)>>1))
#define MAX_USI_INT ((USItype) ~0)
#define NGARDS 8L
#define GARDROUND 0x7f
#define GARDMASK  0xff
#define GARDMSB   0x80
#define EXPBITS 11
#define EXPBIAS 1023
#define FRACBITS 52
#define EXPMAX (0x7ff)
#define QUIET_NAN 0x8000000000000LL
#define FRAC_NBITS 64
typedef UDItype fractype;
typedef USItype halffractype;
typedef DFtype FLO_type;
#define NORMAL_EXPMIN (-(EXPBIAS)+1)
#define IMPLICIT_2 (1LL<<(FRACBITS+1+NGARDS))
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct { fp_class_type class; unsigned int sign; int normal_exp; union { fractype ll; halffractype l[2]; } fraction; } fp_number_type;
typedef union { FLO_type value; fractype value_raw; halffractype words[2]; struct { fractype fraction:FRACBITS __attribute__ ((packed)); unsigned int exp:EXPBITS __attribute__ ((packed)); unsigned int sign:1 __attribute__ ((packed)); } bits; } FLO_union_type;

#define pack_d func_0031DE78
#define unpack_d func_0031DFA8
#define si_to_float func_0031E8C0
#define float_to_si func_0031E978
#define float_to_usi func_0031EA10
#define df_to_sf func_0031EAE0
#define __make_dp func_0031EAB0
#define __make_fp func_0031EDA0
extern fp_number_type D_00755BD0; /* the static `thenan` of nan () */
INLINE static fp_number_type * nan () { return &D_00755BD0; }
INLINE static int isnan (fp_number_type * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf (fp_number_type * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero (fp_number_type * x) { return x->class == CLASS_ZERO; }

extern SFtype __make_fp (fp_class_type, unsigned int, int, USItype);
extern void unpack_d (FLO_union_type *, fp_number_type *);
#define ALIAS(n, a) __asm__ (".globl " #n "\n\t" #n " = " #a)
ALIAS (__pack_d, func_0031DE78);
ALIAS (litodp, func_0031E8C0);
ALIAS (dptoli, func_0031E978);
ALIAS (dptoul, func_0031EA10);
ALIAS (dptofp, func_0031EAE0);

// FUNCTION: GAME 0x31DE78
FLO_type
pack_d ( fp_number_type *  src)
{
  FLO_union_type dst;
  fractype fraction = src->fraction.ll;
  int sign = src->sign;
  int exp = 0;
  if (isnan (src))
    {
      exp = EXPMAX;
      if (src->class == CLASS_QNAN || 1)
	{
	  fraction |= QUIET_NAN;
	}
    }
  else if (isinf (src))
    {
      exp = EXPMAX;
      fraction = 0;
    }
  else if (iszero (src))
    {
      exp = 0;
      fraction = 0;
    }
  else if (fraction == 0)
    {
      exp = 0;
    }
  else
    {
      if (src->normal_exp < NORMAL_EXPMIN)
	{
	  int shift = NORMAL_EXPMIN - src->normal_exp;
	  exp = 0;
	  if (shift > FRAC_NBITS - NGARDS)
	    {
	      fraction = 0;
	    }
	  else
	    {
	      fraction >>= shift;
	    }
	  fraction >>= NGARDS;
	}
      else if (src->normal_exp > EXPBIAS)
	{
	  exp = EXPMAX;
	  fraction = 0;
	}
      else
	{
	  exp = src->normal_exp + EXPBIAS;
	  if ((fraction & GARDMASK) == GARDMSB)
	    {
	      if (fraction & (1 << NGARDS))
		fraction += GARDROUND + 1;
	    }
	  else
	    {
	      fraction += GARDROUND;
	    }
	  if (fraction >= IMPLICIT_2)
	    {
	      fraction >>= 1;
	      exp += 1;
	    }
	  fraction >>= NGARDS;
	}
    }
  dst.bits.fraction = fraction;
  dst.bits.exp = exp;
  dst.bits.sign = sign;
  return dst.value;
}

// FUNCTION: GAME 0x31E8C0
FLO_type
si_to_float (SItype arg_a)
{
  fp_number_type in;
  in.class = CLASS_NUMBER;
  in.sign = arg_a < 0;
  if (!arg_a)
    {
      in.class = CLASS_ZERO;
    }
  else
    {
      in.normal_exp = FRACBITS + NGARDS;
      if (in.sign)
	{
	  if (arg_a == (SItype) 0x80000000)
	    {
	      return -2147483648.0;
	    }
	  in.fraction.ll = (-arg_a);
	}
      else
	in.fraction.ll = arg_a;
      while (in.fraction.ll < (1LL << (FRACBITS + NGARDS)))
	{
	  in.fraction.ll <<= 1;
	  in.normal_exp -= 1;
	}
    }
  return pack_d (&in);
}

// FUNCTION: GAME 0x31E978
SItype
float_to_si (FLO_type arg_a)
{
  fp_number_type a;
  SItype tmp;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  if (isinf (&a))
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  if (a.normal_exp < 0)
    return 0;
  if (a.normal_exp > 30)
    return a.sign ? (-MAX_SI_INT)-1 : MAX_SI_INT;
  tmp = a.fraction.ll >> ((FRACBITS + NGARDS) - a.normal_exp);
  return a.sign ? (-tmp) : (tmp);
}

// FUNCTION: GAME 0x31EA10
USItype
float_to_usi (FLO_type arg_a)
{
  fp_number_type a;
  unpack_d ((FLO_union_type *) & arg_a, &a);
  if (iszero (&a))
    return 0;
  if (isnan (&a))
    return 0;
  if (a.sign)
    return 0;
  if (isinf (&a))
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

// FUNCTION: GAME 0x31EAB0
DFtype
__make_dp (fp_class_type class, unsigned int sign, int exp, UDItype frac)
{
  fp_number_type in;
  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return pack_d (&in);
}

// FUNCTION: GAME 0x31EAE0
SFtype
df_to_sf (DFtype arg_a)
{
  fp_number_type in;
  USItype sffrac;
  unpack_d ((FLO_union_type *) & arg_a, &in);
  sffrac = in.fraction.ll >> F_D_BITOFF;
  if ((in.fraction.ll & (((USItype) 1 << F_D_BITOFF) - 1)) != 0)
    sffrac |= 1;
  return __make_fp (in.class, in.sign, in.normal_exp, sffrac);
}
