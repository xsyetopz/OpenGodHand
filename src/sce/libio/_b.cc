// COMPILER: ee-gcc2.9-991111
#include "_jump.h"
#include "iostream.h"
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)
extern "C" { _IO_ssize_t _IO_padn(_IO_FILE*, int, _IO_ssize_t); }
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

