// Small units in 0x130000-0x140000.
extern unsigned D_00747A84;
extern "C" void trans__7cIDBase(void *);
struct CoreS { char _p[0x14]; unsigned f; };
extern CoreS *CoreSave;
extern "C" float Adjust_theta__Ff(float);
extern "C" void restartAnim__7cIDBase(void *);
struct ScrD;
extern ScrD *ScrDraw;
extern "C" void drawInit__14cScrSpriteDraw(ScrD *);
extern "C" void drawPolyF__14cScrSpriteDrawffffUi(ScrD *, float, float, float, float, unsigned);

// FUNCTION: GAME 0x138558
extern "C" void func_00138558(char *s)
{
    if (*(unsigned char *)(s + 0x278)) {
        *(float *)(s + 0x268) = *(float *)(s + 0x268) * *(float *)(s + 0x270);
        *(float *)(s + 0x274) = *(float *)(s + 0x274) + *(float *)(s + 0x26C);
        *(float *)(s + 0x274) = Adjust_theta__Ff(*(float *)(s + 0x274));
        (*(unsigned char *)(s + 0x278))--;
    }
    if (*(unsigned char *)(s + 0x264)) {
        *(float *)(s + 0x254) = *(float *)(s + 0x254) * *(float *)(s + 0x25C);
        *(float *)(s + 0x260) = *(float *)(s + 0x260) + *(float *)(s + 0x258);
        *(float *)(s + 0x260) = Adjust_theta__Ff(*(float *)(s + 0x260));
        (*(unsigned char *)(s + 0x264))--;
    }
}

// FUNCTION: GAME 0x13DAE0
extern "C" void func_0013DAE0(char *self)
{
    if (D_00747A84 & 0x8000000)
        return;
    if (D_00747A84 & 0x2000000)
        return;
    if (CoreSave->f & 0x4000000)
        trans__7cIDBase(self + 0xD0);
    trans__7cIDBase(self);
}
// FUNCTION: GAME 0x13D288
extern "C" void func_0013D288(void)
{
    if (D_00747A84 & 0x8000000)
        return;
    if (*(unsigned short *)((char *)&D_00747A84 - 0x34) == 0x20)
        return;
    drawInit__14cScrSpriteDraw(ScrDraw);
    drawPolyF__14cScrSpriteDrawffffUi(ScrDraw, 0.0f, 0.0f, 512.0f, 4.0f, 0);
    drawPolyF__14cScrSpriteDrawffffUi(ScrDraw, 0.0f, 445.0f, 512.0f, 3.0f, 0);
}

// FUNCTION: GAME 0x13E010
extern "C" void func_0013E010(char *self)
{
    unsigned short i;
    for (i = 0; i < 8; i++) {
        restartAnim__7cIDBase(self + (i * 0x50 + 0x90));
        *(unsigned char *)(self + i * 0x50 + 0xAC) = 1;
    }
    char *b = self + 0x33C;
    unsigned short j;
    for (j = 0; j < 8; j++)
        b[j] = -1;
}

extern char Dvd[], RoomHeap[], D_0041E030[], D_0041DD20[], D_0041E090[];
extern char *IDManager, **IDSys;
extern "C" int getLocalFileName__10cIDManagerPcT1Sc(char *, char *, char *, signed char);
extern "C" int ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(char *, char *, void **, char *, int, unsigned, unsigned, unsigned);
extern "C" void CheckWait__4cDvd6eDvdId(char *, int);
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *, int, unsigned *);
extern "C" void initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void func_002AC9B8(void *, void *, int);
extern "C" void move__7cIDBase(void *);

// FUNCTION: GAME 0x13E418
extern "C" void LoadTicket__9cCockItem(char *self)
{
    if (!*(int *)(self + 0x90)) {
        char name[0x40];
        getLocalFileName__10cIDManagerPcT1Sc(IDManager, name, D_0041E030, -1);
        char *id = self + 0xB0;
        int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (void **)(self + 0x90), RoomHeap, 0, 0, 0, 0);
        *(int *)(self + 0x94) = r;
        CheckWait__4cDvd6eDvdId(Dvd, r);
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 0x19, *(unsigned **)(self + 0x90));
        initialize__7cIDBase7eIdData5eIdNo(id, 0x19, 0);
        restartAnim__7cIDBase(id);
        id[0x1C] = 1;
    }
}

// FUNCTION: GAME 0x13D698
extern "C" void func_0013D698(char *self)
{
    char *a = *(char **)(self + 0xA4);
    *(float *)(a + 0x40) += 0.03f;
    *(float *)(*(char **)(self + 0xA4) + 0x78) += 0.0207f;
    a = *(char **)(self + 0xA4);
    if (*(float *)(a + 0x40) >= 1.0f) {
        *(float *)(a + 0x40) = *(float *)(*(char **)(a + 0x1C) + 0x28);
        a = *(char **)(self + 0xA4);
        *(float *)(a + 0x78) = *(float *)(*(char **)(a + 0x1C) + 0x48);
        self[0x1C] = 1;
        *(unsigned *)(*(char **)(self + 0xB0) + 0x2C) &= ~0x8000000;
        func_002AC9B8(self, *(char **)(self + 0xB0), 0);
        *(unsigned *)(*(char **)(self + 0x98) + 0x2C) &= ~0x8000000;
        func_002AC9B8(self, *(char **)(self + 0x98), 0);
        *(unsigned *)(*(char **)(self + 0x9C) + 0x2C) &= ~0x8000000;
        func_002AC9B8(self, *(char **)(self + 0x9C), 0);
        *(unsigned short *)(self + 0x92) = *(unsigned short *)(self + 0x92) + 1;
        move__7cIDBase(self);
    }
}

// DRAFT: GAME 0x13C818 (loop addu operand order differs after 4 tries)
#ifdef NONMATCHING
extern "C" void roomInit__12cCockBossBar(char *self)
{
    if (!*(int *)(self + 0x94)) {
        char name[0x40];
        getLocalFileName__10cIDManagerPcT1Sc(IDManager, name, D_0041DD20, -1);
        int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (void **)self + 0x25, RoomHeap, 0, 0, 0, 0);
        *(int *)(self + 0x98) = r;
        CheckWait__4cDvd6eDvdId(Dvd, r);
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 3, *(unsigned **)(self + 0x94));
        initialize__7cIDBase7eIdData5eIdNo(self, 3, 0);
    }
    restartAnim__7cIDBase(self);
    *(unsigned *)(self + 0xA0) = 0x20000000;
    *(float *)(self + 0xA4) = 1.0f;
    *(short *)(self + 0xB4) = 0;
    *(int *)(self + 0xB8) = 0;
    unsigned short i = 0;
    char *w = self + 0xBC;
    do {
        void *v = getIDWork__7cIDBasei(self, i);
        *(void **)(w + i * 4) = v;
        i++;
    } while (i < 5);
}
#endif

// DRAFT: GAME 0x13E7E8 (loop addu operand order differs after 4 tries)
#ifdef NONMATCHING
extern "C" void roomInit__16cCockLastBossBar(char *self)
{
    if (!*(int *)(self + 0x94)) {
        char name[0x40];
        getLocalFileName__10cIDManagerPcT1Sc(IDManager, name, D_0041E090, -1);
        int r = ReadAlloc__4cDvdPCcPPvR5cHeap6eDvdIdUiUiUi(Dvd, name, (void **)(self + 0x94), RoomHeap, 0, 0, 0, 0);
        *(int *)(self + 0x98) = r;
        CheckWait__4cDvd6eDvdId(Dvd, r);
        setIDData__10cIDManager7eIdDataPUi(*IDSys, 0x1C, *(unsigned **)(self + 0x94));
        initialize__7cIDBase7eIdData5eIdNo(self, 0x1C, 0);
    }
    restartAnim__7cIDBase(self);
    *(unsigned *)(self + 0xA0) = 0x20000000;
    *(float *)(self + 0xA4) = 1.0f;
    char *w;
    unsigned short i = 0;
    w = self + 0xC0;
    do {
        *(void **)(w + i * 4) = getIDWork__7cIDBasei(self, i);
        i++;
    } while (i < 4);
    self[0x79] = 0;
    self[0x7A] = 0;
    self[0x7B] = 0;
    self[0x7C] = 0;
}
#endif

// DRAFT: GAME 0x13ED28 (addu operand order of 4 hoisted bases differs after 4 tries)
#ifdef NONMATCHING
extern "C" void func_002AA3D8(void *, int);
extern "C" void func_0013ED28(char *self)
{
    char *w[3];
    func_002AA3D8(self, 0);
    func_002AA3D8(self, 1);
    func_002AA3D8(self, 2);
    func_002AA3D8(self, 3);
    restartAnim__7cIDBase(self);
    self[0x1C] = 1;
    w[0] = (char *)getIDWork__7cIDBasei(self, 0);
    w[1] = (char *)getIDWork__7cIDBasei(self, 1);
    char *e = (char *)getIDWork__7cIDBasei(self, 2);
    w[2] = (char *)getIDWork__7cIDBasei(self, 3);
    float *p1 = (float *)(self + 0x94), *p2 = (float *)(self + 0x90), *p3 = (float *)(self + 0x98), *p4 = (float *)(self + 0x9C);
    unsigned short i;
    for (i = 0; i < 2; i++) {
        p1[i * 4] = 1.0f;
        p2[i * 4] = 2.0f;
        p3[i * 4] = *(float *)(w[i] + 0x74);
        p4[i * 4] = *(float *)(w[i] + 0x7C);
    }
    *(float *)(self + 0xB4) = *(float *)(e + 0x38);
    *(float *)(self + 0xB8) = 256.0f;
    *(int *)(self + 0xB0) = 0;
    self[0xBC] = 0;
}
#endif

// DRAFT: GAME 0x13C630 (div.s hazard nops and store order differ after 4 tries)
#ifdef NONMATCHING
struct Q4 { float v[4]; } __attribute__((aligned(16)));
extern "C" void func_002E1468(Q4 *, Q4 *, Q4 *, Q4 *, float, float, float);
extern "C" void func_0013C630(char *s)
{
    if (*(unsigned char *)(s + 0x74))
        return;
    if (!*(unsigned char *)(s + 0x75))
        return;
    if (*(unsigned char *)(s + 0x76)) {
        *(unsigned short *)(s + 0x72) = *(unsigned short *)(s + 0x72) + 1;
        if (*(short *)(s + 0x70) < *(short *)(s + 0x72)) {
            *(unsigned short *)(s + 0x72) = *(unsigned short *)(s + 0x70);
            *(unsigned char *)(s + 0x75) = 0;
        }
    } else {
        *(unsigned short *)(s + 0x72) = *(unsigned short *)(s + 0x72) - 1;
        if (*(short *)(s + 0x72) < 0) {
            *(short *)(s + 0x72) = 0;
            *(unsigned char *)(s + 0x75) = 0;
        }
    }
    Q4 a, b, c, d;
    float t = (float)*(short *)(s + 0x72) / (float)*(short *)(s + 0x70);
    Q4 *pb = &b;
    b.v[0] = *(float *)(s + 0x58) - *(float *)(s + 0x50);
    b.v[1] = *(float *)(s + 0x5C) - *(float *)(s + 0x54);
    a.v[0] = 0; a.v[3] = 1.0f; a.v[1] = 0; a.v[2] = 0;
    b.v[2] = 0;
    pb->v[3] = 1.0f;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(c));
    func_002E1468(&d, &c, &a, &b, t, 0.0f, 0.0f);
    *(float *)(s + 0x60) = c.v[0];
    *(float *)(s + 0x64) = c.v[1];
}
#endif

// DRAFT: GAME 0x13D400 (register allocation differs after 3 tries)
#ifdef NONMATCHING
extern "C" void func_002AA3D8(void *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(void *, void *);
extern "C" void SetDisp__12CustomIDWorkb(void *, int);
extern "C" void Main__12CustomIDWork(void *);
extern "C" void func_0013D400(char *self)
{
    unsigned short i = 0;
    char *w = self + 0x94;
    *(unsigned short *)(self + 0x92) = 0;
    do {
        func_002AA3D8(self, i);
        void *v = getIDWork__7cIDBasei(self, i);
        *(void **)(w + i * 4) = v;
        func_002AC9B8(self, v, 0);
        i++;
    } while (i < 11);
    restartAnim__7cIDBase(self);
    char *b = self + 0xD0;
    char *c = b;
    *(char *)(self + 0x90) = 1;
    *(int *)(*(char **)(self + 0xA4) + 0x78) = 0;
    int k = 0;
    char *cw = self + 0x120;
    *(int *)(*(char **)(self + 0xA4) + 0x40) = 0;
    move__7cIDBase(self);
    restartAnim__7cIDBase(b);
    do {
        void *v = getIDWork__7cIDBasei(c, k);
        k++;
        Initialize__12CustomIDWorkP7cIDWork(cw, v);
        SetDisp__12CustomIDWorkb(cw, 0);
        cw += 0x7C;
    } while (k < 5);
    char *cw2 = self + 0x120;
    int j = 4;
    do {
        Main__12CustomIDWork(cw2);
        j--;
        cw2 += 0x7C;
    } while (j >= 0);
    move__7cIDBase(c);
    *(char *)(self + 0x38C) = 0;
}
#endif
