struct S11 { long a; unsigned short b; unsigned char c; };
extern "C" {
int func_00381B38(void *, void *, void *);
void func_0032DE88(int, int);
void func_0032DEF8(int, int);
void func_0032DF70(int, int, int);
void func_003821D8(void *, void *);
void func_003825A8(void *, void *);
void func_0032D9B8(int, void *, int);
void func_0032E040(int, int);
char *strcat(char *, const char *);
}
extern S11 D_0045C7F0;
extern S11 D_0077BF80;
extern char D_0045C800[];

// FUNCTION: GAME 0x381BC8
extern "C" int func_00381BC8(char *a, char *b)
{
    char *s = b + 0x30;
    int r = func_00381B38(a, s, b);
    if (r) {
        b[1] = r;
        return 1;
    }
    int h = *(int *)(s + 0x20);
    func_0032DE88(h, 1);
    func_0032DEF8(*(int *)(s + 0x20), 1);
    func_0032DF70(*(int *)(s + 0x20), 1, 1);
    func_003821D8(a, b);
    func_003825A8(a, b);
    S11 *d = &D_0077BF80;
    d->a = D_0045C7F0.a;
    d->b = D_0045C7F0.b;
    d->c = D_0045C7F0.c;
    char *t = *(char **)(a + 0x3C);
    int n = *(int *)(t - 0x10);
    char *src;
    if (n == 0) {
        src = D_0045C800;
    } else {
        t[n] = 0;
        src = *(char **)(a + 0x3C);
    }
    strcat((char *)d, src);
    func_0032D9B8(*(int *)(s + 0x20), &D_0077BF80, 0);
    b[0] = 0;
    func_0032E040(*(int *)(s + 0x20), 0);
    return 0;
}
