// Free units in 0x2B0000-0x2BFFFF, 0x80-0x200 bytes.
extern char Event[];
extern "C" {
unsigned func_00297B98(void *);
float getCutFrame__C6cEvent(void *);

struct Ev2B {
    char _p[0x44];
    unsigned char m_44;
    char _p1[7];
    unsigned char m_4c;
    char _p2[3];
    int m_50;
};

// FUNCTION: GAME 0x2B47C8
int func_002B47C8(Ev2B *self)
{
    if (func_00297B98(Event) < self->m_44)
        return 0;
    if (func_00297B98(Event) < self->m_4c)
        return 1;
    float g = getCutFrame__C6cEvent(Event);
    if ((float)self->m_50 < g)
        return 0;
    return 1;
}

struct VE2B {
    short m_adj;
    short m_pad;
    int (*m_fn)(void *, ...);
};
struct Buf2B {
    int m_0;
    int m_4;
    int m_8;
    char _p[0x18 - 0xC];
    char *m_18;
};
void func_002A7280(void *);

// DRAFT: GAME 0x2BA1C8
// diff: 4 words, second vtable load uses v1 for table and v0 for fn (original swapped)
#ifdef NONMATCHING
int func_002BA1C8(Buf2B *self, int n)
{
    func_002A7280(self);
    VE2B *d = (VE2B *)(self->m_18 + 0x10);
    int p = d->m_fn((char *)self + d->m_adj, self->m_8 * n);
    self->m_4 = n;
    self->m_0 = p;
    if (n) {
        int a2 = self->m_8 * n;
        VE2B *e = (VE2B *)(self->m_18 + 0x20);
        e->m_fn((char *)self + e->m_adj, p, a2);
    }
    return 1;
}
#endif

extern void *Font;
unsigned char func_002A4C00(void *, unsigned);
void func_002B3460(void *);
struct Txt2B {
    char _p[0x14];
    int m_14;
    char _p1[4];
    int m_1c;
    char _p2[0x8C - 0x20];
    unsigned short *m_8c;
};

// DRAFT: GAME 0x2B33D8
// diff: 23 words, flag-set tail is duplicated instead of shared via bnel into the lw/ori block
#ifdef NONMATCHING
void func_002B33D8(Txt2B *self)
{
    if (self->m_1c != 0) {
        unsigned char a = func_002A4C00(Font, *self->m_8c);
        if (!(((self->m_14 >> 1) & 1) && !((self->m_14 >> 2) & 1) && !(a & 1)))
            self->m_14 |= 2;
        else
            func_002B3460(self);
    }
}
#endif

extern char *Cockpit;
struct Task2B {
    int m_0;
    void *m_4;
};
extern Task2B GlobalTask;
extern unsigned char D_003C2554;
extern unsigned char D_003C2555;
void func_0013ED28(void *);
void func_0013EE58(void *);
void func_0013F070(void *);
void exit__9cTaskWork(void *);
void sleep__9cTaskWorkUs(void *, unsigned short);

// FUNCTION: GAME 0x2B6600
void func_002B6600()
{
    func_0013ED28(Cockpit + 0x3A0);
    for (;;) {
        func_0013EE58(Cockpit + 0x3A0);
        func_0013F070(Cockpit + 0x3A0);
        if (D_003C2555) {
            if (D_003C2554) {
                D_003C2554 = 0;
                D_003C2555 = 0;
                exit__9cTaskWork(GlobalTask.m_4);
            }
        }
        sleep__9cTaskWorkUs(GlobalTask.m_4, 1);
    }
}
}
