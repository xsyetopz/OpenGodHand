typedef int (*Handler)(char *, char *);
extern Handler D_003F2188[];
extern Handler D_003F2628[];
extern char D_003F21E8[];
extern char D_003F2368[];
extern char D_003F24D0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x376438
// 44 words; original loop rotation (entry jumps to cnt test, body placed first) not reproduced; tried while(cnt==0), do-while, for(;;) (best)
extern "C" void func_00376438(char *self)
{
    for (;;) {
        if (*(int *)(self + 0x38) != 0) {
            *(int *)(self + 0x38) -= 1;
            return;
        }
        int r = D_003F2188[*(signed char *)(self + 0x3D)](self, self + *(signed char *)(self + 0x3C) * 0x14 + 0x40);
        if (*(unsigned short *)self & 0x1000)
            return;
        if (r == 0)
            *(char **)(self + 0x30) += 0x10;
        char *p = *(char **)(self + 0x30);
        int c = *(int *)p;
        *(int *)(self + 0x38) = c;
        *(char *)(self + 0x3C) = p[4];
        *(char *)(self + 0x3D) = p[5];
        if (c != 0) {
            *(int *)(self + 0x38) = c - 1;
            return;
        }
    }
}
#endif
