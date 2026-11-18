// Insertion sort over 8-byte elements keyed on the float at +4.
struct Elem {
    int a;
    float key;
};
extern "C" void func_002A9098(Elem *p, Elem key, int comp);

static inline int Less(const Elem &a, const Elem &b) { return a.key < b.key; }

static inline void CopyBack(Elem *first, Elem *last, Elem *d)
{
    for (int n = last - first; n > 0; n--) {
        --d;
        --last;
        *d = *last;
    }
}

static inline void LinearInsert(Elem *first, Elem *last, Elem v, int comp)
{
    if (Less(v, *first)) {
        CopyBack(first, last, last + 1);
        *first = v;
    } else {
        func_002A9098(last, v, comp);
    }
}

static inline void InsSort(Elem *first, Elem *last, int comp)
{
    if (first == last) return;
    for (Elem *i = first + 1; i != last; i++)
        LinearInsert(first, i, *i, comp);
}

// DRAFT: GAME 0x2A9100
// 37 words differ: original keeps a second reg (s2) holding a copy of first for the compare and *first store (frame 0x80 vs 0x70), key load order swapped; tried inline helpers, Less by ref/elem, copy order.
#ifdef NONMATCHING
extern "C" void func_002A9100(Elem *first, Elem *last, int comp)
{
    InsSort(first, last, comp);
}
#endif
