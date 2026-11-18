// COMPILER: ee-gcc2.96
extern void func_00336980(), func_00336588();
struct Q { char c; };
// FUNCTION: GAME 0x3366B8
void func_003366B8(struct Q *o)
{
    if (o) {
        func_00336980(o);
        if (o->c == 1) {
            o->c = 0;
            func_00336588(o);
            __asm__ volatile ("");
        }
    }
}

// FUNCTION: GAME 0x3312B8
void func_003312B8(void)
{
    int i = 0x3FFF;
    do {
        i -= 0x20;
        __asm__ volatile ("nop");
    } while (i >= 0);
}

// FUNCTION: GAME 0x333FD8
void func_00333FD8(void)
{
    int i = 0x1FFF;
    do {
        i -= 0x20;
        __asm__ volatile ("nop");
    } while (i >= 0);
}

extern int func_00334008(), func_00331570(), func_00331AD8(), func_003341B8(), func_00334A90(), func_003260C8();
extern char D_004549C0[], D_004549D8[];
struct S { char _0[2]; char c2; char _3[0x25]; int m28; int m2C; };
// FUNCTION: GAME 0x334998
int func_00334998(struct S *o)
{
    int i = 0;
    if (!o)
        return func_00334008(o, D_004549C0);
    if ((unsigned char)o->c2 >= 2) {
        if (o->m2C) func_00331570(o->m2C);
        for (;;) {
            func_00331AD8();
            func_003341B8();
            func_00334A90(o);
            if (o->c2 != 2) { o->m28 = 0; break; }
            i++;
            if (i > 0x63FFF6) {
                func_003260C8(D_004549D8);
                o->m28 = 0;
                break;
            }
            func_00333FD8();
        }
        o->c2 = 0;
    }
}
