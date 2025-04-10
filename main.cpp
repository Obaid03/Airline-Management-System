/*
//before writing code
git pull origin main

//after writing code
git add .
git commit -m "Your commit message"
git push origin main
*/

// test comment
// Hasnain test comment
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

void adminLoginScreen()
{
    cout << "This will show functions related to admin" << endl;
}

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

void adminScreen(vector<Admin> &admins)
{
    bool exit = false;
    int choice = 0, key, maxChoices = 3;;
    do
    {
        system("cls");
        getAirportManagementSystemText();
        // gotoxy(15, 20);
        cout << "What do you want to do?(admin)" << endl;
        if (choice == 0)
            cout << YELLOW ">";
        cout << "1.Register New" << RESET << endl;
        if (choice == 1)
            cout << YELLOW ">";
        cout << "2.Login" << RESET << endl;
        if (choice == 2)
            cout << YELLOW " ";
        cout << "<Go Back>" << RESET << endl;
        //update maxChoices if adding another menu item

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
                addAdmin(admins);
                break;
            case 1:
                adminLoginScreen();
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

void customerScreen(vector<Customer> &customers)
{
    int choice = 0, key;
    system("cls");
    getAirportManagementSystemText();
    // gotoxy(15, 20);
    cout << "What do you want to do(cUSTOMER)?" << endl;
    if (choice == 0)
        cout << YELLOW ">";
    cout << "1.Register New" << RESET << endl;
    if (choice == 1)
        cout << YELLOW ">";
    cout << "2.Login" << RESET << endl;

    key = _getch();
    switch (key)
    {
    case 'w':
    case 'W':
        if (choice > 0)
        {
            choice = choice - 1;
        }
        break;
    case 's':
    case 'S':
        if (choice < 2)
        {
            choice = choice + 1;
        }
        break;
    case '\r': // enter key
    case ' ':
        switch (choice)
        {
        case 0:
            addCustomer(customers);
            break;
        case 1:
            customerLoginScreen(customers);
            break;
        default:
            cout << "Error" << endl;
            break;
        }
    default:
        break;
    }
}

int main()
{
    vector<Admin> admins;
    vector<Customer> customers;

    // cout << "Testing" << endl;
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
            choice = choice - 1;
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
                adminScreen(admins);
                break;
            case 1:
                customerScreen(customers);
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
