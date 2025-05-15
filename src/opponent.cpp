#include "opponent.h"
    int opponent::j=0;
    opponent::opponent(char race) : player(race) {
        this->race = race;
    }
    int opponent::opponent_row(const vector<int> &w) {
        vector <int> adj;
        int total_weight = 0;
        for (int i : w) {
            if (i >= 7) {
                adj.push_back(round(sqrt(7)));
                total_weight += round(sqrt(7));
            }
            else {
                adj.push_back(round(sqrt(i)));
                total_weight += round(sqrt(i));
            }
        }
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(0, total_weight - 1);
        int rnd = dist(gen);
        int cumul = 0;
        for (int i = 0; i < adj.size(); i++) {
            cumul += adj[i];
            if (rnd < cumul) return ++i;
        }
        return (w.size() - 1);
    }
    char opponent::opponent_unit() {
        string s="PSHACX";
        srand(time(0)+j);
        int rnd = rand() % 6;
        j+=2;
        if (j==1000) j=0;
        return s[rnd];
    }
[[nodiscard]] bool opponent::charge_check() const {
        if(kills!=0 && kills%15==0) return true;
        return false;
    }