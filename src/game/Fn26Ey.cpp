extern "C" {
void *func_002948C8(void *, unsigned);
int func_001B8640(void *);
int func_001B8648(void *);
void func_001B8670(void *);
float *func_001B8720(void *);
void setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(void *, float *, int, unsigned, float);
}
extern char g_EmManage[];
extern unsigned short D_00747A50;

// FUNCTION: GAME 0x26E458
extern "C" int func_0026E458(char *self)
{
    if (D_00747A50 == 0x204) {
        for (unsigned i = 0; i < 2; i++) {
            void *s = func_002948C8(g_EmManage, i);
            if (s && *(char **)(self + 0x6EC) && (*(unsigned short *)(*(char **)(self + 0x6EC) + 0x2FE) ^ 0x3B7) == 0
                && !func_001B8640(s) && !func_001B8648(s)) {
                float v[4];
                asm volatile("sqc2 $vf0,%0" : "=m"(v));
                float *p = func_001B8720(s);
                if (v != p) { v[0] = p[0]; v[1] = p[1]; v[2] = p[2]; }
                setGoto__5cEm00RC4cVec14EM00_GOTO_TYPEUif(self, v, 13, 0, 300.0f);
                *(unsigned char *)(self + 0x17B1) = i;
                *(unsigned char *)(self + 0x2F5) = 0x13;
                *(unsigned char *)(self + 0x2F6) = 0;
                *(unsigned char *)(self + 0x2F7) = 0;
                *(unsigned char *)(self + 0x2F4) = 0;
                func_001B8670(s);
                return 1;
            }
        }
    }
    return 0;
}
