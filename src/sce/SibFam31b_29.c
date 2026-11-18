// COMPILER: ee-gcc2.9-991111
// Sibling of the 0x31f1a8 type_info getters.

extern int D_00460DA8;
int *func_003218F8(void);
void func_0031EEA8(void *, char *, void *);

extern int D_007866F8;
extern char D_004512A0[];

// FUNCTION: GAME 0x321860
int *func_00321860(void)
{
    if (!D_007866F8) {
        func_003218F8();
        func_0031EEA8(&D_007866F8, D_004512A0, &D_00460DA8);
    }
    return &D_007866F8;
}
