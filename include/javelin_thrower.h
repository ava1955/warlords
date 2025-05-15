#include "unit.h"
#ifndef JAVELIN_THROWER_H
#define JAVELIN_THROWER_H
class javelin_thrower:public unit {
    public:
    javelin_thrower();
    javelin_thrower(int x, int y);
    javelin_thrower(javelin_thrower*& a, int x);
    ~javelin_thrower() override;
    javelin_thrower& operator=(const javelin_thrower& a);
};
#endif
