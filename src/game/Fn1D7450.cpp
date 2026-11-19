extern char CoreSave[];
extern "C" void func_001DBEB0();
extern "C" void func_001DD340(void *);
extern "C" void func_001DD218(void *, int);
extern "C" void func_001DD238(void *, int);
extern "C" void func_001DD648(void *, int, int);
extern "C" void func_001DEE60(void *, int, int);
extern "C" int getGold__9cCoreSave(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x1D7450
// 10 words differ in tail only: orig lwu;dsra 3;andi;bnez branch. A long local with v=1 then v=2 gives 10; (long)unsigned cast inline with v=2 default, unsigned long->long and a struct unsigned field give 14 (lw/dsll32 or sra)
extern "C" void func_001D7450(char *self)
{
    *(int *)(self + 0x3034) = 0;
    *(int *)(self + 0x3038) = 0;
    func_001DBEB0();
    func_001DD340(self);
    func_001DD218(self, *(int *)(self + 0x3034));
    func_001DD238(self, getGold__9cCoreSave(CoreSave));
    func_001DD648(self, 0, 0x32);
    func_001DD648(self, 1, 0x14);
    func_001DD648(self, 2, 0xF);
    func_001DD648(self, 3, 0xA);
    func_001DD648(self, 4, 8);
    func_001DD648(self, 5, 8);
    func_001DD648(self, 6, 3);
    func_001DD648(self, 7, 2);
    func_001DEE60(self + 0x25B0, 0x11, 0);
    long f = *(unsigned *)(self + 0x3020);
    unsigned char v = 1;
    if ((f >> 3) & 1)
        v = 2;
    *(char *)(self + 0x3025) = 0;
    *(char *)(self + 0x3024) = v;
    *(int *)(self + 0x3020) = 0;
}
#endif
