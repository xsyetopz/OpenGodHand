// Thin forwarders: adjust `this` to an embedded member and tail into its method.
extern "C" void SetNumber__12CustomIDWorki(void *, int);
extern "C" void release__7cIDBase(void *);
extern "C" void trans__7cIDBase(void *);

struct IdOwner {
    char _pad[1];
};

// FUNCTION: GAME 0x1D5760
extern "C" void func_001D5760(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x158, n);
}

// FUNCTION: GAME 0x1D5780
extern "C" void func_001D5780(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x250, n);
}

// FUNCTION: GAME 0x1D6A30
extern "C" void func_001D6A30(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0xD74, n);
}

// FUNCTION: GAME 0x1D6A50
extern "C" void func_001D6A50(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0xE6C, n);
}

// FUNCTION: GAME 0x1DD218
extern "C" void func_001DD218(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x918, n);
}

// FUNCTION: GAME 0x1DD238
extern "C" void func_001DD238(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x820, n);
}

// FUNCTION: GAME 0x1DEE40
extern "C" void func_001DEE40(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x7A4, n);
}

// FUNCTION: GAME 0x1E7848
extern "C" void func_001E7848(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x1C4, n);
}

// FUNCTION: GAME 0x1ED490
extern "C" void func_001ED490(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x124C, n);
}

// FUNCTION: GAME 0x1EE2A8
extern "C" void func_001EE2A8(IdOwner *self, int n)
{
    SetNumber__12CustomIDWorki((char *)self + 0x918, n);
}

// FUNCTION: GAME 0x1DD180
extern "C" void func_001DD180(IdOwner *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1DEDA8
extern "C" void func_001DEDA8(IdOwner *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1ED660
extern "C" void func_001ED660(IdOwner *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1EDF60
extern "C" void func_001EDF60(IdOwner *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1ECBD0
extern "C" void func_001ECBD0(IdOwner *self)
{
    release__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1DD1F8
extern "C" void func_001DD1F8(IdOwner *self)
{
    trans__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1DEE20
extern "C" void func_001DEE20(IdOwner *self)
{
    trans__7cIDBase((char *)self + 0x10);
}

// FUNCTION: GAME 0x1ED6E0
extern "C" void func_001ED6E0(IdOwner *self)
{
    trans__7cIDBase((char *)self + 0x10);
}
