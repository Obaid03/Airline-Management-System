//
// Created by muhammad-ibrahim on 3/23/25.
//

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

public:
    User(string userID, string userName, string userEmail, string userPassword) : userID(userID), userName(userName), userEmail(userEmail), userPassword(userPassword) {};
    

};



class Admin : public User {
private:

public:
Admin(string userID, string userName, string userEmail, string userPassword) : User(userID,userName,userEmail,userPassword) {}
   

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
public:
    static int noOfCustomers;
    vector<Flight> flightsRegisteredByUser;
    int noOfFlights = flightsRegisteredByUser.size();

    vector<Flight> flightsBookedByUser;
    int noOfBookedFlights = flightsBookedByUser.size();


private:
    Customer(string userID, string userName, string userEmail, string userPassword) : User(userID,userName,userEmail,userPassword) , flightsRegisteredByUser(NULL) {
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
