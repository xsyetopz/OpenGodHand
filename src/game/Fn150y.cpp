// 0x15A878: quaternion rotating one unit vector onto another.
extern "C" float sqrtf(float);
struct V3 { float x, y, z; };
struct Q { float x, y, z, w; };
// FUNCTION: GAME 0x15A878
// DIVNOP: 2
extern "C" void SetVectorRotation__10QuaternionRC4cVecT1(Q *q, const V3 *u, const V3 *v) {
  float c[5];
  c[0] = u->y * v->z - u->z * v->y;
  c[1] = u->z * v->x - u->x * v->z;
  c[2] = u->x * v->y - u->y * v->x;
  c[3] = 1.0f;
  c[4] = 1.0f;
  float d = u->x * v->x + u->y * v->y + u->z * v->z;
  float e = d < -1.0f ? -1.0f : d;
  float m = 1.0f;
  if (e < 1.0f) m = e;
  float s = sqrtf((m + 1.0f) * 2.0f);
  float inv = 1.0f / s;
  q->x = c[0] * inv;
  q->y = c[1] * inv;
  q->z = c[2] * inv;
  q->w = s * 0.5f;
}
