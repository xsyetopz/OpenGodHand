// Jump-table switch unit (own file: its .rodata must be exactly the table).
struct Jc { int *m_0; };
struct CsW { char _p[0x14]; unsigned m_14; };
extern CsW *CoreSave;
extern int g_CasinoWork;
extern "C" int getGameDifficulty__9cCoreSave();
extern "C" int getGameLevel__9cCoreSave(Jc *);
extern "C" void setGameLevel__9cCoreSavei(Jc *, int);

// FUNCTION: GAME 0x1FA1A0
extern "C" void func_001FA1A0(Jc *self)
{
    if (self->m_0 == 0)
        return;
    if (getGameDifficulty__9cCoreSave() == 2)
        return;
    if (CoreSave->m_14 & 0x4000000) {
        long t = (unsigned)g_CasinoWork;
        t >>= 1;
        if ((t & 1) == 0)
            return;
    }
    switch (getGameLevel__9cCoreSave(self)) {
    case 1:
    default:
        *(short *)((char *)self->m_0 + 0x1C) = 0;
        break;
    case 2:
        setGameLevel__9cCoreSavei(self, 1);
        break;
    case 3:
    case 4:
        setGameLevel__9cCoreSavei(self, 2);
        break;
    case 5:
        setGameLevel__9cCoreSavei(self, 3);
        break;
    }
}
