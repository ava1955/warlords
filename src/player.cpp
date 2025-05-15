#include "player.h"
    player::player()=default;
    player::player(char race) {
    this->race=race;
    }
    istream & operator >> (istream &in,  player &P) {
        in>>P.race;
        return in;
    }
    player::~player(){
        max_cds.clear();
    }
    const vector <int>& player::get_cd() {
        return max_cds;
    }
    void player::set_cd() {
        switch (race) {
            case 'M': max_cds = {1, 2, 2, 2, 4, 5}; break;
            case 'T': max_cds = {1, 2, 2, 2, 4, 15}; break;
        }
    }
    void player::kill_counter(){
        if (kills!=10) kills++;
    }
    [[nodiscard]] bool player::charge_check() const {
        if(kills!=0 && kills%10==0) return true;
        return false;
    }