
#ifndef PR1_1_TRANSPORT_H
#define PR1_1_TRANSPORT_H

#include <iostream>
#include <fstream>

enum t_type {
    PLANES=1,
    TRAIN=2,
    SHIP=3
};

class transport {
public:
    t_type tr_type;
    int speed;
    int distance;
    double mass;

    virtual bool read(std::ifstream& stream) = 0;
    virtual void out(std::ofstream& stream) = 0;

    virtual void multi(transport* other, std::ofstream& stream) = 0;
    virtual void shipMulti(std::ofstream& stream) = 0;
    virtual void planesMulti(std::ofstream& stream) = 0;
    virtual void trainMulti(std::ofstream& stream) = 0;
    static transport* readTransport(std::ifstream&stream);
    void outTransport(std::ofstream& stream);
    double estimateTime();
    static bool comparator(transport*el1, transport*el2);
private:
};


#endif //PR1_1_TRANSPORT_H
