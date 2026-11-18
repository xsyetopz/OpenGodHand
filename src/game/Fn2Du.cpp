// 0x2D0000 range small units
struct VT5 { char pad[0x10]; short adj; short pad2; int (*fn)(char *, int); };
extern "C" void func_002D5890(char *, int);
extern "C" void func_002D58B8(char *, int, int);
extern "C" void func_002D5440(char *, int);
// FUNCTION: GAME 0x2D5470
extern "C" int execute__12cTaskManagerRFv_vi(char *s, int a, int c) {
    VT5 *vt = *(VT5 **)(s + 0x30);
    int r = vt->fn(s + vt->adj, c);
    if (r != -1) func_002D5890(*(char **)s + r * 0x58, a);
    func_002D5440(s, r);
    return r;
}
// FUNCTION: GAME 0x2D54F0
extern "C" int execute__12cTaskManagerRFPv_vPvi(char *s, int a, int b, int c) {
    VT5 *vt = *(VT5 **)(s + 0x30);
    int r = vt->fn(s + vt->adj, c);
    if (r != -1) func_002D58B8(*(char **)s + r * 0x58, a, b);
    func_002D5440(s, r);
    return r;
}
struct Sn { char pad[0x18]; char *w18; };
extern "C" void func_002CD470(char *, float);
// FUNCTION: GAME 0x2D20E0
extern "C" void BgmEvAllSignal__4cSndf(Sn *s, float f) {
    for (char *p = s->w18; p; p = *(char **)(p + 0x88)) {
        int v = *(int *)(p + 0x98);
        if (v & 0x800) {
            int m = v & -0x801;
            *(int *)(p + 0x98) = m;
            if (!(m & 0x1FF00) && *(int *)(p + 0xB0) != 2) func_002CD470(p, f);
        }
    }
}
