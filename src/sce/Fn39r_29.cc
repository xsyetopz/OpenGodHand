// COMPILER: ee-gcc2.9-991111
// FLAGS: -Isrc/sce/libio -Isrc/sce/libio/stub
// SCE libstdc++ istream constructor and destructor with the virtual ios base inlined.
#include "streambuf_sce.h"

class istream : virtual public ios {
    _IO_size_t _gcount;
public:
    istream();
    ~istream();
};

// FUNCTION: GAME 0x38A298
istream::istream() : _gcount(0) { }

// FUNCTION: GAME 0x38A398
istream::~istream() { }
