#include "game/CustomIDWork.h"
#include "game/cIDBase.h"

// Small unnamed functions in 0x1E0000-0x1EFFFF.

class cCamManager {
public:
    void setPlCamera(unsigned char v);
};
extern cCamManager CamManager;

extern "C" void func_001EC928(int, int);

// FUNCTION: GAME 0x1ED488
extern "C" void func_001ED488(char *p, int v)
{
    *(int *)(p + 0x162C) = v;
}

// FUNCTION: GAME 0x1EF740
extern "C" void func_001EF740()
{
}

// FUNCTION: GAME 0x1EE768
extern "C" int *func_001EE768(int *p)
{
    p[12] = 0;
    p[0] = 0;
    return p;
}

// FUNCTION: GAME 0x1ED7C8
extern "C" void func_001ED7C8(unsigned int *p)
{
    p[0xD2] = 0;
    p[0] |= 1;
}

// FUNCTION: GAME 0x1E7868
extern "C" void func_001E7868(char *self, int n)
{
    ((CustomIDWork *)(self + 0x240))->SetNumber(n);
}

// FUNCTION: GAME 0x1E7888
extern "C" void func_001E7888(char *self, int n)
{
    ((CustomIDWork *)(self + 0x2BC))->SetNumber(n);
}

// FUNCTION: GAME 0x1E78A8
extern "C" void func_001E78A8(char *self, int n)
{
    ((CustomIDWork *)(self + 0x338))->SetNumber(n);
}

// FUNCTION: GAME 0x1E78C8
extern "C" void func_001E78C8(char *self, int n)
{
    ((CustomIDWork *)(self + 0x3B4))->SetNumber(n);
}

// FUNCTION: GAME 0x1E78E8
extern "C" void func_001E78E8(char *self, int n)
{
    ((CustomIDWork *)(self + 0x430))->SetNumber(n);
}

// FUNCTION: GAME 0x1EE2C8
extern "C" void func_001EE2C8(char *self, int n)
{
    ((CustomIDWork *)(self + 0xA10))->SetNumber(n);
}

// FUNCTION: GAME 0x1ECA60
extern "C" void func_001ECA60()
{
    func_001EC928(1, 0xFFFF);
}

// FUNCTION: GAME 0x1E3388
extern "C" void func_001E3388()
{
    CamManager.setPlCamera(0);
}

// FUNCTION: GAME 0x1E6910
extern "C" void func_001E6910()
{
    CamManager.setPlCamera(0);
}

// FUNCTION: GAME 0x1EB9F8
extern "C" void func_001EB9F8()
{
    CamManager.setPlCamera(0);
}

// FUNCTION: GAME 0x1EE9A0
extern "C" void func_001EE9A0(int *p)
{
    char *o = *(char **)p;
    if (o) {
        o[0x2F4] = 2;
        p[0] = 0;
    }
    *((char *)p + 4) = 0;
    p[11] = 0;
    p[12] = 0;
}
