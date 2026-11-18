#define B(o) (*(signed char *)((char *)self + (o)))
#define U(o) (*(unsigned char *)((char *)self + (o)))
#define W(o) (*(int *)((char *)self + (o)))
struct EmNode { int a; EmNode *next; int c; int d; };
extern "C" {
// FUNCTION: GAME 0x291FD8
int func_00291FD8(char *self) { return W(0x530) > 0; }
// FUNCTION: GAME 0x292018
void func_00292018(char *self, int n) { if (W(0x510) < n) W(0x510) = n; }
// FUNCTION: GAME 0x292F08
int func_00292F08(char *self) { return B(0x538) != 0; }
// FUNCTION: GAME 0x292F18
int func_00292F18(char *self) { if (B(0x539) != 0) return 0; B(0x539) = 0xF; return 1; }
// FUNCTION: GAME 0x292F68
void func_00292F68() {}
// FUNCTION: GAME 0x2930A8
int func_002930A8(char *self) { int v = W(0x55C); W(0x55C) = v + 1; return v; }
// FUNCTION: GAME 0x2930B8
void func_002930B8(char *self) { B(0x53A) = 2; }
// FUNCTION: GAME 0x2930E0
int func_002930E0(char *self) { return B(0x53B) != 0; }
// FUNCTION: GAME 0x293120
int func_00293120(char *self) { return B(0x53D) != 0; }
// FUNCTION: GAME 0x293130
int func_00293130(char *self) { return W(0x500); }
// FUNCTION: GAME 0x293718
void func_00293718(char *self, int f) { U(0x5A3) |= f; }
// FUNCTION: GAME 0x293728
void func_00293728(char *self) { U(0x5A3) = 0; U(0x5A0) = 0; }
// FUNCTION: GAME 0x293738
void func_00293738(char *self, int f) { U(0x5A4) |= f; }
// FUNCTION: GAME 0x293750
void func_00293750(char *self) { U(0x5A5) |= 1; }
// FUNCTION: GAME 0x294968
void func_00294968(char *self, float f) { *(float *)(self + 0x544) = f; }
// FUNCTION: GAME 0x294A68
int func_00294A68(char *self) { return B(0x540) != 0; }
// FUNCTION: GAME 0x294A78
int func_00294A78(char *self) { return B(0x541) != 0; }
// FUNCTION: GAME 0x294AD8
void func_00294AD8() {}

// FUNCTION: GAME 0x291FE8
void func_00291FE8(char *self, float *src, int n) { float *d = (float *)(self + 0x520); if (d != src) { d[0] = src[0]; d[1] = src[1]; d[2] = src[2]; } W(0x530) = n; }
// FUNCTION: GAME 0x294898
void func_00294898(char *self, int v) { int *p = (int *)(self + 0x5AC); for (unsigned i = 0; i < 2; i++, p++) { if (*p == 0) { *p = v; return; } } }
// FUNCTION: GAME 0x2948C8
int func_002948C8(char *self, unsigned i) { if (i > 1) return 0; return *(int *)(((int)self) + (i << 2) + 0x5AC); }
// FUNCTION: GAME 0x294970
int func_00294970(char *self) { return *(float *)(self + 0x544) > 0.0f; }
// FUNCTION: GAME 0x2949C8
void func_002949C8(char *self) { if (B(0x53E)) { U(0x53E) = U(0x53E) - 1; } }
// FUNCTION: GAME 0x294998
int func_00294998(char *self) { if (B(0x53E) == 0) return 0; func_002949C8(self); return 1; }
struct cSndFwd { int SeCall(int, short, short, short, unsigned, int) __asm__("SeCall__4cSnd6eSeBlksssUii"); };
extern cSndFwd Snd;
extern unsigned D_00747A30;
extern char g_EmManage;
int func_00292F08(char *);
void func_00290090(void *);
void *SetEffect(int, int, void *, void *, int, unsigned) __asm__("SetEffect__F12eEffDataType6eEffIdP4cObjP12tagEFF_PARAMiT2");
void SetBigHitEffWait(char *, int) __asm__("SetBigHitEffWait__9cEmManagei");
// FUNCTION: GAME 0x292E80
void func_00292E80(char *self)
{
    if (!(D_00747A30 & 0x800) && !func_00292F08(self)) {
        SetEffect(0, 15, 0, 0, -1, 0xFFFFFFFFu);
        SetBigHitEffWait(self, 2);
    }
}
// FUNCTION: GAME 0x294A88
void func_00294A88(char *self)
{
    if (*(short *)(self + 0x542) == 0) {
        *(short *)(self + 0x542) = 150;
        Snd.SeCall(2, 164, -1, -1, 0, 0);
    }
}
// FUNCTION: GAME 0x294AE0
void func_00294AE0(void *a, int b)
{
    if (b == 0xFFFF && a) func_00290090(&g_EmManage);
}
extern char g_EmSet;
void roomInit__11cEmSetParam(void *);
void func_00290110(void *);
void func_00297660(void *);
// FUNCTION: GAME 0x2962A8
void *func_002962A8(void *self) { return self; }
// FUNCTION: GAME 0x290028
void func_00290028(char *self) { *(int *)(self + 8) = 0; self[0x10] = 0; *(int *)self = 0; *(int *)(self + 0xC) = -1; *(int *)(self + 4) = 0; }
// FUNCTION: GAME 0x290000
void *func_00290000(char *self) { *(int *)self = 0; *(int *)(self + 0xC) = -1; *(int *)(self + 4) = 0; *(int *)(self + 8) = 0; self[0x10] = 0; return self; }
// FUNCTION: GAME 0x290230
void func_00290230(void *self) { func_00290110(self); }
// FUNCTION: GAME 0x296350
void func_00296350(void *self) { func_00297660(self); }
// FUNCTION: GAME 0x294B18
void func_00294B18() { func_00294AE0((void *)1, 0xFFFF); }
// FUNCTION: GAME 0x295928
void func_00295928(void *a, int b) { if (b == 0xFFFF && a) roomInit__11cEmSetParam(&g_EmSet); }
// FUNCTION: GAME 0x295958
void func_00295958() { func_00295928((void *)1, 0xFFFF); }
// FUNCTION: GAME 0x290958
int func_00290958(char *p) { unsigned i; for (i = 0; i < 0x40; i++, p += 0x14) { if (*(unsigned char *)(p + 0x10) == 0) return i; } return -1; }
// FUNCTION: GAME 0x290988
int func_00290988(char *self, int k) { int n = 0; for (EmNode *p = *(EmNode **)(self + 0x500); p; p = p->next) { if (p->d == k) n++; } return n; }
// FUNCTION: GAME 0x2919C0
int func_002919C0(char *self, int u, int k) { int n = 0; for (EmNode *p = *(EmNode **)(self + 0x500); p; p = p->next) { char *o = (char *)p->c; if (o && *(int *)(o + 0x564) == k) n++; } return n; }
// FUNCTION: GAME 0x295660
char *func_00295660(char *self) { char *q = self + 0x10; char *f = self + 0x23; for (unsigned i = 0; i < 2; i++, q += 0x18, f += 0x18) { if (*(unsigned char *)f == 0) return q; } return 0; }
// FUNCTION: GAME 0x290048
void func_00290048(char *self, int a, int b) { if (a && b >= -1 && *(int *)(self + 8) == 0 && *(int *)(self + 0xC) == -1 && *(unsigned char *)(self + 0x10) != 1) { *(int *)(self + 8) = a; *(int *)(self + 0xC) = b; *(unsigned char *)(self + 0x10) = 1; } }
extern char g_RoomSave;
extern char CoreSave;
extern char RelSys;
extern unsigned D_00747A24;
extern char *g_Sce;
void *GetEm__9cEmManageUc(void *, unsigned char);
char *func_002BEF60(void *);
int func_001F9FF0(void *);
void unlinkNoFree__7cRelSysQ27cRelSys8eRelType(void *, int);
void free__5cHeapPv(void *, void *);
void *memset(void *, int, unsigned);
unsigned irand__Fv();
// FUNCTION: GAME 0x295978
int func_00295978(char *self) { void *e = GetEm__9cEmManageUc(&g_EmManage, *(unsigned char *)self); *(void **)(self + 4) = e; return e != 0; }
// FUNCTION: GAME 0x2954D0
void func_002954D0(int a, int b, int n) { char *p = func_002BEF60(&g_RoomSave); if (p) { if (n > 0) *(short *)(p + 0x16) = n; else *(short *)(p + 0x16) = 0; } }
// FUNCTION: GAME 0x2962B0
void func_002962B0(char *self) { *(int *)(self + 0x38) = func_001F9FF0(&CoreSave); func_00297660(self); *(unsigned char *)(self + 0x34) = 0; *(int *)self = 0; }
// FUNCTION: GAME 0x295600
void func_00295600(char *self)
{
    if (!(D_00747A24 & 0x1000000) && *(unsigned char *)(g_Sce + 0x14) != 1) {
        memset(self + 0x10, 0, 0x30);
        *(int *)(self + 4) = 0xFFFF;
    }
}
}
