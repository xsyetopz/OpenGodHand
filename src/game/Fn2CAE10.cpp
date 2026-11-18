struct V4 {
    float x, y, z, w;
};

extern "C" int func_002C0A98(char *, V4 *, int);

// FUNCTION: GAME 0x2CAE10
extern "C" int func_002CAE10(char *self, float *pos)
{
    char *p = *(char **)(self + 0x20);
    if (p == 0)
        return 0;
    if (*(float *)(p + 4) != 1.1f) {
        *(char **)(self + 0x20) = 0;
        return 0;
    }
    int r = p[9] != 0;
    if (*(unsigned char *)(p + 8) == 0)
        return r;
    V4 v;
    v.x = pos[0];
    v.y = pos[1];
    v.z = pos[2];
    v.w = 1.0f;
    int i = 0;
    char *e = p + *(unsigned char *)(p + 8) * 0x38 - 0x18;
    if (*(unsigned char *)(p + 8) != 0) {
        do {
            if (*(int *)(e + 0x34) == 0 && func_002C0A98(e, &v, 1) != 0)
                return *(int *)(e + 0x2C) != 0;
            i++;
            e -= 0x38;
        } while (i < *(unsigned char *)(*(char **)(self + 0x20) + 8));
    }
    return r;
}
