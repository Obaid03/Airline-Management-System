

// Contains Flight Class

#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>
using namespace std;


class Customer;

class Flight
{
private:
    string flightNumber;      // unique identifier
    string flightorigin;      // from which city
    string flightdestination; // to which city
    string flightTime;        // time for flight in hours
    string flightDate;
    double distanceInKms;
    int numOfSeatsInFlight;

    vector<Customer> listOfCustomers;

public:
    Flight(string flightNumber = "", string origin = "", string destination = "", string time = 0, string date = 0, double distance = 0, int seats = 0);
       
    string getFlightNumber() const;

    string getOrigin() const;

    string getDestination() const;

    string getTime() const;

    string getDate() const;

    vector<Customer> &getCustomers();
    void AddFlight(vector<Flight> &allflights);

    void RemoveFlight(vector<Flight> &allflights);
    friend ostream &operator<<(ostream &out, const Flight &flight);
};

#endif // FLIGHT_H
