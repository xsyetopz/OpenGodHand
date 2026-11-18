extern "C" {
int func_002CDA38(void *);
int func_002CDFF0(void *, short, short, int, int);
void sceVu0CopyVector(void *, void *);
}

// FUNCTION: GAME 0x2CDE28
extern "C" int func_002CDE28(char *p, short a, short b, void *v, int e, int f)
{
    if (func_002CDA38(p) == 1)
        return 0;
    *(int *)(p + 0x38) = 0;
    *(int *)(p + 0x3C) = 0;
    if (v == 0) {
        *(int *)(p + 0x10) = 0;
        *(float *)(p + 0x4C) = 1.0f;
        *(int *)(p + 0x40) = 0;
        *(int *)(p + 0x44) = 0;
        *(int *)(p + 0x48) = 0;
    } else {
        *(int *)(p + 0x10) = 2;
        sceVu0CopyVector(p + 0x40, v);
        *(float *)(p + 0x44) = *(float *)(p + 0x44) + 1.3f;
    }
    return func_002CDFF0(p, a, b, e, f);
}
