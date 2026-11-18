#include "game/cTaskWork.h"

extern "C" int SignalSema(int);
extern "C" int TerminateThread(int);
extern "C" int DeleteThread(int);
extern "C" void func_003AFBC0();
extern "C" int func_003AFB30(int, int);
extern "C" void func_003AFAE0();

// FUNCTION: GAME 0x2D5AA0
void cTaskWork::sleep(unsigned short n)
{
    m_sleep = n;
    m_active = 1;
    SignalSema(m_owner->m_sema);
    func_003AFBC0();
}

// FUNCTION: GAME 0x2D59F0
void cTaskWork::kill()
{
    if (m_active) {
        m_active = 0;
        if (m_thread != -1) {
            TerminateThread(m_thread);
            DeleteThread(m_thread);
            m_thread = -1;
        }
    }
}

// FUNCTION: GAME 0x2D5A48
void cTaskWork::exit()
{
    m_active = 0;
    int t = m_thread;
    if (t != -1) {
        func_003AFB30(t, 1);
        SignalSema(m_owner->m_sema);
        m_thread = -1;
        func_003AFAE0();
    }
}
