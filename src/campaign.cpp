#include "auxiliary.h"
#include "campaign.h"
campaign::campaign(){}
campaign& campaign::getcampaign() {
    static campaign C;
    return C;
}
campaign::~campaign() {
    provinces.clear();
    map.clear();
    provinces_attackable.clear();
    provinces_conquered.clear();
    dict.clear();
}
campaign::province::province(string colour, string name) {
    this->colour = colour;
    this->name = name;
}
[[nodiscard]] string campaign::province::getcolour() const {
    return colour;
}
[[nodiscard]] string campaign::province::getname() const {
    return name;
}
void campaign::province::setcolour(string colour) {
    this->colour = colour;
}
void campaign::province::addcolour(string colour) {
    this->colour = colour+this->colour;
}

    vector <campaign::province*> campaign::getprovinces() {
        return provinces;
    }
    set <string> campaign::getprovinces_attackable() {
        return provinces_attackable;
    }
    void campaign::setprovinces(province* prov) {
        provinces_conquered.insert(prov);
    }
    campaign::province* campaign::getprovince(char x) {
        switch(x) {
            case 'S': {
                return &Senshan;
            }
            case 'V': {
                return &Vorth;
            }
            case 'O': {
                return &Orthshire;
            }
            case 'C': {
                return &Chan;
            }
            case 'T': {
                return &Thareth;
            }
            case 'B': {
                return &Battakka;
            }
            case 'D': {
                return &Dead_Plains;
            }
        }
    }
    void campaign::setbattles() {
        battles_won++;
    }
    [[nodiscard]] int campaign::getbattles() const {
        return battles_won;
    }
    void campaign::province_update(string colour) {
        provinces_attackable={};
        for (auto i: provinces_conquered) {
            for (auto j: dict[i]) {
                provinces_attackable.insert(j->getname());
                if (j->campaign::province::getcolour()!=colour) {
                    j->campaign::province::addcolour(string(BOLD)+ITALIC);
                }
            }
        }
        for (auto i:provinces_conquered) {
            provinces_attackable.erase(i->campaign::province::getname());
        }
    }
    void campaign::conquest_init(char race) {
        if (race=='H') {
            Orthshire.setcolour(string(BLUE)+UNDERLINE);
            for (auto i: dict[&Orthshire]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }
        if (race=='E') {
            Chan.setcolour(string(MAGENTA)+UNDERLINE);
            for (auto i: dict[&Chan]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }
        if (race=='T') {
            Battakka.setcolour(string(CYAN)+UNDERLINE);
            for (auto i: dict[&Battakka]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }
        if (race=='M') {
            Senshan.setcolour(string(YELLOW)+UNDERLINE);
            for (auto i: dict[&Senshan]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }
        if (race=='U') {
            Dead_Plains.setcolour(string(WHITE)+UNDERLINE);
            for (auto i: dict[&Dead_Plains]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }
        if (race=='O') {
            Thareth.setcolour(string(GREEN)+UNDERLINE);
            for (auto i: dict[&Thareth]) {
                i->addcolour(string(BOLD)+ITALIC);
                provinces_attackable.insert(i->getname());
            }
        }

    }
    void campaign::showmap() const {
        for(int i=0;i<map.size();i++) {
            cout<<map[i]<<endl;
        }
    }
    void campaign::updatemap() {
        map={
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
    }
