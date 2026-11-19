struct Ent { short off; short pad; void (*fn)(char *); };
extern Ent D_003BE000[];
extern char CoreSave;
extern "C" void func_001D6E20(int);
extern "C" void func_001D6F30(int);
extern "C" void func_001DD238(char *, int);
extern "C" int getGold__9cCoreSave(void *);
extern "C" void Move__7PokerId(char *);
extern "C" void Trans__7PokerId(char *);

// FUNCTION: GAME 0x1D7378
extern "C" void Main__5Poker(char *self)
{
    int *base = (int *)(self + 0x3004);
    int i = 4;
    int k = *(unsigned char *)(self + 0x3024) * 8;
    short *s = (short *)(k + (int)D_003BE000);
    void (*f)(char *) = *(void (**)(char *))((int)D_003BE000 + k + 4);
    f(self + *s);
    int *p = base;
    do {
        if (*p) func_001D6E20(*p);
        i--;
        p++;
    } while (i >= 0);
    p = base;
    i = 4;
    do {
        if (*p) func_001D6F30(*p);
        i--;
        p++;
    } while (i >= 0);
    func_001DD238(self, getGold__9cCoreSave(&CoreSave));
    Move__7PokerId(self);
    Trans__7PokerId(self);
}
