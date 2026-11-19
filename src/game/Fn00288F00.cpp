extern "C" void *Getplayer__Fv();
extern "C" int SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern char Snd;
extern unsigned short D_00747A50;

struct cEma2 {
    void setDamage();
};

#ifdef NONMATCHING
// DRAFT: GAME 0x288F00
// 27 words off: original shares the 2F7/2F4/2F5/2F6 tail and hoists v0=1/2; tried goto tails and a shared char v, both worse (28, 32).
void cEma2::setDamage()
{
    char *self = (char *)this;
    char *pl = (char *)Getplayer__Fv();
    if (*(short *)(self + 0x54A) > 0) {
        SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(&Snd, 0, 0x96, self, 0, 0, 0, 0);
        if (D_00747A50 == 0x501)
            *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x54A) - (int)(*(float *)(pl + 0x600) * 10.0f);
        else
            *(short *)(self + 0x54A) = *(unsigned short *)(self + 0x54A) - 1;
        if (*(short *)(self + 0x54A) <= 0) {
            if ((*(int *)(self + 0x15B0) & 2) || (*(unsigned short *)(self + 0x3AC) & 2)) {
                self[0x2F4] = 2;
                self[0x2F5] = 1;
                self[0x2F7] = 0;
            } else {
                self[0x2F7] = 0;
                self[0x2F4] = 2;
                self[0x2F5] = 0;
            }
            self[0x2F6] = 0;
        } else {
            if ((*(int *)(self + 0x15B0) & 2) || (*(unsigned short *)(self + 0x3AC) & 2)) {
                self[0x2F6] = 0;
                self[0x2F7] = 1;
                self[0x2F4] = 1;
                self[0x2F5] = 1;
            } else {
                self[0x2F7] = 0;
                self[0x2F4] = 1;
                self[0x2F5] = 0;
                self[0x2F6] = 0;
            }
        }
    }
}
#endif
