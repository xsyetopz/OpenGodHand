extern "C" void func_002A58A0(char *, int);
extern "C" void func_002A58D8(char *, unsigned);

// FUNCTION: GAME 0x2A4E58
extern "C" void func_002A4E58(char *self, int a, short b, int c, unsigned d, float x, float y, float z)
{
    char *p = self + 0x28000;
    *(int *)(p + 0x2074) = a;
    *(short *)(p + 0x2078) = b;
    *(float *)(p + 0x2080) = x;
    *(float *)(p + 0x207C) = x;
    *(float *)(p + 0x2084) = y;
    *(float *)(p + 0x2088) = z;
    func_002A58A0(self, c);
    func_002A58D8(self, d);
}

extern "C" int *func_002A4F30(char *, int);
extern "C" void func_0031A650(void *, int, int, int);
extern char D_00754C80[];

// DRAFT: GAME 0x2A5930 - 5 words differ: original keeps the new node pointer in t0 instead of a1
#ifdef NONMATCHING
extern "C" void func_002A5930(char *self)
{
    int *p = func_002A4F30(self, 0x10);
    if (p) {
        *(unsigned long *)p = 0x70000000;
        p[2] = 0x11000000;
        p[3] = 0;
        char *b = self + 0x28000;
        func_0031A650(D_00754C80, *(int *)(b + 0x2060), *(int *)(b + 0x2064), *(int *)(b + 0x2050));
    }
}
#endif

extern "C" int func_001FAEA0(void *);
extern "C" void func_002A9B50(float *);
extern char CoreSave[];

// FUNCTION: GAME 0x2A9BF0
extern "C" void func_002A9BF0(float *self)
{
    float t = (float)(func_001FAEA0(CoreSave) * 30 + 0x78);
    self[0] = t;
    if (t < self[1])
        self[1] = t;
    func_002A9B50(self);
}

extern "C" void func_00309000(char *);
extern char D_005CB3B0[];

// DRAFT: GAME 0x2AD1B0 - 17 words differ: original adds 0x744 to the lui/addiu base instead of folding it into the relocation
#ifdef NONMATCHING
extern "C" void func_002AD1B0(int a, int b)
{
    if (b == 0xFFFF && a) {
        char *p = D_005CB3B0 + 0x744;
        for (int i = 0x27F; i != -1; i--) {
            func_00309000(p);
            p += 0xAC;
        }
    }
}
#endif

extern "C" float func_002A9C98(float *);

// FUNCTION: GAME 0x2A9B50
extern "C" void func_002A9B50(float *self)
{
    float f = func_002A9C98(self);
    if (f < 0.5f)
        ((int *)self)[5] = 0;
    else
        ((int *)self)[5] = (f <= 0.75f) ? 1 : 2;
}

extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" void setTextureAddr__5cFont9eFontKindPUiT2(void *, int, int, int);
extern char Sys[];
extern char D_0044ACE0[], D_0044ACE8[];

// FUNCTION: GAME 0x2A4C38
extern "C" void func_002A4C38(void *self)
{
    char *s = Sys;
    int a = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_0044ACE0, *(unsigned *)(s + 0x56C));
    int b = SearchData__FPUiPCcUi(*(void **)(s + 0x5AC), D_0044ACE8, *(unsigned *)(s + 0x56C));
    setTextureAddr__5cFont9eFontKindPUiT2(self, 2, a, b);
}

extern char g_EmManage[];
extern "C" void ReleaseEmAll__9cEmManage(void *);

// FUNCTION: GAME 0x2A6C18
extern "C" void setReleaseActiveHeap__5cGamei(char *self)
{
    ReleaseEmAll__9cEmManage(g_EmManage);
    *(short *)(self + 0x1B2) = 5;
}

extern "C" int isClip__C6cModel(void *);

// DRAFT: GAME 0x2A7448 - 1 word differs: second branch compiles to bnel, original bnez with addiu in the delay slot
#ifdef NONMATCHING
extern "C" int isClip__C8cGameObj(char *self)
{
    long l = *(unsigned *)(self + 0x5A0);
    long a = l & 1;
    int r = 1;
    if (!a) {
        long b = (l >> 1) & 1;
        if (!b)
            r = isClip__C6cModel(self) != 0;
    }
    return r;
}
#endif

// FUNCTION: GAME 0x2A9680
extern "C" void free__5cHeapPv(void *, int *n)
{
    if (n) {
        n -= 8;
        int *p = (int *)n[1];
        p[2] = n[2];
        p[3] = p[3] + (n[4] + n[3]);
        if (n[2]) *(int **)(n[2] + 4) = p;
    }
}

// DRAFT: GAME 0x2A4BA0 - 21 words differ: original copies self to a2 and keeps a single return 0 at the tail; compiled returns 0 first
#ifdef NONMATCHING
extern "C" int func_002A4BA0(char *self, int idx)
{
    unsigned v = idx & 0xFFFF;
    if (!v) return 0;
    char *c = self + (v >> 12) * 16;
    unsigned *t = *(unsigned **)(c + 4);
    unsigned w = t[(v & 0xFFF) + 2];
    return (short)(*(unsigned short *)(c + 0xE) - ((w >> 14) & 0x3F));
}
#endif

struct sIDSysP { int *p; };
extern sIDSysP *IDSys;
extern "C" void func_002ACF30(int *, int, int, int);

// FUNCTION: GAME 0x2AA078
extern "C" int release__7cIDBase(int *self)
{
    int r = 0;
    if (self[1]) {
        func_002ACF30(IDSys->p, self[1], self[5], self[4]);
        r = 1;
        self[0] = 0;
        self[1] = 0;
        self[2] = 0;
    }
    return r;
}

extern char D_005CB300[];

// DRAFT: GAME 0x2AA410 - 9 words differ: loop counter and entry pointer land in swapped registers (a2/a3)
#ifdef NONMATCHING
extern "C" char *getIDWork__7cIDBasei(int *self, int id)
{
    char *p = (char *)self[1];
    if (!p) return D_005CB300;
    int n = self[3];
    char *e = p;
    char *f = e + 0x2C;
    int i;
    for (i = 0; i < n; i++) {
        if ((*(unsigned *)f & 0x80000000) && *(signed char *)(f - 2) == id) return e;
        e += 0xAC;
        f += 0xAC;
    }
    return D_005CB300;
}
#endif

// DRAFT: GAME 0x2AC538 - 34 words differ: gcc peels the i=1 and i=2 iterations of the search loop that the original keeps rolled
#ifdef NONMATCHING
extern "C" int func_002AC538(int, int key, int n, char *tbl)
{
    key = (short)key;
    int i = 1;
    if (!n) return -1;
    if (*(short *)(tbl + 8) >= key) return -1;
    if (i < n) {
        if (*(short *)(tbl + 0x14) >= key) {
            i = 0;
        } else {
            i++;
            while (i < n) {
                if (*(short *)(tbl + i * 12 + 8) >= key) { i--; break; }
                i++;
            }
        }
    }
    return i;
}
#endif

extern "C" void *memset(void *, int, unsigned);
extern "C" void func_002ACCD8(char *);
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *, int, unsigned *);

// FUNCTION: GAME 0x2ACC70
extern "C" void systemInit__10cIDManagerPUi(char *self, unsigned *p)
{
    memset(self + 0x100, 0, 0x640);
    *(int *)(self + 0x18000 + 0x3544) = 0;
    *(int *)(self + 0x740) = 0;
    func_002ACCD8(self);
    setIDData__10cIDManager7eIdDataPUi(self, 1, p);
}

// FUNCTION: GAME 0x2A9C58
extern "C" void SetHeatGage__8cHeatSysf(float *self, float v)
{
    if (self[0] < v) self[1] = self[0];
    else self[1] = v;
    func_002A9B50(self);
}

extern "C" char *getIDWork__7cIDBasei(int *, int);
extern "C" void func_002AA598(int *, char *, int);
extern "C" void func_002AA5F0(int *, char *, int);

// FUNCTION: GAME 0x2AA538
extern "C" void setDispFamily__7cIDBaseib(int *self, int id, int on)
{
    char *w = getIDWork__7cIDBasei(self, id);
    func_002AA598(self, w, on);
    func_002AA5F0(self, w, on);
}

extern "C" void func_002B2348(int *);
extern "C" int func_002B2318(int *);
extern "C" void func_002B22E8(int *, int, int, int, int);

// FUNCTION: GAME 0x2AEF10
extern "C" int func_002AEF10(int *self, int *p)
{
    if (!p[1]) self[4] = p[2];
    func_002B2348(p);
    int r = func_002B2318(p);
    func_002B22E8(p, 0, self[5], 0, 0);
    self[5] = (int)p;
    return r;
}

extern char *Message;
extern "C" unsigned short *getMessageAddr__C8cMessageUs(char *, unsigned short);
extern "C" int getCodeSize__11cMessCommonUs(unsigned short);

// DRAFT: GAME 0x2AF380 - 12 words differ: original uses beql with i++ in the delay slot for the non-flag path; compiled branches over it
#ifdef NONMATCHING
extern "C" int func_002AF380(unsigned short n)
{
    int i = 0;
    unsigned short *p = getMessageAddr__C8cMessageUs(Message, n);
    unsigned w;
    while ((w = *p) >> 15 ? (w & 0xFF00) != 0x8000 : (i++, 1))
        p += getCodeSize__11cMessCommonUs(*p);
    return i;
}
#endif

extern char D_0044AF70[];

// DRAFT: GAME 0x2ACCF8 - 13 words differ: gcc merges the two self+id*8 adds, original keeps two
#ifdef NONMATCHING
extern "C" void setIDData__10cIDManager7eIdDataPUi(char *self, int id, unsigned *data)
{
    int a = SearchData__FPUiPCcUi(data, D_0044AF70, 0);
    id <<= 3;
    *(int *)(self + id) = a;
    int b = SearchData__FPUiPCcUi(data, D_0044AF70, 1);
    self += id;
    *(int *)(self + 4) = b;
}
#endif
