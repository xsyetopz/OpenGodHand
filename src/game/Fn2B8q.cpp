extern "C" void func_002BB2D8();

// FUNCTION: GAME 0x2BB298
extern "C" void func_002BB298(char *self, float *v)
{
    float *d = (float *)(self + 0x60);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
    func_002BB2D8();
}

extern char Dvd[];
extern "C" int func_002019F8(char *);
extern "C" void func_0031A808(char *);

// FUNCTION: GAME 0x2BE200
extern "C" void func_002BE200(char *self)
{
    if (!func_002019F8(Dvd)) func_0031A808(self);
}

extern "C" char func_002BE6A0(char *);

// FUNCTION: GAME 0x2BE630
extern "C" int func_002BE630(char *self, int a)
{
    *(int *)self = a;
    char r = func_002BE6A0(self);
    *(char *)(self + 4) = r;
    if (!(r & 0xFF)) *(int *)self = 0;
    return *(unsigned char *)(self + 4);
}

extern "C" void func_002BF3D0(char *);
extern "C" void func_002BF420(char *);

// FUNCTION: GAME 0x2BF388
extern "C" void func_002BF388(char *self)
{
    switch (*(signed char *)(self + 1)) {
    case 0: func_002BF3D0(self); break;
    case 1: func_002BF420(self); break;
    }
}

extern "C" void func_002B64C0_mtx(char *, char *, char *, char *, int) __asm__("MtxInitCoord__FR7cMatrixRC4cVecN2");

// FUNCTION: GAME 0x2B64C0
extern "C" void func_002B64C0(char *self)
{
    if (*(unsigned char *)(self + 0x16)) return;
    func_002B64C0_mtx(self + 0x50, self + 0x40, self + 0x30, self + 0x20, *(unsigned char *)(self + 0x15));
    *(char *)(self + 0x16) = 1;
}

// FUNCTION: GAME 0x2BAAA8
extern "C" void func_002BAAA8(char *self, float *v)
{
    float *d = (float *)(self + 0x110);
    if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
    char *vt = *(char **)(self + 0x100);
    ((void (*)(char *))(*(void **)(vt + 0x54)))(self + *(short *)(vt + 0x50));
}

extern "C" void func_002BF4C8(char *);
extern "C" void func_002BF518(char *);

// FUNCTION: GAME 0x2BF478
extern "C" void func_002BF478(char *self)
{
    switch (*(signed char *)(self + 1)) {
    case 1: func_002BF4C8(self); break;
    case 2: func_002BF518(self); break;
    }
}

extern "C" void func_002BF708(char *);
extern "C" void func_002BF790(char *);
extern "C" void func_002C0A08(char *);
extern char *g_SaveManager;

// FUNCTION: GAME 0x2BF3D0
extern "C" void func_002BF3D0(char *self)
{
    func_002BF708(self);
    func_002BF790(self);
    func_002C0A08(g_SaveManager);
    char c = *self;
    *(char *)(self + 1) = 1;
    *self = c;
    *(char *)(self + 2) = 0;
    *(char *)(self + 3) = 0;
}
