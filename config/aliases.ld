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


/* Compiled C callers of libio members (src/sce/libio/iostream.cc) that
   still use the automatic names. */
func_00389268 = flush__7ostream;
func_00389398 = _skip_ws__7istream;
func_003885B0 = __ls__7ostreamc;
func_00388A00 = __ls__7ostreami;

/* Callees of src/sce/libio/iostream.cc under the names libio gives them. */
_IO_getc = func_0038EAE0;
_IO_putc = func_0038EB28;
_IO_seekoff = func_0038E3F0;
_IO_seekpos = func_0038E490;
_IO_sgetn = func_0038C9E8;
__underflow = func_0038C5B8;
close__7filebuf = func_0038F020;
do_osfx__7ostream = func_00389548;
ignore__9streambufi = func_0038B168;
read_int__FR7istreamRUxRi = func_00387CD8;
scan__7istreamPCce = func_0038ADC8;
skip_ws__FP9streambuf = func_003875A8;
sputbackc__9streambufc = func_0038B460;
write_int__FR7ostreamUxi = func_00388660;
_vt$3ios = 0x0045D340;
_vt$7istream$3ios = 0x0045D168;
_vt$7ostream$3ios = 0x0045D178;
_vt$8iostream$3ios = 0x0045D158;
