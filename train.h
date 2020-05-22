
#ifndef PR1_1_TRAIN_H
#define PR1_1_TRAIN_H

#include "transport.h"

class train : public transport{
public:
    int length;
    void multi(transport* other, std::ofstream& stream) override;
    void planesMulti(std::ofstream& stream) override;
    void trainMulti(std::ofstream& stream) override;
    bool read(std::ifstream& stream);
    void out(std::ofstream& stream);
private:
};



#endif //PR1_1_TRAIN_H
