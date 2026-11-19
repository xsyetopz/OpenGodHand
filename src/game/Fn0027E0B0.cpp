// God Hand: units of slice F149 (0x27E0B0, 0x28E858, 0x298A78, 0x299A28, 0x2AC048).
extern "C" int setMeshDisplay__6cModelPCcb(void *, char *, int);
extern "C" float func_002AC650(int, short, short, int);
extern "C" int func_002AC6E0(int, void *, float *, void *, float);
extern "C" int func_002AC878(int, void *, float *, void *, float);
extern "C" float GetSpeedRate__9cEmManage(void *, float);
extern "C" void *Getplayer__Fv(void);
extern "C" void InverseKinematics__2IKP8cObjBase(void *, void *);
extern "C" void ScrollTexture__6cModelf(void *, float);
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" void SetMotionStep__FP8cObjBasef(void *, float);
extern "C" void SetSeqEffect__8cObjBase(void *);
extern "C" void calcParts__6cModel(void *);
extern "C" void calcWorldParts__6cModel(void *);
extern "C" float capVu0MagnitudeSqXZ__FPCfT0(int, void *);
extern "C" void func_0027E228(void *);
extern "C" void func_0027E950(void *);
extern "C" void func_0027EDF0(void *);
extern int D_00747A78;
extern char g_CollSolidManage[];
extern char g_EmManage[];
extern char D_0044ABB0[];
extern char D_0044ABB8[];

// FUNCTION: GAME 0x298A78
extern "C" void func_00298A78(void *self, int unused, int arg2, float fparg0) {
    if (self != 0) {
        unsigned short id = *(unsigned short *)((char *)self + 0x2FE);
        switch (id) {
        case 0x625:
            setMeshDisplay__6cModelPCcb(self, D_0044ABB0, 1);
            setMeshDisplay__6cModelPCcb(self, D_0044ABB8, 0);
            if ((unsigned)(arg2 - 6) < 3U && (arg2 != 8 || !(fparg0 >= 17.0f))) {
                setMeshDisplay__6cModelPCcb(self, D_0044ABB0, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044ABB8, 1);
                return;
            }
            break;
        case 0x627:
            setMeshDisplay__6cModelPCcb(self, D_0044ABB0, 1);
            setMeshDisplay__6cModelPCcb(self, D_0044ABB8, 0);
            if ((unsigned)(arg2 - 6) < 3U && (arg2 != 8 || !(fparg0 >= 17.0f))) {
                setMeshDisplay__6cModelPCcb(self, D_0044ABB0, 0);
                setMeshDisplay__6cModelPCcb(self, D_0044ABB8, 1);
            }
            break;
        }
    }
}

// DRAFT: GAME 0x27E0B0
#ifdef NONMATCHING
extern char D_003BFE70[];

extern "C" void func_0027E0B0(char *arg0) {
    if (!(D_00747A78 & 0x40000000)) {
        float speed = GetSpeedRate__9cEmManage(g_EmManage, 2.0f);
        *(float *)(arg0 + 0x5A8) = speed;
        SetMotionStep__FP8cObjBasef(arg0, speed);
        *(float *)(arg0 + 0x618) = capVu0MagnitudeSqXZ__FPCfT0(*(int *)((char *)Getplayer__Fv() + 0xF0), *(void **)(arg0 + 0xF0));
        func_0027E228(arg0);
        ScrollTexture__6cModelf(arg0, *(float *)(arg0 + 0x5A8));
        char *e = D_003BFE70 + (unsigned char)arg0[0x2F4] * 8;
        short b = *(short *)(e + 2);
        long fnv;
        int off;
        if (b >= 0) {
            char *tbl = *(char **)(arg0 + *(short *)(e + 4));
            char *ent = tbl + b * 8 - 8;
            fnv = *(int *)(ent + 4);
            off = *(short *)ent + *(short *)e;
        } else {
            fnv = *(int *)(e + 4);
            off = *(short *)e;
        }
        ((void (*)(char *, short, long, long))fnv)(arg0 + off, b, fnv, 0x3C0000L);
        SetSeqEffect__8cObjBase(arg0);
        func_0027E950(arg0);
        calcParts__6cModel(arg0);
        InverseKinematics__2IKP8cObjBase(arg0 + 0x448, arg0);
        calcWorldParts__6cModel(arg0);
        func_0027EDF0(arg0);
        SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, arg0, 0);
        char *src = *(char **)(arg0 + 0xF0);
        char *dst = arg0 + 0x490;
        if (dst != src) {
            *(float *)(arg0 + 0x490) = *(float *)(src + 0);
            *(float *)(arg0 + 0x494) = *(float *)(src + 4);
            *(float *)(arg0 + 0x498) = *(float *)(src + 8);
        }
    }
}
#endif

// DRAFT: GAME 0x2AC048
#ifdef NONMATCHING
extern "C" void func_002AC048(int arg0, char *arg1) {
    char *s1 = *(char **)(arg1 + 0x1C);
    int a1 = *(int *)(s1 + 4);
    int a3 = *(int *)(arg1 + 0x2C);
    if ((a1 & 0x01000000) && (a3 & 0x2000) == 0 && s1[0x5D] == 0) {
        short a2 = *(short *)(s1 + 0x6C);
        int idx = a2 - 1;
        short a0 = *(short *)(s1 + idx * 12 + 0x78);
        if (!(a1 & 0x80000)) {
            if (a0 < (int)*(unsigned short *)(arg1 + 0xA2)) {
                *(int *)(arg1 + 0x2C) = a3 | 0x2000;
                return;
            }
        } else if (a0 < (int)*(unsigned short *)(arg1 + 0xA2)) {
            *(unsigned short *)(arg1 + 0xA2) = 0;
        }
        float f0 = func_002AC650(arg0, (short)*(unsigned short *)(arg1 + 0xA2), a2, *(int *)(arg1 + 4));
        unsigned char kind = s1[0x67];
        float sp0;
        float sp4;
        int ok = 0;
        if (kind == 1) {
            ok = func_002AC878(arg0, &sp0, &sp4, arg1, f0);
        } else if (kind == 0) {
            ok = func_002AC6E0(arg0, &sp0, &sp4, arg1, f0);
        }
        if (ok != 0) {
            s1 = *(char **)(arg1 + 0x1C);
            *(float *)(arg1 + 0x38) = (float)(*(int *)(s1 + 8) + (sp0 - 256.0f));
            *(float *)(arg1 + 0x3C) = (float)(*(int *)(s1 + 0xC) + (sp4 - 224.0f));
        }
        if (!((*(unsigned int *)(arg1 + 0x2C) >> 5) & 1)) {
            *(unsigned short *)(arg1 + 0xA2) = (unsigned short)(*(unsigned short *)(arg1 + 0xA2) + 1);
        }
    }
}
#endif

// DRAFT: GAME 0x28E858
#ifdef NONMATCHING
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *);
extern "C" void SeFadeOut__4cSnd6eSndIds(void *, int, int);
extern "C" void endSoftEvent__9cScenario(void *);
extern "C" void execUpCut__9cScenarioUsPCcbUci(void *, int, int, int);
extern "C" void exit__9cTaskWork(int);
extern "C" void func_002C45A8(void *, int, void *, int, float, float);
extern "C" void sleep__9cTaskWorkUs(int, int);
extern "C" void start__9classFADEUiUiUiUiUiUi(void *, int, int, int);
extern char Snd[];
extern char Fade[];
extern void *Message;
extern void *g_Sce;

extern "C" void func_0028E858(char *arg0) {
    char *v1 = *(char **)(arg0 + 0x214);
    (*(void (**)(char *, int))(v1 + 0x64))(arg0 + *(int *)(v1 + 0x60), 0);
    char *p = (char *)Getplayer__Fv();
    char *v = *(char **)(p + 0x214);
    (*(void (**)(char *, int))(v + 0x64))(p + *(int *)(v + 0x60), 0);
    int s1 = SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, 0, arg0);
    execUpCut__9cScenarioUsPCcbUci(g_Sce, 0x3004, 0, 0);
    SeFadeOut__4cSnd6eSndIds(Snd, s1, 0xF);
    if (*(int *)((char *)Message + 0xBEC) == 0) {
        start__9classFADEUiUiUiUiUiUi(Fade, 0, 0xA, 0);
        sleep__9cTaskWorkUs(*(int *)((char *)g_Sce + 0x20), 0xF);
        endSoftEvent__9cScenario(g_Sce);
        float spC = 1.0f;
        func_002C45A8(g_Sce, 0x43, &spC, 0, 2.0f, 1.61f);
    } else {
        endSoftEvent__9cScenario(g_Sce);
    }
    exit__9cTaskWork(*(int *)((char *)g_Sce + 0x20));
}
#endif

// DRAFT: GAME 0x299A28 - 33 words differ, 376 vs 376 bytes: the original saves arg1 into s1 at entry and runs the first loop with the index in a0 and the count in a3; the draft swaps those two registers (lui/addiu and loop-counter order also differ). Tried: by-value arg, shl arg (69-78 words), srcptr/down loop forms (50-52), cnt/idx/ptr loop variants, mid/top slot forms (best: or, cnt, idx, mid), declaration order swap, early arg1 local (no change).
#ifdef NONMATCHING
extern "C" void func_002998D8(void *self, int tag, long b);
extern "C" void func_00299868(void *self, long a, long b);
extern "C" void func_00299908(void *self);
extern unsigned int D_004A6980[];
extern unsigned char D_003BD758[];

extern "C" void func_00299A28(char *arg0, unsigned long long arg1, unsigned int *arg2) {
    int i;
    int n = 0x100;
    for (i = 0; n != 0; i++, n--) {
        D_004A6980[i] = arg2[D_003BD758[i]];
    }
    func_002998D8(arg0, 0, 0xE);
    func_00299868(arg0, 0x3F, 0xFF);
    func_00299868(arg0, 0x50, (long)(arg1 | (1ULL << 48)));
    func_00299868(arg0, 0x51, 0);
    func_00299868(arg0, 0x52, (long)((1ULL << 36) | 0x10));
    func_00299868(arg0, 0x53, 0);
    func_00299908(arg0);
    unsigned int *slot = (unsigned int *)(arg0 + 0x10000);
    *(unsigned long long *)(*slot) = (1ULL << 59) | 0x40;
    *(unsigned long long *)((char *)*slot + 8) = 0;
    *slot += 0x10;
    for (i = 0; i < 0x80; i++) {
        *(unsigned long long *)(*slot) = ((unsigned long long *)D_004A6980)[i];
        *slot += 8;
    }
    func_002998D8(arg0, 0, 0xE);
    func_00299868(arg0, 0x3F, 0xFF);
    func_00299908(arg0);
}
#endif
