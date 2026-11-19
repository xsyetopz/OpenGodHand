extern "C" {
int func_001B6FB8(char *);
void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, char *, int);
void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, char *, float *, float);
void setMeshDispFromLayer__7cOmBaseUib(char *, int, int);
float Adjust_theta__Ff(int, float);
void func_0037D148(char *);
void func_0037D3B0(char *);
void func_002E0DE8(int, int, int, char *);
}
extern char g_DmgManage[];
extern char D_0076B1C0[];
extern char D_0076CF20[];
extern char D_0045C1B8[];
extern char D_0045C1C8[];
extern volatile int D_003F2888[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1790B0 57 words differ, 328 vs 368 bytes; loop tail and branch-likely form differ. Tried ternary loop form (58 words).
extern "C" int func_001790B0(char *self) {
    float vec[4];
    func_001B6FB8(self);
    float half = 0.5f;
    float one = 1.0f;
    vec[0] = 0.0f;
    vec[3] = one;
    vec[1] = half;
    vec[2] = 0.0f;
    void *d = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, self, 2);
    *(void **)(self + 0x650) = d;
    if (d)
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(d, self + 0x80, vec, half);
    *(short *)(self + 0x54A) = 1;
    *(short *)(self + 0x548) = 1;
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    if (*(unsigned char *)(self + 0x2B4) != 1) {
        int i = 1;
        int t = 0;
        int k = 1;
        do {
            char *p = 0;
            if (!(k < t) && i < *(unsigned char *)(self + 0x2B4))
                p = ((char **)*(char ***)(self + 0x278))[i];
            *(int *)(p + 0x154) |= 8;
            char *q = 0;
            if (!(k < t) && i < *(unsigned char *)(self + 0x2B4))
                q = ((char **)*(char ***)(self + 0x278))[i];
            *(int *)(q + 0x154) |= 0x10;
            i++;
            k++;
            if (i >= 6)
                break;
        } while (*(unsigned char *)(self + 0x2B4) != i);
    }
    return 1;
}

// DRAFT: GAME 0x1BCFB0 86 words differ, 48 bytes short; required branches missing in the flag and kind paths.
extern "C" void setOpen__7cOmDoor13eDoorOpenKindb(char *self, int kind, int flag) {
    unsigned int st = *(unsigned int *)(self + 0x620);
    if ((st & 1) == 1)
        return;
    if (((st >> 1) & 1) == 1)
        return;
    if (!(((unsigned char)self[0x2F4]) < 2))
        return;
    *(float *)(self + 0x638) = *(float *)(self + 0x104);
    if (kind == 1) {
        int v = *(unsigned short *)(self + 0x2FE);
        float ang = (v == 0x354 || v == 0x314 || v == 0x420) ? 1.5707964f : 1.7453293f;
        *(float *)(self + 0x640) = Adjust_theta__Ff(1, *(float *)(self + 0x104) + ang);
    } else if (kind == 0) {
        int v = *(unsigned short *)(self + 0x2FE);
        float ang = (v == 0x354 || v == 0x314 || v == 0x420) ? 1.5707964f : 1.7453293f;
        *(float *)(self + 0x640) = Adjust_theta__Ff(1, *(float *)(self + 0x104) - ang);
    }
    *(unsigned int *)(self + 0x620) = *(unsigned int *)(self + 0x620) | 1;
    if (flag == 0) {
        self[0x2F7] = 0;
        self[0x2F5] = 1;
        self[0x2F4] = 0;
        self[0x2F6] = 0;
        return;
    }
    *(float *)(self + 0x104) = *(float *)(self + 0x640);
}

// DRAFT: GAME 0x37C930 79 words differ, 12 bytes large; tail loop and branch-likely form differ.
extern "C" void func_0037C930(void) {
    char *s0 = D_0076CF20;
    char *s1 = D_0076B1C0;
    int s2 = 0;
    do {
        unsigned short a = *(unsigned short *)s0;
        if (a != 0 && *(int *)(s1 + 4) == *(int *)(s0 + 0x10)) {
            unsigned short b = *(unsigned short *)s1;
            if (b & 0x8000) {
                if (!(a & 0x8000))
                    *(unsigned short *)s0 = a | 0x8000;
            } else {
                if (a & 0x8000)
                    *(unsigned short *)s0 = a & 0x7FFF;
                if (b & 2) {
                    unsigned short c = *(unsigned short *)s0;
                    if (!(c & 2))
                        *(unsigned short *)s0 = c | 2;
                    if (!(b & 0x80)) {
                        *(int *)(s0 + 0xC) = *(int *)(s0 + 0xC) + 1;
                    } else {
                        func_0037D148(s0);
                        func_0037D3B0(s0);
                    }
                } else if (b & 0x10) {
                    func_0037D148(s0);
                    func_0037D3B0(s0);
                }
            }
        }
        s2++;
        s0 += 0x50;
        s1 += 8;
    } while (s2 < 0x30);
    char *v1 = D_0076CF20 + s2 * 0x50;
    unsigned short a0 = *(unsigned short *)v1;
    while (v1 < D_0076CF20 + 0xFF0) {
        if (a0 != 0) {
            if (!(a0 & 2))
                *(unsigned short *)v1 = a0 | 2;
            *(int *)(v1 + 0xC) = *(int *)(v1 + 0xC) + 1;
        }
        v1 += 0x50;
        if (v1 < D_0076CF20 + 0xFF0)
            a0 = *(unsigned short *)v1;
    }
}

// DRAFT: GAME 0x37E200 90 words differ; dead read of D_003F2888 and volatile qualifier unresolved.
extern "C" int func_0037E200(unsigned char *self, char *arg1) {
    if (*(int *)(arg1 + 0x34) & 0x40)
        return 0;
    if (*(int *)(arg1 + 0x38) & 0x1000) {
        unsigned char v = self[1];
        self[1] = v ? v - 1 : 4;
    }
    if (*(int *)(arg1 + 0x38) & 0x4000) {
        unsigned char v = self[1];
        if (v < 4)
            self[1] = v + 1;
        else
            self[1] = 0;
    }
    if (*(int *)(arg1 + 0x34) & 0x20) {
        self[5] = 0;
        self[4] = 0;
        self[0] = (unsigned char)(self[1] + 1);
        return 1;
    }
    func_002E0DE8(0x15, 3, 0xD, D_0045C1B8);
    int i = 0;
    int s1 = 0x50000;
    do {
        (void)D_003F2888[i];
        func_002E0DE8(0x14, s1 >> 16, ((i ^ self[1]) == 0) ? 0xE : 8, D_0045C1C8);
        s1 += 0x10000;
        i++;
    } while (i < 5);
    return 1;
}
#endif
