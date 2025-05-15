#include "gameplay.h"
namespace play{
int gameplay(char race, char e_race) {
        game G;
        int x;
        char y;
        vector <unit*> lunits={};
        vector <unit*> runits={};
        vector <int> w={1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
        system(CLEAR);
        player P(race);
        opponent O(e_race);
        if (race=='T' ||  race=='M') P.set_cd();
        if (e_race=='T' || race=='M') O.set_cd();
        vector <int> cdP = P.get_cd();
        vector <int> cdO = O.get_cd();
        int row=0;
        char unit_O='.';
        bool charged=0;
        bool charged2=0;
        bool ok=0;
        bool ok2=0;
        G.setbar(race, e_race, 0);
        string lcolour=set_colour(race);
        string rcolour=set_colour(e_race);
        while (true) {
            cout<<"   Turns left: "<<G.getturns()<<endl;
            cout<<"   "<<lcolour;
            for (auto i: "PSHACX") {
                if (i=='X') {
                    switch (race) {
                        case 'H': cout<<'K'; break;
                        case 'E': cout<<'W'; break;
                        case 'M': cout<<'J'; break;
                        case 'O': cout<<'B'; break;
                        case 'T': cout<<'T'; break;
                        case 'U': cout<<'F'; break;
                        default: break;
                    }
                }
                else cout<<i<<" ";
            }
            cout<<"              "<<rcolour;
            for (auto i: "PSHACX") {
                if (i=='X') {
                    switch (e_race) {
                        case 'H': cout<<'K'; break;
                        case 'E': cout<<'W'; break;
                        case 'M': cout<<'J'; break;
                        case 'O': cout<<'B'; break;
                        case 'T': cout<<'T'; break;
                        case 'U': cout<<'F'; break;
                        case 'D': cout<<'M'; break;
                        default: break;
                    }
                }
                else cout<<i<<" ";
            }
            cout<<endl;
            cout<<"   "<<lcolour;
            for (auto i: cdP) {
                cout<<i<<" ";
            }
            cout<<"              "<<rcolour;
            for (auto i: cdO) {
                cout<<i<<" ";
            }
            cout<<endl;
            cout<<"   ";
            G.setbar(race, e_race, G.getscore());
            G.showbar();
            cout<<endl;
            cout<<G;
            if(abs(G.getscore())==18 || G.getturns()<=0){
                G.game_end(race, e_race);
                for (auto i: runits) {
                    delete i;
                    i=nullptr;
                }
                runits.clear();
                for (auto i: lunits) {
                    delete i;
                    i=nullptr;
                }
                lunits.clear();
                if (G.getscore()>0) return 1;
                return -1;
            }
            cooldown:
            if(P.charge_check() && charged==0){
                char Q;
                cout<<RED<<"Enter Q to charge! Use any other key to skip charging"<<RESET<<endl;
                try {
                    cin>>Q;
                    if(Q=='Q' || Q=='q') {
                        ok=1;
                        goto charged;
                    }
                }
                catch (...) {
                    cout<<"Charge skipped."<<endl;
                }
            }
            cout<<"Enter '-1' to skip."<<endl;
            cin>>x;
            if (x==-1) goto skip_left;
            if (x==0) {
                cout<<endl<<"Game aborted.";
                break;
            }
            while (x>10) {
                cout<<"Please enter a valid row.\n";
                cin>>x;
            }
            charged:
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
                    goto cooldown;
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
                    for (int i=0;i<static_cast<int>(cdP.size());i++) {
                        cdP[i]=1+P.get_cd()[i];
                    }
                    ok=0;
                    goto skip_left;
                }
                pikeman *lunit = new pikeman(x, 0);
                lunits.push_back(lunit);
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (y=='S') {
                if (cdP[1]!=0) {
                    cout<<"Cooldown in effect"<<endl;
                    goto cooldown;
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
                    for (int i=0;i<static_cast<int>(cdP.size());i++) {
                        cdP[i]=1+P.get_cd()[i];
                    }
                    ok=0;
                    goto skip_left;
                }
                swordsman *lunit = new swordsman(x, 0);
                lunits.push_back(lunit);
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (y=='H') {
                if (cdP[2]!=0) {
                    cout<<"Cooldown in effect";
                    goto cooldown;
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
                    for (int i=0;i<static_cast<int>(cdP.size());i++) {
                        cdP[i]=1+P.get_cd()[i];
                    }
                    ok=0;
                    goto skip_left;
                }
                halberdier *lunit = new halberdier(x, 0);
                lunits.push_back(lunit);
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (y=='A') {
                if (cdP[3]!=0) {
                    cout<<"Cooldown in effect";
                    goto cooldown;
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
                    for (int i=0;i<static_cast<int>(cdP.size());i++) {
                        cdP[i]=1+P.get_cd()[i];
                    }
                    ok=0;
                    goto skip_left;
                }
                archer *lunit = new archer(x, 0);
                lunits.push_back(lunit);
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (y=='C') {
                if (cdP[4]!=0) {
                    cout<<"Cooldown in effect";
                    goto cooldown;
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
                    for (int i=0;i<static_cast<int>(cdP.size());i++) {
                        cdP[i]=1+P.get_cd()[i];
                    }
                    ok=0;
                    goto skip_left;
                }
                cavalry *lunit = new cavalry(x, 0);
                lunits.push_back(lunit);
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (y=='X') {
                if (cdP[5]!=0) {
                    cout<<"Cooldown in effect";
                    goto cooldown;
                }
                if (race=='E') {
                    if (ok==1) {
                        charged=1;
                        whirler *lunit=new whirler(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            whirler *lunit1=new whirler(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    whirler *lunit = new whirler(x, 0);
                    lunits.push_back(lunit);
                }
                if (race=='H') {
                    if (ok==1) {
                        charged=1;
                        kings_guard *lunit= new kings_guard(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            kings_guard *lunit1=new kings_guard(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    kings_guard *lunit = new kings_guard(x, 0);
                    lunits.push_back(lunit);
                }
                if (race=='U') {
                    if (ok==1) {
                        charged=1;
                        flailer *lunit= new flailer(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            flailer *lunit1=new flailer(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    flailer *lunit = new flailer(x, 0);
                    lunits.push_back(lunit);
                }
                if (race=='M') {
                    if (ok==1) {
                        charged=1;
                        javelin_thrower *lunit= new javelin_thrower(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            javelin_thrower *lunit1=new javelin_thrower(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    javelin_thrower *lunit = new javelin_thrower(x, 0);
                    lunits.push_back(lunit);
                }
                if (race=='T') {
                    if (ok==1) {
                        charged=1;
                        giant_troll *lunit= new giant_troll(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            giant_troll *lunit1=new giant_troll(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    giant_troll *lunit = new giant_troll(x, 0);
                    lunits.push_back(lunit);
                }
                if (race=='O') {
                    if (ok==1) {
                        charged=1;
                        battle_axeman *lunit= new battle_axeman(1, 0);
                        lunits.push_back(lunit);
                        for (int i=2; i<=10; i++) {
                            battle_axeman *lunit1=new battle_axeman(lunit, i);
                            lunits.push_back(lunit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdP.size());i++) {
                            cdP[i]=1+P.get_cd()[i];
                        }
                        ok=0;
                        goto skip_left;
                    }
                    battle_axeman *lunit = new battle_axeman(x, 0);
                    lunits.push_back(lunit);
                }
                for (int i=0;i<static_cast<int>(cdP.size());i++) {
                    cdP[i]=1+P.get_cd()[i];
                }
            }
            if (charged==0) {
                w[x-1]++;
                G.setfield(x, 0, y, race);
            }
            cout<<endl;
            skip_left:
            for (int i=0;i<static_cast<int>(lunits.size());i++) {
                int _x=(*lunits[i]).getX();
                int _y=(*lunits[i]).getY();
                if (auto poz=(*lunits[i]).attack(runits, 'L'); poz>=0) {
                    *runits[poz]-=lunits[i]->damage(runits[poz]);
                    if (*runits[poz]<=0) {
                        G.setfield(runits[poz]->getX(), runits[poz]->getY(), '_', 'R');
                        delete runits[poz];
                        runits[poz]=nullptr;
                        runits.erase(runits.begin()+poz);
                        P.kill_counter();
                    }
                }
                if (auto poz=lunits[i]->collision(runits, 'L'); poz>=0) {
                    continue;
                }
                lunits[i]->movement(G, _x, _y, race, 'L', lunits, i);
            }
            if (unit_O=='.') unit_O=O.opponent_unit();
            if (cdO[string("PSHACX").rfind(unit_O)]) goto skip_right;
            row=O.opponent_row(w);
            if(O.charge_check() && charged2==0) ok2=1;
            if (unit_O=='P') {
                if (ok2==1) {
                    charged2=1;
                    pikeman *runit=new pikeman(1, 17);
                    runits.push_back(runit);
                    for (int i=2; i<=10; i++) {
                        pikeman *runit1=new pikeman();
                        *runit1=*runit;
                        runit1->setX(i);
                        runits.push_back(runit1);
                        w[i-1]++;
                    }
                    for (int i=0;i<static_cast<int>(cdO.size());i++) {
                        cdO[i]=1+O.get_cd()[i];
                    }
                    ok2=0;
                    unit_O='.';
                    goto skip_right;
                }
                pikeman *runit = new pikeman(row, 17);
                runits.push_back(runit);
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
                unit_O='.';
            }
            if (unit_O=='S') {
                if (ok2==1) {
                    charged2=1;
                    swordsman *runit=new swordsman(1, 17);
                    runits.push_back(runit);
                    for (int i=2; i<=10; i++) {
                        swordsman *runit1=new swordsman();
                        *runit1=*runit;
                        runit1->setX(i);
                        runits.push_back(runit1);
                        w[i-1]++;
                    }
                    for (int i=0;i<static_cast<int>(cdO.size());i++) {
                        cdO[i]=1+O.get_cd()[i];
                    }
                    ok2=0;
                    unit_O='.';
                    goto skip_right;
                }
                swordsman *runit = new swordsman(row, 17);
                runits.push_back(runit);
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
                unit_O='.';
            }
            if (unit_O=='H') {
                if (ok2==1) {
                    charged2=1;
                    halberdier *runit=new halberdier(1, 17);
                    runits.push_back(runit);
                    for (int i=2; i<=10; i++) {
                        halberdier *runit1=new halberdier();
                        *runit1=*runit;
                        runit1->setX(i);
                        runits.push_back(runit1);
                        w[i-1]++;
                    }
                    for (int i=0;i<static_cast<int>(cdO.size());i++) {
                        cdO[i]=1+O.get_cd()[i];
                    }
                    ok2=0;
                    unit_O='.';
                    goto skip_right;
                }
                halberdier *runit = new halberdier(row, 17);
                runits.push_back(runit);
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
                unit_O='.';
            }
            if (unit_O=='A') {
                if (ok2==1) {
                    charged2=1;
                    archer *runit=new archer(1, 17);
                    runits.push_back(runit);
                    for (int i=2; i<=10; i++) {
                        archer *runit1=new archer();
                        *runit1=*runit;
                        runit1->setX(i);
                        runits.push_back(runit1);
                        w[i-1]++;
                    }
                    for (int i=0;i<static_cast<int>(cdO.size());i++) {
                        cdO[i]=1+O.get_cd()[i];
                    }
                    ok2=0;
                    unit_O='.';
                    goto skip_right;
                }
                archer *runit = new archer(row, 17);
                runits.push_back(runit);
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
                unit_O='.';
            }
            if (unit_O=='C') {
                if (ok2==1) {
                    charged2=1;
                    cavalry *runit=new cavalry(1, 17);
                    runits.push_back(runit);
                    for (int i=2; i<=10; i++) {
                        cavalry *runit1=new cavalry();
                        *runit1=*runit;
                        runit1->setX(i);
                        runits.push_back(runit1);
                        w[i-1]++;
                    }
                    for (int i=0;i<static_cast<int>(cdO.size());i++) {
                        cdO[i]=1+O.get_cd()[i];
                    }
                    ok2=0;
                    unit_O='.';
                    goto skip_right;
                }
                cavalry *runit = new cavalry(row, 17);
                runits.push_back(runit);
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
                unit_O='.';
            }
            if (unit_O=='X') {
                if (e_race=='E') {
                    if (ok2==1) {
                        charged2=1;
                        whirler *runit=new whirler(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            whirler *runit1=new whirler();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    whirler *runit = new whirler(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='H') {
                    if (ok2==1) {
                        charged2=1;
                        kings_guard *runit=new kings_guard(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            kings_guard *runit1=new kings_guard();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    kings_guard *runit = new kings_guard(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='O') {
                    if (ok2==1) {
                        charged2=1;
                        battle_axeman *runit=new battle_axeman(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            battle_axeman *runit1=new battle_axeman();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    battle_axeman *runit = new battle_axeman(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='T') {
                    if (ok2==1) {
                        charged2=1;
                        giant_troll *runit=new giant_troll(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            giant_troll *runit1=new giant_troll();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    giant_troll *runit = new giant_troll(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='M') {
                    if (ok2==1) {
                        charged2=1;
                        javelin_thrower *runit=new javelin_thrower(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            javelin_thrower *runit1=new javelin_thrower();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    javelin_thrower *runit = new javelin_thrower(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='U') {
                    if (ok2==1) {
                        charged2=1;
                        flailer *runit=new flailer(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            flailer *runit1=new flailer();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    flailer *runit = new flailer(row, 17);
                    runits.push_back(runit);
                }
                if (e_race=='D') {
                    if (ok2==1) {
                        charged2=1;
                        spearmaster *runit=new spearmaster(1, 17);
                        runits.push_back(runit);
                        for (int i=2; i<=10; i++) {
                            spearmaster *runit1=new spearmaster();
                            *runit1=*runit;
                            runit1->setX(i);
                            runits.push_back(runit1);
                            w[i-1]++;
                        }
                        for (int i=0;i<static_cast<int>(cdO.size());i++) {
                            cdO[i]=1+O.get_cd()[i];
                        }
                        ok2=0;
                        unit_O='.';
                        goto skip_right;
                    }
                    spearmaster *runit = new spearmaster(row, 17);
                    runits.push_back(runit);
                }
                for (int i=0;i<static_cast<int>(cdO.size());i++) {
                    cdO[i]=1+O.get_cd()[i];
                }
            }
            skip_right:
            for (int i=0;i<static_cast<int>(runits.size());i++) {
                int _x=runits[i]->getX();
                int _y=runits[i]->getY();
                if (auto poz=runits[i]->attack(lunits, 'R'); poz>=0) {
                    *lunits[poz]-=runits[i]->damage(lunits[poz]);
                    if (*lunits[poz]<=0) {
                        G.setfield(lunits[poz]->getX(), lunits[poz]->getY(), '_', 'R');
                        delete lunits[poz];
                        lunits[poz]=nullptr;
                        lunits.erase(lunits.begin()+poz);
                        O.kill_counter();
                    }
                }
                if (auto poz=runits[i]->collision(lunits, 'R'); poz>=0) {
                    continue;
                }
                runits[i]->movement(G, _x, _y, e_race, 'R', runits, i);
            }
            for (int i=0; i<static_cast<int>(cdP.size()); i++) {
                if (cdP[i]!=0){
                    cdP[i]--;
                }
                if (cdO[i]!=0){
                    cdO[i]--;
                }
            }
            sort(lunits.begin(), lunits.end(), [](const unit* x, const unit* y){return x->getHP()<y->getHP();});
            sort(runits.begin(), runits.end(), [](const unit* x, const unit* y){return x->getHP()<y->getHP();});
            G.setturns();
            system(CLEAR);
        }
        return 0;
    }
}