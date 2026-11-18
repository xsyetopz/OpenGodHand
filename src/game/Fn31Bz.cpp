struct SysS {
    char p0[0x584];
    unsigned f584;
    char p1[0x5B0 - 0x588];
    unsigned short f5B0;
    char p2[0x5F4 - 0x5B2];
    void *f5F4;
};
struct TaskS { int a; void *b; };
extern "C" SysS Sys;
extern "C" TaskS GlobalTask;
extern unsigned D_00747A24;
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" char *CreateObj__F6eObjIdT0(int, int);
extern "C" void func_0031C5C0();
extern "C" void *func_0030F550(int);
extern "C" void *func_00107E40(void *);
// FUNCTION: GAME 0x31C4E0
extern "C" void func_0031C4E0()
{
    if (Sys.f5B0 != 0x20) {
        if (!(Sys.f584 & 0x10000)) {
            do {
                sleep__9cTaskWorkUs(GlobalTask.b, 1);
            } while (!(D_00747A24 & 0x10000));
        }
        {
            char *o = CreateObj__F6eObjIdT0(0x100, 0xFFFF);
            char *vt;
            Sys.f5F4 = o;
            vt = *(char **)(o + 0x214);
            ((void (*)(char *))*(void **)(vt + 0x44))(o + *(short *)(vt + 0x40));
            func_0031C5C0();
        }
    } else {
        Sys.f5F4 = func_00107E40(func_0030F550(0x1690));
    }
}
extern "C" unsigned func_0031CA58(void *);
extern "C" void Draw_Line_sc__FPA3_fUiUib(float (*)[4], unsigned, unsigned, int);
// FUNCTION: GAME 0x31C950
extern "C" void func_0031C950(short x, short y, int a2, int a3, void *p, unsigned z)
{
    float v[2][4];
    v[0][0] = x;
    v[0][1] = y;
    v[0][2] = z;
    v[0][3] = 1.0f;
    v[1][0] = x;
    v[1][1] = y;
    v[1][2] = z;
    v[1][3] = 1.0f;
    Draw_Line_sc__FPA3_fUiUib(v, 1, func_0031CA58(p), 1);
}
