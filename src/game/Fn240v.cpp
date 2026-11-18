struct Qv2 { float f[4]; };
extern "C" void setParent__9cOmWeaponP8cGameObjUiRC4cVecT3(void *, void *, unsigned, void *, void *);

// FUNCTION: GAME 0x26ADF8
extern "C" void func_0026ADF8(char *self, void *w, int flag)
{
    Qv2 pos;
    Qv2 rot;
    unsigned n;
    if (!w)
        return;
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(pos));
    __asm__ volatile("sqc2 $vf0,%0" : "=m"(rot));
    if (*(int *)(self + 0x564) != 0x225 && *(int *)(self + 0x564) != 0x24D) {
        n = 10;
        pos.f[0] = -0.28f; pos.f[1] = -0.035f; pos.f[2] = 0.185f;
        rot.f[0] = 0.0f; rot.f[1] = -0.7853982f; rot.f[2] = 0.0f;
        if (flag) {
            pos.f[0] = 0.28f;
            n = 16;
            rot.f[1] = 0.7853982f;
        }
    } else {
        pos.f[0] = -0.08f; pos.f[1] = -0.03f; pos.f[2] = 0.0f;
        rot.f[0] = 0.0f; rot.f[1] = 0.0f; rot.f[2] = 0.0f;
        n = 10;
        if (flag) {
            pos.f[0] = 0.08f;
            n = 16;
            rot.f[2] = 3.1415927f;
        }
    }
    setParent__9cOmWeaponP8cGameObjUiRC4cVecT3(w, self, n, &pos, &rot);
}
