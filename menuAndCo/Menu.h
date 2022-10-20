//
// Created by kolya on 20.10.2022.
//

#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include "../firstEx/List.h"
#include "../secondEx/TextAnalysis.h"
#include "checkingAccuracyOfTheInput.h"

class Menu {
private:
    List *listOfRoutes;

    void firstEx();

    void secondEx();

public:

    Menu();

    ~Menu();

    void startProgram();
};


#endif //LAB2_MENU_H
