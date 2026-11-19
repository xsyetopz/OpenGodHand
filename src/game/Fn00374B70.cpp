// Free units 0x374B70, 0x37CCE0 and 0x3823E0 (ee-gcc2.95.3-136, C++).

struct Fn374Ent {
    int m0;
    void *m4;
    int m8;
    int mC;
    void *m10;
    int m14;
    void *m18;
    void *m1C;
};
struct Fn374Src {
    int m0;
    int m4;
    char _8[8];
    int m10;
    int m14;
    int m18;
    int m1C;
};
struct Fn374Res {
    int m0;
    int m4;
    int m8;
    unsigned char mC;
};
struct Fn374Out {
    int m0;
    int m4;
    int m8;
    void *mC;
    int m10;
    int m14;
    void *m18;
    int m1C;
    void *m20;
    void *m24;
};
struct Fn37Obj {
    char _0[2];
    short m2;
    char m4;
    unsigned char m5;
    unsigned short m6;
    char _8[0x36];
    unsigned short m3E;
};
struct Fn382Sub {
    char _0[8];
    int m8;
    char _c[0x14];
    int m20;
};
struct Fn382Obj {
    char _0[2];
    unsigned char m2;
    char _3[0x2D];
    Fn382Sub s30;
};

extern Fn374Ent Sde_iss_hed[];
extern Fn374Out D_0076A880;
extern Fn374Res *D_00773250[];
extern char D_0076A600[];

extern "C" {
void func_003758E8(int, void *, int, int);
void func_0037D3C8(void *);
void func_0037D680(void *);
void func_0037D558(void *);
void func_0037D728(void *);
void func_0037C720(void *);
void func_003738A0(void *, int, float);
void func_00373560(void *, int, float);
int func_00382520(int, void *, unsigned char);
int func_0032DCD0(int, int);
void func_0032A6D0(int, int, short);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x374B70
// 52 words differ: src/e/o register choice and three extra daddu copies before the call; tried e/o declaration order and late o declaration (78 words).
extern "C" void func_00374B70(short idx, Fn374Src *src, int a2, int a3, Fn374Res *res)
{
    Fn374Ent *e = &Sde_iss_hed[idx];
    Fn374Out *o = &D_0076A880;
    e->m0 = src->m0;
    e->m8 = a2;
    e->mC = a3;
    e->m4 = (char *)src + src->m4;
    if (src->m10 == 0)
        e->m10 = 0;
    else
        e->m10 = (char *)src + src->m10;
    e->m14 = src->m14;
    if (src->m18 == 0)
        e->m18 = 0;
    else
        e->m18 = (char *)src + src->m18;
    if (src->m1C == 0)
        e->m1C = 0;
    else
        e->m1C = (char *)src + src->m1C;
    D_00773250[idx] = res;
    if (res && res->mC == 0) {
        res->m4 = res->m4 + (int)res;
        Fn374Res *q = D_00773250[idx];
        if (q->m8 != 0)
            q->m8 = q->m8 + (int)q;
        D_00773250[idx]->mC = 1;
    }
    o->m24 = e->m1C;
    o->m4 = idx;
    o->m8 = e->m0;
    o->mC = e->m4;
    o->m10 = e->m8;
    o->m14 = e->mC;
    o->m18 = e->m10;
    o->m1C = e->m14;
    o->m20 = e->m18;
    func_003758E8(3, e->m4, e->m8, e->mC);
}
#endif

// FUNCTION: GAME 0x37CCE0
extern "C" void func_0037CCE0(Fn37Obj *o)
{
    if (o->m5 & 8) {
        if (o->m6 & 1) {
            func_0037D3C8(o);
            func_003738A0(D_0076A600 + o->m2 * 0x84, -1, (float)((int)(o->m3E << 16) >> 24));
            func_00373560(D_0076A600 + o->m2 * 0x84, -1, (float)((int)(o->m3E << 16) >> 24));
        }
        if (o->m6 & 2) {
            func_0037D680(o);
            func_0037C720(o);
        }
    } else {
        if (o->m6 & 1)
            func_0037D3C8(o);
        if (o->m6 & 2)
            func_0037D680(o);
        if (o->m6 & 4)
            func_0037D728(o);
        if (o->m6 & 8)
            func_0037D558(o);
    }
    o->m6 = 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3823E0
// 35 words differ: one extra instruction, since the then-branch folds p+m2*2+0x22 into one addu/addiu pair; tried s1/s2 declaration order (no change).
extern "C" void func_003823E0(int a0, Fn382Obj *p, int flag)
{
    unsigned char f = flag;
    Fn382Sub *s3 = &p->s30;
    unsigned short *s2;
    unsigned short *s1;
    int off;
    int s4;
    if (f) {
        s1 = (unsigned short *)((char *)p + 0x22);
        s4 = 1;
        off = p->m2 * 2 + 0x22;
    } else {
        s1 = (unsigned short *)((char *)p + 0x18);
        s4 = 0;
        off = p->m2 * 2 + 0x18;
    }
    s2 = (unsigned short *)((char *)p + off);
    unsigned short *v1 = s1 + 1;
    if (p->m2 == 0) {
        int n = 3;
        do {
            n -= 1;
            *v1 = *s1;
            v1 += 1;
        } while (n >= 0);
    } else if (func_00382520(a0, p, f) != 0) {
        *s1 = *s2;
    }
    if (s3->m20 != 0) {
        if (p->m2 != 0) {
            func_0032A6D0(func_0032DCD0(s3->m20, p->m2 - 1), s4, (short)*s2);
            return;
        }
        int i = 0;
        if (s3->m8 > 0) {
            do {
                int k = i;
                i += 1;
                short v = (short)s1[1];
                s1 += 1;
                func_0032A6D0(func_0032DCD0(s3->m20, k), s4, v);
            } while (i < s3->m8);
        }
    }
}
#endif
