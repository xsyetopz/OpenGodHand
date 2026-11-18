struct cObjBase;
extern "C" void func_002A8578(cObjBase *, float, int, int, int, int, int);
int moveMotion(cObjBase *);

// FUNCTION: GAME 0x2827C8
extern "C" void func_002827C8(char *self)
{
    unsigned char x = *(unsigned char *)(self + 0x15B0);
    int t = x ? 2 : 0;
    if (x) t = 2;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        switch (*(unsigned char *)(self + 0x2F7)) {
        default:
        case 0: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xC0) + (int)tb, *(int *)(tb + 0xC4) + (int)tb, 2, t, 0); } break;
        case 1: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xB8) + (int)tb, *(int *)(tb + 0xBC) + (int)tb, 2, t, 0); } break;
        case 2: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xC8) + (int)tb, *(int *)(tb + 0xCC) + (int)tb, 2, t, 0); } break;
        case 3: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xD0) + (int)tb, *(int *)(tb + 0xD4) + (int)tb, 2, t, 0); } break;
        case 4: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xD8) + (int)tb, *(int *)(tb + 0xDC) + (int)tb, 2, t, 0); } break;
        case 5: { char *tb = *(char **)(self + 0x304); func_002A8578((cObjBase *)self, 0.0f, *(int *)(tb + 0xD0) + (int)tb, *(int *)(tb + 0xD4) + (int)tb, 2, t, 0); } break;
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        moveMotion((cObjBase *)self);
    }
}
