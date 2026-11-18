extern unsigned D_00747A88;
extern "C" void func_002BF380(char *);
extern "C" void func_002BF388(char *);
extern "C" void func_002BF478(char *);
extern "C" void func_002BF540(char *);
extern "C" void func_002BF568(char *);
extern "C" void Set_bg_mode__FUiUcUcUc(unsigned, int, int, int);

// FUNCTION: GAME 0x2BF2D0
extern "C" void func_002BF2D0(char *self)
{
    func_002BF380(self);
    if (D_00747A88 & 0x40000000) {
        Set_bg_mode__FUiUcUcUc(1, 0, 0, 0);
        switch (*self) {
        case 0:
        case 1: break;
        case 2: func_002BF388(self); break;
        case 3: func_002BF478(self); break;
        case 4: func_002BF540(self); break;
        case 5: func_002BF568(self); break;
        }
    }
}
