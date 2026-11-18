class cMatrix {
public:
    float m[16] __attribute__((aligned(16)));
};
class Quaternion {
public:
    float x, y, z, w;
};

#ifdef NONMATCHING
// DRAFT: GAME 0x1478A8
// diff: 45 words, scheduler order of mul/add.s and swc1; tried product order permutations, chained zero stores, q.x direct loads (53)
void MtxInitRotQuaternion(cMatrix &mtx, const Quaternion &q)
{
    float x = q.x;
    float z = q.z;
    float w = q.w;
    float y = q.y;
    float *m = mtx.m;
    m[15] = 1.0f;
    float xx = 2.0f * (x * x);
    float zz = 2.0f * (z * z);
    float yy = 2.0f * (y * y);
    float yw = 2.0f * (y * w);
    float xy = 2.0f * (x * y);
    float yz = 2.0f * (y * z);
    float zx = 2.0f * (z * x);
    float xw = 2.0f * (x * w);
    float zw = 2.0f * (z * w);
    m[8] = zx + yw;
    m[4] = xy - zw;
    m[9] = yz - xw;
    m[2] = zx - yw;
    m[10] = (1.0f - xx) - yy;
    m[0] = (1.0f - yy) - zz;
    m[5] = (1.0f - zz) - xx;
    m[1] = xy + zw;
    m[6] = yz + xw;
    m[3] = m[14] = m[13] = m[12] = m[11] = m[7] = 0.0f;
}
#endif
