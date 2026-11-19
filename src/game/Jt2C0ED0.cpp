// Flag-bit query on the word at +0x50; sole switch of 0x2C0ED0.
// DRAFT: GAME 0x2C0ED0 - 7 words off: case 3 sign via slti and case 5 bgez/lui order; per-case local unsigned k and if-form sign test help; (int)v<0 in an expression gives srl
#ifdef NONMATCHING
extern "C" int func_002C0ED0(char *self, unsigned id)
{
    unsigned *p = (unsigned *)(self + 0x50);
    switch (id) {
    case 0:
        if (*(int *)p < 0)
            return 1;
        return 0;
    case 1: {
        unsigned k = 0x20000000;
        return (*p & k) != 0;
    }
    case 2: {
        unsigned k = 0x10000000;
        return (*p & k) != 0;
    }
    case 3: {
        unsigned v = *p;
        unsigned k = 0x40000000;
        int sg = 0;
        if ((int)v < 0)
            sg = 1;
        return sg ^ ((v & k) != 0);
    }
    case 4: {
        unsigned k = 0x8000000;
        return (*p & k) != 0;
    }
    case 5: {
        unsigned v = *p;
        if ((int)v >= 0)
            return 0;
        return (v & 0x8000000) != 0;
    }
    case 6: {
        unsigned k = 0x4000000;
        return (*p & k) != 0;
    }
    case 7: {
        unsigned k = 0x2000000;
        return (*p & k) != 0;
    }
    }
    return 0;
}
#endif
