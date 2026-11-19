extern "C" float GetSpeedRate__9cEmManage(void *);
extern char g_EmManage[];
struct SysT { char pad[0x574]; float spd; };
extern SysT Sys;

#define B(o) (*(unsigned char *)(self + (o)))
#define F(o) (*(float *)(self + (o)))

// FUNCTION: GAME 0x1B48E0
extern "C" void func_001B48E0(char *self)
{
    switch (B(0x2F6)) {
    case 1:
        break;
    case 0:
        B(0x2F6) = 1;
        F(0x620) = 0.0f;
        break;
    case 2: {
        float v = F(0x620) + F(0x624) * GetSpeedRate__9cEmManage(g_EmManage) * Sys.spd;
        float m = F(0x61C);
        F(0x620) = v;
        if (m <= v)
            F(0x620) = m;
        break;
    }
    case 3: {
        float v = F(0x620) - F(0x628) * GetSpeedRate__9cEmManage(g_EmManage) * Sys.spd;
        float m = 0.0f;
        F(0x620) = v;
        if (v <= m)
            F(0x620) = m;
        break;
    }
    }
    struct L { unsigned n; char *p; } l;
    l.n = B(0x2B4);
    char *c;
    if (l.n)
        c = **(char ***)(self + 0x278);
    else
        c = 0;
    *(float *)(c + 0x104) += F(0x620) * GetSpeedRate__9cEmManage(g_EmManage) * Sys.spd;
}
