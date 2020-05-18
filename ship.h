
#ifndef PR1_1_SHIP_H
#define PR1_1_SHIP_H

#include <iostream>
#include <fstream>
#include <string>
#include "transport.h"

enum ship_type {
    LINER = 1,
    TUG = 2,
    TANKER = 3
};

class ship : public transport {
public:
    static std::string typeToStr(ship_type t);
    int displacement;
    ship_type ship_type;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};


#endif //PR1_1_SHIP_H
