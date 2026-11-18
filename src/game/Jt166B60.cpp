// Fall-through trans calls keyed on the signed byte at 0x5A; sole switch of 0x166B60.
extern "C" void trans__7cIDBase(void *self);

// FUNCTION: GAME 0x166B60
extern "C" void func_00166B60(char *self)
{
    switch (self[0x5A]) {
    case 2:
    case 3:
        trans__7cIDBase(self + 0xE0);
    case 0:
    case 1:
    case 4:
    default:
        trans__7cIDBase(self);
    }
}
