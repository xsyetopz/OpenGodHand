extern "C" void setMotCamera__11cCamManagerUc(void *, unsigned char);
extern "C" void setMotion__10cMotCameraUiP6cPartsP4cVecfib(void *, int, void *, void *, float, int, int);
extern "C" void move__7cCamera(void *);
extern char CamManager[];
extern int D_00747A78;

#ifdef NONMATCHING
// DRAFT: GAME 0x2C3F10
// 29 words differ (else-return form): original branches beqz forward to a trailing "return 0" block, ours emits bnez + early "return 0" first; variants: early return, int r, if/else return
extern "C" int func_002C3F10(char *self, int id)
{
    if (id) {
        D_00747A78 |= 0x200000;
        char *cm = CamManager;
        setMotCamera__11cCamManagerUc(cm, 0);
        char *cam = cm + 0x530;
        float z = 0.0f;
        setMotion__10cMotCameraUiP6cPartsP4cVecfib(cam, id, 0, 0, z, 0, 0);
        *(float *)(cam + 0x3A8) = z;
        move__7cCamera(cam);
        self[0x111] = 1;
        return 1;
    } else {
        return 0;
    }
}
#endif
