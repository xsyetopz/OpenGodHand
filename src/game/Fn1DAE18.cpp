extern "C" void func_001DEF48(char *, int);
extern "C" void func_001DEFC8(char *, int);

// FUNCTION: GAME 0x1DAE18
extern "C" void func_001DAE18(char *self)
{
    char *s = self + 0x25B0;
    func_001DEF48(s, 0);
    func_001DEFC8(s, 0);
    int **pa = *(int ***)(self + 0x3004);
    int **pb = *(int ***)(self + 0x3008);
    int a = *(int *)((char *)*pa + 0x604);
    int b = *(int *)((char *)*pb + 0x604);
    if (a == 0)
        a = 0xD;
    if (b == 0)
        b = 0xD;
    if (a < b) {
        if (*(unsigned char *)(self + 0x3044)) {
            self[0x3025] = 0;
            self[0x3024] = 0x11;
        } else {
            self[0x3025] = 0;
            self[0x3024] = 0x12;
        }
    } else if (b < a) {
        if (*(unsigned char *)(self + 0x3044)) {
            self[0x3025] = 0;
            self[0x3024] = 0x12;
        } else {
            self[0x3025] = 0;
            self[0x3024] = 0x11;
        }
    } else {
        self[0x3025] = 0;
        self[0x3024] = 0x13;
    }
}
