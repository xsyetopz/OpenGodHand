// Small free units in 0x370000-0x383FFF (slice F182).
struct F182Pk { char b[15]; } __attribute__((packed));
struct F182Ent {
    char _p0[0xA];
    unsigned char m_0A;
    unsigned char m_0B;
    char _p0C[4];
    unsigned char m_10;
    F182Pk m_11;
};
struct F182Sel {
    char _p0[0x4C];
    int m_4C;
    char _p50[4];
    int m_54;
    int m_58;
    F182Pk m_5C;
    char _p6B[1];
    F182Ent *m_6C;
    F182Ent *m_70;
    int m_74;
    int m_78;
    int m_7C;
};

extern "C" {
void func_003733C8(F182Sel *);
int func_00373B20(F182Sel *, int, int);
int func_00373D90(F182Sel *, int, F182Ent *, int);
int func_00374360(F182Sel *, int, F182Ent *);
void free(void *);
int func_0037E8D8(void *);
void *func_003BB058(void *);
void func_002E0DE8(int, int, int, char *);
}
extern void *D_003C4030[];
extern char *D_003F28C0[];
extern char D_0045C328[];

#ifdef NONMATCHING
// DRAFT: GAME 0x373158 - 59 words; Tried: store order, e as o->m_6C+idx, b[12]/b[13] locals (72 words); e stays in a3, not a0
extern "C" int func_00373158(F182Sel *o, int idx)
{
    F182Ent *e = o->m_6C;
    e += idx;
    int var_s1 = 0;
    int v;
    o->m_70 = e;
    o->m_58 = e->m_0A;
    o->m_54 = e->m_0B & 3;
    o->m_78 = idx;
    o->m_5C = e->m_11;
    if (o->m_70->m_10 != 0) {
        var_s1 = o->m_7C;
    }
    if (func_00373B20(o, e->m_11.b[12], e->m_11.b[13]) != 1) {
        if (((unsigned)((o->m_70->m_0B >> 2) & 3) >= 2U) || !(o->m_4C & 0x10)) {
            o->m_4C = o->m_4C & 0xFFFFFFEF;
        }
        v = func_00373D90(o, o->m_74, o->m_70, var_s1);
    } else {
        v = func_00374360(o, o->m_74, o->m_70);
    }
    o->m_4C = o->m_4C | 2;
    if (v == 0) {
        func_003733C8(o);
    }
    return v;
}
#endif

struct F182U2 {
    char _p0[0x3E];
    unsigned short m_3E;
    char _p40[4];
    short m_44;
    char _p46[6];
    unsigned short m_4C;
    unsigned short m_4E;
};

extern "C" int SdeSystemOutModeGet(void);
extern "C" void func_003780F8(int, float *, float *);

#ifdef NONMATCHING
// DRAFT: GAME 0x37D558 - 61 words (268 vs 292 bytes); Tried: store order 4C then 4E (63 to 61 words); mode-1 value lands in a0, target uses a1; branch layout of mode-1 block differs
extern "C" void func_0037D558(F182U2 *o)
{
    short t = (short)o->m_3E >> 1;
    o->m_4C = t;
    o->m_4E = t;
    int mode = SdeSystemOutModeGet();
    if (mode == 1) {
        short a1 = o->m_44;
        if (a1 >= 0x41) {
            int x = o->m_4C * (0x7F - a1);
            o->m_4C = (x > -1 ? x : x + 0x3F) >> 6;
        } else if (a1 < 0x40) {
            int x = o->m_4E * a1;
            o->m_4E = (x > -1 ? x : x + 0x3F) >> 6;
        }
    } else if (mode == 2) {
        float fx, fy;
        func_003780F8((unsigned short)o->m_44, &fx, &fy);
        float p = (float)o->m_4C * fx;
        float q = (float)o->m_4E * fy;
        o->m_4C = (int)p & 0x7FFF;
        o->m_4E = (int)q & 0x7FFF;
    }
}
#endif

struct F182Rq { char _p0[0x34]; int m_34; };
struct F182Ob { char _p0[2]; unsigned char m_2; char _p3[0xD]; int *m_10; };
struct F182Hdr { void *m_0; unsigned m_4; int m_8; void *m_C; };

#ifdef NONMATCHING
// DRAFT: GAME 0x380138 - 20 words (328 vs 328 bytes); Tried: free-first layout (52), m_2 store split into if/else (20, kept), bin slot index split into k (45), refcount sense reversed (57); diffs are branch offsets and bin-path lui/addiu order
extern "C" void func_00380138(F182Ob *o, F182Rq *r)
{
    if (r->m_34 & 0x40) {
        int *s0 = o->m_10;
        int *s2 = s0 + 1;
        if (s2 != o->m_10) {
            F182Hdr *h = (F182Hdr *)((char *)s0[0] - 0x10);
            if (--h->m_8 == 0) {
                unsigned sz = h->m_4;
                if (sz + 0x10 >= 0x81) {
                    free(h);
                } else {
                    void **slot = &D_003C4030[((sz + 0x17) >> 3) - 1];
                    h->m_0 = *slot;
                    *slot = h;
                }
            }
            F182Hdr *h2 = (F182Hdr *)((char *)s2[0] - 0x10);
            void *q = (void *)s2[0];
            if (h2->m_C == 0) {
                h2->m_8 = h2->m_8 + 1;
            } else {
                q = func_003BB058(h2);
            }
            s0[0] = (int)q;
        }
        if (func_0037E8D8(o))
            o->m_2 = 0xC;
        else
            o->m_2 = 1;
    } else {
        unsigned char b = ((unsigned char *)o->m_10)[0x20];
        func_002E0DE8(3, 0x14, 0xA, D_003F28C0[b - 1]);
        func_002E0DE8(3, 0x15, 0xA, D_0045C328);
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x383A20 - 70 words (312 vs 320 bytes); Tried: index copy loop, q base in count loop with n-1 index (70, kept), r base dropped (77), do-while copy loop (75)
extern "C" void func_0032EC78(int, int, int);
extern "C" void func_0032A9F0(int, int);
extern "C" void func_00383A20(int, char *o)
{
    if (o[4] == 0) {
        short *d = (short *)(o + 0x14);
        short *e = (short *)(o + 0xA);
        int i = 0;
        do {
            *d++ = *(short *)(o + 0x12);
            *e++ = *(short *)(o + 8);
        } while (++i < 4);
    }
    if (o[3] & 1) {
        char *p = o + 0xA4;
        if (*(int *)(p + 0x20) != 0) {
            if (o[4] == 0) {
                int count = *(int *)(p + 8);
                if (count > 0) {
                    char *q = o + 0xBC;
                    int k = 0;
                    int n = 1;
                    do {
                        if (q[n] == 0)
                            func_0032EC78(*(int *)(p + 0x20), k, *(short *)(o + 8 + ((unsigned char)o[4] << 1)));
                        k = n;
                    } while (n++ < count);
                }
            } else {
                unsigned m4 = (unsigned char)o[4];
                if (o[0xBC + m4] == 0)
                    func_0032EC78(*(int *)(p + 0x20), m4 - 1, *(short *)(o + 8 + m4 * 2));
            }
        }
    } else {
        int m = *(int *)(o + 0x64);
        if (m != 0)
            func_0032A9F0(m, *(short *)(o + 8));
    }
}
#endif
