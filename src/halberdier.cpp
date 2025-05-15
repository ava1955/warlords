#include "halberdier.h"
    halberdier::halberdier()=default;
    halberdier::halberdier(int x, int y):unit(x, y) {
        min_dmg=4;
        max_dmg=6;
        mv_speed=1;
        max_speed=1;
        hp=10;
        cd=2;
        range=2;
        name='H';
    }
    halberdier::halberdier(halberdier*& a, int x) {
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
    halberdier::~halberdier() {}
    halberdier& halberdier::operator=(const halberdier& a) {
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
    int halberdier::damage(unit* e_unit) {
        srand(time(0)+i);
        int rnd = rand() % (max_dmg-min_dmg+1);
        rnd+=min_dmg;
        i++;
        if (i==1000) i=0;
        if(dynamic_cast<cavalry*>(e_unit)) return rnd+rnd*3/10;
        return rnd;
    }