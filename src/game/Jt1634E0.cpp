// Five-state stepper keyed on the signed byte at 0x5B; sole switch of 0x1634E0.
extern "C" void func_00163598(void *);
extern "C" void func_00163840(void *);

// FUNCTION: GAME 0x1634E0
extern "C" void func_001634E0(char *self)
{
    switch (self[0x5B]) {
    case 0:
        *(unsigned *)(*(char **)(self + 0xE0) + 0x2C) |= 0x8000000;
        self[0x5C] = 0;
        goto adv;
    case 1:
        if ((unsigned char)(((unsigned char *)self)[0xF0] + 1) < 2)
            goto adv;
        func_00163598(self);
        break;
    case 2:
        func_00163840(self);
        break;
    case 3:
    adv:
        ((unsigned char *)self)[0x5B]++;
        break;
    case 4:
        ((unsigned char *)self)[0x5A]++;
        self[0x5B] = 0;
        break;
    }
}
