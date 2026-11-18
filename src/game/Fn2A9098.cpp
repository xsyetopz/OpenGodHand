// Insertion step of a sort keyed on the float at +4 of each 8-byte element.
struct Elem {
    int a;
    float key;
};

// FUNCTION: GAME 0x2A9098
extern "C" void func_002A9098(Elem *p, Elem key)
{
    Elem *q = p - 1;
    while (key.key < q->key) {
        *p = *q;
        p = q;
        q = p - 1;
    }
    *p = key;
}
