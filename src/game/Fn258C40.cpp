extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
extern "C" int func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" void func_001038E0(void *, void *, void *, void *, float, float);
extern int D_003C0138;
extern int D_003C01B0;
extern int D_003C01D8;
extern int D_003C0160;
extern int D_003C0188;
extern int D_003C0200;
extern int D_003C02A0;
extern int D_003C0340;
extern int D_00585720;

// DRAFT: GAME 0x258C40 - 74 words (232 vs 320 bytes), first draft; original has a branch tree the plain switch drops
#ifdef NONMATCHING
extern "C" void func_00258C40(char *self)
{
    *(unsigned int *)(self + 0x16D0) |= 0x4000;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *t = *(char **)(self + 0x304);
        int a = *(int *)(t + 0xC4C) + (int)t;
        int b = *(int *)(t + 0xC50) + (int)t;
        int m = func_00276468(self);
        func_002A8578(self, a, b, 10, m & 0xFFFF, 0, 0.0f);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    /* fallthrough */
    case 1:
        if (moveMotion__FP8cObjBase(self) != 0) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0x6E;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
        addNullSpeed_Rotation__8cObjBasef(self, 1.0f);
        addNullSpeed__8cObjBasef(self, 1.0f);
        break;
    }
}
#endif

// DRAFT: GAME 0x284350 - unscored first draft: store block, zeroed tmp, conditional copy, func_001038E0 call; Tried: plain C stores
#ifdef NONMATCHING
extern "C" void func_00284350(char *self)
{
    float tmp[4];
    *(int *)(self + 0x2130) = 40;
    *(void **)(self + 0x2134) = (void *)&D_003C0138;
    *(void **)(self + 0x2138) = (void *)&D_003C01B0;
    *(void **)(self + 0x213C) = (void *)&D_003C01D8;
    *(int *)(self + 0x2140) = 0;
    *(int *)(self + 0x2144) = 0;
    *(void **)(self + 0x2148) = (void *)&D_003C0160;
    *(void **)(self + 0x214C) = (void *)&D_003C0188;
    *(int *)(self + 0x2150) = 0;
    *(int *)(self + 0x2154) = 0;
    *(void **)(self + 0x2158) = (void *)&D_003C0200;
    *(void **)(self + 0x215C) = (void *)&D_003C02A0;
    *(void **)(self + 0x2160) = (void *)&D_003C0340;
    *(void **)(self + 0x2164) = (void *)&D_00585720;
    *(int *)(self + 0x2168) = 0;
    *(float *)(self + 0x216C) = 0.015f;
    *(float *)(self + 0x2170) = 0.8f;
    *(int *)(self + 0x2174) = 1;
    *(float *)(self + 0x217C) = 0.8f;
    *(float *)(self + 0x2180) = 0.5f;
    *(int *)(self + 0x2184) = 0;
    *(int *)(self + 0x2188) = 0;
    *(int *)(self + 0x218C) = 0x100;
    *(int *)(self + 0x2178) = 0;
    tmp[3] = 1.0f;
    tmp[0] = 0.0f;
    tmp[1] = 0.0f;
    tmp[2] = 0.0f;
    if ((char *)(self + 0x2190) != (char *)tmp) {
        *(float *)(self + 0x2190) = *(float *)(self + 0x2178);
        *(float *)(self + 0x2194) = *(float *)(self + 0x2178);
        *(float *)(self + 0x2198) = tmp[2];
    }
    *(float *)(self + 0x21A0) = 1.0479f;
    func_001038E0(self, self + 0x2130, self + 0x5B0, (void *)&D_003C0160, 0.1f, 0.0f);
}
#endif
