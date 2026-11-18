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
// 14 words differ in tail only: orig lwu;dsra 3;andi;bnez branch, mine lw;sra+xori+movn. Tried (long)unsigned cast, long local, unsigned long->long, struct unsigned field (all lw/dsll32 or sra)
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
    unsigned char v = 2;
    if (!((long)*(unsigned *)(self + 0x3020) >> 3 & 1))
        v = 1;
    *(char *)(self + 0x3025) = 0;
    *(char *)(self + 0x3024) = v;
    *(int *)(self + 0x3020) = 0;
}
#endif
