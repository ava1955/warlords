#include "aux.h"
#ifndef CAMPAIGN_H
#define CAMPAIGN_H
class campaign {
    int battles_won=0;
    class province {
        string colour;
        string name;
    public:
        province(string colour, string name);
        [[nodiscard]] string getcolour() const;
        [[nodiscard]] string getname() const;
        void setcolour(string colour);
        void addcolour(string colour);
    }Battakka=province(CYAN, "Battakka"),
     Chan=province(MAGENTA, "Chan"),
     Vorth=province(RED, "Vorth"),
     Dead_Plains=province(WHITE, "Dead Plains"),
     Thareth=province(GREEN, "Thareth"),
     Senshan=province(YELLOW, "Senshan"),
     Orthshire=province(BLUE, "Orthshire")
    ;
    vector <province*> provinces={&Battakka, &Chan, &Vorth, &Dead_Plains, &Thareth, &Senshan, &Orthshire};
    set <string> provinces_attackable={};
    set <province*> provinces_conquered={};
    vector <string> map={
        "#_____________________ ________________###",
        "/                     |           ___/ \\##",
        "\\                     /          |      \\#",
        "#\\     "+Battakka.getcolour()+Battakka.getname()+RESET"      |    "+Chan.getcolour()+Chan.getname()+RESET"   |       |",
        "##\\              ____/           |       |",
        "##/______________\\###\\__________/  "+Vorth.getcolour()+Vorth.getname()+RESET" |",
        "/                 \\###|       \\______    |",
        "|   "+Thareth.getcolour()+Thareth.getname()+RESET"___________/ "+Dead_Plains.getcolour()+Dead_Plains.getname()+RESET"  |   |",
        "|      /              \\______________/   /",
        "|     /    "+Senshan.getcolour()+Senshan.getname()+RESET"    |              \\  |#",
        "|____/__________       \\  "+Orthshire.getcolour()+Orthshire.getname()+RESET"   \\ |#",
        "################\\______/_______________|##"
    };
    unordered_map <province*, vector <province*>> dict={
        {&Battakka,{&Chan, &Thareth}},
        {&Chan, {&Battakka, &Vorth, &Dead_Plains}},
        {&Vorth, {&Dead_Plains, &Chan, &Orthshire}},
        {&Dead_Plains, {&Thareth, &Chan, &Senshan, &Orthshire, &Vorth, &Chan}},
        {&Orthshire, {&Senshan, &Dead_Plains, &Vorth}},
        {&Thareth, {&Battakka, &Dead_Plains, &Senshan}},
        {&Senshan, {&Thareth, &Dead_Plains, &Orthshire}}
    };
    campaign();
public:
    ~campaign();
    static campaign& getcampaign();
    vector <province*> getprovinces();
    set <string> getprovinces_attackable();
    void setprovinces(province* prov);
    province* getprovince(char x) ;
    void setbattles();
    [[nodiscard]] int getbattles() const;
    void province_update(string colour);
    void conquest_init(char race);
    void showmap() const;
    void updatemap();
};
#endif //CAMPAIGN_H
