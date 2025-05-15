#include "pikeman.h"
    pikeman::pikeman()=default;
    pikeman::pikeman(int x, int y):unit(x, y) {
        min_dmg=1;
        max_dmg=3;
        mv_speed=2;
        max_speed=2;
        hp=9;
        range=2;
        cd=1;
        name='P';
    }
    pikeman::pikeman(pikeman*& a, int x) {
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
    pikeman::~pikeman() {}
    pikeman& pikeman::operator=(const pikeman& a) {
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
    int pikeman::damage(unit* e_unit) {
        srand(time(0)+index);
        int rnd = rand() % (max_dmg-min_dmg+1);
        rnd+=min_dmg;
        index++;
        if (index==1000) index=0;
        if(dynamic_cast<archer*>(e_unit)) return rnd+rnd*3/10;
        if(dynamic_cast<halberdier*>(e_unit)) return rnd+rnd*3/10;
        return rnd;
    }
    int pikeman::collision(vector <unit*> v, char player) {
        if (player=='R') {
            for (int i=0; i<v.size(); i++) {
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
            for (int i=0; i<v.size(); i++) {
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