/* Names that compiled code references for functions the original symbol table
   leaves unnamed. gcc 2.95 mangles `operator delete(void*)` as
   __builtin_delete; the game's version frees through cHeap. */
__builtin_delete = func_0030F5A0;

/* The cEvent wrappers around 0x297AA8 reference data whose relocations hold 0
   in the original executable (`lui a0,0; addiu a0,a0,0`, like `jal func_0`):
   the symbols resolved to address 0 at the original link. */
D_Ev297AA8 = 0x0;
D_Ev297B98 = 0x10; /* a field at offset 0x10 of the same null base */
D_Ev297BF8 = 0x0;

/* Data addresses taken by the cEvent callbacks around 0x298000. */
D_Ev586AF0 = 0x586AF0;
D_Ev44A9B0 = 0x44A9B0;
D_Ev44A9B8 = 0x44A9B8;
D_Ev44A9D0 = 0x44A9D0;
D_Ev44A9D8 = 0x44A9D8;
