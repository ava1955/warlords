#include "spearmaster.h"
    spearmaster::spearmaster()=default;
    spearmaster::spearmaster(int x, int y):unit(x, y) {
        min_dmg=8;
        max_dmg=12;
        mv_speed=1;
        max_speed=1;
        hp=30;
        cd=7;
        range=2;
        name='M';
    }
    spearmaster::spearmaster(spearmaster*& a, int x) {
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
    spearmaster::~spearmaster()=default;
    spearmaster& spearmaster::operator=(const spearmaster& a) {
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