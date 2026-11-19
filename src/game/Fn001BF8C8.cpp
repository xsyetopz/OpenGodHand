extern "C" void TutorialON__13cCockTutorialUs(void *, int);
extern "C" void sleep__9cTaskWorkUs(void *, int);
extern "C" void exit__9cTaskWork(void *, int);
extern "C" void *memset(void *, int, unsigned int);
extern char *Cockpit;
extern char Sys[];
extern char *g_Sce;
extern char D_00747A78[];
extern char Snd[];
extern char g_ps2[];
extern char D_0076A790[];
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int GetSeqSEBase__FP8cObjBase(void *);
extern "C" void SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(void *, int, int, void *, int, int, int, int);
extern "C" int moveMotion__FP8cObjBase(void *);
extern "C" void Pad_act_set__13classPAD_WORKUiUi(void *, unsigned, unsigned);
extern "C" int func_002BDDE0(void *, int, unsigned char, float);
extern "C" int func_002BDD90(void *);
extern "C" void stopSeq__7cPadVib(void *);
extern "C" int func_003827F0(char *, char *);
extern "C" void func_0032EC78(int, int, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1BF8C8
// 91 words. arg0 lands in $s2 instead of $s3; original hoists %hi(g_Sce) and %hi(Cockpit) into s0, s1, s4.
extern "C" void func_001BF8C8(char *arg0)
{
    TutorialON__13cCockTutorialUs(Cockpit + 0x1A20, (((int)*(signed char *)(arg0 + 0x600)) + 0x2000) & 0xFFFF);
    sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 0xA);
    if (!(*(unsigned long *)(Sys + 0x1A0) & 0x30000000)) {
        do {
            sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 1);
        } while (!(*(unsigned long *)(Sys + 0x1A0) & 0x30000000));
    }
    char *ck = Cockpit + 0x1A20;
    int st = ck[0xB8];
    if ((unsigned int)(st - 2) < 2U) {
        ck[0xB8] = 4;
    }
    do {
        sleep__9cTaskWorkUs(*(void **)(g_Sce + 0x20), 1);
    } while (*(signed char *)(Cockpit + 0x1AD8) != 0);
    memset(D_00747A78, 0, 8);
    memset(D_00747A78 + 8, 0, 4);
    int idx = *(int *)(g_Sce + 0x24);
    if (idx >= 0) {
        char *e = *(char **)(g_Sce + 0x1C) + idx * 0x58;
        e[0x50] = (unsigned char)(e[0x50] & 0xFE);
    }
    *(int *)(g_Sce + 0x48) = *(int *)(g_Sce + 0x48) & ~1;
    *(short *)(arg0 + 0x602) = 0xA;
    arg0[0x2F5] = (unsigned char)(arg0[0x2F5] + 1);
    exit__9cTaskWork(*(void **)(g_Sce + 0x20), 0xA);
}
#endif

#ifdef NONMATCHING
struct Seq2BDC00 {
    int m_active;
    unsigned char *m_rate;
    void *m_obj;
    int m_chan;
    char _p10[8];
    unsigned m_flags;
    float m_step;
    float m_pos;
    unsigned m_acc;
};

// DRAFT: GAME 0x2BDC00
// 83 words. Keeping m_rate in a local adds a re-read of 0x4(s2) after the calls (85 words); the field is read directly.
extern "C" void func_002BDC00(Seq2BDC00 *self)
{
    if (self->m_active != 0) {
        if (self->m_rate != 0) {
            int one = 1;
            unsigned a = func_002BDDE0(self, (int)self->m_obj, self->m_rate[0], self->m_pos) & 0xFF;
            unsigned b = func_002BDDE0(self, self->m_chan, self->m_rate[1], self->m_pos) & 0xFF;
            Pad_act_set__13classPAD_WORKUiUi(g_ps2, (a << 16) | 0x02000000, (one << *(int *)(Sys + 0x564)) << 16);
            unsigned acc = self->m_acc + b;
            self->m_acc = acc;
            if (acc >= 0xFF) {
                self->m_acc = acc - 0xFF;
                Pad_act_set__13classPAD_WORKUiUi(g_ps2, 0x01000000, (one << *(int *)(Sys + 0x564)) << 16);
            }
            self->m_pos = self->m_pos + self->m_step;
            int n = func_002BDD90(self);
            float pos = self->m_pos;
            if (self->m_flags & 1) {
                float t = (float)n - 1.0f;
                if (t <= pos) {
                    self->m_pos = pos - t;
                }
            } else if ((float)n - 1.0f < pos) {
                stopSeq__7cPadVib(self);
            }
        }
    }
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x2804F8
// 85 words. Prologue and register roles differ (self in s0, frame 0x20 vs s1/s0, frame 0x30). Shared-variable and hoisted-Snd variants gave 89 to 99.
extern "C" void func_002804F8(char *self)
{
    int base;
    int r;

    if (*(unsigned char *)(self + 0x2F6) != 0) {
        if (*(unsigned char *)(self + 0x2F6) == 1) {
            moveMotion__FP8cObjBase(self);
        }
        return;
    }
    switch (*(unsigned char *)(self + 0x2F7)) {
    case 0:
    default:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xA8) + base, *(int *)(base + 0xAC) + base, 2, 0, 0, 0.0f);
        break;
    case 1:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xA0) + base, *(int *)(base + 0xA4) + base, 2, 0, 0, 0.0f);
        break;
    case 2:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xB0) + base, *(int *)(base + 0xB4) + base, 2, 0, 0, 0.0f);
        break;
    case 3:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xB8) + base, *(int *)(base + 0xBC) + base, 2, 0, 0, 0.0f);
        break;
    case 4:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xC0) + base, *(int *)(base + 0xC4) + base, 2, 0, 0, 0.0f);
        break;
    case 5:
        base = *(int *)(self + 0x304);
        func_002A8578(self, *(int *)(base + 0xC8) + base, *(int *)(base + 0xCC) + base, 2, 0, 0, 0.0f);
        break;
    }
    r = GetSeqSEBase__FP8cObjBase(self);
    SeCall__4cSnd6eSeBlksR4cObjP4cObjP6cPartsUii(Snd, 1, (short)r, self, 0, 0, 0, 0);
    self[0x2F6] = (unsigned char)(self[0x2F6] + 1);
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x37D3C8
// 83 words. Local base pointer g fixed the global load; remaining diff is register swap (g in $a1, zero in $a2, reversed from original).
extern "C" void func_0037D3C8(char *arg0)
{
    char *g = D_0076A790;
    unsigned short v0;
    unsigned short v1;
    int a1 = 0;
    if (*(int *)(g + 0x14) == 2) {
        v0 = *(unsigned short *)(arg0 + 0x3A);
        v1 = *(unsigned short *)(arg0 + 0x28);
    } else {
        v0 = *(unsigned short *)(arg0 + 0x38);
        v1 = *(unsigned short *)(arg0 + 0x26);
    }
    *(unsigned short *)(arg0 + 0x3C) = v0;
    *(unsigned short *)(arg0 + 0x2A) = v1;
    if (*(short *)(arg0 + 0x3C) == 0x80) {
        *(short *)(arg0 + 0x3C) = 0x7FFF;
    } else {
        *(short *)(arg0 + 0x3C) = (short)(*(unsigned short *)(arg0 + 0x3C) << 8);
    }
    unsigned char m = *(unsigned char *)(arg0 + 5);
    if (m == 2) {
        int t;
        if (arg0[4] & 1) {
            t = *(short *)(g + 0x3C) * *(short *)(arg0 + 0x2A);
        } else {
            t = *(short *)(g + 0x3E) * *(short *)(arg0 + 0x2A);
        }
        a1 = t / 32512;
    } else if (m == 4) {
        int t;
        if (!(arg0[4] & 1)) {
            t = *(short *)(g + 0x42);
        } else {
            t = *(short *)(g + 0x40);
        }
        a1 = ((t * *(short *)(arg0 + 0x2A)) / 32512 * *(short *)(arg0 + 0x3C)) / 32512;
    } else if (m == 1 || m == 9) {
        a1 = ((*(short *)(g + 0x3A) * *(short *)(arg0 + 0x3C)) / 32512 * *(short *)(arg0 + 0x30)) / 32512;
    }
    *(short *)(arg0 + 0x3E) = (short)a1;
}
#endif

#ifdef NONMATCHING
// DRAFT: GAME 0x382660
// 87 words. Declaring s2 before s0 gave 87 (91 baseline, 90 with 32-bit read of arg1+0x34); s0-first with branch-local s1/s2 gave 96.
extern "C" void func_00382660(char *arg0, char *arg1)
{
    char *s2 = arg0 + 0x360;
    char *s0 = arg0 + 0x318;
    char *s1 = arg0 + 0x348;
    if (*(int *)(arg1 + 0x34) & 0xA000) {
        s2[*(unsigned char *)(s0 + 2)] ^= 1;
        if (*(unsigned char *)(s0 + 2) == 0) {
            char *a = arg0 + 0x361;
            int n = 0;
            do {
                n += 1;
                *a = s2[*(unsigned char *)(s0 + 2)];
                a += 1;
            } while (n < 4);
        } else if (func_003827F0(arg0, s0) != 0) {
            s1[0x18] = s2[*(unsigned char *)(s0 + 2)];
        }
        int a0 = *(int *)(s1 + 0x20);
        if (a0 != 0) {
            unsigned char v = *(unsigned char *)(s0 + 2);
            if (v != 0) {
                if (s1[v + 0x18] != 0) {
                    func_0032EC78(a0, v - 1, -0x3C0);
                    return;
                }
                func_0032EC78(a0, v - 1, *(short *)(s0 + 4 + v * 2));
                return;
            }
            int v3 = *(int *)(s1 + 8);
            if (s1[v + 0x18] != 0) {
                int s = 0;
                if (v3 > 0) {
                    do {
                        int t = s;
                        s += 1;
                        func_0032EC78(*(int *)(s1 + 0x20), t, -0x3C0);
                    } while (s < *(int *)(s1 + 8));
                }
            } else {
                int a = 0;
                if (v3 > 0) {
                    int s = 1;
                    do {
                        func_0032EC78(*(int *)(s1 + 0x20), a, *(short *)(s0 + 4 + s * 2));
                        a = s;
                        s = a + 1;
                    } while (a < *(int *)(s1 + 8));
                }
            }
        }
    }
}
#endif
