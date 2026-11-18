// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/string/strstr.c (0x3A93F8).
// FUNCTION: GAME 0x3A93F8
char *func_003A93F8(const char *searchee, const char *lookfor)
{
    if (*searchee == 0) {
        if (*lookfor)
            return 0;
        return (char *)searchee;
    }

    while (*searchee) {
        unsigned int i = 0;

        while (1) {
            if (lookfor[i] == 0)
                return (char *)searchee;
            if (lookfor[i] != searchee[i])
                break;
            i++;
        }
        searchee++;
    }
    return 0;
}
