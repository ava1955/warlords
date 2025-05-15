#include "swordsman.h"
    swordsman::swordsman():unit(){}
    swordsman::swordsman(int x, int y):unit(x, y) {
        min_dmg=3;
        max_dmg=4;
        mv_speed=1;
        max_speed=1;
        hp=15;
        range=1;
        cd=2;
        name='S';
    }
    swordsman::swordsman(swordsman*& a, int x) {
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
    swordsman& swordsman::operator=(const swordsman& a) {
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
    swordsman::~swordsman()=default;
int swordsman::damage(unit* e_unit) {
    srand(time(0)+i);
    int rnd = rand() % (max_dmg-min_dmg+1);
    rnd+=min_dmg;
    i++;
    if (i==1000) i=0;
    if(dynamic_cast<archer*>(e_unit)) return rnd+rnd*1/2;
    if(dynamic_cast<pikeman*>(e_unit)) return rnd+rnd*1/2;
    return rnd;
}
unit& swordsman::operator-=(int damage) {
    hp -= damage*(1-def);
    return *this;
}
