// Free units in 0x130000-0x140000.

class cVec {
public:
    cVec() {}
    cVec(float a, float b, float c, float d = 1.0f) : x(a), y(b), z(c), w(d) {}
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w;
};
struct cMat { float m[16]; };
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(cMat *, const cVec *, unsigned char);
class cCamera {
public:
    void reset();
    void resetVib();
    cVec calcRotation(const cVec &, const cVec &) const;
    char _p0[0x1C0]; int m1C0; char _p1[0x200-0x1C4]; cVec v200, v210, v220, v230, v240; float f250;
};
// FUNCTION: GAME 0x138240
void cCamera::reset() {
    v200 = cVec(0.0f, 0.0f, 0.0f);
    v210 = cVec(2.8f, 2.1f, 2.8f);
    v220 = calcRotation(v210, v200);
    cMat m;
    MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, &v220, 4);
    v240 = cVec(0.0f, 1.0f, 0.0f);
    m1C0 = 0;
    f250 = 31.0f;
    resetVib();
}
