extern "C" void func_00150710(float x, float y, float z);
class cVec;
class cMatrix;

#define FSQ(x) asm volatile("nop\n\tnop\n\tsqrt.s %0,%0" : "+f"(x))

// FUNCTION: GAME 0x148160
void MtxGetScaleVec(cVec &, const cMatrix &m)
{
    const float *p = (const float *)&m;
    float a = p[0] * p[0] + p[1] * p[1] + p[2] * p[2];
    FSQ(a);
    float b = p[4] * p[4] + p[5] * p[5] + p[6] * p[6];
    FSQ(b);
    float c = p[8] * p[8] + p[9] * p[9] + p[10] * p[10];
    FSQ(c);
    func_00150710(a, b, c);
}
