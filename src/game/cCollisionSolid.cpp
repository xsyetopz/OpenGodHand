// Small free functions around the collision-solid code (0x133000-0x135FFF).

struct sCollTable {
    char _pad0[0x20];
    char *m_entries;
};

extern "C" void func_001352F8(int a, unsigned int b);

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
