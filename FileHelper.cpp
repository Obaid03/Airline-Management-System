#include "FileHelper.h"
#include <fstream>
#include <sstream>
#include <iostream>

void FileHelper::saveFlights(const vector<Flight>& flights, const string& filename) {
    ofstream outFile(filename);
    for (const auto& f : flights) {
        outFile << f.getFlightNumber() << ","
                << f.getOrigin() << ","
                << f.getDestination() << ","
                << f.getHour() << "," << f.getMinutes() << ","
                << f.getDay() << "," << f.getMonth() << "," << f.getYear() << ","
                << f.getCustomers().size() << ","  // placeholder for actual customer count
                << f.getCustomers().size() << ","  // can adjust or remove
                << "\n";
    }
    outFile.close();
}

vector<Flight> FileHelper::loadFlights(const string& filename) {
    vector<Flight> flights;
    ifstream inFile(filename);
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string flightNumber, origin, destination;
        int hour, minute, day, month, year;
        double distance;
        int seats;

        getline(ss, flightNumber, ',');
        getline(ss, origin, ',');
        getline(ss, destination, ',');
        ss >> hour; ss.ignore();
        ss >> minute; ss.ignore();
        ss >> day; ss.ignore();
        ss >> month; ss.ignore();
        ss >> year; ss.ignore();
        ss >> distance; ss.ignore();
        ss >> seats;

        flights.emplace_back(flightNumber, origin, destination, hour, minute, day, month, year, distance, seats);
    }
    inFile.close();
    return flights;
}

void FileHelper::saveAdmins(const vector<Admin>& admins, const string& filename) {
    ofstream outFile(filename);
    for (const auto& admin : admins) {
        outFile << admin.getUserName() << ","
                << admin.getUserEmail() << ","
                << admin.getUserPassword() << ","
                << admin.getUserID() << "\n";
    }
    outFile.close();
}

vector<Admin> FileHelper::loadAdmins(const string& filename) {
    vector<Admin> admins;
    ifstream inFile(filename);
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, email, password, userID;

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, userID, ',');

        admins.emplace_back(userID, name, email, password);
    }
    inFile.close();
    return admins;
}

void FileHelper::saveCustomers(const vector<Customer>& customers, const string& filename) {
    ofstream outFile(filename);
    for (const auto& customer : customers) {
        outFile << customer.getUserName() << ","
                << customer.getUserEmail() << ","
                << customer.getUserPassword() << ","
                << customer.getUserID() << ",";

        // Write booked flight numbers separated by '|'
        const auto& flights = customer.getFlightsBooked(); // you must implement this
        for (size_t i = 0; i < flights.size(); ++i) {
            outFile << flights[i].getFlightNumber();
            if (i != flights.size() - 1)
                outFile << "|";
        }
        outFile << "\n";
    }
    outFile.close();
}

vector<Customer> FileHelper::loadCustomers(const string& filename, const vector<Flight>& allFlights) {
    vector<Customer> customers;
    ifstream inFile(filename);
    string line;

    while (getline(inFile, line)) {
        stringstream ss(line);
        string name, email, password, userID, bookedFlightsStr;

        getline(ss, name, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, userID, ',');
        getline(ss, bookedFlightsStr);

        Customer cust(userID, name, email, password);

        stringstream flightStream(bookedFlightsStr);
        string flightNum;
        while (getline(flightStream, flightNum, '|')) {
            for (const auto& f : allFlights) {
                if (f.getFlightNumber() == flightNum) {
                    cust.setBookedFlight(f); // you must implement this
                    break;
                }
            }
        }

        customers.push_back(cust);
    }
    inFile.close();
    return customers;
}
