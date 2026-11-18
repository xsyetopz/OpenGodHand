// Mid-size unnamed units in 0x2C0000-0x2E0000.
extern "C" void func_002C4DE0(void *);
extern "C" void func_002C3820(void *);
extern "C" void func_002D56A8(char *);
extern "C" void *GetSeData__4cSndi(void *, int);
extern "C" void *GetBgmData__4cSndi(void *, int);
extern "C" void func_002CF440(void *);
extern "C" void func_002D0068(void *);
extern int D_0044CE48[];
extern "C" int func_002D3210(void *);
extern "C" void func_002CD548(void *, unsigned, unsigned, float);

// FUNCTION: GAME 0x2C3858
extern "C" void func_002C3858(char *self)
{
    func_002C4DE0(self);
    func_002C3820(self);
    func_002D56A8(self + 0x1C);
}

// FUNCTION: GAME 0x2CA558
extern "C" void func_002CA558(void *snd)
{
    for (int i = 0; i < 0x34; i++)
        func_002CF440(GetSeData__4cSndi(snd, i));
    for (int i = 0; i < 2; i++)
        func_002D0068(GetBgmData__4cSndi(snd, i));
}

// FUNCTION: GAME 0x2CB5B8
extern "C" int func_002CB5B8(void *snd)
{
    for (unsigned i = 0; i < 12; i++) {
        if (*(int *)((char *)GetSeData__4cSndi(snd, D_0044CE48[i]) + 0x3C) == -1)
            return D_0044CE48[i];
    }
    return -1;
}

// FUNCTION: GAME 0x2D14F8
extern "C" void func_002D14F8(char *self, float f)
{
    char *p = *(char **)(self + 0x18);
    while (p) {
        if (*(int *)(p + 0xB0) != 2 && (*(unsigned *)(p + 0x98) & 0x100000))
            func_002CD548(p, 0x400000, 0x100000, f);
        p = *(char **)(p + 0x88);
    }
}

// FUNCTION: GAME 0x2D3110
extern "C" char *func_002D3110(char *self)
{
    char *s = self + 0x40;
    char *p = *(char **)self;
    if (p) {
        s = p;
        int i = 1;
        while (i < 16) {
            s += 0xC0;
            if (!(s < self + 0xC40))
                s = self + 0x40;
            if (!func_002D3210(s))
                break;
            i++;
        }
    }
    return s;
}

// FUNCTION: GAME 0x2D5610
extern "C" int func_002D5610(char *self, int idx)
{
    if (idx < 0) {
        unsigned short n = *(unsigned short *)(self + 0xC);
        if (n) {
            self = *(char **)self + 0xC;
            idx = 0;
            do {
                if (!*(unsigned short *)self)
                    return idx;
                idx++;
                self += 0x58;
            } while (idx < n);
        }
        return -1;
    }
    if (idx < *(unsigned short *)(self + 0xC)) {
        char *b = *(char **)self;
        return *(unsigned short *)(b + idx * 0x58 + 0xC) ? -1 : idx;
    }
    return -1;
}
