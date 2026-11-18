// Fn150c: 0x150000-0x160000 free units, round 31.



// FUNCTION: GAME 0x15A590
extern "C" float func_003A19F8(float);
extern "C" float func_003A18F0(float);
class cVec;
struct cVecQ15A590 { float x, y, z, w; };
class Quaternion {
public:
    float q[4];
    void SetEulerXYZ(const cVec &v);
};
void Quaternion::SetEulerXYZ(const cVec &v)
{
    const cVecQ15A590 &e = (const cVecQ15A590 &)v;
    float ax = e.x * 0.5f;
    float ay = e.y * 0.5f;
    float az = e.z * 0.5f;
    float sx = func_003A19F8(ax);
    float cx = func_003A18F0(ax);
    float sy = func_003A19F8(ay);
    float cy = func_003A18F0(ay);
    float sz = func_003A19F8(az);
    float cz = func_003A18F0(az);
    q[0] = sx * cy * cz - cx * sy * sz;
    q[1] = cx * cz * sy + sx * sz * cy;
    q[2] = cx * cy * sz - sx * sy * cz;
    q[3] = cx * cz * cy + sx * sz * sy;
}

// FUNCTION: GAME 0x1632E8
extern "C" int func_001FA710(char *);
extern "C" void func_001633A0(char *);
extern "C" void func_001634E0(char *);
extern "C" void func_00163F00(char *);
extern "C" void func_002AAA40(char *);
extern char D_00569B70[];
extern "C" void func_001632E8(char *self)
{
    *(int *)(*(char **)(self + 0xE0) + 0x84) = func_001FA710(D_00569B70);
    *(unsigned *)(*(char **)(self + 0xE4) + 0x2C) &= 0xF7FFFFFF;
    switch (*(unsigned char *)(self + 0x64)) {
    case 0:
        func_001633A0(self);
        break;
    case 1:
        func_001634E0(self);
        break;
    case 2:
    case 3:
        func_00163F00(self);
        break;
    }
    func_002AAA40(self);
}

