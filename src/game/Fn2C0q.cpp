// Small helpers from 0x2C0000-0x2D0000.
extern "C" void func_001F88A8(char *a, void *c, unsigned char type, float w, float d, float h);

// FUNCTION: GAME 0x2C53A8
extern "C" char *func_002C53A8(char *self)
{
    *(int *)self = 0;
    *(float *)(self + 0x10) = 1.0f;
    self[4] = 0;
    self[5] = 0;
    return self;
}

// FUNCTION: GAME 0x2CFF30
extern "C" char *func_002CFF30(char *self)
{
    self[0] = 0;
    self[1] = 0;
    *(int *)(self + 4) = 0;
    *(int *)(self + 0xC) = 0;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0x18) = -1;
    *(int *)(self + 0x20) = -1;
    return self;
}

// FUNCTION: GAME 0x2CF2D0
extern "C" char *func_002CF2D0(char *self)
{
    *(int *)self = 0;
    *(int *)(self + 4) = 0;
    *(int *)(self + 0x10) = 0;
    *(int *)(self + 0x14) = 0;
    *(int *)(self + 0x18) = 0;
    *(int *)(self + 0x1C) = 0;
    *(int *)(self + 0x20) = 0;
    *(int *)(self + 0x24) = 0;
    *(int *)(self + 0x28) = -1;
    *(int *)(self + 0x3C) = -1;
    return self;
}

// FUNCTION: GAME 0x2CD968
extern "C" char *func_002CD968(char *self, unsigned key)
{
    char *n = *(char **)(self + 0x380);
    while (n) {
        if (!(*(unsigned *)(n + 0xC) < key))
            return n;
        n = *(char **)(n + 8);
    }
    return 0;
}

// FUNCTION: GAME 0x2C2808
extern "C" void AtDataReset__13cSceAtManagerP10cSceAtUnit(char *self, char *u)
{
    if (u) {
        unsigned char c = u[0x4E];
        if (c) {
            u[0x3B] = c;
            u[0x4E] = 0;
        }
        u[0x44] = 0;
        *(int *)(u + 0x3C) = 0;
    }
}

extern "C" void func_003735E0(char *a, int b, float x, float y);

// FUNCTION: GAME 0x2CD470
extern "C" void func_002CD470(char *self, float x)
{
    if (!(*(unsigned *)(self + 0x98) & 0x100))
        func_003735E0(self, -1, 1.0f, x);
}

// FUNCTION: GAME 0x2CD4A8
extern "C" void func_002CD4A8(char *self, float x)
{
    float y = x;
    if (*(unsigned *)(self + 0x98) & 4)
        y = *(float *)(self + 0xC4);
    func_003735E0(self, -1, 0.0f, y);
}

extern "C" char objbaseArray[];
extern "C" char *SearchOM__13cObjBaseArrayUl(char *a, unsigned long k);
extern "C" int isOmBreak__9cScenarioP7cOmBase(char *a, char *b);
extern "C" void func_002C9D58(char *a);
extern "C" void func_002C9E78(char *a);
extern "C" void func_002C9F58(char *a);
extern "C" void *memset(void *, int, unsigned long);
extern "C" int SdeIssTblGet(int a, int b, int c);
extern "C" int SdeSystemOutModeGet(void);
extern "C" int Check__4cDvd6eDvdId(void *d, int id);
extern char Dvd[];

// FUNCTION: GAME 0x2C51E8
extern "C" int func_002C51E8(char *self, unsigned long key)
{
    char *o = SearchOM__13cObjBaseArrayUl(objbaseArray, key);
    return isOmBreak__9cScenarioP7cOmBase(self, o);
}

// FUNCTION: GAME 0x2C9D20
extern "C" void func_002C9D20(char *self)
{
    func_002C9D58(self);
    func_002C9E78(self);
    func_002C9F58(self);
}

// FUNCTION: GAME 0x2CDA48
extern "C" void func_002CDA48(char *self)
{
    memset(self, 0, 0x50);
    *(short *)(self + 0x28) = -1;
    *(short *)(self + 0x2A) = -1;
}

// FUNCTION: GAME 0x2CF218
extern "C" int func_002CF218(int unused, short a, short b, int c)
{
    return SdeIssTblGet(a, b, c) == -1 ? -1 : 0;
}

// FUNCTION: GAME 0x2CF258
extern "C" int func_002CF258(int unused, char *p)
{
    return SdeSystemOutModeGet() != 2 ? *(short *)(p + 0x10) : *(short *)(p + 0x12);
}

// FUNCTION: GAME 0x2CF298
extern "C" int func_002CF298(char *p)
{
    return SdeSystemOutModeGet() != 2 ? *(short *)(p + 0x2C) : *(short *)(p + 0x2E);
}

// FUNCTION: GAME 0x2CF830
extern "C" int func_002CF830(char *self)
{
    int id = *(int *)(self + 0x38);
    if (!id)
        return 1;
    return Check__4cDvd6eDvdId(Dvd, id) == 0;
}

extern "C" void func_002CC150(char *a);
extern "C" void func_002D22F0(char *a);
extern "C" void func_002CB128(char *a);
extern "C" void func_002CB200(char *a);

// FUNCTION: GAME 0x2CA518
extern "C" void func_002CA518(char *self)
{
    func_002CC150(self);
    func_002D22F0(self);
    func_002CB128(self);
    func_002CB200(self);
}

#ifdef NONMATCHING
// FUNCTION: GAME 0x2C0DA8
extern "C" void AreaSet__10cSceAtUnitR4cVecff9eAreaType(char *self, void *v, float a, float b, int t)
{
    func_001F88A8(self + 4, v, t, a, a, b);
}
#endif
