// COMPILER: ee-gcc2.9-991111
// SCE library small units 0x3B1000-0x3BC000, ee-gcc 2.9-991111 -O2 -G0.

#define MFC0_12 ".set push\n.set noreorder\nmfc0 %0, $12\n.set pop"

extern int D_00781780;
struct H { void (*fn)(int); int arg; };
#ifdef NONMATCHING
// DRAFT: GAME 0x3B3F08 (2 words off: original schedules lui before daddu $s0,$gp)
void func_003B3F08(int a0, struct H *h)
{
    if (h->fn) {
        int sv;
        __asm__ volatile("move %0, $28" : "=r"(sv));
        __asm__ volatile("lw $28, %0" : : "m"(D_00781780));
        h->fn(h->arg);
        __asm__ volatile("move $28, %0" : : "r"(sv));
    }
    __asm__ volatile("sync");
    __asm__ volatile("ei");
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B63A0 (8 words off: original returns via a0=0 on the not-enabled path, 80 vs 68 bytes)
int func_003B63A0(void)
{
    int s;
    unsigned t;
    __asm__ volatile(MFC0_12 : "=r"(s));
    s &= 0x10000;
    if (s) {
        do {
            __asm__ volatile("di");
            __asm__ volatile("sync.p");
            __asm__ volatile(MFC0_12 : "=r"(t));
        } while (t & 0x10000);
        return s != 0;
    }
    return 0;
}
#endif

// FUNCTION: GAME 0x3B63F0
int func_003B63F0(void)
{
    int s;
    __asm__ volatile(MFC0_12 : "=r"(s));
    s &= 0x10000;
    __asm__ volatile("ei");
    return s != 0;
}

extern void func_003B6408(void);
extern void func_003B6500(void);
extern void func_003B68B8(void);
extern void func_003B6A30(int);
extern void func_003B6B90(void);
extern void func_003B0950(void);
extern void func_003B6738(void);
extern void func_003B7B40(void);
extern void func_003B7988(void);
// FUNCTION: GAME 0x3B6610
void func_003B6610(void)
{
    func_003B6408();
    func_003B6500();
    func_003B68B8();
    func_003B6A30(2);
    func_003B6B90();
    func_003B0950();
    func_003B6738();
    func_003B7B40();
    func_003B7988();
}

extern int D_003FAEF4;
extern int D_00781840;
extern char D_007817C0[];
extern int D_00781800;
extern int sceSifCallRpc();
// FUNCTION: GAME 0x3B5968
int func_003B5968(int a)
{
    int buf[4];
    if (D_003FAEF4 >= 0) {
        D_00781840 = a;
        buf[0] = 0;
        if (sceSifCallRpc(D_007817C0, 1, 0, &D_00781840, 4, &D_00781800, 4, 0) >= 0)
            return D_00781800;
    }
    return 0;
}

// FUNCTION: GAME 0x3B59D8
int func_003B59D8(int a)
{
    int buf[4];
    if (D_003FAEF4 < 0)
        return 0;
    D_00781840 = a;
    buf[0] = 0;
    if (sceSifCallRpc(D_007817C0, 2, 0, &D_00781840, 4, &D_00781800, 4, 0) >= 0)
        return D_00781800;
    return -1;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3B2488 (28 words off: original keeps the array base reloaded for the 3rd store and un-shared index math; mine CSEs, 84 vs 120 bytes)
struct E { int a, b, gp; };
struct T { int pad[3]; struct E *neg; int pad2; struct E *pos; };
extern struct T D_0077E518;
register int gp __asm__("$28");
void func_003B2488(int i, int x, int y)
{
    if (i < 0) {
        struct E *e;
        i &= 0x7FFFFFFF;
        e = &D_0077E518.neg[i];
        e->b = y;
        e->a = x;
        D_0077E518.neg[i].gp = gp;
    } else {
        struct E *e = &D_0077E518.pos[i];
        e->b = y;
        e->a = x;
        D_0077E518.pos[i].gp = gp;
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B58E0 (3 words off: original puts lui in $v0 and fills the sw delay slot)
extern int sceSifBindRpc();
int func_003B58E0(void)
{
    int *p;
    for (;;) {
        if (sceSifBindRpc(D_007817C0, 0x80000003, 0) < 0)
            return -1;
        if (*(int *)(D_007817C0 + 0x24) != 0)
            break;
        {
            int i = 0x100000;
            do {
                i--;
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
                __asm__ volatile("nop");
            } while (i != -1);
        }
    }
    D_003FAEF4 = 0;
    return 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B6738 (5 words off: arg load order of the 3rd func_003B6668 call, loop uses plain bnez)
extern int func_003B66D0(void);
extern void func_003B6668(int, int);
extern void func_003B6678(int, void *, int);
extern int func_003B66C0(void);
extern void FlushCache(int);
extern int D_003FB6C8[];
extern char D_003FAF20[];
void func_003B6738(void)
{
    unsigned i;
    int *p;
    int *b;
    if (func_003B66D0() == 0)
        return;
    i = 2;
    b = D_003FB6C8;
    p = b + 4;
    func_003B6668(b[0], b[1]);
    func_003B6678(0x80074000, D_003FAF20, 0x7A8);
    FlushCache(0);
    FlushCache(2);
    func_003B6668(b[2], b[3]);
    do {
        i++;
        func_003B6668(p[0], func_003B66C0());
        p += 2;
    } while (i < 3);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B7200 (19 words off: original keeps D_003FBE90 base in $a3 and orders the stores differently)
struct N { struct N *next; int p4; volatile int id; int f0c; int p10, p14; long f18; int p20, p24; int f28; };
struct Q { int p[3]; volatile int ctr; int cnt; struct N *head; };
extern struct Q D_003FBE90;
int func_003B7200(void)
{
    struct Q *q = &D_003FBE90;
    struct N *n = q->head;
    if (n == 0)
        return 0x80008005;
    q->cnt++;
    n->f28 = 0;
    n->f0c = 0;
    q->head = n->next;
    n->f18 = 0;
    q->ctr++;
    n->id = ((q->ctr << 1) & 0x3FE) | 1;
    return ((int)n << 4) | n->id;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x3B68B8
// diff: 2 words; original loads a0 (p[2]) before a1 (p[3]) for the second func_003B6850 call (3 variants tried)
extern int D_003FBE50[];
extern char D_003FB6E8[];
extern char D_003FBE28[];
extern void func_003B6850(int, int);
extern void func_003B6860(int, void *, int);
extern int func_003B68A8(int);
extern void FlushCache(int);
void func_003B68B8(void)
{
    int *p;
    int *q;
    unsigned i;
    if ((*(volatile unsigned int *)0x10001810 & 0x100) == 0) {
        p = D_003FBE50;
        func_003B6850(p[0], p[1]);
        q = p + 4;
        func_003B6860(0x80076000, D_003FB6E8, 0x740);
        func_003B6860(0x82000, D_003FBE28, 0x28);
        FlushCache(0);
        FlushCache(2);
        func_003B6850(p[2], p[3]);
        for (i = 2; i < 8; i++) {
            int v = func_003B68A8(q[0]);
            func_003B6850(q[0], v);
            q += 2;
        }
    }
}
#endif
