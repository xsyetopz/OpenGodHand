// Small free units in 0x2B0000-0x2BFFFF.
class cHeap;
void *_MemoryAlloc(unsigned int size, unsigned int align, cHeap &heap);
extern cHeap *MemDefalutHeapPtr;

extern "C" {
struct PK8 { long v; } __attribute__((packed));
extern PK8 D_00747A78;
extern int Movie;
int func_00394DD8(int, int);
void func_002B5AF8(void *, void *, void *);
void func_002B6420(void *);
void func_002B64C0(void *);
int *func_002BB068(int *, int);

// FUNCTION: GAME 0x2BF800
void func_002BF800(char *a)
{
    D_00747A78 = *(PK8 *)(a + 0x74);
}

// FUNCTION: GAME 0x2BE6A0
int func_002BE6A0(int *self)
{
    return func_00394DD8(*self, 0) == 0;
}

// FUNCTION: GAME 0x2BF540
void func_002BF540(char *p)
{
    if (p[1] == 0) {
        p[3] = 0;
        p[1] = 0;
        p[2] = 0;
        p[0] = 5;
    }
}

#ifdef NONMATCHING
// 2 words differ: original schedules the arg moves (a2=a1, a1=a0) before the lui of Movie
// DRAFT: GAME 0x2B48A0
void func_002B48A0(void *a, void *b)
{
    func_002B5AF8(&Movie, a, b);
}
#endif

// FUNCTION: GAME 0x2B61B0
char *func_002B61B0(char *self)
{
    func_002B6420(self);
    return self + 0xB0;
}

// FUNCTION: GAME 0x2B6328
char *func_002B6328(char *self)
{
    func_002B64C0(self);
    return self + 0x50;
}

// FUNCTION: GAME 0x2BADF8
void *func_002BADF8(int, unsigned size)
{
    return _MemoryAlloc(size, 0x10, *MemDefalutHeapPtr);
}

// FUNCTION: GAME 0x2BB040
void func_002BB040(int *p)
{
    for (unsigned i = 0; i < 4; i++) {
        p[0] = 0;
        p[1] = 0;
        p += 2;
    }
}

// FUNCTION: GAME 0x2BB138
int func_002BB138(int *p, int k)
{
    int *r = func_002BB068(p, k);
    if (r)
        return r[1];
    return 0;
}
}
