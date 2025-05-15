#include "auxiliary.h"
namespace aux{
string set_colour(char race) {
    switch (race) {
        case 'H':  return string(BLUE);
        case 'E': return string(MAGENTA);
        case 'M': return string(YELLOW);
        case 'U': return string(WHITE);
        case 'D': return string(RED);
        case 'T': return string(CYAN);
        case 'O': return string(GREEN);
        case default: return "";
    }
}
    int getprovince(char x) {
    switch(x) {
        case 'S': {
            return 1;
        }
        case 'V': {
            return 2;
        }
        case 'O': {
            return 3;
        }
        case 'C': {
            return 4;
        }
        case 'T': {
            return 5;
        }
        case 'B': {
            return 6;
        }
        case 'D': {
            return 7;
        }
    }
}
}