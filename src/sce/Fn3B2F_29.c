// COMPILER: ee-gcc2.9-991111
struct SemaP { int count, max, init, wait, attr; char *opt; };
struct Srv { int w0, w1, w2, w3, w4, self, w6, cli, w8, sid; };
extern char D_0077FF40[], D_00460060[];
extern struct Srv *func_003B2AC8(char *);
extern void func_003B2B70(struct Srv *);
extern int func_003B2688(int, struct Srv *, int, int, int, int);
extern int CreateSema(void *);
extern void WaitSema(int), DeleteSema(int);
// FUNCTION: GAME 0x3B2F48
int sceSifBindRpc(int *c, int sid, int mode)
{
    struct SemaP s;
    int *srv;
    c[4] = 0;
    c[9] = 0;
    srv = (int *)func_003B2AC8(D_0077FF40);
    if (!srv)
        return -1;
    c[1] = srv[6];
    c[0] = (int)srv;
    srv[8] = sid;
    srv[5] = (int)srv;
    srv[7] = (int)c;
    if (!(mode & 1)) {
        s.max = 1;
        s.opt = D_00460060;
        s.init = 0;
        c[2] = CreateSema(&s);
        if (c[2] < 0) {
            func_003B2B70((struct Srv *)srv);
            return -3;
        }
        if (!func_003B2688(0x80000009, (struct Srv *)srv, 0x40, 0, 0, 0)) {
            func_003B2B70((struct Srv *)srv);
            DeleteSema(c[2]);
            return -2;
        }
        WaitSema(c[2]);
        DeleteSema(c[2]);
        return 0;
    }
    c[2] = -1;
    if (!func_003B2688(0x80000009, (struct Srv *)srv, 0x40, 0, 0, 0)) {
        func_003B2B70((struct Srv *)srv);
        return -2;
    }
    return 0;
}
