struct ObjVec {
    int _p;
    char **b;
    char **e;
};
extern ObjVec *objbaseArray;
extern "C" int func_001C2328(char *);

#ifdef NONMATCHING
// DRAFT: GAME 0x274018
// 35 differing words; gcc folds s>=0x300&&s<0x500 into sltiu/movn and uses a0 instead of s0; variants: early-return loop, do-while with r, hoisted 0x80000000 mask, nested ifs
extern "C" char *func_00274018()
{
    char **e = objbaseArray->e;
    char **p = objbaseArray->b;
    char *r = 0;
    if (p != e) {
        unsigned m = 0x80000000;
        do {
            char *o = *p;
            int f = *(int *)(o + 0x250);
            p++;
            if (f & 0x8000)
                continue;
            if (!(f & m)) {
                int s = *(unsigned short *)(o + 0x2FE);
                int in = 0;
                if (s >= 0x300)
                    in = s < 0x500;
                if ((in & 0xFF) && (s ^ 0x3D1) == 0) {
                    r = o;
                    if (func_001C2328(o))
                        return r;
                }
            }
        } while (p != e);
        r = 0;
    }
    return r;
}
#endif
