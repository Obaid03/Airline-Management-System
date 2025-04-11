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
void loginScreen(const vector<Customer> customers, const vector<Admin> admins, bool isAdmin)
{
    bool flag = false; // flag true if email entered by user is equal to an email in storage(the email user wants to log in to)
    string temp;
    int noOfUsers;
    vector<User *> users; // list/array of pointers to either admin or customer
    int i = 0;
    if (isAdmin)
    {
        noOfUsers = admins.size(); // get no of admins through vector
        for (Admin a : admins)
        {
            users.push_back(&a);
            i++;
        }
    }
    else
    {
        noOfUsers = customers.size(); // get no of customers through vector
        for (Customer c : customers)
        {
            users.push_back(&c);
            i++;
        }
    }
    i = 0;
    do
    {
        cout << "Enter email of user" << endl;
        cin >> temp;
        for (int i = 0; i < noOfUsers; i++) // int i = 0; i < noUsers; i++
        {
            if (temp == users[i]->getUserEmail()) // users[i]->getUserEmail();
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
            cout << "User not found" << endl;
        }
    } while (flag == false);
    cout << "Enter password" << endl;
    cin >> temp;
    for (int i = 0; i < noOfUsers; i++)
    {
        if (temp == users[i]->getUserPassword())
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

/*
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
*/

//when new user is need to be added
void addNewUser(vector<Admin> &admins, vector<Customer> &customers, bool isAdmin)
{
    system("cls");
    string temp, passRepeat;
    User *newUser;
    Admin admin;
    Customer customer;

    if (isAdmin)
        newUser = &admin;
    else
        newUser = &customer;

    cout << "Enter name of new user" << endl;
    cin >> temp;
    newUser->setUserName(temp);
    cout << "Enter email of new user" << endl;
    cin >> temp; // can add a function to check valid email
    newUser->setUserEmail(temp);
    do
    {
        cout << "Enter password for user" << endl;
        cin >> temp;
        cout << "Repeat password" << endl;
        cin >> passRepeat;
        if (temp == passRepeat)
        {
            newUser->setUserPassword(passRepeat);
            cout << "User added successfully" << endl;
        }
        else
        {
            cout << "Passwords do not match! Enter Again" << endl;
        }
    } while (temp != passRepeat); // can add a function to push the user to generate a strong password

    if (isAdmin)
        admins.push_back(admin);
    else
        customers.push_back(customer);

    cout << "User Added Successfully[Press Enter To Return]" << endl;
    cin >> temp;
}

// register and login screen
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
        cout << "What do you want to do?";
        if (isAdmin)
            cout << "--[Admin]" << endl;
        else
            cout << "--[Customer]" << endl;

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
            case 0: // register new user
                if (isAdmin)
                    addNewUser(admins, customers, true);
                else
                    addNewUser(admins, customers, false);
                break;
            case 1:
                if (isAdmin)
                    loginScreen(customers, admins, true);
                else
                    loginScreen(customers, admins, false);
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
            case 0: // admin
                registerAndLoginScreen(admins, customers, true);
                break;
            case 1: // customer
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
    } while (key != 0);
}
