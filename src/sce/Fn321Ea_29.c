// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE out-of-memory hook thunks around 0x3211E0: each indirect call is followed by a framed jal.

#ifdef NONMATCHING
extern int (*D_003C4908)();
extern int (*D_003C4F00)();
extern int func_00320360();
extern void func_003211E0Call() __asm__("func_003211E0");

// DRAFT: GAME 0x3211E0 (original ends right after the jalr with no epilogue and uses lui v0/lw v1; noreturn still emits ld ra/jr)
void func_003211E0() { D_003C4908(); }

// DRAFT: GAME 0x3211F8
int func_003211F8(int a)
{
    int o;
    func_003211E0Call();
    o = (int)D_003C4908;
    D_003C4908 = (int (*)())a;
    return o;
}

// DRAFT: GAME 0x321228 (same missing-epilogue shape as 0x3211E0)
void func_00321228() { D_003C4F00(); }

// DRAFT: GAME 0x321240
int func_00321240() { return *(int *)func_00320360() + 8; }
#endif
