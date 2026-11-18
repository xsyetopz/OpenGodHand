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
