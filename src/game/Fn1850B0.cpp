extern "C" void func_00185F50(void *, int);
// FUNCTION: GAME 0x1850B0
extern "C" void func_001850B0(char *self)
{
    float r = (float)*(short *)(self + 0x628) / (float)*(short *)(self + 0x636);
    switch (*(unsigned char *)(self + 0x65A)) {
    case 0:
        if (r <= 0.5f) {
            func_00185F50(self, 1);
            *(unsigned char *)(self + 0x65A) += 1;
        }
        break;
    case 1:
        if (r <= 0.0f) {
            func_00185F50(self, 4);
            *(unsigned char *)(self + 0x65A) += 1;
        }
        break;
    case 2:
        *(unsigned char *)(self + 0x661) = 1;
        break;
    }
}
