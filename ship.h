
#ifndef PR1_1_SHIP_H
#define PR1_1_SHIP_H

#include <iostream>
#include <fstream>
#include <string>
#include "transport.h"

enum ship_type_ {
    LINER = 1,
    TUG = 2,
    TANKER = 3
};

class ship : public transport {
public:
    static std::string typeToStr(ship_type_ t);
    int displacement;
    ship_type_ ship_type;
    void multi(transport* other, std::ofstream& stream) override;
    void shipMulti(std::ofstream& stream) override;
    void planesMulti(std::ofstream& stream) override;
    void trainMulti(std::ofstream& stream) override;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};


#endif //PR1_1_SHIP_H
