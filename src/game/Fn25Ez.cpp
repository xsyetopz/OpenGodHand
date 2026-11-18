class cP25;
typedef void (cP25::*cP25Pmf)();
class cP25 {
public:
    virtual void f();
};
extern "C" {
void func_0026A938(cP25 *, int, int);
void func_0026B1E8(cP25 *);
void func_001C2318(int);
void func_001D0108(int);
void func_0026BB70(cP25 *);
void func_001D0408(int);
void func_001D04D0(int);
void func_001D05C0(int);
void KillEffect__FPC4cObji13eEspEraseMode(cP25 *, int, int);
}
extern cP25Pmf D_003BF878[];

#define W(o) (*(int *)((char *)self + (o)))
#define B(o) (*(unsigned char *)((char *)self + (o)))

// FUNCTION: GAME 0x25E600
extern "C" void func_0025E600(cP25 *self)
{
    func_0026A938(self, 0, 0);
    func_0026A938(self, 1, 0);
    func_0026B1E8(self);
    if (W(0x70C)) {
        func_001C2318(W(0x70C));
        W(0x70C) = 0;
    }
    if (W(0x730)) {
        func_001D0108(W(0x730));
        W(0x730) = 0;
    }
    func_0026BB70(self);
    if (W(0x738)) {
        func_001D0408(W(0x738));
        W(0x738) = 0;
    }
    if (W(0x6F0))
        func_001D04D0(W(0x6F0));
    if (W(0x708))
        func_001D05C0(W(0x708));
    if (W(0x16D4) & 0x20) {
        KillEffect__FPC4cObji13eEspEraseMode(self, 1, 2);
        W(0x16D4) &= 0xFFFFFFDF;
    }
    B(0x1864) = 0;
    if (!(B(0x2F5) < 5))
        B(0x2F5) = 0;
    (self->*D_003BF878[B(0x2F5)])();
}
