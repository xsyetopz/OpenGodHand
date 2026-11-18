// Misc units in 0x130000-0x138000 over raw offsets.
extern "C" {
void *func_0030F550(int);
void *func_001339F0(void *, int, int, float);
void *func_00134430(void *, int, int, float);
int func_001346C8(void *, int, int, float);
}
extern int D_00460D18;

// FUNCTION: GAME 0x134520
extern "C" void func_00134520(void **self, int a1, int a2, float f)
{
    if (!self[0]) return;
    void *r;
    if (self[1]) {
        void **n = (void **)self[1];
        while (n[0]) n = (void **)n[0];
        r = func_001339F0(func_0030F550(0x80), a1, a2, f);
        n[0] = r;
    } else {
        r = func_001339F0(func_0030F550(0x80), a1, a2, f);
        self[1] = r;
    }
    if (r) D_00460D18++;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1346F8 - 12 words: target keeps self/a1/a2 in s1/s2/s3, mine allocates s3/s1/s2 (register order only)
extern "C" void CreateUnit__21cCollisionSolidManageP8cGameObjQ225cCollisionSolidManageUnit9ePRIORITYf(char *self, int a1, int a2, float f)
{
    void *r;
    if (!a1 || func_001346C8(self, a1, a2, f)) return;
    if (*(char **)self) {
        char *n = *(char **)self;
        while (*(char **)(n + 0x10)) n = *(char **)(n + 0x10);
        r = func_00134430(func_0030F550(0x40), a1, a2, f);
        *(void **)(n + 0x10) = r;
    } else {
        r = func_00134430(func_0030F550(0x40), a1, a2, f);
        *(void **)self = r;
    }
    if (r) *(int *)(self + 4) += 1;
}
#endif

