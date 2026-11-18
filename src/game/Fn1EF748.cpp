extern "C" void func_001F0490(void *);
extern "C" void func_001F28F0(void *);
extern "C" void func_001F2990(void *);
extern "C" void func_001F3260(void *);
extern unsigned D_00747A24;

#ifdef NONMATCHING
// DRAFT: GAME 0x1EF748
// 41 words differ: original recomputes self+0x60 into v0, passes it and copies to s1 in the call delay slot; compiled CSEs it (196 vs 200 bytes); tried m2c nesting, temp var before/after call, assignment in argument.
extern "C" void func_001EF748(char *self)
{
    int st = *(int *)(self + 8);
    char *p;
    if (st != 1) {
        p = self + 0x60;
        if (st < 2) {
            if (st == 0) {
                func_001F3260(p = self + 0x60);
                *(int *)(self + 0x10) = 0x3C;
                *(int *)(self + 8) = *(int *)(self + 8) + 1;
            }
        }
    } else {
        int t = *(int *)(self + 0x10);
        int done;
        if (t != 0) {
            done = 0;
            *(int *)(self + 0x10) = t - 1;
        } else {
            done = 1;
        }
        p = self + 0x60;
        if (done & 0xFF) {
            D_00747A24 |= 8;
            *(int *)(self + 8) += 1;
        }
    }
    func_001F0490(self);
    func_001F28F0(p);
    func_001F2990(p);
}
#endif
