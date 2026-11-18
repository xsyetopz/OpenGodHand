#define B(o) (*(signed char *)((char *)self + (o)))
#define U(o) (*(unsigned char *)((char *)self + (o)))
#define W(o) (*(int *)((char *)self + (o)))
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
}
