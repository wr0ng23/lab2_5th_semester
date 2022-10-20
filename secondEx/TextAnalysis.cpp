//
// Created by kolya on 11.10.2022.
//

#include "TextAnalysis.h"

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

// Получает поток данных и обрабатывает его
void TextAnalysis::printingCorrectWords(std::iostream &inputStream) {
    std::cout << "\nРезультат:\n";
    std::string word;
    while (inputStream >> word) {
        if (isVowel(word[0]) && isVowel(word[word.size() - 1])) {
            std::cout << word << " ";
        }
    }
    std::cout << "\n";
}

void TextAnalysis::readFromConsole() {
    std::cout << "Введите текст в консоль, завершив ввод знаком $: ";
    std::string text;
    // Считывание инфорамции из консоли и создание из этого потока
    std::getline(std::cin, text, '$');
    std::stringstream stringStream(text);
    std::cin.ignore();
    printingCorrectWords(stringStream);
}

void TextAnalysis::readFromFile(std::string fileName) {
    if (!ends_with(fileName, ".txt")) {
        throw MyException("Файл имеет неподдерживаемый тип, вводите имя файла с расширением .txt!\n");
    }

    std::fstream file;
    file.open(fileName, std::ios::in);
    if (!file.is_open()) {
        file.close();
        throw MyException("Файл не открылся!\n");
    }

    printingCorrectWords(file);

    file.close();
}

bool TextAnalysis::ends_with(const std::string &value, const std::string &ending) {
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}