// GetStatus switch (jump table jtbl_0044B270); alone in its file.

struct cMovie {
    int GetStatus(unsigned);
};
extern "C" int func_002B4F98(cMovie *);
extern "C" int func_002D4210(int);

// FUNCTION: GAME 0x2B4EC8
int cMovie::GetStatus(unsigned)
{
    int v = func_002B4F98(this);
    if (v) {
        switch (func_002D4210(v)) {
        case 1: return 1;
        case 2: return 2;
        case 0: case 3: case 4: case 5: return 3;
        }
    }
    return 0;
}
