struct T10 { int a[10]; };
extern T10 D_0042B628, D_0042B650;
extern "C" void SetLocalPosXY__12CustomIDWorkii(char *, int, int);
extern "C" void func_001DD258(char *, int, int);

// FUNCTION: GAME 0x1DDF08
extern "C" void func_001DDF08(char *self, unsigned char k, int x)
{
    if (k < 5) {
        T10 a = D_0042B628;
        T10 b = D_0042B650;
        int o = k << 3;
        SetLocalPosXY__12CustomIDWorkii(self + 0x162C, *(int *)((char *)&b + o), *(int *)((char *)&b + o + 4));
        SetLocalPosXY__12CustomIDWorkii(self + 0x16A8, *(int *)((char *)&a + o), *(int *)((char *)&a + o + 4));
        func_001DD258(self, 0x2D, x);
        func_001DD258(self, 0x2E, x);
    }
}

struct T8b { int a[8]; };
extern long D_00747650;
extern T8b D_0042BAC0;
extern char D_0042BAE0[];
extern "C" void printf__FiiiiiiPCce(int, int, int, int, int, int, const char *, ...);

// FUNCTION: GAME 0x1E6938
extern "C" void func_001E6938(char *self)
{
#define P (*(short *)(self + 0xA80))
    if (D_00747650 & 0x4400008000000L) {
        if (--P < 0)
            P = 7;
    } else if (D_00747650 & 0x8800004000000L) {
        if (++P >= 8)
            P = 0;
    }
    T8b t = D_0042BAC0;
    printf__FiiiiiiPCce(8, 16, 32, 32, 0, 0, D_0042BAE0, t.a[P]);
}
