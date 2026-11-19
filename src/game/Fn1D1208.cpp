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
struct Fp1 {
    void (*fn)(char *);
};

// FUNCTION: GAME 0x1D1208
extern "C" void Main__9BlackJack(char *self)
{
    int i;
    int *p;
    int *a = (int *)(self + 0x17D4);
    int *b;
    int k = *(int *)(self + 0x1804);
    int o = k << 3;
    short s = *(short *)(o + (int)D_003BDF58);
    ((Fp1 *)((int)D_003BDF58 + o + 4))->fn(self + s);
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
    for (p = b, i = 4; i >= 0; p++) {
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
