
#include "container.h"

void container::read_container(std::ifstream &stream) {
    while(!stream.eof()) {
        transport *temp_tr = transport::read_transport(stream);
        if (temp_tr == nullptr) return; // Если не считалось, то ошибка
        element *el = new element{};
        el->t = temp_tr;
        containerAdd(el);
    }
}

void container::containerAdd(element *el) {
    size++;
    if(starting == nullptr) {
        starting = ending = el;
    } else {
        ending->forward = el;
        ending = el;
        el->forward = starting;
    }
}

container::container() {
    size = 0;
    starting = ending = nullptr;
}

void container::containerClear() {
    element *el = starting;
    for(int i = 0; i < size; i++) {
        delete el->t;
        element *next = el->forward;
        delete el;
        el = next;
    }
}

void container::out_container(std::ofstream &stream) {
    element *el = starting;
    for(int i = 0; i < size; i++) {
        stream << i+1 << ". ";
        el->t->out_transport(stream);
        el = el ->forward;
    }
}

void container::multi(std::ofstream &ofst) {
    ofst << "_.-._.-._.-._.-MULTIMETHOD-._.-._.-._.-._" << std::endl;
    element *el1 = starting;
    int count1 = 0;
    for(int i = 0; i < size; i++) {
        element *el2 = starting;
        for(int j = 0; j < size; j++) {
            if(i == j) {
                el2 = el2->forward;
                continue;
            }
            el1->t->multi(el2->t, ofst);
            el1->t->out_transport(ofst);
            el2->t->out_transport(ofst);
            el2 = el2->forward;
        }
        el1 = el1->forward;
    }
}

