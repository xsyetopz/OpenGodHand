extern char Snd[];
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void ResetColorAnim__12CustomIDWork(void *);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLT1Us(char *, int, int, unsigned short);
extern "C" void SetColorAnimNormal__12CustomIDWorkG3COLUs(void *, unsigned, unsigned);
extern "C" void func_001D51B8(char *, int, int);

#define B(o) (*(unsigned char *)(self + (o)))
#define W(o) (*(int *)(self + (o)))

#ifdef NONMATCHING
// DRAFT: GAME 0x1BE068 - 64 words; 288 vs 300 bytes; Tried: switch with fallthrough (62 words, best, source lost); if-chain with goto case1 (2, 64 words); if-chain with live constant one (3, 64 words)
extern "C" void func_001BE068(char *self)
{
    int one = 1;
    int st = B(0x2F5);
    if (st == one) goto case1;
    if (st < 2) {
        if (st != 0) return;
        {
            char *p;
            SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 2, 8, self, 0, 0, 0, 0);
            p = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(p + 0xC) + (int)p, 0, 0, 0, 0, 0.0f);
            B(0x2F5) = one;
            B(0x2F6) = 0;
            B(0x2F7) = 0;
        }
        goto case1;
    }
    if (st == 2) {
        int t = W(0x900);
        int v = t - 1;
        if (t < 0) {
            B(0x2F6) = 0;
            B(0x2F5) = 3;
            B(0x2F7) = 0;
            v = W(0x900) - 1;
        }
        W(0x900) = v;
        return;
    }
    if (st == 3) {
        int v = W(0x5B0);
        B(0x2F4) = 2;
        v = v | 1;
        B(0x2F5) = 0;
        W(0x5B0) = v;
        B(0x2F6) = 0;
        B(0x2F7) = 0;
    }
    return;
case1:
    if (moveMotion__FP8cObjBase(self) != 0) {
        W(0x900) = 0xA;
        B(0x2F5) = 2;
        B(0x2F7) = 0;
        B(0x2F6) = 0;
    }
}
#endif

extern "C" void setMeshDispFromLayer__7cOmBaseUib(char *, unsigned, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1C28A0 - 63 words; 284 vs 300 bytes; frame matches; second setMesh call loads a0/a1 in the wrong order; tried: volatile int n (63, best), plain int n (62, 264 bytes, frame 0x20), unsigned char n (62), counters before calls (72)
#define ENT(i) (*(char **)(*(char **)(self + 0x278) + ((i) << 2)))
extern "C" int func_001C28A0(char *self)
{
    int i;
    int j;
    int z = 0;
    volatile int n;
    *(short *)(self + 0x610) = 0x1E;
    setMeshDispFromLayer__7cOmBaseUib(self, 0, 1);
    setMeshDispFromLayer__7cOmBaseUib(self, 0x40, 0);
    i = 1;
    if (!(i < *(signed char *)(self + 0x60C))) return 1;
    n = B(0x2B4);
    if (!(i < n)) return 1;
    j = 1;
    do {
        int c = (j < z) ? 0 : (i < n);
        char *a = c ? ENT(i) : 0;
        *(int *)(a + 0x154) |= 8;
        int c2 = (j < z) ? 0 : (i < B(0x2B4));
        char *b = c2 ? ENT(i) : 0;
        *(int *)(b + 0x154) |= 0x10;
        i++;
        j++;
        if (!(i < *(signed char *)(self + 0x60C))) break;
        n = B(0x2B4);
    } while (i < n);
    return 1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1D6A70 - 66 words; 336 vs 336 bytes; best of 7: mode-2 tail via goto (66); mode-1 tail via goto (76, reverted); mode!=1 nesting (77); signed int mode (76). Remaining: dispatch beq target and mode-1 constant/and order
#define PACK(x) ((((((x) & 0xFF00FFFFu) | 0x800000u) & 0xFFFF00FFu) | 0x8000u) & 0xFFFFFF00u | 0x80u) & 0xFFFFFFu
extern "C" void func_001D6A70(char *self, int mode0, unsigned a2, unsigned a3, unsigned a4)
{
    int mode = mode0 & 0xFF;
    if (mode != 1) {
        if (mode < 2) {
            if (mode == 0) {
                ResetColorAnim__12CustomIDWork(self + 0xEE8);
                func_001D51B8(self, 0x1E, 0);
            }
            return;
        }
        if (mode != 2) return;
        goto mode2;
    }
    {
        unsigned p1 = PACK(a3);
        unsigned p2 = PACK(a2) | 0x40000000u;
        SetColorAnimNormal__12CustomIDWorkG3COLT1Us(self + 0xEE8, p1, p2, 2);
        func_001D51B8(self, 0x1E, 1);
        return;
    }
mode2:
    SetColorAnimNormal__12CustomIDWorkG3COLUs(self + 0xEE8, PACK(a4), 2);
    func_001D51B8(self, 0x1E, 1);
}
#endif
