#include "cavalry.h"
    cavalry::cavalry()=default;
    cavalry::cavalry(int x, int y):unit(x, y) {
        min_dmg=5;
        max_dmg=7;
        mv_speed=3;
        max_speed=3;
        hp=18;
        cd=4;
        range=1;
        name='C';
    }
    cavalry::cavalry(cavalry*& a, int x) {
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
    cavalry::~cavalry() {}
    cavalry& cavalry::operator=(const cavalry& a) {
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
            def=a.def;
        }
        return *this;
    }
    int cavalry::collision(vector <unit*> v, char player) {
        if (player=='R') {
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()+2<=this->y-this->mv_speed-2 && v[i]->getY()+1>this->y && v[i]->getX()==this->x) {
                    this->setspeed(1);
                    v[i]->setspeed(1);
                    return -1;
                }
                if (v[i]->getY()+1==this->y && v[i]->getX()==this->x) {
                    return i;
                }
            }
        }
        else {
            for (int i=0; i<v.size(); i++) {
                if (v[i]->getY()-2<=this->y+this->mv_speed+2 && v[i]->getY()-1>this->y && v[i]->getX()==this->x) {
                    this->setspeed(1);
                    v[i]->setspeed(1);
                    return -1;
                }
                if (v[i]->getY()-1==this->y && v[i]->getX()==this->x) {
                    return i;
                }
            }
        }
        this->setspeed(this->max_speed);
        return -1;
    }
    unit& cavalry::operator-=(int damage) {
        hp -= damage*(1-def);
        return *this;
    }