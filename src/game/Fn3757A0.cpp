extern "C" void func_00372C68(char *);
extern char D_0076A600[];

#ifdef NONMATCHING
// DRAFT: GAME 0x3757A0
// 5 words differ: base pointer lands in s1 (original keeps it in v0 and copies to s1, s0=v0+0x18C in beqz delay); tried direct D_ refs, base/end copies, m2c loop shape
extern "C" void func_003757A0(int a, int b)
{
    if (b == 0xFFFF) {
        if (a) {
            char *p = D_0076A600;
            int i = 2;
            do {
                i--;
                func_00372C68(p);
                p += 0x84;
            } while (i != -1);
            return;
        }
        char *base = D_0076A600;
        char *e = base + 0x18C;
        if (base && e != base) {
            char *end = base;
            char *q = e;
            do {
                q -= 0x84;
                char *vt = *(char **)(q + 0x80);
                ((void (*)(char *, int))*(int *)(vt + 0xC))(q + *(short *)(vt + 8), 0);
            } while (q != end);
        }
    }
}
#endif
