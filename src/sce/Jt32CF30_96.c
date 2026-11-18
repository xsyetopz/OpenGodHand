// COMPILER: ee-gcc2.96

int func_00329F98(void);
int func_00328098(int);
void func_00326800(int);

// FUNCTION: GAME 0x32CF30
void func_0032CF30(int *a) {
    if (a[2] == 0) return;
    if (func_00329F98() == 0) return;
    switch ((unsigned)((char *)a)[2]) {
    case 0:
    case 1:
        if (func_00328098(a[2]) == 3) func_00326800(a[1]);
        break;
    case 2:
        func_00326800(a[1]);
        break;
    case 3:
    case 4:
        break;
    }
}
