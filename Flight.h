

// Contains Flight Class

#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>
#include "User.h"
#include "DateAndTime.h"
using namespace std;
//testing commit through git by hasnain
//testing 2
class Customer;

class Flight
{
private:
    string flightNumber;      // unique identifier
    string flightorigin;      // from which city
    string flightdestination; // to which city
    Time flightTime;          // time for flight in hours
    Date flightDate;
    double distanceInKms;
    int numOfSeatsInFlight;

    vector<Customer> listOfCustomers;

public:
    Flight(string flightNumber = "", string origin = "", string destination = "", int hour = 0, int minutes = 0, int day = 0, int month = 0, int year = 0, double distance = 0, int seats = 0);

    string getFlightNumber() const;
    string getOrigin() const;
    string getDestination() const;

    // Time getTime() const;

    // Date getDate() const;

    int getMinutes() const;
    int getHour() const;
    string getTimeInString() const;

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    string getDateInString() const;

    const vector<Customer> &getCustomers() const;//added const
    void setCustomers(Customer &cust);//created setter

    vector<Customer> &getCustomers();
    void AddFlight(vector<Flight> &allflights);

    void RemoveFlight(vector<Flight> &allflights);
    friend ostream &operator<<(ostream &out, const Flight &flight);
};

#endif // FLIGHT_H
