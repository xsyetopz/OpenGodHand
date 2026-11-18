extern "C" int GetSeData__4cSndi(void *self, int i);
extern "C" void func_002CF310(int);
extern "C" void func_002CB208(void *);
extern "C" void func_002CD780(void *);
extern "C" void func_002CCB10(void *);
extern "C" void func_002CD470(void *, float);
extern char D_006036A0[];
extern char D_00603310[];

// FUNCTION: GAME 0x2CA910
extern "C" void func_002CA910(char *self)
{
    *(int *)(self + 0xB0) &= 0xFF7FFFFF;
    *(int *)(self + 0xAC) &= 0xFF7FFFFF;
    func_002CF310(GetSeData__4cSndi(self, 2));
    func_002CB208(self);
    func_002CD780(D_006036A0);
    func_002CD780(D_00603310);
    char *p = *(char **)(self + 0x18);
    while (p) {
        int f = *(int *)(p + 0x98);
        if ((f & 0x100) == 0) {
            if (f & 0x1FF00) {
                *(int *)(p + 0x98) = f & 0xFFFE00FF;
                func_002CD470(p, 30.0f);
            }
        } else {
            func_002CCB10(p);
        }
        p = *(char **)(p + 0x88);
    }
    *(int *)(self + 0xA4) = 0;
}
