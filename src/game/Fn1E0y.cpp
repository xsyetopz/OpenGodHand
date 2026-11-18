extern "C" void systemInit__11cDataHolder(char *);
extern "C" int func_001FF0D8(char *);

// FUNCTION: GAME 0x1FEE00
extern "C" int func_001FEE00(char *s, int key)
{
    int i = *(int *)(s + 4);
    i--;
    for (; i != -1; i--) {
        if (func_001FF0D8(*(char **)(s + 8) + i * 0x5C)) {
            if (*(int *)(*(char **)(s + 8) + i * 0x5C + 0x20) == key)
                return i;
        }
    }
    return -1;
}

// FUNCTION: GAME 0x1FE6C8
extern "C" void func_001FE6C8(char *s, int v)
{
    int i = *(int *)(s + 4);
    i--;
    for (; i != -1; i--)
        systemInit__11cDataHolder(*(char **)(s + 8) + i * 0x5C);
    *(int *)s = v;
}
