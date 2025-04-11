/*
//before writing code
git pull origin main

//after writing code
git add .
git commit -m "Your commit message"
git push origin main
*/

#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Flight.h"
#include "User.h"
#include "ConsoleManipulation.h"

#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"   /* White */
using namespace std;

// login screen(when admin and user want to login)
void customerLoginScreen(const vector<Customer> customers)
{
    bool flag = false;
    string temp;
    do
    {
        cout << "Enter email of user" << endl;
        cin >> temp;
        for (Customer i : customers)
        {
            if (temp == i.getUserEmail())
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
            }
        }
        if (flag == false)
        {
            cout << "user not found" << endl;
        }
    } while (flag == false);
    cout << "Enter password" << endl;
    cin >> temp;
    for (Customer i : customers)
    {
        if (temp == i.getUserPassword())
        {
            cout << "Login Successful" << endl;
            cout << "This will show functions related to user" << endl;
        }
        else
        {
            cout << "Wrong Password!" << endl;
        }
    }
}

void adminLoginScreen(const vector<Admin> admins)
{
    bool flag = false;
    string temp;
    do
    {
        cout << "Enter email of user" << endl;
        cin >> temp;
        for (Admin i : admins)
        {
            if (temp == i.getUserEmail())
            {
                flag = true;
                break;
            }
            else
            {
                flag = false;
            }
        }
        if (flag == false)
        {
            cout << "user not found" << endl;
        }
    } while (flag == false);
    cout << "Enter password" << endl;
    cin >> temp;
    for (Admin i : admins)
    {
        if (temp == i.getUserPassword())
        {
            cout << "Login Successful" << endl;
            cout << "This will show functions related to user" << endl;
        }
        else
        {
            cout << "Wrong Password!" << endl;
        }
    }
}
// end of login screen functions

// register functions(new user registration screen)
void addCustomer(vector<Customer> &customers)
{
    string temp, passRepeat;
    Customer newUser;
    cout << "Enter name of new user" << endl;
    cin >> temp;
    newUser.setUserName(temp);
    cout << "Enter email of new user" << endl;
    cin >> temp; // can add a function to check valid email
    newUser.setUserEmail(temp);
    do
    {
        cout << "Enter password for user" << endl;
        cin >> temp;
        cout << "Repeat password" << endl;
        cin >> passRepeat;
        if (temp == passRepeat)
        {
            newUser.setUserPassword(passRepeat);
            cout << "User added successfully" << endl;
        }
        else
        {
            cout << "Passwords do not match! Enter Again" << endl;
        }
    } while (temp != passRepeat); // can add a function to push the user to generate a strong password

    customers.push_back(newUser);
}

void addAdmin(vector<Admin> &admins)
{
    string temp, passRepeat;
    Admin newUser;
    cout << "Enter name of new user" << endl;
    cin >> temp;
    newUser.setUserName(temp);
    cout << "Enter email of new user" << endl;
    cin >> temp; // can add a function to check valid email
    newUser.setUserEmail(temp);
    do
    {
        cout << "Enter password for user" << endl;
        cin >> temp;
        cout << "Repeat password" << endl;
        cin >> passRepeat;
        if (temp == passRepeat)
        {
            newUser.setUserPassword(passRepeat);
            cout << "User added successfully" << endl;
        }
        else
        {
            cout << "Passwords do not match! Enter Again" << endl;
        }
    } while (temp != passRepeat); // can add a function to push the user to generate a strong password

    admins.push_back(newUser);
}
// end of register functions(new user registration functions)

// admin menu screen(calls admin register function and admin login function)
void registerAndLoginScreen(vector<Admin> &admins, vector<Customer> &customers, bool isAdmin)
{
    bool exit = false;
    int choice = 0, key, maxChoices = 3;
    ;
    do
    {
        system("cls");
        getAirportManagementSystemText();
        // gotoxy(15, 20);
        cout << "What do you want to do?" << endl;
        if (choice == 0)
            cout << YELLOW ">";
        cout << "1.Register New" << RESET << endl;
        if (choice == 1)
            cout << YELLOW ">";
        cout << "2.Login" << RESET << endl;
        if (choice == 2)
            cout << YELLOW " ";
        cout << "<Go Back>" << RESET << endl;
        // update maxChoices if adding another menu item

        key = _getch();

        if ((key == 'w' || key == 'W') && (choice > 0))
        {
            choice--;
            cout << "W";
        }
        else if ((key == 's' || key == 'S') && (choice < maxChoices))
        {
            choice++;
            cout << "S";
        }
        else if ((key == '\r' || key == ' ') && (choice < maxChoices))
        {
            switch (choice)
            {
            case 0:
                if (isAdmin)
                    addAdmin(admins);
                else
                    addCustomer(customers);
                break;
            case 1:
                if (isAdmin)
                    adminLoginScreen(admins);
                else
                    customerLoginScreen(customers);
                break;
            case 2:
                exit = true;
                cout << "Exit selected" << endl;
                break;
            default:
                break;
            }
            cout << "R";
        }
        else
        {
            cout << "error" << endl;
        }

    } while (exit == false);
}


int main()
{
    vector<Admin> admins;
    vector<Customer> customers;

    int temp;
    int choice = 0, key;
    do
    {

        system("cls");
        getAirportManagementSystemText();
        // gotoxy(15, 20);
        cout << "Who Is Using?" << endl;
        if (choice == 0)
            cout << YELLOW ">";
        cout << "1.Admin" << RESET << endl;
        if (choice == 1)
            cout << YELLOW ">";
        cout << "2.Customer" << RESET << endl;

        hideCursor();
        key = _getch();
        cout << key << endl;

        if ((key == 'w' || key == 'W') && (choice > 0))
        {
            choice--;
            cout << "W";
        }
        else if ((key == 's' || key == 'S') && (choice < 2))
        {
            choice++;
            cout << "S";
        }
        else if ((key == '\r' || key == ' ') && (choice < 2))
        {
            switch (choice)
            {
            case 0:
                registerAndLoginScreen(admins, customers, true);
                break;
            case 1:
                registerAndLoginScreen(admins, customers, false);
                break;
            default:
                break;
            }
            cout << "R";
        }
        else
        {
            cout << "idk" << endl;
        }
    } while (1);
}
