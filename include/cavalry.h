#include "unit.h"
#ifndef CAVALRY_H
#define CAVALRY_H
class cavalry:public unit {
    int def=1/10;
public:
    cavalry();
    cavalry(int x, int y);
    cavalry(cavalry*& a, int x);
    ~cavalry() override;
    cavalry& operator=(const cavalry& a);
    int collision(vector <unit*> v, char player) override;
    unit& operator-=(int damage) override;
};
#endif