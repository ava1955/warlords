#include "unit.h"
#ifndef WHIRLER_H
#define WHIRLER_H
class whirler:public unit {
public:
    whirler();
    whirler(int x, int y);
    whirler(whirler*& a, int x);
    ~whirler() override;
    whirler& operator=(const whirler& a);
    int collision(vector <unit*> v, char player) override;
};
#endif
