#define O_RDONLY 0
#define O_WRONLY 1
#define O_RDWR 2
#define O_APPEND 0x8
#define O_CREAT 0x200
#define O_TRUNC 0x400
#define O_EXCL 0x800
#ifdef __cplusplus
extern "C" {
#endif
int open(const char*,int,...);
#ifdef __cplusplus
}
#endif
