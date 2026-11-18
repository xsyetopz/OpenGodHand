// Small functions in 0x2E0000-0x2FFFFF.

extern "C" {
void func_002F1AA0(int, unsigned);
void func_002FBED0(void *);

// FUNCTION: GAME 0x2FBE10
void func_002FBE10() {}

// FUNCTION: GAME 0x2FBE18
void func_002FBE18() {}

// FUNCTION: GAME 0x2FBE20
void func_002FBE20() {}

// FUNCTION: GAME 0x2FEBD8
void func_002FEBD8() {}

// FUNCTION: GAME 0x2F1B40
void func_002F1B40() { func_002F1AA0(1, 0xFFFF); }

// FUNCTION: GAME 0x2F29E0
void func_002F29E0(void *p) { func_002FBED0(p); }

void func_002FBE50(void *);
void func_002FBE28(char *);
void func_002FBDD8(void *);
void *func_002E9B68(void *);
void *func_002EBF08(void *);
void *func_002F56C0(void *);
void *func_002F61C8(void *);
extern char D_0044E820[];
extern char D_0044EA10[];
extern char D_0044F880[];
extern char D_0044FAD0[];

// FUNCTION: GAME 0x2FEC30
void func_002FEC30() {}

// FUNCTION: GAME 0x2F3070
void func_002F3070(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2F4D28
void func_002F4D28(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2F5448
void func_002F5448(void *p) { func_002FBED0(p); }

// FUNCTION: GAME 0x2FEBB8
void func_002FEBB8(void *p) { func_002FBE50(p); }

// FUNCTION: GAME 0x2EBC28
void func_002EBC28(char *p)
{
    *(char **)(p + 0xF0) = D_0044E820;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2EFC80
void func_002EFC80(char *p)
{
    *(char **)(p + 0xF0) = D_0044EA10;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2FA070
void func_002FA070(char *p)
{
    *(char **)(p + 0xF0) = D_0044F880;
    func_002FBE28(p);
}

// FUNCTION: GAME 0x2FBE28
void func_002FBE28(char *p)
{
    *(char **)(p + 0xF0) = D_0044FAD0;
    func_002FBDD8(p);
}

// FUNCTION: GAME 0x2FFBF8
void *func_002FFBF8(void *p)
{
    void *r = p;
    if (r)
        r = func_002E9B68(p);
    return r;
}

// FUNCTION: GAME 0x2FFC60
void *func_002FFC60(void *p)
{
    void *r = p;
    if (r)
        r = func_002EBF08(p);
    return r;
}

// FUNCTION: GAME 0x2FFF90
void *func_002FFF90(void *p)
{
    void *r = p;
    if (r)
        r = func_002F56C0(p);
    return r;
}

// FUNCTION: GAME 0x2FFFB8
void *func_002FFFB8(void *p)
{
    void *r = p;
    if (r)
        r = func_002F61C8(p);
    return r;
}
}
