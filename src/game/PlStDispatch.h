#ifndef PLSTDISPATCH_H
#define PLSTDISPATCH_H

// Object whose state byte at 0x2F5 selects a pointer-to-member handler from a table.
// The virtual method keeps the vtable path in the generated dispatch.
class cPlSt {
public:
    virtual void vf();
    char _pad[0x2F5];
    unsigned char st;
};
typedef void (cPlSt::*PlStFn)();

#endif
