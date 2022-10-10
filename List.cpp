//
// Created by kolya on 08.10.2022.
//

#include "List.h"

void List::addElementByIndex(Route *route, int index) {
    if (index > size || index < 0) {
        std::cout << "Введен некорректный индекс!\n";
        return;
    }

    if (index == 0) {
        addElementToBegin(route);
        return;
    }

    if (index == size) {
        addElementToEnd(route);
        return;
    }

    Element *searchedElement = searchingForElementByIndex(index);

    Element *newElement = new Element(); // создаем новый узел
    newElement->route = route; // добавляем новый маршрут в узел

    Element *prevElement = searchedElement->prev; // узел, идущий перед узлом с заданным индексом
    prevElement->next = newElement; // обновление указателя у предыдущего элемента на добавляемый элемент
    newElement->prev = prevElement; // обновление указателя на предыдущий элемент у нового узла

    searchedElement->prev = newElement; // установка указателя на новый элемент у предыдщего узла с этим индексом
    newElement->next = searchedElement; // обновление указателя на следующий элемент у добавленного элемента
    std::cout << "Элемент добавлен в список по индексу " << index << "\n";
    ++size;
}

void List::addElementToBegin(Route *route) {
    Element *newELement = new Element();
    newELement->route = route;

    if (isEmpty()) {
        last = newELement;
    } else {
        newELement->next = first;
        first->prev = newELement;
    }

    first = newELement;
    ++size;
    std::cout << "Маршрут доавблен в начало списка, размер списка: " << size << "\n";
}

void List::addElementToEnd(Route *route) {
    Element *newElement = new Element();
    newElement->route = route;

    if (isEmpty()) {
        first = newElement;
    } else {
        newElement->prev = last;
        last->next = newElement;
    }
    last = newElement;
    ++size;
    std::cout << "Маршрут добавлен в список, размер списка: " << size << "\n";
}

void List::displayList() {
    if (size == 0) {
        std::cout << "Нет элементов в списке!\n";
        return;
    }

    Element *temp = first;
    while (temp) {
        std::cout << *(temp->route);
        temp = temp->next;
    }
}

List::List() {
    first = nullptr;
    last = nullptr;
    size = 0;
}

List::~List() {
    Element *temp;

    while (first) {
        temp = first->next;
        delete first;
        first = temp;
    }
}

bool List::isEmpty() const {
    return size == 0;
}

void List::deleteElementFromBegin() {
    if (isEmpty()) {
        std::cout << "Нет элементов в списке!\n";
        return;
    }

    Element *newFirstElement = first->next;
    if (size != 1) {
        newFirstElement->prev = nullptr;
    }

    std::cout << "Элемент " << *(first->route) << "^^^Успешно удален из начала списка!^^^\n\n";
    delete first;
    first = newFirstElement;
    --size;
}

void List::deleteElementFromEnd() {
    if (isEmpty()) {
        std::cout << "Нет элементов в списке!\n";
        return;
    }

    Element *prevElementBeforeLast = last->prev;
    if (size != 1) {
        prevElementBeforeLast->next = nullptr;
    }

    std::cout << "Элемент " << *(last->route) << "^^^Успешно удален из конца списка!^^^\n\n";
    delete last;
    last = prevElementBeforeLast;
    --size;
}

void List::deleteElementByIndex(int index) {
    if (isIndexCorrect(index)) {
        std::cout << "Введен некорректный индекс!\n";
        return;
    }

    if (index == 0) {
        deleteElementFromBegin();
        return;
    }

    if (index == size - 1) {
        deleteElementFromEnd();
        return;
    }

    Element *searchedElement = searchingForElementByIndex(index);

    Element *prevElement = searchedElement->prev;
    Element *nextElement = searchedElement->next;
    prevElement->next = nextElement;
    nextElement->prev = prevElement;
    delete searchedElement;

    std::cout << "Элемент по индексу " << index << " удален!\n";
    --size;
}

void List::editElementByIndex(Route *route, int index) {
    if (isIndexCorrect(index)) {
        std::cout << "Введен некорректный индекс!\n";
        return;
    }

    Element *searchedElement = searchingForElementByIndex(index);

    delete searchedElement->route;
    searchedElement->route = route;
    std::cout << "Информация обновлена!\n";
}

Element* List::searchingForElementByIndex(int index) {
    Element *searchedElement = first; // кладем указатель на первый элемент для прохода по всему списку
    for (int i = 0; i < index; i++) { // поиск элемента с заданным индексом
        searchedElement = searchedElement->next;
    } // searchedElement - узел, который располагается в данный момент по заданному индексу
    return searchedElement;
}

bool List::isIndexCorrect(int index) const {
    return  (index >= size || index < 0);
}
