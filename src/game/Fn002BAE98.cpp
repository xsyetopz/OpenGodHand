struct VT {
    char p[8];
    short adj, pad;
    void (*dtor)(void *, int);
};
struct Node {
    unsigned flags;
    Node *next;
    VT *vt;
};
struct List {
    char p[0xC];
    unsigned char mode;
    char q[3];
    Node *head;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x2BAE98
// 40 differing words: unlink loop layout and branch offsets (244 vs 252 bytes); tried break and continue loop forms (41)
extern "C" void func_002BAE98(List *l, Node *n)
{
    if (n == 0)
        return;
    if (((n->flags & 0x201) ^ 1) == 0) {
        Node *p = l->head;
        if (p == n) {
            l->head = n->next;
            n->next = 0;
        } else {
            while (p->next != 0) {
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
    switch (l->mode) {
    case 1:
        n->flags |= 0x600;
        break;
    case 0:
        if (((n->flags & 0x201) ^ 1) == 0) {
            if (n != 0) {
                VT *v = n->vt;
                v->dtor((char *)n + v->adj, 3);
            }
            n->flags = 0;
        }
        break;
    case 2:
        n->flags |= 0x200;
        break;
    }
}
#endif
