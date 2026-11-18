// Jump-table unit; this file holds no other .rodata.
extern "C" int func_002965F0(void *);
extern "C" int func_00296818(void *);
extern "C" int func_00296958(void *);
extern "C" int func_00296C28(void *);
extern "C" void func_00296DD8(void *);
extern "C" void func_00297038(void *);

struct Ev {
    char _p0[4];
    char state;
    char _p1[3];
    int flags;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x296530 (1 insn off: sra v0,v1,3 where original has dsrl)
extern "C" void func_00296530(Ev *self)
{
    int f = self->flags;
    unsigned long b = ((unsigned long)(long)f >> 3) & 1;
    if (!b) {
        if (f & 1) {
            switch (self->state) {
            case 0:
                if (!func_002965F0(self))
                    return;
            case 1:
                if (!func_00296818(self))
                    return;
            case 2:
                if (!func_00296958(self))
                    return;
            case 3:
                if (!func_00296C28(self))
                    return;
            case 4:
                func_00297038(self);
            }
        }
    } else
        func_00296DD8(self);
}
#endif
