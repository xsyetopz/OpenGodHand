extern "C" void func_001EF978(void *);
extern "C" int func_001EF8B8(void *);
extern "C" int clearEmDeadFlag__9cRoomSaveUi(void *, unsigned);
extern "C" void setEm__11cEmSetParamUc(void *, unsigned char);
extern "C" void SetVitalMax__7cEmWrapi(void *, int);
extern "C" void SetVital__7cEmWrapi(void *, int);
extern "C" void StartAction__7cEmWrap(void *);
extern char g_RoomSave;
extern char g_EmSet;

// FUNCTION: GAME 0x1F14C8
extern "C" void func_001F14C8(char *self) {
    unsigned char em[16];
    switch (*(int *)(self + 0xB94)) {
    case 0:
        func_001EF978(self);
        *(int *)(self + 0xB94) = *(int *)(self + 0xB94) + 1;
        break;
    case 1:
        if (*(int *)(self + 0xB8C) < *(short *)(self + 0xB6A)) {
            if (func_001EF8B8(self) < 5) {
                int n = *(int *)(self + 0xB90) + 1;
                *(int *)(self + 0xB90) = n;
                if (n >= 12) *(int *)(self + 0xB90) = 0;
                clearEmDeadFlag__9cRoomSaveUi(&g_RoomSave, *(int *)(self + 0xB90));
                em[0] = *(unsigned char *)(self + 0xB90);
                setEm__11cEmSetParamUc(&g_EmSet, em[0]);
                SetVitalMax__7cEmWrapi(em, 0x19);
                SetVital__7cEmWrapi(em, 0x19);
                StartAction__7cEmWrap(em);
                *(int *)(self + 0xB8C) = *(int *)(self + 0xB8C) + 1;
            }
        } else {
            *(int *)(self + 0xB94) = 2;
        }
        break;
    }
}
