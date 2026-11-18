// Medium units in 0x200000-0x280000.

extern char Snd[];
extern "C" void func_002CBA48(void *, int, int, void *, int, int, int, int);
extern "C" void func_002A8578(float, void *, char *, char *, int, int, int);
extern "C" int func_00157C18(void *);
extern "C" void func_0014F9F0(void *, float);
extern "C" void func_0014F928(void *, float);
extern "C" char *func_002DDAB0(float, void *, int);
extern "C" void func_002A7498(float, void *, void *);
extern "C" float func_001F7EB0(void *, void *);
extern "C" void *func_002DB6B0();
extern "C" void func_0026E988(float, void *, void *, int, int);

// FUNCTION: GAME 0x27C790
extern "C" void func_0027C790(char *self)
{
    unsigned char st = *(unsigned char *)(self + 0x2F6);
    switch (st) {
    case 0: {
        func_002CBA48(Snd, 1, 12, self, 0, 0, 0, 0);
        st = *(unsigned char *)(self + 0x2F7);
        if (st) {
            char *p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x40) + (int)p), (char *)(*(int *)(p + 0x44) + (int)p), 0, 0, 0);
        } else {
            char *p = *(char **)(self + 0x304);
            func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x38) + (int)p), (char *)(*(int *)(p + 0x3C) + (int)p), 0, 0, 0);
        }
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (func_00157C18(self)) {
            *(unsigned char *)(self + 0x2F4) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
            *(unsigned char *)(self + 0x2F7) = 0;
        }
    }
}

// FUNCTION: GAME 0x277B18
extern "C" void func_00277B18(char *self)
{
    char *o = func_002DDAB0(15.0f, *(void **)(self + 0xF0), 0);
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0: {
        char *p = *(char **)(self + 0x304);
        func_002A8578(0.0f, self, (char *)(*(int *)(p + 0x14) + (int)p), (char *)(*(int *)(p + 0x18) + (int)p), 3, 0, 0);
        (*(unsigned char *)(self + 0x2F6))++;
    }
    case 1:
        if (o) {
            func_002A7498(*(float *)(self + 0x5A8) * 0.39269909f, self, *(void **)(o + 0xF0));
            if (func_001F7EB0(*(void **)(o + 0xF0), *(void **)(self + 0xF0)) < 0.25f) {
                *(unsigned char *)(self + 0x2F4) = 0;
                *(unsigned char *)(self + 0x2F5) = 3;
                goto c;
            }
            goto tail;
        }
        *(unsigned char *)(self + 0x2F4) = 0;
        *(unsigned char *)(self + 0x2F5) = 0;
    c:
        *(unsigned char *)(self + 0x2F6) = 0;
        *(unsigned char *)(self + 0x2F7) = 0;
    tail:
        func_00157C18(self);
        func_0014F9F0(self, 1.0f);
        func_0014F928(self, 1.0f);
    }
}

// FUNCTION: GAME 0x26E588
// Jump table at 0x445970 (case range 0x208-0x27E) links with this object.
extern "C" int func_0026E588(char *self)
{
    if (0.0f < *(float *)(self + 0x16C0))
        return 0;
    if (*(int *)(self + 0x1644) & 0x40000000)
        return 0;
    switch (*(int *)(self + 0x564)) {
    case 0x208:
    case 0x209:
    case 0x20B:
    case 0x20E:
    case 0x211:
    case 0x213:
    case 0x214:
    case 0x215:
    case 0x217:
    case 0x21C:
    case 0x21F:
    case 0x220:
    case 0x221:
    case 0x222:
    case 0x223:
    case 0x250:
    case 0x251:
    case 0x252:
    case 0x256:
    case 0x260:
    case 0x264:
    case 0x265:
    case 0x26A:
    case 0x270:
    case 0x271:
    case 0x272:
    case 0x273:
    case 0x274:
    case 0x275:
    case 0x276:
    case 0x278:
    case 0x279:
    case 0x27E:
        return 0;
    default:
        break;
    }
    if (*(float *)(self + 0x618) < 16.0f)
        return 0;
    if (*(int *)(self + 0x16EC) > 0)
        return 0;
    char *s1 = self + 0x1660;
    char *o = (char *)func_002DB6B0();
    float d = func_001F7EB0(s1, *(void **)(o + 0xF0));
    float r = *(float *)(self + 0x16C8);
    if (d < r * r)
        return 0;
    *(unsigned *)(self + 0x16D0) &= 0xFFFFFFFDu;
    func_0026E988(450.0f, self, s1, 6, 0);
    *(unsigned char *)(self + 0x2F5) = 0x13;
    *(unsigned char *)(self + 0x2F4) = 0;
    *(unsigned char *)(self + 0x2F6) = 0;
    *(unsigned char *)(self + 0x2F7) = 0;
    return 1;
}
