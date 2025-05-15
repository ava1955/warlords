#ifndef AUXILIARY_H
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <random>
#include <cmath>
#include <unordered_map>
#include <set>
#include <algorithm>
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define ITALIC  "\033[3m"
#define UNDERLINE "\033[4m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#if defined(_WIN32) || defined(_WIN64)
    #define CLEAR "cls"
#elif defined(__APPLE__) || defined(__MACH__) || defined(__linux__) || defined(__unix__)
    #define CLEAR "clear"
#else
    #define CLEAR ""
#endif
using std::vector;
using std::string;
using std::unordered_map;
using std::cin;
using std::cout;
using std::endl;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::set;
using std::ostream;
using std::istream;
namespace aux{
    string set_colour(char race);
    int getprovince(char x);
}
using namespace aux;
#endif