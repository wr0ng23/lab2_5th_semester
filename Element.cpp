//
// Created by kolya on 08.10.2022.
//

#include "Element.h"

Element::Element() : route(nullptr), next(nullptr), prev(nullptr) {}

Element::~Element() {
    delete route;
}
