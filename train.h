
#ifndef PR1_1_TRAIN_H
#define PR1_1_TRAIN_H

#include "transport.h"

class train : public transport{
public:
    int length;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};



#endif //PR1_1_TRAIN_H
