struct W {
    unsigned flags; int p4, p8, c, p10, p14, p18, p1c, p20, p24, p28, p2c;
    short s30, s32; char b34, b35, b36, pad; int p38, p3c, p40;
};
struct WArr { char pad[0x104]; W w[8]; };

extern char g_ActBtn[];
extern "C" void func_001F4778(void *, int, int);
struct CustomIDWork {
    void SetOffsetPosX(int);
    void SetNumber(int);
};
extern "C" void func_001F77D0(WArr *);
extern "C" void func_001F7820(char *, W *);

extern "C" void *initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void restartAnim__7cIDBase(void *);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(void *, void *);
extern "C" void SetDisp__12CustomIDWorkb(char *, int);

enum eScePriority { P0 };
enum eActType { T0 };
enum eActBtnType { B0 };
enum eActFunc { F0 };
struct Node { unsigned flags; int p4, p8, pc, p10, p14, p18, p1c, p20, p24; };
struct cActionButton {
    void set(eScePriority, eActType, eActBtnType, void *, void *, eActFunc);
};
extern "C" Node *func_001F7798(cActionButton *);
extern "C" void func_001F7800(cActionButton *, int, Node *);

struct E16 { int a, b, c, d; };
struct E44 { int a, b, c; char pad[0x44 - 12]; };
extern char D_0042C2D8[], D_0042C2B0[];
extern "C" void func_001F7AE8(E44 *);

extern "C" void *memset(void *, int, unsigned int);
extern char D_005686D0[];
extern char *CoreSave;
extern "C" void func_001FAFA8(void *);
extern "C" void func_001FC138(void *);
extern "C" void setGameDifficulty__9cCoreSave11eDifficulty(void *, int);
extern "C" int func_001FEE00(void *);
extern "C" void func_001FF090(void *);
extern "C" void func_001FF448(void *);

// FUNCTION: GAME 0x1F4B98
extern "C" void func_001F4B98(void *o, unsigned short i, int a, int b)
{
    if (i < 7) {
        func_001F4778(o, i + 10, 0);
        func_001F4778(o, i + 17, 0);
        if (b) {
            if (a) func_001F4778(o, i + 17, 1);
            else func_001F4778(o, i + 10, 1);
        }
    }
}

// FUNCTION: GAME 0x1F4FF0
extern "C" void func_001F4FF0(char *o, unsigned short i, int n, int c)
{
    if (i < 7) {
        int off;
        off = -17;
        if (n >= 10) off = n > 99 ? 0 : -10;
        int idx = i + 0x26;
        CustomIDWork *w = (CustomIDWork *)(o + (idx * 0x7C + 0x60));
        w->SetOffsetPosX(off);
        w->SetNumber(n);
        func_001F4778(o, idx, c);
    }
}

// FUNCTION: GAME 0x1F5478
extern "C" void func_001F5478(void *p, int q)
{
    func_001F4778(p, 0x61, q);
    func_001F4778(p, 0x62, q);
    func_001F4778(p, 0x63, q);
    func_001F4778(p, 0x64, q);
    func_001F4778(p, 0x65, q);
    func_001F4778(p, 0x66, q);
    func_001F4778(p, 0x67, q);
}

// FUNCTION: GAME 0x1F7228
extern "C" void func_001F7228(W *w)
{
    func_001F7820(g_ActBtn, w);
    w->flags &= ~1u;
    w->c = 1;
    w->p1c = 0x31;
    w->p2c = 0x1F;
    w->p10 = 0;
    w->p14 = 0;
    w->p18 = 0;
    w->p24 = 0;
    w->p20 = 0;
    w->p28 = 0;
    w->s30 = 0;
    w->b34 = 0;
    w->b35 = 0;
    w->s32 = 0;
    w->b36 = 0;
    w->p38 = 0;
    w->p3c = 0;
    w->p40 = 0;
}

// FUNCTION: GAME 0x1F72C0
extern "C" void func_001F72C0(WArr *a)
{
    func_001F77D0(a);
    for (unsigned i = 0; i < 8; i++) {
        W *w = &a->w[i];
        w->flags &= ~1u;
        w->c = 1;
        w->p10 = 0;
        w->p14 = 0;
        w->p18 = 0;
        w->p1c = 0x31;
        w->p24 = 0;
        w->p20 = 0;
        w->p28 = 0;
        w->p2c = 0x1F;
        w->s30 = 0;
        w->b34 = 0;
        w->b35 = 0;
        w->s32 = 0;
        w->b36 = 0;
        w->p38 = 0;
        w->p3c = 0;
        w->p40 = 0;
    }
}

// FUNCTION: GAME 0x1F4648
extern "C" void func_001F4648(char *self)
{
    void *base = self + 0x10;
    int i = 0;
    char *w = self + 0x60;
    initialize__7cIDBase7eIdData5eIdNo(base, 0x15, 0);
    restartAnim__7cIDBase(base);
    do {
        Initialize__12CustomIDWorkP7cIDWork(w, getIDWork__7cIDBasei(self + 0x10, i));
        i++;
        w += 0x7C;
    } while (i < 0x6F);
    func_001F4778(self, 0x6F, 0);
}

// FUNCTION: GAME 0x1F4778
extern "C" void func_001F4778(void *obj, int idx, int on)
{
    char *self = (char *)obj;
    if (on) {
        if (idx == 0x6F) {
            char *w = self + 0x60;
            for (int i = 0x6E; i >= 0; i--, w += 0x7C)
                SetDisp__12CustomIDWorkb(w, 1);
        } else {
            SetDisp__12CustomIDWorkb(self + (idx * 0x7C + 0x60), 1);
        }
    } else {
        if (idx == 0x6F) {
            char *w = self + 0x60;
            for (int i = 0x6E; i >= 0; i--, w += 0x7C)
                SetDisp__12CustomIDWorkb(w, 0);
        } else {
            SetDisp__12CustomIDWorkb(self + (idx * 0x7C + 0x60), 0);
        }
    }
}

// FUNCTION: GAME 0x1F7858
void cActionButton::set(eScePriority pr, eActType t, eActBtnType b, void *x, void *y, eActFunc f)
{
    Node *n = func_001F7798(this);
    if (n) {
        n->p1c = t;
        n->flags |= 1;
        n->p20 = b;
        n->p10 = (int)x;
        n->p14 = (int)y;
        n->p24 = f;
        n->p18 = pr;
        func_001F7800(this, pr, n);
    }
}

// FUNCTION: GAME 0x1F7A30
extern "C" void func_001F7A30(int a, int b)
{
    if (b == 0xFFFF && a) {
        char *g = g_ActBtn;
        E16 *e = (E16 *)(g + 4);
        int n = 15;
        do {
            e->a = 3;
            e->c = (int)D_0042C2D8;
            n--;
            e++;
        } while (n != -1);
        int m = 7;
        E44 *w = (E44 *)(g + 0x104);
        do {
            w->a = 3;
            w->c = (int)D_0042C2B0;
            func_001F7AE8(w);
            m--;
            w++;
        } while (m != -1);
    }
}

// FUNCTION: GAME 0x1FEA48
extern "C" int func_001FEA48(char *self)
{
    int i = func_001FEE00(self);
    int r;
    if (i < 0) r = 0;
    else {
        int off = i * 0x5C;
        func_001FF090(*(char **)(self + 8) + off);
        int base = *(int *)(self + 8);
        char *p = (char *)(off + base);
        r = *(int *)(p + 0x10);
    }
    return r;
}

// FUNCTION: GAME 0x1FEF30
extern "C" void clear__12cDataManager(char *self)
{
    int i = *(int *)(self + 4);
    i--;
    asm("" : "+r"(i));
    if (i != -1) {
        int off = i * 0x5C;
        do {
            i--;
            func_001FF448(*(char **)(self + 8) + off);
            off -= 0x5C;
        } while (i != -1);
    }
}

// FUNCTION: GAME 0x1FEFD0
extern "C" int isUnload__12cDataManager6eObjId(char *self, int id)
{
    int i = *(int *)(self + 4);
    i--;
    asm("" : "+r"(i));
    if (i != -1) {
        int base = *(int *)(self + 8);
        int o = i * 0x5C;
        char *p = (char *)(o + base);
        do {
            if (*(int *)(p + 0x20) == id && *(int *)p != 8) return 0;
            i--;
            p -= 0x5C;
        } while (i != -1);
    }
    return 1;
}

// FUNCTION: GAME 0x1F9848
extern "C" void systemInit__9cCoreSave(char **self)
{
    memset(D_005686D0, 0, 0x14A0);
    CoreSave = D_005686D0;
    func_001FAFA8(self);
    unsigned i = 0;
    do {
        *(char *)(*(int *)self + i + 0xB0) = -1;
        i++;
    } while (i < 0x80);
    func_001FC138(self);
    setGameDifficulty__9cCoreSave11eDifficulty(self, 1);
}
