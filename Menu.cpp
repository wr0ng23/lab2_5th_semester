//
// Created by kolya on 20.10.2022.
//

#include "Menu.h"

Menu::Menu() {
    listOfRoutes = new List();
}

Menu::~Menu() {
    delete listOfRoutes;
}

void Menu::firstEx() {
    while (true) {
        system("cls");
        std::cout << "1) Добавить маршрут в список\n"
                  << "2) Изменить информацию о маршруте\n"
                  << "3) Удалить маршрут из списка\n"
                  << "4) Показать список маршрутов\n"
                  << "5) Найти маршрут по номеру\n"
                  << "6) Перейти ко второму заданию\n"
                  << "7) Выйти из программы\n";
        int answer = input<int>();
        system("cls");
        switch (answer) {
            case 1: {
                std::cout << "---Добавление маршрута---\n";
                auto newRoute = new Route;
                std::cin >> *newRoute;

                std::cout << "\nКуда вы хотите добавить маршрут?\n"
                          << "1) В начало списка\n"
                          << "2) В конец списка\n"
                          << "3) По индексу\n";

                int answer1 = checking_accuracy_of_the_input(1, 3);
                if (answer1 == 1) listOfRoutes->addElementToBegin(newRoute);
                else if (answer1 == 2) listOfRoutes->addElementToEnd(newRoute);
                else {
                    std::cout << "\nВведите индекс для добавления маршрута, всего элементов "
                              << listOfRoutes->getSize()
                              << ".\nИндекс должен быть от 1 до " << listOfRoutes->getSize() + 1 << "\n";
                    int index = checking_accuracy_of_the_input(1, listOfRoutes->getSize() + 1);
                    listOfRoutes->addElementByIndex(newRoute, index - 1);
                }
                break;
            }
            case 2: {
                if (listOfRoutes->getSize() == 0) {
                    std::cout << "Маршруты пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Изменение информации о маршруте---\n"
                          << "Информацию о каком маршруте вы хотите изменить?\n\n";
                listOfRoutes->displayList();

                std::cout << "\nВведите индекс для изменения информации о маршруте, всего элементов "
                          << listOfRoutes->getSize() << ".\nИндекс должен быть от 1 до " << listOfRoutes->getSize()
                          << "\n";
                int index = checking_accuracy_of_the_input(1, listOfRoutes->getSize());
                listOfRoutes->editElementByIndex(index - 1);
                break;
            }
            case 3: {
                if (listOfRoutes->getSize() == 0) {
                    std::cout << "Маршруты пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Удаление маршрута из списка---\n"
                          << "Какой маршрут вы хотите удалить из списка?\n\n";
                listOfRoutes->displayList();
                std::cout << "\nВведите индекс маршрута, который хотите удалить, всего элементов "
                          << listOfRoutes->getSize() << ".\nИндекс должен быть от 1 до " << listOfRoutes->getSize()
                          << "\n";
                int index = checking_accuracy_of_the_input(1, listOfRoutes->getSize());
                listOfRoutes->deleteElementByIndex(index - 1);
                break;
            }
            case 4: {
                if (listOfRoutes->getSize() == 0) {
                    std::cout << "Маршруты пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Все текущие маршруты в программе---\n\n";
                listOfRoutes->displayList();
                break;
            }
            case 5: {
                if (listOfRoutes->getSize() == 0) {
                    std::cout << "Маршруты пока не добавлены в программу!\n";
                    break;
                }
                std::cout << "---Поиск маршрута по номеру---\n";
                std::cout << "Введите номер маршрута для поиска\n";
                int numberOfRoute = input<int>();
                listOfRoutes->displayElementByNumberOfRoute(numberOfRoute);
                break;
            }
            case 6:
                secondEx();
            case 7: {
                std::cout << "Выход из программы..\n";
                system("pause");
                exit(1);
            }
            default: {
                std::cout << "Введена неверная цифра, повторите попытку!\n";
            }
        }

        system("pause");
    }
}

void Menu::secondEx() {
    while (true) {
        try {
            system("cls");
            std::cout << "Программа находит все английские слова начинающиеся на гласную и заканчивающиеся на нее\n";
            std::cout << "1) Считывать информацию из файла\n"
                      << "2) Считывать информацию с консоли\n"
                      << "3) Выход из программы\n";
            int answer = checking_accuracy_of_the_input(1, 3);

            if (answer == 1) {
                std::cout << "Введите имя файла в формате(имя_файла.txt)\n";
                std::string nameOfFile = input<std::string>();
                TextAnalysis::readFromFile(nameOfFile);
            } else if (answer == 2) {
                TextAnalysis::readFromConsole();
            } else {
                std::cout << "Выход из программы..\n";
                system("pause");
                exit(1);
            }

        } catch (MyException &e) {
            std::cout << e.get_error();
        }

        system("pause");
    }
}

void Menu::startProgram() {
    std::cout << "Выберите с каким заданием хотите работать:\n"
              << "1) Первое задание\n"
              << "2) Второе задание\n"
              << "3) Выход\n";
    int answer = checking_accuracy_of_the_input(1, 3);

    if (answer == 1) firstEx();
    else if (answer == 2) secondEx();
    else {
        std::cout << "Выход из программы..\n";
        system("pause");
        exit(1);
    }
}
