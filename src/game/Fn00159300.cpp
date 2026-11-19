// Unnamed units in slice F154 (free small units: 0x159300, 0x178368, 0x179E40, 0x17E4C8, 0x377150).

#ifdef NONMATCHING
extern "C" int func_00377FF8();
extern "C" void *func_0037D170(int);
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(void *, void *, int);
extern "C" int AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(void *, void *, void *, void *, float, float);
extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);
extern "C" int move__6cOmSub(char *);
extern "C" void initMove1_ang__6cOmSub(char *, char *, int, int, float, float, float);
extern "C" void setVibration__6cOmSub(char *, int, int, float, float, float);
extern char g_DmgManage[];
extern "C" void AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, void *, void *, float);
extern "C" void *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(void *, int, void *);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void func_001C28A0(char *, char *, int, int);
extern "C" void func_001FD9D8(void *, void *, void *, void *);

// DRAFT: GAME 0x17E4C8 90 words (368 vs 400 bytes): frame 0x40 vs 0x50, saves at wrong offsets, sd ra at 0x0 vs 0x10; float-arg and local-zero variants tried, no gain.
extern "C" void func_0017E4C8(char *a0)
{
    switch (*(unsigned char *)(a0 + 0x2F5)) {
    case 0:
        if (*(char *)(a0 + 0x601) == 0) {
            *(unsigned char *)(a0 + 0x2F7) = 0;
            *(unsigned char *)(a0 + 0x2F4) = 0;
            *(unsigned char *)(a0 + 0x2F5) = 0;
            *(unsigned char *)(a0 + 0x2F6) = 0;
            return;
        }
        initMove1_ang__6cOmSub(a0 + 0x610, a0, 0, 0x5A, 0.2f, 0.0f, 1.5707964f);
        setVibration__6cOmSub(a0 + 0x610, 5, 5, 2.0f, 0.5f, 2.0f);
        *(unsigned char *)(a0 + 0x2F5) = 1;
        *(short *)(a0 + 0x602) = 7;
        *(unsigned char *)(a0 + 0x2F6) = 0;
        *(unsigned char *)(a0 + 0x2F7) = 0;
        /* fall through */
    case 1:
        if (*(short *)(a0 + 0x602) < 0) {
            *(unsigned char *)(a0 + 0x2F6) = 0;
            *(unsigned char *)(a0 + 0x2F5) = 2;
            *(unsigned char *)(a0 + 0x2F7) = 0;
        }
        *(short *)(a0 + 0x602) -= 1;
        break;
    case 2:
        if (move__6cOmSub(a0 + 0x610) == 0) {
            *(short *)(a0 + 0x602) = 0xF;
            *(unsigned char *)(a0 + 0x2F5) = 3;
            *(unsigned char *)(a0 + 0x2F7) = 0;
            *(unsigned char *)(a0 + 0x601) = 0;
            *(unsigned char *)(a0 + 0x600) = 0;
            *(unsigned char *)(a0 + 0x2F6) = 0;
            return;
        }
        break;
    case 3:
        if (*(short *)(a0 + 0x602) < 0) {
            *(unsigned char *)(a0 + 0x2F4) = 0;
            *(unsigned char *)(a0 + 0x2F5) = 0;
            *(unsigned char *)(a0 + 0x2F6) = 0;
            *(unsigned char *)(a0 + 0x2F7) = 0;
        }
        *(short *)(a0 + 0x602) -= 1;
        break;
    }
}

// DRAFT: GAME 0x179E40 95 words: frame 0xA0 vs 0x50 and missing f20 float spill; loop bounds on +0x278 approximated.
extern "C" int func_00179E40(char *a0)
{
    char *t;
    int i;
    int cnt;
    func_001B6FB8(a0);
    t = (char *)CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, a0, 2);
    *(void **)(a0 + 0x650) = t;
    if (t != 0) {
        float vec[4] = {0.0f, 0.0f, 0.0f, 1.0f};
        char mtx[0x40] = {0};
        AddDamageCollCylinder__11cDamageUnitRC7cMatrixRC4cVecT2ff(t, a0 + 0x80, mtx, vec, 1.0f, 0.6f);
    }
    *(unsigned char *)(a0 + 0x54A) = 1;
    *(unsigned char *)(a0 + 0x548) = 1;
    setMeshDispFromLayer__7cOmBaseUib(a0, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(a0, 0x40, 0);
    i = 1;
    cnt = *(unsigned short *)(a0 + 0x2B4);
    if (cnt != 1) {
        do {
            char *p = (i < cnt) ? *(char **)(a0 + 0x278 + i * 4) : 0;
            *(unsigned int *)(p + 0x154) |= 8;
            char *q = (i < cnt) ? *(char **)(a0 + 0x278 + i * 4) : 0;
            i++;
            *(unsigned int *)(q + 0x154) |= 0x10;
        } while (i < 9 && cnt != i);
    }
    return 1;
}

// DRAFT: GAME 0x377150 80 words: t2 uses t0 not t2, branch layout differs; tried store-before-call, pointer-index addressing, separate s1 (vD best).
extern "C" int func_00377150(char *a0, char *a1, int a2)
{
    int r = func_00377FF8();
    *(int *)(a0 + 0x18 + a2 * 4) = r;
    char *t2 = (char *)func_0037D170(a2 * 4);
    int *s1 = (int *)(a0 + 0x18 + a2 * 4);
    if (t2 == 0) {
        return -1;
    }
    *(unsigned short *)(t2 + 0x00) = 1;
    char *a1r = a0 + 0x70;
    unsigned v = a2 & 1;
    *(int *)(t2 + 0x04) = *s1;
    char *t0 = a0 + ((a2 >> 1) * 2);
    *(int *)(t2 + 0x08) = *(int *)(a0 + 0x04);
    *(unsigned char *)(t2 + 0x0D) = 2;
    *(unsigned char *)(t2 + 0x0C) = *(unsigned char *)(a0 + 0x0E);
    *(short *)(t2 + 0x0E) = -1;
    *(unsigned short *)(t2 + 0x10) = 0;
    *(unsigned short *)(t2 + 0x14) = a2;
    *(unsigned short *)(t2 + 0x12) = *(unsigned short *)(a0 + 0x02);
    *(unsigned short *)(t2 + 0x16) = 0;
    *(unsigned short *)(t2 + 0x18) = *(unsigned short *)(t0 + 0x60);
    *(unsigned short *)(t2 + 0x1A) = *(unsigned short *)(t0 + 0x68);
    *(short *)(t2 + 0x24) = -1;
    *(unsigned short *)(t2 + 0x1C) = *(unsigned short *)(a1r + v * 2);
    *(unsigned short *)(t2 + 0x1E) = 0;
    *(short *)(t2 + 0x20) = -1;
    *(short *)(t2 + 0x22) = -1;
    *(unsigned char *)(t2 + 0x28) = 0x7F;
    *(unsigned char *)(t2 + 0x27) = 0;
    *(unsigned char *)(t2 + 0x26) = (unsigned char)(a1[7] + a2);
    *(unsigned char *)(t2 + 0x29) = 0;
    *(unsigned short *)(t2 + 0x2A) = 0;
    if (!(*(unsigned short *)(a0 + 0x12) & 1)) {
        *(unsigned short *)(t2 + 0x2C) = 0;
    } else {
        *(unsigned short *)(t2 + 0x2C) = 1;
    }
    *(unsigned short *)(t2 + 0x2E) = 0x17;
    *(unsigned short *)(t2 + 0x30) = *(unsigned short *)(a0 + 0x5C);
    *(unsigned short *)(t2 + 0x32) = *(unsigned short *)(a0 + 0x5E);
    *(short *)(t2 + 0x3E) = -1;
    *(unsigned short *)(t2 + 0x34) = *(unsigned short *)(a1r + v * 2);
    *(unsigned char *)(t2 + 0x42) = 0;
    *(unsigned short *)(t2 + 0x36) = 0;
    *(unsigned short *)(t2 + 0x38) = 0;
    *(unsigned short *)(t2 + 0x3A) = 0;
    *(unsigned short *)(t2 + 0x3C) = 0;
    *(unsigned char *)(t2 + 0x41) = 0;
    *(unsigned char *)(t2 + 0x40) = 0;
    *(unsigned char *)(t2 + 0x43) = 0;
    return 0;
}

// DRAFT: GAME 0x178368 97 words (380 vs 396 bytes): first m2c-based draft; frame and register roles differ, float constants and the +0x46/+0x4C field widths unverified.
extern "C" int func_00178368(char *a0)
{
    float vec1[4] = {0.6f, 0.0f, 0.0f, 1.0f};
    float vec2[4] = {0.0f, 0.0f, 0.0f, 0.0f};
    float vec3[4] = {0.0f, 0.0f, 0.0f, 1.0f};
    void *t;
    void *g;
    char *a1r;

    func_001B6FB8(a0);
    t = CreateDamageTake__13cDamageManageP8cGameObj8DMG_KIND(g_DmgManage, a0, 2);
    *(void **)(a0 + 0x600) = t;
    if (t != 0) {
        func_001FD9D8(t, a0 + 0x80, vec2, vec3);
    }
    g = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 0, a0);
    *(void **)(a0 + 0x604) = g;
    if (g != 0) {
        AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(g, a0 + 0x80, vec3, 1.0f);
        *(unsigned short *)(*(char **)(a0 + 0x604) + 0x46) = 0x2E;
        *(int *)(*(char **)(a0 + 0x604) + 0x4C) = 0;
        SetDamageCollActive__11cDamageUnitb(g, 0);
    }
    a1r = a0 + 0x620;
    *(int *)(a0 + 0x5E8) = 0;
    *(int *)(a0 + 0x5E4) = 0;
    *(int *)(a0 + 0x5F0) = 0;
    *(short *)(a0 + 0x5F6) = 0;
    *(unsigned char *)(a0 + 0x54A) = 1;
    *(char **)(a0 + 0x608) = a1r;
    *(int *)(a0 + 0x60C) = 6;
    *(int *)(a0 + 0x5EC) = 7;
    *(unsigned char *)(a0 + 0x548) = 1;
    *(int *)(a0 + 0x5F4) = -1;
    func_001C28A0(a0, a1r, 6, 7);
    return 1;
}

// DRAFT: GAME 0x159300 99 words (304 vs 400 bytes): Hermite lookup over 0x10-byte keys from m2c; the original is 96 bytes larger, so the loop and the sentinel/no-key paths are missing or wrong.
extern "C" float func_00159300(char *a0, char *a1, float fa)
{
    int n = *(unsigned short *)(a1 + 2);
    char *base = a0 + *(int *)(a1 + 8);
    int i = 0;
    if (n == 0) {
        return *(float *)(base - 0xC);
    }
    while (i < n) {
        float key = *(float *)(base + i * 0x10);
        if (key == fa) {
            return *(float *)(base + i * 0x10 + 4);
        }
        if (key > fa) {
            break;
        }
        i++;
    }
    if (i >= n) {
        return *(float *)(base + (n - 1) * 0x10 + 4);
    }
    char *r0 = base + (i - 1) * 0x10;
    char *r1 = base + i * 0x10;
    float t = (fa - *(float *)r0) / (*(float *)r1 - *(float *)r0);
    float t1 = t * t;
    float t2 = t1 * t;
    float h00 = 2.0f * t2 - 3.0f * t1 + 1.0f;
    float h01 = 3.0f * t1 - 2.0f * t2;
    float h10 = t2 - 2.0f * t1 + t;
    float h11 = t2 - t1;
    return h00 * *(float *)(r0 + 4) + h01 * *(float *)(r1 + 4) + h10 * *(float *)(r0 + 0xC) + h11 * *(float *)(r1 + 8);
}
#endif
