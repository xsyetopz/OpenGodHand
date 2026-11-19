// Units: setOmSuspend__9cScenariob (0x2C5068), func_002D4DA0 (0x2D4DA0).

typedef int fn_u128 __attribute__((mode(TI)));
struct fn_blk20 { fn_u128 q[2]; };
struct fn_objarr { int pad0; void **begin; void **end; };

extern "C" fn_objarr *objbaseArray;

#ifdef NONMATCHING
// DRAFT: GAME 0x2C5068
// 37 differing words, 160 bytes. The range flag and arg1 branch shape miss the
// original's a2 flag and delay-slot increment. Tried: &&-range do-while, bool
// flag in for loop, char ternary flag, unsigned char flag in do-while and for,
// and swapped arg1 arms (38 words).
extern "C" void setOmSuspend__9cScenariob(int arg1)
{
    void **p;
    for (p = objbaseArray->begin; p < objbaseArray->end; p++) {
        char *o = (char *)*p;
        int t = *(unsigned short *)(o + 0x2FE);
        unsigned char in = 0;
        if (t >= 0x300)
            in = t < 0x500;
        if (in) {
            if (arg1 != 1) {
                *(unsigned int *)(o + 0x250) &= 0xFFFF7FFF;
            } else if (!(((unsigned long)*(unsigned int *)(o + 0x5B8) >> 6) & 1)) {
                *(unsigned int *)(o + 0x250) |= 0x8000;
            }
        }
    }
}
#endif

// FUNCTION: GAME 0x2D4DA0
extern "C" void func_002D4DA0(void)
{
    __asm__ volatile(".set noreorder\n\tsync\n\t1: nop\n\tnop\n\tnop\n\tnop\n\tbc0f 1b\n\tnop\n\tnop\n\t.set reorder");
}
