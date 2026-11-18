extern "C" {
struct HE8D {
    int m_0;
    float m_4;
};

void func_002A8B90(HE8D *first, HE8D *last, void *cmp);
void func_002A8AA8(HE8D *h, int hole, int len, long item, void *cmp);
void func_002A8C48(HE8D *first, HE8D *last, void *cmp);

// DRAFT: GAME 0x2A8D30
#ifdef NONMATCHING
void func_002A8D30(HE8D *first, HE8D *middle, HE8D *last, int, void *cmp)
{
    func_002A8B90(first, middle, cmp);
    for (HE8D *i = middle; i < last; i++) {
        if (i->m_4 < first->m_4) {
            HE8D v = *i;
            HE8D w = v;
            *i = *first;
            func_002A8AA8(first, 0, middle - first, ((long)w.m_4 << 32) | w.m_0, cmp);
        }
    }
    func_002A8C48(first, middle, cmp);
}
}
#endif
