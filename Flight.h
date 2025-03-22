//
// Created by muhammad-ibrahim on 3/23/25.
//

#ifndef FLIGHT_H
#define FLIGHT_H


class Flight {
private:
    std::string flightName;

public:
    Flight(std::string strname) : flightName(strname) {
    };

    void display() const {
        std::cout << "Flight " << flightName << std::endl;
    };
};


#endif //FLIGHT_H
