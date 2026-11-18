extern "C" void move__7cCamera(void *);
extern "C" void MoveEffect__Fv();
extern "C" void func_002AEFA8(void *);
extern "C" void func_00140E58(void *);
extern void *pCamWork, *Message, *Cockpit;
extern int *objbaseArray;

// FUNCTION: GAME 0x2AE650
extern "C" void Move__3cMc()
{
    move__7cCamera(pCamWork);
    MoveEffect__Fv();
    func_002AEFA8(Message);
    func_00140E58(Cockpit);
    for (char **p = (char **)objbaseArray[1]; p != (char **)objbaseArray[2]; p++) {
        char *o = *p;
        unsigned f = *(unsigned *)(o + 0x250);
        if (!(f & 0x8000)) {
            if (!(f & 0x80000000)) {
                char *vt = *(char **)(o + 0x214);
                ((void (*)(char *))*(int *)(vt + 0x54))(o + *(short *)(vt + 0x50));
            }
        }
    }
}

// FUNCTION: GAME 0x2AA480
extern "C" void func_002AA480(int *self)
{
    for (int i = 0; i < self[3]; i++) {
        char *e = (char *)(i * 0xAC + self[1]);
        int c = *(char *)(e + 0x29);
        if (c < 0) {
            *(int *)(e + 0x20) = 0;
            continue;
        }
        if (c == *(unsigned char *)(e + 0x28)) {
            *(int *)(e + 0x20) = 0;
            return;
        }
        for (int j = 0; j < self[3]; j++) {
            if (i != j) {
                char *a = (char *)(i * 0xAC + self[1]);
                char *b = (char *)(j * 0xAC + self[1]);
                if (*(char *)(a + 0x29) == *(unsigned char *)(b + 0x28))
                    *(int *)(a + 0x20) = (int)b;
            }
        }
    }
}

// FUNCTION: GAME 0x2AA5F0
extern "C" void func_002AA5F0(int *self, int target, int flag)
{
    for (int i = 0; i < self[3]; i++) {
        char *e = (char *)(self[1] + i * 0xAC);
        if (target != (int)e && target == *(int *)(e + 0x20)) {
            int t = flag ^ 1;
            if (t)
                *(unsigned *)(e + 0x2C) |= 0x20000000;
            else
                *(unsigned *)(e + 0x2C) &= 0xDFFFFFFF;
            func_002AA5F0(self, self[1] + i * 0xAC, flag);
        }
    }
}

extern "C" short *SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" void func_003127B0(void *, int);
extern "C" void *_MemoryAlloc__FUiUiR5cHeap(unsigned, unsigned, void *);
extern "C" void func_002A9498(void *, void *, int, int);
extern "C" void func_00150098(int);
extern "C" void func_001492E8(int);
extern void *D_00747A4C, *MemDefalutHeapPtr;
extern char D_0044AD60[], objArray[], scrArray[], D_00754C50[], D_00754C20[], D_00754240[], D_00754C10[];

// FUNCTION: GAME 0x2A5D80
extern "C" void func_002A5D80()
{
    short *d = SearchData__FPUiPCcUi(D_00747A4C, D_0044AD60, 0);
    func_003127B0(objArray, d[0] + d[1]);
    func_003127B0(scrArray, d[0]);
    func_003127B0(D_00754C50, 0x80);
    func_003127B0(&objbaseArray, d[1]);
    int sz = d[0] * 0x380 + 0x20;
    func_002A9498(D_00754C20, _MemoryAlloc__FUiUiR5cHeap(sz, 0x10, MemDefalutHeapPtr), sz, 0);
    func_002A9498(D_00754240, _MemoryAlloc__FUiUiR5cHeap(*(int *)(d + 6), 0x10, MemDefalutHeapPtr), *(int *)(d + 6), 0);
    func_002A9498(D_00754C10, _MemoryAlloc__FUiUiR5cHeap(*(int *)(d + 2), 0x10, MemDefalutHeapPtr), *(int *)(d + 2), 0);
    func_00150098(d[8]);
    func_001492E8(d[9]);
}

extern "C" int func_002ACE48(int, int, int, int);
extern "C" void func_002AA1E0(int *, int *, int);
extern "C" void func_002AA480(int *);
extern int *IDSys;
extern int IDManager;

// FUNCTION: GAME 0x2AA0D0
extern "C" int setWorkFromData__7cIDBasePUi(int *self, int *d)
{
    if (d[0] == 0x504449) {
        int *w = d + 4;
        self[3] = 0;
        if (*IDSys == IDManager) {
            for (unsigned i = 0; i < (unsigned)d[1]; i++) {
                if (!(*(unsigned *)((char *)d + 0x14 + i * 0x2E0) & 0x200)) self[3]++;
            }
        } else {
            self[3] = d[1];
        }
        if (!self[3]) return 0;
        if (!self[1]) {
            if (!(self[1] = func_002ACE48(*IDSys, self[3], self[5], self[4]))) return 0;
        }
        func_002AA1E0(self, w, self[3]);
        func_002AA480(self);
        return 1;
    }
    return 0;
}

extern "C" void *getMessageAddr__C8cMessageUs(void *, unsigned short);
extern "C" void *getRubyAddr__C8cMessageUs(void *, unsigned short);
extern "C" void setBodyData__13cMessDrawFontPCUsN21(void *, void *, void *, int);
extern "C" void setRubyData__13cMessDrawFontPCUsT1(void *, void *, void *);
extern "C" void setDrawCounter__13cMessDrawFontii(void *, int, int);

// FUNCTION: GAME 0x2AF590
extern "C" void func_002AF590(void *self, unsigned short no)
{
    void *a = getMessageAddr__C8cMessageUs(Message, no);
    void *r = getRubyAddr__C8cMessageUs(Message, no);
    setBodyData__13cMessDrawFontPCUsN21(self, a, a, 0);
    setRubyData__13cMessDrawFontPCUsT1(self, r, r);
    setDrawCounter__13cMessDrawFontii(self, 0, 0xFFFFFFF);
}

extern "C" int func_002B2318(int *);
extern "C" void func_002B2080(int *);
extern "C" void func_002B22E8(int *, int *, int *, int, unsigned short);

// FUNCTION: GAME 0x2AEE40
extern "C" int *func_002AEE40(char *self, short key)
{
    int *p = *(int **)(self + 0x14);
    if (!p) return 0;
    *(int *)(self + 0x14) = func_002B2318(p);
    func_002B2080(p);
    int *prev = 0;
    int *c = *(int **)(self + 0x10);
    while (c && key < *(short *)((char *)c + 2)) {
        prev = c;
        c = (int *)prev[2];
    }
    *(unsigned short *)(self + 0xBD8) += 1;
    if (*(unsigned short *)(self + 0xBD8) == 0xFFFF) *(unsigned short *)(self + 0xBD8) = 0;
    func_002B22E8(p, prev, c, key, *(unsigned short *)(self + 0xBD8));
    if (!prev) *(int **)(self + 0x10) = p;
    return p;
}

extern "C" void KillEffect__FPC4cObji13eEspEraseMode(char *, int, int);

// FUNCTION: GAME 0x2A8718
extern "C" void func_002A8718(char *self)
{
    char *p = *(char **)(self + 0x42C);
    if (p) {
        char *e = p + *(unsigned short *)(p + 0x14);
        for (unsigned i = 0; i < *(unsigned short *)(p + 0x16); i++, e += 12) {
            int id = *(int *)e;
            if (id != -1) {
                if (*(unsigned char *)(e + 0xA) & 2)
                    KillEffect__FPC4cObji13eEspEraseMode(self, id, 2);
                else
                    KillEffect__FPC4cObji13eEspEraseMode(self, id, 0);
            }
        }
    }
    int s = *(short *)(self + 0x570);
    if (s != -1) KillEffect__FPC4cObji13eEspEraseMode(self, s, *(int *)(self + 0x574));
    *(short *)(self + 0x570) = -1;
    *(int *)(self + 0x574) = 2;
}

