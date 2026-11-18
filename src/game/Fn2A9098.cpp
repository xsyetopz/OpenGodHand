// Insertion step of a sort keyed on the float at +4 of each 8-byte element.
struct Elem {
    int a;
    float key;
};
static inline int Less(const float &a, const float &b) { return a < b; }

// DRAFT: GAME 0x2A9098 - 11 words differ: the compare result and q swap v0/v1 (size matches, 100 B); tried for/goto/q-- loops, bool Less, p[-1], temp copies (11 or worse)
#ifdef NONMATCHING
extern "C" void func_002A9098(Elem *p, Elem key)
{
    Elem *q = p - 1;
    while (Less(key.key, q->key)) {
        *p = *q;
        p = q;
        q = p - 1;
    }
    *p = key;
}
#endif
