#include "unit.h"
#ifndef GIANT_TROLL_H
#define GIANT_TROLL_H
class giant_troll:public unit {
public:
    giant_troll();
    giant_troll(int x, int y);
    giant_troll(giant_troll*& a, int x);
    ~giant_troll() override;
    giant_troll& operator=(const giant_troll& a);
};
#endif
