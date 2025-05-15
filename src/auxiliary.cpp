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
    }
}
    int getprovince(char x) {
    switch(x) {
        case 'S': {
            return 1;
            break;
        }
        case 'V': {
            return 2;
            break;
        }
        case 'O': {
            return 3;
            break;
        }
        case 'C': {
            return 4;
            break;
        }
        case 'T': {
            return 5;
            break;
        }
        case 'B': {
            return 6;
            break;
        }
        case 'D': {
            return 7;
            break;
        }
    }
}
}