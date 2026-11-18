// COMPILER: ee-gcc2.96
extern int func_0036D688(), func_0036D8E8();

// FUNCTION: GAME 0x0036D528
void func_0036D528(int *a)
{
    if (func_0036D688()) {
        func_0036D8E8(0, 0xFF030201);
        return;
    }
    *a = 1;
}

// FUNCTION: GAME 0x0036DA30
void func_0036DA30(int *a)
{
    if (func_0036D688()) {
        func_0036D8E8(0, 0xFF030210);
        return;
    }
    a[0x46] = 1;
}

// FUNCTION: GAME 0x0036E200
void func_0036E200() {}

// FUNCTION: GAME 0x0036E378
void func_0036E378() {}
