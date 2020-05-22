
#include "ship.h"

bool ship::read(std::ifstream &stream) {
    if(!stream.eof())
        stream >> displacement;
    else return false;
    if(!stream.eof()) {
        int typ;
        stream >> typ;
        ship_type = (ship_type_) typ;
    }
    else return false;
    return true;
}

void ship::out(std::ofstream &stream) {
    stream << "Ships; Displacement: " << displacement << "; Ship type: " << ship::typeToStr(ship_type) << ";" << std::endl;
}

std::string ship::typeToStr(ship_type_ t) {
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

void ship::multi(transport *other, std::ofstream &stream) {
    other->shipMulti(stream);
}

void ship::shipMulti(std::ofstream &stream) {
    stream << "| ship + ship |" << std::endl;
}

void ship::planesMulti(std::ofstream &stream) {
    stream << "| ship + planes |" << std::endl;
}

void ship::trainMulti(std::ofstream &stream) {
    stream << "| ship + train |" << std::endl;
}
