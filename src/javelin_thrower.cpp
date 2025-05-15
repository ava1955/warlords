#include "javelin_thrower.h"
    javelin_thrower::javelin_thrower()=default;
    javelin_thrower::javelin_thrower(int x, int y):unit(x, y) {
        min_dmg=5;
        max_dmg=7;
        mv_speed=1;
        max_speed=1;
        hp=20;
        cd=5;
        range=6;
        name='J';
    }
    javelin_thrower::javelin_thrower(javelin_thrower*& a, int x) {
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
    javelin_thrower::~javelin_thrower() {}
    javelin_thrower& javelin_thrower::operator=(const javelin_thrower& a) {
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