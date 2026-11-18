// ProDG libc-adjacent game code in 0x3A53A8-0x3AF7B8 (continued from Fn3Az.cpp).
extern void *D_003FA62C;

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
        fp->m_54 = (Rt2 *)D_003FA62C;
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
extern "C" int func_003A6E60(void);

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
    } else if ((st.m_mode & 0xf000) == 0x8000 && fp->m_28 == func_003A6E60) {
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

// DRAFT: GAME 0x3AE730
// diff: original has a nop after the reloaded lw a0,0x54(s0) before lw v0,0x38(a0) (same as 3A6130); rest matches
#ifdef NONMATCHING
extern "C" int func_003AE730(Fq *fp)
{
    unsigned c;
    if (!fp->m_54)
        fp->m_54 = D_003FA62C;
    if (!((Rt2 *)fp->m_54)->m_38)
        func_003A61F0((Rt2 *)fp->m_54);
    c = fp->m_c;
    if (!(c & 8)) {
        if (!(c & 0x10))
            return -1;
        if (c & 4) {
            fp->m_c = c & 0xffdb;
            fp->m_0 = fp->m_10;
            fp->m_4 = 0;
        }
        fp->m_c |= 8;
    }
    if (!fp->m_10)
        func_003A6950(fp);
    c = fp->m_c;
    if (c & 1) {
        fp->m_8 = 0;
        fp->m_18 = -fp->m_14;
    } else {
        int v = 0;
        if (!(c & 2))
            v = fp->m_14;
        fp->m_8 = v;
    }
    return 0;
}
#endif

struct Bg {
    char _pad[0x10];
    int m_10;
};

extern "C" long func_003AF3D8(Bg *, int *);
extern "C" long func_0031E5F0(long, long);


struct Bn {
    Bn *m_next;
};

struct Rm {
    char _pad[0x48];
    Bn *m_48;
};

extern int D_0045FCD8[];
extern "C" Bn *func_003AE8F8(Rm *, Bn *, int, int);
extern "C" Bn *func_003AEC80(Rm *, int);
extern "C" Bn *func_003AECB8(Rm *, Bn *, Bn *);
extern "C" void func_003AE8C0(Rm *, Bn *);

// FUNCTION: GAME 0x3AEEC0
extern "C" Bn *func_003AEEC0(Rm *self, Bn *b, int k)
{
    Bn *p5;
    int i = k & 3;
    if (i)
        b = func_003AE8F8(self, b, D_0045FCD8[i - 1], 0);
    k >>= 2;
    if (!k)
        return b;
    p5 = self->m_48;
    if (!p5) {
        p5 = self->m_48 = func_003AEC80(self, 625);
        p5->m_next = 0;
    }
    for (;;) {
        if (k & 1) {
            Bn *t = func_003AECB8(self, b, p5);
            func_003AE8C0(self, b);
            b = t;
        }
        k >>= 1;
        if (!k)
            break;
        {
            Bn *q = p5->m_next;
            if (!q) {
                q = func_003AECB8(self, p5, p5);
                p5->m_next = q;
                q->m_next = 0;
            }
            p5 = q;
        }
    }
    return b;
}
