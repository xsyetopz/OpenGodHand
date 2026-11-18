extern "C" void *memset(void *, int, unsigned int);
extern "C" void *memcpy(void *, const void *, unsigned int);

struct S4 {
    unsigned short a, b, c, d;
};

// FUNCTION: GAME 0x2C7E30
extern "C" S4 func_002C7E30(const void *src, unsigned char t) {
    S4 tmp;
    memset(&tmp, 0, 8);
    if (t == 1)
        memcpy(&tmp, src, 8);
    return tmp;
}
