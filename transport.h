
#ifndef PR1_1_TRANSPORT_H
#define PR1_1_TRANSPORT_H

#include <iostream>
#include <fstream>

enum T_type {
    PLANES=1,
    TRAIN=2
};

class transport {
public:
    T_type tr_type;
    int speed;
    int distance;
    double mass;

    virtual bool read(std::ifstream& stream) = 0;
    virtual void out(std::ofstream& stream) = 0;

    static transport* read_transport(std::ifstream&stream);
    void out_transport(std::ofstream& stream);
private:
};


#endif //PR1_1_TRANSPORT_H
