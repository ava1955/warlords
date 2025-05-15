#include "game.h"
    void game::setturns() {
        turns--;
    }
     [[nodiscard]] int game::getturns() const {
        return turns;
    }
     [[nodiscard]] int game::getscore() const {
        return score;
    }
    void game::setscore(int delta){
        if(abs(score)==18) return;
        score+=delta;
    }
    void game::showbar() const {
        cout<<bar;
    }
    void game::setbar(char race, char e_race, int _score){
        string lcolour, rcolour;
        switch(race){
            case 'H': lcolour=string(BLUE); break;
            case 'E': lcolour=string(MAGENTA); break;
            case 'M': lcolour=string(YELLOW); break;
            case 'U': lcolour=string(WHITE); break;
            case 'D': lcolour=string(RED); break;
            case 'T': lcolour=string(CYAN); break;
            case 'O': lcolour=string(GREEN); break;
        }
        switch(e_race){
            case 'H': rcolour=string(BLUE); break;
            case 'E': rcolour=string(MAGENTA); break;
            case 'M': rcolour=string(YELLOW); break;
            case 'U': rcolour=string(WHITE); break;
            case 'D': rcolour=string(RED); break;
            case 'T': rcolour=string(CYAN); break;
            case 'O': rcolour=string(GREEN); break;
        }
        bar=lcolour;
        for(int i=0;i<18+_score;i++){
            bar+="■";
        }
        bar+=rcolour;
        for(int i=18+_score; i<37; i++){
            bar+="■";
        }
        bar+=string(RESET);
    }
    void game::setfield(int x, int y, char Y, char race) {
        if (race=='E' && Y!='_') field[x-1][y]=MAGENTA+string(1, Y)+RESET;
        else if (race=='H' && Y!='_') field[x-1][y]=BLUE+string(1, Y)+RESET;
        else if (race=='D' && Y!='_') field[x-1][y]=RED+string(1, Y)+RESET;
        else if (race=='M' && Y!='_') field[x-1][y]=YELLOW+string(1, Y)+RESET;
        else if (race=='O' && Y!='_') field[x-1][y]=GREEN+string(1, Y)+RESET;
        else if (race=='U' && Y!='_') field[x-1][y]=WHITE+string(1, Y)+RESET;
        else if (race=='T' && Y!='_') field[x-1][y]=CYAN+string(1, Y)+RESET;
        else field[x-1][y]=RESET+string(1, '_');
    }
    ostream & operator << (ostream &out, const game &G) {
        for (int i = 0; i < static_cast<int>(G.field.size()); i++) {
            if(i==static_cast<int>(G.field.size())-1) out<<i+1<<": ";
            else out<<" "<<i+1<<": ";
            for (int j = 0; j < static_cast<int>(G.field[i].size()); j++) {
                out << G.field[i][j] << " ";
            }
            out << endl;
        }
        return out;
    };
    void game::game_end(char race, char e_race) const {
        if(this->getscore()>0){
            switch(race){
                case 'H': cout<<BLUE<<"The Human Alliance has won!"; break;
                case 'E': cout<<MAGENTA<<"The Elves have won!"; break;
                case 'M': cout<<YELLOW<<"The Men of the West have won!"; break;
                case 'U': cout<<WHITE<<"The Undead have won!"; break;
                case 'D': cout<<RED<<"The Demons have won!"; break;
                case 'T': cout<<CYAN<<"The Trolls have won!"; break;
                case 'O': cout<<GREEN<<"The Orcs have won!"; break;
            }
        }
        if(this->getscore()<0){
            switch(e_race){
                case 'H': cout<<BLUE<<"The Human Alliance has won!"; break;
                case 'E': cout<<MAGENTA<<"The ELves have won!"; break;
                case 'M': cout<<YELLOW<<"The Men of the West have won!"; break;
                case 'U': cout<<WHITE<<"The Undead have won!"; break;
                case 'D': cout<<RED<<"The Demons have won!"; break;
                case 'T': cout<<CYAN<<"The Trolls have won!"; break;
                case 'O': cout<<GREEN<<"The Orcs have won!"; break;
            }
        }
        cout<<RESET<<endl;
        if(this->getscore()==0) cout<<"The battle is a draw.";
    }