// Unnamed units in 0x2F0000-0x2FFFFF, continued.
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void func_002EBC50(char *, int);
extern char D_0044F7D0[];

#define FREE_AT(O) \
    if (*(char **)(self + O)) \
        free__5cHeapPv(*(void **)(*(char **)(self + O) - 0x20), *(char **)(self + O))

// FUNCTION: GAME 0x2F7D88
extern "C" void func_002F7D88(char *self, int f)
{
    *(char **)(self + 0xF0) = D_0044F7D0;
    FREE_AT(0x364);
    FREE_AT(0x368);
    FREE_AT(0x36C);
    FREE_AT(0x370);
    FREE_AT(0x360);
    func_002EBC50(self, f);
}

extern "C" void *func_002FBCC8(void *);
struct Qv { float f[4]; };
#define VF0(P) __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)(P)))

// FUNCTION: GAME 0x2F7CD8
extern "C" void *func_002F7CD8(char *self)
{
    func_002FBCC8(self);
    float one = 1.0f;
    *(int *)(self + 0x2B0) = 0;
    *(char **)(self + 0xF0) = D_0044F7D0;
    *(float *)(self + 0x2D4) = one;
    *(int *)(self + 0x2B4) = 0;
    *(int *)(self + 0x2B8) = 0;
    *(int *)(self + 0x2BC) = 0;
    *(int *)(self + 0x2C0) = 0;
    *(int *)(self + 0x2C4) = 0;
    *(int *)(self + 0x2C8) = 0;
    *(int *)(self + 0x2D8) = 0;
    *(int *)(self + 0x2DC) = 0;
    char *q = self + 0x320;
    int i = 1;
    do {
        VF0(q);
        i--;
        q += 16;
    } while (i != -1);
    VF0(self + 0x340);
    VF0(self + 0x350);
    *(int *)(self + 0x2BC) = 0;
    *(int *)(self + 0x360) = 0;
    *(int *)(self + 0x364) = 0;
    *(int *)(self + 0x368) = 0;
    *(int *)(self + 0x36C) = 0;
    *(int *)(self + 0x370) = 0;
    return self;
}

#ifdef NONMATCHING
struct cVec { float x, y, z, w; };
class cNode { public: void setLocalTranslation(const cVec &); };
extern "C" void func_002FBE50(void *);
extern "C" void func_002FBED0(void *);

static inline unsigned char okLt(const int &n, int i) { unsigned char ok = 0; ok = i < n; return ok; }
// DRAFT: GAME 0x2F9DC8 (37 words: andi 0xFF after slt missing, lbu n before bltz, tail is func_002B6288(self,&v) w/ v.w store in delay slot; tried uchar ok local, n+&n, okLt(const int&) inline)
extern "C" void func_002F9DC8(char *self)
{
    char *p = *(char **)(self + 0x114);
    if (!p) {
        func_002FBE50(self);
        return;
    }
    int i = *(int *)(self + 0x2B4);
    int slot = 0;
    if (i >= 0 && okLt(*(unsigned char *)(p + 0x2B4), i))
        slot = (*(int **)(p + 0x278))[i];
    if (!slot) {
        func_002FBE50(self);
        return;
    }
    cVec v __attribute__((aligned(16)));
    v.x = 0;
    v.y = 0;
    v.z = 0;
    v.w = 1.0f;
    ((cNode *)self)->setLocalTranslation(v);
    func_002FBED0(self);
}
#endif

extern "C" void func_002FBE50(void *);
extern "C" void func_002FA350(float *);
extern int D_00747A84;

// FUNCTION: GAME 0x2FCAC8
extern "C" int func_002FCAC8(char *self)
{
    if (!*(unsigned char *)(self + 0x24C))
        return 0;
    if ((!(*(int *)(*(char **)(self + 0x110) + 4) & 0x2000) && (*(unsigned char *)(self + 0x11D) & 1)) || (D_00747A84 & 0x20000))
        func_002FA350((float *)(self + 0x250));
    else
        *(float *)(self + 0x250) = *(float *)(self + 0x250) + 1.0f;
    int t = (int)*(float *)(self + 0x250);
    *(unsigned char *)(self + 0x24D) = t;
    if ((unsigned char)t >= *(unsigned char *)(self + 0x24C)) {
        func_002FBE50(self);
        return 1;
    }
    return 0;
}
