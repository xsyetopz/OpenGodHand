// Small functions in the ProDG game-code island 0x372CB0-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn37FS {
    int w0;
    int w4;
    int w8;
    int wC;
    int w10;
    char _14[0x1C];
    int w30;
};
struct Fn37FT {
    int w0;
    int w4;
    int w8;
    int wC;
    int w10;
    char _14[0xC];
    int w20;
};
struct Fn37FB {
    char _0[3];
    unsigned char b3;
    char _4[0x68];
    Fn37FS s6c;
};
extern "C" {
int func_0032DCD0(int, int);
int func_00329F98(int);
int func_0032E118(int);
int func_0032A530(int);
int func_0032E1F0(int);
int func_0032E280(int);
int func_0032E310(int);
int func_0032A4A8(int);
int func_0032A5B8(int);
int func_0032A648(int);
void func_00381D60(int, void *, void *);
void func_00380EB0(int, void *, void *);
}

// FUNCTION: GAME 0x37FE78
extern "C" int func_0037FE78(int a, Fn37FB *b)
{
    if (b->b3 & 2) {
        Fn37FT *s = (Fn37FT *)((char *)b + 0xCC);
        int h = func_0032DCD0(s->w20, 0);
        if (func_00329F98(h) != 2)
            return 0;
        s->w0 = func_0032E118(s->w20);
        s->w4 = func_0032A530(h);
        s->w8 = func_0032E1F0(s->w20);
        s->wC = func_0032E280(s->w20);
        s->w10 = func_0032E310(s->w20);
        func_00381D60(a, s, b);
        return 1;
    }
    Fn37FS *s = &b->s6c;
    if (func_00329F98(s->w30) < 2)
        return 0;
    s->w0 = func_0032A4A8(s->w30);
    s->w4 = func_0032A530(s->w30);
    s->w8 = func_0032A5B8(s->w30);
    s->wC = func_0032A648(s->w30);
    func_00380EB0(a, s, b);
    return 1;
}
