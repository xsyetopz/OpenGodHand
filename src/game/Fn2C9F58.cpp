extern "C" {
void sceVu0UnitMatrix(void *, void *, void *, unsigned);
void func_002CA220(void *);
void func_002CA390(void *, int);
void func_002CD638(int);
extern char D_005FEFF0[], D_005FFCF0[], D_005FFD80[], D_00601180[];
}

struct S2C9F58 {
    char pad0[0x34];
    void *p34, *p38, *p3c, *p40;
    int i44;
    char pad48[8];
    unsigned i50;
    char pad54[4];
    unsigned i58, i5c;
    char pad60[0x60];
    float fc0, fc4, fc8, fcc;
    char matd0[0x40];
    char pad110[0x10];
    char pad120[8];
    int i128;
    short s12c;
    char pad12e[2];
    int i130;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2C9F58  53 words; const-load order and float regs (f0/f1 shared) differ; variants: 4-arg vs 1-arg sceVu0UnitMatrix
extern "C" void func_002C9F58(S2C9F58 *p) {
    p->i44 = 0;
    p->s12c = 0;
    p->p34 = D_005FFD80;
    p->p38 = D_00601180;
    p->p3c = D_005FEFF0;
    p->p40 = D_005FFCF0;
    p->i50 = 0x80000000;
    p->i128 = -2;
    p->fc0 = 0.0f;
    p->fcc = 1.0f;
    p->i5c = 0x80000000;
    p->i58 = 0x80000000;
    p->fc8 = 0.0f;
    p->fc4 = 0.0f;
    sceVu0UnitMatrix(p->matd0, p->p3c, p->p40, p->i50);
    *(int *)((char *)p + 0x110) = 0;
    short *q = (short *)((char *)p + 0x160);
    int n = 0xF;
    do {
        q[1] = -1;
        n--;
        q[0] = -1;
        *(int *)(q + 2) = 0;
        q += 4;
    } while (n >= 0);
    *(int *)((char *)p + 0x1E0) = 0;
    func_002CD638(-1);
    func_002CA220(p);
    p->i130 = -1;
    func_002CA390(p, 0);
}
#endif
