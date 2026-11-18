// Game main task loop; sole switch of 0x2A5998.
struct GameT {
    unsigned char state;
};
struct TaskT {
    int _a;
    void *task;
};
extern GameT Game;
extern TaskT GlobalTask;
extern unsigned D_00747A24;
extern "C" void func_002A5B00(void *);
extern "C" void func_002A6CA8(void *);
extern "C" void func_002A6DA8(void *);
extern "C" void func_002A5B18(void *);
extern "C" void func_002A5BB8(void *);
extern "C" void func_002A5D40(void *);
extern "C" void func_002A5EC0(void *);
extern "C" void gameLoop__5cGame(void *);
extern "C" void func_002A67D0(void *);
extern "C" void sleep__9cTaskWorkUs(void *, unsigned short);
extern "C" void exit__9cTaskWork(void *);

// FUNCTION: GAME 0x2A5998
extern "C" void func_002A5998()
{
    D_00747A24 |= 0x80000000;
    func_002A5B00(&Game);
    if (D_00747A24 & 0x80000000) {
        do {
            func_002A6CA8(&Game);
            func_002A6DA8(&Game);
            switch (Game.state) {
            case 0:
                func_002A5B18(&Game);
                break;
            case 1:
                func_002A5BB8(&Game);
                break;
            case 2:
                func_002A5D40(&Game);
                break;
            case 3:
                func_002A5EC0(&Game);
                break;
            case 4:
                gameLoop__5cGame(&Game);
                break;
            case 5:
                func_002A67D0(&Game);
                break;
            }
            sleep__9cTaskWorkUs(GlobalTask.task, 1);
        } while ((int)D_00747A24 < 0);
    }
    exit__9cTaskWork(GlobalTask.task);
}
