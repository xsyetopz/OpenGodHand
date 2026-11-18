extern "C" {
char *func_002C30C0(void *);
char *func_002C30C8(void *, char *);
void func_002C1D68(void *, void *, void *);
int HitCheck__C5cAreaRC4cVec(void *, void *);
void getCenterPos__10cSceAtUnitR4cVec(void *, void *);

// FUNCTION: GAME 0x2C2638
int func_002C2638(void *self, void *pos, void *center, float *out)
{
    char area[0x30];
    char *u = func_002C30C0(self);
    while ((u = func_002C30C8(self, u)) != 0) {
        if (((u[0x34] ^ 1) & 1) == 0 && (unsigned char)u[0x35] == 0xC) {
            func_002C1D68(self, area, u);
            if (HitCheck__C5cAreaRC4cVec(area, pos) == 1) {
                if (center) getCenterPos__10cSceAtUnitR4cVec(u, center);
                if (out) *out = *(float *)(u + 0x10);
                return 1;
            }
        }
    }
    return 0;
}
}
