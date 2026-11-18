extern "C" void func_0015D168(float *, int, int, int, int, int, int *, int, int);
extern int *D_007479F4;

// FUNCTION: GAME 0x2B1F80
extern "C" void func_002B1F80(int *self, int idx, int a2, float x0, float y0, float x1, float y1)
{
    int sp10[20];
    float sp60[8];
    int *e = (int *)(self[1] + idx * 0x14);
    int k = e[0];
    if (k == -1)
        k = self[0];
    int p = D_007479F4[k] + (int)D_007479F4;
    sp10[0] = 1;
    ((float *)sp10)[1] = ((float *)e)[1];
    ((float *)sp10)[2] = ((float *)e)[2];
    ((float *)sp10)[3] = ((float *)e)[3];
    ((float *)sp10)[4] = ((float *)e)[4];
    sp60[0] = x0;
    sp60[1] = y0;
    sp60[4] = x1;
    sp60[5] = y1;
    sp60[2] = 65535.0f;
    sp60[3] = 1.0f;
    sp60[6] = 65535.0f;
    sp60[7] = 1.0f;
    func_0015D168(sp60, a2, 1, p, 0x3B00, 0x1CF0, sp10, 6, 2);
}
