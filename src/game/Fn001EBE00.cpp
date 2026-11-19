// Units at 0x1EBE00, 0x271148 and 0x27FEB0.
extern "C" void calcParts__6cModel(void *);
extern "C" void *Getplayer__Fv();
extern "C" float Turn_dest__FPCffT0f(int, void *, float, float);
extern "C" void func_002DC260(void *);
extern "C" void func_002DC5E0(void *);
extern "C" void func_002A8578(void *, int, int, int, int, int, float);
extern "C" int moveMotion__FP8cObjBase(void *);

// FUNCTION: GAME 0x1EBE00
extern "C" void func_001EBE00(char *self, int idx, int flag)
{
    unsigned int i = idx & 0xFFFF;
    if (i < 5) {
        unsigned int s2 = i + 1;
        unsigned int a3 = i * 2 + 1;
        unsigned int s3 = i + 6;
        if (flag != 0) {
            if (s2 < 0x20) *(int *)(self + 0x54) &= ~(int)(1UL << s2);
            if (s3 < 0x20) *(int *)(self + 0x54) |= (int)(1UL << s3);
        } else {
            char *base = self + 0x1C4;
            void **slot = (void **)(base + (i << 3));
            void *a = *slot;
            if (a != 0) {
                void **s0 = (void **)(base + (a3 << 2));
                if (*s0 != 0) {
                    *(float *)((char *)a + 0x104) = 1.5707964f;
                    *(float *)((char *)*s0 + 0x104) = -1.5707964f;
                    calcParts__6cModel(*slot);
                    calcParts__6cModel(*s0);
                    if (s2 < 0x20) *(int *)(self + 0x54) |= (int)(1UL << s2);
                    if (s3 < 0x20) *(int *)(self + 0x54) &= ~(int)(1UL << s3);
                }
            }
        }
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x271148 - 65 differing words (v6, 324 bytes); original saves $s2 with a 0x50 frame, compiled code saves $s0/$s1 with 0x40; variants v2 to v8 tried, none below 65.
extern "C" void func_00271148(char *arg0)
{
    char *p = (char *)Getplayer__Fv();
    if (*(int *)(p + 0x6A0) == 0 && !(*(float *)(p + 0x54C) > 0.0f)) {
        Getplayer__Fv();
        char *q = (char *)Getplayer__Fv();
        float d = Turn_dest__FPCffT0f(*(int *)(q + 0xF0), *(void **)(arg0 + 0xF0),
                                      *(float *)(q + 0x104), 3.1415927f);
        float a = d < 0.0f ? -d : d;
        if (!(a < 1.7453293f)) {
            float t = *(float *)(*(char **)(p + 0xF0) + 4) - *(float *)(*(char **)(arg0 + 0xF0) + 4);
            float b = t < 0.0f ? -t : t;
            if (!(b > 0.5f) && (*(float *)(arg0 + 0x618) < 4.0f)) {
                if (*(int *)(arg0 + 0x564) != 0x20F) func_002DC260(arg0);
                else func_002DC5E0(arg0);
            }
        }
    }
}

// DRAFT: GAME 0x27FEB0 - 74 differing words (s3, 316 vs 332 bytes); compiler hoists the per-case f12/a0/a3 argument setup into the shared call block, which the original keeps per case; s4, s5, s6 and an early-return form regressed.
extern "C" void func_0027FEB0(char *self)
{
    unsigned int st = *(unsigned char *)(self + 0x2F6);
    char *o;
    int a1 = 0;
    int a2;
    if (st < 8) {
        switch (st) {
        case 0:
            o = *(char **)(self + 0x304);
            a1 = *(int *)(o + 0x138) + (int)o;
            a2 = *(int *)(o + 0x13C) + (int)o;
            goto call;
        case 2:
            o = *(char **)(self + 0x304);
            a1 = *(int *)(o + 0x140) + (int)o;
            a2 = *(int *)(o + 0x144) + (int)o;
        call:
            func_002A8578(self, a1, a2, 5, 0, 0, 0.0f);
            (*(unsigned char *)(self + 0x2F6))++;
        move:
            moveMotion__FP8cObjBase(self);
            break;
        case 1:
        case 3:
            goto move;
        case 4:
            o = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(o + 0x140) + (int)o, *(int *)(o + 0x144) + (int)o, 5, 0, 0, 0.0f);
            (*(unsigned char *)(self + 0x2F6))++;
            /* fall through */
        case 5:
            if (moveMotion__FP8cObjBase(self)) {
                *(unsigned char *)(self + 0x2F7) = 0;
                *(unsigned char *)(self + 0x2F4) = 0;
                *(unsigned char *)(self + 0x2F5) = 0;
                *(unsigned char *)(self + 0x2F6) = 0;
            }
            break;
        case 6:
            o = *(char **)(self + 0x304);
            func_002A8578(self, *(int *)(o + 0x150) + (int)o, *(int *)(o + 0x154) + (int)o, 5, 0, 0, 0.0f);
            (*(unsigned char *)(self + 0x2F6))++;
            /* fall through */
        case 7:
            moveMotion__FP8cObjBase(self);
            break;
        }
    }
}
#endif
