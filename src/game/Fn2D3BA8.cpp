extern "C" char *strcpy(char *, const char *);
extern "C" int func_001FF9C0(void *, void *, int, int);
extern "C" void func_002D3710(void *);
extern "C" int func_002D3C78(void *, int *);
extern "C" void func_00346078(int, int, int);
extern "C" void func_00347BC0(int, int, int);
extern char D_00580D40[];

static inline int isBusy(char *s)
{
    if (*(int *)s != 0)
        return 1;
    return 0;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2D3BA8
// 48 words; busy flag (v1 != 1) folded away by compiler, original keeps slti-less flag compare; tried inline fn, ternary, ++, early return
extern "C" int func_002D3BA8(char *self, int *name)
{
    if (isBusy(self) != 1) {
        char *buf = self + 0x64;
        strcpy(buf, (const char *)*name);
        if (func_002D3C78(self, name) == 0) {
            func_002D3710(self);
            return 0;
        }
        int r = func_001FF9C0(D_00580D40, buf, 0, 0);
        if (*(int *)(self + 0x3C) & 4)
            func_00347BC0(*(int *)self, 0, r);
        else
            func_00346078(*(int *)self, 0, r);
        return 1;
    }
    return 0;
}
#endif
