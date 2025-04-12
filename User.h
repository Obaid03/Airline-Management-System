
// Contains User Class

#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include "Flight.h"
#include <conio.h>
#define YELLOW "\033[33m" /* Yellow */
#define RESET "\033[0m"
using namespace std;

class User
{
private:
    string userID;
    string userName;
    string userEmail;
    string userPassword;
    static int noOfUsers;

public:
    User(string userID, string userName, string userEmail, string userPassword) : userID(userID), userName(userName), userEmail(userEmail), userPassword(userPassword)
    {
        this->userID = ++noOfUsers;
    };

    bool verifyCredential(const string &email, const string &password)
    {
        return (userEmail == email && userPassword == password);
    }

    virtual void userPanel() = 0;

    void editInformation()
    {
        cout << "will d";
    }

    void setUserName(const string &name) { userName = name; }
    void setUserEmail(const string &email) { userEmail = email; }
    void setUserPassword(const string &password) { userPassword = password; }

    string getUserName() const { return userName; }
    string getUserEmail() const { return userEmail; }
    string getUserPassword() const { return userPassword; }
};

class Admin : public User
{
private:
    static int noOfAdmins;

public:
    Admin(string userID = "", string userName = "", string userEmail = "", string userPassword = "") : User(userID, userName, userEmail, userPassword)
    {
        noOfAdmins++;
    }

    void addNewFlight(vector<Flight> &flights, Flight &newFlightToAdd)
    {
        flights.push_back(newFlightToAdd);
    }

    void removeFlight()
    {
    }

    void listAllFlights()
    {
    }

    void listAllCustomers()
    {
    }

    void userPanel() override
    {
        system("cls");

        int choice = 0;
        int key; 
        int maxChoices = 5;
        bool exit = false;
        do
        {
            system("cls");
            cout << "Admin Control Panel" << endl;
            cout << "======================" << endl;
            cout << "Hello, " << getUserName() << endl << "\n";
            if (choice == 0)
                cout << YELLOW ">";
            cout << "1.Edit Information" << RESET << endl;
            if (choice == 1)
                cout << YELLOW ">";
            cout << "2.Add New Flight" << RESET << endl;
            if (choice == 2)
                cout << YELLOW ">";
            cout << "3.Remove Flight" << RESET << endl;
            if (choice == 3)
                cout << YELLOW ">";
            cout << "4.List All Flights" << RESET << endl;
            if (choice == 4)
                cout << YELLOW ">";
            cout << "5.List All Customers" << RESET << endl;
            if (choice == 5)
                cout << YELLOW ">";
            cout << "6.Exit" << RESET << endl;
            // update maxChoices if adding another menu item

            key = _getch();

            if ((key == 'w' || key == 'W' || key == 72) && (choice > 0))
            {
                choice--;
                // cout << "W";
            }
            else if ((key == 's' || key == 'S' || key == 80) && (choice < maxChoices))
            {
                choice++;
                // cout << "S";
            }
            else if (key == '\r' || key == ' ')
            {
                switch (choice)
                {
                case 0:
                    editInformation();
                    break;
                case 1: // new FLight
                    // addNewFlight();
                    break;
                case 2: // remove flight
                    removeFlight();
                case 3: // list all flights
                    listAllFlights();
                    break;
                case 4:
                    listAllCustomers();
                    break;
                case 5:
                    exit = true;
                    break;
                default:

                    break;
                }
            }
            else
            {
                cout << "error" << endl;
            }

        } while (exit == false);
    }
};

class Customer : public User
{
private:
    static int noOfCustomers;

    vector<Flight> flightsBookedByCustomer;
    int noOfBookedFlights = flightsBookedByCustomer.size();

public:
    Customer(string userID = "", string userName = "", string userEmail = "", string userPassword = "") : User(userID, userName, userEmail, userPassword), flightsBookedByCustomer(0)
    {
        noOfCustomers++;
    }

    void editInformation()
    {
    }

    void displayData()
    {
    }

    void bookNewFlight()
    {
    }

    void removeFlight()
    {
    }

    void userPanel() override
    {
        system("cls");

        int choice = 0;
        int key = 0;
        int maxChoices = 4;
        bool exit = false;
        do
        {
            system("cls");
            cout << "Customer Control Panel" << endl;
            cout << "======================" << endl;
            cout << "Hello, " << getUserName() << endl
                 << "\n";
            if (choice == 0)
                cout << YELLOW ">";
            cout << "1.Edit Information" << RESET << endl;
            if (choice == 1)
                cout << YELLOW ">";
            cout << "2.Display Data" << RESET << endl;
            if (choice == 2)
                cout << YELLOW ">";
            cout << "3.Book New Flight" << RESET << endl;
            if (choice == 3)
                cout << YELLOW ">";
            cout << "4.Remove Flight" << RESET << endl;
            if (choice == 4)
                cout << YELLOW ">";
            cout << "5.Exit" << RESET << endl;
            // update maxChoices if adding another menu item

            key = _getch();

            if ((key == 'w' || key == 'W' || key == 72) && (choice > 0))
            {
                choice--;
                // cout << "W";
            }
            else if ((key == 's' || key == 'S' || key == 80) && (choice < maxChoices))
            {
                choice++;
                // cout << "S";
            }
            else if (key == '\r' || key == ' ')
            {
                switch (choice)
                {
                case 0: // edit information
                    editInformation();
                    break;
                case 1: // display data
                    displayData();
                case 2: // book new flight
                    bookNewFlight();
                    break;
                case 3: // remove flight
                    removeFlight();
                    break;
                case 4:
                    exit = true;
                    break;
                default:
                    break;
                }
            }
            else
            {
                cout << "error" << endl;
            }

        } while (exit == false);
    }
};

int Customer::noOfCustomers = 0;
int Admin::noOfAdmins = 0;
int User::noOfUsers = 0;

#endif // USER_H
