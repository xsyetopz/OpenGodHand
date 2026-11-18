// Small functions from 0x140000-0x150000.
extern char *IDManager;
extern char D_0041EA90[];
extern "C" void func_001415E8(char *, int);
extern "C" int initialize__7cIDBase7eIdData5eIdNo(char *, int, int);
extern "C" int func_002ACE28(char *, int);
extern "C" char *getMeshPtr__6cModeli(char *, int);
extern "C" void func_00155D98(char *, int, int);
extern "C" void func_00155D60(char *, int, int);
extern "C" void free__5cHeapPv(int, char *);
extern "C" void removeMesh__6cModel(char *);
extern "C" void func_00149E60(char *);
extern "C" void _$_12cBoundingBox(char *, int);
extern "C" void func_00150048(char *, int);

// FUNCTION: GAME 0x140DE0
extern "C" void func_00140DE0(char *s)
{
    char *p = s + 0x22F4;
    for (int i = 0x10; i >= 0; i--, p += 12) {
        char *o = *(char **)p;
        if (o) {
            char *vt = *(char **)(o + 0x80);
            ((void (*)(char *))*(int *)(vt + 0x1C))(o + *(short *)(vt + 0x18));
        }
    }
    s[0x23BC] = 0;
    func_001415E8(s, 0);
}

// FUNCTION: GAME 0x143B70
extern "C" void func_00143B70(char *s)
{
    *(int *)(s + 0x90) = 0;
    initialize__7cIDBase7eIdData5eIdNo(s, 1, 0xF);
    initialize__7cIDBase7eIdData5eIdNo(s + 0x500, 1, 0xE);
    initialize__7cIDBase7eIdData5eIdNo(s + 0x550, 1, 0x15);
    initialize__7cIDBase7eIdData5eIdNo(s + 0x4B0, 1, 0xD);
    *(int *)(s + 0x94) = func_002ACE28(IDManager, 0x36);
}

// FUNCTION: GAME 0x14D700
extern "C" void func_0014D700(char *s, int a, int b)
{
    for (char *m = getMeshPtr__6cModeli(s, 0); m; m = *(char **)(m + 0x404))
        func_00155D98(m, a, b);
}

// FUNCTION: GAME 0x14D768
extern "C" void func_0014D768(char *s, int a, int b)
{
    for (char *m = getMeshPtr__6cModeli(s, 0); m; m = *(char **)(m + 0x404))
        func_00155D60(m, a, b);
}

// FUNCTION: GAME 0x1496C0
extern "C" void func_001496C0(char *s, int f)
{
    *(char **)(s + 0x214) = D_0041EA90;
    char *m = *(char **)(s + 0x238);
    if (m) {
        free__5cHeapPv(*(int *)(m - 0x20), m);
    }
    removeMesh__6cModel(s);
    func_00149E60(s);
    _$_12cBoundingBox(s + 0x260, 2);
    func_00150048(s, f);
}

struct B14B640 { char c[24]; };
extern "C" int getMeshNum__C6cModel(char *);
extern "C" void func_001F91D0(char *, char *);

// FUNCTION: GAME 0x14B640
extern "C" void func_0014B640(char *s, int a, char *b)
{
    int n = getMeshNum__C6cModel(s);
    if (n == 0) *(int *)(s + 0x25C) = a;
    else *(int *)(getMeshPtr__6cModeli(s, n - 1) + 0x404) = a;
    int c = (unsigned char)s[0x2B1] + 1;
    s[0x2B1] = c;
    if ((c & 0xFF) == 1) *(B14B640 *)(s + 0x260) = *(B14B640 *)b;
    else func_001F91D0(s + 0x260, b);
}

extern unsigned short D_003BD70C;
extern "C" void func_00144C90(char *);

// FUNCTION: GAME 0x144B50
extern "C" void func_00144B50(char *s)
{
    unsigned short i = 0;
    do {
        initialize__7cIDBase7eIdData5eIdNo(s + 0x100 + i * 0x50, 1, 5);
        i = i + 1;
    } while (i < 5);
    initialize__7cIDBase7eIdData5eIdNo(s + 0x430, 1, 0x19);
    initialize__7cIDBase7eIdData5eIdNo(s + 0x480, 1, 0x1A);
    *(unsigned *)(s + 0x364) = 0x80808080;
    *(unsigned *)(s + 0x368) = 0x80808080;
    func_00144C90(s);
    *(short *)(s + 0x41E) = 0;
    *(short *)(s + 0x420) = 0;
    *(int *)(s + 0x90) = 0;
    *(unsigned short *)(s + 0x4D0) = D_003BD70C;
}

extern "C" void func_002AA3D8(char *, int);
extern "C" char *getIDWork__7cIDBasei(char *, int);

// FUNCTION: GAME 0x1468B0
extern "C" void func_001468B0(char *s)
{
    unsigned short i;
    s[0x79] = 0; s[0x7A] = 0; s[0x7B] = 0; s[0x7C] = 0;
    for (i = 0; i < 4; i++) func_002AA3D8(s, i);
    *(float *)(getIDWork__7cIDBasei(s, 0) + 0x3C) = -50.0f;
    for (i = 0; i < 4; i++) func_002AA3D8(s + 0xA0, i);
    *(float *)(getIDWork__7cIDBasei(s + 0xA0, 0) + 0x3C) = -50.0f;
    *(short *)(s + 0x102) = 0x5A;
}

extern "C" int func_0031ED08(float);
extern "C" int setMotionInfo__FP8cObjBaseUiUiUiffUs(char *, int, int, int, float, float, unsigned short);
extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void func_0014E818(char *, char *, float);
extern "C" void addNullSpeed__8cObjBasef(char *, float);

// FUNCTION: GAME 0x14EB90
extern "C" void func_0014EB90(char *s)
{
    switch ((unsigned char)s[0x2F6]) {
    case 0:
        setMotionInfo__FP8cObjBaseUiUiUiffUs(s, *(int *)(s + 0x428), *(int *)(s + 0x42C), func_0031ED08(*(float *)(s + 0x438)), *(float *)(s + 0x440), *(float *)(s + 0x430), *(unsigned short *)(s + 0x434));
        s[0x2F6] = (unsigned char)s[0x2F6] + 1;
    case 1:
        if (moveMotion__FP8cObjBase(s)) s[0x2F6]++;
        func_0014E818(s, s + 0x4C0, *(float *)(s + 0x4B8));
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    case 2:
        moveMotion__FP8cObjBase(s);
        func_0014E818(s, s + 0x4C0, *(float *)(s + 0x4B8));
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    }
}
