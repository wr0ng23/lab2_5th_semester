//
// Created by kolya on 08.10.2022.
//

#ifndef LAB2_ELEMENT_H
#define LAB2_ELEMENT_H

#include "Route.h"

class Element {
public:
    Route *route;
    Element *next;
    Element *prev;

    Element();

    ~Element();
};


#endif //LAB2_ELEMENT_H
