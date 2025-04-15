#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// Importing Other Header Files
#include "Flight.h"
#include "ConsoleManipulation.h"
#include "User.h"
#include "Constants.h"

using namespace std;



// FLIGHT CLASS MEMBER FUNCTIONS
//==========================================================================================================

Flight::Flight(string flightNumber, string origin, string destination, string time, string date, double distance, int seats)
    : flightNumber(flightNumber), flightorigin(origin), flightdestination(destination),
      flightTime(time), flightDate(date), distanceInKms(distance), numOfSeatsInFlight(seats) {}

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

string Flight::getTime() const
{
    return flightTime;
}

string Flight::getDate() const
{
    return flightDate;
}

vector<Customer>& Flight::getCustomers()
{
    return listOfCustomers;
}

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
    cin >> flightTime;

    printLine(screenWidth, CYAN);
    // cout << "Enter Flight Date " << endl;
    printText("Enter Flight Date", screenWidth, WHITE, false);
    cin >> flightDate;

    printLine(screenWidth, CYAN);
    // cout << "Enter Distance in KM " << endl;
    printText("Enter Distance in KM", screenWidth, WHITE, false);
    cin >> distanceInKms;

    printLine(screenWidth, CYAN);
    // cout << "Enter Number of Seats Available " << endl;
    printText("Enter Number of Seats Available", screenWidth, WHITE, false);
    cin >> numOfSeatsInFlight;
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


//FRIEND FUNCTION(S)
//==========================================================================================================
ostream &operator<<(ostream &out, const Flight &flight)
{
    out << "Flight Number " << flight.flightNumber << endl;
    out << "city of Departure " << flight.flightorigin << endl;
    out << "city of Arrival " << flight.flightdestination << endl;
    out << "Flight Time " << flight.flightTime << endl;
    out << "Flight Date " << flight.flightDate << endl;
    out << "Distance in KM " << flight.distanceInKms << endl;
    out << "Number of Seats Available " << flight.numOfSeatsInFlight << endl;
    return out;
}
//==========================================================================================================