// Unnamed units in 0x2E0000-0x2EFFFF, continued.
extern char D_0061B644;

#ifdef NONMATCHING
// DRAFT: GAME 0x2E9BA0 (13 words off: f0/f1 swapped in every float temp (store order now matches); 5 probes)
extern "C" int func_002E9BA0(char *self)
{
    *(unsigned *)(self + 0x11C) &= 0xFEFFFFFF;
    char *o = *(char **)(self + 0x110);
    float t = 0.01f * *(float *)(o + 0x144);
    *(float *)(self + 0x2B4) = t;
    *(float *)(self + 0x2B0) = t;
    *(float *)(self + 0x2BC) = *(float *)(o + 0x150) * 0.1f;
    *(float *)(self + 0x2C8) = *(float *)(o + 0x13C) * 1000.0f;
    *(float *)(self + 0x2D0) = *(float *)(o + 0x140);
    *(unsigned char *)(self + 0x2CC) = *(unsigned char *)(o + 0x16C);
    *(unsigned char *)(self + 0x2CE) = *(unsigned char *)(o + 0x170) + 1;
    D_0061B644 = 0;
    return 1;
}
#endif

#ifdef NONMATCHING
struct cHeap;
extern cHeap D_00754200;
void *_MemoryAlloc(unsigned, unsigned, cHeap &);
extern char D_0061B280[];
extern int D_00747A34;
extern char D_00580D40[], D_0044E030[], D_0044E040[];
extern "C" void func_001FFD00(char *, char *);

// DRAFT: GAME 0x2E1348 (23 words off: original shares the lq/epilogue in branch delay slots; 3 probes)
extern "C" void func_002E1348()
{
    D_0061B280[9] = 8;
    *(short *)(D_0061B280 + 0xA) = 0;
    D_0061B280[8] = 8;
    void *p = _MemoryAlloc(0x1000, 0x40, D_00754200);
    int f = D_00747A34;
    *(void **)(D_0061B280 + 0x14) = p;
    if (f & 0x4000)
        func_001FFD00(D_00580D40, D_0044E040);
    else
        func_001FFD00(D_00580D40, D_0044E030);
}
#endif

#ifdef NONMATCHING
extern "C" void func_002FBED0(void *);
extern "C" void func_002FBE50(void *);
extern "C" void func_002E2C50(void *);
extern "C" void func_002E2D40(void *);
extern "C" void func_002E2E00(void *);

// DRAFT: GAME 0x2E2800 (46 words off: original beq/beqz/beq chain plus beql instead of movz for the 0x1E default; 3 probes)
extern "C" void func_002E2800(char *self)
{
    func_002FBED0(self);
    if (!(*(unsigned char *)(self + 0x2CC) & 1)) {
        if (*(unsigned *)(self + 0x2CC) & 4) {
            int c = *(unsigned char *)(self + 0x2D5);
            if (!c)
                c = 0x1E;
            *(unsigned char *)(self + 0x24C) = c;
            *(unsigned *)(self + 0x2CC) &= 0xFFFFFFFB;
        }
        return;
    }
    switch (*(int *)(self + 0x2C4)) {
    case 1:
        func_002E2D40(self);
        break;
    case 0:
        func_002E2C50(self);
        break;
    case 2:
        func_002E2E00(self);
        break;
    default:
        func_002FBE50(self);
        break;
    }
}
#endif
