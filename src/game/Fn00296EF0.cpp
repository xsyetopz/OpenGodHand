// God Hand: units of slice F129 (0x296EF0 - 0x2A9F30).
extern "C" int func_00298028(void *, int);
extern "C" void func_0(void *);
extern "C" int setMeshDisplay__6cModelPCcb(void *, char *, int);
extern char D_Ev297AA8[];
extern char D_Ev297AB0[];
extern char D_Ev297AB8[];
extern char D_Ev297AC0[];
extern char D_Ev297AC8[];
extern char D_Ev297AD0[];
extern char D_Ev297AD8[];
extern char D_Ev297AE0[];
extern char D_Ev297AE8[];
extern char D_Ev297AF0[];
extern char D_Ev297AF8[];
extern char D_Ev297B00[];
extern char D_Ev297B08[];
extern char D_Ev297B10[];
extern char D_Ev297B18[];
extern char D_Ev297AA9[];
extern int D_00747A84;
extern char D_0044AC48[];
extern char D_0044AC50[];
extern char D_0044AC58[];
extern char D_0044AC60[];
extern char D_0044AC68[];
extern "C" int func_002ACD78(int, int, int);
extern "C" int SearchData__FPUiPCcUi(void *, const char *, unsigned);
extern "C" void setTextureAddr__5cFont9eFontKindPUiT2(void *, int, int, int);
extern "C" void setEnvInit__13cMessDrawFont(void *, void *);
extern "C" void func_002AF6A8(void *, int, int);
extern char *Font;
extern int *IDSys;
extern char *Message;
extern char MessDrawFont[];
extern char Sys[];
extern char D_0044AF20[];
extern char D_0044AF28[];
extern char D_0044AF30[];

#ifdef NONMATCHING
// DRAFT: GAME 0x296EF0 1 word differs: 0x296F08 shift is dsra/srl, original dsrl. Tried: unsigned int load, % 2, (unsigned long)(long) cast, local unsigned long, / 4, (long) cast and int local (1 word, sra); uint/ulong bitfields, 64-bit loads, & 4 (73-76).
extern "C" void movePlayQuit__6cEvent(char *self)
{
    if (((unsigned long)(long)*(int *)(self + 8) >> 2) & 1) {
        char *s = D_Ev297AA9;
        if (func_00298028(s, 0x20) & 0xFF) self[0x34] = 1;
        func_0(D_Ev297AA8);
        func_0(D_Ev297AB0);
        func_0(s);
        func_0(D_Ev297AB8);
        func_0(D_Ev297AC0);
        func_0(D_Ev297AC8);
        func_0(D_Ev297AD0);
        func_0(D_Ev297AD8);
        func_0(D_Ev297AE0);
        func_0(D_Ev297AE8);
        func_0(D_Ev297AF0);
        func_0(D_Ev297AF8);
        func_0(D_Ev297B00);
        func_0(D_Ev297B08);
        func_0(D_Ev297B10);
        func_0(D_Ev297B18);
        func_0(s);
        *(int *)(self + 8) &= ~4;
        D_00747A84 &= ~1;
    }
}
#endif

// FUNCTION: GAME 0x2991D8
extern "C" void func_002991D8(char *self, int, int n, float t)
{
    if (self == 0) return;
    unsigned short id = *(unsigned short *)(self + 0x2FE);
    switch (id) {
    case 0x627:
    case 0x625:
        setMeshDisplay__6cModelPCcb(self, D_0044AC48, 0);
        if (n < 3) break;
        if (n == 3 && !(t >= 10.0f)) {
            setMeshDisplay__6cModelPCcb(self, D_0044AC50, 1);
            setMeshDisplay__6cModelPCcb(self, D_0044AC58, 0);
            return;
        }
        setMeshDisplay__6cModelPCcb(self, D_0044AC50, 0);
        setMeshDisplay__6cModelPCcb(self, D_0044AC58, 1);
        return;
    case 0x626:
        if (n >= 2) {
            setMeshDisplay__6cModelPCcb(self, D_0044AC60, 1);
            setMeshDisplay__6cModelPCcb(self, D_0044AC68, 0);
        }
        break;
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2A9F30 first attempt from m2c, not yet compared.
extern "C" int setPackedMessData__7cIDBase7eIdData5eIdNo(char *self, int eIdData, int eIdNo)
{
    int id = func_002ACD78(*IDSys, eIdData, eIdNo + 1);
    int ret = 0;
    if (id != 0) {
        *(int *)(self + 8) = id;
        char *sys = Sys;
        int mode = *(int *)(sys + 0x56C);
        if (mode == 0) {
            int s0 = SearchData__FPUiPCcUi((void *)id, D_0044AF20, 0);
            setTextureAddr__5cFont9eFontKindPUiT2(Font, 3, s0, SearchData__FPUiPCcUi((void *)id, D_0044AF28, 0));
        } else {
            if (mode >= 0) {
                if (mode < 7) {
                    int s0 = SearchData__FPUiPCcUi((void *)*(int *)(sys + 0x558), D_0044AF20, 0);
                    setTextureAddr__5cFont9eFontKindPUiT2(Font, 3, s0, SearchData__FPUiPCcUi((void *)id, D_0044AF28, 0));
                }
            }
        }
        *(int *)(Message + 8) = SearchData__FPUiPCcUi((void *)id, D_0044AF30, 0);
        setEnvInit__13cMessDrawFont(MessDrawFont, Message);
        func_002AF6A8(MessDrawFont, 2, 0);
        ret = 1;
    }
    return ret;
}
#endif
