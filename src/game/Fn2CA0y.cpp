struct N1 { int a; N1 *next; };
struct N2 { char pad[0x88]; N2 *next; };
extern char D_006036A0[], D_00603310[], D_00602F80[];
extern "C" void func_002CE430(N1 *);
extern "C" void func_002CCB10(N2 *);
extern "C" void func_002CB070(char *);
extern "C" void func_00375050(int, int);
extern "C" int func_00375180();
extern "C" void func_002CA470(char *);
extern "C" void func_00395398(int);
extern "C" void func_002CA148(char *);
extern "C" void func_002CD780(char *);
extern "C" void func_0032D250();
extern "C" void func_00324AC8();
extern "C" void func_00325818();
// FUNCTION: GAME 0x2CA040
extern "C" void func_002CA040(char *self)
{
    N1 *p = *(N1 **)(self + 0x1C);
    N2 *q;
    if (p != 0) {
        do {
            func_002CE430(p);
            p = p->next;
        } while (p != 0);
    }
    q = *(N2 **)(self + 0x18);
    if (q != 0) {
        do {
            func_002CCB10(q);
            q = q->next;
        } while (q != 0);
    }
    *(int *)(self + 0xAC) = 0;
    *(int *)(self + 0xB0) = 0;
    *(int *)(self + 0x30) = 0;
    *(int *)(self + 0xA8) = 0;
    func_002CB070(self);
    func_00375050(0, 0);
    while (func_00375180() == 1) {
        func_002CA470(self);
        func_00395398(0);
    }
    func_002CA148(self);
    func_002CD780(D_006036A0);
    func_002CD780(D_00603310);
    func_002CD780(D_00602F80);
    func_0032D250();
    func_00324AC8();
    func_00325818();
}
