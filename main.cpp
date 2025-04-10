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
#include "Flight.h"
#include "User.h"
using namespace std;

void userScreen(const vector<Customer> customers)
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
        else {
            cout << "Wrong Password!" << endl;
        }

    }
    
}

void adminScreen()
{
    cout << "This will show functions related to admin" << endl;
}

void addUser(vector<Customer> &customers)
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

void addUser(vector<Admin> &admins)
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

int main()
{
    vector<Admin> admins;
    vector<Customer> customers;

    cout << "Testing" << endl;
    int temp;

    do
    {
        cout << "1.Admin, 2.User\n>";
        cin >> temp;
        switch (temp)
        {
        case 1:
            cout << "1.Register new Admin\n2.Login Admin\n>";
            cin >> temp;
            switch (temp)
            {
            case 1:
                addUser(admins);
                break;
            case 2:
                adminScreen();
                break;
            case 3:
                break;
            default:
                cout << "Not a Valid command\n>" << endl;
                break;
            }

            break;

        case 2:
            cout << "1.Register new User\n2.Login User\n>";
            cin >> temp;
            switch (temp)
            {
            case 1:
                addUser(customers);
                break;
            case 2:
                userScreen(customers);
                break;
            case 3:
                break;
            default:
                cout << "Not a Valid command\n>" << endl;
                break;
            }
            break;
        default:
            break;
        }
    } while (temp != 0);
}
