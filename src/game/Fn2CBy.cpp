// God Hand: unit in 0x2CB778.

extern "C" char *func_002CC4B8(char *, int);
extern "C" int func_002CFC68(char *);

// FUNCTION: GAME 0x2CB778
extern "C" int func_002CB778(char *self, int id)
{
    if (id == -1) return 1;
    if (*(int *)(func_002CC4B8(self, id) + 0x3C) == -1) return 1;
    return func_002CFC68(func_002CC4B8(self, id));
}
