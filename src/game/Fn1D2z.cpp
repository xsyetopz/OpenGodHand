extern unsigned long Sys[];
extern char Snd[];
extern char CoreSave[];
extern "C" void func_001D5690(char *, int);
extern "C" void func_001D5B90(char *, int);
extern "C" void func_001D5760(char *, int);
extern "C" void subGold__9cCoreSavei(char *, int);
extern "C" void SeCall__4cSnd6eSeBlksssUii(char *, int, int, int, int, int, int);
// FUNCTION: GAME 0x1D2BB0
extern "C" void func_001D2BB0(char *self)
{
    switch (*(int *)(self + 0x1808)) {
    case 0:
        func_001D5690(self, 0);
        func_001D5B90(self, 1);
        *(int *)(self + 0x1808) += 1;
    case 1: {
        register int st __asm__("$3");
        if (Sys[0x36] & 0x3300003000000UL) {
            func_001D5690(self, 1);
            func_001D5B90(self, 0);
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15F, -1, -1, 0, 0);
            st = 6;
        } else if (Sys[0x34] & 0x10000000UL) {
            subGold__9cCoreSavei(CoreSave, *(int *)(self + 0x1814));
            *(int *)(self + 0x1814) = *(int *)(self + 0x1814) << 1;
            func_001D5760(self, *(int *)(self + 0x1814));
            func_001D5B90(self, 0);
            SeCall__4cSnd6eSeBlksssUii(Snd, 0, 0x15E, -1, -1, 0, 0);
            st = 0xB;
        } else
            break;
        *(int *)(self + 0x1808) = 0;
        __asm__ volatile("" : : : "memory");
        *(int *)(self + 0x1804) = st;
    }
    }
}
