

//Contains Flight Class

#ifndef FLIGHT_H
#define FLIGHT_H
#include<vector>
using namespace std;

class Customer;
class Flight {
private:
    int flightNumber;//unique identifier
    string departure;//from which city
    string destination;//to which city
    float flightTime;//time for flight in hours
    double distanceInKms;
    int numOfSeatsInFlight;

    vector<Customer> listOfCustomers;

public:
};


#endif //FLIGHT_H
