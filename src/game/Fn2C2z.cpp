struct Area { char b[0x30]; };
extern "C" char *func_002C30C0(char *);
extern "C" char *func_002C30C8(char *, char *);
extern "C" void func_002C1D68(char *, Area *, char *);
extern "C" int HitCheck__C5cAreaRC4cVec(Area *, void *);

// FUNCTION: GAME 0x2C2490
extern "C" int func_002C2490(char *self, void *pos, float *out)
{
    Area a;
    char *o = func_002C30C0(self);
    while ((o = func_002C30C8(self, o)) != 0) {
        if ((*(int *)(o + 0x34) & 0xFF01) == 0xB01) {
            func_002C1D68(self, &a, o);
            if (HitCheck__C5cAreaRC4cVec(&a, pos) == 1) {
                if (out) {
                    out[0] = *(float *)(o + 0x5C);
                    out[1] = *(float *)(o + 0x60);
                    out[2] = *(float *)(o + 0x64);
                }
                return 1;
            }
        }
    }
    return 0;
}

// FUNCTION: GAME 0x2C2568
extern "C" int func_002C2568(char *self, void *pos, float *out)
{
    Area a;
    char *o = func_002C30C0(self);
    while ((o = func_002C30C8(self, o)) != 0) {
        if (*(unsigned char *)(o + 0x35) == 0xD) {
            func_002C1D68(self, &a, o);
            if (HitCheck__C5cAreaRC4cVec(&a, pos) == 1) {
                if (out) {
                    out[0] = *(float *)(o + 0x5C);
                    out[1] = *(float *)(o + 0x60);
                    out[2] = *(float *)(o + 0x64);
                }
                return 1;
            }
        }
    }
    return 0;
}
