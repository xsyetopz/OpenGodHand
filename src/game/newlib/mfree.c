// FLAGS: -Iinclude/newlib -Iinclude/newlib/machine
// newlib 1.9.0 libc/stdlib/malloc.c free (0x3A7CC0).
struct _reent;
extern struct _reent *_impure_ptr;
extern void __malloc_lock(struct _reent *) __asm__("func_003A8048");
extern void __malloc_unlock(struct _reent *) __asm__("func_003A80A8");
extern void _free_r(struct _reent *, void *) __asm__("func_003ACA28");

// FUNCTION: GAME 0x3A7CC0
void free(void *aptr)
{
    __malloc_lock(_impure_ptr);
    _free_r(_impure_ptr, aptr);
    __malloc_unlock(_impure_ptr);
}
