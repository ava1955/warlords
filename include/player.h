#include "aux.h"
#ifndef PLAYER_H
#define PLAYER_H
class player {
protected:
    vector <int> max_cds = {1, 2, 2, 2, 4, 7};
    char race;
    int kills=0;
public:
    player();
    player(char race);
    char getrace();
    friend istream & operator >> (istream &in,  player &P);
    ~player();
    vector <int> get_cd();
    void set_cd();
    void kill_counter();
    [[nodiscard]] virtual bool charge_check() const;
    [[nodiscard]] int getkills() const;
};
#endif