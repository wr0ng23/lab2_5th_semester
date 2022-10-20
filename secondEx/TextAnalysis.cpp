//
// Created by kolya on 11.10.2022.
//

#include "TextAnalysis.h"

bool TextAnalysis::isVowel(char c) {
    switch (c) {
        case 'a':
        case 'A':
        case 'e':
        case 'E':
        case 'i':
        case 'I':
        case 'o':
        case 'O':
        case 'u':
        case 'U':
            return true;
        default:
            return false;
    }
}

/*bool TextAnalysis::isPunctuationMark(char c) {
    switch (c) {
        case ',':
        case '.':
        case ':':
        case ';':
        case '!':
        case '?':
        case ')':
        case '(':
        case '}':
        case '{':
        case '"':
        case '\'':
        case ']':
        case '[':
            return true;
        default:
            return false;
    }
}*/

// Получает поток данных и обрабатывает его
void TextAnalysis::printingCorrectWords(std::iostream & inputStream) {
    std::string line;
    // Построчно считывает строки из потока
    while (std::getline(inputStream, line)) {
        std::stringstream lineStream(line);
        std::string word;
        // Считывание и обработка слов в каждой строке
        while (lineStream >> word) {
            if (isVowel(word[0]) && isVowel(word[word.size() - 1])) {
                std::cout << word << " ";
            }
        }
        std::cout << "\n";
    }
}

void TextAnalysis::readFromConsole() {
    std::cout << "Введите текст в консоль, завершив ввод знаком $: ";
    std::string text;
    // Считывание инфорамции из консоли и создание из этого потока
    std::getline(std::cin, text, '$');
    std::stringstream stringStream(text);

    std::cout << "\nРезультат: ";
    printingCorrectWords(stringStream);
}

void TextAnalysis::readFromFile() {
    std::fstream file;

    file.open("input.txt", std::ios::in);
    if (!file.is_open()) {
        file.close();
        throw MyException("Файл не открылся!\n");
    }
    printingCorrectWords(file);

    file.close();
}