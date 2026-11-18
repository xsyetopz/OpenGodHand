struct V3 { float x, y, z; V3 &operator=(const V3 &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; } };
struct NP { char p0[0x80]; char m[0x70]; V3 *pv; char p1[0xC]; V3 v100; char p2[4]; V3 v110; char p3[4]; V3 v120; char p4[0x14]; unsigned char b140; };
extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(char *, V3 *, V3 *, V3 *, unsigned char);
// FUNCTION: GAME 0x14A2B0
extern "C" void calcNullPart__6cModel(char *self)
{
    if (!(*(unsigned *)(self + 0x250) & 0x800)) {
        NP *p = (NP *)self;
        MtxInitCoord__FR7cMatrixRC4cVecN21Uc(p->m - 0 , p->pv, &p->v100, &p->v110, p->b140);
        p->v120 = p->v110;
    }
}
struct Mn { char pad[0x404]; Mn *w404; };
extern "C" void func_00149350(void *);
extern "C" void func_001F8A88(float *o, float x0, float x1, float y0, float y1, float z0, float z1);
// FUNCTION: GAME 0x14B798
extern "C" void removeMesh__6cModel(char *self)
{
    Mn *m = *(Mn **)(self + 0x25C);
    while (m) {
        Mn *n = m->w404;
        self[0x2B1]--;
        func_00149350(m);
        *(Mn **)(self + 0x25C) = n;
        m = n;
    }
    func_001F8A88((float *)(self + 0x260), 0, 0, 0, 0, 0, 0);
}

struct Ob { char p[0x358]; unsigned char cnt; char q[3]; char *t[10]; char b384; };
extern "C" unsigned char *getIDWork__7cIDBasei(void *, int);
// FUNCTION: GAME 0x140718
extern "C" void func_00140718(Ob *o, int i, int f)
{
    if (o->b384 == 0 || f != 0) {
        int j = 1;
        int k;
        o->b384 = o->b384 + 10;
        char *p = (char *)o + (i * 0x50 + 0xC0);
        o->t[0] = p;
        getIDWork__7cIDBasei(p, 0)[0x4F] = 0x80;
        for (k = i - 1; k >= 0; k--) {
            char *b = (char *)o + (k * 0x50 + 0xC0);
            o->t[j++] = b;
            getIDWork__7cIDBasei(b, 0)[0x4F] = 0x20;
        }
        for (k = i + 1; k < o->cnt; k++) {
            char *b = (char *)o + (k * 0x50 + 0xC0);
            o->t[j++] = b;
            getIDWork__7cIDBasei(b, 0)[0x4F] = 0x20;
        }
    }
}

struct Q { char p[0x24C]; float f24C; char p1[4]; unsigned w254; char p2[0x5E]; unsigned char b2B6, b2B7; char p3[4]; unsigned char b2BC; char p4[7]; int w2C4; };
struct R { char p[0x380]; unsigned w380; };
extern "C" int D_00747AA8;
extern "C" void func_00148BD8(R *, int, int);
extern "C" void func_00148690(R *, int, void *);
// FUNCTION: GAME 0x14B4D0
extern "C" void func_0014B4D0(Q *q, R *r)
{
    register int k __asm__("$7") = 0;
    if (r->w380 & 0x20000000) {
        if (q->f24C * ((float)q->b2B6 / 255.0f) * ((float)q->b2B7 / 255.0f) * ((float)q->b2BC / 255.0f) == 1.0f)
            k = 3;
    }
    __asm__ volatile("" : : "r"(k));
    if ((r->w380 & 0x40000000) && D_00747AA8)
        func_00148BD8(r, q->w2C4, D_00747AA8);
    else if (q->w254 & 0x10000000)
        func_00148690(r, q->w2C4, (char *)q + 0x2D4);
    else
        func_00148690(r, q->w2C4, 0);
}
