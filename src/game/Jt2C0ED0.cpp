// Flag-bit query on the word at +0x50; sole switch of 0x2C0ED0.
// DRAFT: GAME 0x2C0ED0 - gcc turns single-bit tests into shifts (sra/andi); original keeps lui/and/sltu with a shared tail (33 words differ)
#ifdef NONMATCHING
extern "C" int func_002C0ED0(char *self, unsigned id)
{
    unsigned *p = (unsigned *)(self + 0x50);
    switch (id) {
    case 0:
        return (int)*p < 0;
    case 1:
        return (*p & 0x20000000) != 0;
    case 2:
        return (*p & 0x10000000) != 0;
    case 3: {
        unsigned v = *p;
        return ((int)v < 0) ^ ((v & 0x40000000) != 0);
    }
    case 4:
        return (*p & 0x8000000) != 0;
    case 5: {
        unsigned v = *p;
        if ((int)v < 0)
            return (v & 0x8000000) != 0;
        return 0;
    }
    case 6:
        return (*p & 0x4000000) != 0;
    case 7:
        return (*p & 0x2000000) != 0;
    }
    return 0;
}
#endif
