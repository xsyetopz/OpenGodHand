#ifndef CMODEL_H
#define CMODEL_H

struct sMeshInfo {
    char _pad0[8];
    long m_key;
};

struct sModelMesh {
    char _pad0[0x380];
    unsigned int m_flags;
    char _pad384[0x404 - 0x384];
    sModelMesh *m_next;
    char _pad408[4];
    unsigned char m_layer;
    char _pad40D[0x414 - 0x40D];
    sMeshInfo *m_info;
};

class cModel {
public:
    unsigned char getMeshNum() const;
    int isClip() const;
    sModelMesh *getMeshPtr(int n);
    sModelMesh *getMeshPtr(const char *name);
    int setMeshDisplay(const char *name, bool on);
    void setLayerDisplay(int layer, bool on);
    void Trans_Extra();

    char _pad0[0x250];
    unsigned int m_flags;
    char _pad254[0x25C - 0x254];
    sModelMesh *m_meshList;
    char _pad260[0x2B1 - 0x260];
    unsigned char m_meshNum;
};

#endif
