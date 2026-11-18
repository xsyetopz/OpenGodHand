// Small units in 0x1E0000-0x1F0000 (continued from Fn1E0s.cpp).

class CustomIDWork {
public:
    CustomIDWork();
};

class cIDBase {
public:
    cIDBase();
};
inline void *operator new(unsigned int, void *p) { return p; }

// FUNCTION: GAME 0x1ECA80
extern "C" char *func_001ECA80(char *self)
{
    *(int *)self = 0;
    new (self + 0x10) cIDBase;
    int i = 0x2C;
    char *p = self + 0x60;
    do {
        new (p) CustomIDWork;
        p += 0x7C;
    } while (--i != -1);
    return self;
}

// FUNCTION: GAME 0x1ED548
extern "C" char *func_001ED548(char *self)
{
    *(int *)self = 0;
    new (self + 0x10) cIDBase;
    int i = 5;
    char *p = self + 0x60;
    do {
        new (p) CustomIDWork;
        p += 0x7C;
    } while (--i != -1);
    return self;
}

// FUNCTION: GAME 0x1EDE38
extern "C" char *func_001EDE38(char *self)
{
    *(int *)self = 0;
    new (self + 0x10) cIDBase;
    int i = 0x1C;
    char *p = self + 0x60;
    do {
        new (p) CustomIDWork;
        p += 0x7C;
    } while (--i != -1);
    return self;
}
