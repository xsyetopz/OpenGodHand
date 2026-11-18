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

#ifdef NONMATCHING
// DRAFT: GAME 0x1B3548 - n spill is sb/sltiu instead of sw/slt; same unresolved idiom as 0x1C2378
extern "C" void func_001B3548(Mdl190 *self)
{
    unsigned char n = self->n;
    const unsigned char &r = n;
    char *e = (r > 2) ? self->tbl[2] : 0;
    float *f = (float *)(e + 0x100);
    float v = (*f - 3.1415927f) * 0.9f + 3.1415927f;
    *f = v;
    if (v >= 3.054326f) {
        *f = 3.1415927f;
        *((unsigned char *)self + 0x2F5) = 2;
    }
}
#endif
