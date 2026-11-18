// COMPILER: ee-gcc2.9-991111
// FLAGS: -O2
// SCE libio small wrappers: list link/unlink and 64-bit streamsize adapters over 32-bit libio entry points.
typedef long ssize;
extern int _IO_un_link(void *);
extern int _IO_link_in(void *);
extern unsigned int _IO_default_xsputn(void *, const void *, int);
extern unsigned int _IO_default_xsgetn(void *, void *, int);
extern unsigned int _IO_sgetn(void *, void *, int);
extern unsigned int _IO_file_xsputn(void *, const void *, int);
extern unsigned int func_0038C8B0(void *, const void *, int);
extern unsigned int func_0038CA10(void *, void *, int);

// FUNCTION: GAME 0x38B030
int func_0038B030(void *fp) { return _IO_un_link(fp); }

// FUNCTION: GAME 0x38B050
int func_0038B050(void *fp) { return _IO_link_in(fp); }

// FUNCTION: GAME 0x38B108
unsigned long func_0038B108(void *f, const void *d, ssize n) { return func_0038C8B0(f, d, n); }

// FUNCTION: GAME 0x38B138
unsigned long func_0038B138(void *f, void *d, ssize n) { return func_0038CA10(f, d, n); }

// FUNCTION: GAME 0x38BA38
unsigned long func_0038BA38(void *f, void *d, ssize n) { return _IO_sgetn(f, d, n); }

// FUNCTION: GAME 0x38F0F0
unsigned long func_0038F0F0(void *f, const void *d, ssize n) { return _IO_file_xsputn(f, d, n); }

extern int func_0038F3D8(void *);
extern int func_003A6420(int);
extern void func_003A5F68(int);
extern int func_00393878(void *);

// FUNCTION: GAME 0x38EF80
int func_0038EF80(void *fp) { return func_0038F3D8(fp); }

// FUNCTION: GAME 0x393720
int func_00393720(int *o) { return func_003A6420(o[22]); }

// FUNCTION: GAME 0x393740
void func_00393740(int *o)
{
    func_003A5F68(o[22]);
    o[22] = 0;
}

// FUNCTION: GAME 0x3938E0
int func_003938E0(char *o) { return func_00393878(o + 8); }

// FUNCTION: GAME 0x393BF8
int func_00393BF8(char *o) { return func_00393878(o + 8); }

// FUNCTION: GAME 0x393900
int func_00393900(int *o) { return ((o[2] >> 1) ^ 1) & 1; }

// FUNCTION: GAME 0x393C18
int func_00393C18(int *o) { return ((o[2] >> 1) ^ 1) & 1; }

// FUNCTION: GAME 0x393F10
int func_00393F10(int *o) { return ((o[0] >> 1) ^ 1) & 1; }
