extern "C" void func_001F4778(void *, int, int);
extern "C" void func_001F5478(void *, int);
extern "C" void func_001F4928(void *, int);
extern "C" void func_001F9C88(void *);
extern "C" void func_001F9ED0(void *);
extern "C" void func_001F9C30(void *);
extern "C" void func_001F9C58(void *);
extern "C" void func_001F9DD0(void *);
extern "C" void func_001F9E28(void *);
extern "C" void func_001F9E90(void *);
extern "C" void func_001FACB0(void *);
extern "C" char *Getplayer__Fv(void);
extern "C" void setVital__9cCoreSavei(void *, int);

// FUNCTION: GAME 0x1F4840
extern "C" void func_001F4840(void *self)
{
    func_001F4778(self, 0x6F, 0);
    func_001F4778(self, 0, 1);
    func_001F4778(self, 1, 1);
    func_001F4778(self, 2, 1);
    func_001F4778(self, 3, 1);
    func_001F4778(self, 4, 1);
    func_001F4778(self, 5, 1);
    func_001F4778(self, 6, 1);
    func_001F4778(self, 7, 1);
    func_001F4778(self, 8, 1);
    func_001F4778(self, 9, 1);
    func_001F5478(self, 1);
    func_001F4928(self, 1);
}

// FUNCTION: GAME 0x1F9B88
extern "C" void func_001F9B88(void *self, int flag)
{
    func_001F9C88(self);
    if (flag) {
        func_001F9ED0(self);
        func_001F9C30(self);
        func_001F9C58(self);
        func_001F9DD0(self);
        func_001F9E28(self);
        func_001F9E90(self);
    }
    func_001FACB0(self);
    if (*(short *)(Getplayer__Fv() + 0x54A) > 0)
        setVital__9cCoreSavei(self, *(short *)(Getplayer__Fv() + 0x54A));
    else
        setVital__9cCoreSavei(self, 1);
}
