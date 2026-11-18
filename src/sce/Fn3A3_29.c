// COMPILER: ee-gcc2.9-991111

struct Gs {
    short m_0;
    char _pad[4];
    short m_6;
    int m_8;
    int m_C;
};
extern struct Gs *func_00395388(void);
extern void func_003B0130(void);
extern long func_003B01C0(void);

#ifdef NONMATCHING
// DRAFT: GAME 0x395398
// diff: 14 words (compare/shift order on b path)
int func_00395398(void)
{
    struct Gs *p = func_00395388();
    if (p->m_8 == 0) {
        func_003B0130();
        if (p->m_0 == 1)
            return (*(volatile unsigned long *)0x12001000 >> 13) & 1;
    } else {
        int b = (func_003B01C0() >> 13) & 1;
        return p->m_0 == 1 ? b : 1;
    }
    return 1;
}
#endif

extern int sceOpen(const char *, int);
extern int sceRead(int, void *, int);
extern int sceClose(int);
extern int atoi(const char *);
extern char D_0045DF50[];

// FUNCTION: GAME 0x3964C0
int func_003964C0(void)
{
    char buf[0x100];
    int fd = sceOpen(D_0045DF50, 1);
    unsigned i;
    char *p;
    if (fd < 0)
        return -1;
    i = 0;
    p = buf;
    while (i < 0x100) {
        sceRead(fd, p, 1);
        if (*p++ == 0)
            break;
        i++;
    }
    sceClose(fd);
    return atoi(buf + (i - 9)) > 0x1315670;
}

extern void func_003B06D8(int);
extern void func_003B0740(int);
extern void func_003AF9A0(int, int);
extern int func_003AF980(int, int, int);

// FUNCTION: GAME 0x395F68
int func_00395F68(int a)
{
    struct Gs *p = func_00395388();
    int old = p->m_8;
    if (a == 0) {
        func_003B06D8(2);
        func_003AF9A0(2, p->m_C);
        p->m_C = 0;
        p->m_8 = 0;
    } else {
        if (old != 0) {
            func_003B06D8(2);
            func_003AF9A0(2, p->m_C);
        }
        p->m_8 = a;
        p->m_C = func_003AF980(2, a, -1);
        func_003B0740(2);
    }
    return old;
}

extern int D_003F86A0, D_003F86A4, D_003F8674, D_003F8668, D_003F8654;
extern int D_0077C3C0, D_003F8660, D_003F866C, D_003F8670;
extern void iSignalSema(int);
extern void SignalSema(int);
extern void DeleteSema(int);
extern int func_003B63A0(void);
extern void func_003B63F0(void);
extern void func_003B2500(int);

#ifdef NONMATCHING
// DRAFT: GAME 0x3984D8
// diff: 35 words (hi/lo base register choice for D_003F86xx)
void func_003984D8(int *a)
{
    D_003F86A0 = *a;
    D_003F86A4 = D_003F86A0;
    if (D_003F86A0 == 0xB) {
        D_003F86A0 = 0;
        D_003F8674 = 0;
        return;
    }
    iSignalSema(D_003F8668);
    if (D_003F8654 && D_0077C3C0)
        iSignalSema(D_003F8660);
    else
        D_003F8674 = 0;
    D_003F86A0 = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x398720
// diff: 9 words (lui hoisting order)
void func_00398720(void)
{
    int en;
    if (D_003F8654) {
        D_003F86A0 = -1;
        SignalSema(D_003F8660);
    }
    DeleteSema(D_003F8668);
    DeleteSema(D_003F866C);
    DeleteSema(D_003F8670);
    DeleteSema(D_003F8660);
    en = func_003B63A0();
    func_003B2500(0x80000012);
    if (en)
        func_003B63F0();
}
#endif
