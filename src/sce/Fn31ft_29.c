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
typedef unsigned int UHItype __attribute__ ((mode (HI)));
typedef unsigned int USItype __attribute__ ((mode (SI)));
typedef unsigned int UDItype __attribute__ ((mode (DI)));
#define INLINE __inline__
#define F_D_BITOFF (52+8-(23+7))
#define NGARDS    7L
#define GARDROUND 0x3f
#define GARDMASK  0x7f
#define GARDMSB   0x40
#define EXPBITS 8
#define EXPBIAS 127
#define FRACBITS 23
#define EXPMAX (0xff)
#define QUIET_NAN 0x100000L
#define FRAC_NBITS 32
typedef USItype fractype;
typedef UHItype halffractype;
typedef SFtype FLO_type;
#define NORMAL_EXPMIN (-(EXPBIAS)+1)
#define IMPLICIT_1 (1LL<<(FRACBITS+NGARDS))
#define IMPLICIT_2 (1LL<<(FRACBITS+1+NGARDS))
typedef enum { CLASS_SNAN, CLASS_QNAN, CLASS_ZERO, CLASS_NUMBER, CLASS_INFINITY } fp_class_type;
typedef struct { fp_class_type class; unsigned int sign; int normal_exp; union { fractype ll; halffractype l[2]; } fraction; } fp_number_type;
typedef union { FLO_type value; fractype value_raw; struct { fractype fraction:FRACBITS __attribute__ ((packed)); unsigned int exp:EXPBITS __attribute__ ((packed)); unsigned int sign:1 __attribute__ ((packed)); } bits; } FLO_union_type;

#define pack_d func_0031EB38
#define unpack_d func_0031EC48
#define __make_fp func_0031EDA0
#define sf_to_df func_0031EDD0
#define __muldi3 func_0031DE10
#define __make_dp func_0031EAB0
INLINE static int isnan (fp_number_type * x) { return x->class == CLASS_SNAN || x->class == CLASS_QNAN; }
INLINE static int isinf (fp_number_type * x) { return x->class == CLASS_INFINITY; }
INLINE static int iszero (fp_number_type * x) { return x->class == CLASS_ZERO; }

#define ALIAS(n, a) __asm__ (".globl " #n "\n\t" #n " = " #a)
ALIAS (__pack_f, func_0031EB38);
ALIAS (__unpack_f, func_0031EC48);

// FUNCTION: GAME 0x31EB38
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

// FUNCTION: GAME 0x31EC48
void
unpack_d (FLO_union_type * src, fp_number_type * dst)
{
  fractype fraction;
  int exp;
  int sign;
  fraction = src->bits.fraction;
  exp = src->bits.exp;
  sign = src->bits.sign;
  dst->sign = sign;
  if (exp == 0)
    {
      dst->class = CLASS_ZERO;
    }
  else if (exp == EXPMAX)
    {
      if (fraction == 0)
	{
	  dst->class = CLASS_INFINITY;
	}
      else
	{
	  if (fraction & QUIET_NAN)
	    {
	      dst->class = CLASS_QNAN;
	    }
	  else
	    {
	      dst->class = CLASS_SNAN;
	    }
	  dst->fraction.ll = fraction;
	}
    }
  else
    {
      dst->normal_exp = exp - EXPBIAS;
      dst->class = CLASS_NUMBER;
      dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}

// FUNCTION: GAME 0x31EDA0
SFtype
__make_fp(fp_class_type class,
	     unsigned int sign,
	     int exp,
	     USItype frac)
{
  fp_number_type in;
  in.class = class;
  in.sign = sign;
  in.normal_exp = exp;
  in.fraction.ll = frac;
  return pack_d (&in);
}

extern DFtype __make_dp (fp_class_type, unsigned int, int, UDItype frac);

extern DFtype __make_dp (fp_class_type, unsigned int, int, UDItype frac);

// FUNCTION: GAME 0x31EDD0
DFtype
sf_to_df (SFtype arg_a)
{
  fp_number_type in;

  unpack_d ((FLO_union_type *) & arg_a, &in);
  return __make_dp (in.class, in.sign, in.normal_exp,
		    ((UDItype) in.fraction.ll) << F_D_BITOFF);
}

/* libgcc2.c, L_muldi3 (longlong.h umul_ppmm for __mips__).  */
typedef int SItype __attribute__ ((mode (SI)));
typedef int DItype __attribute__ ((mode (DI)));
struct DIstruct {SItype low, high;};
typedef union { struct DIstruct s; DItype ll; } DIunion;
#define umul_ppmm(w1, w0, u, v) \
  __asm__ ("multu %2,%3" : "=l" ((USItype) (w0)), "=h" ((USItype) (w1)) : "d" ((USItype) (u)), "d" ((USItype) (v)))
#define __umulsidi3(u, v) \
  ({DIunion __w; umul_ppmm (__w.s.high, __w.s.low, u, v); __w.ll; })

// FUNCTION: GAME 0x31DE10
DItype
__muldi3 (DItype u, DItype v)
{
  DIunion w;
  DIunion uu, vv;

  uu.ll = u,
  vv.ll = v;

  w.ll = __umulsidi3 (uu.s.low, vv.s.low);
  w.s.high += ((USItype) uu.s.low * (USItype) vv.s.high
	       + (USItype) uu.s.high * (USItype) vv.s.low);

  return w.ll;
}
