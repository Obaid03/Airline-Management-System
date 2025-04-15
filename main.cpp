#include <iostream>
#include <windows.h>
#include <conio.h>

#include "Flight.h"
#include "User.h"
#include "ConsoleManipulation.h"
#include "Constants.h"

using namespace std;

// login screen(when admin and user want to login)
void loginScreen(const vector<Customer> customers, const vector<Admin> admins, vector<Flight> &allFlights, bool isAdmin)
{
    bool flag = false; // flag true if email entered by user is equal to an email in storage(the email user wants to log in to)
    string temp;
    int noOfUsers;
    vector<User *> users; // list/array of pointers to either admin or customer
    int indexOfMatchedUser = -1;
    /*The Range for loop stores one item of a container in the left hand side, so in each iteration
    it is actually storing an object/index of an array/vector in the left hand side, so by storing it
    as a refrence we are directly passing the memory address of admin users to users vector*/
    if (isAdmin)
    {
        noOfUsers = admins.size(); // get no of admins through vector
        for (const Admin &a : admins)
        {
            users.push_back(const_cast<Admin *>(&a)); // here it is typecasting from refrence to pointer
        }
    }
    else
    {
        noOfUsers = customers.size(); // get no of customers through vector
        for (const Customer &c : customers)
        {
            users.push_back(const_cast<Customer *>(&c));
        }
    }

    system("cls");
    printLine(screenWidth, CYAN);
    printText("USER LOGIN", screenWidth, GREEN, true);
    printLine(screenWidth, CYAN);

    do
    {
        printLine(screenWidth, CYAN);
        printText("Enter Email", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        // cout << "Enter email of user" << endl;
        cin >> temp;
        for (int i = 0; i < noOfUsers; i++) // int i = 0; i < noUsers; i++
        {
            if (temp == users[i]->getUserEmail()) // users[i]->getUserEmail();
            {
                flag = true;
                indexOfMatchedUser = i;
                // cout << "Enter password" << endl;
                printLine(screenWidth, CYAN);
                printText("Enter Password", screenWidth, WHITE, false);
                cout << CYAN << "|=>>>> " << RESET;
                cin >> temp;
                if (temp == users[indexOfMatchedUser]->getUserPassword())
                {
                    printLine(screenWidth, CYAN);
                    printText("Login Successful!", screenWidth, GREEN, true);
                    printLine(screenWidth, CYAN);
                    system("pause");
                    users[indexOfMatchedUser]->userPanel(allFlights);
                    return;
                }
                else
                {
                    printLine(screenWidth, CYAN);
                    printText("Wrong Password", screenWidth, RED, true);
                    printLine(screenWidth, CYAN);
                    system("pause");
                }
                // break;
            }
            else
            {
                flag == false;
            }
        }
        if (flag == false)
        {
            printLine(screenWidth, CYAN);
            printText("User Not Found!", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }

    } while (flag == false);
}

// when new user is need to be added
void addNewUser(vector<Admin> &admins, vector<Customer> &customers, bool isAdmin)
{
    system("cls");
    // cout << "User Registrarion" << endl;
    // cout << "=================" << endl;
    printLine(screenWidth, CYAN);
    printText("USER REGISTRATION", screenWidth, GREEN, true);
    printLine(screenWidth, CYAN);

    string temp, passRepeat;
    bool isValid = false;
    User *newUser;
    Admin admin;
    Customer customer;

    if (isAdmin)
        newUser = &admin;
    else
        newUser = &customer;

    // cout << "Enter name of new user" << endl;
    printText("Enter name of User", screenWidth, WHITE, false);
    cout << CYAN << "|=>>>> " << RESET;
    cin >> temp;
    newUser->setUserName(temp);

    do
    {
        printText("Enter email of User", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        cin >> temp;
        isValid = isValidEmail(temp);
        if (isValid)
        {
            newUser->setUserEmail(temp);
        }
        else {
            printLine(screenWidth, CYAN);
            printText("Email Not Valid! Enter Again", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }
    } while(!isValid);

    do
    {
        // cout << "Enter password for user" << endl;
        printText("Enter password for User", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        cin >> temp;
        // cout << "Repeat password" << endl;
        printText("Repeat password", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        cin >> passRepeat;
        if (temp == passRepeat)
        {
            newUser->setUserPassword(passRepeat);
        }
        else
        {
            // cout << "Passwords do not match! Enter Again" << endl;
            printLine(screenWidth, CYAN);
            printText("Passwords do not match! Enter Again", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }
    } while (temp != passRepeat); // can add a function to push the user to generate a strong password

    if (isAdmin)
        admins.push_back(admin);
    else
        customers.push_back(customer);

    // cout << "User Added Successfully" << endl;
    printLine(screenWidth, CYAN);
    printText("User Added Successfully", screenWidth, GREEN, true);
    printLine(screenWidth, CYAN);
    system("pause");
}

// register and login screen
void registerAndLoginScreen(vector<Admin> &admins, vector<Customer> &customers, vector<Flight> &flights, bool isAdmin)
{
    bool exit = false; // exit condition to check at the end of do while
    int choice = 0;
    int maxChoices = 2;
    string menuOptions[3] = {"Register", "Login", "<Go Back>"};
    int key;
    do
    {
        // system("cls");
        // getAirportManagementSystemText();

        // cout << "What do you want to do?";
        // if (isAdmin)
        //     cout << "--[Admin]" << endl;
        // else
        //     cout << "--[Customer]" << endl;

        // if (choice == 0)
        //     cout << YELLOW ">";
        // cout << "1.Register New" << RESET << endl;
        // if (choice == 1)
        //     cout << YELLOW ">";
        // cout << "2.Login" << RESET << endl;
        // if (choice == 2)
        //     cout << YELLOW " ";
        // cout << "<Go Back>" << RESET << endl;
        // // update maxChoices if adding another menu item
        system("cls");
        getAirportManagementSystemText();
        printLine(screenWidth, CYAN);
        printText("What do you want to do?", screenWidth, WHITE, true);
        if (isAdmin)
            printText("--[Admin]--", screenWidth, GREEN, true);
        else
            printText("--[Customer]--", screenWidth, GREEN, true);
        printLine(screenWidth, CYAN);

        for (int i = 0; i < 3; i++)
        {
            if (choice == i)
            {
                printText(string("=> ") + to_string(i + 1) + ". " + menuOptions[i], screenWidth, YELLOW, true);
            }

            else
            {
                printText(to_string(i + 1) + ". " + menuOptions[i], screenWidth, WHITE, true);
            }
        }
        printLine(screenWidth, CYAN);

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
            case 0: // register new user
                if (isAdmin)
                    addNewUser(admins, customers, true);
                else
                    addNewUser(admins, customers, false);
                break;
            case 1:
                if (isAdmin)
                    loginScreen(customers, admins, flights, true);
                else
                    loginScreen(customers, admins, flights, false);
                break;
            case 2:
                exit = true;
                cout << "Exit selected" << endl;
                break;
            default:
                break;
            }
        }
        else
        {
            cout << "Error" << endl;
        }

    } while (exit == false);
}

int main()
{
    /*
    vector<Admin> admins;
    vector<Customer> customers;
    */

    // Temporary hardcoded Admins
    vector<Admin> admins = {
        Admin("A001", "TestAdmin", "testadmin", "123"),
        Admin("A002", "Bob", "bob@admin.com", "123"),
        Admin("A003", "Charlie", "charlie@admin.com", "123"),
        Admin("A004", "Diana", "diana@admin.com", "123"),
        Admin("A005", "Evan", "evan@admin.com", "123")};

    // Temporary hardcoded Customers
    vector<Customer> customers = {
        Customer("C001", "TestUser", "testuser", "123"),
        Customer("C002", "Gina", "gina@user.com", "123"),
        Customer("C003", "Hassan", "hassan@user.com", "123"),
        Customer("C004", "Isha", "isha@user.com", "123"),
        Customer("C005", "Junaid", "junaid@user.com", "123")};

    vector<Flight> flights = {
        Flight("PK301", "Karachi", "Lahore", "08:00", "2025-04-20", 1020, 100),
        Flight("PK302", "Lahore", "Islamabad", "11:00", "2025-04-21", 380, 80),
        Flight("PK303", "Karachi", "Islamabad", "14:00", "2025-04-22", 1200, 90),
        Flight("PK304", "Islamabad", "Quetta", "17:00", "2025-04-23", 700, 60),
        Flight("PK305", "Lahore", "Karachi", "20:00", "2025-04-24", 1020, 110),
    };

    bool exit = false;
    int choice = 0; // selects the option to choose
    // here choice = 0 ->Admin\\ and choice = 1->Customer

    int maxChoices = 2; // used as an upper limit so choice cannot be higher than this
    // lower limit is always 0

    string menuOptions[3] = {"Admin", "Customer", "Exit"};
    // int scr = 130;
    int key; // variable to take input from the user
    do
    {
        system("cls");
        getAirportManagementSystemText();
        printLine(screenWidth, CYAN);
        printText("Who Is Using?", screenWidth, WHITE, true);
        printLine(screenWidth, CYAN);

        for (int i = 0; i < 3; i++)
        {
            if (choice == i)
            {
                printText(string("=> ") + to_string(i + 1) + ". " + menuOptions[i], screenWidth, YELLOW, true);
            }

            else
            {
                printText(to_string(i + 1) + ". " + menuOptions[i], screenWidth, WHITE, true);
            }
        }
        printLine(screenWidth, CYAN);

        hideCursor();
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
            case 0: // admin
                registerAndLoginScreen(admins, customers, flights, true);
                break;
            case 1: // customer
                registerAndLoginScreen(admins, customers, flights, false);
                break;
            case 2:
                exit = true;
            default:
                break;
            }
        }
        else
        {
            // cout << "Use W and S to navigate";
        }
    } while (exit == false);
    return 0;
}
