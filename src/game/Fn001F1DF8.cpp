extern "C" int func_001C2490(int);
extern "C" void func_001EF978(char *);

// FUNCTION: GAME 0x1F1DF8
extern "C" void func_001F1DF8(char *self)
{
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) += 1;
        break;
    case 1:
        if (*(int *)(self + 0xC64))
            if (func_001C2490(*(int *)(self + 0xC64))) *(int *)(self + 0xC64) = 0;
        if (*(int *)(self + 0xC68))
            if (func_001C2490(*(int *)(self + 0xC68))) *(int *)(self + 0xC68) = 0;
        if (*(int *)(self + 0xC6C))
            if (func_001C2490(*(int *)(self + 0xC6C))) *(int *)(self + 0xC6C) = 0;
        if (*(int *)(self + 0xC70))
            if (func_001C2490(*(int *)(self + 0xC70))) *(int *)(self + 0xC70) = 0;
        if (*(int *)(self + 0xC74))
            if (func_001C2490(*(int *)(self + 0xC74))) *(int *)(self + 0xC74) = 0;
        break;
    }
}
