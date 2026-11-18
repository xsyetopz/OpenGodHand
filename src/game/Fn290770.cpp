struct Fn290770Node {
    Fn290770Node *prev;
    Fn290770Node *next;
    void *data;
    int key;
};

struct Fn290770List {
    Fn290770Node *head;
    Fn290770Node *tail;
};

extern char g_EmSet;
extern "C" void func_002956F0(void *);
extern "C" void func_002956A0(void *, void *);
extern "C" void ReleaseObj__FP4cObj(void *);
extern "C" void func_00290028(void *);
extern "C" int func_00290988(void *, int);

// DRAFT: GAME 0x290770
// 15 words: only s1/s2 swap (orig s1=em, s2=self); tried hoisted list ptr, tail-store if order, local copies.
#ifdef NONMATCHING
extern "C" int ReleaseEm__9cEmManageP7cEmBase(char *self, void *em)
{
    func_002956F0(&g_EmSet);
    for (Fn290770Node *n = *(Fn290770Node **)(self + 0x500); n; n = n->next) {
        if (n->data == em) {
            func_002956A0(&g_EmSet, em);
            ReleaseObj__FP4cObj(em);
            Fn290770List *l = (Fn290770List *)(self + 0x500);
            if (n) {
                Fn290770Node *p = n->prev;
                Fn290770Node *x = n->next;
                if (!p) *(Fn290770Node **)(self + 0x500) = x; else p->next = x;
                if (!x) l->tail = p; else x->prev = p;
            }
            int key = n->key;
            func_00290028(n);
            if (func_00290988(self, key) == 0) {
                *(int *)(self + 0x50C) -= 1;
            }
            *(int *)(self + 0x508) -= 1;
            return 1;
        }
    }
    return 0;
}
#endif
