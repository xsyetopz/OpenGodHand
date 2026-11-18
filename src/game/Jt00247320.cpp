// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char g_CollSolidManage[];
extern "C" void SetActive__21cCollisionSolidManageP8cGameObjb(void *, void *, int);
extern "C" int func_00276468(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void func_002705D8(void *);
extern "C" void addNullSpeed_Rotation__8cObjBasef(void *, float);
extern "C" void addNullSpeed__8cObjBasef(void *, float);
#define TAIL() addNullSpeed_Rotation__8cObjBasef(self, 1.0f); addNullSpeed__8cObjBasef(self, 1.0f)
#define st (*(unsigned char *)(self + 0x2F6))
#ifdef NONMATCHING
// DRAFT: GAME 0x247320 - frame 0x50 vs 0x30 (extra callee-saved s1/s2), case 0 branch order differs
extern "C" void func_00247320(void *s) {
    char *self = (char *)s;
    SetActive__21cCollisionSolidManageP8cGameObjb(g_CollSolidManage, self, 0);
    *(unsigned *)(self + 0x16D0) |= 0x20000;
    char *p;
    switch (st) {
    case 0: {
        int a, b, t = func_00276468(self) & 0xFFFF;
        int m = *(int *)(self + 0x564);
        if (m == 0x22C) { p = *(char **)(self + 0x304); a = *(int *)(p + 0x3710); b = *(int *)(p + 0x3714); }
        else if (m == 0x21C) { p = *(char **)(self + 0x304); a = *(int *)(p + 0x3708); b = *(int *)(p + 0x370C); }
        else { p = *(char **)(self + 0x304); a = *(int *)(p + 0x36F0); b = *(int *)(p + 0x36F4); }
        func_002A8578(self, a + (int)p, b + (int)p, 0, t, 0, 0.0f);
        st++;
    }
    case 1:
        if (moveMotion__FP8cObjBase(self)) {
            if (*(int *)(self + 0x564) == 0x244) st++; else func_002705D8(self);
        }
        TAIL();
        break;
    case 2:
        p = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(p + 0x36F8) + (int)p, *(int *)(p + 0x36FC) + (int)p, 3, func_00276468(self) & 0xFFFF, 0, 0.0f);
        st++;
    case 3:
        moveMotion__FP8cObjBase(self);
        TAIL();
        if (*(unsigned *)(self + 0x16D0) & 0x20000000) st = 4;
        else if (*(float *)(self + 0x16C0) > 0.0f) st = 4;
        break;
    case 4:
        p = *(char **)(self + 0x304);
        func_002A8578(self, *(int *)(p + 0x3700) + (int)p, *(int *)(p + 0x3704) + (int)p, 3, func_00276468(self) & 0xFFFF, 0, 0.0f);
        st++;
    case 5:
        if (moveMotion__FP8cObjBase(self)) func_002705D8(self);
        TAIL();
        break;
    }
}
#endif
