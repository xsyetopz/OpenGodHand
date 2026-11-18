// FUNCTION: GAME 0x2A71F0
extern "C" void func_002A71F0(char *t)
{
    if (*(char **)t) {
        unsigned i = 0;
        if (*(int *)(t + 4)) {
            do {
                char *e = *(char **)t + *(int *)(t + 8) * i;
                if (((*(unsigned *)e & 0x201) ^ 1) == 0) {
                    char *vt = *(char **)(t + 0x18);
                    (*(void (**)(char *, char *))(vt + 0x34))(t + *(short *)(vt + 0x30), e);
                }
                i++;
            } while (i < *(unsigned *)(t + 4));
        }
    }
}
