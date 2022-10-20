#include <windows.h>
#include "firstEx/List.h"
#include "secondEx/TextAnalysis.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    TextAnalysis::readFromConsole();
    system("pause");

    return 0;
}
