#include "whirler.h"
    whirler::whirler()=default;
    whirler::whirler(int x, int y) {
        min_dmg=11;
        max_dmg=14;
        mv_speed=2;
        max_speed=2;
        hp=17;
        cd=7;
        range=2;
        unit::x=x;
        unit::y=y;
        name='W';
    }
    whirler::whirler(whirler*& a, int x) {
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
    whirler::~whirler()=default;
    whirler& whirler::operator=(const whirler& a) {
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

int whirler::collision(vector <unit*> v, char player) {
        if (player=='R') {
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()+2<=this->y-this->mv_speed-1 && v[i]->getY()+1>this->y && v[i]->getX()==this->x) {
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
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()-2<=this->y+this->mv_speed+1 && v[i]->getY()-1>this->y && v[i]->getX()==this->x) {
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
