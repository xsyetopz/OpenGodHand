extern int D_007476B0;
struct S { char pad[0x3DC88]; long v[2][2]; };

// FUNCTION: GAME 0x151368
extern "C" long func_00151368(S *b, int i) {
    return b->v[i][D_007476B0 & 1];
}

struct Hp;
extern "C" Hp SubScrHeap;
extern "C" void func_002A94F0(Hp *);
struct SS { char pad[0x50]; int w50; char pad2[0xC]; int w60; unsigned char b64; };

// FUNCTION: GAME 0x161590
extern "C" void func_00161590(SS *s) {
    func_002A94F0(&SubScrHeap);
    s->b64 = 0; s->w60 = -1; s->w50 = 0;
}

extern "C" void trans__7cIDBase(void *);
extern "C" void func_00163C58();
extern "C" void func_00164978(void *);
extern char D_00567D70[];
struct T { char pad[0x5B]; char b5B; char pad2[8]; unsigned char b64; };

// FUNCTION: GAME 0x1640E8
extern "C" void func_001640E8(T *s) {
    unsigned char c = s->b64;
    if (c == 1 && s->b5B == c) func_00163C58();
    func_00164978(D_00567D70);
    trans__7cIDBase(s);
}
