// ProDG-built libc-adjacent game code in 0x393FD8-0x394F20 and 0x3A53A8-0x3AF7B8.
extern "C" void _exit(int);
extern "C" double strtod(const char *, char **);
extern "C" void func_00394088(void *, void *, int);
extern "C" void func_003A6020(void);
extern "C" void func_003A6830(void *, void (*)(void));
extern "C" void func_003A6290(void *);
extern "C" int func_003ADF50(void *, int);
extern "C" int func_003B0388(int);
extern int D_0077DB88;
extern "C" void func_003A61F0(void *);
extern void *_impure_ptr;
extern char D_0045FB80;
extern unsigned char D_0045F039[];

// FUNCTION: GAME 0x394328
extern "C" void func_00394328(void *a, void *b)
{
    func_00394088(a, b, 0);
}

struct Fp {
    char _pad[0xE];
    short m_e;
    char _pad2[0x54 - 0x10];
    void *m_54;
};

// Round 23.
struct Pr {
    char _pad[0x10];
    int m_10;
    int m_14;
};

extern "C" long strtol(const char *, char **, int);
extern "C" void func_003A9498(char *, const char *, void *);
extern "C" double func_003A80E8(void *, const char *, char **);
extern "C" long func_003ACE90(void *, const char *, char **, int);
extern "C" long func_003A9018(void *, const char *, char **, int);
extern "C" void func_003AB188(void *, void *, int, int);
extern "C" Pr *_Balloc(void *, int);

struct FreeList {
    char _pad[0x4C];
    int **m_tab;
};
struct FreeNode {
    int *m_next;
    int m_idx;
};

// Round 24.
extern "C" void func_003A8048(void *);
extern "C" void func_003A80A8(void *);
extern "C" int GetThreadId(void);
extern "C" int WaitSema(int);
extern "C" int SignalSema(int);
extern "C" int func_003A6AA8(void *);
extern "C" void func_003A61F0(void *);
extern "C" int func_003B0388(int);
extern int D_003FA990;
extern int D_003FA994;
extern int D_003FAF18;
extern int D_0077DB88;

struct Fio {
    unsigned char *m_ptr;
    int m_cnt;
};

struct Rn {
    char _pad[0x38];
    int m_38;
};

struct Fq {
    char _pad[0xE];
    short m_e;
    char _pad2[0x54 - 0x10];
    Rn *m_54;
};
