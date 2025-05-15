#include "unit.h"
#include "halberdier.h"
#include "giant_troll.h"
#ifndef ARCHER_H
#define ARCHER_H
class archer:public unit {
public:
    archer();
    archer(int x, int y);
    archer(archer*& a, int x);
    ~archer() override;
    archer& operator=(const archer& a);
    int damage(unit *e_unit) override;
};
#endif
