extern char D_00429EC8[];
extern "C" void *func_001B6E90(void *);

// FUNCTION: GAME 0x001C8F80
extern "C" char *func_001C8F80(char *self)
{
    func_001B6E90(self);
    *(char **)(self + 0x214) = D_00429EC8;
    *(int *)(self + 0x600) = 5;
    *(int *)(self + 0x604) = 0xE;
    *(int *)(self + 0x608) = 0;
    return self;
}
