// COMPILER: ee-gcc2.9-991111
// FLAGS: -Isrc/sce/libio -Isrc/sce/libio/stub
// SCE libstdc++ ostream small helpers (manipulator application, rdbuf).
#include "streambuf_sce.h"

class ostream : virtual public ios {
public:
    ostream& operator<<(ostream& (*f)(ostream&));
};

class istream : virtual public ios {
};


// FUNCTION: GAME 0x38A478
ostream& ostream::operator<<(ostream& (*f)(ostream&)) { return (*f)(*this); }

// The remaining units carry no name in the SN symbol list; they link by their func_ unit names.
extern "C" {

// FUNCTION: GAME 0x38A448
ostream* func_0038A448(ostream* o, ios& (*f)(ios&)) { (*f)(*o); return o; }

// FUNCTION: GAME 0x38A438
streambuf* func_0038A438(ostream* o) { return o->rdbuf(); }

// FUNCTION: GAME 0x389E20
streambuf* func_00389E20(istream* i) { return i->rdbuf(); }

// FUNCTION: GAME 0x389478
istream* func_00389478(istream* i) { return i; }

// FUNCTION: GAME 0x389480
istream* func_00389480(istream* i) { return i; }

// FUNCTION: GAME 0x389488
istream* func_00389488(istream* i) { return i; }

// FUNCTION: GAME 0x38A498
int func_0038A498(void* a, int b) { extern int func_00388D18(void*, int); return func_00388D18(a, b); }

extern void func_0031EE80(void*, const char*, const char*, int);
extern int D_00786738[];
extern char D_0045D1F8[], D_0045D208[];

// FUNCTION: GAME 0x38A340
int* func_0038A340()
{
    if (!D_00786738[0]) {
        __tf3ios();
        func_0031EE80(D_00786738, D_0045D1F8, D_0045D208, 1);
    }
    return D_00786738;
}

}
