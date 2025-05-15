#include "unit.h"
#include "cavalry.h"
#ifndef HALBERDIER_H
#define HALBERDIER_H
class halberdier:public unit {
public:
    halberdier();
    halberdier(int x, int y);
    halberdier(halberdier*& a, int x);
    ~halberdier() override;
    halberdier& operator=(const halberdier& a);
    int damage(unit* e_unit) override;
};
#endif