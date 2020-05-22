#include "transport.h"
#include "planes.h"
#include "train.h"
#include "ship.h"

transport* transport::readTransport(std::ifstream &stream) {
    int type;
    stream >> type;
    if(type < 1 || type > 3) {
        std::cout << "Input error." << std::endl;
        return nullptr;
    }
    transport *temp_t;
    switch (type) {
        case t_type::PLANES:
            temp_t = new planes{};
            if(!temp_t->read(stream)) return nullptr;
            temp_t->tr_type = t_type::PLANES;
            break;
        case t_type::TRAIN:
            temp_t = new train{};
            if(!temp_t->read(stream)) return nullptr;
            temp_t->tr_type = t_type::TRAIN;
            break;
        case t_type::SHIP:
            temp_t = new ship{};
            if(!temp_t->read(stream)) return nullptr;
            temp_t->tr_type = t_type::SHIP;
            break;
        default:
            return nullptr;
    }
    if(!stream.eof()) stream >> temp_t->speed;
    else delete temp_t;
    if(temp_t->speed <= 0) {
        delete temp_t;
        return nullptr;
    }
    if(!stream.eof()) stream >> temp_t->distance;
    else delete temp_t;
    if(!stream.eof()) stream >> temp_t->mass;
    else delete temp_t;
    if(temp_t->mass <= 0) {
        return nullptr;
    }
    return temp_t;
}

void transport::outTransport(std::ofstream &stream) {
    stream << "Speed: " << speed << "; Distance: " << distance << "; Estimate time: " << estimateTime()
    << "; Mass: " << mass << "; Type: ";
    out(stream);
}

double transport::estimateTime() {
    return distance/speed;
}

bool transport::comparator(transport *el1, transport *el2) {
    return el1->estimateTime() < el2->estimateTime();
}
