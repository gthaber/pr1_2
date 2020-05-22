#include "train.h"

bool train::read(std::ifstream &stream) {
    if(!stream.eof())
        stream >> length;
    else return false;
    return true;
}

void train::out(std::ofstream &stream) {
    stream << "Train; Length: " << length << ";" << std::endl;
}

void train::multi(transport *other, std::ofstream &stream) {
    other->trainMulti(stream);
}

void train::shipMulti(std::ofstream &stream) {
    stream << "| train + ship |" << std::endl;
}

void train::planesMulti(std::ofstream &stream) {
    stream << "| train + planes |" << std::endl;
}

void train::trainMulti(std::ofstream &stream) {
    stream << "| train + train |" << std::endl;
}
