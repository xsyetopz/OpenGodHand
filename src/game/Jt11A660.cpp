// Six-state motion sequence; sole switch and jump table of 0x11A660.
extern char g_CollSolidManage[];
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void func_002A8578(void *, int, int, int, float, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_0012AC28(void *);
extern "C" void func_0012B928(void *);
extern "C" void func_0012C540(void *, int);

// FUNCTION: GAME 0x11A660
extern "C" void func_0011A660(char *self)
{
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(float *)(self + 0x54C) = 2.0f;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x6F0) + (int)t, *(int *)(t + 0x6F4) + (int)t, 3, 0.0f, 0, 0);
        func_0012AC28(self);
        func_0012B928(self);
        self[0x2F6]++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            func_0012C540(self, 1);
            self[0x2F6]++;
            *(unsigned *)(self + 0x250) |= 2;
            char *p = *(char **)(self + 0x68C);
            if (p)
                *(unsigned *)(p + 0x250) |= 2;
        }
        break;
    case 2: {
        char *t = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(t + 0x28) + (int)t, *(int *)(t + 0x2C) + (int)t, 3, 0.0f, 0, 0);
        self[0x2F6]++;
    }
    case 3: {
        moveMotion__FP8cObjBase(self);
        *(unsigned *)(self + 0x15F4) |= 0x1000;
        *(unsigned *)(self + 0x250) |= 2;
        char *p = *(char **)(self + 0x68C);
        if (p)
            *(unsigned *)(p + 0x250) |= 2;
        break;
    }
    case 4: {
        char *t = *(char **)(self + 0x304);
        *(short *)(self + 0x5E0) = 0;
        *(short *)(self + 0x5E2) = 0;
        func_002A8578(self, *(int *)(t + 0x6F8) + (int)t, *(int *)(t + 0x6FC) + (int)t, 0, 0.0f, 0, 0);
        self[0x2F6]++;
    }
    case 5:
        if (moveMotion__FP8cObjBase(self)) {
            self[0x2F4] = 0;
            self[0x2F5] = 0;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
    }
}
