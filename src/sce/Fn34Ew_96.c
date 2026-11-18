// COMPILER: ee-gcc2.96
void func_0036C450(int, int, int);
void func_00355880(int);
int DeleteSema(int);
int func_00356358(char *);

// FUNCTION: GAME 0x350418
void func_00350418(char *a, int *arr, int n)
{
    int s = **(int **)(a + 0x1FC0);
    int i;
    register int c __asm__("$3");
    if (s != 0) {
        for (i = 0; (c = i < n); i++)
            func_0036C450(s, i, arr[i]);
    }
}

// FUNCTION: GAME 0x3562A0
int func_003562A0(char *a)
{
    func_00355880(5);
    *(volatile int *)0x1000B420 = 0;
    *(volatile int *)0x1000B410 = 0;
    *(volatile int *)0x1000B430 = 0;
    DeleteSema(*(int *)(a + 0x40));
    return 1;
}

// FUNCTION: GAME 0x356E98
int func_00356E98(char *a)
{
    int *p;
    if (func_00356358(a) == 0) return 1;
    p = (int *)(*(char **)(a + 0x1FC0) + 0x1128);
    if (p[8] == 1) return 1;
    { int c = p[3] < 3; __asm__("" : "+r"(c)); return c == 0; }
}

void func_00352AA0(char *, char *);
void func_0035B0E8(char *, int *, int *);

// FUNCTION: GAME 0x3519A8
int func_003519A8(char *a)
{
    char *s = a + 0xD6C;
    register int r __asm__("$2") = 0;
    if (*(int *)(a + 0xD98) != 0) {
        char buf[0x20] __attribute__((aligned(16)));
        int x[2];
        func_00352AA0(a + 0xD9C, buf);
        *(int *)(buf + 0x18) = 0;
        func_0035B0E8(buf, &x[0], &x[1]);
        r = x[0] - *(int *)(s + 0x24);
    }
    return r;
}

// FUNCTION: GAME 0x353348
int func_00353348(char *a, int b)
{
    int k = *(int *)(*(char **)(a + 0x1FC0) + 0x74);
    int r = 0;
    if (k != 3) {
        if ((unsigned)k < 4) {
            if (k == 2) {
                if ((unsigned)(b - 2) < 2)
                    r = 1;
            }
        }
    } else {
        r = b == k;
    }
    return r;
}
