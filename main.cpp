
// Вариант 4 - 3 - 2 - 1
// Контейнер на основе однонаправленного кольцевого списка.
// Разбиение на модули осуществляется по объектному принципу.
// Обобщение, построенное на основе непосредственного включения специализаций.
#include <gtest/gtest.h>
#include "container.h"
const bool Testing = false;
using namespace std;
int RunTests() {
    testing::InitGoogleTest();
    return RUN_ALL_TESTS();
}

int main(int argc, char* argv[]) {
    if(Testing) {
        return RunTests();
    }
    if(argc !=3) {
        cout << "incorrect command line! " << endl
             << "Waited: command in_file out_file"
             << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    ofstream ofst(argv[2]);
    if(!ifst.is_open()) {
        std::cout << "I/O File is missing.\n";
        return 1;
    }
    cout << "START"<< endl;
    container c{};
    c.read_container(ifst);
    c.out_container(ofst);
    ofst << "Sorted container" << std::endl;
    c.sort();
    c.out_container(ofst);
    ofst << "Ignoring type 1:" << std::endl;
    c.out_container(ofst, T_type::PLANES);
    ofst << "Ignoring type 2:" << std::endl;
    c.out_container(ofst, T_type::TRAIN);
    c.containerClear();
    cout << "END"<< endl;
    return 0;
}