//
// Created by kolya on 07.10.2022.
//

#ifndef LAB2_SAFEINPUT_H
#define LAB2_SAFEINPUT_H
#include <iostream>

template<typename T>
T input() {
    T answer;
    while (true) {
        std::cin.unsetf(std::ios::skipws);
        std::cout << "Ввод: ";
        std::cin >> answer;
        if (std::cin.good()) {
            std::cin.ignore(1000, '\n');
            return answer;
        }
        std::cin.clear();
        std::cin.ignore(1000, '\n');
        std::cout << "Повторите попытку ввода, произошла ошибка!" << std::endl;
    }
}

template<>
inline std::string input<std::string>() {
    std::string answer;
    std::cout << "Ввод: ";
    std::getline(std::cin, answer);
    return answer;
}

#endif //LAB2_SAFEINPUT_H
