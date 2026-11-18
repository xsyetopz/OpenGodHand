struct cOmSub {
    unsigned char b0, b1, b2, b3;
    char pad[0x140 - 4];
    float v140, v144, v148, v14C, v150;
    void setVibration(unsigned int a, unsigned int b, float c, float d, float e);
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1C7D50
// 13 words differ: compiler schedules ori/sb after the float stores; tried reorder, temps, bitfield, byte temp
void cOmSub::setVibration(unsigned int a, unsigned int b, float c, float d, float e) {
    b3 |= 8;
    v140 = (float)(int)a;
    v150 = e;
    v144 = (float)(int)b;
    v148 = c;
    v14C = d;
}
#endif

// FUNCTION: GAME 0x1F2690
extern "C" void func_001F2690() {}

// FUNCTION: GAME 0x1F5098
extern "C" void func_001F5098() {}

// FUNCTION: GAME 0x1F6ED8
extern "C" void func_001F6ED8() {}

// FUNCTION: GAME 0x1F7B50
extern "C" void func_001F7B50() {}
