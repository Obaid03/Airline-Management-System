#ifndef FILEHELPER_H
#define FILEHELPER_H

#include <vector>
#include <string>
#include "Flight.h"
#include "User.h"

using namespace std;

class FileHelper {
public:
    // === FLIGHT ===
    static void saveFlights(const vector<Flight>& flights, const string& filename);
    static vector<Flight> loadFlights(const string& filename);

    // === ADMIN ===
    static void saveAdmins(const vector<Admin>& admins, const string& filename);
    static vector<Admin> loadAdmins(const string& filename);

    // === CUSTOMER ===
    static void saveCustomers(const vector<Customer>& customers, const string& filename);
    static vector<Customer> loadCustomers(const string& filename, const vector<Flight>& allFlights); // needs flights to link booked ones
};

#endif // FILEHELPER_H
