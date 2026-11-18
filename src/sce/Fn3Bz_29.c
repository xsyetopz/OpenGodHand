// COMPILER: ee-gcc2.9-991111

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

extern int func_003B2550();

// FUNCTION: GAME 0x3B2688
int func_003B2688(int a, int b, int c, int d, int e, int f)
{
    return func_003B2550(a, 0, b, c, d, e, f);
}

// FUNCTION: GAME 0x3B26C8
int func_003B26C8(int a, int b, int c, int d, int e, int f)
{
    return func_003B2550(a, 1, b, c, d, e, f);
}

// DRAFT: GAME 0x3B3328
// diff: original keeps separate return-0/return-1 exits (60 bytes); 2.9 merges them (44 bytes)
#ifdef NONMATCHING
int func_003B3328(int *p)
{
    int *q = (int *)p[0];
    if (q && p[1] == q[6] && (q[4] & 1))
        return 1;
    return 0;
}
#endif

extern int func_003B35F8();
extern void func_003B3650();
extern void func_003AFBC0();

// FUNCTION: GAME 0x3B3818
void sceSifRpcLoop(int a)
{
    int r;
    for (;;) {
        while ((r = func_003B35F8(a)) != 0)
            func_003B3650(r);
        func_003AFBC0();
    }
}

// FUNCTION: GAME 0x3B64A8
int *func_003B64A8(int *p, int *end, int v)
{
    while (*p != v && p < end)
        p++;
    return p < end ? p : 0;
}
