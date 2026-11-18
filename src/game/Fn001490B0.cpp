// Unit at 0x1490B0.
extern "C" void func_001F8A88(void *, float, float, float, float, float, float);

struct M { int off; char pad[0x10]; unsigned short cnt; };

#ifdef NONMATCHING
// DRAFT: GAME 0x1490B0 - 48 words differ: original spills mesh ptr to 0($sp) (frame 0x20) and copies cnt to v1; tried struct/array/address-taken locals (no spill emitted).
extern "C" void func_001490B0(void *unused, char **pp, void *out)
{
    float minx = 1e9f, maxx = -1e9f, miny = 1e9f, maxy = -1e9f, minz = 1e9f, maxz = -1e9f;
    char *base = *pp;
    int n = *(unsigned short *)(base + 0xA);
    int i = 0;
    if (n != 0) {
        char *tbl = base + 0x20;
        do {
            M *arr[1];
            arr[0] = (M *)(*(int *)(tbl + (i << 2)) + (int)base);
            M *m = arr[0];
            int cnt = m->cnt;
            float *v = (float *)(m->off + (int)m);
            if (cnt != 0) {
                do {
                    float t = v[0];
                    if (t < minx) minx = t;
                    if (maxx < t) maxx = t;
                    t = v[1];
                    if (t < miny) miny = t;
                    if (maxy < t) maxy = t;
                    t = v[2];
                    if (t < minz) minz = t;
                    if (maxz < t) maxz = t;
                    v += 4;
                } while (--cnt != 0);
            }
            i++;
        } while (i < n);
    }
    func_001F8A88(out, minx, maxx, miny, maxy, minz, maxz);
}
#endif
