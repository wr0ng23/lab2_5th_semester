//
// Created by kolya on 11.10.2022.
//

#include "TextAnalysis.h"

bool TextAnalysis::isPunctuationMark(char c) {
    switch (c) {
        case ',':
        case '.':
        case ':':
        case ';':
        case '!':
        case '?':
        case '(':
        case ')':
        case '[':
        case ']':
        case '{':
        case '}':
        case '<':
        case '>':
        case '"':
        case '\'':
            return true;
        default:
            return false;
    }
}

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
    std::string word;
    std::string resultString;

    while (inputStream >> word) {
        //Проверка кончается и начинается ли слово с гласной, например: apple ...
        bool firstCheck = isVowel(word[0]) && isVowel(word[word.size() - 1]);

        //Та же проверка, только если слово содержит знак препинания в конце, например: apple, ...
        bool secondCheck = isVowel(word[0]) && isVowel(word[word.size() - 2])
                           && isPunctuationMark(word[word.size() - 1]);

        // Если слово содержит знак препинания в начале, например: (apple ...
        bool thirdCheck = isVowel(word[1]) && isVowel(word[word.size() - 1]) && isPunctuationMark(word[0]);

        // Если слово содержит в начале и конце знак понктуации, например: (apple, ...
        bool forthCheck = isVowel(word[1]) && isVowel(word[word.size() - 2]) && isPunctuationMark(word[0]) &&
                          isPunctuationMark(word[word.size() - 1]);

        // Переменная отвечающая за то, что слово подходит под условия
        bool flag = false;
        // Если слово подходит под условия и содержит в себе знаки припинания, слово парсится без них
        if (firstCheck) {
            flag = true;
        } else if (secondCheck) {
            word = word.substr(0, word.size() - 1);
            flag = true;
        } else if (thirdCheck) {
            word = word.substr(1, word.size());
            flag = true;
        }
        else if (forthCheck) {
            word = word.substr(1, word.size() - 2);
            flag = true;
        }

        // Если слово еще не разу не встречалось, оно добавляется в результирующую строку
        if ((resultString.find(word) == std::string::npos) && flag) {
            resultString.append(word + " ");
            flag = false;
        }
    }

    std::cout << "\nРезультат:\n" << resultString << "\n";
}

void TextAnalysis::readFromConsole() {
    std::cout << "Введите текст в консоль, завершив ввод знаком $: ";
    std::string text;
    // Считывание инфорамции из консоли и создание из этого потока
    std::getline(std::cin, text, '$');
    std::cin.ignore();
    std::stringstream stringStream(text);

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