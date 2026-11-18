struct cObjBase;
extern "C" void func_002A8578(cObjBase *, float, int, int, int, int, int);
int moveMotion(cObjBase *);

// FUNCTION: GAME 0x281F38
extern "C" void func_00281F38(char *self)
{
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *tb;
        if (*(unsigned char *)(self + 0x2F7)) {
            tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x60) + (int)tb, *(int *)(tb + 0x68) + (int)tb, 5, t, 0);
        } else {
            tb = *(char **)(self + 0x304);
            func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x60) + (int)tb, *(int *)(tb + 0x64) + (int)tb, 5, t, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion((cObjBase *)self);
        break;
    case 2: {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x6C) + (int)tb, *(int *)(tb + 0x70) + (int)tb, 5, t, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 3:
        moveMotion((cObjBase *)self);
        break;
    case 4: {
        char *tb = *(char **)(self + 0x304);
        func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0x74) + (int)tb, *(int *)(tb + 0x78) + (int)tb, 5, t, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 5:
        if (moveMotion((cObjBase *)self)) {
            *(unsigned char *)(self + 0x2F7) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F4) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F5) = 0;
            __asm__ volatile("");
            *(unsigned char *)(self + 0x2F6) = 0;
        }
    }
}
