//
// Created by kolya on 11.10.2022.
//

#ifndef LAB2_TEXTANALYSIS_H
#define LAB2_TEXTANALYSIS_H

#include <fstream>
#include <sstream>
#include "../MyException.h"

class TextAnalysis {
private:
    static bool isVowel(char c);
    static void printingCorrectWords(std::iostream & stringStream);
    static bool ends_with(const std::string &value, const std::string &ending);
public:
    //static bool isPunctuationMark(char c);
    static void readFromConsole();
    static void readFromFile(std::string fileName);
};

#endif //LAB2_TEXTANALYSIS_H
