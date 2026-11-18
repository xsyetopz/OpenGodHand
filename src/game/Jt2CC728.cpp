// Sound-object setup from a parameter block; sole switch of 0x2CC728.
extern char Snd[];
extern "C" int GetBgmData__4cSndi(void *, int);
extern "C" int func_002D0598(void *, unsigned);
extern "C" int func_002D0578(void *, unsigned);
extern "C" void func_002CC628(void *);
extern "C" void func_002CC5C0(void *);

// FUNCTION: GAME 0x2CC728
extern "C" int func_002CC728(char *self, char *a1, unsigned *src, int flag)
{
    *(char **)(self + 0x8C) = a1 + 0x80;
    *(int *)(self + 0xB8) = GetBgmData__4cSndi(Snd, (int)a1);
    *(unsigned *)(self + 0x90) = src[0];
    unsigned k = src[1];
    *(unsigned *)(self + 0x94) = k;
    unsigned u = src[2];
    *(int *)(self + 0x98) = flag;
    *(unsigned *)(self + 0x9C) = u;
    switch (k) {
    case 3:
        *(unsigned *)(self + 0xAC) = ((unsigned short *)src)[6];
        *(int *)(self + 0xA4) = func_002D0578(Snd, ((unsigned short *)src)[7]);
        break;
    case 2:
        *(int *)(self + 0xA8) = func_002D0598(Snd, ((unsigned short *)src)[6]);
        *(int *)(self + 0xA4) = func_002D0578(Snd, ((unsigned short *)src)[7]);
        break;
    case 1:
    case 4:
    case 5:
        *(unsigned short *)(self + 0xA0) = ((unsigned short *)src)[6];
        *(unsigned short *)(self + 0xA2) = ((unsigned short *)src)[7];
        break;
    case 0:
        *(unsigned *)(self + 0x94) = 0;
        return 0;
    default:
        break;
    }
    func_002CC628(self);
    func_002CC5C0(self);
    return 1;
}
