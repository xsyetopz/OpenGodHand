extern "C" int func_002B6510(char *);
extern "C" char *func_002B5E50(char *);
extern "C" char *func_002B61B0(char *);
extern "C" char *func_002B6328(char *);
extern "C" void MtxMultiply__FR7cMatrixRC7cMatrixT1(char *, char *, char *);
extern "C" void MtxCopy__FR7cMatrixRC7cMatrix(char *, char *);

// FUNCTION: GAME 0x2B6420
extern "C" void func_002B6420(char *self)
{
    if (!func_002B6510(self)) {
        char *p = func_002B5E50(self);
        if (p) {
            char *a = func_002B61B0(p);
            MtxMultiply__FR7cMatrixRC7cMatrixT1(self + 0xB0, a, func_002B6328(self));
        } else {
            MtxCopy__FR7cMatrixRC7cMatrix(self + 0xB0, func_002B6328(self));
        }
        *(unsigned *)(self + 0x90) |= 1;
    }
}

extern "C" void *memset(void *, int, unsigned);
extern "C" void func_003452D8(void *);
extern "C" void func_00346B78(int);
extern "C" void func_00344520(void *, void *, int);
extern "C" void func_002D3710(char *);
extern "C" void func_002B48A0();
extern "C" void func_002B48C8();
extern char D_005E7E30[];

struct P4 { float f; int a; int b; int c; int pad[4]; };

// FUNCTION: GAME 0x2B4960
extern "C" void func_002B4960(char *self)
{
    P4 p;
    *(int *)(self + 0x10) = 0;
    *(char *)(self + 0x14) = 0;
    *(int *)(self + 0x18) = 0;
    *(char **)self = D_005E7E30;
    int *q = (int *)(self + 4);
    int i = 2;
    memset(&p, 0, 0x20);
    p.f = 59.94f;
    p.a = 1;
    p.b = 1;
    p.c = 0;
    func_003452D8(&p);
    func_00346B78(-1);
    func_00344520((void *)func_002B48A0, (void *)func_002B48C8, 0);
    char *s = *(char **)self;
    do {
        func_002D3710(s);
        i--;
        s += 0xAC;
        *q = 0;
        q++;
    } while (i >= 0);
}

