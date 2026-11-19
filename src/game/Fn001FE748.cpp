// Slice F138: func_001FE748, func_0023D410, func_0027F780.
extern "C" void func_001FF110(void *);
extern "C" int func_001FF6E0(void *, int);
extern "C" int func_001FF710(void *, int);
extern "C" int func_001FF0D8(void *, int);
extern "C" void func_001FF2E0(void *, int);

// DRAFT: GAME 0x1FE748
#ifdef NONMATCHING
extern "C" void func_001FE748(char *self)
{
    int i;
    for (i = *(int *)(self + 4) - 1; i != -1; i--) {
        {
            int off = i * 0x5C;
            func_001FF110(*(char **)(self + 8) + off);
            if (func_001FF6E0(*(char **)(self + 8) + off, 0xFFFE) != 0) {
                char *e = *(char **)(self + 8) + off;
                if (*(int *)e == 8) {
                    int j;
                    int s3 = *(int *)(e + 0x20);
                    func_001FF710(e, 0xFFFE);
                    j = *(int *)(self + 4) - 1;
                    if (j != -1) {
                        int o = j * 0x5C;
                        do {
                            if (func_001FF0D8(*(char **)(self + 8) + o, s3) != 0
                                && func_001FF6E0(*(char **)(self + 8) + o, s3) != 0
                                && func_001FF710(*(char **)(self + 8) + o, s3) != 0) {
                                *(int *)(*(char **)(self + 8) + o + 4) = 0;
                                func_001FF2E0(*(char **)(self + 8) + o, 0);
                            }
                            j = j - 1;
                            o = o - 0x5C;
                        } while (j != -1);
                    }
                }
            }
        }
    }
}
#endif

extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" unsigned int func_00276468(void *);

// DRAFT: GAME 0x23D410
#ifdef NONMATCHING
extern "C" void func_0023D410(char *self)
{
    char *o;
    char *s2;
    char *s1;
    unsigned int r;
    switch ((unsigned char)self[0x2F6]) {
    case 0:
        *(char *)(self + 0x1864) = 0;
        o = *(char **)(self + 0x304);
        s2 = (char *)(*(int *)(o + 0xC4C) + (int)o);
        s1 = (char *)(*(int *)(o + 0xC50) + (int)o);
        r = func_00276468(self);
        func_002A8578(self, (int)s2, (int)s1, 0xA, (int)(r & 0xFFFF), 0, 0.0f);
        self[0x2F6] = (char)(self[0x2F6] + 1);
        /* fallthrough */
    case 1:
        if (moveMotion__FP8cObjBase(self) != 0) {
            self[0x2F4] = 0;
            self[0x2F5] = 0x6E;
            self[0x2F6] = 0;
            self[0x2F7] = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
    if (*(unsigned short *)(self + 0x3AC) & 8) {
        *(int *)(self + 0x16D0) = *(int *)(self + 0x16D0) | 0x4000;
    }
}
#endif

// DRAFT: GAME 0x27F780
#ifdef NONMATCHING
extern "C" void func_0027F780(char *self)
{
    char *o;
    switch ((unsigned char)self[0x2F6]) {
    case 0:
        o = *(char **)(self + 0x304);
        if (self[0x2F7] != 0) {
            func_002A8578(self, (int)(*(int *)(o + 0x48) + (int)o), (int)(*(int *)(o + 0x50) + (int)o), 5, 0, 0, 0.0f);
        } else {
            func_002A8578(self, (int)(*(int *)(o + 0x48) + (int)o), (int)(*(int *)(o + 0x4C) + (int)o), 5, 0, 0, 0.0f);
        }
        self[0x2F6] = (char)(self[0x2F6] + 1);
        moveMotion__FP8cObjBase(self);
        return;
    case 2:
        o = *(char **)(self + 0x304);
        func_002A8578(self, (int)(*(int *)(o + 0x48) + (int)o), (int)(*(int *)(o + 0x58) + (int)o), 5, 0, 0, 0.0f);
        self[0x2F6] = (char)(self[0x2F6] + 1);
        moveMotion__FP8cObjBase(self);
        return;
    case 4:
        o = *(char **)(self + 0x304);
        func_002A8578(self, (int)(*(int *)(o + 0x48) + (int)o), (int)(*(int *)(o + 0x60) + (int)o), 5, 0, 0, 0.0f);
        self[0x2F6] = (char)(self[0x2F6] + 1);
        break;
    case 5:
        break;
    case 1:
    case 3:
        moveMotion__FP8cObjBase(self);
        return;
    default:
        return;
    }
    if (moveMotion__FP8cObjBase(self) != 0) {
        self[0x2F7] = 0;
        self[0x2F4] = 0;
        self[0x2F5] = 0;
        self[0x2F6] = 0;
    }
}
#endif
