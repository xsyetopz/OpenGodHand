// Sound buffer allocation at 0x374210.
struct SndBuf { int m0; int m4; int m8; int _c; int m10; };
struct cHeap;
extern cHeap SoundHeap;
extern "C" int func_0031C8E0(int, int, cHeap &);
extern "C" void func_0031C928(int, cHeap &);
extern "C" int func_0032D340(int, int, int, int);

// FUNCTION: GAME 0x374210
extern "C" int func_00374210(SndBuf *p, int a, int b, int c)
{
    int k = (a / 1000) * 0x61A8;
    int n = p->m10;
    int base = n * 0x40C0 + 0x24;
    int t = ((n * k) / 44) * (b + 1);
    int u = (t + 0x800) / 0x800 * 0x800;
    p->m8 = (u + base) * c + 0x40;
    int r = func_0031C8E0(p->m8, 0x40, SoundHeap);
    p->m4 = r;
    if (r) {
        int s = func_0032D340(c, p->m10, r, p->m8);
        p->m0 = s;
        if (s) return 1;
        func_0031C928(p->m4, SoundHeap);
        p->m4 = 0;
    }
    return 0;
}
