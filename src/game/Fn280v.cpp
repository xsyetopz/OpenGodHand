extern char g_EmdManager[];
extern char RoomHeap;
extern "C" int func_0028FE58(void *);
extern "C" int func_0028FED8(void *, int);

// FUNCTION: GAME 0x292AF0
extern "C" int func_00292AF0(void *, int *out)
{
    unsigned i;
    for (i = 0; i < (unsigned)func_0028FE58(g_EmdManager); i++) {
        int id = func_0028FED8(g_EmdManager, i);
        switch (id) {
        case 0x202:
        case 0x208:
        case 0x278:
            if (out) { out[0] = id; out[10] = 0x20F; }
            return 0x20F;
        case 0x207:
        case 0x20D:
        case 0x270:
            if (out) { out[0] = id; out[10] = 0x210; }
            return 0x210;
        case 0x21D:
        case 0x276:
            if (out) { out[0] = id; out[10] = 0x226; }
            return 0x226;
        }
    }
    return 0xFFFF;
}

extern "C" int func_00290958(void *);
extern "C" int func_001FE9B8(void *, int);
extern "C" void loadWait__12cDataManager6eObjIdR5cHeapb(void *, int, void *, int);
extern "C" void func_001FEAA0(void *, int, int, int);
extern "C" char *CreateObj__F6eObjIdT0(int, int);
extern "C" void func_00290048(void *, void *, int);
extern "C" int func_00290988(void *, int);
extern "C" void ReleaseEm__9cEmManageP7cEmBase(void *, void *);
struct N { N *prev; N *next; int d; int id; unsigned char st; };
struct L {
    N *head; N *tail;
    void push(N *n) {
        if (n) {
            if (!tail) {
                head = n;
                n->prev = 0;
                head->next = 0;
                tail = n;
            } else {
                tail->next = n;
                n->prev = tail;
                tail = n;
                n->next = 0;
            }
        }
    }
};
// FUNCTION: GAME 0x2905D0
extern "C" char *EntryEm__9cEmManageP11SET_EM_DATAiP7cEmBase(char *self, int *data, int id, char *em0)
{
    if (data) {
        if (id < -1) return 0;
        int idx = func_00290958(self);
        if (idx != -1) {
            if (func_001FE9B8(g_EmdManager, data[0]) == 0)
                loadWait__12cDataManager6eObjIdR5cHeapb(g_EmdManager, data[0], &RoomHeap, 1);
            func_001FEAA0(g_EmdManager, data[0], data[10], data[11]);
            char *em = CreateObj__F6eObjIdT0(data[0], 0xFFFF);
            if (!em) return 0;
            N *n = (N *)(self + idx * 0x14);
            func_00290048(n, em, id);
            ((L *)(self + 0x500))->push(n);
            (*(int *)(self + 0x508))++;
            if (func_00290988(self, id) == 1) (*(int *)(self + 0x50C))++;
            *(unsigned short *)(em + 0x640) = *((unsigned char *)data + 0x31);
            char *vt = *(char **)(em + 0x214);
            if (((int (*)(char *, int *, char *))*(int *)(vt + 0x9C))(em + *(short *)(vt + 0x98), data, em0))
                return em;
            ReleaseEm__9cEmManageP7cEmBase(self, em);
        }
    }
    return 0;
}
