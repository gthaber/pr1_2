#include "transport.h"
#include "planes.h"
#include "train.h"

transport* transport::read_transport(std::ifstream &stream) {
    int type;
    stream >> type;
    if(type < 1 || type > 2) {
        std::cout << "Input error." << std::endl;
        return nullptr;
    }
    transport *temp_t;
    switch (type) {
        case T_type::PLANES:
            temp_t = new planes{};
            temp_t->read(stream);
            temp_t->tr_type = T_type::PLANES;
            break;
        case T_type::TRAIN:
            temp_t = new train{};
            temp_t->read(stream);
            temp_t->tr_type = T_type::TRAIN;
            break;
        default:
            return nullptr;
    }
    if(!stream.eof()) stream >> temp_t->speed;
    else delete temp_t;
    if(!stream.eof()) stream >> temp_t->distance;
    else delete temp_t;
    return temp_t;
}

void transport::out_transport(std::ofstream &stream) {
    stream << "Speed: " << speed << "; Distance: " << distance << "; Type: ";
    out(stream);
}
