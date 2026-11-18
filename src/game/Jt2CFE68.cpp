// Formats a name by id; sole switch of 0x2CFE68.
extern "C" int sprintf(char *, const char *, ...);
extern char D_0044D010[], D_0044D018[];
extern int D_003C3100[], D_003C3104, D_003C310C, D_003C3118;

// FUNCTION: GAME 0x2CFE68
extern "C" void func_002CFE68(int, int id, unsigned t, char *dst)
{
    switch (id) {
    case 3:
        sprintf(dst, D_0044D010, D_003C310C, t & 0xFF);
        break;
    case 2:
        sprintf(dst, D_0044D018, D_003C3100[id], t & 0xFFF);
        break;
    case 1: case 7: case 8: case 9: case 10: case 11: case 12: case 13:
    case 16: case 17: case 18: case 19:
        sprintf(dst, D_0044D010, D_003C3104, t & 0xFF);
        break;
    case 6:
        sprintf(dst, D_0044D010, D_003C3118, t & 0xFF);
        break;
    default:
        break;
    }
}
