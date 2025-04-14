

// Contains Flight Class

#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>
#include "ConsoleManipulation.h"
using namespace std;
const int screenWidtha = 100;

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"

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
    Flight() {}

    Flight(string flightNumber, string origin, string destination, string time, string date, double distance, int seats)
        : flightNumber(flightNumber), flightorigin(origin), flightdestination(destination),
          flightTime(time), flightDate(date), distanceInKms(distance), numOfSeatsInFlight(seats) {}

    string getFlightNumber() const
    {
        return flightNumber;
    }

    string getOrigin() const
    {
        return flightorigin;
    }

    string getDestination() const
    {
        return flightdestination;
    }

    string getTime() const
    {
        return flightTime;
    }

    string getDate() const
    {
        return flightDate;
    }

    vector<Customer> &getCustomers()
    {
        return listOfCustomers;
    }

    void AddFlight(vector<Flight> &allflights)
    {
        // Existing flight numbers
        // cout << "\nCurrent Flights:\n";
        printLine(screenWidtha, CYAN);
        printText("Current Flights:", screenWidtha, CYAN, false);

        for (const Flight &flight : allflights)
        {
            // cout << "Flight Number -->" << flight.getFlightNumber() << "\n";
            printText("Flight Number -->" + flight.getFlightNumber(), screenWidtha, WHITE, false);
        }
        printLine(screenWidtha, CYAN);

        while (true)
        {
            int flag = 0;
            string fn;
            // cout << CYAN << "\nEnter Flight Number to add (or '0' to cancel): " << RESET;
            printText("Enter Flight Number to add (or '0' to cancel):", screenWidtha, CYAN, false);
            cin >> fn;

            // Cancelling
            if (fn == "0")
            {
                printLine(screenWidtha, CYAN);
                // cout << RED << "Cancelled flight Adding.\n" << RESET;
                printText("Cancelled flight Adding.", screenWidtha, RED, true);
                printLine(screenWidtha, CYAN);
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
            printLine(screenWidtha, CYAN);
            // cout << RED << "Invalid Flight Number! Try again.\n" << RESET;
            printText("Invalid Flight Number! Try again.", screenWidtha, RED, true);
            printLine(screenWidtha, CYAN);
        }

        // cout << "Enter city of Departure " << endl;
        printLine(screenWidtha, CYAN);
        printText("Enter city of Departure", screenWidtha, WHITE, false);
        cin >> flightorigin;

        printLine(screenWidtha, CYAN);
        // cout << "Enter city of Arrival " << endl;
        printText("Enter city of Arrival", screenWidtha, WHITE, false);
        cin >> flightdestination;

        printLine(screenWidtha, CYAN);
        // cout << "Enter Flight Time " << endl;
        printText("Enter Flight Time", screenWidtha, WHITE, false);
        cin >> flightTime;

        printLine(screenWidtha, CYAN);
        // cout << "Enter Flight Date " << endl;
        printText("Enter Flight Date", screenWidtha, WHITE, false);
        cin >> flightDate;

        printLine(screenWidtha, CYAN);
        // cout << "Enter Distance in KM " << endl;
        printText("Enter Distance in KM", screenWidtha, WHITE, false);
        cin >> distanceInKms;

        printLine(screenWidtha, CYAN);
        // cout << "Enter Number of Seats Available " << endl;
        printText("Enter Number of Seats Available", screenWidtha, WHITE, false);
        cin >> numOfSeatsInFlight;
    }

    void RemoveFlight(vector<Flight> &allflights)
    {
        string fn;
        int found = 0;

        // Existing flight numbers
        printText("Current Flights:", screenWidtha, CYAN, false);
        for (const Flight &flight : allflights)
        {
            printText("Flight Number -->" + flight.getFlightNumber(), screenWidtha, WHITE, false);
        }

        while (true)
        {
            printText("Enter Flight Number to remove (or '0' to cancel):", screenWidtha, CYAN, false);
            cin >> fn;

            // Cancelling
            if (fn == "0")
            {
                printText("Cancelled flight removal.", screenWidtha, RED, false);
                return;
            }

            // Finding flight
            for (auto itr = allflights.begin(); itr != allflights.end(); ++itr)
            {
                if ((itr->getFlightNumber()) == fn)
                {
                    allflights.erase(itr);
                    printText("Flight Number" + fn + " removed successfully!", screenWidtha, RED, false);
                    found = 1;
                    break;
                }
            }

            if (found)
                break;

            printText("Invalid Flight Number! Try again.", screenWidtha, RED, false);
        }
    }

    friend ostream &operator<<(ostream &out, const Flight &flight);
};

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

#endif // FLIGHT_H
