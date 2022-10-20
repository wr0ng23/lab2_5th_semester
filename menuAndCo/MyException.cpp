//
// Created by kolya on 11.10.2022.
//

#include "MyException.h"

MyException::MyException(const std::string& error) : message_of_error_(error) {}

std::string MyException::get_error() const {
    return message_of_error_;
}