// Small units in 0x150000-0x170000.
struct MtxA { float v[16]; } __attribute__((aligned(16)));
struct V3 { float x, y, z; };
struct Q { float x, y, z, w; };
extern char D_0041FA90[], D_0041FBA0[];
struct IdIn { char _p[0x28]; int a; int b; };
struct IdSys { IdIn *in; };
extern IdSys *IDSys;
extern char CamManager[], World_light_work[];
extern "C" void MtxInitRotY__FR7cMatrixf(MtxA &, float);
extern "C" void MtxInitRotVec__FR7cMatrixRC4cVecUc(MtxA *, const void *, unsigned char);
extern "C" void func_001508D8(float *, const MtxA *, float *);
extern "C" float sinf(float);
extern "C" float capVu0Sin__Ff(float);
extern "C" int func_00161500(char *, char *);
extern "C" void func_001615D0(char *);
extern "C" void setIDData__10cIDManager7eIdDataPUi(IdIn *, int, unsigned *);
extern "C" void initialize__7cIDBase7eIdData5eIdNo(char *, int, int);
extern "C" void resetAnim__7cIDBase(char *);
extern "C" void setPackedMessData__7cIDBase7eIdData5eIdNo(char *, int, int);
extern "C" unsigned getIDWork__7cIDBasei(char *, int);
extern "C" float capVu0Cos__Ff(float);
extern "C" void release__7cIDBase(void *);
extern "C" void func_00161590(void *);
extern "C" void func_001615F0(void *);
extern "C" void func_00138F40(void *, int);
extern "C" void func_002D98A0(void *);
extern "C" void SubscreenMode__4pl00Ui(char *, unsigned);

// FUNCTION: GAME 0x150830
extern "C" void VecRotVec__FR4cVecRC4cVecT1Uc(float *d, float *s, const void *v, unsigned char k)
{
    MtxA m;
    MtxInitRotVec__FR7cMatrixRC4cVecUc(&m, v, k);
    func_001508D8(d, &m, s);
}

// FUNCTION: GAME 0x150888
extern "C" void VecRotY__FR4cVecRC4cVecf(float *d, float *s, float a)
{
    MtxA m;
    MtxInitRotY__FR7cMatrixf(m, a);
    func_001508D8(d, &m, s);
}

// FUNCTION: GAME 0x159FC8
extern "C" void SetRotationAxis__10QuaternionRC4cVecf(float *q, const float *v, float a)
{
    float h = a * 0.5f;
    float s = sinf(h);
    q[0] = v[0] * s;
    q[1] = v[1] * s;
    q[2] = v[2] * s;
    q[3] = capVu0Cos__Ff(h);
}

// FUNCTION: GAME 0x16C678
extern "C" void func_0016C678(char *self)
{
    func_001615F0(self);
    func_00138F40(CamManager, 0);
    V3 *d = (V3 *)(*(char **)(self + 0x264) + 0x100);
    V3 *s = (V3 *)(self + 0x270);
    if (d != s) { d->x = s->x; d->y = s->y; d->z = s->z; }
    *(int *)(*(char **)(self + 0x264) + 0x2C0) = 10;
    SubscreenMode__4pl00Ui(*(char **)(self + 0x264), 0);
    release__7cIDBase(self + 0x290);
    release__7cIDBase(self + 0x170);
    release__7cIDBase(self);
    IdIn *in = IDSys->in;
    in->b = 0;
    in->a = 0;
    func_00161590(self);
    func_002D98A0(World_light_work);
}

// FUNCTION: GAME 0x15A040
extern "C" void AddRotationAxis__10QuaternionRC4cVecf(Q *q, const float *v, float a)
{
    float h = a * 0.5f;
    Q t; t.x = q->x; t.y = q->y; t.z = q->z; t.w = q->w;
    float s = capVu0Sin__Ff(h);
    float c = capVu0Cos__Ff(h);
    q->x = (v[1] * t.z - v[2] * t.y + v[0] * t.w) * s + c * t.x;
    q->y = (v[2] * t.x - v[0] * t.z + v[1] * t.w) * s + c * t.y;
    q->z = (v[0] * t.y - v[1] * t.x + v[2] * t.w) * s + c * t.z;
    q->w = (v[0] * t.x + v[1] * t.y + v[2] * t.z) * -s + c * t.w;
}

// FUNCTION: GAME 0x166638
extern "C" void func_00166638(char *self)
{
    func_001615D0(self);
    if (func_00161500(self, D_0041FA90)) {
        char *sub = self + 0xE0;
        setIDData__10cIDManager7eIdDataPUi(IDSys->in, 8, *(unsigned **)(self + 0x50));
        initialize__7cIDBase7eIdData5eIdNo(self, 8, 0);
        resetAnim__7cIDBase(self);
        setPackedMessData__7cIDBase7eIdData5eIdNo(self, 8, 2);
        initialize__7cIDBase7eIdData5eIdNo(sub, 8, 1);
        resetAnim__7cIDBase(sub);
        self[0x5A] = 0;
        *(int *)(self + 0x60) = 4;
        self[0x5B] = 0;
        self[0x5C] = 0;
        self[0x5D] = 0;
    }
    {
        unsigned short i = 0;
        unsigned *w = (unsigned *)(self + 0x80);
        for (; i < 0x18; i++)
            *(unsigned *)((char *)w + (i << 2)) = getIDWork__7cIDBasei(self, i);
        self[0x130] = 0;
        self[0x131] = 0;
    }
}

// FUNCTION: GAME 0x1673D0
extern "C" void func_001673D0(char *self)
{
    func_001615D0(self);
    if (func_00161500(self, D_0041FBA0)) {
        char *sub = self + 0xC0;
        setIDData__10cIDManager7eIdDataPUi(IDSys->in, 0x1B, *(unsigned **)(self + 0x50));
        initialize__7cIDBase7eIdData5eIdNo(self, 0x1B, 0);
        resetAnim__7cIDBase(self);
        setPackedMessData__7cIDBase7eIdData5eIdNo(self, 0x1B, 2);
        initialize__7cIDBase7eIdData5eIdNo(sub, 0x1B, 1);
        resetAnim__7cIDBase(sub);
        self[0x5A] = 0;
        *(int *)(self + 0x60) = 5;
        self[0x5B] = 0;
        self[0x5C] = 0;
        self[0x5D] = 0;
    }
    {
        unsigned short i = 0;
        unsigned *w = (unsigned *)(self + 0x80);
        for (; i < 0x10; i++)
            *(unsigned *)((char *)w + (i << 2)) = getIDWork__7cIDBasei(self, i);
        self[0x110] = 0;
        self[0x111] = 0;
    }
}
