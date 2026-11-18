// 0x2DA7A8: yaw toward a target relative to a heading, wrapped to +-pi.
extern "C" float atanf(float);
// FUNCTION: GAME 0x2DA7A8
// DIVNOP: 2
extern "C" float func_002DA7A8(float *a, float *b, float yaw) {
  float dz = b[2] - a[2];
  float dx = b[0] - a[0];
  float r;
  if (dz != 0.0f) {
    r = atanf(dx / dz);
    if (dz < 0.0f) r -= 3.1415927f;
  } else if (dx > 0.0f) {
    r = 1.5707964f;
  } else {
    r = -1.5707964f;
  }
  float d = r - yaw;
  if (d > 3.1415927f) d -= 6.2831855f;
  if (d < -3.1415927f) d += 6.2831855f;
  return d;
}
