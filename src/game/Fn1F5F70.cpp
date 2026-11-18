struct sSt {
    short off;
    short _pad;
    void (*fn)(void *);
};
struct sSndObj {
    char _0;
    unsigned char st;
    unsigned char b2;
    unsigned char b3;
    char _4;
    unsigned char b5;
    char _6[2];
    int cnt;
    char _c[0x24 - 0xC];
    int bgm;
};
extern sSt D_003BF0F8[];
extern long D_00747640;
extern char Snd;
extern "C" void func_001F6680(sSndObj *);
extern "C" void func_001F6758(sSndObj *);
extern "C" void func_001F6A20(sSndObj *);
extern "C" int func_002D1578(void *, int);
extern "C" void BgmEventStart__4cSnd9eBgmReqNoii(void *, int, int, int);

// FUNCTION: GAME 0x1F5F70
extern "C" void func_001F5F70(sSndObj *self)
{
    int o = self->st << 3;
    short *e = (short *)(o + (int)D_003BF0F8);
    (*(void (**)(void *))((int)D_003BF0F8 + o + 4))((char *)self + *e);
    if (D_00747640 & 0x20000000) {
        self->b2 = 0;
        self->st = 2;
        self->b3 = 0;
    }
    func_001F6680(self);
    func_001F6758(self);
    func_001F6A20(self);
    if (--self->cnt < 0) {
        if (self->b5 != 0) {
            if (self->bgm != -2) {
                self->b5 = 0;
                BgmEventStart__4cSnd9eBgmReqNoii(&Snd, self->bgm, 0, 0);
            }
        } else if (self->bgm != -2) {
            void *s = &Snd;
            if (func_002D1578(s, self->bgm) == 0)
                BgmEventStart__4cSnd9eBgmReqNoii(s, self->bgm, 0, 0);
        }
    }
}
