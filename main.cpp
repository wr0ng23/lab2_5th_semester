#include <windows.h>
#include "Menu.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    Menu* menu = new Menu;
    menu->startProgram();

    return 0;
}
