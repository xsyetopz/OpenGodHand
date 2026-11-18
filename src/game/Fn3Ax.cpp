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
extern void *_impure_ptr;
extern char D_0045FB80;
extern unsigned char D_0045F039[];

// FUNCTION: GAME 0x3A6CD8
extern "C" int _user_strerror(void)
{
    return 0;
}

// FUNCTION: GAME 0x3AD118
extern "C" char *func_003AD118(void *)
{
    return &D_0045FB80;
}

// FUNCTION: GAME 0x3A7B48
extern "C" void abort(void)
{
    _exit(1);
}

// FUNCTION: GAME 0x394328
extern "C" void func_00394328(void *a, void *b)
{
    func_00394088(a, b, 0);
}

// FUNCTION: GAME 0x3A6A88
extern "C" void func_003A6A88(void)
{
    func_003A6020();
}

// FUNCTION: GAME 0x3A6290
extern "C" void func_003A6290(void *self)
{
    func_003A6830(self, func_003A6020);
}

struct Fp {
    char _pad[0xE];
    short m_e;
    char _pad2[0x54 - 0x10];
    void *m_54;
};

// FUNCTION: GAME 0x3A6EC8
extern "C" void __sclose(Fp *self)
{
    func_003ADF50(self->m_54, self->m_e);
}

// FUNCTION: GAME 0x3AD0F8
extern "C" char *func_003AD0F8(char *self)
{
    unsigned char t = D_0045F039[(int)self] & 1;
    return t ? self + 0x20 : self;
}

// FUNCTION: GAME 0x3A62B0
extern "C" void _cleanup(void)
{
    func_003A6290(_impure_ptr);
}

// Round 23.
struct Pr {
    char _pad[0x10];
    int m_10;
    int m_14;
};

extern "C" long strtol(const char *, char **, int);
extern "C" void func_003A9498(char *, const char *, void *);
extern "C" double func_003A80E8(void *, const char *, char **);
extern "C" long func_003ACE90(void *, const char *, char **, int);
extern "C" long func_003A9018(void *, const char *, char **, int);
extern "C" void func_003AB188(void *, void *, int, int);
extern "C" Pr *_Balloc(void *, int);

// FUNCTION: GAME 0x3AD130
extern "C" void func_003AD130(void)
{
    func_003AD118(_impure_ptr);
}

// FUNCTION: GAME 0x3A62D8
extern "C" void func_003A62D8(char *d, const char *s, unsigned n)
{
    while (n--)
        *d++ = *s++;
}

// FUNCTION: GAME 0x3A9470
extern "C" void strtok(char *s, const char *delim)
{
    func_003A9498(s, delim, (char *)_impure_ptr + 0x5C);
}

// FUNCTION: GAME 0x3A8FE0
extern "C" double strtod(const char *s, char **e)
{
    return func_003A80E8(_impure_ptr, s, e);
}

// FUNCTION: GAME 0x3AD0C0
extern "C" long strtol(const char *s, char **e, int base)
{
    return func_003ACE90(_impure_ptr, s, e, base);
}

// FUNCTION: GAME 0x3A9228
extern "C" long func_003A9228(const char *s, char **e, int base)
{
    return func_003A9018(_impure_ptr, s, e, base);
}

// FUNCTION: GAME 0x3AB158
extern "C" void func_003AB158(Fp *self, int a, int b)
{
    func_003AB188(self->m_54, self, a, b);
}

struct FreeList {
    char _pad[0x4C];
    int **m_tab;
};
struct FreeNode {
    int *m_next;
    int m_idx;
};

// Round 24.
extern "C" void func_003A8048(void *);
extern "C" void func_003A80A8(void *);
extern "C" int GetThreadId(void);
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
extern "C" int func_003A6AA8(void *);
extern "C" void func_003A61F0(void *);
extern "C" int func_003B0388(int);
extern int D_003FA990;
extern int D_003FA994;
extern int D_003FAF18;
extern int D_0077DB88;

// FUNCTION: GAME 0x3A80A8
extern "C" void func_003A80A8(void *)
{
    if (--D_003FA994 == 0) {
        D_003FA990 = -1;
        SignalSema(D_003FAF18);
    }
}

// FUNCTION: GAME 0x3A8048
extern "C" void func_003A8048(void *)
{
    int tid = GetThreadId();
    if (D_003FA990 == tid) {
        D_003FA994++;
        return;
    }
    WaitSema(D_003FAF18);
    D_003FA990 = tid;
    D_003FA994++;
}

struct Fio {
    unsigned char *m_ptr;
    int m_cnt;
};

// FUNCTION: GAME 0x3A6C10
extern "C" int __srget(Fio *f)
{
    if (func_003A6AA8(f))
        return -1;
    f->m_cnt--;
    return *f->m_ptr++;
}

struct Rn {
    char _pad[0x38];
    int m_38;
};

struct Fq {
    char _pad[0xE];
    short m_e;
    char _pad2[0x54 - 0x10];
    Rn *m_54;
};

// Round 25.
// FUNCTION: GAME 0x3ADF50
extern "C" int func_003ADF50(void *self, int a1)
{
    D_0077DB88 = 0;
    int r = func_003B0388(a1);
    if (r == -1 && D_0077DB88)
        *(int *)self = D_0077DB88;
    return r;
}

