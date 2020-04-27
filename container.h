
#ifndef PR1_1_CONTAINER_H
#define PR1_1_CONTAINER_H

#include <iostream>
#include <fstream>
#include "transport.h"

class element {
public:
    transport* t;
    element* forward;
private:
};

class container {
public:
    container();
    void containerClear();
    void containerAdd(element*);
    void read_container(std::ifstream& stream);
    void out_container(std::ofstream& stream);
    element* starting;
    element* ending;
    int size;
private:
};


#endif //PR1_1_CONTAINER_H
