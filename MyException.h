//
// Created by kolya on 11.10.2022.
//

#ifndef LAB2_MYEXCEPTION_H
#define LAB2_MYEXCEPTION_H


#include <exception>
#include <iostream>

class MyException : public std::exception {
private:
    std::string message_of_error_;
public:
    explicit MyException(const std::string& error);

    [[nodiscard]] bool is_critical_error() const;

    [[nodiscard]] std::string get_error() const;
};


#endif //LAB2_MYEXCEPTION_H
