// Unnamed unit at 0x2C8EF8.
struct Fn2C8Sys {
    char _p0[0x554];
    char *m_554;
    char _p558[0x56C - 0x558];
    int m_56C;
    char _p570[0x594 - 0x570];
    unsigned m_594;
};
extern Fn2C8Sys Sys;
extern "C" void func_002C8EB0(void *);
extern "C" void func_002C90A0(void *, int);
extern "C" void func_002C9950(void *);

struct Fn2C8Hdr { char b[12]; };
struct Fn2C8Obj {
    char *m_0;
    int m_4;
    int m_8;
    unsigned m_C;
};

// FUNCTION: GAME 0x2C8EF8
extern "C" int func_002C8EF8(Fn2C8Obj *self)
{
    char *a = (char *)(*(int *)(Sys.m_554 + 0x14) + (int)Sys.m_554);
    if ((Sys.m_594 & 0x800) || Sys.m_56C)
        a = (char *)(*(int *)(Sys.m_554 + 0x18) + (int)Sys.m_554);
    if (a) {
        *(Fn2C8Hdr *)&self->m_4 = *(Fn2C8Hdr *)a;
        if (self->m_4 == 0x444C53) {
            if (self->m_8 == 1) {
                char *p = a + 0xC;
                self->m_0 = p;
                for (unsigned i = 0; i < self->m_C; i++)
                    *(unsigned short *)(p + 0x14) = *(unsigned short *)(p + 0x18);
            } else {
                self->m_0 = a + 0xC;
            }
            func_002C90A0(self, 0);
            func_002C9950(self);
            return 1;
        }
    }
    func_002C8EB0(self);
    return 0;
}
