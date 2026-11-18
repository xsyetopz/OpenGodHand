extern "C" void initialize__7cIDBase7eIdData5eIdNo(void *, int, int);
extern "C" void restartAnim__7cIDBase(void *);
extern "C" void *getIDWork__7cIDBasei(void *, int);
extern "C" void Initialize__12CustomIDWorkP7cIDWork(void *, void *);
extern "C" void SetMessNo__12CustomIDWorki(void *, int);
extern "C" void func_001F29C0(void *, int, int);
extern "C" void func_001F3488(void *, int);

#ifdef NONMATCHING
// DRAFT: GAME 0x1F27B0
extern "C" void func_001F27B0(char *self)
{
    char *a = self + 0x10;
    int i = 0;
    char *p = self + 0x60;
    initialize__7cIDBase7eIdData5eIdNo(a, 0x15, 1);
    restartAnim__7cIDBase(a);
    do {
        void *w = getIDWork__7cIDBasei(self + 0x10, i);
        i++;
        Initialize__12CustomIDWorkP7cIDWork(p, w);
        p += 0x7C;
    } while (i < 0x12);
    a = self + 0x930;
    func_001F29C0(self, 0x12, 0);
    char *c = a;
    int j = 0;
    initialize__7cIDBase7eIdData5eIdNo(a, 0x15, 2);
    char *m = self + 0xA78;
    restartAnim__7cIDBase(a);
    a = self + 0x980;
    do {
        void *w = getIDWork__7cIDBasei(c, j);
        j++;
        Initialize__12CustomIDWorkP7cIDWork(a, w);
        a += 0x7C;
    } while (j < 3);
    SetMessNo__12CustomIDWorki(m, 0x300F);
    func_001F3488(self, 0);
}
#endif
