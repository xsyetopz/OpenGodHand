// COMPILER: ee-gcc2.9-991111
/* This is part of libio/iostream, providing -*- C++ -*- input/output.
   Copyright (C) 1993, 1997, 2000 Free Software Foundation, Inc.

   This file is part of the GNU IO Library.  This library is free
   software; you can redistribute it and/or modify it under the
   terms of the GNU General Public License as published by the
   Free Software Foundation; either version 2, or (at your option)
   any later version.

   This library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this library; see the file COPYING.  If not, write to the Free
   Software Foundation, 59 Temple Place - Suite 330, Boston, MA  02111-1307,
   USA.

   As a special exception, if you link this library with files
   compiled with a GNU compiler to produce an executable, this does not cause
   the resulting executable to be covered by the GNU General Public License.
   This exception does not however invalidate any other reasons why
   the executable file might be covered by the GNU General Public License. */

/* Written by Per Bothner (bothner@cygnus.com). */


/* Reconstruction of libio/iostream.cc (egcs/gcc 2.95 libio) as built in the SCE
   libstdc++ of God Hand. Only functions whose bytes match are kept. */
#define _STREAM_COMPAT
#include "iostream.h"
#include "_jump.h"
#include "_sys.h"

#define LONGEST long long

// Not reproduced yet; declared so the matching callers compile.
extern int skip_ws(streambuf* sb);
extern int read_int(istream& stream, unsigned LONGEST& val, int& neg);
extern void write_int(ostream& stream, unsigned LONGEST val, int sign);

// FUNCTION: GAME 0x387610
istream& istream::get(char& c)
{
    if (ipfx1()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	int ch = _strbuf->sbumpc();
	if (ch == EOF) {
	  set(ios::eofbit|ios::failbit);
	  _gcount = 0;
	}
	else {
	  c = (char)ch;
	  _gcount = 1;
	}
	isfx();
	_IO_cleanup_region_end (0);
    }
    else
      _gcount = 0;
    return *this;
}

// FUNCTION: GAME 0x3876D0
int istream::peek()
{
  if (!good())
    return EOF;
  if (_tie && rdbuf()->in_avail() == 0)
    _tie->flush();
  int ch = _strbuf->sgetc();
  if (ch == EOF)
    set(ios::eofbit);
  return ch;
}

// FUNCTION: GAME 0x387788
istream& istream::ignore(int n /* = 1 */, int delim /* = EOF */)
{
    _gcount = 0;
    if (ipfx1()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	register streambuf* sb = _strbuf;
	if (delim == EOF) {
	    _gcount = sb->ignore(n);
	    goto unlock;
	}
	for (;;) {
#if 0
	    if (n != MAXINT) // FIXME
#endif
	    if (--n < 0)
		break;
	    int ch = sb->sbumpc();
	    if (ch == EOF) {
		set(ios::eofbit|ios::failbit);
		break;
	    }
	    _gcount++;
	    if (ch == delim)
		break;
	}
    unlock:
	isfx();
	_IO_cleanup_region_end (0);
    }
    return *this;
}


int
// FUNCTION: GAME 0x387958
istream::sync ()
{
  streambuf *sb = rdbuf ();
  if (sb == NULL)
    return EOF;
  if (sb->sync ()) // Later: pubsync
    {
      setstate (ios::badbit);
      return EOF;
    }
  else
    return 0;
}

// FUNCTION: GAME 0x3879C0
istream& istream::seekg(streampos pos)
{
    pos = _strbuf->pubseekpos(pos, ios::in);
    if (pos == streampos(EOF))
	set(ios::badbit);
    return *this;
}

// FUNCTION: GAME 0x387A10
istream& istream::seekg(streamoff off, _seek_dir dir)
{
  streampos pos = _IO_seekoff (_strbuf, off, (int) dir, _IOS_INPUT);
  if (pos == streampos(EOF))
    set(ios::badbit);
  return *this;
}

// FUNCTION: GAME 0x387A60
streampos istream::tellg()
{
#if 0
    streampos pos = _strbuf->pubseekoff(0, ios::cur, ios::in);
#else
    streampos pos = _IO_seekoff (_strbuf, 0, _IO_seek_cur, _IOS_INPUT);
#endif
    if (pos == streampos(EOF))
	set(ios::badbit);
    return pos;
}

// FUNCTION: GAME 0x387AB8
istream& istream::operator>>(char& c)
{
    if (ipfx0()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	int ch = _strbuf->sbumpc();
	if (ch == EOF)
	    set(ios::eofbit|ios::failbit);
	else
	    c = (char)ch;
	isfx();
	_IO_cleanup_region_end (0);
    }
    return *this;
}

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
#define LONGEST long long
#else
#define LONGEST long
#endif


#define READ_INT(TYPE) \
istream& istream::operator>>(TYPE& i)\
{\
    unsigned LONGEST val; int neg;\
    if (read_int(*this, val, neg)) {\
	if (neg) val = -val;\
	i = (TYPE)val;\
    }\
    return *this;\
}

// FUNCTION: GAME 0x387F78
READ_INT(short)
READ_INT(unsigned short)
// FUNCTION: GAME 0x388038
READ_INT(int)
READ_INT(unsigned int)
// FUNCTION: GAME 0x3880F8
READ_INT(long)
READ_INT(unsigned long)
#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
READ_INT(long long)
READ_INT(unsigned long long)
#endif

// DRAFT: GAME 0x3882D8
istream& istream::operator>>(long double& x)
{
    if (ipfx0())
      {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
#if _G_HAVE_LONG_DOUBLE_IO
	scan("%Lg", &x);
#else
	double y;
	scan("%lg", &y);
	x = y;
#endif
	isfx();
	_IO_cleanup_region_end (0);
      }
    return *this;
}

// operator>>(double&) and (float&) match, but their "%lg"/"%g" literals sit in the
// object's .rodata, which is not linked yet; Fn38y_29.c carries 0x388380 meanwhile.
#ifdef NONMATCHING
// DRAFT: GAME 0x388380
istream& istream::operator>>(double& x)
{
    if (ipfx0())
      {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	scan("%lg", &x);
	isfx();
	_IO_cleanup_region_end (0);
      }
    return *this;
}

istream& istream::operator>>(float& x)
{
    if (ipfx0())
      {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	scan("%g", &x);
	isfx();
	_IO_cleanup_region_end (0);
      }
    return *this;
}
#endif

// FUNCTION: GAME 0x3884C0
istream& istream::operator>>(register streambuf* sbuf)
{
    if (ipfx0()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	register streambuf* inbuf = rdbuf();
	// FIXME: Should optimize!
	for (;;) {
	    register int ch = inbuf->sbumpc();
	    if (ch == EOF) {
		set(ios::eofbit);
		break;
	    }
	    if (sbuf->sputc(ch) == EOF) {
		set(ios::failbit);
		break;
	    }
	}
	isfx();
	_IO_cleanup_region_end (0);
    }
    return *this;
}

// FUNCTION: GAME 0x3885B0
ostream& ostream::operator<<(char c)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
#if 1
	// This is what the cfront implementation does.
	if (_strbuf->sputc(c) == EOF) {
	    set(ios::badbit);
	    goto failed;
	}
#else
	// This is what cfront documentation and current ANSI drafts say.
	int w = width(0);
	char fill_char = fill();
	register int padding = w > 0 ? w - 1 : 0;
	register streambuf *sb = _strbuf;
	if (!(flags() & ios::left) && padding) // Default adjustment.
	    if (_IO_padn(sb, fill_char, padding) < padding) {
	      set(ios::badbit);
	      goto failed;
	    }
	if (sb->sputc(c) == EOF) {
	  set(ios::badbit);
	  goto failed;
        }
	if (flags() & ios::left && padding) // Left adjustment.
	    if (_IO_padn(sb, fill_char, padding) < padding)
	      set(ios::badbit);
#endif
       failed:
	osfx();
	_IO_cleanup_region_end (0);
    }
    return *this;
}

/* Write VAL on STREAM.
   If SIGN<0, val is the absolute value of a negative number.
   If SIGN>0, val is a signed non-negative number.
   If SIGN==0, val is unsigned. */


// FUNCTION: GAME 0x388A00
ostream& ostream::operator<<(int n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	int sign = 1;
	unsigned int abs_n = (unsigned)n;
	if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
	    abs_n = -((unsigned)n), sign = -1;
	write_int(*this, abs_n, sign);
	_IO_cleanup_region_end (0);
    }
    return *this;
}

// FUNCTION: GAME 0x388AA0
ostream& ostream::operator<<(unsigned int n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	write_int(*this, n, 0);
	_IO_cleanup_region_end (0);
    }
    return *this;
}


// FUNCTION: GAME 0x388B18
ostream& ostream::operator<<(long n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	int sign = 1;
	unsigned long abs_n = (unsigned long)n;
	if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
	    abs_n = -((unsigned long)n), sign = -1;
	write_int(*this, abs_n, sign);
	_IO_cleanup_region_end (0);
    }
    return *this;
}

// FUNCTION: GAME 0x388BA8
ostream& ostream::operator<<(unsigned long n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	write_int(*this, n, 0);
	_IO_cleanup_region_end (0);
    }
    return *this;
}

#if defined(__GNUC__) && !defined(__STRICT_ANSI__)
ostream& ostream::operator<<(long long n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	int sign = 1;
	unsigned long long abs_n = (unsigned long long)n;
	if (n < 0 && (flags() & (ios::oct|ios::hex)) == 0)
	    abs_n = -((unsigned long long)n), sign = -1;
	write_int(*this, abs_n, sign);
	_IO_cleanup_region_end (0);
    }
    return *this;
}


ostream& ostream::operator<<(unsigned long long n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	write_int(*this, n, 0);
	_IO_cleanup_region_end (0);
    }
    return *this;
}
#endif /*__GNUC__*/


#if 0
ostream& ostream::operator<<(const void *p)
{ Is in osform.cc, to avoid pulling in all of _IO_vfprintf by this file. */ }
#endif

// FUNCTION: GAME 0x388FB0
ostream& ostream::operator<<(register streambuf* sbuf)
{
  if (opfx())
    {
      _IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				_strbuf);
      char buffer[_IO_BUFSIZ];
      register streambuf* outbuf = _strbuf;
      for (;;)
	{
	  _IO_size_t count = _IO_sgetn(sbuf, buffer, _IO_BUFSIZ);
	  if (count <= 0)
	    break;
	  if (_IO_sputn(outbuf, buffer, count) != count)
	    {
	      set(ios::badbit);
	      break;
	    }
	}
      osfx();
      _IO_cleanup_region_end (0);
    }
  return *this;
}

// FUNCTION: GAME 0x389090
ostream::ostream(streambuf* sb, ostream* tied)
{
  init (sb, tied);
}

// FUNCTION: GAME 0x389170
ostream& ostream::seekp(streampos pos)
{
    pos = _strbuf->pubseekpos(pos, ios::out);
    if (pos == streampos(EOF))
	set(ios::badbit);
    return *this;
}

// FUNCTION: GAME 0x3891C0
ostream& ostream::seekp(streamoff off, _seek_dir dir)
{
  streampos pos = _IO_seekoff (_strbuf, off, (int) dir, _IOS_OUTPUT);
  if (pos == streampos(EOF))
    set(ios::badbit);
  return *this;
}

// FUNCTION: GAME 0x389210
streampos ostream::tellp()
{
#if 1
    streampos pos = _IO_seekoff (_strbuf, 0, _IO_seek_cur, _IOS_OUTPUT);
#else
    streampos pos = _strbuf->pubseekoff(0, ios::cur, ios::out);
#endif
    if (pos == streampos(EOF))
	set(ios::badbit);
    return pos;
}

// FUNCTION: GAME 0x389268
ostream& ostream::flush()
{
    if (_strbuf->sync())
	set(ios::badbit);
    return *this;
}

// FUNCTION: GAME 0x3892C0
ostream& flush(ostream& outs)
{
  return outs.flush();
}

// FUNCTION: GAME 0x3892E0
istream& ws(istream& ins)
{
    if (ins.ipfx1()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  ins._strbuf);
	int ch = skip_ws(ins._strbuf);
	if (ch == EOF)
	    ins.set(ios::eofbit);
	else
	    ins._strbuf->sputbackc(ch);
	ins.isfx();
	_IO_cleanup_region_end (0);
    }
    return ins;
}

// Skip white-space.  Return 0 on failure (EOF), or 1 on success.
// Differs from ws() manipulator in that failbit is set on EOF.
// Called by ipfx() and ipfx0() if needed.

// FUNCTION: GAME 0x389398
int istream::_skip_ws()
{
    int ch = skip_ws(_strbuf);
    if (ch == EOF) {
	set(ios::eofbit|ios::failbit);
	return 0;
    }
    else {
	_strbuf->sputbackc(ch);
	return 1;
    }
}

// FUNCTION: GAME 0x389400
ostream& ends(ostream& outs)
{
    outs.put('\0');
    return outs;
}

// FUNCTION: GAME 0x389438
ostream& endl(ostream& outs)
{
    return flush(outs.put('\n'));
}

// FUNCTION: GAME 0x389470
istream& lock(istream& ins)
{
  _IO_flockfile (ins._strbuf);
  return ins;
}
istream& unlock(istream& ins)
{
  _IO_funlockfile (ins._strbuf);
  return ins;
}
ostream& lock(ostream& outs)
{
  _IO_flockfile (outs._strbuf);
  return outs;
}
ostream& unlock(ostream& outs)
{
  _IO_funlockfile (outs._strbuf);
  return outs;
}


// FUNCTION: GAME 0x389490
ostream& ostream::write(const char *s, streamsize n)
{
    if (opfx()) {
	_IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				  _strbuf);
	if (_IO_sputn(_strbuf, s, n) != n)
	    set(ios::failbit);
	osfx();
	_IO_cleanup_region_end (0);
    }
    return *this;
}


// FUNCTION: GAME 0x3895B0
iostream::iostream(streambuf* sb, ostream* tied)
{
  init (sb, tied);
}

// NOTE: extension for compatibility with old libg++.
// Not really compatible with fistream::close().
#ifdef _STREAM_COMPAT
// FUNCTION: GAME 0x389710
void ios::close()
{
  if (_strbuf->_flags & _IO_IS_FILEBUF)
    ((struct filebuf*)rdbuf())->close();
  else if (_strbuf != NULL)
    rdbuf()->sync();
  _strbuf = NULL;
  _state = badbit;
}

// FUNCTION: GAME 0x389770
int istream::skip(int i)
{
    int old = (_flags & ios::skipws) != 0;
    if (i)
	_flags |= ios::skipws;
    else
	_flags &= ~ios::skipws;
    return old;
}
#endif

