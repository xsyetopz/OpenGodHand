extern "C" void func_0012F600(void *, int *, int);

struct Grid {
    char _p0[0x18];
    char *data;
    char _p1[0x64 - 0x1C];
    unsigned w;
    unsigned h;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x12F4C8
// regalloc differs: original spills x1/y0 to sp10/sp14 and i*w*h, j*h+a to sp0/sp4; mine spills args to sp0-8; one 8-arg nested-loop form tried.
extern "C" void func_0012F4C8(Grid *g, unsigned x0, unsigned x1, unsigned y0, unsigned y1, unsigned z0, unsigned z1, int arg)
{
    for (unsigned i = x0; i <= x1; i++) {
        int a = i * g->w * g->h;
        for (unsigned j = y0; j <= y1; j++) {
            int b = j * g->h + a;
            for (unsigned k = z0; k <= z1; k++) {
                int *p = (int *)(g->data + (b + k) * 8);
                if (*p != -1)
                    func_0012F600(g, p, arg);
            }
        }
    }
}
#endif
