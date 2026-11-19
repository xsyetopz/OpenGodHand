struct Vq {
    float x, y, z, w;
    Vq(float a, float b, float c, float d) : x(a), y(b), z(c), w(d) {}
};
extern char g_DmgManage[];
extern "C" int func_001B6FB8(char *);
extern "C" void *CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(void *, int, char *);
extern "C" int AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(void *, char *, const Vq &, float);
extern "C" void SetDamageCollActive__11cDamageUnitb(void *, int);
extern "C" void *Getplayer__Fv();
extern "C" int func_001FDD38(char *, int);
extern "C" int checkDamage__7cOmBaseP11cDamageTake(char *, int);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(char *, int, int, char *, int, char *, int);
extern "C" void setMeshColorFromLayer__7cOmBaseUifff(char *, unsigned, float, float, float);
extern unsigned char D_005CB010;
extern char Snd[];
extern unsigned int D_00747A24;
extern char GlobalTask[];
extern char Sys[];
extern char cVram_work[];
extern int IDManager;
extern int *IDSys;
extern char D_0044AD58[];
extern int g_SaveManager;
extern char PadVib[];
extern int Font;
extern int Message;
extern int SubScr;
extern char Event[];
extern int Cockpit;
extern char Door[];
extern int SaveLoad;
extern char g_DataManager[];
extern char g_EmdManager[];
extern char RoomHeap[];
extern char D_005FEC58[];
extern "C" void sleep__9cTaskWorkUs(int, int);
extern "C" void func_00150C10(void *, void *, int);
extern "C" int SearchData__FPUiPCcUi(void *, char *, unsigned int);
extern "C" void systemInit__10cIDManagerPUi(int, int);
extern "C" void func_002BF878(int);
extern "C" void func_002BDB78(void *);
extern "C" void func_002A4970(int);
extern "C" void func_002AE990(int);
extern "C" void func_0015FD98(int);
extern "C" void func_002962B0(void *);
extern "C" void func_00140C88(int);
extern "C" void func_001FFE00(void *);
extern "C" void func_002BF130(int);
extern "C" void func_001FE6C8(void *, void *);
extern "C" void func_002C8EF8(void *);
extern char D_0042C750[];
extern unsigned char D_0045F039[];
extern "C" char *strcpy(char *, const char *);
extern "C" char *strtok(char *, const char *);
extern "C" int strcmp(const char *, const char *);

// DRAFT: GAME 0x1B0DE8
// 80/97 words differ: CreateDamageGive arg order (a2 before a1), Vq local zero-store scheduling, ternary spill; tried inline Vq, locals before/after m (vA/vB/vC)
#ifdef NONMATCHING
extern "C" int func_001B0DE8(char *self)
{
    func_001B6FB8(self);
    *(int *)(self + 0x600) = 0;
    *(int *)(self + 0x604) = 0;
    *(float *)(self + 0x630) = 150.0f;
    *(void **)(self + 0x66C) = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 0, self);
    Vq v2(0.0f, 0.0f, 0.0f, 1.0f);
    Vq v1(0.0f, 0.0f, 0.0f, 1.0f);
    char *m = *(unsigned char *)(self + 0x2B4) ? *(char **)*(char **)(self + 0x278) : 0;
    *(int *)(self + 0x674) = AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x66C), m + 0x80, v1, 3.0f);
    SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x66C), 0);
    *(void **)(self + 0x670) = CreateDamageGive__13cDamageManage8DMG_KINDP8cGameObj(g_DmgManage, 1, self);
    char *m2 = *(unsigned char *)(self + 0x2B4) ? *(char **)*(char **)(self + 0x278) : 0;
    *(int *)(self + 0x678) = AddDamageCollSphere__11cDamageUnitRC7cMatrixRC4cVecf(*(void **)(self + 0x670), m2 + 0x80, v2, 3.0f);
    SetDamageCollActive__11cDamageUnitb(*(void **)(self + 0x670), 0);
    *(int *)(self + 0x650) = 0;
    *(int *)(self + 0x654) = 0;
    *(int *)(self + 0x658) = 0;
    if (*(unsigned short *)(self + 0x2FE) == 0x360) {
        *(float *)(self + 0x118) = 2.0f;
        *(float *)(self + 0x110) = 2.0f;
        *(float *)(self + 0x114) = 2.0f;
    }
    *(int *)(self + 0x668) = 0;
    *(unsigned char *)(self + 0x667) = 0;
    *(int *)(self + 0x5B8) = (*(int *)(self + 0x5B8) | 8) & ~0x40;
    return 1;
}
#endif

// DRAFT: GAME 0x194558
// 71/98 words differ: frame 0x20 vs original 0x30 (missing stack slot), branch/slt order around the 0x54A compare, SeCall argument scheduling; one variant tried
#ifdef NONMATCHING
extern "C" void func_00194558(char *self)
{
    if (*(int *)(self + 0x608) != 0 && D_005CB010 != 0 &&
        func_001FDD38(*(char **)(self + 0x608), (int)Getplayer__Fv()) == 1) {
        *(unsigned char *)(self + 0x2F4) = 2;
        *(unsigned char *)(self + 0x2F5) = 0;
        *(int *)(self + 0x5B0) = *(int *)(self + 0x5B0) | 1;
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    }
    int r = checkDamage__7cOmBaseP11cDamageTake(self, *(int *)(self + 0x604));
    if (r == 1) {
        if (*(short *)(self + 0x54A) > 0) {
            char *parts = 0;
            if (1 < (int)*(unsigned char *)(self + 0x2B4)) {
                parts = *(char **)(*(char **)(self + 0x278) + 4);
            }
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 0x8C, self, 0, parts, 0);
            *(int *)(self + 0xAF4) = 8;
        } else {
            *(unsigned char *)(self + 0x2F4) = 2;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(int *)(self + 0x5B0) = *(int *)(self + 0x5B0) | 1;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
    int n = *(int *)(self + 0xAF4);
    int m = n - 1;
    if (n != 0) {
        *(int *)(self + 0xAF4) = m;
        if (m != 0) {
            if (m & 1) {
                setMeshColorFromLayer__7cOmBaseUifff(self, 2, 1.0f, 1.0f, 1.0f);
                return;
            }
            setMeshColorFromLayer__7cOmBaseUifff(self, 2, 1.0f, 0.0f, 0.0f);
            return;
        }
        setMeshColorFromLayer__7cOmBaseUifff(self, 2, 1.0f, 1.0f, 1.0f);
    }
}
#endif

// DRAFT: GAME 0x2A5BB8
// 96/98 words differ: prologue keeps arg in s4 (frame 0x60 vs 0x50), data-symbol lui/lw placeholders differ from the original's hi/lo pairs; variants: reloaded vs cached Sys+0x550 (96), hoisted sys/vram locals (101, reverted)
#ifdef NONMATCHING
extern "C" void func_002A5BB8(char *arg0)
{
    if (!(D_00747A24 & 0x2000)) {
        do {
            sleep__9cTaskWorkUs(*(int *)(GlobalTask + 4), 1);
        } while (!(D_00747A24 & 0x2000));
    }
    func_00150C10(cVram_work, *(char **)(Sys + 0x550) + *(int *)(*(char **)(Sys + 0x550) + 4), 1);
    func_00150C10(cVram_work, *(char **)(Sys + 0x550) + *(int *)(*(char **)(Sys + 0x550) + 8), 1);
    *IDSys = IDManager;
    systemInit__10cIDManagerPUi(IDManager, SearchData__FPUiPCcUi(*(void **)(Sys + 0x558), D_0044AD58, 0));
    func_002BF878(g_SaveManager);
    func_002BDB78(PadVib);
    func_002A4970(Font);
    func_002AE990(Message);
    func_0015FD98(SubScr);
    func_002962B0(Event);
    func_00140C88(Cockpit);
    func_001FFE00(Door);
    func_002BF130(SaveLoad);
    func_001FE6C8(g_DataManager, 0);
    func_001FE6C8(g_EmdManager, RoomHeap);
    func_002C8EF8(D_005FEC58);
    *arg0 = 2;
}
#endif

// DRAFT: GAME 0x1FFA68
// 94 words differ: frame 0xC0 vs 0xD0, s7 (outer-loop 3) not saved; variants tried: e[0]==0 check, int type, (unsigned char) cast
#ifdef NONMATCHING
extern "C" char *func_001FFA68(char *a0, char *a1)
{
    char buf[0x40];
    char *e;
    char *tok;
    char *p;
    unsigned char type;

    if (*(char **)a0 == 0) {
        return 0;
    }
    strcpy(buf, a1);
    if (buf[0]) {
        p = buf;
        do {
            if (*p == '/') {
                *p = '\\';
            }
            *p = (D_0045F039[*p] & 1) ? *p + 0x20 : *p;
            p++;
        } while (*p);
    }
    e = *(char **)a0;
    tok = strtok(buf, D_0042C750);
    if (tok == 0) {
        return 0;
    }
    type = e[0];
    for (;;) {
        while (type != 3) {
            if (type == 2) {
                if (strcmp(*(char **)(e + 4), tok) == 0) {
                    return e;
                }
                e += 12;
            } else if (type == 1 && (strcmp(*(char **)(e + 4), tok) == 0 || strcmp(a0 + 0x19, tok) == 0)) {
                e = *(char **)(e + 8);
                break;
            } else {
                e += 12;
            }
            type = e[0];
        }
        type = e[0];
        if (type == 0) {
            return 0;
        }
        tok = strtok(0, D_0042C750);
        if (tok == 0) {
            return 0;
        }
        type = e[0];
    }
}
#endif
