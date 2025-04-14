
// Contains User Class

#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include <vector>
#include <conio.h>

// classes
#include "Flight.h"
#include "ConsoleManipulation.h"

#define YELLOW "\033[33m"
#define RESET "\033[0m"
#define CYAN "\033[36m"
#define GREEN "\033[32m"
#define RED "\033[31m"
#define BOLD "\033[1m"
#define MAGENTA "\033[35m"
#define WHITE "\033[37m"
using namespace std;
int screenWidth = 100;
// normal size 52

// Global Functions
bool isValidEmail(const string &email)
{
    return email.find('@') != string::npos && email.find('.') != string::npos;
}

class User
{
protected:
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

    virtual void userPanel(vector<Flight> &allFlights) = 0;

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
    // vector<Flight>& flights;
    static int noOfAdmins;

public:
    Admin(string userID = "", string userName = "", string userEmail = "", string userPassword = "") : User(userID, userName, userEmail, userPassword)
    {
        noOfAdmins++;
    }
    void editInformation()
    {
        system("cls");
        // cout << CYAN << "=====================================================================" << endl;
        // cout << CYAN << "||" << YELLOW << " Attention: You are changing your personal details                " << CYAN << "||" << endl;
        // cout << CYAN << "=====================================================================" << RESET << endl;
        printLine(screenWidth, CYAN);
        printText("Attention: You are changing your personal detail", screenWidth, RED, true);
        printLine(screenWidth, CYAN);

        _getch();
        system("cls");

        string NewName, NewEmail, NewPassword;
        char c, ch;

        // cout << "Current Username: " << getUserName() << endl;
        printLine(screenWidth, CYAN);
        printText("Current Username:" + getUserName(), screenWidth, WHITE, false);

        printText("Enter New Username", screenWidth, WHITE, false);
        cout << "-> ";
        cin >> NewName;

        // cout << "\nCurrent Email: " << getUserEmail() << endl;
        printLine(screenWidth, CYAN);
        printText("Current Email:" + getUserEmail(), screenWidth, WHITE, false);

        printText("Enter New Email", screenWidth, WHITE, false);
        cout << "-> ";
        cin >> NewEmail;

        while (!isValidEmail(NewEmail))
        {
            // cout << RED << "Invalid email format! Please enter again:\n-> " << RESET;
            printText("Invalid email format! Please enter again", screenWidth, RED, false);
            cout << "-> ";
            cin >> NewEmail;
        }

        // cout << "Enter New Password:\n-> ";
        printLine(screenWidth, CYAN);
        printText("Enter New Password", screenWidth, WHITE, false);
        cout << "-> ";

        NewPassword = "";
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!NewPassword.empty())
                {
                    cout << "\b \b";
                    NewPassword.pop_back();
                }
            }
            else
            {
                cout << '*';
                NewPassword += ch;
            }
        }
        cout << endl;

        system("cls");

        // cout << YELLOW << BOLD << " Please confirm your updated details:\n" << RESET;
        printLine(screenWidth, CYAN);
        printText("Please confirm your updated details", screenWidth, YELLOW, false);

        // cout << "Username: " << NewName << endl;
        printText("Username:" + NewName, screenWidth, WHITE, false);

        // cout << "Email: " << NewEmail << endl;
        printText("Email:" + NewEmail, screenWidth, WHITE, false);

        // cout << "Password: " << string(NewPassword.length(), '*') << endl;
        printText("Password:" + string(NewPassword.length(), '*'), screenWidth, WHITE, false);
        printLine(screenWidth, CYAN);

        // cout << "\n" << CYAN << "Do you want to save these changes? (y/n): " << RESET;
        // printLine(screenWidth, CYAN);
        printText("Do you want to save these changes? (y/n):", screenWidth, YELLOW, false);
        cin >> c;

        if (c == 'y' || c == 'Y')
        {
            userName = NewName;
            userEmail = NewEmail;
            userPassword = NewPassword;
            system("cls");

            // cout << GREEN << BOLD << " Success! Your information has been updated." << RESET << endl;
            printLine(screenWidth, CYAN);
            printText("Success! Your information has been updated.", screenWidth, GREEN, true);
            printLine(screenWidth, CYAN);
        }
        else
        {
            // cout << RED << "Update cancelled. Returning to main menu..." << RESET << endl;
            printLine(screenWidth, CYAN);
            printText("Update cancelled. Returning to main menu...", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }

        printText("Press any key to return to the main menu...", screenWidth, CYAN, true);
        printLine(screenWidth, CYAN);

        _getch();
    }

    /*
        void addNewFlight(vector<Flight> &allflights)
        {
            system("cls");
            Flight newflight;
            newflight.AddFlight(allflights);
            if(newflight.getFlightNumber() != ""){
                allflights.push_back(newflight);

            }
            cout << "Flight Added Successfuly" << endl;
            cout << "+==================================================+" << endl;
            cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
            cout << "+--------------------------------------------------+" << RESET << endl;

            _getch();
        }
    */
    void addNewFlight(vector<Flight> &allflights)
    {
        system("cls");
        Flight newflight;
        newflight.AddFlight(allflights);

        if (newflight.getFlightNumber() != "")
        {
            allflights.push_back(newflight);
        }

        // cout << "Flight Added Successfuly" << endl;
        printLine(screenWidth, CYAN);
        printText("Flight Added Successfully", screenWidth, GREEN, true);

        // cout << "+==================================================+" << endl;
        // cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
        // cout << "+--------------------------------------------------+" << RESET << endl;
        printLine(screenWidth, CYAN);
        printText("Press any key to return to the main menu...", screenWidth, CYAN, true);
        printLine(screenWidth, CYAN);

        _getch();
    }

    void removeFlight(vector<Flight> &allflights)
    {
        system("cls");
        Flight temp;

        // string fn;
        // cout << "Enter Flight Number " << endl;
        // cin >> fn;

        temp.RemoveFlight(allflights);

        // cout << "+==================================================+" << endl;
        // cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
        // cout << "+--------------------------------------------------+" << RESET << endl;
        printLine(screenWidth, CYAN);
        printText("Press any key to return to the main menu...", screenWidth, CYAN, true);
        printLine(screenWidth, CYAN);

        _getch();
    }

    void listAllFlights(vector<Flight> &allflights)
{
    char choice;
    system("cls");

    if (allflights.empty())
    {
        // cout << RED << "No flights available!\n" << RESET;
        printText("No flights available!", screenWidth, RED, true);
    }
    else
    {
        // cout << CYAN << "==== ALL AVAILABLE FLIGHTS ====\n" << RESET;
        printText("==== ALL AVAILABLE FLIGHTS ====", screenWidth, CYAN, true);
        // cout << RED << "--------------------------------\n" << RESET;
        printLine(screenWidth, RED);

        for (const Flight &flight : allflights)
        {
            cout << flight << "\n"; // Flight info via overloaded <<
            // cout << RED << "--------------------------------\n" << RESET;
            printLine(screenWidth, RED);
        }
    }

    // cout << "+==================================================+" << endl;
    // cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
    // cout << "+--------------------------------------------------+" << RESET << endl;
    printLine(screenWidth, CYAN);
    printText("Press any key to return to the main menu...", screenWidth, CYAN, true);
    printLine(screenWidth, CYAN);

    _getch();
}


    // void listAllCustomers(vector<Flight>& allFlights){}

    void userPanel(vector<Flight> &allFlights) override
    {
        int choice = 0, key, maxChoices = 5;
        bool exit = false;

        do
        {
            system("cls");

            // cout << CYAN << "+--------------------------------------------------+" << endl;
            printLine(screenWidth, CYAN);
            printText("Admin DASHBOARD", screenWidth, YELLOW, true);
            printLine(screenWidth, CYAN);
            printText("Welcome, " + getUserName(), screenWidth, WHITE, false);
            // cout << "| " << YELLOW << "               CUSTOMER DASHBOARD               " << CYAN << "|" << endl;
            // cout << "+--------------------------------------------------+" << endl;
            // cout << "| " << WHITE << "Welcome, " << GREEN << getUserName() << WHITE << "!" << CYAN << "                                    |" << endl;

            // yahan jo first booked flight hongo wo ayin gi
            // if (!flightsBookedByCustomer.empty())
            // {
            //     const Flight &nextFlight = flightsBookedByCustomer[0];
            //     printLine(screenWidth, CYAN);
            //     printText(" YOUR NEXT FLIGHT:", screenWidth, YELLOW, false);
            //     printText(" Flight: " + nextFlight.getFlightNumber() + "   " + nextFlight.getOrigin() + " to " + nextFlight.getDestination(), screenWidth, WHITE, false);
            //     printText(" Date: " + nextFlight.getDate() + "   Time: " + nextFlight.getTime(), screenWidth, WHITE, false);
            //     // cout << "+--------------------------------------------------+" << endl;
            //     // cout << "| " << YELLOW << "YOUR NEXT FLIGHT:                                " << CYAN << " |" << endl;
            //     // cout << "| " << WHITE << "Flight: " << nextFlight.getFlightNumber() << "   " << nextFlight.getOrigin() << " to " << nextFlight.getDestination() << CYAN << "            |" << endl;
            //     // cout << "| " << WHITE << "Date: " << nextFlight.getDate() << "   Time: " << nextFlight.getTime() << CYAN << "                 |" << endl;
            // }

            printLine(screenWidth, CYAN);
            printText("MENU OPTIONS:", screenWidth, MAGENTA, false);
            // cout << "+--------------------------------------------------+" << endl;
            // cout << "| " << MAGENTA << "MENU OPTIONS:                                    " << CYAN << " |" << endl;

            string options[6] = {
                "Edit Profile Information",
                "Add New Flight",
                "Remove Flight",
                "List All Flights",
                "List All Customers",
                "Log Out"};

            for (int i = 0; i < 6; i++)
            {
                if (choice == i)
                    printText(string("=> ") + to_string(i + 1) + ". " + options[i], screenWidth, YELLOW, false);
                // cout << "| " << YELLOW << "=> " << (i + 1) << ". " << options[i] << CYAN << "                          |" << endl;
                else
                    printText(string(" => ") + to_string(i + 1) + ". " + options[i], screenWidth, WHITE, false);
                // cout << "|    " << WHITE << (i + 1) << ". " << options[i] << CYAN << "                          |" << endl;
            }
            printLine(screenWidth, CYAN);

            // cout << "+--------------------------------------------------+" << endl;
            // printLine(screenWidth, CYAN);
            // printText(" Total Booked Flights: " + flightsBookedByCustomer.size(), screenWidth, WHITE, false);
            // printText(" Navigation: [W/S] Move   [Enter] Select", screenWidth, WHITE, false);
            // printLine(screenWidth, CYAN);
            // cout << "| " << WHITE << "Total Booked Flights: " << flightsBookedByCustomer.size() << CYAN << "                        |" << endl;
            // cout << "| " << WHITE << "Navigation: [W/S] Move   [Enter] Select           " << CYAN << " |" << endl;
            // cout << "+--------------------------------------------------+" << RESET << endl;

            key = _getch();

            if ((key == 'w' || key == 'W') && (choice > 0))
                choice--;
            else if ((key == 's' || key == 'S') && (choice < maxChoices))
                choice++;
            else if (key == '\r' || key == ' ')
            {
                switch (choice)
                {
                case 0:
                    editInformation();
                    break;
                case 1: // new FLight
                    addNewFlight(allFlights);
                    break;
                case 2: // remove flight
                    removeFlight(allFlights);
                    break;
                case 3: // list all flights
                    listAllFlights(allFlights);
                    break;
                case 4:
                    // listAllCustomers(allFlights);
                    break;
                case 5:
                    exit = true;
                    break;
                default:

                    break;
                }
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

    // void editInformation()
    // {
    //     system("cls");
    //     cout << CYAN << "=====================================================================" << endl;
    //     cout << CYAN << "||" << YELLOW << " Attention: You are changing your personal details                " << CYAN << "||" << endl;
    //     cout << CYAN << "=====================================================================" << RESET << endl;
    //     _getch();
    //     system("cls");

    //     string NewName, NewEmail, NewPassword;
    //     char c, ch;

    //     cout << "Current Username: " << getUserName() << endl;
    //     cout << "Enter New Username:\n-> ";
    //     cin >> NewName;
    //     cout << "\nCurrent Email: " << getUserEmail() << endl;
    //     cout << "Enter New Email:\n-> ";
    //     cin >> NewEmail;
    //     while (!isValidEmail(NewEmail))
    //     {
    //         cout << RED << "Invalid email format! Please enter again:\n-> " << RESET;
    //         cin >> NewEmail;
    //     }
    //     // cout << "New Password:\n-> ";
    //     // cin >> NewPassword;
    //     cout << "\nEnter New Password:\n-> ";
    //     NewPassword = "";
    //     while ((ch = _getch()) != '\r')
    //     {
    //         if (ch == '\b')
    //         {
    //             if (!NewPassword.empty())
    //             {
    //                 cout << "\b \b";
    //                 NewPassword.pop_back();
    //             }
    //         }
    //         else
    //         {
    //             cout << '*';
    //             NewPassword += ch;
    //         }
    //     }
    //     cout << endl;

    //     system("cls");
    //     cout << YELLOW << BOLD << " Please confirm your updated details:\n"
    //          << RESET;
    //     cout << "Username: " << NewName << endl;
    //     cout << "Email: " << NewEmail << endl;
    //     cout << "Password: " << string(NewPassword.length(), '*') << endl;
    //     cout << "\n"
    //          << CYAN << "Do you want to save these changes? (y/n): " << RESET;
    //     cin >> c;

    //     if (c == 'y' || c == 'Y')
    //     {
    //         userName = NewName;         // setUserName(NewName);
    //         userEmail = NewEmail;       // setUserEmail(NewEmail);
    //         userPassword = NewPassword; // setUserPassword(NewPassword);
    //         system("cls");
    //         cout << GREEN << BOLD << " Success! Your information has been updated." << RESET << endl;
    //     }
    //     else
    //     {
    //         cout << RED << "Update cancelled. Returning to main menu..." << RESET << endl;
    //     }
    //     cout << "\nPress any key to continue..." << endl;
    //     _getch();
    // }

    // void displayEnhancedData()
    // {
    //     system("cls");

    //     cout << CYAN << "+--------------------------------------------------+" << endl;
    //     cout << "| " << YELLOW << "                MY FLIGHT DETAILS                 " << CYAN << " |" << endl;
    //     cout << "+==================================================+" << endl;
    //     cout << "|  " << WHITE << "PERSONAL INFORMATION:                            " << CYAN << " |" << endl;
    //     cout << "|  " << WHITE << "Name: " << getUserName() << CYAN << "                                 |" << endl;
    //     cout << "|  " << WHITE << "Email: " << getUserEmail() << CYAN << "                           |" << endl;
    //     cout << "+==================================================+" << endl;

    //     if (flightsBookedByCustomer.empty())
    //     {
    //         cout << "|  " << RED << "You have no flights booked yet!                 " << CYAN << " |" << endl;
    //         cout << "|  " << YELLOW << "Use the 'Book New Flight' option to make a booking." << CYAN << " |" << endl;
    //     }
    //     else
    //     {
    //         cout << "|  " << GREEN << "YOUR BOOKED FLIGHTS:                            " << CYAN << " |" << endl;
    //         cout << "+==================================================+" << endl;

    //         for (int i = 0; i < flightsBookedByCustomer.size(); i++)
    //         {
    //             const Flight &flight = flightsBookedByCustomer[i];

               
    //             cout << "|  " << YELLOW << "+------------------------------------------+" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "BOARDING PASS                           " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "Flight: " << flight.getFlightNumber() << "                             " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "From: " << flight.getOrigin() << " To: " << flight.getDestination() << "                  " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "Date: " << flight.getDate() << "    Time: " << flight.getTime() << "          " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "Passenger: " << getUserName() << "                      " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "Seat: " << (10 + i) << "A                             " << YELLOW << "|" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|                                          |" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "|  " << WHITE << "****** BOARDING TIME: " << flight.getTime() << ":" << flight.getTime().substr(3, 2) << " ******" << YELLOW << "     |" << CYAN << "    |" << endl;
    //             cout << "|  " << YELLOW << "+------------------------------------------+" << CYAN << "    |" << endl;

    //             if (i < flightsBookedByCustomer.size() - 1)
    //                 cout << "|                                                  |" << endl;
    //         }
    //     }

    //     cout << "+==================================================+" << endl;
    //     cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
    //     cout << "+--------------------------------------------------+" << RESET << endl;

    //     _getch();
    // }
    // void removeFlightEnhanced()
    // {
    //     system("cls");

    //     cout << CYAN << "+--------------------------------------------------+" << endl;
    //     cout << "| " << YELLOW << "              CANCEL FLIGHT BOOKING               " << CYAN << " |" << endl;
    //     cout << "+==================================================+" << endl;

    //     if (flightsBookedByCustomer.empty())
    //     {
    //         cout << "|  " << RED << "You have no flights booked to cancel.           " << CYAN << " |" << endl;
    //         cout << "|  " << WHITE << "Press any key to return...                       " << CYAN << " |" << endl;
    //         cout << "+--------------------------------------------------+" << RESET << endl;
    //         _getch();
    //         return;
    //     }

    //     cout << "|  " << WHITE << "YOUR CURRENT BOOKINGS:                          " << CYAN << " |" << endl;
    //     cout << "+==================================================+" << endl;

    //     for (int i = 0; i < flightsBookedByCustomer.size(); i++)
    //     {
    //         const Flight &flight = flightsBookedByCustomer[i];
    //         cout << "|  " << WHITE << (i + 1) << ". " << flight.getFlightNumber()
    //              << " | " << flight.getOrigin() << " to " << flight.getDestination()
    //              << " | " << flight.getDate() << CYAN << "  |" << endl;
    //     }

    //     cout << "+==================================================+" << endl;
    //     cout << "|  " << WHITE << "Enter the number of the flight to cancel (1-"
    //          << flightsBookedByCustomer.size() << "): " << RESET;

    //     int choice;
    //     cin >> choice;

    //     if (choice >= 1 && choice <= flightsBookedByCustomer.size())
    //     {
    //         string flightNo = flightsBookedByCustomer[choice - 1].getFlightNumber();

    //         cout << CYAN << "+==================================================+" << endl;
    //         cout << "|  " << YELLOW << "Are you sure you want to cancel this flight? (y/n): " << RESET;

    //         char confirm;
    //         cin >> confirm;

    //         if (confirm == 'y' || confirm == 'Y')
    //         {
    //             flightsBookedByCustomer.erase(flightsBookedByCustomer.begin() + choice - 1);

    //             cout << CYAN << "+==================================================+" << endl;
    //             cout << "|  " << GREEN << "√ Flight " << flightNo << " has been cancelled successfully!" << CYAN << " |" << endl;
    //         }
    //         else
    //         {
    //             cout << CYAN << "+==================================================+" << endl;
    //             cout << "|  " << YELLOW << "Flight cancellation aborted.                     " << CYAN << " |" << endl;
    //         }
    //     }
    //     else
    //     {
    //         cout << CYAN << "+==================================================+" << endl;
    //         cout << "|  " << RED << "X Invalid selection!                            " << CYAN << " |" << endl;
    //     }

    //     cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
    //     cout << "+--------------------------------------------------+" << RESET << endl;
    //     _getch();
    // }
    void editInformation()
    {
        system("cls");
        // cout << CYAN << "=====================================================================" << endl;
        // cout << CYAN << "||" << YELLOW << " Attention: You are changing your personal details                " << CYAN << "||" << endl;
        // cout << CYAN << "=====================================================================" << RESET << endl;
        printLine(screenWidth, CYAN);
        printText("Attention: You are changing your personal detail", screenWidth, RED, true);
        printLine(screenWidth, CYAN);

        _getch();
        system("cls");

        string NewName, NewEmail, NewPassword;
        char c, ch;

        // cout << "Current Username: " << getUserName() << endl;
        printLine(screenWidth, CYAN);
        printText("Current Username:" + getUserName(), screenWidth, WHITE, false);

        printText("Enter New Username", screenWidth, WHITE, false);
        cout << "-> ";
        cin >> NewName;

        // cout << "\nCurrent Email: " << getUserEmail() << endl;
        printLine(screenWidth, CYAN);
        printText("Current Email:" + getUserEmail(), screenWidth, WHITE, false);

        printText("Enter New Email", screenWidth, WHITE, false);
        cout << "-> ";
        cin >> NewEmail;

        while (!isValidEmail(NewEmail))
        {
            // cout << RED << "Invalid email format! Please enter again:\n-> " << RESET;
            printText("Invalid email format! Please enter again", screenWidth, RED, false);
            cout << "-> ";
            cin >> NewEmail;
        }

        // cout << "Enter New Password:\n-> ";
        printLine(screenWidth, CYAN);
        printText("Enter New Password", screenWidth, WHITE, false);
        cout << "-> ";

        NewPassword = "";
        while ((ch = _getch()) != '\r')
        {
            if (ch == '\b')
            {
                if (!NewPassword.empty())
                {
                    cout << "\b \b";
                    NewPassword.pop_back();
                }
            }
            else
            {
                cout << '*';
                NewPassword += ch;
            }
        }
        cout << endl;

        system("cls");

        // cout << YELLOW << BOLD << " Please confirm your updated details:\n" << RESET;
        printLine(screenWidth, CYAN);
        printText("Please confirm your updated details", screenWidth, YELLOW, false);

        // cout << "Username: " << NewName << endl;
        printText("Username:" + NewName, screenWidth, WHITE, false);

        // cout << "Email: " << NewEmail << endl;
        printText("Email:" + NewEmail, screenWidth, WHITE, false);

        // cout << "Password: " << string(NewPassword.length(), '*') << endl;
        printText("Password:" + string(NewPassword.length(), '*'), screenWidth, WHITE, false);
        printLine(screenWidth, CYAN);

        // cout << "\n" << CYAN << "Do you want to save these changes? (y/n): " << RESET;
        // printLine(screenWidth, CYAN);
        printText("Do you want to save these changes? (y/n):", screenWidth, YELLOW, false);
        cin >> c;

        if (c == 'y' || c == 'Y')
        {
            userName = NewName;
            userEmail = NewEmail;
            userPassword = NewPassword;
            system("cls");

            // cout << GREEN << BOLD << " Success! Your information has been updated." << RESET << endl;
            printLine(screenWidth, CYAN);
            printText("Success! Your information has been updated.", screenWidth, GREEN, true);
            printLine(screenWidth, CYAN);
        }
        else
        {
            // cout << RED << "Update cancelled. Returning to main menu..." << RESET << endl;
            printLine(screenWidth, CYAN);
            printText("Update cancelled. Returning to main menu...", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }

        printText("Press any key to return to the main menu...", screenWidth, CYAN, true);
        printLine(screenWidth, CYAN);

        _getch();
    }
    void displayEnhancedData()
    {
        system("cls");
    
        printLineD(screenWidth, CYAN);
        printText("MY FLIGHT DETAILS", screenWidth, YELLOW, true);
        printLine(screenWidth, CYAN);
        printText("PERSONAL INFORMATION:", screenWidth, WHITE, false);
        printText("Name: " + getUserName(), screenWidth, WHITE, false);
        printText("Email: " + getUserEmail(), screenWidth, WHITE, false);
        printLine(screenWidth, CYAN);
    
        if (flightsBookedByCustomer.empty())
        {
            printText("You have no flights booked yet!", screenWidth, RED, false);
            printText("Use the 'Book New Flight' option to make a booking.", screenWidth, YELLOW, false);
        }
        else
        {
            printText("YOUR BOOKED FLIGHTS:", screenWidth, GREEN, false);
            printLine(screenWidth, CYAN);
    
            for (int i = 0; i < flightsBookedByCustomer.size(); i++)
            {
                const Flight &flight = flightsBookedByCustomer[i];
    
                printText("+------------------------------------------+", screenWidth, YELLOW, false);
                printText("|  BOARDING PASS                           |", screenWidth, YELLOW, false);
                printText("|  Flight: " + flight.getFlightNumber(), screenWidth, WHITE, false);
                printText("|  From: " + flight.getOrigin() + " To: " + flight.getDestination(), screenWidth, WHITE, false);
                printText("|  Date: " + flight.getDate() + "    Time: " + flight.getTime(), screenWidth, WHITE, false);
                printText("|  Passenger: " + getUserName(), screenWidth, WHITE, false);
                printText("|  Seat: " + to_string(10 + i) + "A", screenWidth, WHITE, false);
                printText("|                                          |", screenWidth, YELLOW, false);
                printText("|  ****** BOARDING TIME: " + flight.getTime() + ":" + flight.getTime().substr(3, 2) + " ******", screenWidth, WHITE, false);
                printText("+------------------------------------------+", screenWidth, YELLOW, false);
    
                if (i < flightsBookedByCustomer.size() - 1)
                    cout << endl;
            }
        }
    
        printLine(screenWidth, CYAN);
        printText("Press any key to return to the main menu...", screenWidth, WHITE, false);
        printLineD(screenWidth, CYAN);
    
        _getch();
    }
    


    void bookNewFlightEnhanced(vector<Flight> &allFlights)
    {
        system("cls");
        string origin, destination;
        vector<Flight> matchingFlights;

       // cout << CYAN << "+--------------------------------------------------+" << endl;
       printLineD(screenWidth,CYAN);
       printText("FLIGHT BOOKING WIZARD",screenWidth,YELLOW,true);
       printLine(screenWidth,CYAN);
       printText("STEP 1: Choose your travel route",screenWidth,YELLOW,false);
       printLine(screenWidth,CYAN);
       printText("From (Origin City): ",screenWidth,WHITE,false);
       cout<<CYAN<<"|=>>>> "<<RESET;
       cin >>origin;
       printText("To (Destination City): ",screenWidth,WHITE,false);
       cout<<CYAN<<"|=>>>> "<<RESET;
       cin >> destination;
      //  cout << "| " << YELLOW << "              FLIGHT BOOKING WIZARD               " << CYAN << " |" << endl;
      // cout << "+==================================================+" << endl;
     //   cout << "|  " << WHITE << "STEP 1: Choose your travel route                  " << CYAN << " |" << endl;
       // cout << "+==================================================+" << endl;

       //cccccccc  " << WHITE << "From (Origin City): " << RESET;
      //  cin >> origin;

     //   cout << CYAN << "|  " << WHITE << "To (Destination City): " << RESET;
        //cin >> destination;

        // Find matching flights
        for (const Flight &flight : allFlights)
        {
            if (flight.getOrigin() == origin && flight.getDestination() == destination)
            {
                matchingFlights.push_back(flight);
            }
        }

        printLine(screenWidth,CYAN);
        //cout << CYAN << "+==================================================+" << endl;

        if (matchingFlights.empty())
        {
            printText("X No flights found for this route.",screenWidth,RED,false);
            printText("Press any key to return...",screenWidth,WHITE,false);
            printLine(screenWidth,CYAN);
           // cout << "|  " << RED << "X No flights found for this route.               " << CYAN << " |" << endl;
            //cout << "|  " << WHITE << "Press any key to return...                       " << CYAN << " |" << endl;
           // cout << "+--------------------------------------------------+" << RESET << endl;
            _getch();
            return;
        }
        printText(to_string(matchingFlights.size())+" Flight(s) found!",screenWidth,GREEN,false);
        printText("STEP 2: Select your preferred flight",screenWidth,WHITE,false);
        printLine(screenWidth,CYAN);
       // cout << "|  " << GREEN << " " << matchingFlights.size() << " flights found!                            " << CYAN << " |" << endl;
       //cout << "|  " << WHITE << "STEP 2: Select your preferred flight              " << CYAN << " |" << endl;
      //  cout << "+==================================================+" << endl;

        for (int i = 0; i < matchingFlights.size(); ++i)
        {   printText(to_string(i+1)+". "+matchingFlights[i].getFlightNumber()+" | "+matchingFlights[i].getDate()+" | "+ matchingFlights[i].getTime(),screenWidth,WHITE,false);
            //cout << "|  " << WHITE << (i + 1) << ". " << matchingFlights[i].getFlightNumber()
              //   << " | " << matchingFlights[i].getDate()
                // << " | " << matchingFlights[i].getTime() << CYAN << "          |" << endl;
        }
        printLine(screenWidth,CYAN);
        printText("Enter flight number (1-"+to_string(matchingFlights.size())+"): ",screenWidth,WHITE,false);
        int select;
        cout<<CYAN<<"|=>>>> "<<RESET;
        cin >> select;
        //cout << "+==================================================+" << endl;
        //cout << "|  " << WHITE << "Enter flight number (1-" << matchingFlights.size() << "): " << RESET;

        

        if (select >= 1 && select <= matchingFlights.size())
        {
            flightsBookedByCustomer.push_back(matchingFlights[select - 1]);

            printLine(screenWidth,CYAN);
            printText(" Flight booked successfully!",screenWidth,GREEN,false);
            printLineS(screenWidth,CYAN);
            printText("BOOKING CONFIRMATION:",screenWidth,YELLOW,false);
            printText("Flight: "+matchingFlights[select - 1].getFlightNumber(),screenWidth,WHITE,false);
            printText("Route: "+matchingFlights[select - 1].getOrigin()+" -> "+matchingFlights[select - 1].getDestination(),screenWidth,WHITE,false);
            printText("Date/Time: "+matchingFlights[select - 1].getDate()+" at "+ matchingFlights[select - 1].getTime(),screenWidth,WHITE,false);
           // cout << CYAN << "+==================================================+" << endl;
           // cout << "|  " << GREEN << " Flight booked successfully!                    " << CYAN << " |" << endl;
           // cout << "|                                                  |" << endl;
           // cout << "|  " << YELLOW << "BOOKING CONFIRMATION:                            " << CYAN << " |" << endl;
           // cout << "|  " << WHITE << "Flight: " << matchingFlights[select - 1].getFlightNumber() << CYAN << "                                    |" << endl;
           // cout << "|  " << WHITE << "Route: " << matchingFlights[select - 1].getOrigin() << " -> "
           //      << matchingFlights[select - 1].getDestination() << CYAN << "                        |" << endl;
           // cout << "|  " << WHITE << "Date/Time: " << matchingFlights[select - 1].getDate() << " at "
           //      << matchingFlights[select - 1].getTime() << CYAN << "               |" << endl;
        }
        else
        {
            printLine(screenWidth,CYAN);
            printText("X Invalid selection!",screenWidth,RED,false);
            //cout << CYAN << "+==================================================+" << endl;
            //cout << "|  " << RED << "X Invalid selection!                            " << CYAN << " |" << endl;
        }
        printText("Press any key to return to the main menu...",screenWidth,WHITE,false);
        printLineD(screenWidth,CYAN);
        //cout << "|  " << WHITE << "Press any key to return to the main menu...      " << CYAN << " |" << endl;
        //cout << "+--------------------------------------------------+" << RESET << endl;
        _getch();
    }
    void removeFlightEnhanced()
    {
        system("cls");
    
        printLineD(screenWidth, CYAN);
        printText("CANCEL FLIGHT BOOKING", screenWidth, YELLOW, true);
        printLine(screenWidth, CYAN);
    
        if (flightsBookedByCustomer.empty())
        {
            printText("You have no flights booked to cancel.", screenWidth, RED, false);
            printText("Press any key to return...", screenWidth, WHITE, false);
            printLineD(screenWidth, CYAN);
            _getch();
            return;
        }
    
        printText("YOUR CURRENT BOOKINGS:", screenWidth, WHITE, false);
        printLine(screenWidth, CYAN);
    
        for (int i = 0; i < flightsBookedByCustomer.size(); i++)
        {
            const Flight &flight = flightsBookedByCustomer[i];
            printText(to_string(i + 1) + ". " + flight.getFlightNumber() + " | " +
                      flight.getOrigin() + " to " + flight.getDestination() + " | " +
                      flight.getDate(),
                      screenWidth, WHITE, false);
        }
    
        printLine(screenWidth, CYAN);
        printText("Enter the number of the flight to cancel (1-" + to_string(flightsBookedByCustomer.size()) + "):", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        int choice;
        cin >> choice;
    
        if (choice >= 1 && choice <= flightsBookedByCustomer.size())
        {
            string flightNo = flightsBookedByCustomer[choice - 1].getFlightNumber();
    
            printLine(screenWidth, CYAN);
            printText("Are you sure you want to cancel this flight? (y/n):", screenWidth, YELLOW, false);
            cout << CYAN << "|=>>>> " << RESET;
            char confirm;
            cin >> confirm;
    
            if (confirm == 'y' || confirm == 'Y')
            {
                flightsBookedByCustomer.erase(flightsBookedByCustomer.begin() + choice - 1);
                printLine(screenWidth, CYAN);
                printText("  Flight " + flightNo + " has been cancelled successfully!", screenWidth, GREEN, false);
            }
            else
            {
                printLine(screenWidth, CYAN);
                printText("Flight cancellation aborted.", screenWidth, YELLOW, false);
            }
        }
        else
        {
            printLine(screenWidth, CYAN);
            printText("X Invalid selection!", screenWidth, RED, false);
        }
    
        printText("Press any key to return to the main menu...", screenWidth, WHITE, false);
        printLineD(screenWidth, CYAN);
        _getch();
    }
    
    void userPanel(vector<Flight> &allFlights) override
    {
        int choice = 0, key, maxChoices = 4;
        bool exit = false;

        do
        {
            clearScreen();

            // cout << CYAN << "+--------------------------------------------------+" << endl;
            printLine(screenWidth, CYAN);
            printText("CUSTOMER DASHBOARD", screenWidth, YELLOW, true);
            printLine(screenWidth, CYAN);
            printText("Welcome, " + getUserName(), screenWidth, WHITE, false);
            // cout << "| " << YELLOW << "               CUSTOMER DASHBOARD               " << CYAN << "|" << endl;
            // cout << "+--------------------------------------------------+" << endl;
            // cout << "| " << WHITE << "Welcome, " << GREEN << getUserName() << WHITE << "!" << CYAN << "                                    |" << endl;

            //yahan jo first booked flight hongo wo ayin gi 
            if (!flightsBookedByCustomer.empty())
            {
                const Flight &nextFlight = flightsBookedByCustomer[0];
                printLine(screenWidth,CYAN);
                printText(" YOUR NEXT FLIGHT:", screenWidth, YELLOW, false);
                printText(" Flight: " + nextFlight.getFlightNumber() + "   " + nextFlight.getOrigin() + " to " + nextFlight.getDestination(), screenWidth, WHITE, false);
                printText(" Date: " + nextFlight.getDate() + "   Time: " + nextFlight.getTime(), screenWidth, WHITE, false);
                // cout << "+--------------------------------------------------+" << endl;
                // cout << "| " << YELLOW << "YOUR NEXT FLIGHT:                                " << CYAN << " |" << endl;
                // cout << "| " << WHITE << "Flight: " << nextFlight.getFlightNumber() << "   " << nextFlight.getOrigin() << " to " << nextFlight.getDestination() << CYAN << "            |" << endl;
                // cout << "| " << WHITE << "Date: " << nextFlight.getDate() << "   Time: " << nextFlight.getTime() << CYAN << "                 |" << endl;
            }

            printLine(screenWidth, CYAN);
            printText("MENU OPTIONS:", screenWidth, MAGENTA, false);
            // cout << "+--------------------------------------------------+" << endl;
            // cout << "| " << MAGENTA << "MENU OPTIONS:                                    " << CYAN << " |" << endl;

            
            string options[5] = {
                "Edit Profile Information",
                "View My Flights",
                "Book New Flight",
                "Cancel a Flight",
                "Log Out"};

            for (int i = 0; i < 5; i++)
            {
                if (choice == i)
                    printText(string("=> ") + to_string(i+1) + ". " + options[i], screenWidth, YELLOW, false);
                    // cout << "| " << YELLOW << "=> " << (i + 1) << ". " << options[i] << CYAN << "                          |" << endl;
                else
                    printText(string(" => ") + to_string(i+1) + ". " + options[i], screenWidth, WHITE, false);
                    // cout << "|    " << WHITE << (i + 1) << ". " << options[i] << CYAN << "                          |" << endl;
            }

            // cout << "+--------------------------------------------------+" << endl;
            printLine(screenWidth, CYAN);
            printText(" Total Booked Flights: " + flightsBookedByCustomer.size(), screenWidth, WHITE, false);
            printText(" Navigation: [W/S] Move   [Enter] Select", screenWidth, WHITE, false);
            printLine(screenWidth, CYAN);
            // cout << "| " << WHITE << "Total Booked Flights: " << flightsBookedByCustomer.size() << CYAN << "                        |" << endl;
            // cout << "| " << WHITE << "Navigation: [W/S] Move   [Enter] Select           " << CYAN << " |" << endl;
            // cout << "+--------------------------------------------------+" << RESET << endl;

            key = _getch();

            
            if ((key == 'w' || key == 'W') && (choice > 0))
                choice--;
            else if ((key == 's' || key == 'S') && (choice < maxChoices))
                choice++;
            else if (key == '\r' || key == ' ')
            {
                switch (choice)
                {
                case 0: // Edit information
                    editInformation();
                    break;
                case 1: // View flights
                    displayEnhancedData();
                    break;
                case 2: // Book new flight
                    bookNewFlightEnhanced(allFlights);
                    break;
                case 3: // Cancel flight
                    removeFlightEnhanced();
                    break;
                case 4: // Exit
                    exit = true;
                    cout << GREEN << "Logging out...\n"
                         << RESET << endl;
                    // Sleep(1000);
                    break;
                }
            }
        } while (exit == false);
    }
};
// test comment  by hasnain for git checking..
int Customer::noOfCustomers = 0;
int Admin::noOfAdmins = 0;
int User::noOfUsers = 0;

#endif // USER_H
