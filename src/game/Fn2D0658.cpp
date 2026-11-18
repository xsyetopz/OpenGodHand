struct Ent {
    unsigned short id;
    short val;
    int _pad[2];
};
extern char Sys[];
extern "C" Ent *func_002D05D8(int, int *);
extern "C" void func_002D0820(void *, float);

#ifdef NONMATCHING
// DRAFT: GAME 0x2D0658
// 38 words; v ? v : 0x80000000 lands as movz s1 instead of lui/movn v0 + move, and Sys lui/addiu hoist; tried short/int v, separate val temp
extern "C" void func_002D0658(char *self, int v, int id, float f)
{
    int n;
    if (*(int *)(self + 0x30) != 0) {
        v = v ? v : 0x80000000;
        Ent *e = func_002D05D8(id >> 8, &n);
        if (e != 0) {
            func_002D0820(self, f);
            int i = 0;
            if (n > 0) {
                do {
                    if (e->id == id) {
                        e->val = v;
                        if (id == *(unsigned short *)(Sys + 0x5B0))
                            *(int *)(self + 0x58) = v;
                        return;
                    }
                    i++;
                    e++;
                } while (i < n);
            }
        }
    }
}
#endif
