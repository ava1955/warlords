#include "unit.h"
#ifndef FLAILER_H
#define FLAILER_H
class flailer:public unit {
public:
    flailer();
    flailer(int x, int y);
    flailer(flailer*& a, int x);
    ~flailer() override;
    flailer& operator=(const flailer& a);
};
#endif
