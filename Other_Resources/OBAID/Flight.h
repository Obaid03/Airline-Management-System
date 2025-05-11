// Contains Flight Class
#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>
#include "User.h"
#include "DateAndTime.h"
using namespace std;

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
    //SETTERS
    void setFlightNumber(string fn);
    void setOrigin(string o);
    void setDestination(string t);
    void setflightTime(int t,int t1);
    void setflightDate(int y,int m,int d);
    void setDistance(double d);
    void setSeats(int s);
    void setCustomers(Customer &cust);
    // void setOrigin(string o);
    // void setDestination(string t);
    // void setflightTime(int t,int t1);


    //GETTERS
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
    const vector<Customer> &getCustomers()const;

    // void AddFlight(vector<Flight> &allflights);
    // void RemoveFlight(vector<Flight> &allflights);
    
    friend ostream &operator<<(ostream &out, const Flight &flight);
};

#endif // FLIGHT_H
