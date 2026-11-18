// COMPILER: ee-gcc2.9-991111
#include "_jump.h"
#include "iostream.h"
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)
extern "C" { _IO_ssize_t _IO_padn(_IO_FILE*, int, _IO_ssize_t); }
ostream& ostream::operator<<(const char *s)
{
  if (opfx())
    {
      _IO_cleanup_region_start ((void (*) __P ((void *))) _IO_funlockfile,
				_strbuf);
      if (s == NULL)
	s = "(null)";
      int len = strlen(s);
      int w = width(0);
// FIXME: Should we: if (w && len>w) len = w;
      char fill_char = fill();
      register streambuf *sbuf = rdbuf();
      register int padding = w > len ? w - len : 0;
      if (!(flags() & ios::left) && padding > 0) // Default adjustment.
	{ int pn = padding; if (_IO_padn(sbuf, fill_char, pn) != pn)
	  {
	    set(ios::badbit);
	    goto failed;
	  } }
      if (_IO_sputn (sbuf, s, len) != len)
	{
	  set(ios::badbit);
	  goto failed;
	}
      if (flags() & ios::left && padding > 0) // Left adjustment.
	{ int pn = padding; if (_IO_padn(sbuf, fill_char, pn) != pn)
	  set(ios::badbit); }
     failed:
      osfx();
      _IO_cleanup_region_end (0);
    }
  return *this;
}
