struct Poker {
    void SetDefaultDisp();
};
extern "C" void func_1DD340(Poker *);
extern "C" void func_1DD648(Poker *, int, int);

// FUNCTION: GAME 0x001D72D0
void Poker::SetDefaultDisp()
{
    func_1DD340(this);
    func_1DD648(this, 0, 0x32);
    func_1DD648(this, 1, 0x14);
    func_1DD648(this, 2, 0xF);
    func_1DD648(this, 3, 0xA);
    func_1DD648(this, 4, 8);
    func_1DD648(this, 5, 8);
    func_1DD648(this, 6, 3);
    func_1DD648(this, 7, 2);
}
