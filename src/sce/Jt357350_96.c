// COMPILER: ee-gcc2.96

long func_0035BA58();
void func_00357468();
int func_003574A8();
int func_003574D8();
int func_00357870();
int func_00357910();
int func_00357980();
void func_0035BB60();

// FUNCTION: GAME 0x357350
void func_00357350(char *p) {
    long s;
    int st = *(int *)(p + 0x48);
    if ((unsigned)(st - 1) < 4 && *(int *)(p + 0x44) != 0) {
        *(volatile int *)(p + 0x44) = 0;
        s = func_0035BA58();
        if ((unsigned)(st - 2) < 3) func_00357468(p);
        st = *(int *)(p + 0x48);
        switch (st) {
        case 1: st = func_003574A8(p); break;
        case 2: st = func_003574D8(p); break;
        case 3: st = func_00357870(p); break;
        case 4: st = func_00357910(p); break;
        case 6: st = func_00357980(p); break;
        case 0:
        case 5:
        default:
            break;
        }
        *(int *)(p + 0x48) = st;
        func_0035BB60(p + 0x3760, func_0035BA58() - s);
    }
}
