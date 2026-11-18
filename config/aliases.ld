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
do_osfx__7ostream = func_00389548;
read_int__FR7istreamRUxRi = func_00387CD8;
scan__7istreamPCce = func_0038ADC8;
skip_ws__FP9streambuf = func_003875A8;
write_int__FR7ostreamUxi = func_00388660;
_vt$3ios = 0x0045D340;
_vt$7istream$3ios = 0x0045D168;
_vt$7ostream$3ios = 0x0045D178;
_vt$8iostream$3ios = 0x0045D158;

/* Compiled C callers of units that src/sce/libio now names (streambuf, genops, filebuf, fileops, io*). */
func_0038B0B0 = __overflow__FP9streambufi;
func_0038B168 = ignore__9streambufi;
func_0038BA10 = sputc__9streambufi;
func_0038C9E8 = _IO_sgetn;
func_0038CD18 = _IO_sputbackc;
func_0038CFC0 = _IO_init_marker;
func_0038EAE0 = _IO_getc;
func_0038EB28 = _IO_putc;

/* Callees of the libio sources above under the names libio gives them. */
_IO_default_setbuf = func_0038CB28;
_IO_default_xsputn = func_0038C8B0;
_IO_do_write = func_00392A80;
_IO_file_attach = func_00392998;
_IO_file_doallocate = func_0038F3D8;
_IO_file_fopen = func_00392830;
_IO_file_overflow = func_00392CD0;
_IO_file_read = func_00393230;
_IO_file_seekoff = func_00392F00;
_IO_file_sync = func_00392E48;
_IO_file_underflow = func_00392BA0;
_IO_file_write = func_003932B8;
_IO_padn = func_0038E138;
__rtti_si = func_0031EEA8;
__rtti_user = func_0031EEC8;
__throw = func_00320E18;
close = func_003B0388;
fstat = func_003B0450;
lseek = func_003B0390;
sync_with_stdio__3iosi = func_0038AFB0;
terminate__Fv = func_003211E0;
__errno = func_003A4FB8;
_IO_least_marker = func_0038C238;
setbuf__7filebufPci = func_0038EF60;
