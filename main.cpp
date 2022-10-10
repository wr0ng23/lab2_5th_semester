#include <windows.h>
#include "List.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    List* list = new List;
    list->addElementToEnd(new Route("A", "B", 1));
    list->addElementToEnd(new Route("B", "C", 2));
    list->addElementToEnd(new Route("C", "D", 3));
    list->addElementByIndex(new Route("Z", "F", 10), 1);
    list->displayList();
    std::cout << "=========================\n";

    list->deleteElementByIndex(2);
    list->displayList();
    std::cout << "=========================\n";

    list->editElementByIndex(new Route("Q", "E", 120), 2);
    list->displayList();
    std::cout << "=========================\n";

    list->addElementByIndex(new Route("P", "O", 101), 1);
    list->addElementByIndex(new Route("Y", "E", 303), 1);

    list->displayList();

    delete list;
    system("pause");

    return 0;
}
