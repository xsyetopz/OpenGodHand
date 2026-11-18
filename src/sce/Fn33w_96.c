// COMPILER: ee-gcc2.96
extern char D_00455910[], D_00455920[], D_00455940[], D_00455950[];
extern char D_00455A70[], D_00455A80[], D_00455AA0[], D_00455AB0[];
extern char D_00455BC8[], D_00455BD8[], D_00455BF8[], D_00455C08[], D_00456938[];
extern char D_00456930[], D_003EADC0[];
extern void (*D_003EADB8)();
extern int D_003EADBC;
void *memset(void *, int, unsigned);
unsigned strlen(const char *);
char *strncpy(char *, const char *, unsigned);
void func_00338A48(char *, char *);
void func_00339458(char *, char *);
void func_0033A048(char *, char *);
void func_0033F240(char *, char *, int);
void func_003A5A20(char *, char *, int);
void func_0033B6E8(char *);

// FUNCTION: GAME 0x338CD0
void func_00338CD0(int *a)
{
    if (!a) { func_00338A48(D_00455910, D_00455920); return; }
    if (!a[1]) { func_00338A48(D_00455940, D_00455950); return; }
    memset(a, 0, 0x24);
    a[1] = 0;
}

// FUNCTION: GAME 0x3396F8
void func_003396F8(int *a)
{
    if (!a) { func_00339458(D_00455A70, D_00455A80); return; }
    if (!a[1]) { func_00339458(D_00455AA0, D_00455AB0); return; }
    memset(a, 0, 0x40);
    a[1] = 0;
}

// FUNCTION: GAME 0x33A300
void func_0033A300(char *a)
{
    if (!a) { func_0033A048(D_00455BC8, D_00455BD8); return; }
    if (!a[4]) { func_0033A048(D_00455BF8, D_00455C08); return; }
    memset(a, 0, 0x30);
    a[4] = 0;
}

// FUNCTION: GAME 0x33E818
int func_0033E818(char *p, int n, short *out)
{
    int i;
    int r = 0x7FFFFFFF;
    register int k = 0x80;
    n--;
    for (i = 0; i < n; i += 2) {
        if (*(unsigned short *)(p + i) == k) {
            if (i < r) r = i;
            break;
        }
    }
    if (r != 0x7FFFFFFF) { *out = r; return 0; }
    *out = 0;
    return -1;
}

// FUNCTION: GAME 0x33F348
void func_0033F348(char *a, char *b, char *c, int d)
{
    func_0033F240(a, c, d);
    func_003A5A20(c, D_00456938, d - strlen(c) - 1);
    func_0033F240(b, c + strlen(c), 4 - strlen(c));
}

#ifdef NONMATCHING
// DRAFT: GAME 0x33F1A8
// diff: 2 words (lui/lw of D_003EADB8 uses $v0 instead of $v1)
void func_0033F1A8(char *a, char *b)
{
    if (a == 0 || b == 0) {
        func_0033B6E8(D_00456930);
        return;
    }
    strncpy(D_003EADC0, a, 0xFF);
    func_003A5A20(D_003EADC0, b, 0xFF);
    if (D_003EADB8) (*D_003EADB8)(D_003EADBC, D_003EADC0);
    func_0033B6E8(D_003EADC0);
}
#endif
