extern "C" void func_002B3158(void *);
extern "C" int func_002B3190(void *);
extern "C" int func_002B31F8(void *);
extern "C" void func_002B3230(void *);

// FUNCTION: GAME 0x2B3078
extern "C" void func_002B3078(char *self)
{
    switch (*(unsigned char *)(self + 0xD)) {
    case 1:
        goto l3100;
    case 0:
        func_002B3158(self);
        switch (*(unsigned char *)(self + 0xA4)) {
        case 3:
            *(unsigned char *)(self + 0xD) = 1;
            break;
        case 1:
            break;
        case 0:
        case 2:
        case 4:
        case 5:
            *(unsigned char *)(self + 0xD) = 2;
            break;
        }
    l3100:
        if (func_002B3190(self) == 0)
            return;
        *(unsigned char *)(self + 0xD) = *(unsigned char *)(self + 0xD) + 1;
    case 2:
        if (func_002B31F8(self) == 0)
            return;
        func_002B3230(self);
        *(unsigned char *)(self + 0xC) = 2;
        *(unsigned char *)(self + 0xD) = 0;
        *(unsigned char *)(self + 0xE) = 0;
        *(unsigned char *)(self + 0xF) = 0;
    }
}
