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
