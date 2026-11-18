extern "C" {
int sprintf(char *, const char *, ...);
unsigned int strlen(const char *);
int isspace(int);
int isdigit(int);
int isalpha(int);
extern _IO_ssize_t _IO_padn(_IO_FILE *, int, _IO_ssize_t);
}
#define _IO_sputn(__fp, __s, __n) _IO_XSPUTN (__fp, __s, __n)
