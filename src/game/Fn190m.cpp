extern const char D_00428840[];
extern const char D_00428A20[];
extern char g_DmgManage[];
extern char g_CollScr[];
extern char g_CollSolidManage[];
extern "C" void func_001FE278(void *, void *);
extern "C" void func_001FE370(void *, void *);
extern "C" void func_001331B8(void *, long, int);
extern "C" void ReleaseUnit__21cCollisionSolidManageP8cGameObj(void *, void *);
extern "C" void ReleaseObj__FP4cObj(void *);
void _$_8cGameObj(char *, int);
extern "C" void func_001B6F38(char *, int);

// FUNCTION: GAME 0x1B6F38
extern "C" void func_001B6F38(char *self, int d)
{
    *(const void **)(self + 0x214) = D_00428A20;
    func_001331B8(g_CollScr, *(long *)(self + 0x540), 0);
    ReleaseUnit__21cCollisionSolidManageP8cGameObj(g_CollSolidManage, self);
    ReleaseObj__FP4cObj(self);
    func_001FE370(g_DmgManage, self);
    _$_8cGameObj(self, d);
}

// FUNCTION: GAME 0x1B5768
extern "C" void func_001B5768(char *self, int d)
{
    *(const void **)(self + 0x214) = D_00428840;
    void *p = *(void **)(self + 0x600);
    if (p) {
        func_001FE278(g_DmgManage, p);
        *(void **)(self + 0x600) = 0;
    }
    char *q = *(char **)(self + 0x604);
    if (q)
        q[0x2F4] = 1;
    q = *(char **)(self + 0x608);
    if (q)
        q[0x2F4] = 1;
    func_001B6F38(self, d);
}

struct Mesh190 {
    char p0[0x380];
    unsigned fl;
    char p1[0x3A0 - 0x384];
    float col[3];
    char p2[0x404 - 0x3AC];
    Mesh190 *next;
    char p3[0x40C - 0x408];
    unsigned char layer;
};
extern "C" Mesh190 *getMeshPtr__6cModeli(void *, int);

#define MESH_FLAG_FN(name, bit)                                           \
    extern "C" void name(void *self, unsigned layer, int on)              \
    {                                                                     \
        Mesh190 *m = getMeshPtr__6cModeli(self, 0);                       \
        if (m) {                                                          \
            for (; m; m = m->next) {                                      \
                if (m->layer == layer) {                                  \
                    if (on == 1)                                          \
                        m->fl &= ~(bit);                                  \
                    else                                                  \
                        m->fl |= (bit);                                   \
                }                                                         \
            }                                                             \
        }                                                                 \
    }

// FUNCTION: GAME 0x1B7280
MESH_FLAG_FN(setMeshDispFromLayer__7cOmBaseUib, 1)
// FUNCTION: GAME 0x1B7300
MESH_FLAG_FN(func_001B7300, 0x2000)

// FUNCTION: GAME 0x1B71A0
extern "C" void setMeshColorFromLayer__7cOmBaseUifff(void *self, unsigned layer, float r, float g, float b)
{
    Mesh190 *m = getMeshPtr__6cModeli(self, 0);
    if (m) {
        for (; m; m = m->next) {
            if (m->layer == layer) {
                float *c = m->col;
                c[0] = r;
                c[1] = g;
                c[2] = b;
            }
        }
    }
}

struct Mdl190 {
    char p0[0x278];
    char **tbl;
    char p1[0x2B4 - 0x27C];
    unsigned char n;
};

static inline int Gt(const int &v, int n) { return v > n; }
// FUNCTION: GAME 0x1B3548
extern "C" void func_001B3548(Mdl190 *self)
{
    char *e = Gt(self->n, 2) ? self->tbl[2] : 0;
    float pi = 3.1415927f;
    float *f = (float *)(e + 0x100);
    float v = (*f - pi) * 0.9f + pi;
    *f = v;
    if (v >= 3.054326f) {
        *f = pi;
        *((unsigned char *)self + 0x2F5) = 2;
    }
}

extern "C" void setParent__5cOm59P8cGameObjiRC4cVecT3(void *, void *, int, const void *, const void *);

// FUNCTION: GAME 0x1AE5B0
extern "C" void setArm__5cOm5cUiP5cOm59G4cVecT3(char *self, unsigned idx, char *child, const void *a, const void *b)
{
    if (child != 0 && idx < 2) {
        int *t = *(int **)(child + 0xF0);
        t[0] = 0;
        t[1] = 0;
        t[2] = 0;
        int *c = (int *)(child + 0x100);
        c[0] = 0;
        c[1] = 0;
        c[2] = 0;
        setParent__5cOm59P8cGameObjiRC4cVecT3(child, self, -1, a, b);
        *(char **)(self + (idx << 2) + 0x604) = child;
    }
}

// FUNCTION: GAME 0x1AA478
extern "C" void func_001AA478(char *self)
{
    int *tp = (int *)(self + 0x9E0);
    if (*tp != 0) {
        *tp = *tp - 1;
        if (*tp != 0) {
            if (*tp & 1)
                setMeshColorFromLayer__7cOmBaseUifff(self, 1, 1.0f, 1.0f, 1.0f);
            else
                setMeshColorFromLayer__7cOmBaseUifff(self, 1, 1.0f, 0.0f, 0.0f);
        } else {
            setMeshColorFromLayer__7cOmBaseUifff(self, 1, 1.0f, 1.0f, 1.0f);
        }
    }
}

extern "C" void func_001B6F38(char *, int);
extern "C" void func_001FE278(void *, void *);
extern char g_DmgManage[];
extern const char D_00426F88[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1A2630 - 4 words (void*/unsigned d, no dd temp, p!=e loop, local g tried): s3/s4 swapped (g_DmgManage hi vs d register order)
extern "C" void func_001A2630(char *self, int d)
{
    *(const void **)(self + 0x214) = D_00426F88;
    int **p = (int **)(self + 0x600);
    int i;
    int dd = d;
    for (i = 1; i >= 0; i--, p++) {
        if (*p != 0) {
            func_001FE278(g_DmgManage, *p);
            *p = 0;
        }
    }
    func_001B6F38(self, dd);
}
#endif

struct Tbl6 { int v[6]; };
extern const Tbl6 D_00427CD8;
extern "C" int Rnd__Fv();

// FUNCTION: GAME 0x1ABB58
extern "C" int func_001ABB58(void *self, int idx)
{
    Tbl6 t = D_00427CD8;
    if (idx < 3)
        return 1;
    return Rnd__Fv() % t.v[idx] == 0;
}

struct V4 {
    float x, y, z, w;
};
extern "C" void func_001B6FB8(void *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" void *func_001FD9D8(void *, void *, void *, void *, void *);
extern "C" void func_001BFB28(void *);
#define FN170_BOX(NAME, X, Y, Z) \
extern "C" int NAME(char *self) \
{ \
    func_001B6FB8(self); \
    V4 a, b, c, d; \
    V4 *pa = &a; \
    V4 *pb = &b; \
    V4 *pc = &c; \
    a.x = (X); \
    a.y = (Y); \
    a.z = (Z); \
    pa->w = 1.0f; \
    b.x = (X); \
    b.y = (Y); \
    b.z = (Z); \
    pb->w = 1.0f; \
    c.x = 0; \
    c.y = a.y * -0.5f; \
    c.z = 0; \
    pc->w = 1.0f; \
    void *t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2); \
    *(void **)(self + 0x600) = t; \
    if (t) { \
        V4 *pd = &d; \
        d.x = 0; \
        d.y = 0; \
        d.z = 0; \
        pd->w = 1.0f; \
        func_001FD9D8(t, self + 0x80, &c, &d, &b); \
    } \
    *(short *)(self + 0x548) = 1; \
    *(short *)(self + 0x54A) = 1; \
    func_001BFB28(self); \
    return 1; \
}


// FUNCTION: GAME 0x19C1B0
FN170_BOX(func_0019C1B0, 0.839999974f, 1.35599995f, 0.839999974f)
