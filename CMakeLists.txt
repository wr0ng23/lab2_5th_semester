cmake_minimum_required(VERSION 3.23)
project(lab2)

set(CMAKE_CXX_STANDARD 20)

add_executable(lab2 main.cpp firstEx/Route.cpp firstEx/Route.h safeInput.h firstEx/List.cpp firstEx/List.h firstEx/Element.cpp firstEx/Element.h MyException.cpp MyException.h secondEx/TextAnalysis.cpp secondEx/TextAnalysis.h Menu.cpp Menu.h checkingAccuracyOfTheInput.cpp checkingAccuracyOfTheInput.h)
