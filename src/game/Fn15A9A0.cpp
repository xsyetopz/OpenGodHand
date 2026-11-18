// 0x15A9A0, 0x15ABA0: orthonormal basis built from two vectors.
#include "cvecop.h"
extern "C" float func_00101E28(float *);
extern "C" void sceVu0UnitMatrix(float *);
extern "C" void func_0015A190(char *, float *);
// FUNCTION: GAME 0x15ABA0
// DIVNOP: 2 2
extern "C" void func_0015ABA0(char *out, float *a, float *b) {
  float v[4], n[4], c[4], r[4], u[4];
  cvecop_CopyR(v, b);
  float *cp = c;
  c[0] = v[1] * a[2] - v[2] * a[1];
  c[1] = v[2] * a[0] - v[0] * a[2];
  c[2] = v[0] * a[1] - v[1] * a[0];
  cp[3] = 1.0f;
  cvecop_Zero(r);
  float l = func_00101E28(c);
  if (0.0f < l) {
    float s = 1.0f / l;
    r[0] = c[0] * s; r[1] = c[1] * s; r[2] = c[2] * s; r[3] = c[3];
  }
  float *rp = r;
  cvecop_CopyR(n, rp);
  float *p2 = r;
  r[0] = n[1] * v[2] - n[2] * v[1];
  r[1] = n[2] * v[0] - n[0] * v[2];
  r[2] = n[0] * v[1] - n[1] * v[0];
  p2[3] = 1.0f;
  cvecop_Zero(u);
  l = func_00101E28(r);
  if (0.0f < l) {
    float s = 1.0f / l;
    u[0] = r[0] * s; u[1] = r[1] * s; u[2] = r[2] * s; u[3] = r[3];
  }
  float *up = u;
  cvecop_CopyR(c, up);
  float m[16];
  sceVu0UnitMatrix(m);
  m[0] = c[0]; m[1] = c[1]; m[2] = c[2];
  m[4] = n[0]; m[5] = n[1]; m[6] = n[2];
  m[8] = v[0]; m[9] = v[1]; m[10] = v[2];
  func_0015A190(out, m);
}

// FUNCTION: GAME 0x15A9A0
// DIVNOP: 2 2
extern "C" void SetCoordinateRotationZ__10QuaternionRC4cVecT1(char *out, float *a, float *b) {
  float v[4], n[4], c[4], r[4], u[4];
  cvecop_CopyR(v, a);
  float *cp = c;
  c[0] = b[1] * v[2] - b[2] * v[1];
  c[1] = b[2] * v[0] - b[0] * v[2];
  c[2] = b[0] * v[1] - b[1] * v[0];
  cp[3] = 1.0f;
  cvecop_Zero(r);
  float l = func_00101E28(c);
  if (0.0f < l) {
    float s = 1.0f / l;
    r[0] = c[0] * s; r[1] = c[1] * s; r[2] = c[2] * s; r[3] = c[3];
  }
  float *rp = r;
  cvecop_CopyR(n, rp);
  float *p2 = r;
  r[0] = v[1] * n[2] - v[2] * n[1];
  r[1] = v[2] * n[0] - v[0] * n[2];
  r[2] = v[0] * n[1] - v[1] * n[0];
  p2[3] = 1.0f;
  cvecop_Zero(u);
  l = func_00101E28(r);
  if (0.0f < l) {
    float s = 1.0f / l;
    u[0] = r[0] * s; u[1] = r[1] * s; u[2] = r[2] * s; u[3] = r[3];
  }
  float *up = u;
  cvecop_CopyR(c, up);
  float m[16];
  sceVu0UnitMatrix(m);
  m[0] = n[0]; m[1] = n[1]; m[2] = n[2];
  m[4] = c[0]; m[5] = c[1]; m[6] = c[2];
  m[8] = v[0]; m[9] = v[1]; m[10] = v[2];
  func_0015A190(out, m);
}
