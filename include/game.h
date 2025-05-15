#include "auxiliary.h"
#ifndef GAME_H
#define GAME_H
    class game{
    vector <vector <string> > field={
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"},
        {"_", "_",  "_", "_",  "_", "_",  "_", "_",  "_", "_", "_",  "_", "_",  "_", "_",  "_", "_",  "_"}
    };
    string bar;
    int score=0;
    int turns=150;
public:
    void setturns();
     [[nodiscard]] int getturns() const;
     [[nodiscard]] int getscore() const;
    void setscore(int delta);
    void showbar() const;
    void setbar(char race, char e_race, int score);
    void setfield(int x, int y, char Y, char race) ;
    void show() const;
    void game_end(char race, char e_race) const;
        friend ostream & operator << (ostream &out, const game &G);
};
#endif