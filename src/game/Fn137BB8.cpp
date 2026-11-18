extern "C" {
int HitCheck__C5cAreaRC4cVec(void *, void *);
int HitCheck__C5cAreaRC4cVecf(void *, void *, float);
}

struct Area137 { char _0[0x30]; float f30; char _34[10]; unsigned char b3E; char _3F[0x2D]; };
struct AreaSet137 {
    Area137 *areas;
    char _4[8];
    unsigned count;
    char _10[0x20];
    Area137 *cur;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x137BB8
// 28 words: code identical except s-register allocation (orig found=s1,s=s2,best=s3,pos=s4,off=s5,i=s6); tried decl order, char* offset vs Area* index, int-returning HitCheck (fixes andi)
extern "C" int func_00137BB8(AreaSet137 *s, void *pos)
{
    if (s->areas == 0)
        return 0;
    unsigned char best = 0xFF;
    unsigned i = 0;
    Area137 *found = 0;
    if (s->count != 0) {
        do {
            Area137 *a = &s->areas[i];
            int hit;
            if (a == s->cur)
                hit = HitCheck__C5cAreaRC4cVecf(a, pos, a->f30);
            else
                hit = HitCheck__C5cAreaRC4cVec(a, pos);
            if ((unsigned char)hit) {
                if (a->b3E < best) {
                    found = a;
                    best = a->b3E;
                }
            }
            i++;
        } while (i < s->count);
    }
    if (found != 0) {
        s->cur = found;
        return 1;
    }
    s->cur = 0;
    return 0;
}
#endif
