#ifndef CVEC_H
#define CVEC_H

class cVec {
public:
    cVec &operator=(const cVec &o)
    {
        if (this != &o) {
            x = o.x;
            y = o.y;
            z = o.z;
        }
        return *this;
    }

    float x, y, z;
};

#endif
