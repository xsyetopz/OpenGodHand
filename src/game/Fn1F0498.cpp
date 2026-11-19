struct cVObj1F { char pad[0x214]; };
class cVCall1F : public cVObj1F {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4();
    virtual void v5(); virtual void v6(); virtual void v7();
};
extern "C" cVCall1F *CreateObj__F6eObjIdT0(int, int);

// FUNCTION: GAME 0x1F0498
extern "C" cVCall1F *func_001F0498(void *self, int id, float *v, float f)
{
    cVCall1F *o = CreateObj__F6eObjIdT0(id, 0xFFFF);
    if (o) {
        register char *vt asm("$3") = *(char **)((char *)o + 0x214);
        ((void (*)(char *))(*(void **)(vt + 0x44)))((char *)o + *(short *)(vt + 0x40));
        float *d = *(float **)((char *)o + 0xF0);
        if (d != v) { d[0] = v[0]; d[1] = v[1]; d[2] = v[2]; }
        *(float *)((char *)o + 0x104) = f;
    }
    return o;
}
