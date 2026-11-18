// COMPILER: ee-gcc2.9-991111
// FLAGS: -Isrc/sce/libio -Isrc/sce/libio/stub
// SCE libstdc++ ostream small helpers (manipulator application, rdbuf).
#include "streambuf_sce.h"

class ostream : virtual public ios {
public:
    ostream& operator<<(ostream& (*f)(ostream&));
    ostream& operator<<(ios& (*f)(ios&));
    streambuf* rdbuf2() const;
};

// FUNCTION: GAME 0x38A478
ostream& ostream::operator<<(ostream& (*f)(ostream&)) { return (*f)(*this); }

// FUNCTION: GAME 0x38A448
ostream& ostream::operator<<(ios& (*f)(ios&)) { (*f)(*this); return *this; }

// FUNCTION: GAME 0x38A438
streambuf* ostream::rdbuf2() const { return _strbuf; }

class istream : virtual public ios {
public:
    istream& self1();
    streambuf* rdbuf2() const;
};

// FUNCTION: GAME 0x389E20
streambuf* istream::rdbuf2() const { return _strbuf; }

// FUNCTION: GAME 0x389478
istream& istream::self1() { return *this; }
