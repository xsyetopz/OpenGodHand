// COMPILER: ee-gcc2.9-991111
// SDK thread helpers: dispatcher setup and DelayThread.

struct SemaP { int count, max, init, wait, attr; char *opt; };

struct ThP { int attr; void *entry; void *stack; int size; void *gp; int prio; int r6, r7; char *opt; };
struct Q { int m0, m4; };
extern int D_003FAE48, D_0077DF90;
extern char D_0045FE28[];
extern struct Q D_0077DF98;
extern char D_0077DB90[];
extern char _gp[];
extern int CreateSema(void *), CreateThread(void *), GetThreadId(void);
extern void DeleteSema(int), StartThread(int, void *), func_003AFB30(int, int);
extern void func_003B0878(void);
extern char D_0045FE40[];
extern int CreateSema(void *), func_003B7638(int, int), func_003B7768(int, void *, int);
extern void WaitSema(int), func_003B0D20(void);

// FUNCTION: GAME 0x3B0950
int func_003B0950(void)
{
    struct ThP t;
    struct SemaP s;
    if (D_003FAE48 > 0)
        return -1;
    s.max = 0xFF;
    s.init = 0;
    s.opt = D_0045FE28;
    D_0077DF90 = CreateSema(&s);
    if (D_0077DF90 < 0)
        return -1;
    t.entry = func_003B0878;
    t.stack = D_0077DB90;
    t.size = 0x400;
    t.gp = _gp;
    t.prio = 0;
    t.opt = D_0045FE28;
    D_003FAE48 = CreateThread(&t);
    if (D_003FAE48 < 0) {
        DeleteSema(D_0077DF90);
        return -1;
    }
    D_0077DF98.m0 = 0;
    D_0077DF98.m4 = 0;
    StartThread(D_003FAE48, &D_0077DF98);
    func_003AFB30(GetThreadId(), 1);
    return D_003FAE48;
}

// FUNCTION: GAME 0x3B0AE0
int DelayThread(int a)
{
    struct SemaP s;
    int sema, r, st;
    __asm__ volatile(".set noreorder\n\tmfc0 %0,$12\n\t.set reorder" : "=r"(st));
    if (!(st & 0x10000))
        return 0x80008008;
    s.max = 1;
    s.opt = D_0045FE40;
    s.init = 0;
    sema = CreateSema(&s);
    if (sema < 0)
        return 0x80008003;
    r = func_003B7768(func_003B7638(0, a), func_003B0D20, sema);
    if (r < 0) {
        DeleteSema(sema);
        return r;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return 0;
}
