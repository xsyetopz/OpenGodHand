enum eEffDataType { };
enum eEffId { };
class cObj;
extern void *SetEffect(eEffDataType, eEffId, cObj *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
struct P {
    float f0[4];
    float v10[4];
    float v20[4];
    float f30[4];
    float f40;
    int i44, i48;
    unsigned char b4C, b4D, b4E, b4F;
    int i50;
    int pad54[3];
    float v60[4];
    short h70, h72;
    char b74;
    int i78;
} __attribute__((aligned(16)));

// FUNCTION: GAME 0x306900
void SetEffectParts(eEffDataType t, eEffId id, cObj *o, int k, float a, float b, float c, float d, int e)
{
    P p;
    p.f0[0] = 1.0f; p.f0[1] = 1.0f; p.f0[2] = 1.0f; p.f0[3] = 1.0f;
    __asm__ volatile("sqc2 $vf0,0x10(%0)\n\tsqc2 $vf0,0x20(%0)" : : "r"(&p) : "memory");
    p.f30[0] = 1.0f;
    float *q = p.f30;
    q[1] = 1.0f; q[2] = 1.0f; q[3] = 1.0f;
    p.f40 = 1.0f;
    int mm = -1;
    p.b4C = mm; p.b4F = 0xFF;
    p.i44 = 0; p.i48 = 0; p.b4D = 0; p.b4E = 0; p.i50 = 0;
    __asm__ volatile("sqc2 $vf0,0x60(%0)" : : "r"(&p) : "memory");
    p.b4C = k;
    p.v20[0] = a; p.v20[1] = b; p.v20[2] = c; p.f40 = d;
    p.h70 = 0; p.h72 = 0; p.b74 = 0; p.i78 = 0;
    SetEffect(t, id, o, &p, e, -1);
}
