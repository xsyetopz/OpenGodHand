// Medium units of 0x2A0000-0x2AFFFF.

// FUNCTION: GAME 0x2A8B90
struct S8 { unsigned a; int b; };
extern "C" {
void func_002A8AA8(S8 *, int, int, long, void *);
void func_002A8B90(S8 *first, S8 *last, void *cmp)
{
    int n = last - first;
    if (n >= 2) {
        int i = (n - 2) / 2;
        S8 *p = (S8 *)((char *)(i * 8) + (long)first);
        for (;;) {
            S8 t = *p;
            func_002A8AA8(first, i, n, ((long)t.b << 32) | t.a, cmp);
            if (i == 0)
                return;
            p--;
            i--;
        }
    }
}
}

// FUNCTION: GAME 0x2A9538
struct N { char p0[8]; N *next; unsigned cap; unsigned off; };
struct L { N *head; };
extern unsigned D_00747A34;
extern "C" {
void func_002A9620(L *, N *, N *);
char *func_002A9538(L *l, unsigned size, unsigned align)
{
    if (D_00747A34 & 0x80000)
        return 0;
    if (size == 0)
        return 0;
    for (N *n = l->head; n; n = n->next) {
        unsigned need = size + 0x20;
        if (n->cap < need)
            continue;
        char *e = (char *)n + n->off;
        char *r = (char *)(((unsigned long)(e + 0x1F) + align) & -align);
        N *h = (N *)(r - 0x20);
        unsigned gap = (char *)h - e;
        unsigned tot = need + gap;
        if (n->cap >= tot) {
            func_002A9620(l, h, n);
            h->off = need;
            h->cap = n->cap - tot;
            n->cap = gap;
            return r;
        }
    }
    return 0;
}
}

extern "C" {
void *memset(void *, int, unsigned);
// FUNCTION: GAME 0x2ACE48
char *func_002ACE48(char *b, int n, int a, int c)
{
#define F(T, o) *(T *)(b + (*(int *)(b + 0x740) << 4) + o)
    if (n == 0) return 0;
    int used = *(int *)(b + 0x18000 + 0x3544);
    if (0x280 - used < n) return 0;
    char *slot = b + (used * 0xAC + 0x744);
    F(unsigned char, 0x10D) = 1;
    F(char *, 0x108) = slot;
    F(unsigned char, 0x10C) = n;
    F(int, 0x100) = a;
    F(int, 0x104) = c;
    (*(int *)(b + 0x740))++;
    *(int *)(b + 0x18000 + 0x3544) += n;
    memset(slot, 0, n * 0xAC);
    return slot;
}
}

extern int *IDSys;
extern int IDManager;
extern "C" {
void func_002AA2D0(void *, char *, char *);
// FUNCTION: GAME 0x2AA1E0
void func_002AA1E0(char **o, char *s, int n)
{
    *o = s;
    memset(o[1], 0, n * 0xAC);
    for (int i = 0; i < n; i++) {
        if (*IDSys == IDManager) {
            while (*(unsigned *)(s + 4) & 0x200) s += 0x2E0;
        }
        func_002AA2D0(o, s, o[1] + i * 0xAC);
        s += 0x2E0;
    }
}
}

extern "C" void DllLoad__3cMcb(void *, int);
extern "C" void DllRelease__3cMc(void *);
extern "C" void exit__9cTaskWork(void *);
extern "C" void func_0(void *);
extern "C" void func_002D5958(void *, void *);
extern "C" void func_0030DA08();
struct GT { int p; void *t; };
struct U84 { int a; unsigned f; };
extern char Mc;
extern char D_Ev297AA8[];
extern void *D_00752C04;
extern U84 D_00747A84;
extern GT GlobalTask;
// FUNCTION: GAME 0x2AE788
extern "C" void func_002AE788()
{
    DllLoad__3cMcb(&Mc, 0);
    func_0(D_Ev297AA8);
    func_0(D_Ev297AA8);
    DllRelease__3cMc(&Mc);
    exit__9cTaskWork(D_00752C04);
}
// FUNCTION: GAME 0x2AE8A8
extern "C" void func_002AE8A8()
{
    D_00747A84.f |= 0x80000000;
    DllLoad__3cMcb(&Mc, 0);
    func_0(D_Ev297AA8);
    DllRelease__3cMc(&Mc);
    D_00747A84.f &= 0x7FFFFFFF;
    func_002D5958(GlobalTask.t, (void *)func_0030DA08);
    exit__9cTaskWork(GlobalTask.t);
}
extern "C" void func_00394F20(void *);
extern "C" void free__5cHeapPv(void *, void *);
struct OB { unsigned char f; int p; };
extern char SubScrHeap;
// FUNCTION: GAME 0x2AE5E8
extern "C" void DllRelease__3cMc(void *v)
{
    OB *o = (OB *)v;
    if (o->f == 1) {
        func_0(D_Ev297AA8);
        func_00394F20((void *)o->p);
        o->f = 0;
    }
    if (o->p) {
        free__5cHeapPv(&SubScrHeap, (void *)o->p);
        o->p = 0;
    }
}
