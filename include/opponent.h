#include "aux.h"
#include "player.h"
#ifndef OPPONENT_H
#define OPPONENT_H
class opponent:public player {
    static int j;
public:
    opponent(char race);
    [[nodiscard]] bool charge_check() const override;
    int opponent_row(vector<int> &w);
    static char opponent_unit();
};
#endif