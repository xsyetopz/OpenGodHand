// Unit at 0x37A0F0.
struct Ent { int w[8]; };
extern Ent Sde_iss_hed[];
extern Ent D_0076E510[];
extern Ent D_0076EA50[];

struct Obj { char pad[7]; signed char type; short cnt[1]; };

#ifdef NONMATCHING
// DRAFT: GAME 0x37A0F0 - 52 words differ: original keeps self in t2 and reloads lb type each iteration; ours hoists type as lbu+shifts. Tried if-chain, switch, volatile type (53).
extern "C" short func_0037A0F0(Obj *self, short a, short step)
{
    short cnt = *(short *)((char *)self + 0x10 + self->type * 2);
    if (cnt > 0) {
        int k = 0x10000;
        do {
            short i = a;
            if (i < 0)
                i = cnt - 1;
            if (i >= cnt)
                i = 0;
            int v;
            switch (self->type) {
            case 0:
                v = Sde_iss_hed[i].w[0];
                break;
            case 1:
                v = D_0076E510[i].w[0];
                break;
            case 2:
                v = D_0076EA50[i].w[5];
                break;
            default:
                v = 0;
            }
            if (v)
                return i;
            a = i + step;
            k += 0x10000;
        } while ((k >> 16) < cnt);
    }
    return -1;
}
#endif
