extern "C" int checkDeadFlag__7cEmBase(void *);
struct Node { int pad; Node *next; char *obj; };
extern Node *D_005869F0;

struct Obj { char pad[0x2FE]; unsigned short id; };
static inline unsigned char inRange(Obj *o)
{
    int v = o->id;
    unsigned char r = 0;
    if (v >= 0x200)
        r = v < 0x300;
    return r;
}
static inline unsigned char inRange2(Obj *o)
{
    int v = o->id;
    unsigned char r = 0;
    if (v >= 0x2A0)
        r = v < 0x300;
    return r;
}

static inline unsigned char inRange2(int v)
{
    unsigned char q = 0;
    if (v >= 0x2A0)
        q = v < 0x300;
    return q;
}

// DRAFT: GAME 0x2D0C10
// 37 words differ (ee-gcc emits movz for the u8 range flags instead of branches); tried helper inlines, hand-written locals, split helper.
#ifdef NONMATCHING
extern "C" int func_002D0C10(int, int id)
{
    for (Node *n = D_005869F0; n; n = n->next) {
        Obj *o = (Obj *)n->obj;
        if (o) {
            int v = o->id;
            unsigned char r = 0;
            if (v >= 0x200)
                r = v < 0x300;
            if (r) {
                if (!inRange2(v) && !checkDeadFlag__7cEmBase(o) && o->id == id)
                    return 1;
            }
        }
    }
    return 0;
}
#endif
