extern "C" {
char *getTexAddr__10cIDManager7eIdDataUi(int *, int, unsigned);
void func_002C5EA8(void *, char *, int, unsigned char, float, float, float, float, float, float, float, float,
                   float, float, float, float, int, float, float, float, int, float);
}
extern int **IDSys;

#ifdef NONMATCHING
// DRAFT: GAME 0x2AAEF0
extern "C" void func_002AAEF0(unsigned char *a, int *b, unsigned char *c)
{
    char *tex = *(char **)(c + 0x24);
    if (tex == 0)
        tex = getTexAddr__10cIDManager7eIdDataUi(*IDSys, c[0x8A], c[0x8B] + 1);
    int m = a[0x46];
    if (a[0x46] == 6)
        m = c[0x8D];
    b[10] = m;
    b[11] = *(short *)(c + 0x8E);
    float x = *(float *)(c + 0x68) * *(float *)(c + 0x58);
    float y = *(float *)(c + 0x6C) * *(float *)(c + 0x5C);
    func_002C5EA8(b, tex, *(int *)(c + 0x64), c[0x89], *(float *)(c + 0x50), *(float *)(c + 0x54), x, y,
                  *(float *)(c + 0x60), *(float *)(c + 0x70), *(float *)(c + 0x74), *(float *)(c + 0x78),
                  *(float *)(c + 0x7C), *(float *)(c + 0x80), x, y, 0, 1.0f, x, y, 0, 1.0f);
}
#endif
