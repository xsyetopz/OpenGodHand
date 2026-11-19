struct RoomObj { char _p[0x54A]; short m_54A; char _q[0xF4]; unsigned short m_640; };

extern void func_002954D0(int a, int b, int n);

// FUNCTION: GAME 0x2956A0
extern "C" void func_002956A0(int self, RoomObj *o)
{
    int k = o->m_640;
    if ((unsigned)k < 0x40) {
        if (o->m_54A > 0)
            func_002954D0(self, k, o->m_54A);
        else
            func_002954D0(self, k, 1);
    }
}

struct DmgNode { int _0; DmgNode *m_4; char *m_8; };
struct DmgList { char _p[0x500]; DmgNode *m_500; };

extern "C" int strcmp(const char *, const char *);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(const float *, const float *);
extern "C" void setDamage__5cEma2(void *);
extern char D_0044A7A8[];

// FUNCTION: GAME 0x292D18
extern "C" void func_00292D18(DmgList *self, const float *pos)
{
    for (DmgNode *n = self->m_500; n; n = n->m_4) {
        char *e = n->m_8;
        if (e) {
            if (strcmp(D_0044A7A8, *(const char **)(e + 0x4AC)) == 0 && *(short *)(e + 0x54A) > 0) {
                if (!(4.0f < capVu0MagnitudeSqXZ__FPCfT0(*(const float **)(e + 0xF0), pos)))
                    setDamage__5cEma2(e);
            }
        }
    }
}

struct RdSlot { char _p[8]; unsigned char m_8; char _q[3]; void *m_C; void *m_10; };

extern "C" int sprintf(char *, const char *, ...);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(void *, const char *, void **, void *, int, unsigned, unsigned, unsigned);
extern void *MemDefalutHeapPtr;
extern char Dvd[];
extern unsigned D_00747A30;
extern char D_0044A920[], D_0044A940[], D_0044A958[];

// DRAFT: GAME 0x297378 - 8 words differ: else branch stores m_10 after sprintf in original, here before; storing after in both branches makes gcc merge the sprintf calls (31 words); tried common-tail store (7 words, sw/lui order), *(int*) store, int r = sprintf, extra m_C stores, comma-expr store in sprintf arg (8), swapped branches (31), fmt local (22), z temp (31); orig also orders lui/lw a3/addiu a0/daddu a1 differently before ReadAlloc
#ifdef NONMATCHING
extern "C" void func_00297378(RdSlot *self)
{
    char buf[0x40];
    unsigned long f = (unsigned long)self->m_8;
    unsigned long b = f >> 7;
    if (!b) {
        if (D_00747A30 & 0x400) {
            sprintf(buf, D_0044A920, D_0044A940);
            self->m_10 = 0;
        } else {
            self->m_10 = 0;
            sprintf(buf, D_0044A958, D_0044A940);
        }
        self->m_C = (void *)ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, buf, &self->m_10, MemDefalutHeapPtr, 0, 0, 0, 0);
    }
}
#endif
