
#include "ship.h"

bool ship::read(std::ifstream &stream) {
    if(!stream.eof())
        stream >> displacement;
    else return false;
    if(!stream.eof()) {
        int typ;
        stream >> typ;
        ship_type = (ship_type) typ;
    }
    else return false;
    return true;
}

void ship::out(std::ofstream &stream) {
    stream << "Ships; Displacement: " << displacement << "; Ship type: " << ship::typeToStr(ship_type) << ";" << std::endl;
}

std::string ship::typeToStr(ship_type t) {
    switch(t) {
        case 1:
            return "Liner";
        case 2:
            return "Tug";
        case 3:
            return "Tanker";
        default:
            return "Unknown type";
    }
}
