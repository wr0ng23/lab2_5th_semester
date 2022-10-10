//
// Created by kolya on 07.10.2022.
//

#ifndef LAB2_ROUTE_H
#define LAB2_ROUTE_H
#include "safeInput.h"

class Route {
private:
    std::string startPointOfTheRoute;
    std::string finalPointOfTheRoute;
    int numberOfRoute;
public:
    Route();

    Route(std::string startPointOfTheRoute, std::string finalPointOfTheRoute, int numberOfRoute);

    ~Route();

    friend std::ostream &operator<<(std::ostream &os, const Route &route);

    friend std::istream& operator>> (std::istream& is, Route &route);

    [[nodiscard]] const std::string &getStartPointOfTheRoute() const;

    void setStartPointOfTheRoute(const std::string &startPointOfTheRoute);

    [[nodiscard]] const std::string &getFinalPointOfTheRoute() const;

    void setFinalPointOfTheRoute(const std::string &finalPointOfTheRoute);

    [[nodiscard]] int getNumberOfRoute() const;

    void setNumberOfRoute(int numberOfRoute);
};


#endif //LAB2_ROUTE_H
