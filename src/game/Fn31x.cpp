extern int D_00747B14;
extern unsigned *D_00747A4C;
extern char D_00450ED8[];
extern char D_00450E88[];
unsigned *SearchData(unsigned *, const char *, unsigned);
extern "C" int memcmp(const void *, const void *, unsigned);
extern "C" void func_0031C238(int, char *, char *);
extern "C" void func_0031D3D0(int, int, int, int);
extern "C" float func_0031CF78(void);

// FUNCTION: GAME 0x31C1D0
extern "C" void func_0031C1D0(int a, char *b)
{
    if (b && !memcmp(b, D_00450E88, 4))
        func_0031C238(a, b + 4, b + 0x20);
}

// FUNCTION: GAME 0x31CE38
unsigned *SearchCameraData(const char *n)
{
    unsigned *p = SearchData(D_00747A4C, D_00450ED8, 0);
    if (!p)
        return 0;
    return SearchData(p, n, 0);
}

// FUNCTION: GAME 0x31CF30
extern "C" float func_0031CF30(void)
{
    float r = func_0031CF78();
    if (r <= 0.0f)
        r += 1.0f;
    return r;
}

// FUNCTION: GAME 0x31CF78
extern "C" float func_0031CF78(void)
{
    unsigned r = D_00747B14 * 0x10DCD;
    D_00747B14 = r;
    float f = (float)r * 2.3283064e-10f;
    return f + f;
}

// FUNCTION: GAME 0x31D658
extern "C" unsigned short func_0031D658(char *s, unsigned char b)
{
    for (int i = 0; i < *(unsigned short *)(s + 8); i++) {
        int p = ((int *)(s + 0x10))[i] + (int)s;
        func_0031D3D0(p, *(int *)p + p, i, b);
    }
    return *(unsigned short *)(s + 8);
}

extern char Sys[];
extern char Dvd[];
extern char RoomHeap[];
extern char D_00450EC0[];
extern int D_007558A0[];
extern "C" int sprintf(char *, const char *, ...);
extern "C" int func_00200DF8(char *, char *, char *, char *, int, int *, int, int);
extern "C" void func_00201108(char *, int);

// FUNCTION: GAME 0x31CC48
extern "C" void func_0031CC48(void)
{
    char buf[0x40];
    int v;
    sprintf(buf, D_00450EC0, (unsigned char)Sys[0x5B1], (unsigned char)Sys[0x5B1], (unsigned char)Sys[0x5B0]);
    func_00201108(Dvd, func_00200DF8(Dvd, buf, Sys + 0x5AC, RoomHeap, 0, &v, 0, 0));
    D_007558A0[0] = *(int *)(Sys + 0x5AC);
    D_007558A0[1] = v;
}
