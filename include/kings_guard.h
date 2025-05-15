#include "unit.h"
#ifndef KINGS_GUARD_H
#define KINGS_GUARD_H
class kings_guard:public unit {
    int def=1/5;
public:
    kings_guard();
    kings_guard(int x, int y);
    kings_guard(kings_guard*& a, int x);
    ~kings_guard() override;
    kings_guard& operator=(const kings_guard& a);
    unit& operator-=(int damage) override;
};
#endif
