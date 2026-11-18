// cIDBase batch mover.
extern "C" void trans__7cIDBase(char *self);
extern "C" char *getIDWork__7cIDBasei(char *self, int i);
extern "C" void move__7cIDBase(char *self, float *a, unsigned char *b, int *c);

struct Fn143 {
    char _p0[0xB0];
    char id[0x50];
    float f[16];
    int c[16];
    unsigned char b[16];
    unsigned char on[16];
};

#ifdef NONMATCHING
// DRAFT: GAME 0x143998
// 59 differing words: original hoists base pointers (self+0x100/1B0/140/1A0) into s3-s6 and builds a/b/c directly in a1-a3; tried flat char* bases (58), inline exprs (70).
extern "C" void func_00143998(Fn143 *self)
{
    trans__7cIDBase(self->id);
    char *w = getIDWork__7cIDBasei(self->id, 0);
    unsigned i = 0;
    do {
        float *a = &self->f[i];
        unsigned char *b = &self->b[i];
        int *c = &self->c[i];
        if (self->on[i] == 1) {
            *(float *)(w + 0x3C) = *(float *)(*(char **)(w + 0x1C) + 0xC) + *a;
            *(unsigned char *)(w + 0x4F) = *b;
            *(int *)(w + 0x84) = *c;
            move__7cIDBase(self->id, a, b, c);
            trans__7cIDBase(self->id);
        }
        i = (i + 1) & 0xFFFF;
    } while (i < 0x10);
}
#endif
