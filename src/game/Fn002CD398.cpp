extern "C" int func_00373A50(void *);
extern "C" void func_00373430(void *);
extern "C" void func_003733C8(void *);
extern "C" int func_00373118(void *, int, int, int);
extern "C" int func_00373158(void *, int);
extern "C" int func_00373298(void *, int);
extern "C" void func_00373560(void *, int, float);
extern "C" void func_002CD470(void *, float);
extern "C" int GetHeadPtr__8cBgmData(int);

// FUNCTION: GAME 0x2CD398
extern "C" int func_002CD398(char *self)
{
    if (*(unsigned *)(self + 0x98) & 0x100)
        return 0;
    if (func_00373A50(self) == 1) {
        func_00373430(self);
        func_003733C8(self);
    }
    if (func_00373118(self, *(int *)(self + 0x8C), GetHeadPtr__8cBgmData(*(int *)(self + 0xB8)), 0) == 0) {
        return 0;
    } else {
        int r;
        if (*(unsigned *)(self + 0x98) & 1)
            r = func_00373158(self, *(int *)(self + 0x90));
        else
            r = func_00373298(self, *(int *)(self + 0x90));
        if (r != 0) {
            func_00373560(self, -1, 0);
            func_002CD470(self, 0);
            *(int *)(self + 0xB4) = 0;
            return 1;
        }
        return 0;
    }
}
