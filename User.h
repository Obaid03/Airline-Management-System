
//Contains User Class

#ifndef USER_H
#define USER_H
#include "Flight.h"
#include <vector>
using namespace std;



class User {
private:
    string userID;
    string userName;
    string userEmail;
    string userPassword;
    static int noOfUsers;

public:
    User(string userID, string userName, string userEmail, string userPassword) : userID(userID), userName(userName), userEmail(userEmail), userPassword(userPassword) {
        this->userID = ++noOfUsers;
    };
    
    bool verifyCredential(const string& email, const string& password) {
        return(userEmail==email && userPassword==password);
    }

    void setUserName(const string& name) {userName = name;}
    void setUserEmail(const string& email) {userEmail = email;}
    void setUserPassword(const string& password) {userPassword = password;}

    string getUserName() const {return userEmail;}
    string getUserEmail() const {return userEmail;}
    string getUserPassword() const {return userPassword;}
};



class Admin : public User {
private:
    static int noOfAdmins;

public:
Admin(string userID="", string userName="", string userEmail="", string userPassword="") : User(userID,userName,userEmail,userPassword) {
    noOfAdmins++;
}
   

    void addNewFlight(vector<Flight>& flights, Flight& newFlightToAdd) {
        flights.push_back(newFlightToAdd);
    }

    void removeFlight() {

    }

    void listAllFlights() {

    }

    void listAllCustomers() {

    }
};


class Customer : public User {
private:
    static int noOfCustomers;

    vector<Flight> flightsBookedByCustomer;
    int noOfBookedFlights = flightsBookedByCustomer.size();


public:
    Customer(string userID="", string userName="", string userEmail="", string userPassword="") : User(userID,userName,userEmail,userPassword) , flightsBookedByCustomer(0) {
        noOfCustomers++;
    }

    void editInformation() {

    }


    void displayData() {

    }

    void bookNewFlight() {

    }

    void removeFlightFromBooking() {

    }

    //when booking is confirmed
    void addNewFlight() {

    }

    void removeFlight() {

    }



};

int Customer::noOfCustomers = 0;
int Admin::noOfAdmins = 0;
int User::noOfUsers = 0;

#endif //USER_H
