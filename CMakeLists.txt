cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp firstEx/Route.cpp firstEx/Route.h menuAndCo/safeInput.h firstEx/List.cpp firstEx/List.h firstEx/Element.cpp firstEx/Element.h menuAndCo/MyException.cpp menuAndCo/MyException.h secondEx/TextAnalysis.cpp secondEx/TextAnalysis.h menuAndCo/Menu.cpp menuAndCo/Menu.h menuAndCo/checkingAccuracyOfTheInput.cpp menuAndCo/checkingAccuracyOfTheInput.h)
