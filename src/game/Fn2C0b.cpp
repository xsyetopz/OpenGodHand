extern char Snd[];
extern "C" void *GetBgmData__4cSndi(void *, int);
extern "C" int func_002CFF68(void *);
extern "C" int func_002CC728(void *, int, void *, int);

struct BgmArgs {
    int a, b, c;
    short d, e;
};

// FUNCTION: GAME 0x2CC9C0
extern "C" int func_002CC9C0(void *self, int idx, int a, int b, int c, int d, int e)
{
    int ok = func_002CFF68(GetBgmData__4cSndi(Snd, idx));
    if (!ok) {
        return 0;
    }
    BgmArgs args;
    args.a = a;
    args.b = b;
    args.c = c;
    args.d = d;
    args.e = e;
    return func_002CC728(self, idx, &args, 1);
}

struct Blk {
    void *owner;
    Blk *prev;
    Blk *next;
    int size;
    int cur;
    int end;
    int req;
};
extern "C" Blk *func_002CD968(void *, int);
extern "C" Blk *func_002CD930(void *);

#ifdef NONMATCHING
// DRAFT: GAME 0x2CD7C8 - self/sz saved in swapped s1/s2, store order and beql differ (20 words)
extern "C" int func_002CD7C8(void *self, unsigned n)
{
    int sz = (n + 15) & 0xFFFFFFF0u;
    Blk *s = func_002CD968(self, sz);
    if (s) {
        Blk *b = func_002CD930(self);
        if (b) {
            b->prev = s;
            b->next = s->next;
            b->req = sz;
            b->owner = self;
            b->size = s->size - sz;
            b->cur = s->cur + sz;
            b->end = s->cur;
            if (s->next) {
                s->next->prev = b;
            }
            s->size = 0;
            s->next = b;
            return b->end;
        }
    }
    return 0;
}
#endif
