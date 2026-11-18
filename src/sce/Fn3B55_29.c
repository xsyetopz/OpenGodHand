// COMPILER: ee-gcc2.9-991111
struct SemaP { int count, max, init, wait, attr; char *opt; };
struct R { int sema; int *res; int w8; int fd; int arg; };
extern int D_0077FFC0;
extern char D_00780C00[], D_007816C0[], D_00460240[];
extern int D_003FAEDC;
extern int *func_003B3A48(int);
extern void func_003B3EC8(int), func_003B3EF8(void);
extern int func_003B3958(char *, int, int, void *, int, char *, int, int, int, int);
extern int CreateSema(void *);
extern void WaitSema(int), DeleteSema(int);
// FUNCTION: GAME 0x3B5520
int sceDread(int fd, int buf)
{
    struct SemaP s;
    int res;
    int *f;
    int sema;
    struct R *r = (struct R *)&D_0077FFC0;
    f = func_003B3A48(fd);
    func_003B3EC8(0xB);
    if (!D_003FAEDC || !f || !f[1]) {
        func_003B3EF8();
        return -9;
    }
    r->fd = f[0];
    r->arg = buf;
    s.max = 1;
    s.opt = D_00460240;
    s.init = 0;
    sema = CreateSema(&s);
    D_0077FFC0 = sema;
    r->res = &res;
    r->w8 = 4;
    if (func_003B3958(D_007816C0, 0xB, 0, r, 0x20, D_00780C00, 4, 0, 0, 0) < 0) {
        WaitSema(sema);
        func_003B3EF8();
        return -0xB;
    }
    f = *(int **)((unsigned)D_00780C00 | 0x20000000);
    func_003B3EF8();
    if (!f) {
        DeleteSema(sema);
        return -0xB;
    }
    WaitSema(sema);
    DeleteSema(sema);
    return res;
}
