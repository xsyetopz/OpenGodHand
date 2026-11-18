// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/malloc.c malloc (0x3A7C70).
struct _reent;
extern struct _reent *_impure_ptr;
extern void __malloc_lock(struct _reent *) __asm__("func_003A8048");
extern void __malloc_unlock(struct _reent *) __asm__("func_003A80A8");
extern void *_malloc_r(struct _reent *, unsigned int) __asm__("func_003AC2F8");

// FUNCTION: GAME 0x3A7C70
void *malloc(unsigned int nbytes)
{
    void *result;
    __malloc_lock(_impure_ptr);
    result = _malloc_r(_impure_ptr, nbytes);
    __malloc_unlock(_impure_ptr);
    return result;
}
