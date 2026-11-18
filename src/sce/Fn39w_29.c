// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE libio small wrappers: list link/unlink and 64-bit streamsize adapters over 32-bit libio entry points.
typedef long ssize;
extern int _IO_un_link(void *);
extern int _IO_link_in(void *);
extern unsigned int _IO_default_xsputn(void *, const void *, int);
extern unsigned int _IO_default_xsgetn(void *, void *, int);
extern unsigned int _IO_sgetn(void *, void *, int);
extern unsigned int _IO_file_xsputn(void *, const void *, int);
extern unsigned int func_0038C8B0(void *, const void *, int);
extern unsigned int func_0038CA10(void *, void *, int);

// FUNCTION: GAME 0x38B030
int func_0038B030(void *fp) { return _IO_un_link(fp); }

// FUNCTION: GAME 0x38B050
int func_0038B050(void *fp) { return _IO_link_in(fp); }

// FUNCTION: GAME 0x38B108
unsigned long func_0038B108(void *f, const void *d, ssize n) { return func_0038C8B0(f, d, n); }

// FUNCTION: GAME 0x38B138
unsigned long func_0038B138(void *f, void *d, ssize n) { return func_0038CA10(f, d, n); }

// FUNCTION: GAME 0x38BA38
unsigned long func_0038BA38(void *f, void *d, ssize n) { return _IO_sgetn(f, d, n); }

// FUNCTION: GAME 0x38F0F0
unsigned long func_0038F0F0(void *f, const void *d, ssize n) { return _IO_file_xsputn(f, d, n); }

extern int func_0038F3D8(void *);
extern int func_003A6420(int);
extern void func_003A5F68(int);
extern int func_00393878();

// FUNCTION: GAME 0x38EF80
int func_0038EF80(void *fp) { return func_0038F3D8(fp); }

// FUNCTION: GAME 0x393720
int func_00393720(int *o) { return func_003A6420(o[22]); }

// FUNCTION: GAME 0x393740
void func_00393740(int *o)
{
    func_003A5F68(o[22]);
    o[22] = 0;
}

// FUNCTION: GAME 0x3938E0
int func_003938E0(char *o) { return func_00393878(o + 8); }

// FUNCTION: GAME 0x393BF8
int func_00393BF8(char *o) { return func_00393878(o + 8); }

// FUNCTION: GAME 0x393900
int func_00393900(int *o) { return ((o[2] >> 1) ^ 1) & 1; }

// FUNCTION: GAME 0x393C18
int func_00393C18(int *o) { return ((o[2] >> 1) ^ 1) & 1; }

// FUNCTION: GAME 0x393F10
int func_00393F10(int *o) { return ((o[0] >> 1) ^ 1) & 1; }

struct Sb {
    int flags;
    int pad04;
    int w8;
    int wC;
    int pad10[8];
    struct Sb *next;
    char pad34[0xC];
    long off;
    char pad48[0x10];
    void *fp;
};
extern unsigned int fwrite(const void *, int, int, void *);
extern unsigned long func_0038B108(void *, const void *, long);

// FUNCTION: GAME 0x38C238
int func_0038C238(int *o)
{
    long n = o[2] - o[3];
    int *q = (int *)o[12];
    if (q) {
        do {
            if (q[2] < n)
                n = q[2];
            q = (int *)q[0];
        } while (q);
    }
    return (int)n;
}

// FUNCTION: GAME 0x3936C0
unsigned long func_003936C0(struct Sb *o, const void *d, long n)
{
    unsigned long r = fwrite(d, 1, n, o->fp);
    if (o->off >= 0)
        o->off += n;
    return r;
}

// FUNCTION: GAME 0x393820
unsigned long func_00393820(struct Sb *o, const void *d, long n)
{
    if (((o->flags >> 1) ^ 1) & 1)
        return func_0038B108(o, d, n);
    return fwrite(d, 1, n, o->fp);
}

extern int func_00392A80(void *, int, int);
extern int func_003A6020(int);
extern int doallocate__7filebuf(void *);

// FUNCTION: GAME 0x393770
int func_00393770(int *o)
{
    if (func_00392A80(o, o[4], o[5] - o[4]))
        return -1;
    if (!(o[0] & 8)) {
        int r = func_003A6020(o[22]);
        if (r)
            return -1;
    }
    return 0;
}

// FUNCTION: GAME 0x3937D0
int func_003937D0(int *o, int c)
{
    if (doallocate__7filebuf(o) == -1)
        return -1;
    if (c != -1)
        return c;
    return func_003A6020(o[22]);
}

#ifdef NONMATCHING
struct VE {
    short d, i;
    int (*f)(void *, int, int);
};

// DRAFT: GAME 0x393878
int func_00393878(int *o, int a)
{
    if (a) {
        int fl = o[0];
        if (fl & 2)
            o[0] = fl & ~2;
    } else if (!(o[0] & 2)) {
        struct VE *v = *(struct VE **)((char *)o + 0x50);
        v[10].f((char *)o + v[10].d, 0, 0);
    }
}
#endif

/* istream/ostream thunks and state setters in 0x389000-0x38B100 */
extern int func_0038F1A0();
extern int func_0038F140();
extern int __rs__7istreamRc();
extern int func_00387B78();
extern int func_00387890();
extern int get__7istreamRc();
extern int __ls__7ostreami();
extern int __ls__7ostreamUi(void *, unsigned int);
extern int _IO_switch_to_get_mode();
extern int _IO_free_backup_area();

struct St {
    char pad[0x10];
    unsigned long long st;
};

// FUNCTION: GAME 0x3897A8
struct St *func_003897A8(struct St *o) { o->st = (o->st & ~0x70) | 0x20; return o; }

// FUNCTION: GAME 0x3897C8
struct St *func_003897C8(struct St *o) { o->st = (o->st & ~0x70) | 0x40; return o; }

// FUNCTION: GAME 0x3897E8
struct St *func_003897E8(struct St *o) { o->st = (o->st & ~0x70) | 0x10; return o; }

// FUNCTION: GAME 0x389808
int func_00389808(void *o) { return func_0038F1A0(o); }

// FUNCTION: GAME 0x389960
int func_00389960(void *o) { return func_0038F140(o); }

// FUNCTION: GAME 0x389D50
int func_00389D50(void *o, int (*f)(void *)) { return f(o); }

// FUNCTION: GAME 0x389D70
void *func_00389D70(void **o, void (*f)(void *))
{
    f(*o);
    return o;
}

// FUNCTION: GAME 0x389DA0
int func_00389DA0(void *o) { return __rs__7istreamRc(o); }

// FUNCTION: GAME 0x389DC0
int func_00389DC0(void *o) { return __rs__7istreamRc(o); }

// FUNCTION: GAME 0x389DE0
int func_00389DE0(void *o) { return func_00387B78(o); }

// FUNCTION: GAME 0x389E00
int func_00389E00(void *o) { return func_00387B78(o); }

// FUNCTION: GAME 0x38A178
int func_0038A178(void *o) { return func_00387890(o); }

// FUNCTION: GAME 0x38A198
int func_0038A198(void *o) { return func_00387890(o); }

// FUNCTION: GAME 0x38A1B8
int func_0038A1B8(void *o) { return func_00387890(o); }

// FUNCTION: GAME 0x38A218
int func_0038A218(void *o) { return get__7istreamRc(o); }

// FUNCTION: GAME 0x38A258
int func_0038A258(void *o) { return get__7istreamRc(o); }

// FUNCTION: GAME 0x38A4E8
int func_0038A4E8(void *o) { return __ls__7ostreami(o); }

// FUNCTION: GAME 0x38A508
int func_0038A508(void *o, unsigned short v) { return __ls__7ostreamUi(o, v); }

// FUNCTION: GAME 0x38B070
int func_0038B070(void *o) { return _IO_switch_to_get_mode(o); }

// FUNCTION: GAME 0x38B090
int func_0038B090(void *o) { return _IO_free_backup_area(o); }
