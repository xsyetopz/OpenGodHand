struct Ent { short a; short b; unsigned short c; short c2; short d; short e; int g; int h; };
extern char CoreSave[];
extern "C" void func_001F4C40(char *, int, int);
extern "C" int func_001F4530(char *, int, unsigned);
extern "C" int func_001FC4D0(char *, int);
extern "C" void func_001F4B98(char *, int, int, int);
extern "C" void func_001F4CA8(char *, int, int, int);
extern "C" void func_001F4FF0(char *, int, int, int);
extern "C" void func_001F5098(char *, int, int, int);
extern "C" void func_001F50A0(char *, int, int, int);
extern "C" void func_001F5210(char *, int, int, int);
extern "C" void func_001F5278(char *, int, int);

// FUNCTION: GAME 0x1F4068
extern "C" void func_001F4068(char *self, unsigned short id, Ent *e, int flag)
{
    if (id < 7) {
        char *p = self + 0x60;
        func_001F4C40(p, id, e->a);
        if (func_001F4530(self, e->a, e->c)) {
            func_001F4B98(p, id, func_001FC4D0(CoreSave, e->a), flag);
            func_001F4CA8(p, id, e->d, flag);
            func_001F4FF0(p, id, e->e, flag);
            func_001F5098(p, id, 0, flag);
            func_001F50A0(p, id, e->g, flag);
            int h;
            if (func_001FC4D0(CoreSave, e->a))
                h = 0;
            else
                h = e->h;
            func_001F5210(p, id, h, flag);
            func_001F5278(p, id, 0);
        } else {
            func_001F4B98(p, id, func_001FC4D0(CoreSave, e->a), 0);
            func_001F4CA8(p, id, e->d, 0);
            func_001F4FF0(p, id, e->e, 0);
            func_001F5098(p, id, 0, 0);
            func_001F50A0(p, id, e->g, 0);
            int h;
            if (func_001FC4D0(CoreSave, e->a))
                h = 0;
            else
                h = e->h;
            func_001F5210(p, id, h, 0);
            func_001F5278(p, id, flag);
        }
    }
}
