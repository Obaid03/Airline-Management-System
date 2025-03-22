//
// Created by muhammad-ibrahim on 3/23/25.
//

#ifndef FLIGHT_H
#define FLIGHT_H
using namespace std;

class Flight {
private:
    std::string flightName;

public:
    Flight(string strname) : flightName(strname) {
    };

    void display() const {
        cout << "Flight " << flightName << endl;
    };
};


#endif //FLIGHT_H
