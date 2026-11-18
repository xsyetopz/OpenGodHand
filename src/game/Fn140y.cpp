// Medium functions from 0x140000-0x160000.

extern int D_0041EA80;
extern "C" void *memset(void *, int, unsigned);
extern "C" int func_00152340(char *, long);

// FUNCTION: GAME 0x149AD8
extern "C" int setTextureExchange__6cModelPCUiPCvi(char *m, char *a, char *h, int k)
{
    if (!a || !h) return 0;
    if (*(int *)h != D_0041EA80) return 0;
    if (k >= *(unsigned short *)(h + 4)) return 0;
    {
        char *t = h + 8;
        char *e = m + 0x2D4;
        unsigned char *p = (unsigned char *)(t + *(unsigned short *)(h + 6) * 8);
        int n;
        if (k > 0) {
            do {
                k--;
                p += *p * 2 + 1;
            } while (k);
        }
        memset(e, 0xFF, 0x10);
        unsigned char c = *p++;
        if (c) {
            n = c;
            do {
                int r = func_00152340(a, *(long *)(t + p[1] * 8));
                if (r != -1) e[r] = p[0];
                p += 2;
            } while (--n);
        }
        return 1;
    }
}

extern "C" int func_0031ED08(float);
extern "C" int setMotionInfo__FP8cObjBaseUiUiUiffUs(char *, int, int, int, float, float, unsigned short);
extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(char *, float);
extern "C" void addNullSpeed__8cObjBasef(char *, float);

// FUNCTION: GAME 0x14ED60
extern "C" void func_0014ED60(char *s)
{
    switch ((unsigned char)s[0x2F6]) {
    case 0:
        setMotionInfo__FP8cObjBaseUiUiUiffUs(s, *(int *)(s + 0x428), *(int *)(s + 0x42C), func_0031ED08(*(float *)(s + 0x438)), *(float *)(s + 0x440), *(float *)(s + 0x430), *(unsigned short *)(s + 0x434));
        s[0x2F6] = (unsigned char)s[0x2F6] + 1;
    case 1:
        if (moveMotion__FP8cObjBase(s)) s[0x2F6]++;
        addNullSpeed_Rotation__8cObjBasef(s, 1.0f);
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    case 2:
        moveMotion__FP8cObjBase(s);
        addNullSpeed_Rotation__8cObjBasef(s, 1.0f);
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    }
}

extern "C" void MtxInitCoord__FR7cMatrixRC4cVecN21Uc(char *, char *, char *, char *, unsigned char);
extern "C" void Adjust_theta_vec__FPf(float *);
extern "C" void MtxInitTransVec__FR7cMatrixRC4cVec(char *, char *);
extern "C" void MtxMulRotVec__FR7cMatrixRC7cMatrixRC4cVecUc(char *, char *, float *, unsigned char);
extern "C" void MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(char *, char *, char *);
extern "C" void MtxMultiply__FR7cMatrixRC7cMatrixT1(char *, char *, char *);

// FUNCTION: GAME 0x14A170
extern "C" void func_0014A170(char *s)
{
    int i;
    char *p;
    if (!(*(unsigned *)(s + 0x250) & 0x800))
        MtxInitCoord__FR7cMatrixRC4cVecN21Uc(s + 0x80, *(char **)(s + 0xF0), s + 0x100, s + 0x110, (unsigned char)s[0x140]);
    i = 0;
    p = *(char **)(s + 0x144);
    if (*(unsigned char *)(s + 0x2B4)) {
        do {
            float v[4];
            Adjust_theta_vec__FPf((float *)(p + 0x100));
            float x = *(float *)(p + 0x100) + *(float *)(p + 0x130);
            float y = *(float *)(p + 0x104) + *(float *)(p + 0x134);
            float z = *(float *)(p + 0x108) + *(float *)(p + 0x138);
            v[0] = x;
            v[3] = 1.0f;
            v[1] = y;
            v[2] = z;
            Adjust_theta_vec__FPf(v);
            unsigned long f1 = *(int *)(p + 0x154);
            if (((f1 >> 3) & 1) == 0) {
                MtxInitTransVec__FR7cMatrixRC4cVec(p, *(char **)(p + 0xD0));
                MtxMulRotVec__FR7cMatrixRC7cMatrixRC4cVecUc(p, p, v, 0);
                MtxMulScaleVec__FR7cMatrixRC7cMatrixRC4cVec(p, p, p + 0x110);
            }
            unsigned long f2 = *(int *)(p + 0x154);
            if (((f2 >> 4) & 1) == 0)
                MtxMultiply__FR7cMatrixRC7cMatrixT1(p + 0x80, *(char **)(p + 0x148) + 0x80, p);
            i++;
            p = *(char **)(p + 0x144);
        } while (i < *(unsigned char *)(s + 0x2B4));
    }
}

extern char **IDSys;
extern char D_0041F1F0[];
extern "C" void func_001615D0(char *);
extern "C" int func_00161500(char *, char *);
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *, int, unsigned *);
extern "C" void initialize__7cIDBase7eIdData5eIdNo(char *, int, int);
extern "C" void resetAnim__7cIDBase(char *);
extern "C" char *getIDWork__7cIDBasei(char *, int);

// FUNCTION: GAME 0x1616A8
extern "C" void func_001616A8(char *s)
{
    unsigned short i;
    char **p;
    func_001615D0(s);
    if (func_00161500(s, D_0041F1F0)) {
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 9, *(unsigned **)(s + 0x50));
        initialize__7cIDBase7eIdData5eIdNo(s, 9, 0);
        resetAnim__7cIDBase(s);
        s[0x1C] = 1;
        *(int *)(s + 0x60) = 6;
        s[0x5A] = 0;
        s[0x5B] = 0;
        s[0x5C] = 0;
        s[0x5D] = 0;
    }
    i = 0;
    p = (char **)(s + 0x80);
    do {
        *(char **)((char *)p + (i << 2)) = getIDWork__7cIDBasei(s, i);
        i = i + 1;
    } while (i < 0xF);
    s[0xBC] = 0;
}

extern char D_0041F378[];
extern "C" int setPackedMessData__7cIDBase7eIdData5eIdNo(char *, int, int);

// FUNCTION: GAME 0x161BD0
extern "C" void func_00161BD0(char *s)
{
    unsigned short i;
    char **p;
    func_001615D0(s);
    if (func_00161500(s, D_0041F378)) {
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 6, *(unsigned **)(s + 0x50));
        initialize__7cIDBase7eIdData5eIdNo(s, 6, 0);
        resetAnim__7cIDBase(s);
        s[0x1C] = 1;
        setPackedMessData__7cIDBase7eIdData5eIdNo(s, 6, 1);
        s[0x5A] = 0;
        s[0x5B] = 0;
        *(int *)(s + 0x60) = 2;
        s[0x5C] = 0;
        s[0x5D] = 0;
    }
    i = 0;
    p = (char **)(s + 0x80);
    do {
        *(char **)((char *)p + (i << 2)) = getIDWork__7cIDBasei(s, i);
        i = i + 1;
    } while (i < 0x1B);
    s[0xEC] = 0;
    s[0xED] = 0;
    s[0xEE] = 0;
    s[0xEF] = 0;
}

extern char D_0041FC50[];
extern "C" void restartAnim__7cIDBase(char *);

// FUNCTION: GAME 0x167FA8
extern "C" void func_00167FA8(char *s)
{
    int i;
    char **p;
    func_001615D0(s);
    if (func_00161500(s, D_0041FC50)) {
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 0x16, *(unsigned **)(s + 0x50));
        initialize__7cIDBase7eIdData5eIdNo(s, 0x16, 0);
        restartAnim__7cIDBase(s);
        *(int *)(s + 0x60) = 8;
    }
    i = 0;
    p = (char **)(s + 0x80);
    do {
        *p = getIDWork__7cIDBasei(s, i);
        i = i + 1;
        p = p + 1;
    } while (i < 4);
    if ((unsigned char)s[0x64] == 1) {
        s[0x5A] = 1;
        *(unsigned *)(*(char **)(s + 0x8C) + 0x2C) &= 0xF7FFFFFF;
        s[0x91] = 0;
    } else {
        s[0x91] = 0;
    }
}
