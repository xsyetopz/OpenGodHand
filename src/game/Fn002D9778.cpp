// Callees used by this slice. Declarations stay local to this file.
extern "C" void func_002D9458(char *, char *);
extern "C" void Set_LightData__11cWorldLightP14LIGHT_DATA_TBL(void *, void *, int, void *);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void *Getplayer__Fv();
extern "C" int func_0010B698(void *);
extern "C" int CkPlCatched__9cEmManage(void *);
extern "C" int func_002C2B58(void *, int, void *, void *);
extern "C" float Turn_dest_dir__Ffff(float, float, float);
extern "C" void set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(void *, int, int, int, void *, int, int);
extern "C" void func_002DCA58();
extern "C" void MtxInitRotY__FR7cMatrixf(float *, float);
extern "C" void sceVu0ApplyMatrix(float *, const float *, const float *);
extern "C" void func_00104010(void *, void *, void *);
extern "C" int func_00306C78(void *, int, void *, void *);
extern "C" void *CreateObj__F6eObjIdT0(int, int);
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(void *, void *, unsigned int, int, int);
extern "C" void func_002D9F68(void *, void *);
extern "C" void ReleaseObj__FP4cObj(void *);
void *SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
extern char g_EmManage[];
extern char g_SceAt[];
extern char g_ActBtn[];
extern int D_00741DC8;
extern int D_0044F110;
extern int D_0044F130;

struct Qv { float f[4]; };
// Stores vf0 (0,0,0,1) as a quadword, as the VU0 zero-init does in the original.
static inline void sqc2_vf0(void *p) { __asm__ volatile("sqc2 $vf0,%0" : "=m"(*(Qv *)p)); }
static inline float bitsf(unsigned int u) { union { unsigned int u; float f; } x; x.u = u; return x.f; }

#ifdef NONMATCHING
// DRAFT: GAME 0x2D9778 - 48 words; frame 0x90 vs 0x80, ra at 0x70 vs 0x60, fr store order differs; tried dropping int i58 with char-offset store (still 48)
extern "C" void func_002D9778(char *self) {
    struct Lt {
        short s0;
        short s1;
        int i4;
        int i8;
        int i0c;
        float f10;
        float f14;
        float f18;
        float f1c;
        float v20[4];
        float v30[4];
        float f40;
        int i44;
        int i48;
        int i4c;
        int i50;
        int i54;
        int i58;
    } t;
    func_002D9458(self + 0xE8A0, self);
    *(int *)(self + 0x78) = 0;
    memset(self + 0x80, 0, 0x7000);
    {
        short *p = (short *)(self + 0x7010);
        int n = 0xFF;
        do {
            *p = 0xFF;
            n--;
            p = (short *)((char *)p - 0x70);
        } while (n >= 0);
    }
    *(float *)(self + 0x40) = 0.45f;
    *(float *)(self + 0x48) = 0.45f;
    *(float *)(self + 0x44) = 0.45f;
    sqc2_vf0(&t.f10);
    sqc2_vf0(t.v20);
    sqc2_vf0(t.v30);
    t.s1 = 1;
    t.i54 = 0;
    t.i4 = 0;
    t.s0 = 1;
    *(int *)&t.f10 = 0;
    t.f14 = 0.4f;
    t.f18 = 3.5f;
    t.f1c = 1.0f;
    t.v30[0] = 0.5f;
    t.v30[1] = 0.5f;
    t.v30[2] = 0.5f;
    t.v30[3] = 1.0f;
    t.f40 = bitsf(0x3C23D70A);
    t.i44 = 0;
    t.i48 = 0;
    t.i4c = 0;
    t.i50 = 1;
    t.i58 = (int)0x87000000u;
    Set_LightData__11cWorldLightP14LIGHT_DATA_TBL(self, &t, 1, &t.f10);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2DC920 - 64 words; EmManage address folding and branch layout differ; tried caching g_EmManage+0x514 in a char* and passing em-0x514 to CkPlCatched (77, worse)
extern "C" void SetActionJumpUp__Fv() {
    float v[4];
    float dir;
    char *p = (char *)Getplayer__Fv();
    sqc2_vf0(v);
    if (*(short *)(p + 0x54A) > 0 && func_0010B698(p) == 0 && *(int *)(g_EmManage + 0x514) <= 0 &&
        CkPlCatched__9cEmManage(g_EmManage) == 0 &&
        func_002C2B58(g_SceAt, *(int *)(p + 0xF0), v, &dir) != 0) {
        float r = Turn_dest_dir__Ffff(*(float *)(p + 0x104), dir, bitsf(0x40490FDB));
        float a = r;
        if (r < 0.0f) {
            a = -r;
        }
        if (!(bitsf(0x3FA78D36) < a)) {
            float *q = (float *)(p + 0x660);
            if (q != v) {
                q[0] = v[0];
                q[1] = v[1];
                q[2] = v[2];
            }
            *(float *)(p + 0x670) = dir;
            set__13cActionButton12eScePriority8eActType11eActBtnTypePvT48eActFunc(g_ActBtn, 4, 8, 0, (void *)func_002DCA58, 0, 0);
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2DF860 - 47 words; frame 0xA0 vs 0x90 and pen/obj register swap; tried nested range check (56) and null-check reorder (47)
extern "C" void EmClothMove__F6eObjIdP4cObjP8PEN_INFOP10CLOTH_INFO(int id, char *obj, void *flag, char *pen) {
    float m[16];
    float v[4];
    if (obj == 0) return;
    if (flag == 0) return;
    if (pen == 0) return;
    sqc2_vf0(v);
    if (id >= 0x270 && id < 0x275) {
        MtxInitRotY__FR7cMatrixf(m, *(float *)(obj + 0x104));
        v[0] = bitsf(0x3CA3D70A);
        v[1] = bitsf(0x3CA3D70A);
        v[2] = bitsf(0xBCA3D70A);
        sceVu0ApplyMatrix(v, m, v);
        float *d = (float *)(pen + 0x60);
        if (d != v) {
            d[0] = v[0];
            d[1] = v[1];
            d[2] = v[2];
        }
    }
    func_00104010(obj, pen, flag);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2F4290 - 41 words; t2 register ($v1 vs $t2), epilogue branch offsets, fr-block store order; tried goto head (41), shared return tail (41), unsigned int temp (41)
extern "C" int func_002F4290(char *self) {
    int o80, o84;
    char fr[0x80];
    unsigned char t2;
    void *obj;
    if (func_00306C78((void *)&D_00741DC8, *(int *)(self + 0x2B4), &o80, &o84) == 0) goto L42D0;
    obj = CreateObj__F6eObjIdT0(0x500, 0xFFFF);
    *(void **)(self + 0x2B0) = obj;
    if (obj != 0) goto L42E8;
L42D0:
    func_002D9F68(self, (void *)&D_0044F110);
    return 0;
L42E8:
    if (setupModel__6cModelPC10SCR_HEADERUibT3(obj, (void *)o80, (unsigned int)o84, 0, 0) != 0) goto L4328;
    func_002D9F68(self, (void *)&D_0044F130);
    ReleaseObj__FP4cObj(*(void **)(self + 0x2B0));
    return 0;
L4328:
    t2 = *(unsigned char *)(self + 0x2DC);
    if (t2 != 0) {
    *(float *)(fr + 0x00) = 1.0f;
    *(float *)(fr + 0x04) = 1.0f;
    *(float *)(fr + 0x08) = 1.0f;
    *(float *)(fr + 0x0C) = 1.0f;
    sqc2_vf0(fr + 0x10);
    sqc2_vf0(fr + 0x20);
    *(float *)(fr + 0x30) = 1.0f;
    *(float *)(fr + 0x3C) = 1.0f;
    *(float *)(fr + 0x34) = 1.0f;
    *(float *)(fr + 0x38) = 1.0f;
    *(float *)(fr + 0x40) = 1.0f;
    fr[0x4C] = -1;
    fr[0x4F] = -1;
    *(int *)(fr + 0x44) = 0;
    *(int *)(fr + 0x48) = 0;
    fr[0x4D] = 0;
    fr[0x4E] = 0;
    *(int *)(fr + 0x50) = 0;
    sqc2_vf0(fr + 0x60);
    *(int *)(fr + 0x48) = *(int *)(self + 0x104);
    fr[0x74] = (char)t2;
    *(float *)(fr + 0x40) = *(float *)(self + 0x2E0);
    *(short *)(fr + 0x70) = 0;
    *(short *)(fr + 0x72) = 0;
    *(int *)(fr + 0x78) = 0;
    SetEffect(*(short *)(self + 0x23A), *(unsigned short *)(self + 0x23C), *(void **)(self + 0x2B0), fr, -1, 0xFFFFFFFFu);
    }
    return 1;
}
#endif
