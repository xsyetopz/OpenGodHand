extern "C" float atanf(float);

// FUNCTION: GAME 0x2DA038
// DIVNOP: 2
float Turn_dest(const float *a, float cur, const float *b, float lim)
{
    float l = lim, c = cur;
    float dx = b[0] - a[0];
    float dz = b[2] - a[2];
    float ang;
    if (dx == 0.0f && dz == 0.0f) return 0.0f;
    if (dz != 0.0f) {
        ang = atanf(dx / dz);
        if (dz < 0.0f) ang -= 3.1415927f;
    } else {
        ang = (0.0f < dx) ? 1.5707964f : -1.5707964f;
    }
    float d = ang - c;
    if (3.1415927f < d) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    float s = (0.0f < d) ? 1.0f : -1.0f;
    float m = (l < ((0.0f < d) ? d : -d)) ? l : (!(0.0f < d) ? -d : d);
    // Reusing d for the clamped value puts the final abs in the original's
    // c.lt/bc1t form with the mov in the delay slot.
    d = m;
    return d * s;
}

// FUNCTION: GAME 0x2DA2D0
// DIVNOP: 2
int Dest_ck(const float *a, float cur, const float *b, float lim)
{
    float l = lim, c = cur;
    float dx = b[0] - a[0];
    float dz = b[2] - a[2];
    float ang;
    if (dz != 0.0f) {
        ang = atanf(dx / dz);
        if (dz < 0.0f) ang -= 3.1415927f;
    } else {
        ang = (0.0f < dx) ? 1.5707964f : -1.5707964f;
    }
    float d = ang - c;
    if (3.1415927f < d) d -= 6.2831855f;
    if (d < -3.1415927f) d += 6.2831855f;
    float m = (l < ((0.0f < d) ? d : -d)) ? l : (!(0.0f < d) ? -d : d);
    d = m;
    return d != l;
}
