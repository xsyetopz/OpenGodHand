// Mid-size units in 0x1E0000-0x1F6000.
#include "game/cVec.h"

extern "C" void setSubScrCamera__11cCamManagerUc(void *, unsigned char);
extern char CamManager[];

// FUNCTION: GAME 0x1E32E8
extern "C" void func_001E32E8(char *self, cVec *a, cVec *b)
{
    setSubScrCamera__11cCamManagerUc(CamManager, 0);
    *(char **)(self + 0x498) = CamManager + 0xC90;
    *(cVec *)(CamManager + 0xEA0) = *a;
    *(cVec *)(*(char **)(self + 0x498) + 0x200) = *b;
}

// FUNCTION: GAME 0x1E6870
extern "C" void func_001E6870(char *self, cVec *a, cVec *b)
{
    setSubScrCamera__11cCamManagerUc(CamManager, 0);
    *(char **)(self + 0x3DC) = CamManager + 0xC90;
    *(cVec *)(CamManager + 0xEA0) = *a;
    *(cVec *)(*(char **)(self + 0x3DC) + 0x200) = *b;
}

// FUNCTION: GAME 0x1EB718
extern "C" void func_001EB718(char *self, cVec *a, cVec *b)
{
    setSubScrCamera__11cCamManagerUc(CamManager, 0);
    *(char **)(self + 0x200) = CamManager + 0xC90;
    *(cVec *)(CamManager + 0xEA0) = *a;
    *(cVec *)(*(char **)(self + 0x200) + 0x200) = *b;
}

extern "C" void func_001E4520(char *, int);

// FUNCTION: GAME 0x1E3128
extern "C" void func_001E3128(char *self)
{
    switch (*(int *)(self + 0xC)) {
    case 0: {
        unsigned short *tp = (unsigned short *)(self + 0x4C2);
        if (*tp != 0) {
            int n = *tp - 1;
            *tp = n;
            if ((unsigned short)n == 0) {
                *(int *)(self + 0x54) &= -0x101;
                func_001E4520(self, 0);
            }
        }
        *(int *)(self + 0xC) += 1;
        break;
    }
    case 1:
        *(int *)(self + 4) = 0;
        *(int *)(self + 8) = 0;
        *(int *)(self + 0xC) = 0;
        break;
    }
}
