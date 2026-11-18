struct Vt {
    int pad0[2];
    short adj;
    short pad;
    void (*fn)(char *, int);
};
struct Node {
    unsigned flags;
    Node *next;
    Vt *vt;
};
struct Mgr {
    char pad[0xC];
    unsigned char mode;
    char pad2[3];
    Node *head;
};
extern Mgr g_CollisionManager;

struct Obj {
    char pad[0x28];
    Node *h28;
    short s2C;
    char b2E;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1FCBA0 - list-unlink loop shape and switch-tail (sb 0x2E duplicated per exit in original) differ; tried t=p->next temp loop, Vt offsets fixed
extern "C" int func_001FCBA0(Obj *self)
{
    Node *n = self->h28;
    Mgr *m = &g_CollisionManager;
    if (n) {
        if (((n->flags & 0x201) ^ 1) == 0) {
            Node *p = m->head;
            if (p == n) {
                m->head = n->next;
                n->next = 0;
            } else {
                while (p->next) {
                    Node *t = p->next;
                    if (t == n) {
                        p->next = n->next;
                        n->next = 0;
                        break;
                    }
                    p = t;
                }
            }
        }
        switch (m->mode) {
        case 1:
            n->flags |= 0x600;
            break;
        case 0:
            if (((n->flags & 0x201) ^ 1) == 0) {
                if (n)
                    n->vt->fn((char *)n + n->vt->adj, 3);
                n->flags = 0;
            }
            break;
        case 2:
            n->flags |= 0x200;
            break;
        }
    }
    self->b2E = 0;
    self->h28 = 0;
    return 1;
}
#endif
