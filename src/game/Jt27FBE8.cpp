// Motion sequence with shared call tail; sole switch of 0x27FBE8.
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);

// DRAFT: GAME 0x27FBE8 - 36 words differ (280 vs 280 B): original has a1=0 in the jump delay slot and a different arg-setup schedule in cases 0/2/4; tried (cObjBase*,float,int x5) and float-last signatures, int z=0 passed for zero args: still 36
#ifdef NONMATCHING
extern "C" void func_0027FBE8(char *self)
{
    char *t;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        t = *(char **)(self + 0x304);
        { int a = *(int *)(t + 0x14); int b = *(int *)(t + 0x18); func_002A8578(self, a + (int)t, b + (int)t, 5, 0.0f, 0, 0); }
        *(int *)(self + 0x5F0) = 1;
        self[0x2F6]++;
    case 1:
        moveMotion__FP8cObjBase(self);
        break;
    case 2:
        t = *(char **)(self + 0x304);
        { int a = *(int *)(t + 0x1C); int b = *(int *)(t + 0x20); func_002A8578(self, a + (int)t, b + (int)t, 5, 0.0f, 0, 0); }
        *(int *)(self + 0x5F0) = 1;
        self[0x2F6]++;
        goto chk;
    case 4:
        t = *(char **)(self + 0x304);
        { int a = *(int *)(t + 0x24); int b = *(int *)(t + 0x28); func_002A8578(self, a + (int)t, b + (int)t, 5, 0.0f, 0, 0); }
        *(int *)(self + 0x5F0) = 1;
        self[0x2F6]++;
    case 3:
    case 5:
    chk:
        if (moveMotion__FP8cObjBase(self)) {
            self[0x2F4] = 0;
            self[0x2F5] = 0;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
    }
}
#endif
