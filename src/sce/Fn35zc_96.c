// COMPILER: ee-gcc2.96

extern int func_0035B188();
extern int func_0035B6B0();
extern int func_0035B6F8();
extern long func_0035BA58();
extern long D_00766C80;

#ifdef NONMATCHING
// DRAFT: GAME 0x35A768 original copies a0 to a1 and uses a0 as the constant 4; gcc keeps a in a0; 12 words
int func_0035A768(char *a)
{
    char *p = a + 0x950;
    int r = 0;
    if (*(int *)(a + 0x48) == 4 && *(int *)(a + 0x50) == 0)
        r = *(int *)(p + 0x20) == 0;
    return r;
}
#endif

// FUNCTION: GAME 0x35C200
void func_0035C200(char *a, int b, int c)
{
    char *p = a + c * 0x44; char *q = a + b * 0x74; *(int *)(p + 0x1F40) = b; *(int *)(q + 0x1360) = c;
}

// FUNCTION: GAME 0x35B218
void func_0035B218(int a, int b, int c, int *d)
{
    func_0035B188(0x5DC0);
    *d = a;
}

// FUNCTION: GAME 0x35B250
void func_0035B250(int a, int b, int c, int *d)
{
    func_0035B188(0x7530);
    *d = a;
}

// FUNCTION: GAME 0x35B288
void func_0035B288(int a, int b, int c, int *d)
{
    func_0035B188(0xEA60);
    *d = a;
}

// FUNCTION: GAME 0x35BB08
long func_0035BB08()
{
    if (!D_00766C80)
        func_0035BA58();
    return D_00766C80;
}

// FUNCTION: GAME 0x35B678
int func_0035B678(char *a, int *b)
{
    if (!b) return 0; return func_0035B6B0(a, b[5], b[6]);
}

// FUNCTION: GAME 0x35B6B0
int func_0035B6B0(char *a, int b, int c)
{
    char *p = a + 0xA0C;
    int out;
    if (*(int *)(p + 0x38) != 0)
        return 1;
    func_0035B6F8(a, b, c, &out, *(int *)(p + 0xB0));
    return out;
}

extern int D_00459920[];
extern int func_00358A48();
extern int func_00358FF8();
extern int func_0035A8E8();
extern int func_0034DD70();
extern int func_003B7FE0();

#ifdef NONMATCHING
// DRAFT: GAME 0x35EB60 gcc emits xori/movz with 4 in a0; original xor with a2 (0x51 kept) and movn; 8 words
int func_0035EB60(int *a, int *b)
{
    int t = a[1]; if (t == 0x51) return 4; if (t == 0x61) return 5; return b[0x94 / 4] != 0x51 ? 5 : 4;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3581E0 bnez skip target: original returns the nonzero callee result (skips daddu v0); 1 word
int func_003581E0(char *a)
{
    if (func_00358A48(a))
        return 0;
    *(int *)(a + 0x4C) = 6;
    func_00358FF8(a);
    return 0;
}
#endif

// FUNCTION: GAME 0x35A8A8
int func_0035A8A8(int a)
{
    if (func_0035A8E8(a)) {
        func_0034DD70(a, 0xFF000222);
        return 1;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x35B5B8 original hoists lui/addu for D_00459920 before the 0x3E8 store; gcc stores first; 5 words
void func_0035B5B8(char *a, int *b, int *c)
{
    int i = *(int *)(a + 0x920); if (i == 0) { *b = 0; *c = 0x7512; } else { *b = 0x3E8; *c = D_00459920[i]; }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35BB60 min/max/sum register assignment and store order differ; 12 words
void func_0035BB60(long *a, long b)
{
    long s = a[0]; long mn = a[1]; long mx = a[2]; int n = *(int *)((char *)a + 0x18); s += b; if (b < mn) mn = b; if (mx < b) mx = b; n++; *(int *)((char *)a + 0x18) = n; a[0] = s; a[1] = mn; a[2] = mx;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35C1C0 a0+d*0x74 kept in a0 by the original; gcc uses v0; 2 words
void func_0035C1C0(char *a, int b, int c, int d)
{
    char *p = a + b * 0x44;
    *(int *)(p + c * 4 + 0x1F44) = d;
    *(int *)(a + d * 0x74 + 0x135C) = b;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35A5E0 original copies hi into v1 before the branch; gcc skips it; 9 words
int func_0035A5E0(char *a, int b)
{
    int x = *(int *)(a + 0x294); int hi = x + *(int *)(a + 0x298); int lim = x + *(int *)(a + 0x29C); if (b < hi) return hi; return b < lim ? lim : 0x7FFFFFFF;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x352258 mult and sd ra are swapped in the prologue; 2 words
int func_00352258(int a)
{
    int r = func_003B7FE0((long)a * 0x55D4A80);
    // barrier after the call blocks gcc 2.96 from turning it into a tail jump
    __asm__ volatile("");
    return r;
}
#endif

extern void *memcpy();
extern int func_00351C00();
extern int func_0039A8E8();
extern int func_00366B80();
extern int D_004598E0;
extern int D_003EE2F4;
extern char D_00766C28[];

// FUNCTION: GAME 0x354430
void func_00354430(int *a, int *b)
{
    memcpy((void *)a[0], (void *)b[0], b[1]);
    a[1] = b[1];
}

#ifdef NONMATCHING
// DRAFT: GAME 0x354B98 original splits the three early returns into separate epilogues and keeps the tail j; gcc merges them; 9 words
void func_00354B98(int a, int b)
{
    if (b < -3)
        return;
    if (b < -1)
        return;
    if (b == 0)
        return;
    func_0034DD70(a, b);
}
#endif

// FUNCTION: GAME 0x3571F8
void func_003571F8()
{
    if (D_004598E0 != 0x5A5A5A5A)
        func_0034DD70(0, 0xFF000201);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x351BB8 original compares the call result with 1 via beq and branches; gcc folds to xori/sltiu; 8 words
int func_00351BB8(int a, int b, int c)
{
    if (c == 0x80)
        return 1;
    if (b >= 5)
        return 0;
    return func_00351C00() == 1;
}
#endif

// FUNCTION: GAME 0x356368
int func_00356368()
{
    if (D_003EE2F4) {
        func_0039A8E8();
        return func_00366B80(D_00766C28, 0, 0x48);
    }
}

extern int func_0035D7B8();

#ifdef NONMATCHING
// DRAFT: GAME 0x35DE38 s0/s1 spill order in the prologue is swapped (sd s1 before sd s0); 2 words
int func_0035DE38(int *a, int *b)
{
    char *p = (char *)a[1] + 0xB0;
    *b = 0;
    if (func_0035D7B8(a)) {
        *b = *(unsigned char *)p;
        return 1;
    }
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x35DE88 s0/s1 spill order in the prologue is swapped (sd s1 before sd s0); 2 words
int func_0035DE88(int *a, int *b)
{
    char *p = (char *)a[1] + 0xB0;
    *b = 0;
    if (func_0035D7B8(a)) {
        *b = *(unsigned char *)(p + 1);
        return 1;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x355408
char *func_00355408(char *a, char *b)
{
    char *s = *(char **)(a + 0x1FC0) + 0x180;
    char *q = a + 0x16B0;
    int i;
    for (i = 0; i < 16; i++) {
        if (q + 8 == b)
            return s;
        q += 0x88;
        s += 0xF0;
    }
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x355490 original loads a3=0 and the limit before forming a0+0x16B0; gcc schedules the addiu earlier; 5 words
char *func_00355490(char *a, char *b)
{
    char *t = *(char **)(a + 0x1FC0);
    int n = *(int *)(t + 0x178);
    char *s = t + 0x180;
    char *q = a + 0x16B0;
    int i;
    for (i = 0; i < n; i++) {
        if (s == b)
            return q;
        q += 0x88;
        s += 0xF0;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x359DA8
int func_00359DA8(char *a)
{
    char *p = a + 0x1F30; int v; a += *(int *)(p + 0x14) * 0x74; p += *(int *)(a + 0x1360) * 0x44; v = *(int *)(p + 0x20); if (v < 0) return -1; return v;
}

// FUNCTION: GAME 0x35BD88
void func_0035BD88(int *a, int b)
{
    int i;
    a[1] = 0;
    a[0] = 0;
    a[3] = b;
    a[4] = 8;
    for (i = 2; i >= 0; i--)
        a[5 + i] = 8;
    a[8] = -1;
}
