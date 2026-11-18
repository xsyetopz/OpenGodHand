// Small functions in the ProDG game-code island (ee-gcc2.95.3-136, C++).

struct S { char p0[0x10]; int m10, m14; float m18; int m1C; int m20; char p24[0xC]; int m30; };
struct Q { char p0[3]; unsigned char m3; char p4[0x2C]; int m30; S a; };
extern "C" {
int func_0032DC58(int);
void *func_0032DCD0(int, int);
void func_0032A160(void *, void *, void *);
int func_00329F98(int);
int func_0032B6E0(int);
float func_0032AE10(int);
int func_0032D0C0(int);
// FUNCTION: GAME 0x3835A0
void func_003835A0(int unused, Q *q) {
    char buf[16] __attribute__((aligned(16)));
    S *s;
    if (q->m3 & 1) {
        s = (S *)((char *)q + 0xA4);
        if (s->m20) q->m30 = func_0032DC58(s->m20);
        else q->m30 = -1;
        if (q->m30 >= 0) {
            void *o = func_0032DCD0(s->m20, 0);
            if (o) func_0032A160(o, &s->m14, buf);
        }
    } else {
        s = (S *)((char *)q + 0x34);
        if (s->m30) q->m30 = func_00329F98(s->m30);
        else q->m30 = -1;
        if (q->m30 >= 0) {
            func_0032A160((void *)s->m30, &s->m10, buf);
            s->m14 = func_0032B6E0(s->m30);
            s->m18 = func_0032AE10(s->m30);
            s->m1C = func_0032D0C0(s->m30);
        }
    }
}
}
