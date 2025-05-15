#include "battle_axeman.h"
    battle_axeman::battle_axeman()=default;
    battle_axeman::battle_axeman(int x, int y):unit(x, y) {
        min_dmg=5;
        max_dmg=7;
        mv_speed=1;
        max_speed=1;
        hp=30;
        cd=7;
        range=2;
        name='B';
    }
    battle_axeman::battle_axeman(battle_axeman*& a, int x) {
        min_dmg=(*a).min_dmg;
        max_dmg=(*a).max_dmg;
        mv_speed=(*a).mv_speed;
        max_speed=(*a).max_speed;
        hp=(*a).hp;
        range=(*a).range;
        cd=(*a).cd;
        unit::x=x;
        y=(*a).y;
        name=(*a).name;
    }
    battle_axeman::~battle_axeman() {}
    battle_axeman& battle_axeman::operator=(const battle_axeman& a) {
        if (this != &a) {
            min_dmg = a.min_dmg;
            max_dmg = a.max_dmg;
            mv_speed = a.mv_speed;
            max_speed = a.max_speed;
            hp = a.hp;
            range = a.range;
            cd = a.cd;
            x = a.x;
            y = a.y;
            name = a.name;
        }
        return *this;
    }