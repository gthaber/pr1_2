
#ifndef PR1_1_SHIP_H
#define PR1_1_SHIP_H

#include <iostream>
#include <fstream>
#include <string>
#include "transport.h"

enum Ship_Type {
    LINER = 1,
    TUG = 2,
    TANKER = 3
};

class ship : public transport {
public:
    static std::string type_to_str(Ship_Type t);
    int displacement;
    Ship_Type ship_type;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};


#endif //PR1_1_SHIP_H
