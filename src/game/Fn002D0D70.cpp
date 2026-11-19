struct EntR { int m_0, m_4, m_8, m_c, m_10, m_14; };
extern "C" EntR *func_002D0B88(unsigned short);
extern "C" int func_002D0CD0(char *);
extern char *SubScr;
extern char *D_00586B28;
extern unsigned short D_00583EEC;
extern unsigned char D_005CB010;

#ifdef NONMATCHING
// DRAFT: GAME 0x2D0D70
// 61 differing words: gcc folds the ==0 flag (xori/beqz) and reloads SubScr/D_00586B28 differently; tried int/unsigned char flag, if-else flag
extern "C" int func_002D0D70(char *self, unsigned short id)
{
    int t = *(int *)(SubScr + 0x48);
    if (t == 3 || t == 12) {
        unsigned char z = 0;
        if (*(int *)(SubScr + 0xEE8) == 0) z = 1;
        if (!z) {
            unsigned short v;
            if (!(*(int *)D_00586B28 & 1))
                v = D_00583EEC;
            else
                v = *(unsigned short *)(D_00586B28 + 8);
            int c = (id ^ 0x21) != 0;
            unsigned short a = 0x100;
            if (c) a = v;
            return func_002D0B88(a)->m_4;
        }
    }
    int r = 10;
    if (D_005CB010 == 0) {
        EntR *e = func_002D0B88(id);
        if (*(int *)(self + 0x13C) == 1) return e->m_8;
        r = func_002D0CD0(self);
        if (r == -2) {
            int k = *(int *)(self + 0x13C);
            if (k == 2) return e->m_c;
            if (k < 3) return e->m_4;
            if (k == 3) return e->m_10;
            if (k == 4) return e->m_14;
            return e->m_4;
        }
    }
    return r;
}
#endif
