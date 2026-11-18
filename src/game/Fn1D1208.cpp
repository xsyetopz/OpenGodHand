extern "C" void func_001D0CE8(int);
extern "C" void func_001D0DF8(int);
extern "C" void func_001D5780(void *, int);
extern "C" void Move__11BlackJackId(void *);
extern "C" void Trans__11BlackJackId(void *);
extern "C" int getGold__9cCoreSave(void *);
extern char CoreSave[];

struct Ent {
    short off, pad;
    void (*fn)(char *);
};
extern Ent D_003BDF58[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1D1208
extern "C" void Main__9BlackJack(char *self)
{
    int i;
    int *p;
    int *a = (int *)(self + 0x17D4);
    int *b;
    D_003BDF58[*(int *)(self + 0x1804)].fn(self + D_003BDF58[*(int *)(self + 0x1804)].off);
    for (i = 4, p = a; i >= 0; p++) {
        int v = *p;
        i--;
        if (v) func_001D0CE8(v);
    }
    b = (int *)(self + 0x17E8);
    for (i = 4, p = a; i >= 0; p++) {
        int v = *p;
        i--;
        if (v) func_001D0DF8(v);
    }
    for (i = 4, p = b; i >= 0; p++) {
        int v = *p;
        i--;
        if (v) func_001D0CE8(v);
    }
    for (i = 4, p = b; i >= 0; p++) {
        int v = *p;
        i--;
        if (v) func_001D0DF8(v);
    }
    func_001D5780(self, getGold__9cCoreSave(CoreSave));
    Move__11BlackJackId(self);
    Trans__11BlackJackId(self);
}
#endif
