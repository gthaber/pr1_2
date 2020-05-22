
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
    void multi(std::ofstream &ofst);
    void containerClear();
    void containerAdd(element*);
    void readContainer(std::ifstream& stream);
    void outContainer(std::ofstream& stream);
    void sort();
    int outContainer(std::ofstream& stream, t_type typ);
    element* starting;
    element* ending;
    int size;
private:
};


#endif //PR1_1_CONTAINER_H
