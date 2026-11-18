// Jump-table switch unit (own file: its .rodata must be exactly the table).
extern char *Cockpit;

struct Jb { char _p[0x1C]; unsigned m_1C; unsigned m_20; };
static inline void SetF(char *p) { *(unsigned char *)(p + 0x94) |= 1; }
static inline void SetPos(char *p, float a, float b) { *(float *)(p + 0xA4) = a; *(float *)(p + 0xA0) = b; }

#ifdef NONMATCHING
// DRAFT: GAME 0x1F7680 - 54 words: orig loads 330.0f (lui/mtc1 f0) inside each of cases 0-3 and sets Cockpit+0x1380 via lw+addiu at tail; mine shares f0 load and shape differs. Tried case 0/default merge, inline helper SetF/SetPos, (Cockpit+0x1380)[off]
extern "C" int func_001F7680(void *a0, Jb *arg)
{
    float f0, f1;
    SetF(Cockpit + 0x1380);
    switch (arg->m_20) {
    case 1:
        *(unsigned char *)(Cockpit + 0x1415) = 0;
        f1 = 200.0f; f0 = 330.0f;
        break;
    case 2:
        *(unsigned char *)(Cockpit + 0x1415) = 3;
        f1 = 200.0f; f0 = 330.0f;
        break;
    case 3:
        *(unsigned char *)(Cockpit + 0x1415) = 2;
        f1 = 200.0f; f0 = 330.0f;
        break;
    case 16:
        *(unsigned char *)(Cockpit + 0x1415) = 4;
        f1 = 230.0f; f0 = 290.0f;
        break;
    case 17:
        *(unsigned char *)(Cockpit + 0x1415) = 5;
        f1 = 230.0f; f0 = 290.0f;
        break;
    case 18:
        *(unsigned char *)(Cockpit + 0x1415) = 6;
        f1 = 230.0f; f0 = 290.0f;
        break;
    case 0:
    default:
        *(unsigned char *)(Cockpit + 0x1415) = 1;
        f1 = 200.0f; f0 = 330.0f;
        break;
    }
    SetPos(Cockpit + 0x1380, f0, f1);
    *(unsigned *)(Cockpit + 0x1464) = arg->m_1C + 0x3011;
    return 0;
}
#endif
