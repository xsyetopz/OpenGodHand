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
