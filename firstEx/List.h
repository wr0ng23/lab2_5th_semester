//
// Created by kolya on 08.10.2022.
//

#ifndef LAB2_LIST_H
#define LAB2_LIST_H

#include "Element.h"
#include "../menuAndCo/MyException.h"
#include "../menuAndCo/checkingAccuracyOfTheInput.h"

class List {
private:
    Element *first;
    Element *last;
    int size;

    void bubbleSort();

    void swapRoutes(Route *route1, Route *route2);

    [[nodiscard]] Element *searchingForElementByIndex(int index) const;

    [[nodiscard]] bool isIndexIncorrect(int index) const;

public:
    List();

    ~List();

    [[nodiscard]] int getSize() const;

    void displayElementByNumberOfRoute(int searchedNumberOfRoute) const;

    void editElementByIndex(int index);

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
