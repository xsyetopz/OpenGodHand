// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/mallocr.c _free_r (0x3ACA28), Doug Lea malloc 2.6.x.
struct _reent;
typedef struct malloc_chunk *mchunkptr;
typedef struct malloc_chunk *mbinptr;
struct malloc_chunk {
    unsigned int prev_size;
    unsigned int size;
    struct malloc_chunk *fd;
    struct malloc_chunk *bk;
};

extern mbinptr D_003FA9D0[];
extern unsigned long D_003FADD8;
extern unsigned int D_003FADE0;

void lock_(struct _reent *) __asm__("func_003A8048");
void unlock_(struct _reent *) __asm__("func_003A80A8");
int trim_(struct _reent *, unsigned int) __asm__("func_003ACD20");

#define av_ D_003FA9D0
#define trim_threshold D_003FADD8
#define top_pad D_003FADE0
#define bin_at(i) ((mbinptr)((char *)&(av_[2 * (i) + 2]) - 8))
#define top (bin_at(0)->fd)
#define last_remainder (bin_at(1))
#define binblocks (*(unsigned int *)&av_[1])
#define PREV_INUSE 1
#define chunksize(p) ((p)->size & ~(3))
#define chunk_at_offset(p, s) ((mchunkptr)(((char *)(p)) + (s)))
#define inuse_bit_at_offset(p, s) (((mchunkptr)(((char *)(p)) + (s)))->size & PREV_INUSE)
#define set_head(p, s) ((p)->size = (s))
#define set_foot(p, s) (((mchunkptr)((char *)(p) + (s)))->prev_size = (s))
#define unlink(P, BK, FD) \
    {                     \
        BK = (P)->bk;     \
        FD = (P)->fd;     \
        FD->bk = BK;      \
        BK->fd = FD;      \
    }
#define idx2binblock(ix) (1 << ((ix) / 4))
#define mark_binblock(ii) (binblocks |= idx2binblock(ii))
#define smallbin_index(sz) (((unsigned long)(sz)) >> 3)
#define bin_index(sz)                                                           \
    (((((unsigned long)(sz)) >> 9) == 0) ? (((unsigned long)(sz)) >> 3) :       \
     ((((unsigned long)(sz)) >> 9) <= 4)  ? (56 + (((unsigned long)(sz)) >> 6)) : \
     ((((unsigned long)(sz)) >> 9) <= 20) ? (91 + (((unsigned long)(sz)) >> 9)) : \
     ((((unsigned long)(sz)) >> 9) <= 84) ? (110 + (((unsigned long)(sz)) >> 12)) : \
     ((((unsigned long)(sz)) >> 9) <= 340) ? (119 + (((unsigned long)(sz)) >> 15)) : \
     ((((unsigned long)(sz)) >> 9) <= 1364) ? (124 + (((unsigned long)(sz)) >> 18)) : 126)
#define frontlink(P, S, IDX, BK, FD)                       \
    {                                                      \
        if (S < 0x200) {                                   \
            IDX = smallbin_index(S);                       \
            mark_binblock(IDX);                            \
            BK = bin_at(IDX);                              \
            FD = BK->fd;                                   \
            P->bk = BK;                                    \
            P->fd = FD;                                    \
            FD->bk = BK->fd = P;                           \
        } else {                                           \
            IDX = bin_index(S);                            \
            BK = bin_at(IDX);                              \
            FD = BK->fd;                                   \
            if (FD == BK)                                  \
                mark_binblock(IDX);                        \
            else {                                         \
                while (FD != BK && S < chunksize(FD))      \
                    FD = FD->fd;                           \
                BK = FD->bk;                               \
            }                                              \
            P->bk = BK;                                    \
            P->fd = FD;                                    \
            FD->bk = BK->fd = P;                           \
        }                                                  \
    }
#define link_last_remainder(P)                  \
    {                                           \
        last_remainder->fd = last_remainder->bk = P; \
        P->fd = P->bk = last_remainder;         \
    }

#ifdef NONMATCHING
// DRAFT: GAME 0x3ACA28
// diff: 67 words; the trim_threshold ld is hoisted above the set_head store, and binblocks is OR-ed with a 32-bit sllv where the original uses dsllv
void func_003ACA28(struct _reent *reent_ptr, void *mem)
{
    mchunkptr p;
    unsigned int hd;
    unsigned int sz;
    int idx;
    mchunkptr next;
    unsigned int nextsz;
    unsigned int prevsz;
    int islr;
    mbinptr bck;
    mchunkptr fwd;

    if (mem == 0)
        return;
    lock_(reent_ptr);
    p = (mchunkptr)((char *)mem - 8);
    hd = p->size;
    sz = hd & ~PREV_INUSE;
    next = chunk_at_offset(p, sz);
    nextsz = chunksize(next);
    if (next == top) {
        sz += nextsz;
        if (!(hd & PREV_INUSE)) {
            prevsz = p->prev_size;
            p = chunk_at_offset(p, -(long)prevsz);
            sz += prevsz;
            unlink(p, bck, fwd);
        }
        set_head(p, sz | PREV_INUSE);
        top = p;
        if ((unsigned long)(sz) >= (unsigned long)trim_threshold)
            trim_(reent_ptr, top_pad);
        unlock_(reent_ptr);
        return;
    }
    set_head(next, nextsz);
    islr = 0;
    if (!(hd & PREV_INUSE)) {
        prevsz = p->prev_size;
        p = chunk_at_offset(p, -(long)prevsz);
        sz += prevsz;
        if (p->fd == last_remainder)
            islr = 1;
        else
            unlink(p, bck, fwd);
    }
    if (!(inuse_bit_at_offset(next, nextsz))) {
        sz += nextsz;
        if (!islr && next->fd == last_remainder) {
            islr = 1;
            link_last_remainder(p);
        } else
            unlink(next, bck, fwd);
    }
    set_head(p, sz | PREV_INUSE);
    set_foot(p, sz);
    if (!islr)
        frontlink(p, sz, idx, bck, fwd);
    unlock_(reent_ptr);
}
#endif
