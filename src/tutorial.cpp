#include "tutorial.h"
namespace tutor {
    char init;
    peiculesque Steve;
    int tutorial(){
        system(CLEAR);
        Steve.getpeiculesque();
        game Tutorial;
        Tutorial.setbar('H', 'E', 0);
        cout<<Tutorial;
        cout<<"This is a turn-based strategy game that involves soldiers (of different types)\n";
        cout<<"battling each other on a battlefield. The goal is to make it so as many of your\n";
        cout<<"own units pass into the enemy side. The game is won if you manage to skew the bar\n";
        cout<<"in your favour completely (the entire bar is 1 colour) or if it remains skewed in\n";
        cout<<"your favour once 150 turns have passed.\n";
        cout<<"Enter C to continue\n";
        cin>>init;
        if (init=='C' || init=='c') {
            system(CLEAR);
            Steve.getpeiculesque();
            cout<<Tutorial;
            cout<<"For the sake of this tutorial, you will play as the Human Alliance against the Elves.\n";
            cout<<"You may play a plethora of other races in the game proper.\n";
            cout<<"Enter C to continue\n";
            cin>>init;
            if (init=='C' || init=='c') {
                int cool=1;
                system(CLEAR);
                char race='H';
                char e_race='E';
                int x;
                char y;
                vector <unit*> lunits={};
                vector <unit*> runits={};
                vector <int> w={1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
                player P(race);
                opponent O(e_race);
                vector <int> cdP = P.get_cd();
                vector <int> cdO = O.get_cd();
                int row=0;
                char unit='.';
                bool charged=0;
                bool ok=0;
                Tutorial.setbar(race, e_race, 0);
                while (true) {
                    Steve.getpeiculesque();
                    cout<<"   Turns left: "<<Tutorial.getturns()<<endl;
                    cout<<"   "<<BLUE;
                    for (auto i: "PSHACK") {
                        cout<<i<<" ";
                    }
                    cout<<"             "<<MAGENTA;
                    for (auto i: "PSHACW") {
                        cout<<i<<" ";
                    }
                    cout<<endl;
                    cout<<"   "<<BLUE;
                    for (auto i: cdP) {
                        cout<<i<<" ";
                    }
                    cout<<"              "<<MAGENTA;
                    for (auto i: cdO) {
                        cout<<i<<" ";
                    }
                    cout<<endl;
                    cout<<"   ";
                    Tutorial.setbar(race, e_race, Tutorial.getscore());
                    Tutorial.showbar();
                    cout<<endl;
                    cout<<Tutorial;
                    if(abs(Tutorial.getscore())==18 || Tutorial.getturns()<=0){
                        Tutorial.game_end(race, e_race);
                        for (auto i: runits) {
                            delete i;
                            i=nullptr;
                        }
                        runits.clear();
                        for (auto i: lunits) {
                            delete i;
                            i=nullptr;
                        }
                        cout<<"Congratulations! You completed the tutorial! You may play the game now. Eshti reghele, te suny pa myne. Enter C to go back to menu\n";
                        lunits.clear();
                        cin>>init;
                        if (init=='C' || init=='c') return 1;
                        return 0;
                    }
                    cooldown_tutorial:
                    if(P.charge_check() && charged==0){
                        char Q;
                        cout<<RED<<"Enter Q to charge! Use any other key to skip charging"<<RESET<<endl;
                        try {
                            cin>>Q;
                            if(Q=='Q' || Q=='q') {
                                ok=1;
                                goto charged_tutorial;
                            }
                        }
                        catch (...) {
                            cout<<"Charge skipped."<<endl;
                        }
                    }
                    if (cool==1) {
                        cout<<"Cooldowns work by counting the number of turns that have passed since the last unit spawn\n";
                        cout<<"Once the cooldown of a given unit is 0, you can spawn it by first entering the row you'll place\n";
                        cout<<"it on, and then the initial of said unit. Here is what each initial means:\n";
                        cout<<"P - Pikeman, S - Swordsman, H - Halberdier, A - Archer, C - Cavalry, K - King's Guard (Human Alliance),\n";
                        cout<<"W - Whirler (Elves), J - Javelin Thrower (Men of the West), F - Flailer (The Undead), T - Giant Troll (Trolls)\n";
                        cout<<"B - Battle Axeman (Orcs), M - Spearmaster (Demons)\n";
                        cout<<"Also, X is the generic key for spawning special units that are peculiar to each race.\n";
                    }
                    if (cool==2) {
                        cout<<"I believe it's time I describe each unit for you:\n";
                        cout<<"Pikemen are brittle, quick units that can outpoke enemies from a range of 2.\n";
                        cout<<"Swordsmen are tanky and versatile units that form the backbone of any army.\n";
                        cout<<"Halberdiers are high damage, low defence units.\n";
                        cout<<"Archers are glass cannons that can take down enemmies from afar.\n";
                        cout<<"Cavalrymen are high damage, high defence units that trample down any enemy.\n";
                        cout<<"Special units are by far the strongest units in the game and will be very hard to take down.\n";
                        cout<<"Also, when you manage to kill 10 units, you'll be able to charge and send units on all lanes.\n";
                    }
                    cool++;
                    cout<<"Enter '-1' to skip."<<endl;
                    cin>>x;
                    if (x==-1) goto skip_left_tutorial;
                    if (x==0) {
                        cout<<endl<<"Game aborted.";
                        break;
                    }
                    while (x>10) {
                        cout<<"Please enter a valid row.\n";
                        cin>>x;
                    }
                    charged_tutorial:
                    cin>>y;
                    y=toupper(y);
                    while (!strchr("PSHACX", y)) {
                        cout<<"Please enter a valid unit.\n";
                        cin>>y;
                        y=toupper(y);
                    }
                    if (y=='P') {
                        if (cdP[0]!=0) {
                            cout<<"Cooldown in effect"<<endl;
                            goto cooldown_tutorial;
                        }
                        if (ok==1) {
                            charged=1;
                            pikeman *lunit=new pikeman(1, 0);
                            lunits.push_back(lunit);
                            for (int i=2; i<=10; i++) {
                                pikeman *lunit1= new pikeman(lunit, i);
                                lunits.push_back(lunit1);
                                w[i-1]++;
                            }
                            for (int i=0;i<cdP.size();i++) {
                                cdP[i]=1+P.get_cd()[i];
                            }
                            ok=0;
                            goto skip_left_tutorial;
                        }
                        pikeman *lunit = new pikeman(x, 0);
                        lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (y=='S') {
                        if (cdP[1]!=0) {
                            cout<<"Cooldown in effect"<<endl;
                            goto cooldown_tutorial;
                        }
                        if (ok==1) {
                            charged=1;
                            swordsman *lunit=new swordsman(1, 0);
                            lunits.push_back(lunit);
                            for (int i=2; i<=10; i++) {
                                swordsman *lunit1= new swordsman(lunit, i);
                                lunits.push_back(lunit1);
                                w[i-1]++;
                            }
                            for (int i=0;i<cdP.size();i++) {
                                cdP[i]=1+P.get_cd()[i];
                            }
                            ok=0;
                            goto skip_left_tutorial;
                        }
                        swordsman *lunit = new swordsman(x, 0);
                        lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (y=='H') {
                        if (cdP[2]!=0) {
                            cout<<"Cooldown in effect";
                            goto cooldown_tutorial;
                        }
                        if (ok==1) {
                            charged=1;
                            halberdier *lunit=new halberdier(1, 0);
                            lunits.push_back(lunit);
                            for (int i=2; i<=10; i++) {
                                halberdier *lunit1=new halberdier(lunit, i);
                                lunits.push_back(lunit1);
                                w[i-1]++;
                            }
                            for (int i=0;i<cdP.size();i++) {
                                cdP[i]=1+P.get_cd()[i];
                            }
                            ok=0;
                            goto skip_left_tutorial;
                        }
                        halberdier *lunit = new halberdier(x, 0);
                        lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (y=='A') {
                        if (cdP[3]!=0) {
                            cout<<"Cooldown in effect";
                            goto cooldown_tutorial;
                        }
                        if (ok==1) {
                            charged=1;
                            archer *lunit=new archer(1, 0);
                            lunits.push_back(lunit);
                            for (int i=2; i<=10; i++) {
                                archer *lunit1=new archer(lunit, i);
                                lunits.push_back(lunit1);
                                w[i-1]++;
                            }
                            for (int i=0;i<cdP.size();i++) {
                                cdP[i]=1+P.get_cd()[i];
                            }
                            ok=0;
                            goto skip_left_tutorial;
                        }
                        archer *lunit = new archer(x, 0);
                        lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (y=='C') {
                        if (cdP[4]!=0) {
                            cout<<"Cooldown in effect";
                            goto cooldown_tutorial;
                        }
                        if (ok==1) {
                            charged=1;
                            cavalry *lunit=new cavalry(1, 0);
                            lunits.push_back(lunit);
                            for (int i=2; i<=10; i++) {
                                cavalry *lunit1=new cavalry(lunit, i);
                                lunits.push_back(lunit1);
                                w[i-1]++;
                            }
                            for (int i=0;i<cdP.size();i++) {
                                cdP[i]=1+P.get_cd()[i];
                            }
                            ok=0;
                            goto skip_left_tutorial;
                        }
                        cavalry *lunit = new cavalry(x, 0);
                        lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (y=='X') {
                        if (cdP[5]!=0) {
                            cout<<"Cooldown in effect";
                            goto cooldown_tutorial;
                        }
                            if (ok==1) {
                                charged=1;
                                kings_guard *lunit= new kings_guard(1, 0);
                                lunits.push_back(lunit);
                                for (int i=2; i<=10; i++) {
                                    kings_guard *lunit1=new kings_guard(lunit, i);
                                    lunits.push_back(lunit1);
                                    w[i-1]++;
                                }
                                for (int i=0;i<cdP.size();i++) {
                                    cdP[i]=1+P.get_cd()[i];
                                }
                                ok=0;
                                goto skip_left_tutorial;
                            }
                            kings_guard *lunit = new kings_guard(x, 0);
                            lunits.push_back(lunit);
                        for (int i=0;i<cdP.size();i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                    }
                    if (charged==0) {
                        w[x-1]++;
                        Tutorial.setfield(x, 0, y, race);
                    }
                    cout<<endl;
                    skip_left_tutorial:
                    for (int i=0;i<lunits.size();i++) {
                        int _x=(*lunits[i]).getX();
                        int _y=(*lunits[i]).getY();
                        if (auto poz=(*lunits[i]).attack(runits, 'L'); poz>=0) {
                            *runits[poz]-=lunits[i]->damage(runits[poz]);
                            if (*runits[poz]<=0) {
                                Tutorial.setfield(runits[poz]->getX(), runits[poz]->getY(), '_', 'R');
                                delete runits[poz];
                                runits[poz]=nullptr;
                                runits.erase(runits.begin()+poz);
                                P.kill_counter();
                            }
                        }
                        if (auto poz=lunits[i]->collision(runits, 'L'); poz>=0) {
                            continue;
                        }
                        lunits[i]->movement(Tutorial, _x, _y, race, 'L', lunits, i);
                    }
                    if (unit=='.') unit=O.opponent_unit();
                    if (cdO[string("PSHACX").rfind(unit)]) goto skip_right_tutorial;
                    row=O.opponent_row(w);
                    if (unit=='P') {
                        pikeman *runit = new pikeman(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    if (unit=='S') {
                        swordsman *runit = new swordsman(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    if (unit=='H') {
                        halberdier *runit = new halberdier(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    if (unit=='A') {
                        archer *runit = new archer(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    if (unit=='C') {
                        cavalry *runit = new cavalry(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    if (unit=='X') {
                        whirler *runit = new whirler(row, 17);
                        runits.push_back(runit);
                        for (int i=0;i<cdO.size();i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        unit='.';
                    }
                    skip_right_tutorial:
                    for (int i=0;i<runits.size();i++) {
                        int _x=runits[i]->getX();
                        int _y=runits[i]->getY();
                        if (auto poz=runits[i]->attack(lunits, 'R'); poz>=0) {
                            *lunits[poz]-=runits[i]->damage(lunits[poz]);
                            if (*lunits[poz]<=0) {
                                Tutorial.setfield(lunits[poz]->getX(), lunits[poz]->getY(), '_', 'L');
                                delete lunits[poz];
                                lunits[poz]=nullptr;
                                lunits.erase(lunits.begin() + poz);
                                O.kill_counter();
                            }
                        }
                        if (auto poz=runits[i]->collision(lunits, 'R'); poz>=0) {
                            continue;
                        }
                        runits[i]->movement(Tutorial, _x, _y, e_race, 'R', runits, i);
                    }
                    for (int i=0; i<cdP.size(); i++) {
                        if (cdP[i]!=0){
                            cdP[i]--;
                        }
                        if (cdO[i]!=0){
                            cdO[i]--;
                        }
                    }
                    Tutorial.setturns();
                    system(CLEAR);
                }
            }
            system(CLEAR);
            Steve.getpeiculesque();
            cout<<Tutorial;
        }
    }
}