#include "unit.h"
#include "pikeman.h"
#include "archer.h"
#ifndef SWORDSMAN_H
#define SWORDSMAN_H
class swordsman:public unit {
    int def=3/20;
public:
    swordsman();
    swordsman(int x, int y);
    swordsman(swordsman*& a, int x);
    ~swordsman() override;
    swordsman& operator=(const swordsman& a);
    int damage(unit* e_unit) override;
    unit& operator-=(int damage) override;
};
#endif