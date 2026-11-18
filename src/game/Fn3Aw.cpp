// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8 (continued from Fn3Az.cpp).
extern void *_impure_ptr;

struct Rt2 {
    char _pad[0x38];
    int m_38;
};

struct Fp {
    char _pad[0xc];
    short m_c;
    char _pad2[0x1c - 0xe];
    int m_1c;
    char _pad3[0x2c - 0x20];
    int (*m_2c)(int);
    char _pad4[0x54 - 0x30];
    Rt2 *m_54;
};

extern "C" int func_003A6020(Fp *);
extern "C" void func_003A61F0(Rt2 *);

// FUNCTION: GAME 0x3A5F68
extern "C" int func_003A5F68(Fp *fp)
{
    int r;
    if (!fp)
        return 0;
    if (!fp->m_54)
        fp->m_54 = (Rt2 *)_impure_ptr;
    if (!fp->m_54->m_38)
        func_003A61F0(fp->m_54);
    if (!fp->m_c)
        return 0;
    r = 0;
    if (fp->m_c & 8)
        r = func_003A6020(fp);
    if (fp->m_2c) {
        if (fp->m_2c(fp->m_1c) < 0)
            r = -1;
    }
    fp->m_c = 0;
    return r;
}

struct Fq {
    char *m_0;
    int m_4;
    int m_8;
    unsigned short m_c;
    short m_e;
    char *m_10;
    int m_14;
    int m_18;
    char _pad2[0x28 - 0x1c];
    int (*m_28)(void);
    char _pad3[0x4c - 0x2c];
    int m_4c;
    char _pad4[0x54 - 0x50];
    void *m_54;
};

struct St {
    int _0;
    unsigned m_mode;
    char _pad[0x70 - 8];
};

extern "C" int func_003ADFA8(void *, int, St *);
extern "C" int __sseek(void);

// FUNCTION: GAME 0x3A6950
extern "C" void func_003A6950(Fq *fp)
{
    St st;
    if (fp->m_c & 2) {
        fp->m_0 = (char *)fp + 0x43;
        fp->m_10 = (char *)fp + 0x43;
        fp->m_14 = 1;
        return;
    }
    if (fp->m_e < 0 || func_003ADFA8(fp->m_54, fp->m_e, &st) < 0) {
        fp->m_c |= 0x800;
    } else if ((st.m_mode & 0xf000) == 0x8000 && fp->m_28 == __sseek) {
        fp->m_4c = 0x400;
        fp->m_c |= 0x400;
    } else {
        fp->m_c |= 0x800;
    }
    fp->m_c |= 2;
    fp->m_0 = (char *)fp + 0x43;
    fp->m_14 = 1;
    fp->m_10 = (char *)fp + 0x43;
}
