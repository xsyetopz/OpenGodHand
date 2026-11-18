#include "game/cModel.h"

extern unsigned int D_00747A80;
extern "C" int func_001F8AD8(void *, void *);

// FUNCTION: GAME 0x14B638
unsigned char cModel::getMeshNum() const
{
    return m_meshNum;
}

// FUNCTION: GAME 0x14E4C8
void cModel::Trans_Extra()
{
}

// FUNCTION: GAME 0x14B470
int cModel::isClip() const
{
    if (D_00747A80 & 0x800000)
        return 1;
    if (m_flags & 2)
        return 1;
    if (m_flags & 0x10000)
        return 0;
    return func_001F8AD8((char *)this + 0x260, (char *)this + 0x80) == 0;
}

// FUNCTION: GAME 0x14B6F8
sModelMesh *cModel::getMeshPtr(int n)
{
    sModelMesh *p = m_meshList;
    while (n--) {
        p = p->m_next;
        if (!p)
            return m_meshList;
    }
    return p;
}

// FUNCTION: GAME 0x14B730
sModelMesh *cModel::getMeshPtr(const char *name)
{
    long key = 0;
    int i = 0;
    if (*name) {
        do {
            key |= (long)*name << (i * 8);
            i++;
            name++;
        } while (i < 8 && *name);
    }
    sModelMesh *m = m_meshList;
    while (m && m->m_info->m_key != key)
        m = m->m_next;
    return m;
}

// FUNCTION: GAME 0x14A338
int cModel::setMeshDisplay(const char *name, bool on)
{
    sModelMesh *m = getMeshPtr(name);
    if (!m)
        return 0;
    if (on)
        m->m_flags &= ~1;
    else
        m->m_flags |= 1;
    return 1;
}

// FUNCTION: GAME 0x14A398
void cModel::setLayerDisplay(int layer, bool on)
{
    for (sModelMesh *m = m_meshList; m; m = m->m_next) {
        if (layer == m->m_layer) {
            if (on)
                m->m_flags &= ~1;
            else
                m->m_flags |= 1;
        }
    }
}
