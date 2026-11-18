struct V3_001C6A90 {
    float x, y, z;
};
extern "C" void func_001C7138(void *);
extern "C" void func_001C7310(void *);
extern "C" void setReverse__6cOmSubb(char *self, int b);

// FUNCTION: GAME 0x1C6A90
extern "C" void func_001C6A90(char *self, unsigned a, V3_001C6A90 *p, V3_001C6A90 *q, unsigned char t, float f0, float f1)
{
    self[3] = t;
    self[2] = 0;
    self[0] = 0;
    *(float *)(self + 0x30) = (float)a;
    V3_001C6A90 *d = (V3_001C6A90 *)(self + 0x90);
    if (d != p) {
        d->x = p->x;
        d->y = p->y;
        d->z = p->z;
    }
    V3_001C6A90 *e = (V3_001C6A90 *)(self + 0xA0);
    if (e != q) {
        e->x = q->x;
        e->y = q->y;
        e->z = q->z;
    }
    *(float *)(self + 0x138) = f0;
    *(float *)(self + 0x13C) = f1;
    *(float *)(self + 0x130) = f0;
    *(float *)(self + 0x134) = f1;
    func_001C7138(self);
    func_001C7310(self);
    setReverse__6cOmSubb(self, 0);
}
