
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
        this->userID = noOfUsers++;
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

int User::noOfUsers = 0;

class Admin : public User {
private:

public:
Admin(string userID="", string userName="", string userEmail="", string userPassword="") : User(userID,userName,userEmail,userPassword) {}
   

    void addNewFlight() {

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
    vector<Flight> flightsRegisteredByUser;
    int noOfFlights = flightsRegisteredByUser.size();

    vector<Flight> flightsBookedByUser;
    int noOfBookedFlights = flightsBookedByUser.size();


public:
    Customer(string userID="", string userName="", string userEmail="", string userPassword="") : User(userID,userName,userEmail,userPassword) , flightsRegisteredByUser(0) {
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

#endif //USER_H
