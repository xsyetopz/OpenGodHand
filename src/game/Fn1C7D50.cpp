struct cOmSub {
    unsigned char b0, b1, b2, b3;
    char pad[0x140 - 4];
    float v140, v144, v148, v14C, v150;
    void setVibration(unsigned int a, unsigned int b, float c, float d, float e);
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1C7D50
// 12 words differ: orig has lbu/ori/sb first, compiler puts it between the 0x150 and 0x148 stores; 12 = b3 RMW last (kept). Tried reorder, temps, bitfield, byte temp, volatile byte/float ptrs, RMW after first store (13), hoisted float locals (12 or 13)
void cOmSub::setVibration(unsigned int a, unsigned int b, float c, float d, float e) {
    v140 = (float)(int)a;
    v150 = e;
    v144 = (float)(int)b;
    v148 = c;
    v14C = d;
    b3 |= 8;
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
