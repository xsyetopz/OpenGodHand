struct MsgT { char _p[0xBDC]; int t[1]; };
extern MsgT *Message;

extern "C" void func_002B4560(void *);
extern "C" void func_00345610(void *);
extern "C" void func_002BB010(void *);
extern "C" void func_00394F20(int);
extern "C" void func_00394D58(int);
extern "C" void func_002BF170(void *);

// FUNCTION: GAME 0x2B45D8
extern "C" void func_002B45D8() {}

// FUNCTION: GAME 0x2B45E0
extern "C" void func_002B45E0() {}

// FUNCTION: GAME 0x2B1270
extern "C" int func_002B1270(void *self, unsigned short *p)
{
    return Message->t[p[1]];
}

// FUNCTION: GAME 0x2B2AE8
extern "C" int func_002B2AE8(char *self)
{
    self[0x3C] = 0;
    self[0x70] = 2;
    *(int *)(self + 0x18) = 0;
    self[0xA4] = 2;
    return 0;
}

// FUNCTION: GAME 0x2B4390
extern "C" void func_002B4390(void *self)
{
    func_002B4560(self);
}

// FUNCTION: GAME 0x2B4A30
extern "C" void func_002B4A30(void *self)
{
    func_00345610(self);
}

// FUNCTION: GAME 0x2BA4B0
extern "C" void func_002BA4B0(void *self)
{
    func_002BB010(self);
}

// FUNCTION: GAME 0x2BE6C8
extern "C" void func_002BE6C8(int *self)
{
    func_00394F20(*self);
}

// FUNCTION: GAME 0x2BE6E8
extern "C" void func_002BE6E8()
{
    func_00394D58(0);
}

// FUNCTION: GAME 0x2BF130
extern "C" void func_002BF130(void *self)
{
    func_002BF170(self);
}
