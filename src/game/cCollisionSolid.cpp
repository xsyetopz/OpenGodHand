// Small free functions around the collision-solid code (0x133000-0x135FFF).

struct sCollTable {
    char _pad0[0x20];
    char *m_entries;
};

extern "C" void func_001352F8(int a, unsigned int b);
extern "C" void *func_00133670(int a, unsigned int b);
extern "C" void *func_0031EEC8(void *obj, const char *name);

extern int D_00460D08[];
extern int D_00460D18;
extern const char D_0041D618[];

extern char g_CollSolidManage[];
struct sCollClear;
extern "C" sCollClear *func_00134650(sCollClear *self);

struct sCollLink {
    int m_id;
    int _pad[3];
    sCollLink *m_next;
};

struct sCollFlagNode {
    sCollFlagNode *m_next;
    int _pad;
    int m_flags;
};

struct sCollFlagList {
    int _pad0;
    sCollFlagNode *m_head;
};

struct sCollClear {
    int m_a;
    int m_b;
    int m_tab[32];
    int m_end;
};

// FUNCTION: GAME 0x1333B8
extern "C" char *func_001333B8(sCollTable *self, unsigned short i)
{
    return self->m_entries + i * 8;
}

// FUNCTION: GAME 0x133B80
extern "C" void func_00133B80(int *self)
{
    self[2] &= ~2;
}

// FUNCTION: GAME 0x133B98
extern "C" void func_00133B98()
{
}

// FUNCTION: GAME 0x134648
extern "C" void func_00134648(int *self, int v)
{
    self[2] = v;
}

// FUNCTION: GAME 0x1352F0
extern "C" void func_001352F0()
{
}

// FUNCTION: GAME 0x135328
extern "C" void func_00135328()
{
    func_001352F8(1, 0xFFFF);
}

// FUNCTION: GAME 0x133968
extern "C" void func_00133968()
{
    func_00133670(1, 0xFFFF);
}

// FUNCTION: GAME 0x1352F8
extern "C" void func_001352F8(int a, unsigned int b)
{
    if (b == 0xFFFF && a != 0)
        func_00134650((sCollClear *)g_CollSolidManage);
}

// FUNCTION: GAME 0x134650
extern "C" sCollClear *func_00134650(sCollClear *self)
{
    unsigned int i;
    self->m_a = 0;
    for (i = 0; i < 32; i++)
        self->m_tab[i] = 0;
    self->m_end = 0;
    return self;
}

// FUNCTION: GAME 0x134690
extern "C" void func_00134690(sCollClear *self)
{
    unsigned int i;
    self->m_a = 0;
    self->m_b = 0;
    D_00460D18 = 0;
    for (i = 0; i < 32; i++)
        self->m_tab[i] = 0;
    self->m_end = 0;
}

// FUNCTION: GAME 0x134608
extern "C" void func_00134608(sCollFlagList *self, int on)
{
    sCollFlagNode *n = self->m_head;
    if (n) {
        do {
            if (on == 1)
                n->m_flags |= 1;
            else
                n->m_flags &= ~1;
            n = n->m_next;
        } while (n);
    }
}

// FUNCTION: GAME 0x1346C8
extern "C" sCollLink *func_001346C8(sCollLink **self, int id)
{
    sCollLink *n;
    if (!id)
        return 0;
    for (n = *self; n; n = n->m_next) {
        if (n->m_id == id)
            break;
    }
    return n;
}

// FUNCTION: GAME 0x133900
extern "C" int *func_00133900()
{
    if (!D_00460D08[0])
        func_0031EEC8(D_00460D08, D_0041D618);
    return D_00460D08;
}
