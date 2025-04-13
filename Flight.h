

// Contains Flight Class

#ifndef FLIGHT_H
#define FLIGHT_H
#include <vector>
#include <iostream>
using namespace std;

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
        // existing flight numbers
        cout << "\nCurrent Flights:\n";
        for (const Flight &flight : allflights)
        {
            cout << "Flight Number -->" << flight.getFlightNumber() << "\n";
        }
        while (true)
        {
            int flag = 0;
            string fn;
            cout << CYAN << "\nEnter Flight Number to add (or '0' to cancel): " << RESET;
            cin >> fn;

            // cancelling
            if (fn == "0")
            {
                cout << RED << "Cancelled flight Adding.\n"
                     << RESET;
                return;
            }
            for (const Flight &flight : allflights)
            {
                if (flight.getFlightNumber() == fn)
                {
                    // cout << "Flight number already exists! Try again."<< endl;
                    flag = 1;
                    break;
                }
                else
                {
                    flag = 0;
                    continue;
                }
            }
            if (!flag)
            {
                flightNumber = fn;
                break;
            }
            cout << RED << "Invalid Flight Number! Try again.\n"
                 << RESET;
        }

        cout << "Enter city of Departure " << endl;
        cin >> flightorigin;
        cout << "Enter city of Arrival " << endl;
        cin >> flightdestination;
        cout << "Enter Flight Time " << endl;
        cin >> flightTime;
        cout << "Enter Flight Date " << endl;
        cin >> flightDate;
        cout << "Enter Distance in KM " << endl;
        cin >> distanceInKms;
        cout << "Enter Number of Seats Available " << endl;
        cin >> numOfSeatsInFlight;
    }
    void RemoveFlight(vector<Flight> &allflights)
    {
        string fn;
        int found = 0;

        // existing flight numbers
        cout << "\nCurrent Flights:\n";
        for (const Flight &flight : allflights)
        {
            cout << "Flight Number -->" << flight.getFlightNumber() << "\n";
        }

        while (true)
        {
            cout << "\nEnter Flight Number to remove (or '0' to cancel): ";
            cin >> fn;

            // cancelling
            if (fn == "0")
            {
                cout << "Cancelled flight removal.\n";
                return;
            }

            // finding  flight
            for (auto itr = allflights.begin(); itr != allflights.end(); ++itr)
            {
                if ((itr->getFlightNumber()) == fn)
                {
                    allflights.erase(itr);
                    cout << RED << "Flight Number" << fn << " removed successfully!\n"
                         << RESET;
                    found = 1;
                    break;
                }
            }

            if (found)
                break;

            cout << RED << "Invalid Flight Number! Try again.\n"
                 << RESET;
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
