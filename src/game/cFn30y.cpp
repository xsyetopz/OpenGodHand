// More unnamed small units in 0x300000-0x31BFFF: object factories, lazy singletons, list copy.
class cHeap;
void *_MemoryAlloc(unsigned int, unsigned int, cHeap &);
extern "C" void *memset(void *, int, unsigned);
extern "C" void *__8cObjBase(void *);
extern "C" void MtxCopy__FR7cMatrixRC7cMatrix(void *, void *);
extern "C" void func_002B6528();
extern "C" void func_0031EEA8(void *, const void *, const void *);
extern "C" void func_00306BB0(void *, int);
extern "C" void func_003062A8(int, int);
extern char D_00754C10[], D_00460D58[], D_00741DC8[];
extern unsigned D_00747A34;
extern char D_00450B98[], D_00450B28[], D_0044B840[];
extern int D_007863C8, D_007865C8, D_007865D8, D_00786598, D_007865A8;
extern char D_0044FBA8[], D_0044FBB8[], D_0044FDB8[], D_0044FDD8[], D_0044FDE8[];

// FUNCTION: GAME 0x317E80
extern "C" void *func_00317E80()
{
    if (D_00747A34 & 0x10000)
        return 0;
    char *p = (char *)_MemoryAlloc(0x4D0, 0x10, *(cHeap *)D_00754C10);
    if (!p)
        return 0;
    memset(p, 0, 0x4D0);
    __8cObjBase(p);
    *(char **)(p + 0x214) = D_00450B98;
    return p;
}

// FUNCTION: GAME 0x317F70
extern "C" void *func_00317F70()
{
    if (D_00747A34 & 0x10000)
        return 0;
    char *p = (char *)_MemoryAlloc(0x4D0, 0x10, *(cHeap *)D_00754C10);
    if (!p)
        return 0;
    memset(p, 0, 0x4D0);
    __8cObjBase(p);
    *(char **)(p + 0x214) = D_00450B28;
    return p;
}

// FUNCTION: GAME 0x3139E0
extern "C" void *func_003139E0()
{
    if (D_00747A34 & 0x10000)
        return 0;
    char *p = (char *)_MemoryAlloc(0x4E0, 0x10, *(cHeap *)D_00754C10);
    if (!p)
        return 0;
    memset(p, 0, 0x4E0);
    __8cObjBase(p);
    *(char **)(p + 0x214) = D_0044B840;
    return p;
}

// FUNCTION: GAME 0x318700
extern "C" void func_00318700(char *self, char *o)
{
    int i = 0;
    char *d = *(char **)(self + 0x144);
    char *s = *(char **)(o + 0x144);
    while (i < *(unsigned char *)(self + 0x2B4)) {
        MtxCopy__FR7cMatrixRC7cMatrix(d, s);
        i++;
        *(unsigned *)(d + 0x154) |= 8;
        d = *(char **)(d + 0x144);
        s = *(char **)(s + 0x144);
    }
}

// FUNCTION: GAME 0x300148
extern "C" void *func_00300148()
{
    if (!D_007863C8) {
        if (!D_00786598) {
            func_002B6528();
            func_0031EEA8(&D_00786598, D_0044FBA8, D_00460D58);
        }
        func_0031EEA8(&D_007863C8, D_0044FBB8, &D_00786598);
    }
    return &D_007863C8;
}

// FUNCTION: GAME 0x305148
extern "C" void *func_00305148()
{
    if (!D_007865C8) {
        if (!D_007865A8) {
            func_002B6528();
            func_0031EEA8(&D_007865A8, D_0044FDB8, D_00460D58);
        }
        func_0031EEA8(&D_007865C8, D_0044FDD8, &D_007865A8);
    }
    return &D_007865C8;
}

// FUNCTION: GAME 0x305200
extern "C" void *func_00305200()
{
    if (!D_007865D8) {
        if (!D_007865A8) {
            func_002B6528();
            func_0031EEA8(&D_007865A8, D_0044FDB8, D_00460D58);
        }
        func_0031EEA8(&D_007865D8, D_0044FDE8, &D_007865A8);
    }
    return &D_007865D8;
}

// FUNCTION: GAME 0x305858
extern "C" int func_00305858(int *s, int k)
{
    int v = 0;
    int n = s[3] - 1;
    if (k ^ 1) v = n;
    s[3] = n;
    if (v > 0) return 0;
    if (v) return 0;
    func_00306BB0(D_00741DC8, s[0]);
    func_003062A8(s[0], 2);
    s[3] = 0; s[1] = 0; s[2] = 0; s[0] = 5;
    return 1;
}
