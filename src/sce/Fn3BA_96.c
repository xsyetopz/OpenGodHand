// COMPILER: ee-gcc2.96
extern void func_003B9DE0(char *);
extern void func_003B9DB0(void);
extern void func_003B9DC8(void);
extern void func_003BA148(int *);
extern char D_00460950[];
// FUNCTION: GAME 0x3BA0C8
void func_003BA0C8(int *p)
{
    int i;
    if (p == 0) {
        func_003B9DE0(D_00460950);
        return;
    }
    func_003B9DB0();
    for (i = 0; i < p[6]; i++)
        func_003BA148(p);
    func_003B9DC8();
}
