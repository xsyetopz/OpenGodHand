// Moves the head node of a list to the tail; returns its offset from the base.
extern unsigned D_00747A34;

struct Node {
    Node *next;
    Node *prev;
};
struct List {
    int _a;
    int base;
    int _b[2];
    Node *head;
    Node *tail;
};

// FUNCTION: GAME 0x2A97A0
extern "C" int func_002A97A0(List *l)
{
    if (D_00747A34 & 0x80000)
        return 0;
    Node *n = l->head;
    if (!n)
        return 0;
    l->head = n->prev;
    if (n->prev)
        n->prev->next = 0;
    n->next = 0;
    Node *t = l->tail;
    n->prev = t;
    if (t)
        t->next = n;
    l->tail = n;
    return (int)n - l->base;
}
