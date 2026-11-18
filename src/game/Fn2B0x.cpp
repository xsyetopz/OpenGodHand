extern "C" int func_002B6510(char *);
extern "C" char *func_002B5E50(char *);
extern "C" char *func_002B61B0(char *);
extern "C" char *func_002B6328(char *);
extern "C" void MtxMultiply__FR7cMatrixRC7cMatrixT1(char *, char *, char *);
extern "C" void MtxCopy__FR7cMatrixRC7cMatrix(char *, char *);

// FUNCTION: GAME 0x2B6420
extern "C" void func_002B6420(char *self)
{
    if (!func_002B6510(self)) {
        char *p = func_002B5E50(self);
        if (p) {
            char *a = func_002B61B0(p);
            MtxMultiply__FR7cMatrixRC7cMatrixT1(self + 0xB0, a, func_002B6328(self));
        } else {
            MtxCopy__FR7cMatrixRC7cMatrix(self + 0xB0, func_002B6328(self));
        }
        *(unsigned *)(self + 0x90) |= 1;
    }
}

extern unsigned D_00747A2C[];
extern unsigned D_00747A88;
extern "C" void func_002B17A8(char *);
extern "C" void func_002B17F8(char *);
extern "C" void func_002B1830(char *);
extern "C" void func_002B1BE8(char *);
extern "C" void func_002B1C30(char *);

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

extern "C" int func_002B46F0(char *, int, int, int);

// FUNCTION: GAME 0x2B39B0
extern "C" int func_002B39B0(char *self)
{
    int k;
    switch (*(unsigned short *)(*(char **)(self + 0x8C) + 2)) {
    default:
    case 0:
    case 5: k = 0; break;
    case 1: k = 1; break;
    case 2: k = 6; break;
    case 3: k = 2; break;
    case 4: k = 3; break;
    case 6: k = *(int *)(self + 0x20); break;
    }
    func_002B46F0(self, k, *(short *)(*(char **)(self + 0x8C) + 4), *(int *)(self + 0x18));
    return 0;
}

extern "C" int func_002B2500(char *);
extern "C" void func_002B3078(char *);
extern "C" void func_002B3240(char *);
extern "C" void func_002B3D70(char *);
extern "C" void func_002B3EC8(char *);
extern "C" void func_002B4028(char *);
extern "C" void func_002B4188(char *);
extern "C" void func_002B4390(char *);

// FUNCTION: GAME 0x2B2438
extern "C" void func_002B2438(char *self)
{
    switch (*(unsigned char *)(self + 0xC)) {
    case 0:
        if (!func_002B2500(self))
            break;
    case 1: func_002B3078(self); break;
    case 2: func_002B3240(self); break;
    case 3: func_002B3D70(self); break;
    case 4: func_002B3EC8(self); break;
    case 5: func_002B4028(self); break;
    case 6: func_002B4188(self); break;
    case 7: break;
    }
    if (*(unsigned short *)(self + 0x2E))
        (*(unsigned short *)(self + 0x2E))--;
    func_002B4390(self);
}
