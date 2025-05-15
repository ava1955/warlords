#include "unit.h"
#ifndef SPEARMASTER_H
#define SPEARMASTER_H
class spearmaster:public unit {
public:
    spearmaster();
    spearmaster(int x, int y);
    spearmaster(spearmaster*& a, int x);
    ~spearmaster() override;
    spearmaster& operator=(const spearmaster& a);
};
#endif
