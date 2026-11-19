extern "C" {
void func_001E6938(char *);
void func_001E6BE8(char *);
void func_001E6CD8(char *);
void func_001E6DA0(char *);
void func_001E6E68(char *);
void func_001E6FE8(char *);
void func_001E73C0(char *);
void func_001E7440(char *);
void func_001E79E8(char *);
void func_001E8830(char *);
int getGold__9cCoreSave(void *);
void SetNumber__12CustomIDWorki(char *, int);
}
extern char CoreSave[];
extern int D_00747A2C;

struct F082E;
struct F082E {
    short off;
    short pad;
    void (*fn)(char *, short *);
};
extern F082E D_003BE140[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1E4D48
// 5 words differ: gcc CSEs the two table-entry address computations into one register; original keeps addu a1 (lh and arg) and v1 (lw of fn), then jalr v0. Tried &D[i], int-cast adds, short* + (i<<2), 2-arg fn(self+off, e), a/e declaration order over a0-a2 and e0-e4, separate fn-pointer variant: all 5 words.
extern "C" void func_001E4D48(char *self)
{
    int i = *(int *)(self + 4);
    short *a = (short *)D_003BE140 + (i << 2);
    F082E *e = &D_003BE140[i];
    e->fn(self + *a, a);
    func_001E6BE8(self);
    func_001E6CD8(self);
    func_001E6DA0(self);
    func_001E6E68(self);
    func_001E6FE8(self);
    func_001E79E8(self + 0x310);
    func_001E8830(self + 0x58);
    func_001E8830(self + 0x140);
    func_001E8830(self + 0x228);
    int g = getGold__9cCoreSave(CoreSave);
    SetNumber__12CustomIDWorki(self + 0x450, g);
    func_001E73C0(self + 0x400);
    func_001E7440(self + 0x400);
    if (D_00747A2C & 0x200) func_001E6938(self);
}
#endif
