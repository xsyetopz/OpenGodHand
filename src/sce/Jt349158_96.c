// COMPILER: ee-gcc2.96

void func_00348D58();
void func_003490B0();
void func_003491D0();
void func_003466F0();

// FUNCTION: GAME 0x349158
int func_00349158(int *o) {
    switch (o[1]) {
    case 0:
    case 3:
    case 4:
        break;
    case 1:
        func_00348D58(o);
        break;
    case 2:
        func_003490B0(o);
        break;
    default:
        break;
    }
    func_003491D0(o);
    func_003466F0(o);
    return 0;
}
