#include "flailer.h"
    flailer::flailer()=default;
    flailer::flailer(int x, int y):unit(x, y) {
        min_dmg=9;
        max_dmg=13;
        mv_speed=1;
        max_speed=1;
        hp=25;
        cd=7;
        range=2;
        name='F';
    }
    flailer::flailer(flailer*& a, int x) {
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
    flailer::~flailer() {}
    flailer& flailer::operator=(const flailer& a) {
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