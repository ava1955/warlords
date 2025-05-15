#include "giant_troll.h"
    giant_troll::giant_troll()=default;
    giant_troll::giant_troll(int x, int y):unit(x, y) {
        min_dmg=15;
        max_dmg=20;
        mv_speed=1;
        max_speed=1;
        hp=50;
        cd=15;
        range=1;
        name='T';
    }
    giant_troll::giant_troll(giant_troll*& a, int x) {
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
    giant_troll::~giant_troll() {}
    giant_troll& giant_troll::operator=(const giant_troll& a) {
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