struct IDW { char pad[0x2C]; unsigned flags; };
struct IDBase { int x; };
extern "C" IDW *getIDWork__7cIDBasei(IDBase *, int);
struct Obj {
    char pad0[0xC];
    int sel;
    int on[4];
    char pad1[0x20];
    IDBase id;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1F6680
// 50 words differ: self+0x30 is CSE'd into a2 and loop regs swap (s0/s1); tried raw-pointer, inline helper (56), merged-store, typed struct (best)
extern "C" void func_001F6680(Obj *self)
{
    int i = 0;
    int *p = self->on;
    do {
        IDW *w;
        if (*p != 0) {
            w = getIDWork__7cIDBasei(&self->id, i);
            w->flags = w->flags & 0xDFFFFFFF;
        } else {
            w = getIDWork__7cIDBasei(&self->id, i);
            w->flags = w->flags | 0x20000000;
        }
        if (i == self->sel) {
            w = getIDWork__7cIDBasei(&self->id, i + 4);
            w->flags = w->flags & 0xDFFFFFFF;
        } else {
            w = getIDWork__7cIDBasei(&self->id, i + 4);
            w->flags = w->flags | 0x20000000;
        }
        i++;
        p++;
    } while (i < 4);
}
#endif
