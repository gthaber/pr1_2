
#ifndef PR1_1_PLANES_H
#define PR1_1_PLANES_H

#include <iostream>
#include <fstream>
#include "transport.h"

class planes : public transport {
public:
    int range;
    int carry;
    void multi(transport* other, std::ofstream& stream) override;
    void planesMulti(std::ofstream& stream) override;
    void trainMulti(std::ofstream& stream) override;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};


#endif //PR1_1_PLANES_H
