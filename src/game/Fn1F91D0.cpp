extern "C" void func_001F8A88(void *, float, float, float, float, float, float);

struct Fn1F91D0Box {
    float x, y, z, hx, hy, hz;
};

// FUNCTION: GAME 0x1F91D0
extern "C" Fn1F91D0Box *func_001F91D0(Fn1F91D0Box *a, Fn1F91D0Box *b) {
    float x1 = a->x, h1 = a->hx, x0 = b->x, h0 = b->hx;
    float minx = x0 - h0;
    float t = x1 - h1;
    if (t < minx) minx = t;
    t = x1 + h1;
    float maxx = x0 + h0;
    if (maxx < t) maxx = t;
    float y1 = a->y, hy1 = a->hy, y0 = b->y, hy0 = b->hy;
    float miny = y0 - hy0;
    t = y1 - hy1;
    if (t < miny) miny = t;
    t = y1 + hy1;
    float maxy = y0 + hy0;
    if (maxy < t) maxy = t;
    float z1 = a->z, hz1 = a->hz, z0 = b->z, hz0 = b->hz;
    float minz = z0 - hz0;
    t = z1 - hz1;
    if (t < minz) minz = t;
    t = z1 + hz1;
    float maxz = z0 + hz0;
    if (maxz < t) maxz = t;
    func_001F8A88(a, minx, maxx, miny, maxy, minz, maxz);
    return a;
}
