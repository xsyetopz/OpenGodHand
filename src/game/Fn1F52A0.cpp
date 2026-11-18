struct T7 { int a[7]; };
extern T7 D_0042BFB0;
extern T7 D_0042BFD0;
extern "C" void SetLocalPosY__12CustomIDWorki(char *, int);
extern "C" void func_001F4778(char *, int, int);

// FUNCTION: GAME 0x1F52A0
extern "C" void func_001F52A0(char *s, unsigned short n, int f)
{
    if (n < 7) {
        T7 a = D_0042BFB0;
        SetLocalPosY__12CustomIDWorki(s + 0x440, a.a[n]);
        T7 b = D_0042BFD0;
        SetLocalPosY__12CustomIDWorki(s + 0x4BC, b.a[n]);
        func_001F4778(s, 8, f);
        func_001F4778(s, 9, f);
    }
}
