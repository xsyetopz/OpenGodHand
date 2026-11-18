// ProDG-built libc-adjacent game code in 0x393FD8-0x394F20 and 0x3A53A8-0x3AF7B8.
extern "C" void _exit(int);
extern "C" double strtod(const char *, char **);
extern "C" void func_00394088(void *, void *, int);
extern "C" void func_003A6020(void);
extern "C" void func_003A6830(void *, void (*)(void));
extern "C" void func_003A6290(void *);
extern "C" int func_003ADF50(void *, int);
extern "C" int func_003B0388(int);
extern int D_0077DB88;
extern "C" void func_003A61F0(void *);
extern void *D_003FA62C;
extern char D_0045FB80;
extern unsigned char D_0045F039[];

extern "C" void func_003A6EC8(void *);

struct Fi;
extern "C" int func_003A6D78(Fi *, int, int);
extern "C" int func_003A6DE0(Fi *, int, int);
extern "C" long func_003A6E60(Fi *, int, int);
extern "C" long func_003AE068(void *, int, int, int);
extern "C" long func_003AE008(void *, int, int, int);
extern "C" long func_003AE128(void *, int, int, int);

struct Fi {
    int m_0;
    int m_4;
    int m_8;
    unsigned short m_c;
    short m_e;
    int m_10;
    int m_14;
    int m_18;
    void *m_1c;
    void *m_20;
    void *m_24;
    void *m_28;
    void *m_2c;
    char _pad[0x50 - 0x30];
    int m_50;
    void *m_54;
};

// FUNCTION: GAME 0x3A6188
extern "C" void func_003A6188(Fi *self, short a1, short a2, void *a3)
{
    self->m_54 = a3;
    self->m_c = a1;
    self->m_e = a2;
    self->m_20 = (void *)func_003A6D78;
    self->m_24 = (void *)func_003A6DE0;
    self->m_28 = (void *)func_003A6E60;
    self->m_2c = (void *)func_003A6EC8;
    self->m_4 = 0;
    self->m_8 = 0;
    self->m_10 = 0;
    self->m_18 = 0;
    self->m_1c = self;
    self->m_0 = 0;
}

// FUNCTION: GAME 0x3A6D78
extern "C" int func_003A6D78(Fi *self, int a1, int a2)
{
    int r = func_003AE068(self->m_54, self->m_e, a1, a2);
    if (r >= 0)
        self->m_50 += r;
    else
        self->m_c &= ~0x1000;
    return r;
}

// FUNCTION: GAME 0x3A6DE0
extern "C" int func_003A6DE0(Fi *self, int a1, int a2)
{
    if (self->m_c & 0x100)
        func_003AE008(self->m_54, self->m_e, 0, 2);
    self->m_c &= ~0x1000;
    return func_003AE128(self->m_54, self->m_e, a1, a2);
}

// FUNCTION: GAME 0x3A6E60
extern "C" long func_003A6E60(Fi *self, int a1, int a2)
{
    long r = func_003AE008(self->m_54, self->m_e, a1, a2);
    if (r == -1) {
        self->m_c &= ~0x1000;
    } else {
        self->m_50 = r;
        self->m_c |= 0x1000;
    }
    return r;
}
