extern "C" void *memset(void *, int, unsigned long);
extern "C" void func_001FC810(void *, void *, int);
extern "C" char *func_002BB138(void *, int);

// FUNCTION: GAME 0x1FDD38
extern "C" int func_001FDD38(char *self, int key)
{
    int buf[20];
    memset(buf, 0, 0x50);
    char *p = *(char **)(self + 0x3C);
    if (p) {
        do {
            int n = 0;
            func_001FC810(p, buf, 0x14);
            int a = buf[0];
            if (a) {
                int *q = buf;
                do {
                    char *r = func_002BB138((char *)a + 0x14, 1);
                    n++;
                    if (*(int *)(r + 0x30) == key)
                        return 1;
                    q++;
                    if (n >= 0x14)
                        break;
                    a = *q;
                } while (a);
            }
            p = *(char **)(p + 0x24);
        } while (p);
    }
    return 0;
}
