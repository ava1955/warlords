#include "kings_guard.h"
    kings_guard::kings_guard()=default;
    kings_guard::kings_guard(int x, int y):unit(x, y){
        min_dmg=7;
        max_dmg=9;
        mv_speed=1;
        max_speed=1;
        hp=35;
        cd=7;
        range=1;
        name='K';
    }
    kings_guard::kings_guard(kings_guard*& a, int x) {
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
        def=a->def;
    }
    kings_guard::~kings_guard() {}
    kings_guard& kings_guard::operator=(const kings_guard& a) {
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
    unit& kings_guard::operator-=(int damage) {
        hp -= damage*(1+def);
        return *this;
    }