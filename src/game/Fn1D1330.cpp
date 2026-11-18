extern "C" void func_001D4670();
extern "C" void SetDefaultDisp__11BlackJackId(void *);
extern "C" void func_001D5760(void *, int);
extern "C" void func_001D5780(void *, int);
extern "C" int getGold__9cCoreSave(void *);
extern char CoreSave[];

struct BJ {
    char pad[0x17FC];
    short s17FC, s17FE;
    unsigned int f1800;
    int i1804, i1808;
    char pad2[0x1814 - 0x180C];
    int i1814, i1818;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1D1330
// 18 words differ: original lwu+dsra and branch (bnez, v=2 in delay slot), we emit lw/sra+movn; tried long, long long, unsigned long casts, local copies
extern "C" void func_001D1330(BJ *self) {
    self->i1814 = 0;
    self->i1818 = 0;
    self->s17FC = 0;
    self->s17FE = 0;
    func_001D4670();
    SetDefaultDisp__11BlackJackId(self);
    func_001D5760(self, 0);
    func_001D5780(self, getGold__9cCoreSave(CoreSave));
    int v = 2;
    if (!(((long long)self->f1800 >> 3) & 1))
        v = 1;
    self->i1808 = 0;
    self->i1804 = v;
    self->f1800 = 0;
}
#endif
