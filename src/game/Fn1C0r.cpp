struct V3 {
    float x, y, z;
};
extern char CamManager[];
extern "C" void setSubScrCamera__11cCamManagerUc(void *, unsigned char);

// FUNCTION: GAME 0x001D44D8
extern "C" void SetBlackJackCamera__9BlackJackG4cVecT1(char *self, V3 *a, V3 *b)
{
    setSubScrCamera__11cCamManagerUc(CamManager, 0);
    V3 *p = (V3 *)(CamManager + 0xEA0);
    *(char **)(self + 0x181C) = CamManager + 0xC90;
    if (a != p) {
        p->x = a->x;
        p->y = a->y;
        p->z = a->z;
    }
    V3 *c = (V3 *)(*(char **)(self + 0x181C) + 0x200);
    if (c != b) {
        c->x = b->x;
        c->y = b->y;
        c->z = b->z;
    }
}


extern "C" void func_001D51B8(void *, int, int);

// FUNCTION: GAME 0x001D52A0
extern "C" void SetDefaultDisp__11BlackJackId(void *self)
{
    func_001D51B8(self, 0x2D, 0);
    func_001D51B8(self, 1, 1);
    func_001D51B8(self, 2, 1);
    func_001D51B8(self, 3, 1);
    func_001D51B8(self, 4, 1);
    func_001D51B8(self, 0xA, 1);
    func_001D51B8(self, 0xC, 1);
    func_001D51B8(self, 0xF, 1);
    func_001D51B8(self, 0x22, 1);
    func_001D51B8(self, 0x19, 1);
}

extern "C" void func_001C7138(void *);
extern "C" void func_001C7310(void *);
extern "C" void calcParts__6cModel(void *);

// FUNCTION: GAME 0x001C7CA0
extern "C" void setReverse__6cOmSubb(char *self, int b)
{
    if (b == 1)
        self[1] = b;
    else
        self[1] = 0;
    self[0] = 0;
    if (b == 1) {
        float a = *(float *)(self + 0x13C);
        float c = *(float *)(self + 0x138);
        *(float *)(self + 0x130) = a;
        *(float *)(self + 0x134) = c;
    } else {
        float a = *(float *)(self + 0x138);
        float c = *(float *)(self + 0x13C);
        *(float *)(self + 0x130) = a;
        *(float *)(self + 0x134) = c;
    }
    func_001C7138(self);
    func_001C7310(self);
    void *m = *(void **)(self + 4);
    if (m) {
        calcParts__6cModel(m);
        void **p = (void **)(self + 0xC);
        unsigned i = 0;
        do {
            if (*p)
                calcParts__6cModel(*p);
            i++;
            p++;
        } while (i < 8);
    }
}

struct COL {
    unsigned r : 8;
    unsigned g : 8;
    unsigned b : 8;
    unsigned a : 8;
};
extern "C" void SetColorAnimSin__12CustomIDWorkG3COLT1Us(void *, COL, COL, unsigned short);
extern "C" void ResetColorAnim__12CustomIDWork(void *);

// FUNCTION: GAME 0x001D57A0
extern "C" void func_001D57A0(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x5B4, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x5B4);
    }
}

// FUNCTION: GAME 0x001D5848
extern "C" void func_001D5848(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x4BC, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x4BC);
    }
}

// FUNCTION: GAME 0x001D58F0
extern "C" void func_001D58F0(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x6AC, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x6AC);
    }
}

// FUNCTION: GAME 0x001D5998
extern "C" void func_001D5998(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x105C, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x105C);
    }
}


// FUNCTION: GAME 0x001D5A40
extern "C" void func_001D5A40(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x3C4, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x3C4);
    }
}


// FUNCTION: GAME 0x001D5AE8
extern "C" void func_001D5AE8(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x2CC, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x2CC);
    }
}


// FUNCTION: GAME 0x001D5B90
extern "C" void func_001D5B90(char *self, int on)
{
    COL c1, c2;
    if (on) {
        c1.r = 0x60;
        c1.g = 0x60;
        c1.b = 0x60;
        c1.a = 0x50;
        c2.r = 0xA0;
        c2.g = 0xA0;
        c2.b = 0xA0;
        c2.a = 0x80;
        SetColorAnimSin__12CustomIDWorkG3COLT1Us(self + 0x820, c1, c2, 3);
    } else {
        ResetColorAnim__12CustomIDWork(self + 0x820);
    }
}
