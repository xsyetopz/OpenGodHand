// COMPILER: ee-gcc2.96
int func_0036A1D8(int, int *);
void func_0036A238(int, int *, int *, int *);
int func_0035A1C8(char *, int);
int func_0034C7B0(char *, int);
void func_0034DD70(char *, int);
void func_00352F40(char *, int, int);
void func_00353060(char *, int, int, int);
void func_00353098(char *, char *);
void *memcpy(void *, const void *, unsigned);

// FUNCTION: GAME 0x352E10
int func_00352E10(char *a, int b, int c, int d)
{
    int buf[4];
    char *s2 = a + 0x90C;
    char *s3 = *(char **)(a + 0x1FC0);
    if (*(int *)(s2 + 0x10) != 0) return 0;
    {
        if (func_0036A1D8(b, buf)) {
            func_0034DD70(a, 0xFF000F16);
            return;
        }
        func_0036A238(b, &buf[1], &buf[2], &buf[3]);
        if (func_0035A1C8(a, 0x3C) == 0) {
            *(int *)(s3 + 0x114) = 0;
        } else {
            int k = func_0034C7B0(a, 1);
            int t = buf[3];
            if (t == -1) {
                t = buf[1];
                buf[3] = t;
            }
            *(int *)(s3 + 0x114) = t < k ? t : k;
        }
        func_00352F40(a, buf[0], d);
        func_00353060(s2, buf[0], c, buf[1]);
        func_00353098(a, s2);
    }
}

// FUNCTION: GAME 0x3569E0
int func_003569E0(char *a, int b, char *c, int d, char *e, int f, char *g, int h)
{
    int fp = f + h;
    int s3;
    if (b + d < fp) return 0;
    if (f >= b) {
        memcpy(a, e, b);
        memcpy(c, e + b, f - b);
        memcpy(c + f - b, g, h);
    } else {
        s3 = b - f;
        if (h >= s3) {
            memcpy(a, e, f);
            memcpy(a + f, g, s3);
            memcpy(c, g + b - f, h - s3);
        } else {
            memcpy(a, e, f);
            memcpy(a + f, g, h);
        }
    }
    return fp;
}
