// COMPILER: ee-gcc2.96
int func_00355508(int);
int func_00350BE8(int, int);
void func_00350C58(int, int);
void func_0035A000(int, int, int);
int func_00356358(int);
void func_003562A0(int);
int func_00358A38(void);
int func_0039A998(int);
void func_0039AA48(void);
int func_00356868(int);

// FUNCTION: GAME 0x350B60
void func_00350B60(int a)
{
    int *s = (int *)(a + 0x950);
    int r = func_00355508(a);
    if (r == -1 || func_00350BE8(a, r) != 0) {
        func_00350C58(a, 1);
        if (*s == 0) func_0035A000(a, 5, 0);
    }
}

// FUNCTION: GAME 0x357720
void func_00357720(int a)
{
    int *s = (int *)(a + 0xA0C);
    if (s[0x18 / 4] == 0 && s[0x3C / 4] == 2) func_0035A000(a, 0xF, 1);
    if (s[0x14 / 4] == 0 && s[0x3C / 4] == 1) func_0035A000(a, 0xF, 2);
}

// FUNCTION: GAME 0x3567E0
int func_003567E0(int a)
{
    int s;
    if (func_00356358(a)) {
        s = *(int *)(a + 0x1FC0);
        func_003562A0(s + 0x1198);
        if (func_00358A38() != 1) {

            return func_0039A998(s + 0x1150);
        }
        func_0039AA48();
        return func_00356868(a);
    }
    return 0;
}

extern int D_003EE2C4[];
int func_0034DEC8(int);
int func_0034DD70();
void func_00359848(void);
int func_00359CB8(int);

// FUNCTION: GAME 0x358328
int func_00358328(void)
{
    int *p = D_003EE2C4;
    int i;
    for (i = 0; i < 8; i++, p++)
        if (*p == 0) return i;
    return -1;
}

// FUNCTION: GAME 0x3596F0
int func_003596F0(int a, int b)
{
    int *p = (int *)(a + b * 0x74 + 0x1348);
    if (p[0] == 0) return 0;
    return (p[2] < p[1]) ^ 1;
}

// FUNCTION: GAME 0x359800
void func_00359800(int a)
{
    if (*(int *)(a + 0x36B0) != 0) {
        func_00359848();
        func_00359CB8(a);
    }
}

// FUNCTION: GAME 0x359E80
int func_00359E80(int a)
{
    if (func_0034DEC8(a) != 0) func_0034DD70(0, 0xFF000111);
    return *(int *)(a + 0x48);
}

int func_0035A0A0(int);
int func_0035A1C8(int, int);
void func_0035A518(int);
void func_0035B058(int);
void func_0035A6F8(int);
int func_0035AE18();

// DRAFT: GAME 0x35A000
// regs s1/s2 swapped (4 words)
#ifdef NONMATCHING
void func_0035A000(int a, int b, int c)
{
    if (func_0035A0A0(a)) *(int *)(a + b * 4 + 0xA0C) = c;
}
#endif

// DRAFT: GAME 0x35A050
// regs s1/s2 swapped (4 words)
#ifdef NONMATCHING
void func_0035A050(int a, int b, int c)
{
    if (func_0035A0A0(a)) *(int *)(a + b * 4 + 0xB9C) = c;
}
#endif

// FUNCTION: GAME 0x35A4D0
void func_0035A4D0(int *a, int b)
{
    *a = 0;
    func_0035A518((int)(a + 1));
    a[9] = b;
    a[10] = 1;
}

// FUNCTION: GAME 0x35A6A8
void func_0035A6A8(int a)
{
    func_0035A6F8(a);
    if (func_0035A1C8(a, 0x47) == 1) func_0035B058(a);
}

// DRAFT: GAME 0x35A7C8
// orig if/else with nop delay, mine merges bnel (10 words)
#ifdef NONMATCHING
void func_0035A7C8(int a, int *b)
{
    if (func_0035A1C8(a, 0x47) == 1) {
        b[0x2D0 / 4] = b[0x2A8 / 4];
    } else {
        b[0x2D0 / 4] = b[0x2DC / 4];
    }
}
#endif

// FUNCTION: GAME 0x35AC58
int func_0035AC58(int a, int *b, int *c)
{
    int r = func_0035AE18(a);
    if (r) {
        *b = -2;
        *c = 1;
        return 0;
    }
    return r;
}

// DRAFT: GAME 0x35AE18
// 12 words off, mine 84 vs 80 B
#ifdef NONMATCHING
int func_0035AE18(int a, int *b, int *c)
{
    int v = *(int *)(a + 0x48);
    if (v == 4 || v == -4 || v == 6 || v == -6) return 1;
    *b = -1;
    *c = 1;
    return 0;
}
#endif

extern void *memset(void *, int, unsigned);
// FUNCTION: GAME 0x35C480
void func_0035C480(int a)
{
    memset((void *)(a + 0x18), 0, 0xF0);
    *(int *)(a + 0x14) = 0;
    *(int *)(a + 0x19C) += 1;
}

int func_0035CFC8(int);
int func_0035D0D8(int);
int func_0035D050(int);
int func_0035B9B0(int);
extern int D_00766C9C;
extern int D_00766C90;
void func_0035D708(int *);
int func_0035CAC8(int);

// FUNCTION: GAME 0x35CF80
int func_0035CF80(int a)
{
    int r;
    func_0035CFC8(a);
    r = func_0035D0D8(a);
    func_0035D050(a);
    return r;
}

// DRAFT: GAME 0x35D360
// branch layout inverted (6 words)
#ifdef NONMATCHING
int func_0035D360(int a)
{
    if (func_0035A1C8(a, 0xF) != 0) return func_0035B9B0(a) != 0;
    return 1;
}
#endif

// FUNCTION: GAME 0x35D5C8
void func_0035D5C8(void)
{
    if (--D_00766C9C <= 0) func_0035D708(&D_00766C90);
}

// FUNCTION: GAME 0x35CA68
void func_0035CA68(int *a, int b)
{
    int i;
    for (i = 0; i < a[4]; i++) a[6 + i] -= b;
    a[0x1A8 / 4] = func_0035CAC8((int)a);
}

int func_0035D800(int);

// FUNCTION: GAME 0x35D7B8
int func_0035D7B8(int a)
{
    int v;
    if (func_0035D800(a) == 0) return 0;
    v = *(int *)(a + 0xC);
    if (v == 0x6B || v >= 0x6E) return 1;
    return 0;
}

// FUNCTION: GAME 0x35DC10
int func_0035DC10(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(int *)s;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35DC60
int func_0035DC60(int a, int *b)
{
    int s;
    *b = -1;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(unsigned char *)(s + 4);
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35DCB0
int func_0035DCB0(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(short *)(s + 8);
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35DD00
int func_0035DD00(int a, int *b)
{
    int s;
    *b = 0;
    s = *(int *)(a + 4) + 0x80;
    if (func_0035D7B8(a)) {
        *b = *(int *)(s + 0xC);
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x35DA58
int func_0035DA58(int a, int b)
{
    int r = 0;
    int i;
    for (i = 0; i < 0x1A; i++) {
        int p = a + i * 64 + 0x180;
        if (*(unsigned char *)(p + 0x18) == b) {
            r = p;
            break;
        }
    }
    return r;
}

void func_0035D728(int);
int func_0035E9E8(int);

// FUNCTION: GAME 0x35D758
void func_0035D758(int n, int p)
{
    if (n > 0) {
        do {
            func_0035D728(p);
            p += 0x10;
        } while (--n != 0);
    }
}

// FUNCTION: GAME 0x35E968
int func_0035E968(int a, int b)
{
    if (func_0035E9E8(a) == 0xC0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}

// FUNCTION: GAME 0x35E9A8
int func_0035E9A8(int a, int b)
{
    if (func_0035E9E8(a) == 0xE0) return (*(unsigned char *)(b + 0x20) != 0) & (*(unsigned char *)(b + 0x20) >= 2);
    return 0;
}
