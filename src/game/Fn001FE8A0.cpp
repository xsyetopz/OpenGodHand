extern "C" int func_001FEE00(char *, int);
extern "C" int func_001FEEA0(char *);
extern "C" void func_001FF090(char *);
extern "C" int func_001FF180(char *, int, int);
extern "C" int func_001FF238(char *);
void func_002D5250(unsigned short);

// FUNCTION: GAME 0x1FE8A0
extern "C" int loadWait__12cDataManager6eObjIdR5cHeapb(char *self, int id, int heap, int wait)
{
    int i = func_001FEE00(self, id);
    if (i >= 0) {
        func_001FF090(*(char **)(self + 8) + i * 0x5C);
        return *(int *)(*(char **)(self + 8) + i * 0x5C + 0x10);
    }
    i = func_001FEEA0(self);
    if (i < 0)
        return 0;
    int r = func_001FF180(*(char **)(self + 8) + i * 0x5C, id, heap);
    while (!func_001FF238(*(char **)(self + 8) + i * 0x5C))
        func_002D5250(1);
    if (wait)
        func_001FF090(*(char **)(self + 8) + i * 0x5C);
    else
        *(int *)(i * 0x5C + *(int *)(self + 8) + 4) = -100;
    return r;
}
