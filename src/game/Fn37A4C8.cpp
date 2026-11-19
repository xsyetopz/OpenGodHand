extern "C" {
int func_00374DF8(void *, int);
void func_00375050(int, int);
void func_00375D98(int, int, int);
void func_0037A5F0(void *);
void func_0037A668(void *);
void func_00387270(int, int, int, int);
}

// FUNCTION: GAME 0x37A4C8
extern "C" int func_0037A4C8(char *p)
{
    int f = *(int *)(p + 0x34);
    if (f & 0x40) {
        switch (p[7]) {
        case 0:
            func_00375050(0, -1);
            break;
        case 1:
            func_00387270(-1, 0, -1, 15);
            break;
        case 2:
            func_00375D98(0, 0, -1);
            break;
        }
        return 1;
    }
    if (f & 0x20) {
        switch (p[7]) {
        case 0:
            *(int *)(p + 0xC) = func_00374DF8(p + 0x9C, 0);
            break;
        case 1:
            func_0037A5F0(p);
            break;
        case 2:
            func_0037A668(p);
            break;
        }
        return 1;
    }
    return 0;
}
