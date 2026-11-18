#include "game/Fn2B0b.h"

// FUNCTION: GAME 0x2B45D8
extern "C" void func_002B45D8() {}

// FUNCTION: GAME 0x2B45E0
extern "C" void func_002B45E0() {}

// FUNCTION: GAME 0x2B1270
extern "C" int func_002B1270(void *self, unsigned short *p)
{
    return Message->t[p[1]];
}

// FUNCTION: GAME 0x2B2AE8
extern "C" int func_002B2AE8(char *self)
{
    self[0x3C] = 0;
    self[0x70] = 2;
    *(int *)(self + 0x18) = 0;
    self[0xA4] = 2;
    return 0;
}

// FUNCTION: GAME 0x2B4390
extern "C" void func_002B4390(void *self)
{
    func_002B4560(self);
}

// FUNCTION: GAME 0x2B4A30
extern "C" void func_002B4A30(void *self)
{
    func_00345610(self);
}

// FUNCTION: GAME 0x2BA4B0
extern "C" void func_002BA4B0(void *self)
{
    func_002BB010(self);
}

// FUNCTION: GAME 0x2BE6C8
extern "C" void func_002BE6C8(int *self)
{
    func_00394F20(*self);
}

// FUNCTION: GAME 0x2BE6E8
extern "C" void func_002BE6E8()
{
    func_00394D58(0);
}

// FUNCTION: GAME 0x2BF130
extern "C" void func_002BF130(void *self)
{
    func_002BF170(self);
}

// FUNCTION: GAME 0x2B6350
extern "C" void func_002B6350(char *self, void *m)
{
    MtxCopy__FR7cMatrixRC7cMatrix(self + 0xB0, m);
}

// FUNCTION: GAME 0x2B8320
extern "C" void func_002B8320(void *self)
{
    _$_8cObjBase(self);
}

// FUNCTION: GAME 0x2B8908
extern "C" void func_002B8908(void *self)
{
    _$_8cObjBase(self);
}

// FUNCTION: GAME 0x2BE818
extern "C" void func_002BE818(void *self)
{
    func_002BE858(self, 0);
}

// FUNCTION: GAME 0x2BF150
extern "C" void func_002BF150(void *self)
{
    func_002BF170(self);
}

// FUNCTION: GAME 0x2B6400
extern "C" void func_002B6400(char *self)
{
    self[0x16] = 0;
    func_002B6370(self);
}

// FUNCTION: GAME 0x2BA158
extern "C" int func_002BA158(void *self, void *p)
{
    func_002B8990(p);
    return 1;
}

// FUNCTION: GAME 0x2BAE40
extern "C" void func_002BAE40(void *self, void *p, unsigned n)
{
    memset(p, 0, n);
}

// FUNCTION: GAME 0x2BB020
extern "C" void func_002BB020()
{
    func_002BA428(1, 0xFFFF);
}

// FUNCTION: GAME 0x2BE530
extern "C" void func_002BE530()
{
    func_002BE510(1, 0xFFFF);
}

// FUNCTION: GAME 0x2BE838
extern "C" void func_002BE838(char *self, int b, int idx)
{
    func_002BE560(self + idx * 8);
}

// FUNCTION: GAME 0x2BE948
extern "C" void func_002BE948()
{
    func_002BE8E8(1, 0xFFFF);
}

// FUNCTION: GAME 0x2BAE20
extern "C" void func_002BAE20(void *self, char *p)
{
    if (p) {
        free__5cHeapPv(*(void **)(p - 0x20), p);
    }
}

// FUNCTION: GAME 0x2BE510
extern "C" void func_002BE510(int a, int b)
{
    if (b == 0xFFFF && a) {
        D_005E8600 = 0;
    }
}

// FUNCTION: GAME 0x2BE890
void cRelSys::linkNoAlloc(void *p, const char *name, eRelType t)
{
    func_002BE630((char *)this + t * 8, p, name);
}

// FUNCTION: GAME 0x2B6528
extern "C" int *func_002B6528()
{
    if (!D_00460D58[0]) {
        func_0031EEC8(D_00460D58, D_0044B330);
    }
    return D_00460D58;
}

// FUNCTION: GAME 0x2BAD40
extern "C" int *func_002BAD40()
{
    if (!D_00460D60[0]) {
        func_0031EEC8(D_00460D60, D_0044BE98);
    }
    return D_00460D60;
}

// FUNCTION: GAME 0x2BAFA0
extern "C" int *func_002BAFA0()
{
    if (!D_00460D68[0]) {
        func_0031EEC8(D_00460D68, D_0044BF60);
    }
    return D_00460D68;
}

// FUNCTION: GAME 0x2B65B0
extern "C" void executeTask__11cNowLoading()
{
    if (!D_003C2554) {
        D_003C2554 = 1;
        execute__12cTaskManagerRFv_vi(&GlobalTask, func_002B6600, -1);
    }
}

// FUNCTION: GAME 0x2C5028
extern "C" SceRoom *func_002C5028(int a, unsigned short id)
{
    SceRoom *r = SceRoomTable;
    while (r->id != 0xFFFF) {
        if (r->id == id) {
            return r;
        }
        r++;
    }
    return 0;
}

// near-miss: 8 differing words, 56 vs 64 bytes; original has two separate return-0 blocks
#ifdef NONMATCHING
// DRAFT: GAME 0x2C9060
extern "C" char *func_002C9060(int *self, unsigned idx)
{
    char *items = (char *)self[0];
    unsigned n;
    if (!items || !(n = self[3])) {
        return 0;
    }
    if (idx < n) {
        return items + idx * 0x24;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x2CD740
extern "C" void func_002CD740(char *self)
{
    int *p = *(int **)(self + 0x380);
    p[2] = 0;
    (*(int **)(self + 0x380))[1] = 0;
    (*(int **)(self + 0x380))[6] = 0;
    (*(int **)(self + 0x380))[3] = *(int *)(self + 0x384);
    (*(int **)(self + 0x380))[0] = (int)self;
    (*(int **)(self + 0x380))[4] = 0;
    (*(int **)(self + 0x380))[5] = 0;
}

struct Row5 { int v[5]; };
extern Row5 D_003C23B0[];
// FUNCTION: GAME 0x2B0480
extern "C" void func_002B0480(int *self, float *out)
{
    out[0] = 1.0f;
    ((int *)out)[1] = D_003C23B0[self[0x13]].v[self[0x14]];
    ((int *)out)[2] = 0;
}

// near-miss: 7 differing words, same size; original keeps the count in $v1 and the mask in $a0, mine reuses $a2/$v1
#ifdef NONMATCHING
// DRAFT: GAME 0x2C3000
extern "C" void func_002C3000(int a, unsigned *p, int n)
{
    int k = n - 1;
    p[0] = 0xFFFFFFFF;
    if (k > 0) {
        do {
            p[1] = (unsigned)p & 0x7FFFFFFF;
            p++;
        } while (--k);
    }
}
#endif

// near-miss: 11 differing words, 68 vs 64 bytes; original rebuilds the %hi in $a0 on both paths, mine uses $v0 and a longer constant
#ifdef NONMATCHING
// DRAFT: GAME 0x2B4D68
extern "C" void Stop__6cMovieUi()
{
    int r = func_002B4F98();
    if (r) {
        func_002D42E0(r);
    }
    D_00747A84[0] &= ~0x2000u;
}
#endif
