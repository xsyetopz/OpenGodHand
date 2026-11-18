extern int D_00747A24[];
extern "C" void move__7cIDBase(void *);

// DRAFT: GAME 0x13E970 - 21 words: float regs (h=f3 vs f4, later f3/f5 swap); ternary and h+=r variants no better
#ifdef NONMATCHING
// DIVNOP: 0 2
extern "C" void func_0013E970(char *self)
{
    if (!*(int *)(self + 0x94)) return;
    char *o = *(char **)(self + 0x9C);
    if (!o) return;
    unsigned long fl = D_00747A24[0];
    unsigned long fb = (fl >> 3) & 1;
    if (fb) return;
    if (D_00747A24[2] < 0) return;
    if (!*(short *)(o + 0x548)) return;
    if (D_00747A24[0x18] & 0x80000) return;
    if (!(*(unsigned *)(self + 0xA0) & 0x40000000)) {
        float one = 1.0f;
        *(float *)(self + 0xA8) = one;
        *(float *)(self + 0xAC) = one;
        *(float *)(*(char **)(self + 0xC0) + 0x44) = one;
        *(float *)(*(char **)(self + 0xC8) + 0x44) = *(float *)(self + 0xA8);
        *(float *)(*(char **)(self + 0xC4) + 0x44) = *(float *)(self + 0xA8);
        *(float *)(*(char **)(self + 0xCC) + 0x44) = *(float *)(self + 0xA8);
        *(unsigned *)(self + 0xA0) |= 0x40000000;
    }
    char *p = *(char **)(self + 0x9C);
    float r = (float)*(short *)(p + 0x54A) / (float)*(short *)(p + 0x548);
    float h = r + r;
    if (*(float *)(self + 0xAC) != h) *(unsigned short *)(self + 0xBE) = 0x28;
    *(float *)(self + 0xB4) = h;
    if (*(unsigned short *)(self + 0xBE) == 0) {
        float a = *(float *)(self + 0xA8);
        *(float *)(self + 0xB8) = a;
        *(float *)(self + 0xA8) = a - (a - h) * 0.07f;
    } else {
        *(unsigned short *)(self + 0xBE) = *(unsigned short *)(self + 0xBE) - 1;
    }
    *(unsigned char *)(self + 0xBC) =
        (int)((*(float *)(self + 0xA8) - h) / (*(float *)(self + 0xB0) - h) * 128.0f);
    *(float *)(self + 0xAC) = h;
    float f3 = *(float *)(self + 0xB4), f4;
    if (1.0f < f3) { f4 = f3 - 1.0f; f3 = 1.0f; } else f4 = 0.0f;
    float f0 = *(float *)(self + 0xB8), f2;
    if (1.0f < f0) { f2 = f0 - 1.0f; f0 = 1.0f; } else f2 = 0.0f;
    *(float *)(*(char **)(self + 0xC0) + 0x44) = f4;
    *(float *)(*(char **)(self + 0xC8) + 0x44) = f3;
    *(float *)(*(char **)(self + 0xC4) + 0x44) = f2;
    *(float *)(*(char **)(self + 0xCC) + 0x44) = f0;
    *(unsigned char *)(*(char **)(self + 0xC4) + 0x4F) = *(unsigned char *)(self + 0xBC);
    *(unsigned char *)(*(char **)(self + 0xCC) + 0x4F) = *(unsigned char *)(self + 0xBC);
    if (*(unsigned short *)(self + 0xBE) == 0x27) *(float *)(self + 0xB0) = *(float *)(self + 0xA8);
    move__7cIDBase(self);
}
#endif
