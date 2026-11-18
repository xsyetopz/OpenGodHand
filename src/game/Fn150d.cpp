// Second half of Fn150b (split to keep files under 300 lines).
// Units in .text 0x150000-0x16FFFF (continued).

struct VT150 {
    char _pad[8];
    short adj;
    short _pad2;
    void (*fn)(void *, int);
};
extern "C" void func_002A9800(void *self, void *obj);
// FUNCTION: GAME 0x15FBA8
extern "C" void func_001538F0();
extern "C" void func_002C54E8(char *);
extern "C" void func_0030F650();
extern "C" void func_002C3818(char *);
extern "C" void func_002AF028(char *);
extern "C" void func_002FB310();
extern "C" void func_001410A8(char *);
extern "C" void func_00160B90(char *);
extern char *ScrDraw;
extern char *g_Sce;
extern char *Message;
extern char *Cockpit;
extern char *SubScr;
void Trans(void)
{
    func_001538F0();
    func_002C54E8(ScrDraw);
    func_0030F650();
    func_002C3818(g_Sce);
    func_002AF028(Message);
    func_002FB310();
    func_001410A8(Cockpit);
    func_00160B90(SubScr);
}

// FUNCTION: GAME 0x156918
struct cVec { float x, y, z, w; };
struct V2N { float x, y; };
int chack_point_line(const cVec &p, const cVec &a, const cVec &b)
{
    V2N u, v;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(u));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(v));
    u.x = a.x - p.x;
    u.y = a.y - p.y;
    v.x = b.x - p.x;
    v.y = b.y - p.y;
    float c = u.x * v.y - u.y * v.x;
    int r;
    if (c > 0.0f)
        r = 1;
    else if (c < 0.0f)
        r = -1;
    else
        r = 0;
    return r;
}

// FUNCTION: GAME 0x15FC10
extern int D_00566E30;
extern int D_00752D08;
extern unsigned int D_00747A2C[];
extern char cFilter_tag[];
extern "C" int func_003950F8(int, int);
extern "C" void func_00299368(char *);
extern "C" void func_002A0940(char *);
extern "C" void func_0015FC10(void)
{
    D_00566E30 = 1;
    do {
        D_00566E30 = func_003950F8(1, 0);
    } while (D_00566E30);
    int t = *(volatile int *)0x10000800;
    unsigned f = D_00747A2C[1] & 0x4000000;
    D_00752D08 = t;
    if (!f) {
        func_00299368(cFilter_tag);
        func_002A0940(cFilter_tag);
    }
    D_00752D08 = D_00752D08 - *(volatile int *)0x10000800;
}

// DRAFT: GAME 0x157178
// diff: 23 words, fp reg alloc/load order (orig loads b.z before c.z but subs dz after ez-less order); tried decl orders, inline ez, split dot/len, ex*dx operand order; best is ez before dz
#ifdef NONMATCHING
void GetPointCalcPointLine(const cVec &a, const cVec &b, const cVec &c, cVec *out)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;
    float ex = c.x - a.x;
    float ey = c.y - a.y;
    float ez = c.z - a.z;
    float dz = b.z - a.z;
    float t = (dx * ex + dy * ey + dz * ez) / (dx * dx + dy * dy + dz * dz);
    out->x = a.x + dx * t;
    out->y = a.y + dy * t;
    out->z = a.z + dz * t;
    out->w = 1.0f;
}
#endif

// FUNCTION: GAME 0x1508F8
extern "C" void func_002D5070(char *);
extern "C" char *func_001508F8(char *self)
{
    char *p = self + 0x3DC88;
    int i = 0x1C1;
    do {
        char *q = p;
        int j = 1;
        do {
            func_002D5070(q);
            q += 8;
        } while (--j != -1);
        p += 0x10;
    } while (--i != -1);
    *(int *)(self + 8) = 0x2600;
    *(int *)(self + 0) = 0;
    *(int *)(self + 0xC) = 0;
    *(int *)(self + 4) = 0;
    return self;
}

// DRAFT: GAME 0x152340
// diff: reg alloc (a2 vs v1 for divisor 8) and search-loop layout
#ifdef NONMATCHING
extern "C" int func_00151630(char *);
static inline unsigned AlignPad152340(unsigned v, unsigned a)
{
    return v + (a - v % a) % a;
}
extern "C" int func_00152340(char *self, long key)
{
    unsigned a = 8;
    unsigned v = (unsigned)self + (*(int *)(self + 4) * 4 + 0x10);
    long *tbl = (long *)AlignPad152340(v, a);
    if (func_00151630(self) == 3) {
        int n = *(int *)(self + 4);
        int i;
        for (i = 0; i < n; i++) {
            if (tbl[i] == key)
                break;
        }
        if (i < n)
            return i;
    }
    return -1;
}
#endif

// DRAFT: GAME 0x159510
// diff: loop tail duplication (bnel+lbu in delay slots) and handler-call reg alloc
#ifdef NONMATCHING
typedef float (*MotionFn159510)(char *, char *, int, float);
extern MotionFn159510 D_003BD910[];
float MotionGetParam(void *obj, int id, int kind, float f)
{
    char *o = (char *)obj;
    if (o) {
        char *e = o + 8;
        for (unsigned i = 0; i < *(unsigned char *)(o + 6); i++, e += 12) {
            if (*(signed char *)e != id)
                continue;
            unsigned w = *(unsigned *)e;
            if (kind != -1 && (int)((w >> 8) & 0xF) != kind)
                continue;
            return D_003BD910[(w >> 12) & 0xF](o, e, kind, f);
        }
    }
    if (kind < 9) {
        if (kind < 6)
            return 0.0f;
        return 1.0f;
    }
    return 0.0f;
}
#endif
