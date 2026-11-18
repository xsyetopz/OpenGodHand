// Medium functions in the ProDG game-code island 0x380000-0x387430 (ee-gcc2.95.3-136, C++).

struct Fn38A { char _0[0x20]; int w20; int w24; char _28[8]; int w30; int w34; };
extern "C" {
int printf(const char *, ...);
void func_00380E88(void);
void func_00381D38(void);
int func_0031C890(int);
void func_0031C900(int);
int func_00329438(int, int, int);
int func_0032D340(int, int, int, int);
}
// FUNCTION: GAME 0x381B38
extern "C" int func_00381B38(void *a, Fn38A *b)
{
    int p, q;
    func_00381D38();
    p = func_0031C890(0x8C6D0);
    b->w24 = p;
    if (!p) {
        printf("Error:Memory Allocating Error!!(aixp_work)\n");
        return 1;
    }
    q = func_0032D340(4, 2, p, 0x8C6D0);
    b->w20 = q;
    if (!q) {
        printf("Error:AIXP_Create Error!!\n");
        func_0031C900(b->w24);
        return 2;
    }
    return 0;
}
