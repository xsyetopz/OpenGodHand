extern char RelSys[];

extern "C" void unlinkNoFree__7cRelSysQ27cRelSys8eRelType(void *, int);
extern "C" void free__5cHeapPv(void *, void *);
extern "C" void func_00297660(void *);
// FUNCTION: GAME 0x2974F0
extern "C" void func_002974F0(char *self)
{
    unsigned long f = *(unsigned char *)(self + 8);
    if (f >> 7) {
        unlinkNoFree__7cRelSysQ27cRelSys8eRelType(RelSys, 2);
        *(int *)(self + 8) &= -0x81;
    }
}


// FUNCTION: GAME 0x2962F0
extern "C" void func_002962F0(char *self)
{
    unsigned long f = *(unsigned char *)(self + 8);
    if (f >> 7) unlinkNoFree__7cRelSysQ27cRelSys8eRelType(RelSys, 2);
    char *p = *(char **)(self + 0x10);
    if (p) {
        free__5cHeapPv(*(void **)(p - 0x20), p);
    }
    *(char **)(self + 0x10) = 0;
    func_00297660(self);
}
