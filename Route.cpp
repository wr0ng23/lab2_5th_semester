//
// Created by kolya on 07.10.2022.
//

#include "Route.h"

const std::string &Route::getStartPointOfTheRoute() const {
    return startPointOfTheRoute;
}

void Route::setStartPointOfTheRoute(const std::string &startPointOfTheRoute) {
    Route::startPointOfTheRoute = startPointOfTheRoute;
}

const std::string &Route::getFinalPointOfTheRoute() const {
    return finalPointOfTheRoute;
}

void Route::setFinalPointOfTheRoute(const std::string &finalPointOfTheRoute) {
    Route::finalPointOfTheRoute = finalPointOfTheRoute;
}

int Route::getNumberOfRoute() const {
    return numberOfRoute;
}

void Route::setNumberOfRoute(int numberOfRoute) {
    Route::numberOfRoute = numberOfRoute;
}

std::ostream &operator<<(std::ostream &os, const Route &route) {
    os << "\nstartPointOfTheRoute: " << route.startPointOfTheRoute << "\nfinalPointOfTheRoute: "
       << route.finalPointOfTheRoute << "\nnumberOfRoute: " << route.numberOfRoute << "\n\n";
    return os;
}

std::istream& operator>> (std::istream& is, Route &route) {
    std::cout << "Название начального пункта маршрута:\n";
    route.setStartPointOfTheRoute(input<std::string>());

    std::cout << "Название конечного пункта маршрута:\n";
    route.setFinalPointOfTheRoute(input<std::string>());

    std::cout << "Номер маршрута:\n";
    route.setNumberOfRoute(input<int>());

    return is;
}

Route::Route() {
    std::cout << "Вызван конструктор без параметров класса Route\n";
    startPointOfTheRoute = "";
    finalPointOfTheRoute = "";
    numberOfRoute = 0;
}

Route::Route(std::string startPointOfTheRoute, std::string finalPointOfTheRoute, int numberOfRoute) {
    std::cout << "Вызван конструктор с параметрами класса Route\n";
    this->startPointOfTheRoute = startPointOfTheRoute;
    this->finalPointOfTheRoute = finalPointOfTheRoute;
    this->numberOfRoute = numberOfRoute;
}

Route::~Route() {
    std::cout << "Вызван деструктор класса Route\n";
};
