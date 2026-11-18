// COMPILER: ee-gcc2.96
// Jump-table unit; this file holds no other .rodata.

void func_0033B688(void);
void func_0033B6B8(void);
int func_003312B0(int);
void func_00331070(int);

// FUNCTION: GAME 0x3340F0
void func_003340F0(int *a) {
    if (a[11] == 0) return;
    func_0033B688();
    switch (func_003312B0(a[11])) {
    case 9:
        ((char *)a)[2] = 3;
        func_00331070(a[11]);
        a[11] = 0;
        break;
    case 3:
        a[10] = a[9];
        a[7] += a[9];
        ((char *)a)[2] = 1;
        func_00331070(a[11]);
        a[11] = 0;
        break;
    case 0:
        ((char *)a)[2] = 0;
        func_00331070(a[11]);
        a[11] = 0;
        break;
    case 1:
    case 2:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        break;
    }
    func_0033B6B8();
}
