// Medium unnamed functions in 0x300000-0x31BFFF.
extern "C" void func_002A9528(void *);
extern "C" void func_002C53A8(void *);
extern char D_00754200[], SoundHeap[], RoomHeap[], SubScrHeap[], D_00754240[];
extern char D_00754C10[], D_00754C20[], scrArray[], D_00754C50[];
extern int objArray, objbaseArray;
unsigned int *SearchData(unsigned int *, const char *, unsigned int);
extern char D_0044FEA0[];

struct SrchPair { unsigned *b; unsigned *a; };

// FUNCTION: GAME 0x30EE68
extern "C" void func_0030EE68(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754200);
        func_002A9528(SoundHeap);
        func_002A9528(RoomHeap);
        func_002A9528(SubScrHeap);
        func_002A9528(D_00754240);
    }
}

// FUNCTION: GAME 0x305358
extern "C" void func_00305358(unsigned *self, unsigned *d)
{
    self[1] = (unsigned)SearchData(d, D_0044FEA0, 0);
    self[0] = (unsigned)SearchData(d, D_0044FEA0, 1);
}

#ifdef NONMATCHING
// DRAFT: GAME 0x3182D8
// 4 words differ: lui registers for the last two stores (D_00754C50 / objbaseArray) come out swapped
extern "C" void func_003182D8(void *p, int f)
{
    if (f == 0xFFFF && p) {
        func_002A9528(D_00754C10);
        func_002A9528(D_00754C20);
        objArray = 0;
        func_002C53A8(scrArray);
        objbaseArray = 0;
        *(int *)D_00754C50 = 0;
    }
}
#endif


struct LNode { LNode *prev; LNode *next; int _8; unsigned key; };
extern "C" void func_00307060(void *);
extern "C" int func_00305858(void *, int);
extern "C" void *func_003058D8(void *, int);
extern "C" void getEffTypeString__FPc12eEffDataType(char *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x306FF8
// 15 words differ: loop tail is rotated in the original (bnel back to the top); store order in the insert-before branch
extern "C" void func_00306FF8(char *self, LNode *n)
{
    LNode *c = (LNode *)(self + 0x4200);
    if (c) {
        for (;;) {
            if (n->key < c->key) {
                n->next = c;
                LNode *pv = c->prev;
                n->prev = pv;
                pv->next = n;
                c->prev = n;
                break;
            }
            if (c->next) {
                c = c->next;
                continue;
            }
            c->next = n;
            n->prev = c;
            n->next = 0;
            break;
        }
    }
    func_00307060(self);
}
#endif

// FUNCTION: GAME 0x3059A8
extern "C" int func_003059A8(void *self, int type, int x)
{
    char buf[16];
    int r;
    if (type == 5)
        r = 0;
    else {
        void *e = func_003058D8(self, type);
        if (!e) {
            getEffTypeString__FPc12eEffDataType(buf, type);
            r = 0;
        } else
            r = func_00305858(e, x);
    }
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x306F10
// 3 words differ: original computes (self + 0x300) first and adds i * 4 after; gcc adds self to i * 4 first
extern "C" int func_00306F10(char *self, int i)
{
    struct Ob { char _p[0xA]; unsigned short cnt; };
    Ob **sp;
    Ob *o;
    short r;
    if (i >= 32 || (o = *(sp = (Ob **)(self + 0x300) + i)) == 0)
        return -1;
    r = --o->cnt;
    if (r < 0)
        return r;
    if (r == 0) {
        func_00306FF8(self, (LNode *)*sp);
        *sp = 0;
    }
    return r;
}
#endif
