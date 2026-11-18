// COMPILER: ee-gcc2.9-991111
// SCE library units built by SCE ee-gcc 2.9x (sd s0 prologues), -O2 -G0.

extern int *func_003A4FB8(void);
extern void iSignalSema(int);
extern void func_003B0D80(int);
extern void func_003B0D48(int);
extern void func_003B0E30(int);
extern void func_003B2450(void);
extern int D_003FAE54;
extern void func_003B3E70(void);
extern int D_003FAEE4;
extern int WaitSema(int);
extern int func_003B5C48(int, int, int, int *);
extern int func_003B5E78(int, int, int, int *, int);
extern void func_003B6818(int);
extern void func_003AF8C0(int);
extern int func_003B00D0(int, int *);
extern void (*D_003D141C)(void);

// FUNCTION: GAME 0x3B0360
int func_003B0360(void)
{
    *func_003A4FB8() = 5;
    return -1;
}

// FUNCTION: GAME 0x3B0D20
int func_003B0D20(int a, int b, int c, int d)
{
    iSignalSema(d);
    __asm__ volatile("sync\n\tei");
    return 0;
}

// FUNCTION: GAME 0x3B0E30
void func_003B0E30(int c)
{
    if (c == 10) {
        func_003B0D48(13);
        func_003B0D48(10);
    } else
        func_003B0D48(c);
}

// FUNCTION: GAME 0x3B1E40
int func_003B1E40(int a, int b, int c)
{
    if (c)
        func_003B0D80(c);
    return 1;
}

// FUNCTION: GAME 0x3B1E68
int func_003B1E68(int a, int b, int c)
{
    if (c)
        func_003B0E30(c);
    return 1;
}

// FUNCTION: GAME 0x3B2AA0
void func_003B2AA0(void)
{
    func_003B2450();
    D_003FAE54 = 0;
}

// FUNCTION: GAME 0x3B3EC8
int func_003B3EC8(void)
{
    func_003B3E70();
    WaitSema(D_003FAEE4);
    return 0;
}

// FUNCTION: GAME 0x3B5E50
int func_003B5E50(int a, int b, int c)
{
    int v;
    return func_003B5C48(a, b, c, &v);
}

// FUNCTION: GAME 0x3B60A0
int func_003B60A0(int a, int b, int c)
{
    int v;
    return func_003B5E78(a, b, c, &v, 0);
}

// FUNCTION: GAME 0x3B6820
void func_003B6820(int a)
{
    func_003B6818(a);
    func_003AF8C0(a);
}

// FUNCTION: GAME 0x3B7AA8
int func_003B7AA8(int a)
{
    int v = a;
    return func_003B00D0(0x10, &v);
}

// FUNCTION: GAME 0x3B9AF8
void func_003B9AF8(void)
{
    if (D_003D141C)
        D_003D141C();
}

extern int func_003B2B90();
extern int func_003B26C8();
extern int func_003B0100();
extern int func_003B0110();
extern int func_003B7C58();

// FUNCTION: GAME 0x3B2BC0
int func_003B2BC0(int *a, int b)
{
    if (b < 0 || b >= a[8])
        return func_003B2B90();
    return a[7] + (b << 6);
}

// FUNCTION: GAME 0x3B2CD0
int func_003B2CD0(int a, int b, int c, int *d)
{
    return func_003B26C8(0x80000008, d, 0x40, d[9], d[10], d[11]) ? 0 : 0x800;
}

// FUNCTION: GAME 0x3B7C18
int func_003B7C18(void)
{
    if (func_003B0100() == 0x2000000)
        return func_003B7C58();
    return func_003B0110();
}

// FUNCTION: GAME 0x3B2E38
int func_003B2E38(int a, int b, int c, int d)
{
    return func_003B26C8(0x80000008, d, 0x40, 0, 0, 0) ? 0 : 0x800;
}

extern int func_003B63A0();
extern void func_003B63F0();
extern int func_003AF9F0();
extern int func_003AF9E0();
extern int func_003AFA10();
extern int func_003AFA00();

// FUNCTION: GAME 0x3B06D8
int func_003B06D8(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AF9F0(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B0740
int func_003B0740(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AF9E0(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B07A8
int func_003B07A8(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AFA10(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

// FUNCTION: GAME 0x3B0810
int func_003B0810(int a)
{
    int s0, r;
    __asm__ volatile("mfc0 %0, $12" : "=r"(s0));
    s0 &= 0x10000;
    if (s0)
        func_003B63A0();
    r = func_003AFA00(a);
    __asm__ volatile("sync");
    if (s0)
        func_003B63F0();
    return r;
}

extern void func_003AFD50();
extern void func_003AFD40();

// FUNCTION: GAME 0x3B66D0
int func_003B66D0(void)
{
    unsigned v[2];
    func_003AFD50(&v[0]);
    v[1] = (v[0] & 0xFFFF1FFF) | 0x2000;
    func_003AFD40(&v[1]);
    func_003AFD50(&v[1]);
    func_003AFD40(&v[0]);
    return ((v[1] >> 13) & 7) == 0;
}

extern int memcmp(const void *, const void *, unsigned);
extern int func_003B2080();
extern int func_003B0060();
extern int D_003FAE50;
extern char D_003FAE3C[];
extern char D_007816E8[];
extern char *D_003FAEF0;
extern char D_00781BA8[];
extern char *D_003FAEFC;
extern void func_003B6A10();
extern int func_003B7130();
extern void func_003B6C28();

struct SifNode {
    int a, b, c, d, e;
    struct SifNode *next;
};
struct SifHead {
    char pad[0x28];
    struct SifNode *head;
};
extern struct SifHead D_0077FF40;
struct SifNode2 {
    int a[14];
    struct SifNode2 *next;
};
struct SifList {
    int pad[2];
    struct SifNode2 *head;
};

// FUNCTION: GAME 0x3B2148
int func_003B2148(int a, int b)
{
    int ie = func_003B63A0();
    if (D_003FAE50) {
        if (ie)
            func_003B63F0();
        return func_003B2080(a, b, 0);
    }
    if (ie)
        func_003B63F0();
    return func_003B0060(a, b);
}

// FUNCTION: GAME 0x3B3368
void sceSifSetRpcQueue(struct SifNode *n, int b)
{
    struct SifNode *p, *h;
    func_003B63A0();
    n->a = b;
    n->b = 0;
    h = D_0077FF40.head;
    n->c = 0;
    n->d = 0;
    n->e = 0;
    n->next = 0;
    if (!h) {
        D_0077FF40.head = n;
    } else {
        p = h;
        while (p->next)
            p = p->next;
        p->next = n;
    }
    func_003B63F0();
}

// FUNCTION: GAME 0x3B34D0
struct SifNode2 *sceSifRemoveRpc(struct SifNode2 *n, struct SifList *l)
{
    struct SifNode2 *p;
    func_003B63A0();
    p = l->head;
    if (p == n) {
        l->head = p->next;
    } else {
        for (; p; p = p->next) {
            if (p->next == n) {
                p->next = n->next;
                break;
            }
        }
    }
    func_003B63F0();
    return p;
}

// FUNCTION: GAME 0x3B3568
struct SifNode *sceSifRemoveRpcQueue(struct SifNode *n)
{
    struct SifNode *p;
    func_003B63A0();
    p = D_0077FF40.head;
    if (p == n) {
        D_0077FF40.head = p->next;
    } else {
        for (; p; p = p->next) {
            if (p->next == n) {
                p->next = n->next;
                break;
            }
        }
    }
    func_003B63F0();
    return p;
}

// FUNCTION: GAME 0x3B4158
int func_003B4158(void)
{
    char *b = D_003FAE3C;
    char *a = D_007816E8;
    int r = 0;
    if (memcmp(a, b, 4))
        if (memcmp(a, D_003FAEF0, 4))
            r = memcmp(b, D_003FAEF0, 4) != 0;
    return r;
}

// FUNCTION: GAME 0x3B5B80
int func_003B5B80(void)
{
    char *b = D_003FAE3C;
    char *a = D_00781BA8;
    int r = 0;
    if (memcmp(a, b, 4))
        if (memcmp(a, D_003FAEFC, 4))
            r = memcmp(b, D_003FAEFC, 4) != 0;
    return r;
}

// FUNCTION: GAME 0x3B6B90
int func_003B6B90(void)
{
    int ie = func_003B63A0();
    unsigned v = *(volatile unsigned *)0x10001010;
    if (v & 0x80) {
        if (ie)
            func_003B63F0();
        return 1;
    }
    func_003B6A10((v & 0xFFFFF3FF) | 0x80);
    func_003B6C28(func_003B7130());
    if (ie)
        func_003B63F0();
    return 0;
}

extern void func_003BA9F0();
extern void func_003BA978();

// FUNCTION: GAME 0x3BA978
void func_003BA978(int a)
{
    int r = func_003B63A0(a);
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B000 = a;
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
}

// FUNCTION: GAME 0x3BA9F0
void func_003BA9F0(int a)
{
    int r = func_003B63A0();
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 | 0x10000;
    *(volatile int *)0x1000B400 = a;
    *(volatile unsigned *)0x1000F590 = *(volatile unsigned *)0x1000F520 & 0xFFFEFFFF;
    if (r)
        func_003B63F0();
}

// FUNCTION: GAME 0x3BAA68
void func_003BAA68(int *a)
{
    func_003BA9F0(1);
    a[0] = *(volatile int *)0x1000B410;
    a[1] = *(volatile int *)0x1000B430;
    a[2] = *(volatile int *)0x1000B420;
    a[3] = *(volatile int *)0x1000B400;
    while (*(volatile unsigned *)0x10002010 & 0xF0)
        ;
    func_003BA978(0);
    a[4] = *(volatile int *)0x1000B010;
    a[5] = *(volatile int *)0x1000B020;
    a[6] = *(volatile int *)0x1000B000;
    a[7] = *(volatile int *)0x10002020;
    a[8] = *(volatile int *)0x10002010;
}

// FUNCTION: GAME 0x3BAB50
void func_003BAB50(unsigned *o)
{
    unsigned v = o[7];
    unsigned ch = v & 0x7F;
    unsigned sum = ((v >> 16) & 3) + ((v >> 8) & 0xF);
    unsigned b = o[0] - (sum << 4);
    unsigned a = o[2] + sum;
    if (o[4] && o[5]) {
        *(volatile unsigned *)0x1000B010 = o[4];
        *(volatile unsigned *)0x1000B020 = o[5];
        func_003BA978(o[6] | 0x100);
    }
    while (*(volatile int *)0x10002010 < 0)
        ;
    *(volatile unsigned *)0x10002000 = ch;
    while (*(volatile int *)0x10002010 < 0)
        ;
    if (b && a) {
        *(volatile unsigned *)0x1000B410 = b;
        *(volatile unsigned *)0x1000B430 = o[1];
        *(volatile unsigned *)0x1000B420 = a;
        func_003BA9F0(o[3] | 0x100);
    }
}
