struct M { char pad[0x2F4]; unsigned char a, b, c, d; };

// FUNCTION: GAME 0x281368
extern "C" void func_00281368(M *s, unsigned int m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 7; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 7; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 7; s->c = 4; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x2813F0
extern "C" void func_002813F0(M *s, unsigned int m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 10; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 10; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 10; s->c = 4; s->d = 0; break;
    case 3: s->a = 0; s->b = 10; s->c = 6; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x281500
extern "C" void func_00281500(M *s, unsigned char m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 16; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 16; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 16; s->c = 4; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x281560
extern "C" void func_00281560(M *s, unsigned char m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 17; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 17; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 17; s->c = 4; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x2832F8
extern "C" void func_002832F8(M *s, unsigned int m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 9; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 9; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 9; s->c = 4; s->d = 0; break;
    case 3: s->a = 0; s->b = 9; s->c = 6; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x2833D8
extern "C" void func_002833D8(M *s, unsigned char m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 13; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 13; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 13; s->c = 4; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x283438
extern "C" void func_00283438(M *s, unsigned char m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 14; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 14; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 14; s->c = 4; s->d = 0; break;
    }
}

// FUNCTION: GAME 0x2832A0
extern "C" void func_002832A0(M *s, unsigned int m)
{
    switch (m) {
    default:
    case 0: s->a = 0; s->b = 6; s->c = 0; s->d = 0; break;
    case 1: s->a = 0; s->b = 6; s->c = 2; s->d = 0; break;
    case 2: s->a = 0; s->b = 6; s->c = 4; s->d = 0; break;
    }
}

extern char D_00448E10[], D_00448E18[];
extern "C" int GetEm00CharIndex__F6eObjIdT0(int, int);
extern "C" void func_001595E8(void *, int);
extern "C" unsigned SearchData__FPUiPCcUi(unsigned *, const char *, unsigned);
extern "C" void setTextureExchange__6cModelPCUiPCvi(void *, unsigned, const void *, int);
extern "C" int setupModel__6cModelPC10SCR_HEADERUibT3(void *, unsigned, unsigned, int, int);
// FUNCTION: GAME 0x28AC58
extern "C" int func_0028AC58(char *self)
{
    int idx = GetEm00CharIndex__F6eObjIdT0(*(unsigned short *)(self + 0x2FE), *(int *)(self + 0x564));
    func_001595E8(self, 0);
    unsigned a = SearchData__FPUiPCcUi(*(unsigned **)(self + 0x304), D_00448E10, idx);
    unsigned b = SearchData__FPUiPCcUi(*(unsigned **)(self + 0x304), D_00448E18, idx);
    switch (*(int *)(self + 0x564)) {
    case 0x2A7:
        if (*(int *)(self + 0x155C) & 1) {
            *(unsigned *)(self + 0x254) |= 0x10000000;
            char *t = *(char **)(self + 0x304);
            setTextureExchange__6cModelPCUiPCvi(self, b, (char *)(*(int *)(t + 0x44) + (int)t), 0);
        }
        break;
    case 0x2A9:
        if (*(int *)(self + 0x155C) & 1) {
            *(unsigned *)(self + 0x254) |= 0x10000000;
            char *t = *(char **)(self + 0x304);
            setTextureExchange__6cModelPCUiPCvi(self, b, (char *)(*(int *)(t + 0x48) + (int)t), 0);
        }
        break;
    case 0x2AB:
        if (*(int *)(self + 0x155C) & 1) {
            *(unsigned *)(self + 0x254) |= 0x10000000;
            char *t = *(char **)(self + 0x304);
            setTextureExchange__6cModelPCUiPCvi(self, b, (char *)(*(int *)(t + 0x4C) + (int)t), 0);
        }
        if (*(int *)(self + 0x155C) & 2) {
            *(unsigned *)(self + 0x254) |= 0x10000000;
            char *t = *(char **)(self + 0x304);
            setTextureExchange__6cModelPCUiPCvi(self, b, (char *)(*(int *)(t + 0x4C) + (int)t), 1);
        }
        break;
    }
    if (b) return setupModel__6cModelPC10SCR_HEADERUibT3(self, a, b, 0, 0);
    return 0;
}
