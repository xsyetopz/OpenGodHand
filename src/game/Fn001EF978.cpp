extern "C" int checkDeadFlag__7cEmBase(void *);
struct Node { void *pad; Node *next; char *em; };
struct EmMan { char pad[0x500]; Node *list; char pad2[0x5B5 - 0x504]; char f5B5; };
extern EmMan g_EmManage;

static inline unsigned char inR(int v, int lo, int hi) { unsigned char r = 0; if (v >= lo) r = v < hi; return r; }
#ifdef NONMATCHING
// DRAFT: GAME 0x1EF978
// 39 words differ: original branches (slti/bnez, daddu 0) for the u8 range flags, ours emits movz and is 16 bytes shorter; tried u8 locals and inline helper
extern "C" void func_001EF978(void) {
    Node *n = g_EmManage.list;
    if (n) {
        char *e = n->em;
        do {
            if (e) {
                int s = *(unsigned short *)(e + 0x2FE);
                if (inR(s, 0x200, 0x300)) {
                    if (!inR(s, 0x2A0, 0x300) && checkDeadFlag__7cEmBase(e) != 1) {
                        char *t = *(char **)(e + 0x214);
                        (*(void (**)(char *))(t + 0xDC))(e + *(short *)(t + 0xD8));
                    }
                }
            }
            n = n->next;
            if (n) e = n->em;
        } while (n);
    }
    g_EmManage.f5B5 = 0;
}
#endif
