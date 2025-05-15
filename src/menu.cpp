#include "menu.h"
bool menu() {
    peiculesque Steve;
    Steve.getpeiculesque();
    cout<<"Welcome to Warlords. I am Steve the Peiculesque and I will guide you through your gameplay.\n";
    cout<<"You have a field of battle consisting of 10 rows on which you can place units: \n";
    cout<<"Swordsmen, Halberdiers, Archers, Cavalry, and a special units based on your chosen race: \n";
    cout<<"Enter 1-10 for row placement => P/S/H/A/C/X for units \n";
    cout<<"Enter 0 to abandon game.\n";
    cout<<"Enter X to play a single battle. Enter Y to play the tutorial (recommended). Enter Z to play campaign mode.\n";
    char init;
    cin>>init;
    if (init=='X' || init=='x') {
        cout<<"Choose your race:"<<MAGENTA<<"Elves (E)"<<RESET<<", "<<BLUE<<"Human Alliance (H)"<<RESET<<", "<<YELLOW<<"Men of the West (M)"<<RESET<<", "<<GREEN<<"Orcs (O)"<<RESET<<", "<<CYAN<<"Trolls (T)"<<RESET<<", "<<WHITE<<"The Undead (U)"<<RESET;
        char race;
        cin>>race;
        race=toupper(race);
        while (!strchr("EHMOTU", race)) {
            cout<<"Please choose a valid race";
            cin>>race;
            race=toupper(race);
        }
        cout<<"Choose an enemy race to fight against (not the same race):"<<MAGENTA<<"Elves (E)"<<RESET<<", "<<BLUE<<"Human Alliance (H)"<<RESET<<", "<<YELLOW<<"Men of the West (M)"<<RESET<<", "<<GREEN<<"Orcs (O)"<<RESET<<", "<<CYAN<<"Trolls (T)"<<RESET<<", "<<WHITE<<"The Undead (U)"<<RESET<<", "<<RED<<"Demons (D)"<<RESET;
        char e_race;
        cin>>e_race;
        e_race=toupper(e_race);
        while (!strchr("EHMOTUD", e_race) && e_race==race) {
            cout<<"Please choose a valid race";
            cin>>e_race;
            e_race=toupper(e_race);
        }
        int i=play::gameplay(race, e_race);
        cout<<"Press C to go back to menu\n";
        char c;
        cin>>c;
        if (c=='C' || c=='c') return 1;
        return 0;
    }
    if (init=='Y' || init=='y') if (tutor::tutorial()==1) return 1;
    if (init=='Z' || init=='z') conq::conquest();
    return 0;
}