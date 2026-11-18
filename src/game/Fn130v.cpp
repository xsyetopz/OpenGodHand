// Free units in 0x130000-0x140000 (motion camera setup).

struct Q4 { float v[4]; } __attribute__((aligned(16)));
class cVec {
public:
    cVec() {}
    cVec(float a, float b, float c, float d = 1.0f) : x(a), y(b), z(c), w(d) {}
    cVec(const cVec &o) { __asm__ volatile("lqc2 $vf4,0(%1)\n\tsqc2 $vf4,%0" : "=m"(*(Q4 *)this) : "r"(&o)); }
    cVec &operator=(const cVec &o) { if (this != &o) { x = o.x; y = o.y; z = o.z; } return *this; }
    float x, y, z, w;
} __attribute__((aligned(16)));
class cParts;
class cCamera { public:
    enum eMode { M0, M1, M2, M3 };
    void setMode(eMode);
    char _p0[0x27A]; short m27A; char _p1[0x2B4-0x27C]; float m2B4; char _p2[0x3A4-0x2B8];
    unsigned m3A4; int m3A8; cParts *m3AC; cVec m3B0; float m3C0, m3C4, m3C8; char _p3[0x3E4-0x3CC]; unsigned m3E4;
};
class cMotCamera : public cCamera { public:
    void setMotion(unsigned, cParts *, cVec *, float, int, bool);
};
// FUNCTION: GAME 0x1390B8
void cMotCamera::setMotion(unsigned id, cParts *p, cVec *pos, float f, int s, bool b) {
    m3A4 = id;
    m3AC = p;
    m3A8 = 0;
    m2B4 = 1.0f;
    cVec v = pos ? cVec(*pos) : cVec(0.0f, 0.0f, 0.0f);
    m3B0 = v;
    m27A = s;
    m3E4 = 0;
    float *q = &m3C0;
    q[0] = 0.0f;
    q[1] = f;
    q[2] = 0.0f;
    setMode(M3);
    if (b) m3E4 |= 1;
}
