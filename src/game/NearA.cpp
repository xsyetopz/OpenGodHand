// God Hand: near-miss conversions
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void moveMotion__FP8cObjBase(void *);
// FUNCTION: GAME 0x27F5F0
extern "C" void func_0027F5F0(char *self)
{
    switch ((unsigned char)self[0x2F6]) {
    case 0:
        switch ((unsigned char)self[0x2F7]) {
        default:
        case 0: {
            char *p = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(p + 0x2C) + (int)p, *(int *)(p + 0x30) + (int)p, 5, 0, 0, 0.0f);
            break;
        }
        case 1: {
            char *p = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(p + 0x34) + (int)p, *(int *)(p + 0x38) + (int)p, 5, 0, 0, 0.0f);
            break;
        }
        }
        self[0x2F6]++;
    case 1:
        moveMotion__FP8cObjBase(self);
    }
}

extern "C" void *memset(void *, int, unsigned);
extern "C" int *func_001E7E18(int *);
extern "C" int *func_001E7960(int *);
extern "C" int *func_001E7118(int *);
// FUNCTION: GAME 0x1DFB98
extern "C" char *__5Slot1(char *self)
{
    char *p;
    int i;
    memset(self, 0, 0x54);
    *(int *)(self + 0x54) = 0;
    p = self + 0x58;
    for (i = 2; i != -1; i--) {
        func_001E7E18((int *)p);
        p += 0x108;
    }
    func_001E7960((int *)(self + 0x370));
    func_001E7118((int *)(self + 0x4D0));
    *(unsigned short *)(self + 0x48C) = 0xFFFF;
    *(int *)(self + 0x490) = 9;
    *(int *)(self + 0x4B0) = 0;
    *(int *)(self + 0x4B4) = 0;
    *(int *)(self + 0x4B8) = 0;
    *(int *)(self + 0x4BC) = 0;
    *(int *)(self + 0x498) = 0;
    *(short *)(self + 0x4C2) = 0;
    *(short *)(self + 0xB50) = 0;
    *(short *)(self + 0xB52) = 0;
    return self;
}
