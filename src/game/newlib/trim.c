// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/mallocr.c malloc_trim (0x3ACD20); long is 64-bit on EE, so / and * go through libgcc.
struct _reent;
struct chunk {
    unsigned int prev_size;
    unsigned int size;
};
struct arena {
    int pad[2];
    struct chunk *top;
};
extern struct arena D_003FA9D0;
extern long D_003FADE8, D_003FAE00;

void *sbrk_(struct _reent *, long) __asm__("func_003AE0C8");
void lock_(struct _reent *) __asm__("func_003A8048");
void unlock_(struct _reent *) __asm__("func_003A80A8");
long divdi_(long, long) __asm__("func_003B8E88");
long muldi_(long, long) __asm__("func_0031DE10");

#ifdef NONMATCHING
// DRAFT: GAME 0x3ACD20
// diff: 66 words; original calls libgcc divdi/muldi (func_003B8E88/func_0031DE10) for the page rounding, ours inlines it
int func_003ACD20(struct _reent *r, unsigned int pad)
{
    long top_size, pagesz = 4096;
    int extra;
    char *cur, *nb;

    lock_(r);
    top_size = D_003FA9D0.top->size & ~3;
    extra = ((top_size - pad - 16 + (pagesz - 1)) / pagesz - 1) * pagesz;
    if (extra < pagesz) {
        unlock_(r);
        return 0;
    }
    cur = sbrk_(r, 0);
    if (cur == (char *)D_003FA9D0.top + top_size) {
        nb = sbrk_(r, -extra);
        if (nb == (char *)0xFFFFFFFFFFFFFFFFL) {
            cur = sbrk_(r, 0);
            top_size = cur - (char *)D_003FA9D0.top;
            if (top_size >= 16) {
                D_003FAE00 = cur - (char *)D_003FADE8;
                D_003FA9D0.top->size = top_size | 1;
            }
            unlock_(r);
            return 0;
        }
        D_003FA9D0.top->size = (top_size - extra) | 1;
        D_003FAE00 -= extra;
        unlock_(r);
        return 1;
    }
    unlock_(r);
    return 0;
}

#endif
