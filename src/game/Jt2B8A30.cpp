// Slot-id predicate; sole switch of 0x2B8A30.
// FUNCTION: GAME 0x2B8A30
extern "C" int func_002B8A30(void *self, unsigned id)
{
    switch (id) {
    case 0:
    case 1:
    case 3:
    case 5:
    case 7:
        return 1;
    case 2:
    case 4:
    case 6:
    case 8:
    default:
        return 0;
    }
}
