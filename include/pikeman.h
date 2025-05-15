#include "unit.h"
#include "archer.h"
#include "halberdier.h"
#ifndef PIKEMAN_H
#define PIKEMAN_H
class pikeman:public unit{
public:
    pikeman();
    pikeman(int x, int y);
    pikeman(pikeman*& a, int x);
    ~pikeman() override;
    int damage(unit* e_unit) override;
    pikeman& operator=(const pikeman& a);
    int collision(vector <unit*> v, char player) override;
};
#endif