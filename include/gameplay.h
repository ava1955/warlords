#include "auxiliary.h"
#include "campaign.h"
#include "game.h"
#include "player.h"
#include "opponent.h"
#include "peiculesque.h"
#include "unit.h"
#include "pikeman.h"
#include "swordsman.h"
#include "halberdier.h"
#include "archer.h"
#include "cavalry.h"
#include "whirler.h"
#include "kings_guard.h"
#include "giant_troll.h"
#include "spearmaster.h"
#include "javelin_thrower.h"
#include "flailer.h"
#include "battle_axeman.h"
#include <algorithm>
using std::sort;
#ifndef GAMEPLAY_H
#define GAMEPLAY_H
namespace play {
    int gameplay(char race, char e_race);
}
#endif
