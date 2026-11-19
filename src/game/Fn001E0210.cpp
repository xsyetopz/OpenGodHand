extern "C" {
void func_001E33B0(char *);
void func_001E3858(char *);
void func_001E39D0(char *);
void func_001E3B40(char *);
void func_001E3CB0(char *);
void func_001E3DD0(char *);
void func_001E4010(char *);
void func_001E4308(char *);
void func_001E44A8(char *);
void func_001E4610(char *);
void func_001E73C0(char *);
void func_001E7440(char *);
void func_001E79E8(char *);
void func_001E7EA0(char *);
int getGold__9cCoreSave(void *);
void SetNumber__12CustomIDWorki(char *, int);
}
extern char CoreSave[];
extern unsigned D_00747A2C;

struct F0210 {
    short off;
    short pad;
    void (*fn)(char *, short *);
};
extern F0210 D_003BE0B0[];

#ifdef NONMATCHING
// DRAFT: GAME 0x1E0210
// 5 words differ: gcc CSEs the two table-entry address computations into one register; original keeps addu a1 (lh and arg) and v1 (lw of fn), then jalr v0. Tried a/e declaration order over a0-a2 and e0-e4, char*/int-cast forms, separate fn-pointer variant: all 5 words.
extern "C" void func_001E0210(char *self)
{
    int i = *(int *)(self + 4);
    short *a = (short *)((char *)D_003BE0B0 + (i << 3));
    F0210 *e = (F0210 *)((char *)D_003BE0B0 + (i << 3));
    char *q = self + 0x4D0;
    e->fn(self + *a, a);
    func_001E3858(self);
    func_001E39D0(self);
    func_001E3B40(self);
    func_001E3CB0(self);
    func_001E3DD0(self);
    func_001E4010(self);
    func_001E4308(self);
    func_001E44A8(self);
    func_001E4610(self);
    func_001E79E8(self + 0x370);
    func_001E7EA0(self + 0x58);
    func_001E7EA0(self + 0x160);
    func_001E7EA0(self + 0x268);
    int g = getGold__9cCoreSave(CoreSave);
    SetNumber__12CustomIDWorki(self + 0x520, g);
    func_001E73C0(q);
    func_001E7440(q);
    if (D_00747A2C & 0x200) func_001E33B0(self);
}
#endif
