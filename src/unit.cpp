#include "unit.h"
    unit::unit()=default;
    unit::unit(int x, int y) {
    unit::x=x;
    unit::y=y;
}
    [[nodiscard]] int unit::getX() const {
        return x;
    }
    [[nodiscard]] int unit::getY() const {
        return y;
    }
    void unit::setX(int i) {
        this->x=i;
    }
    unit& unit::operator-=(int damage) {
        hp -= damage;
        return *this;
    }
    [[nodiscard]] int unit::getHP() const {
        return this->hp;
    }
    void unit::setspeed(int newspeed) {
        this->mv_speed=newspeed;
    }
    int unit::collision(vector <unit*> v, char player) {
        if (player=='R') {
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()+2<=this->y-this->mv_speed && v[i]->getY()+1>this->y && v[i]->getX()==this->x) {
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
                if (v[i]->getY()-2<=this->y+this->mv_speed && v[i]->getY()-1>this->y && v[i]->getX()==this->x) {
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
    void unit::movement(game &G, int x, int y, char race, char player, vector <unit*> &v, int i) {
        if (player=='R') {
            if (v[i]->getY()<mv_speed){
                G.setscore(-1);
                delete v[i];
                v[i]=nullptr;
                v.erase(v.begin() + i);
                G.setfield(x, y, '_', race);
                return;
            }
        }
        else {
            if (v[i]->getY()>17-mv_speed){
                G.setscore(1);
                delete v[i];
                v[i]=nullptr;
                v.erase(v.begin() + i);
                G.setfield(x, y, '_', race);
                return;
            }
        }
        if (player=='L') {
            if (this->y==0) G.setfield(x, y+1, name, race);
            else G.setfield(x, y+mv_speed, name, race);
            G.setfield(x, y, '_', race);
            if (this->y==0) this->y=1;
            else this->y=y+mv_speed;
        }
        else if (player=='R') {
            if (this->y==17) G.setfield(x, y-1, name, race);
            else G.setfield(x, y-mv_speed, name, race);
            G.setfield(x, y, '_', race);
            if (this->y==17) this->y=16;
            else this->y = y-mv_speed;
        }
    }
    [[nodiscard]] int unit::attack(vector <unit*> const& v, char player) const {
        if (player=='R') {
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()<=this->y-1 && v[i]->getY()>=this->y-range && v[i]->getX()==this->x) {
                    return i;
                }
            }
        }
        else {
            for (int i=0; i<static_cast<int>(v.size()); i++) {
                if (v[i]->getY()>=this->y+1 && v[i]->getY()<=this->y+range && v[i]->getX()==this->x) {
                    return i;
                }
            }
        }
        return -1;
    }
    int unit::damage(unit*){
        srand(time(nullptr)+index);
        int rnd = rand() % (max_dmg-min_dmg+1);
        rnd+=min_dmg;
        index++;
        if (index==1000) index=0;
        return rnd;
    }
    bool operator<=(const unit& u, int value) {
        return u.hp <= value;
    }
unit:: ~unit() = default;
