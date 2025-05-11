#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// Importing Other Header Files
#include "Flight.h"
#include "ConsoleManipulation.h"
#include "User.h"
#include "FileHelper.h"
#include "Constants.h"
#include "AirlineException.h"
using namespace std;

// FLIGHT CLASS MEMBER FUNCTIONS
//==========================================================================================================

//SETTERS
Flight::Flight(string flightNumber, string origin, string destination, int hour, int minutes, int day, int month, int year, double distance, int seats)
    : flightNumber(flightNumber), flightorigin(origin), flightdestination(destination),
      flightTime(hour, minutes), flightDate(day, month, year), distanceInKms(distance), numOfSeatsInFlight(seats) {}

string Flight::getFlightNumber() const
{
    return flightNumber;
}

string Flight::getOrigin() const
{
    return flightorigin;
}

string Flight::getDestination() const
{
    return flightdestination;
}

// Time Flight::getTime() const
// {
//     return flightTime;
// }

// Date Flight::getDate() const
// {
//     return flightDate;
// }

int Flight::getMinutes() const { return flightTime.getMinutes(); }
int Flight::getHour() const { return flightTime.getHour(); }


string Flight::getTimeInString() const
{
    return to_string(flightTime.getHour()) + ":" + to_string(flightTime.getMinutes());
}

int Flight::getYear() const { return flightDate.getYear(); }
int Flight::getMonth() const { return flightDate.getMonth(); }
int Flight::getDay() const { return flightDate.getDay(); }

string Flight::getDateInString() const
{
    return to_string(flightDate.getDay()) + "/" + to_string(flightDate.getMonth()) + "/" + to_string(flightDate.getYear());
}


const vector<Customer> &Flight::getCustomers()const{
    return listOfCustomers;
}


//SETTERS
void Flight::setFlightNumber(string fn){flightNumber=fn;}
void Flight::setOrigin(string o){flightorigin=o;}
void Flight::setDestination(string d){flightdestination=d;}
void Flight::setflightTime(int t,int t1){
    flightTime.setHour(t);
    flightTime.setMinutes(t1);}

void Flight::setflightDate(int y,int m,int d){
    flightDate.setYear(y);
    flightDate.setMonth(m);
    flightDate.setDay(d);
}
void Flight::setDistance(double d){distanceInKms=d;} 
void Flight::setSeats(int s){numOfSeatsInFlight=s;}

void Flight::setCustomers(Customer &cust){
    listOfCustomers.push_back(cust);    }


// FRIEND FUNCTION(S)
//==========================================================================================================
ostream &operator<<(ostream &out, const Flight &flight)
{
    out << "Flight Number:  " << flight.flightNumber << endl;
    out << "city of Departure:  " << flight.flightorigin << endl;
    out << "city of Arrival:  " << flight.flightdestination << endl;
    out << "Flight Time: " << flight.flightTime.getHour() << ":" << flight.flightTime.getMinutes() << endl;
    out << "Flight Date:  " << flight.flightDate.getDay() << "/" << flight.flightDate.getMonth() << "/" << flight.flightDate.getYear() << endl;
    out << "Distance in KM:  " << flight.distanceInKms << endl;
    out << "Number of Seats Available:  " << flight.numOfSeatsInFlight << endl;
    return out;
}
//==========================================================================================================
