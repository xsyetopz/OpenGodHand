// COMPILER: ee-gcc2.96
typedef struct { char c[0x20]; } S35C;
extern void *memset();
extern int func_0035D800(), func_0035C200(), func_0035C140();

// FUNCTION: GAME 0x0035C080
void func_0035C080(int a, int *b)
{
    func_0035C200(a, 2, 3);
    func_0035C140(a, 3, 4);
    if (b[5]) {
        func_0035C200(a, 4, 5);
        func_0035C140(a, 5, 6);
        func_0035C200(a, 6, 7);
    } else {
        func_0035C200(a, 4, 7);
    }
}

// FUNCTION: GAME 0x0035DAA0
int func_0035DAA0(int *a, char *b)
{
    char *p;
    *b = 0;
    p = (char *)a[1] + 0x60;
    if (func_0035D800(a)) {
        memset(b, 0, 0x21);
        *(S35C *)b = *(S35C *)p;
        return 1;
    }
    return 0;
}

// FUNCTION: GAME 0x0035DDB0
char *func_0035DDB0(char *s, int *out)
{
    int v = 0;
    int c = *s;
    while (c != '.' && c != ' ' && c != 0 && (unsigned)(c - '0') < 10) {
        v = v * 10 + c - '0';
        s++;
        c = *s;
    }
    *out = v;
    return s;
}
