#include "game.h"
#include "player.h"
#ifndef UNIT_H
#define UNIT_H
class unit {
protected:
    int i=0;
    char name='\0';
    int min_dmg=0, max_dmg=0, mv_speed=0, hp=0, range=0, cd=0, x=0, y=0, max_speed=0;
public:
    unit();
    unit(int x, int y);
    [[nodiscard]] int getX() const;
    [[nodiscard]] int getY() const;
    void setX(int i);
    virtual unit& operator-=(int damage);
    [[nodiscard]] int getHP() const;
    friend bool operator<=(const unit& u, int value);
    [[nodiscard]] int getmin() const;
    [[nodiscard]] int getmax() const;
    void setspeed(int newspeed);
    virtual int collision(vector <unit*> v, char player);
    void movement(game &G, int x, int y, char race, char player, vector <unit*> &v, int i);
    [[nodiscard]] int attack(vector <unit*> const& v, char player) const;
    virtual int damage(unit *e_unit);
    virtual ~unit() = 0;
};
#endif
