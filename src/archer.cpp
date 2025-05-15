#include "archer.h"
    archer::archer()=default;
    archer::archer(int x, int y):unit(x, y) {
        min_dmg=1;
        max_dmg=3;
        mv_speed=1;
        max_speed=1;
        hp=6;
        cd=2;
        range=8;
        name='A';
    }
    archer::archer(archer*& a, int x) {
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
    archer::~archer() {}
    archer& archer::operator=(const archer& a) {
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
    int archer::damage(unit* e_unit) {
        srand(time(0)+i);
        int rnd = rand() % (max_dmg-min_dmg+1);
        rnd+=min_dmg;
        i++;
        if (i==1000) i=0;
        if(dynamic_cast<halberdier*>(e_unit)) return rnd+rnd*3/10;
        if(dynamic_cast<giant_troll*>(e_unit)) return rnd+rnd*3/10;
        return rnd;
    }