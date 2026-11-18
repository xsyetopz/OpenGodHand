// Object state-machine and init units in 0x14E000-0x160000.
extern "C" int func_0031ED08(float);
extern "C" int setMotionInfo__FP8cObjBaseUiUiUiffUs(char *, int, int, int, float, float, unsigned short);
extern "C" int moveMotion__FP8cObjBase(char *);
extern "C" void addNullSpeed__8cObjBasef(char *, float);
extern "C" void *memset(void *, int, unsigned);
extern "C" void func_0015FCB8(char *, char *, int);

// FUNCTION: GAME 0x14EAD8
extern "C" void func_0014EAD8(char *s)
{
    switch ((unsigned char)s[0x2F6]) {
    case 0:
        setMotionInfo__FP8cObjBaseUiUiUiffUs(s, *(int *)(s + 0x428), *(int *)(s + 0x42C), func_0031ED08(*(float *)(s + 0x438)), *(float *)(s + 0x440), *(float *)(s + 0x430), *(unsigned short *)(s + 0x434));
        s[0x2F6] = (unsigned char)s[0x2F6] + 1;
    case 1:
        if (moveMotion__FP8cObjBase(s)) s[0x2F6]++;
        break;
    case 2:
        moveMotion__FP8cObjBase(s);
        break;
    }
}

// FUNCTION: GAME 0x14EC88
extern "C" void func_0014EC88(char *s)
{
    switch ((unsigned char)s[0x2F6]) {
    case 0:
        setMotionInfo__FP8cObjBaseUiUiUiffUs(s, *(int *)(s + 0x428), *(int *)(s + 0x42C), func_0031ED08(*(float *)(s + 0x438)), *(float *)(s + 0x440), *(float *)(s + 0x430), *(unsigned short *)(s + 0x434));
        s[0x2F6] = (unsigned char)s[0x2F6] + 1;
    case 1:
        if (moveMotion__FP8cObjBase(s)) s[0x2F6]++;
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    case 2:
        moveMotion__FP8cObjBase(s);
        addNullSpeed__8cObjBasef(s, 1.0f);
        break;
    }
}

// FUNCTION: GAME 0x15FD98
extern "C" void func_0015FD98(char *s)
{
    memset(s, 0, 0x48);
    char *p = s + 4;
    int i = 8;
    func_0015FCB8(s, s + 0x60, 0);
    func_0015FCB8(s, s + 0x310, 1);
    func_0015FCB8(s, s + 0x620, 2);
    func_0015FCB8(s, s + 0x730, 3);
    func_0015FCB8(s, s + 0x880, 4);
    func_0015FCB8(s, s + 0x9C0, 5);
    func_0015FCB8(s, s + 0xBA0, 8);
    func_0015FCB8(s, s + 0xC40, 7);
    func_0015FCB8(s, s + 0xAE0, 6);
    for (; i >= 0; i--) {
        char *o = *(char **)p;
        if (o) {
            char *vt = *(char **)(o + 0x70);
            ((void (*)(char *))*(void **)(vt + 0xC))(o + *(short *)(vt + 8));
        }
        p += 8;
    }
    *(short *)(s + 0x50) = 0;
    *(int *)(s + 0x48) = -1;
    *(int *)(s + 0xED0) = 0;
    s[0xED4] = 0;
    int m = -1;
    int j = 8;
    int *q = (int *)(s + 0xF08);
    do {
        *q = m;
        q--;
    } while (--j >= 0);
    s[0xF15] = 0;
}
