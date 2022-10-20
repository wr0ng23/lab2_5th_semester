//
// Created by kolya on 20.10.2022.
//
#include "checkingAccuracyOfTheInput.h"

int checking_accuracy_of_the_input(int low_limit, int high_limit) {
    int answer;
    while (true) {
        answer = input<int>();
        if (answer < low_limit || answer > high_limit) {
            std::cout << "Повторите попытку ввода, вводимое число должно быть в диапазоне от " << low_limit << " до "
                      << high_limit << "\n";
        } else break;
    }
    return answer;
}