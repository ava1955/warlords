#include "conquest.h"
namespace conq{
    void conquest() {
        campaign& C = campaign::getcampaign();
        cout<<"Choose your race:"<<MAGENTA<<"Elves (E)"<<RESET<<", "<<BLUE<<"Human Alliance (H)"<<RESET<<", "<<YELLOW<<"Men of the West (M)"<<RESET<<", "<<GREEN<<"Orcs (O)"<<RESET<<", "<<CYAN<<"Trolls (T)"<<RESET<<", "<<WHITE<<"The Undead (U)"<<RESET;
        char race;
        cin>>race;
        race=toupper(race);
        while (!strchr("EHMOTU", race)) {
            cout<<"Please choose a valid race";
            cin>>race;
            race=toupper(race);
        }
        C.conquest_init(race);
        string colour;
        auto provinces=C.getprovinces();
        switch (race) {
            case 'H': colour=BLUE; C.setprovinces(provinces[6]); break;
            case 'E': colour=MAGENTA; C.setprovinces(provinces[1]); break;
            case 'M': colour=YELLOW; C.setprovinces(provinces[5]); break;
            case 'T': colour=CYAN; C.setprovinces(provinces[0]); break;
            case 'O': colour=GREEN; C.setprovinces(provinces[4]); break;
            case 'D': colour=RED; C.setprovinces(provinces[2]); break;
            case 'U': colour=WHITE; C.setprovinces(provinces[3]); break;
        }
        C.updatemap();
        C.province_update(colour);
        C.showmap();
        while (C.getbattles()<6) {
            set <string> aux=C.getprovinces_attackable();
            cout<<"You may attack the following provinces:"<<endl;
            int _i=0;
            for (auto elem: aux) {
                if (_i==aux.size()-1) {
                    cout<<elem<<endl;
                    break;
                }
                cout<<elem<<", ";
                _i++;
            }
            string province;
            getline(cin, province);
            while (true) {
                bool found = false;
                for (const auto& elem : aux) {
                    if (province == elem) {
                        found = true;
                        break;
                    }
                }
                if (found) break;
                cout << "Please enter a valid province." << endl;
                getline(cin, province);
            }
            switch (province[0]) {
                case 'S': {
                    int _i=gameplay(race, 'M');
                    if (_i==1) {
                        C.setbattles();
                        auto Senshan = C.getprovince('S');
                        Senshan->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[5]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'V': {
                    int _i=gameplay(race, 'D');
                    if (_i==1) {
                        C.setbattles();
                        auto Vorth = C.getprovince('V');
                        Vorth->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[2]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'O': {
                    int _i=gameplay(race, 'H');
                    if (_i==1) {
                        C.setbattles();
                        auto Orthshire = C.getprovince('O');
                        Orthshire->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[6]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'C': {
                    int _i=gameplay(race, 'E');
                    if (_i==1) {
                        C.setbattles();
                        auto Chan = C.getprovince('C');
                        Chan->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[1]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'T': {
                    int _i=gameplay(race, 'O');
                    if (_i==1) {
                        C.setbattles();
                        auto Thareth = C.getprovince('T');
                        Thareth->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[4]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'B': {
                    int _i=gameplay(race, 'T');
                    if (_i==1) {
                        C.setbattles();
                        auto Battakka = C.getprovince('B');
                        Battakka->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[0]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
                case 'D': {
                    int _i=gameplay(race, 'U');
                    if (_i==1) {
                        C.setbattles();
                        auto Dead_Plains = C.getprovince('D');
                        Dead_Plains->setcolour(string(colour)+UNDERLINE);
                        C.setprovinces(provinces[3]);
                    }
                    cout<<"Press C to continue your conquest.\n";
                    char c;
                    cin>>c;
                    if (c=='C' || c=='c') {
                        system(CLEAR);
                        break;
                    }
                }
            }
            C.updatemap();
            C.province_update(colour);
            C.showmap();
        }
        switch (race) {
            case 'H': cout<<endl<<"After years of fighting, "<<BLUE<<"the Human Alliance"<<RESET<<" conquered the land, bringing with them an age of peace which lasted for many years.\n"; break;
            case 'E': cout<<endl<<"After years of fighting, "<<MAGENTA<<"the Elves"<<RESET<<" conquered the land, bringing with them an endless night which lasted for many years.\n"; break;
            case 'M': cout<<endl<<"After years of fighting, "<<YELLOW<<"the Men of the West"<<RESET<<" conquered the land, bringing with them a mighty empire which lasted for many years.\n"; break;
            case 'T': cout<<endl<<"After years of fighting, "<<CYAN<<"the Trolls"<<RESET<<" conquered the land, bringing with them an endless winter which lasted for many years.\n"; break;
            case 'O': cout<<endl<<"After years of fighting, "<<GREEN<<"the Orcs"<<RESET<<" conquered the land, bringing with them oppression and misery which lasted for many years.\n"; break;
            case 'U': cout<<endl<<"After years of fighting, "<<WHITE<<"the Undead"<<RESET<<" conquered the land, bringing with them a reign of terror which lasted for many years.\n"; break;
        }
        cout<<"Congratulations! You have completed campaign mode!\n";
    }
}