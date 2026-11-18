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
// FUNCTION: GAME 0x380AE8
extern "C" int func_00380AE8(void *a, Fn38A *b)
{
    int p, q;
    func_00380E88();
    p = func_0031C890(0x231E4);
    b->w34 = p;
    if (!p) {
        printf("Error:Memory Allocating Error!!(adxt_work)\n");
        return 1;
    }
    q = func_00329438(2, p, 0x231E4);
    b->w30 = q;
    if (!q) {
        printf("Error:ADXT_Create Error!!\n");
        func_0031C900(b->w34);
        return 2;
    }
    return 0;
}
