#include "game/cScenario.h"

#ifdef NONMATCHING
// DRAFT: GAME 0x2C4C58
// 20 words: branch tree matches; base reg a3 vs a0, movz in hex-digit decode; tried if/else, ternary, inline helper
int cScenario::getObjIdFromStr(const char *s)
{
    int base;
    if (s[0] == 'p' && s[1] == 'l') {
        base = 0x100;
    } else if (s[0] == 'e' && s[1] == 'm') {
        base = 0x200;
    } else if (s[0] == 'o' && s[1] == 'm') {
        base = 0x300;
    } else if (s[0] == 'o' && s[1] == 'l') {
        base = 0x400;
    } else if (s[0] == 'e' && s[1] == 'f') {
        base = 0x500;
    } else if (s[0] == 'e' && s[1] == 'l') {
        base = 0x600;
    } else {
        return 0xFFFF;
    }
    int a = s[2] - '0';
    if (s[2] >= 'a') a = s[2] - 'W';
    base += a * 16;
    char c = s[3];
    if (c < 'a') return base - '0' + c;
    return base - 'W' + c;
}
#endif
