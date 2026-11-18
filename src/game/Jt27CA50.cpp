// Motion sequence with shared call tail; sole switch of 0x27CA50.
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x27CA50
extern "C" void func_0027CA50(char *self)
{
    char *t;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x90) + (int)t, *(int *)(t + 0x94) + (int)t, 5, 0.0f, 0, 0);
        self[0x2F6]++;
        goto mm;
    case 2:
        t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x98) + (int)t, *(int *)(t + 0x9C) + (int)t, 5, 0.0f, 0, 0);
        self[0x2F6]++;
    case 1:
    case 3:
    mm:
        moveMotion__FP8cObjBase(self);
        break;
    case 4:
        t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0xA0) + (int)t, *(int *)(t + 0xA4) + (int)t, 5, 0.0f, 0, 0);
        self[0x2F6]++;
    case 5:
        if (moveMotion__FP8cObjBase(self)) {
            self[0x2F4] = 0;
            self[0x2F5] = 0;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
    }
}
