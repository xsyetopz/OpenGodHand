extern char g_DataManager[];
extern char D_0057F060[];
extern "C" void func_001FE6B8(char *, char *, int);

// FUNCTION: GAME 0x1F7B58
extern "C" void func_001F7B58()
{
}

// FUNCTION: GAME 0x1F7D18
extern "C" void func_001F7D18()
{
}

// FUNCTION: GAME 0x1FF780
extern "C" void func_001FF780(int a, int b)
{
    if (b == 0xFFFF && a) {
        int n = 0x4F;
        do {
            n--;
        } while (n != -1);
        func_001FE6B8(g_DataManager, D_0057F060, 0x50);
    }
}

#ifdef NONMATCHING
// DRAFT: GAME 0x2812A8
// 27 differing words: gcc emits a binary-tree compare, original is linear 1,0,2,3 chain; tried if-chains, shared-tail switch, nested ifs.
extern "C" void func_002812A8(char *p, int k, unsigned char c)
{
    switch (k) {
    case 1:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F6] = 2;
        p[0x2F4] = 0;
        break;
    case 2:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F6] = 4;
        p[0x2F4] = 0;
        break;
    case 3:
        p[0x2F7] = c;
        p[0x2F5] = k;
        p[0x2F6] = 6;
        p[0x2F4] = 0;
        break;
    default:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F4] = 0;
        p[0x2F6] = 0;
        break;
    }
}

// DRAFT: GAME 0x2831C8
// Same as 0x2812A8 (identical asm); 27 differing words.
extern "C" void func_002831C8(char *p, int k, unsigned char c)
{
    switch (k) {
    case 1:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F6] = 2;
        p[0x2F4] = 0;
        break;
    case 2:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F6] = 4;
        p[0x2F4] = 0;
        break;
    case 3:
        p[0x2F7] = c;
        p[0x2F5] = k;
        p[0x2F6] = 6;
        p[0x2F4] = 0;
        break;
    default:
        p[0x2F7] = c;
        p[0x2F5] = 3;
        p[0x2F4] = 0;
        p[0x2F6] = 0;
        break;
    }
}
#endif
