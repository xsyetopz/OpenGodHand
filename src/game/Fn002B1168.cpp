extern "C" char *getMessageAddr__C8cMessageUs(char *, unsigned short);
extern "C" int getCodeSize__11cMessCommonUs(unsigned short);
extern "C" int func_002A4B88(void *, unsigned short);
extern char *Message;
extern void *Font;

#ifdef NONMATCHING
// DRAFT: GAME 0x2B1168
// 65 differing words: gcc hoists 0x8000 and Font lui into s3/s4 and rotates loop differently; tried for(;;)+return, while+break
extern "C" float func_002B1168(char *self, unsigned short id, float *scale)
{
    float best = 0.0f;
    unsigned short *p = (unsigned short *)getMessageAddr__C8cMessageUs(Message, id);
    for (;;) {
        unsigned short c = *p;
        if ((c >> 15) == 0) {
            float w = (float)func_002A4B88(Font, *p) * (*scale * *(float *)(self + 0x40) * *(float *)(self + 0x48));
            if (best < w)
                best = w;
        } else if ((c & 0xFF00) == 0x8000) {
            if (*(int *)self & 1)
                best += (*(float *)(self + 0x38) + 12.0f) * *(float *)(self + 0x48);
            return best;
        }
        p += getCodeSize__11cMessCommonUs(*p);
    }
}
#endif
