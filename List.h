//
// Created by kolya on 08.10.2022.
//

#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include "Element.h"

class List {
private:
    Element *first;
    Element *last;
    int size;

    Element *searchingForElementByIndex(int index);

    [[nodiscard]] bool isIndexCorrect(int index) const;

public:
    List();

    ~List();

    void editElementByIndex(Route *route, int index);

    void deleteElementFromBegin();

    void deleteElementFromEnd();

    void deleteElementByIndex(int index);

    void addElementToEnd(Route *route);

    void addElementToBegin(Route *route);

    void addElementByIndex(Route *route, int index);

    [[nodiscard]] bool isEmpty() const;

    void displayList();
};


#endif //LAB2_LIST_H
