// Motion sequence with shared call tail; sole switch of 0x27FBE8.
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x27FBE8
extern "C" void func_0027FBE8(char *self)
{
    char *t;
    int x, y;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x14) + (int)t, *(int *)(t + 0x18) + (int)t, 5, 0.0f, 0, 0);
        *(int *)(self + 0x5F0) = 1;
        self[0x2F6]++;
    case 1:
        moveMotion__FP8cObjBase(self);
        break;
    case 2: {
        t = *(char **)(self + 0x304);
        x = *(int *)(t + 0x1C);
        y = *(int *)(t + 0x20);
        goto call;
    case 4:
        t = *(char **)(self + 0x304);
        x = *(int *)(t + 0x24);
        y = *(int *)(t + 0x28);
    call:
        func_002A8578(self, x + (int)t, y + (int)t, 5, 0.0f, 0, 0);
    }
    adv:
        *(int *)(self + 0x5F0) = 1;
        self[0x2F6]++;
    case 3:
    case 5:
        if (moveMotion__FP8cObjBase(self)) {
            self[0x2F4] = 0;
            self[0x2F5] = 0;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
    }
}
