#include "unit.h"
#ifndef BATTLE_AXEMAN_H
#define BATTLE_AXEMAN_H
class battle_axeman:public unit {
public:
    battle_axeman();
    battle_axeman(int x, int y);
    battle_axeman(battle_axeman*& a, int x);
    ~battle_axeman() override;
    battle_axeman& operator=(const battle_axeman& a);
};
#endif
