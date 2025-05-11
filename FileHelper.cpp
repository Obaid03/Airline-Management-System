#include "FileHelper.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileHelper::saveFlights(const vector<Flight> &flights, const string &filename)
{
    ofstream outFile(filename);

    // Write header line
    outFile << "FlightNumber,Origin,Destination,Hour,Minute,Day,Month,Year,Distance,Seats\n";

    for (const auto &f : flights)
    {
        outFile << f.getFlightNumber() << ","
                << f.getOrigin() << ","
                << f.getDestination() << ","
                << f.getHour() << "," << f.getMinutes() << ","
                << f.getDay() << "," << f.getMonth() << "," << f.getYear() << ","
                << f.getDistance() << ","
                << f.getSeats() << "\n";
    }
    outFile.close();
}

vector<Flight> FileHelper::loadFlights(const string &filename)
{
    vector<Flight> flights;
    ifstream inFile(filename);
    string line;

    // Skip header line
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string flightNumber, origin, destination;
        int hour, minute, day, month, year;
        double distance;
        int seats;

        getline(ss, flightNumber, ',');
        getline(ss, origin, ',');
        getline(ss, destination, ',');
        ss >> hour;
        ss.ignore();
        ss >> minute;
        ss.ignore();
        ss >> day;
        ss.ignore();
        ss >> month;
        ss.ignore();
        ss >> year;
        ss.ignore();
        ss >> distance;
        ss.ignore();
        ss >> seats;

        flights.emplace_back(flightNumber, origin, destination, hour, minute, day, month, year, distance, seats);
    }
    inFile.close();
    return flights;
}

void FileHelper::saveAdmins(const vector<Admin> &admins, const string &filename)
{
    ofstream outFile(filename);

    // Write header line
    outFile << "UserName,Email,Password\n";

    for (const auto &admin : admins)
    {
        outFile << admin.getUserName() << ","
                << admin.getUserEmail() << ","
                << admin.getUserPassword() << "\n"; // Removed trailing comma
    }
    outFile.close();
}

vector<Admin> FileHelper::loadAdmins(const string &filename)
{
    vector<Admin> admins;
    ifstream inFile(filename);
    string line;

    // Skip header line
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string name, email, password;
        string userID = "0"; // Default userID since it's not in the file

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, password); // Get to the end of line without delimiter

        admins.emplace_back(userID, name, email, password); // Constructor order: userID, name, email, password
    }
    inFile.close();
    return admins;
}

void FileHelper::saveCustomers(const vector<Customer> &customers, const string &filename)
{
    ofstream outFile(filename);
    // cout << "Save Customers Called" << endl;

    outFile << "UserName,Email,Password,BookedFlights\n";

    for (const auto &customer : customers)
    {
        outFile << customer.getUserName() << ","
                << customer.getUserEmail() << ","
                << customer.getUserPassword() << ",";

        // Write booked flight numbers separated by '|'
        vector<Flight> flights = customer.getFlightsBooked();
        for (size_t i = 0; i < flights.size(); ++i) {
            cout << flights[i].getFlightNumber() << endl;
            outFile << flights[i].getFlightNumber();
            if (i != flights.size() - 1)
                outFile << "|";
        }
        outFile << "\n";
        // debug lines:
        // vector<Flight> flights = customer.getFlightsBooked();
        // // cout << "Debug - Number of flights: " << flights.size() << endl;

        // // If size is greater than 0, check first flight
        // if (flights.size() > 0)
        // {
        //     cout << "Debug - First flight number: " << flights[0].getFlightNumber() << endl;
        // }

        // // Then proceed with your loop
        // for (size_t i = 0; i < flights.size(); ++i)
        // {
        //     cout << "Debug - Processing flight " << i << ": " << flights[i].getFlightNumber() << endl;
        //     outFile << flights[i].getFlightNumber();
        //     if (i != flights.size() - 1)
        //         outFile << "|";
        // }
        
    }
    outFile.close();
}

vector<Customer> FileHelper::loadCustomers(const string &filename, const vector<Flight> &allFlights)
{
    vector<Customer> customers;
    ifstream inFile(filename);
    string line;

    // Skip header line
    getline(inFile, line);

    while (getline(inFile, line))
    {
        stringstream ss(line);
        string name, email, password, bookedFlightsStr;
        string userID = "0"; // Default userID since it's not in the file

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, bookedFlightsStr); // Get the rest of the line

        Customer cust(userID, name, email, password);

        // Only process flight bookings if there's data
        if (!bookedFlightsStr.empty())
        {
            stringstream flightStream(bookedFlightsStr);
            string flightNum;
            while (getline(flightStream, flightNum, '|'))
            {
                if (!flightNum.empty())
                { // Skip empty flight numbers
                    for (const auto &f : allFlights)
                    {
                        if (f.getFlightNumber() == flightNum)
                        {
                            cust.setBookedFlight(f);
                            break;
                        }
                    }
                }
            }
        }

        customers.push_back(cust);
    }
    inFile.close();
    return customers;
}