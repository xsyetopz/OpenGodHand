// COMPILER: ee-gcc2.9-991111
#include "_jump.h"
#include "iostream.h"
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)
extern "C" { _IO_ssize_t _IO_padn(_IO_FILE*, int, _IO_ssize_t); }
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
