// COMPILER: ee-gcc2.96

extern int D_003EE804;
extern char D_0045A1B0[];
extern long D_003EEA70;

// FUNCTION: GAME 0x360720
int func_00360720(void)
{
    return D_003EE804;
}

// FUNCTION: GAME 0x360790
char *func_00360790(void)
{
    return D_0045A1B0;
}

// FUNCTION: GAME 0x360940
int func_00360940(int a)
{
    return a ? 0x23 : 0;
}

// FUNCTION: GAME 0x360C58
long func_00360C58(void)
{
    return D_003EEA70;
}

extern int func_00368FC0();
extern char D_003EEA90[];
extern char D_003EEA98[];

// FUNCTION: GAME 0x360C40
int func_00360C40(void)
{
    return (unsigned long)D_003EEA70 < 2;
}

// FUNCTION: GAME 0x360C80
void func_00360C80(long a)
{
    D_003EEA70 = a;
}

// FUNCTION: GAME 0x360D18
char *func_00360D18(void)
{
    return D_003EEA90;
}

// FUNCTION: GAME 0x365EB0
char *func_00365EB0(void)
{
    return D_003EEA98;
}

extern int D_003F1FF0;
extern char D_0045A478[];

// FUNCTION: GAME 0x368FB0
void func_00368FB0(int *p, int b, int c)
{
    p[0] = b;
    p[1] = c;
}

// FUNCTION: GAME 0x36CCA8
int func_0036CCA8(void)
{
    return D_003F1FF0;
}

// FUNCTION: GAME 0x36D0E8
char *func_0036D0E8(void)
{
    return D_0045A478;
}

// FUNCTION: GAME 0x368E80
void func_00368E80(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}

// FUNCTION: GAME 0x36DDC8
void func_0036DDC8(char *a, int b, int c)
{
    int *p = (int *)(a + 0x14C);
    p[0] = b;
    p[1] = c;
}

// FUNCTION: GAME 0x369118
void func_00369118(int *p)
{
    p[2] = -1;
    *(long *)p = -1;
    p[3] = -1;
}

// FUNCTION: GAME 0x369E80
void func_00369E80(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

// FUNCTION: GAME 0x36A3A8
void func_0036A3A8(char *a, int b, int c)
{
    int *p = (int *)(a + 0x3EC);
    p[0] = b;
    p[1] = c;
    p[2] = 0;
}

extern void func_0036CCF0();
extern void func_0036CD18();
extern void func_0036CD48();
extern void func_0034B648();
extern void func_0036CA68();
extern int D_003F1AA0[];
extern int D_003F2048[];

// FUNCTION: GAME 0x36D7E0
void func_0036D7E0(int *p)
{
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
}

// FUNCTION: GAME 0x36C3B8
void func_0036C3B8(char *a, int *b, int *c)
{
    int *p = (int *)(a + 0x78);
    *b = p[6];
    *c = p[7];
}

// FUNCTION: GAME 0x36CC80
void func_0036CC80(int *a, int b, int c, int d)
{
    int *p = a + 2;
    int one = 1;
    p[0] = d;
    p[1] = b;
    p[2] = c;
    a[1] = one;
}

// FUNCTION: GAME 0x36C658
void func_0036C658(void)
{
    func_0036CCF0();
}

// FUNCTION: GAME 0x36C670
void func_0036C670(void)
{
    func_0036CD18();
}

// FUNCTION: GAME 0x36C688
void func_0036C688(char *a)
{
    func_0036CD48(*(int *)(a + 0x3B4));
}

// FUNCTION: GAME 0x36CA38
void func_0036CA38(char *a)
{
    func_0034B648(*(int *)(a + 0x3C));
}

// FUNCTION: GAME 0x36CA50
void func_0036CA50(void)
{
    func_0036CA68();
}

// FUNCTION: GAME 0x369E60
void func_00369E60(void)
{
    func_00369E80(D_003F1AA0);
}

// FUNCTION: GAME 0x36D7C0
void func_0036D7C0(void)
{
    func_0036D7E0(D_003F2048);
}

extern void *memset(void *, int, unsigned);
extern int D_003F1EC8[];

// FUNCTION: GAME 0x36CA68
void func_0036CA68(void)
{
    memset(D_003F1EC8, 0, 0x128);
    D_003F1EC8[1] = 8;
}

extern void func_0036CF08();
extern void func_0036BFB0();
extern void func_0036D6B0();
extern int func_00368E90();
extern char D_003F1AC8[];
extern char *D_003F1ABC;

// FUNCTION: GAME 0x36BF60
void func_0036BF60(char *a)
{
    func_0036BFB0(a);
    if (a) {
        func_0036D6B0(a, D_003F1AC8, 0x100);
        D_003F1ABC = a + 0x180;
    }
}

// FUNCTION: GAME 0x36C8D0
void func_0036C8D0(char *a)
{
    if (func_0036CCA8()) {
        int v = *(int *)(a + 0x3B4);
        if (v) func_0036CF08(v);
    }
}

// FUNCTION: GAME 0x369F20
int func_00369F20(char *a, int b, int c)
{
    if (a == 0) func_00369F70(D_003F1AA0, b);
    else func_00369F70(a + 0x250, b);
    return b;
}

// FUNCTION: GAME 0x369188
int func_00369188(int *a)
{
    if (func_00368FC0()) return func_00368E90(0, 0xFF020103);
    *a = 1;
}
