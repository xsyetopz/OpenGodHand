extern "C" int func_001B6FB8(void *self);
extern "C" void effDataRegist__6espSys12eEffDataTypePv(void *sys, int t, void *p);
extern "C" void *SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(int, int, void *, void *, int, unsigned);
extern char EspSys[];

// FUNCTION: GAME 0x17EC98
extern "C" int func_0017EC98(char *self)
{
    func_001B6FB8(self);
    char *p = *(char **)(self + 0x304);
    effDataRegist__6espSys12eEffDataTypePv(EspSys, 0x27D, (char *)(*(int *)(p + 0xC) + (int)p));
    SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2(0x27D, 1, self, 0, -1, 0xFFFFFFFFu);
    return 1;
}
