// God Hand: small units in 0x280000-0x2A0000
extern char D_Ev297AA8[];
extern char D_Ev297BF8[];
extern "C" void func_0(char *);
// FUNCTION: GAME 0x297AD0
extern "C" void releaseWork__6cEvent(char *self)
{
    if (self[9] & 1) {
        func_0(D_Ev297AA8);
        func_0(D_Ev297AA8);
        func_0(D_Ev297BF8);
    }
}
