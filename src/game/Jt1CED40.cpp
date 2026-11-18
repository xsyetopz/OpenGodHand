// Jump-table unit; this file holds no other .rodata.
extern char g_EmManage[];
extern "C" float GetSpeedRate__9cEmManage(char *);

// DRAFT: GAME 0x1CED40 (prologue: original stores the byte to sp+0 before the slt test; whole body then shifts)
#ifdef NONMATCHING
extern "C" void func_001CED40(char *self)
{
    float sp = GetSpeedRate__9cEmManage(g_EmManage);
    int n = *(unsigned char *)(self + 0x2B4);
    volatile int dummy = n;
    char *a1 = 1 < n ? *(char **)(*(char **)(self + 0x278) + 4) : 0;
    switch (*(unsigned char *)(self + 0x2F6)) {
    case 0:
        *(short *)(self + 0x56A) = 0;
        *(unsigned char *)(self + 0x2F6) += 1;
        *(float *)(self + 0x24C) = 0;
    case 1: {
        float f = *(float *)(self + 0x24C) + sp * 0.1f;
        *(int *)(self + 0x250) |= 0x10;
        *(float *)(self + 0x24C) = f;
        if (f > 1.0f) {
            *(float *)(self + 0x24C) = 1.0f;
            *(unsigned char *)(self + 0x2F6) += 1;
            *(int *)(self + 0x250) &= ~0x10;
        }
        break;
    }
    case 2:
        *(float *)(self + 0x674) = 30.0f;
        *(unsigned char *)(self + 0x2F6) += 1;
    case 3:
        if (a1 != 0) {
            **(float **)(a1 + 0xD0) += sp * 0.05f;
            *(float *)(self + 0x674) -= sp;
            if (*(float *)(self + 0x674) <= 0.0f)
                *(unsigned char *)(self + 0x2F6) += 1;
        } else
            *(unsigned char *)(self + 0x2F6) += 1;
        break;
    case 4:
        *(float *)(self + 0x674) = 60.0f;
        *(unsigned char *)(self + 0x2F6) += 1;
    case 5:
        *(float *)(self + 0x674) -= sp;
        if (*(float *)(self + 0x674) <= 0.0f)
            *(unsigned char *)(self + 0x2F6) += 1;
        break;
    case 6:
        *(unsigned char *)(self + 0x2F6) += 1;
    case 7: {
        float f = *(float *)(self + 0x24C) - sp * 0.1f;
        *(int *)(self + 0x250) |= 0x10;
        *(float *)(self + 0x24C) = f;
        if (f < 0.0f) {
            *(float *)(self + 0x24C) = 0.0f;
            *(unsigned char *)(self + 0x2F4) = 1;
            *(unsigned char *)(self + 0x2F7) = 0;
            *(unsigned char *)(self + 0x2F5) = 0;
            *(unsigned char *)(self + 0x2F6) = 0;
        }
        break;
    }
    }
}
#endif
