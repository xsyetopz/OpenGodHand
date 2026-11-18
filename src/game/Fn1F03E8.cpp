extern "C" void *Getplayer__Fv();
extern "C" void func_001F0360(char *, void *);
struct Node { int pad; Node *next; char *obj; };
extern Node *D_005869F0;
extern unsigned char D_005CB010;

struct Obj { char pad[0x2FE]; unsigned short id; };
static inline unsigned char inRange(Obj *o)
{
    int v = o->id;
    unsigned char r = 0;
    if (v >= 0x200)
        r = v < 0x300;
    return r;
}

#ifdef NONMATCHING
// DRAFT: GAME 0x1F03E8
// 20 words differ: gcc folds u16 range test to sltiu/movn, original uses slti x2 + andi; tried inline helper, int/short casts, struct field, ternary
extern "C" void func_001F03E8(char *self)
{
    *(int *)(self + 0xBC8) = 0;
    if (D_005CB010 == 0)
        func_001F0360(self, Getplayer__Fv());
    for (Node *n = D_005869F0; n; n = n->next) {
        char *o = n->obj;
        if (o) {
            if (inRange((Obj *)o))
                func_001F0360(self, o);
        }
    }
}
#endif
