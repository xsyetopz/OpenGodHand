extern "C" {
int sprintf(char *, const char *, ...);
unsigned int strlen(const char *);
int isspace(int);
int isdigit(int);
int isalpha(int);
extern int fflush(void *); extern void *stdout, *stderr;
extern _IO_ssize_t _IO_padn(_IO_FILE *, int, _IO_ssize_t);
}
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)
#define _IO_seek_set 0
#define _IO_seek_cur 1
#define UINT_MAX 0xffffffffU
