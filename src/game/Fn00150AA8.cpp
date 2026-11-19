extern "C" void printf__FiiiiPCce(int, int, int, int, const char *, ...);
extern const char D_0041ECC0[];
extern const char D_0041ECD8[];
extern const char D_0041ED08[];
extern const char D_0041ED28[];
extern const char D_0041ED48[];
extern "C" char *getIDWork__7cIDBasei(char *, int);
extern "C" void move__7cIDBase(char *, int);
extern "C" void trans__7cIDBase(char *);
extern "C" void ResetColorAnim__12CustomIDWork(void *);
extern "C" void SetOffsetPosX__12CustomIDWorki(void *, int);
extern "C" void SetMoveOffsetPosX__12CustomIDWorkiiUs(void *, int, int, unsigned short);
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(char *, int, int, unsigned short);
extern "C" void func_001ED700(char *, int, int);
extern "C" int func_003807E0(int unused, short x);
extern "C" void func_0032A9F0(int, int);
extern unsigned short deciBelTbl[];

#ifdef NONMATCHING
// DRAFT: GAME 0x150AA8 - 47 words; p is built as self + (int)0x38000 to pull self into $s0; store order of 0x5C60..0x5C70 still differs
extern "C" void func_00150AA8(char *self)
{
    char *p = (char *)0x38000;
    p = self + (int)p;
    printf__FiiiiPCce(0x50, 0x58, 0, 5, D_0041ECC0, *(unsigned short *)(p + 0x78A8), 0x1C2);
    unsigned char a = *(unsigned char *)(p + 0x78AA);
    unsigned char b = *(unsigned char *)(p + 0x78AB);
    printf__FiiiiPCce(0x50, 0x60, 0, 5, D_0041ECD8, a, b, a + b, 0x140);
    printf__FiiiiPCce(0x50, 0x70, 0, 5, D_0041ED08, *(int *)(p + 0x5C60), *(int *)(p + 0x5C64));
    printf__FiiiiPCce(0x50, 0x78, 0, 5, D_0041ED28, *(int *)(p + 0x5C78), *(int *)(p + 0x5C7C));
    printf__FiiiiPCce(0x50, 0x80, 0, 5, D_0041ED48, *(int *)(p + 0x5C6C), *(int *)(p + 0x5C70));
    *(int *)(self + 0x34) = 0x2800;
    *(int *)(self + 0x38) = 0x1C20;
    *(int *)(p + 0x5C7C) = 0x1C20;
    *(int *)(p + 0x5C78) = 0x2800;
    *(unsigned short *)(p + 0x78A8) = 0;
    *(int *)(p + 0x5C60) = 0x2800;
    *(int *)(p + 0x5C64) = 0x1C20;
    *(int *)(p + 0x5C6C) = 0x2800;
    *(int *)(p + 0x5C70) = 0x1C20;
    *(int *)(self + 0x3C) = 0;
    char *q = self + 0x3DC50;
    for (int n = 0x96; n != 0; n--) {
        *(int *)(q - 0x12C0) = -1;
        *(int *)(q - 0x960) = -1;
        *(int *)q = -1;
        q -= 0x10;
    }
    p[0x78AB] = 0;
    p[0x78AA] = 0;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x16ACD0 - 4 words best (order i,k20,k256,w,obj,pv); 0x16AD2C/30 0x1A emitted after pv (orig before pv addiu); 0x16AD94/98 a0/a1 order in call-d setup (jal 0x16ADB8). Tried: obj-first 6w, i,w,obj,k20,k256,pv 4w, i,k20,k256,obj,w,pv 6w, k1a local 4w, k1a before floats 4w, inline pv 88w (frame change), pv load before call c 46w, pv at loop top 4w, a/b call swap 6w, hoisted i*0x1A temp 90w, pv before w in if-block 8w, float local before call c 80w (frame 372 vs 360)
extern "C" void func_0016ACD0(char *self)
{
    if (*(signed char *)(self + 0x5A) == 3) {
        unsigned short i = 0;
        const float k20 = 20.0f;
        const float k256 = 256.0f;
        short *w = (short *)(self + 0x260);
        char *obj = self + 0x210;
        int *pv = (int *)(self + 0x26C);
        do {
            if (*(short *)((int)w + (i << 1)) != 0) {
                char *a = getIDWork__7cIDBasei(obj, 0);
                char *b = getIDWork__7cIDBasei(obj, 0);
                *(float *)(a + 0x3C) = *(float *)(*(char **)(b + 0x1C) + 0xC) - (float)(int)(i * 0x1A);
                char *c = getIDWork__7cIDBasei(obj, 0);
                *(signed char *)(c + 0x4F) = (signed char)(int)((float)*(short *)((int)w + (i << 1)) / k20 * k256);
                char *d = getIDWork__7cIDBasei(obj, 0);
                int v = *(int *)((int)pv + (i << 2));
                *(int *)(d + 0x84) = v;
                move__7cIDBase(obj, v);
                trans__7cIDBase(obj);
            }
            i = i + 1;
        } while (i < 5);
    }
    trans__7cIDBase(self + 0xD0);
    trans__7cIDBase(self);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x1EDC28 - 85 words; case 2 reads $v1 from the caller (stand-in v1 = 0), so an exact match is probably not reachable
extern "C" void func_001EDC28(char *self, int a1, unsigned a2)
{
    unsigned v1 = 0;
    a1 = a1 & 0xFF;
    char *s0;
    if (a1 == 1) {
        s0 = self + 0x250;
        ResetColorAnim__12CustomIDWork(s0);
        SetOffsetPosX__12CustomIDWorki(s0, 0);
        func_001ED700(self, 4, 1);
        return;
    }
    if (a1 < 2) {
        s0 = self + 0x250;
        ResetColorAnim__12CustomIDWork(s0);
        SetOffsetPosX__12CustomIDWorki(s0, -0x190);
        func_001ED700(self, 4, 0);
        return;
    }
    if (a1 == 2) {
        s0 = self + 0x250;
        unsigned c1 = v1 & 0xFFFFFF;
        c1 |= 0x80000000;
        c1 &= 0xFF00FFFF;
        c1 |= 0x800000;
        c1 &= 0xFFFF00FF;
        c1 |= 0x8000;
        c1 &= 0xFFFFFF00;
        c1 |= 0x80;
        unsigned c2 = a2 & 0xFFFFFF00;
        c2 |= 0xD0;
        c2 &= 0xFFFF00FF;
        c2 |= 0xD000;
        c2 &= 0xFF00FFFF;
        c2 |= 0xD00000;
        c2 &= 0xFFFFFF;
        c2 |= 0x80000000;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(s0, (int)c1, (int)c2, 6);
        SetMoveOffsetPosX__12CustomIDWorkiiUs(s0, -0x190, 0, 0xC);
        func_001ED700(self, 4, 1);
        return;
    }
    if (a1 == 3) {
        SetMoveOffsetPosX__12CustomIDWorkiiUs(self + 0x250, 0, 0x190, 8);
        func_001ED700(self, 4, 1);
        return;
    }
    s0 = self + 0x250;
    ResetColorAnim__12CustomIDWork(s0);
    SetOffsetPosX__12CustomIDWorki(s0, -0x190);
    func_001ED700(self, 4, 0);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x381150 - 56 words; clamp arms use a shared temp for the store, remaining diff is branch and store placement in the 0x8000/0x2000 arm and the jal block
extern "C" void func_00381150(char *self, char *a1)
{
    int a3 = 1;
    if (*(int *)(a1 + 0x2C) & 2) {
        a3 = 10;
    }
    int off = *(unsigned char *)(self + 5) * 0x48 + 0x48;
    char *s0 = self + off;
    char *s1 = s0 + 0x10;
    int a2 = *(int *)(a1 + 0x38);
    if (a2 < 0) {
        int t;
        if (*(short *)(s0 + 4) >= a3 - 0x3C0) {
            t = (short)(*(unsigned short *)(s0 + 4) - a3);
        } else {
            t = -0x3C0;
        }
        *(short *)(s0 + 4) = (short)t;
        *(short *)(s0 + 6) = (short)func_003807E0((int)self, *(short *)(s0 + 4));
    } else if (a2 & 0x40000000) {
        int t;
        if (-a3 >= *(short *)(s0 + 4)) {
            t = (short)(*(unsigned short *)(s0 + 4) + a3);
        } else {
            t = 0;
        }
        *(short *)(s0 + 4) = (short)t;
        *(short *)(s0 + 6) = (short)func_003807E0((int)self, *(short *)(s0 + 4));
    } else {
        if (a2 & 0x8000) {
            if (*(short *)(s0 + 6) < a3) {
                *(short *)(s0 + 6) = 0;
            } else {
                *(short *)(s0 + 6) = (short)(*(unsigned short *)(s0 + 6) - a3);
            }
        } else {
            if (!(a2 & 0x2000)) {
                return;
            }
            if (0x7F - a3 < *(short *)(s0 + 6)) {
                *(short *)(s0 + 6) = 0x7F;
            } else {
                *(short *)(s0 + 6) = (short)(*(unsigned short *)(s0 + 6) + a3);
            }
        }
        *(unsigned short *)(s0 + 4) = deciBelTbl[*(short *)(s0 + 6)];
    }
    int v = *(int *)(s1 + 0x30);
    if (v != 0) {
        func_0032A9F0(v, *(short *)(s0 + 4));
    }
}
#endif
