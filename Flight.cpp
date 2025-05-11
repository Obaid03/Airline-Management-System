#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
#include "AirlineException.h"
// Importing Other Header Files
#include "Flight.h"
#include "ConsoleManipulation.h"
#include "User.h"
#include "Constants.h"

using namespace std;

// FLIGHT CLASS MEMBER FUNCTIONS
//==========================================================================================================

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

const vector<Customer> &Flight::getCustomers() const
{
    return listOfCustomers;
}

void Flight::setCustomers(Customer &cust){//setter
    listOfCustomers.push_back(cust);    }



void Flight::AddFlight(vector<Flight> &allflights)
{
    
        // Existing flight numbers
        // cout << "\nCurrent Flights:\n";
        printLine(screenWidth, CYAN);
        printText("Current Flights:", screenWidth, CYAN, false);
    
        for (const Flight &flight : allflights)
        {
            // cout << "Flight Number -->" << flight.getFlightNumber() << "\n";
            printText("Flight Number -->" + flight.getFlightNumber(), screenWidth, WHITE, false);
        }
        printLine(screenWidth, CYAN);
    
        while (true)
        {
            int flag = 0;
            string fn;
            // cout << CYAN << "\nEnter Flight Number to add (or '0' to cancel): " << RESET;
            printText("Enter Flight Number to add (or '0' to cancel):", screenWidth, CYAN, false);
            cin >> fn;
    
            // Cancelling
            if (fn == "0")
            {
                printLine(screenWidth, CYAN);
                // cout << RED << "Cancelled flight Adding.\n" << RESET;
                printText("Cancelled flight Adding.", screenWidth, RED, true);
                printLine(screenWidth, CYAN);
                return;
            }
    
            for (const Flight &flight : allflights)
            {
                if (flight.getFlightNumber() == fn)
                {
                    // cout << "Flight number already exists! Try again." << endl;
                    flag = 1;
                    break;
                }
            }
    
            if (!flag)
            {
                flightNumber = fn;
                break;
            }
            printLine(screenWidth, CYAN);
            // cout << RED << "Invalid Flight Number! Try again.\n" << RESET;
            printText("Invalid Flight Number! Try again.", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }
    
        int temp; // used for dates and times
        // cout << "Enter city of Departure " << endl;
        printLine(screenWidth, CYAN);
        printText("Enter city of Departure", screenWidth, WHITE, false);
        cin >> flightorigin;
    
        printLine(screenWidth, CYAN);
        // cout << "Enter city of Arrival " << endl;
        printText("Enter city of Arrival", screenWidth, WHITE, false);
        cin >> flightdestination;
    
        printLine(screenWidth, CYAN);
        // cout << "Enter Flight Time " << endl;
        printText("Enter Flight Time", screenWidth, WHITE, false);
        printText("Hour", screenWidth, WHITE, false);
           temp= getValidIntInput(1,12);
            //cin >> temp;
            flightTime.setHour(temp);
            printText("Minutes", screenWidth, WHITE, false);
            //cin >> temp;
            temp= getValidIntInput(1,60);
            flightTime.setMinutes(temp);
        
            printLine(screenWidth, CYAN);
            // cout << "Enter Flight Date " << endl;
            printText("Enter Flight Date", screenWidth, WHITE, false);
            printText("Year", screenWidth, WHITE, false);
            temp= getValidIntInput(2025,3000);
            //cin >> temp;
            flightDate.setYear(temp);
            printText("Month", screenWidth, WHITE, false);
            temp= getValidIntInput(1,12);
            //cin >> temp;
            flightDate.setMonth(temp);
            printText("Day", screenWidth, WHITE, false);
            temp= getValidIntInput(1,30);
           // cin >> temp;
            flightDate.setDay(temp);
        
            printLine(screenWidth, CYAN);
            // cout << "Enter Distance in KM " << endl;
            printText("Enter Distance in KM", screenWidth, WHITE, false);
            distanceInKms= getValidIntInput(1,5000);
            ///cin >> distanceInKms;
        
            printLine(screenWidth, CYAN);
            // cout << "Enter Number of Seats Available " << endl;
            printText("Enter Number of Seats Available", screenWidth, WHITE, false);
            numOfSeatsInFlight= getValidIntInput(1,500);
           // cin >> numOfSeatsInFlight;
        
    
}

void Flight::RemoveFlight(vector<Flight> &allflights)
{
    string fn;
    int found = 0;

    // Existing flight numbers
    printText("Current Flights:", screenWidth, CYAN, false);
    for (const Flight &flight : allflights)
    {
        printText("Flight Number -->" + flight.getFlightNumber(), screenWidth, WHITE, false);
    }

    while (true)
    {
        printText("Enter Flight Number to remove (or '0' to cancel):", screenWidth, CYAN, false);
        cin >> fn;

        // Cancelling
        if (fn == "0")
        {
            printText("Cancelled flight removal.", screenWidth, RED, false);
            return;
        }

        // Finding flight
        for (auto itr = allflights.begin(); itr != allflights.end(); ++itr)
        {
            if ((itr->getFlightNumber()) == fn)
            {
                allflights.erase(itr);
                printText("Flight Number" + fn + " removed successfully!", screenWidth, RED, false);
                found = 1;
                break;
            }
        }

        if (found)
            break;

        printText("Invalid Flight Number! Try again.", screenWidth, RED, false);
    }
}

//==========================================================================================================

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