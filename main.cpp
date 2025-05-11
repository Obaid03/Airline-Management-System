#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <exception>

#include "Flight.h"
#include "User.h"
#include "ConsoleManipulation.h"
#include "Constants.h"
#include "FileHelper.h"

using namespace std;

const string FLIGHTS_FILE = "flights.csv";
const string ADMINS_FILE = "admins.csv";
const string CUSTOMERS_FILE = "customers.csv";

class FileException : public exception
{
    string message;

public:
    FileException(const string &msg) : message(msg) {}
    const char *what() const noexcept override
    {
        return message.c_str();
    }
};

void saveAllData(bool showMessage, const vector<Admin> &admins, const vector<Customer> &customers, const vector<Flight> &flights)
{
    FileHelper::saveFlights(flights, FLIGHTS_FILE);
    FileHelper::saveAdmins(admins, ADMINS_FILE);
    FileHelper::saveCustomers(customers, CUSTOMERS_FILE);

    if (showMessage)
    {
        printLine(screenWidth, CYAN);
        printText("All data saved successfully!", screenWidth, GREEN, true);
        printLine(screenWidth, CYAN);
        system("pause");
    }
}

// Generate unique ID for new users
string generateUniqueID(bool isAdmin, const vector<Admin> &admins, const vector<Customer> &customers)
{
    string prefix = isAdmin ? "A" : "C";

    // Choose the appropriate vector based on isAdmin
    int count;
    if (isAdmin)
    {
        count = admins.size();
    }
    else
    {
        count = customers.size();
    }

    // Generate the ID with the prefix and count
    return prefix + to_string(count + 1);
}

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
    printLine(screenWidth, CYAN);
    printText("USER REGISTRATION", screenWidth, GREEN, true);
    printLine(screenWidth, CYAN);

    string temp, passRepeat;
    bool isValid = false;
    User *newUser;

    // Generate unique ID for the new user
    string userID = generateUniqueID(isAdmin, admins, customers);

    Admin admin(userID, "", "", "");
    Customer customer(userID, "", "", "");

    if (isAdmin)
        newUser = &admin;
    else
        newUser = &customer;

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
        else
        {
            printLine(screenWidth, CYAN);
            printText("Email Not Valid! Enter Again", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }
    } while (!isValid);

    do
    {
        printText("Enter password for User", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        cin >> temp;
        printText("Repeat password", screenWidth, WHITE, false);
        cout << CYAN << "|=>>>> " << RESET;
        cin >> passRepeat;
        if (temp == passRepeat)
        {
            newUser->setUserPassword(passRepeat);
        }
        else
        {
            printLine(screenWidth, CYAN);
            printText("Passwords do not match! Enter Again", screenWidth, RED, true);
            printLine(screenWidth, CYAN);
        }
    } while (temp != passRepeat);

    if (isAdmin)
    {
        admins.push_back(admin);
        FileHelper::saveAdmins(admins, ADMINS_FILE); // Save admins to file
    }
    else
    {
        customers.push_back(customer);
        FileHelper::saveCustomers(customers, CUSTOMERS_FILE); // Save customers to file
    }

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
        }
        else if ((key == 's' || key == 'S' || key == 80) && (choice < maxChoices))
        {
            choice++;
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
                break;
            default:
                break;
            }
        }
    } while (exit == false);
}

int main()
{
    // Initialize default vectors
    vector<Admin> admins;
    vector<Customer> customers;
    vector<Flight> flights;

    bool fileExist = false;

    try
    {
        // Try to open the files
        ifstream flightsCheck(FLIGHTS_FILE);
        ifstream adminsCheck(ADMINS_FILE);
        ifstream customersCheck(CUSTOMERS_FILE);

        if (!flightsCheck.good())
            throw FileException("Flights file not found: " + FLIGHTS_FILE);
        if (!adminsCheck.good())
            throw FileException("Admins file not found: " + ADMINS_FILE);
        if (!customersCheck.good())
            throw FileException("Customers file not found: " + CUSTOMERS_FILE);

        fileExist = true;
        // Close file checks
        flightsCheck.close();
        adminsCheck.close();
        customersCheck.close();
    }
    catch (const FileException &fe)
    {
        fileExist = false;
        printLine(screenWidth, RED);
        printText("File Error: " + string(fe.what()), screenWidth, RED, true);
        printLine(screenWidth, RED);
        system("pause");
    }

    if (fileExist)
    {

        // Load data from files
        flights = FileHelper::loadFlights(FLIGHTS_FILE);
        admins = FileHelper::loadAdmins(ADMINS_FILE);
        customers = FileHelper::loadCustomers(CUSTOMERS_FILE, flights);

        printLine(screenWidth, CYAN);
        printText("Data loaded from files", screenWidth, GREEN, true);
        printLine(screenWidth, CYAN);
    }
    else
    {
        // harcoded data for test purpose
        admins = {
            Admin("A001", "TestAdmin", "testadmin", "123"),
            Admin("A002", "Bob", "bob@admin.com", "123"),
            Admin("A003", "Charlie", "charlie@admin.com", "123"),
            Admin("A004", "Diana", "diana@admin.com", "123"),
            Admin("A005", "Evan", "evan@admin.com", "123")};

        customers = {
            Customer("C001", "TestUser", "testuser", "123"),
            Customer("C002", "Gina", "gina@user.com", "123"),
            Customer("C003", "Hassan", "hassan@user.com", "123"),
            Customer("C004", "Isha", "isha@user.com", "123"),
            Customer("C005", "Junaid", "junaid@user.com", "123")};

        flights = {
            Flight("PK301", "Karachi", "Lahore", 8, 1, 20, 4, 2025, 1020, 100),
            Flight("PK302", "Lahore", "Islamabad", 11, 2, 21, 4, 2025, 380, 80),
            Flight("PK303", "Karachi", "Islamabad", 14, 3, 22, 4, 2025, 1200, 90),
            Flight("PK304", "Islamabad", "Quetta", 17, 4, 23, 4, 2025, 700, 60),
            Flight("PK305", "Lahore", "Karachi", 20, 5, 24, 4, 2025, 1020, 110),
        };

        // Save default data to files

        printLine(screenWidth, CYAN);
        saveAllData(false, admins, customers, flights);
        printLine(screenWidth, CYAN);

        printLine(screenWidth, CYAN);
        printText("Dummy Data Entered into Files (For Test Purposes)", screenWidth, GREEN, true);
        printLine(screenWidth, CYAN);
        system("pause");
    }

    bool exit = false;
    int choice = 0;
    int maxChoices = 3;

    string menuOptions[4] = {"Admin", "Customer", "Save All Data", "Exit"};
    int key;

    do
    {
        system("cls");
        getAirportManagementSystemText();
        printLine(screenWidth, CYAN);
        printText("Who Is Using?", screenWidth, WHITE, true);
        printLine(screenWidth, CYAN);

        for (int i = 0; i < 4; i++)
        {
            if (choice == i)
                printText("=> " + to_string(i + 1) + ". " + menuOptions[i], screenWidth, YELLOW, true);
            else
                printText(to_string(i + 1) + ". " + menuOptions[i], screenWidth, WHITE, true);
        }

        printLine(screenWidth, CYAN);
        hideCursor();
        key = _getch();

        if ((key == 'w' || key == 'W' || key == 72) && (choice > 0))
            choice--;
        else if ((key == 's' || key == 'S' || key == 80) && (choice < maxChoices))
            choice++;
        else if (key == '\r' || key == ' ')
        {
            switch (choice)
            {
            case 0:
                registerAndLoginScreen(admins, customers, flights, true);
                break;
            case 1:
                registerAndLoginScreen(admins, customers, flights, false);
                break;
            case 2:
                saveAllData(true, admins, customers, flights);
                system("pause");
                break;
            case 3:
                exit = true;
                break;
            }
        }
    } while (!exit);

    saveAllData(true, admins, customers, flights);
    return 0;
}

/*int main()
{
    // Initialize default vectors
    vector<Admin> admins;
    vector<Customer> customers;
    vector<Flight> flights;

    // Try to load data from files
    bool filesExist = false;

    ifstream flightsCheck(FLIGHTS_FILE);
    ifstream adminsCheck(ADMINS_FILE);
    ifstream customersCheck(CUSTOMERS_FILE);

    if (flightsCheck.good() && adminsCheck.good() && customersCheck.good()) {
        filesExist = true;
        flightsCheck.close();
        adminsCheck.close();
        customersCheck.close();
    } else {
        flightsCheck.close();
        adminsCheck.close();
        customersCheck.close();
    }

    if (filesExist) {
        // Load data from files
        flights = FileHelper::loadFlights(FLIGHTS_FILE);
        admins = FileHelper::loadAdmins(ADMINS_FILE);
        customers = FileHelper::loadCustomers(CUSTOMERS_FILE, flights);

        printLine(screenWidth, CYAN);
        printText("Data loaded from files", screenWidth, GREEN, true);
        printLine(screenWidth, CYAN);
     } //else {
    //     // Use default hardcoded data if files don't exist
    //     admins = {
    //         Admin("A001", "TestAdmin", "testadmin", "123"),
    //         Admin("A002", "Bob", "bob@admin.com", "123"),
    //         Admin("A003", "Charlie", "charlie@admin.com", "123"),
    //         Admin("A004", "Diana", "diana@admin.com", "123"),
    //         Admin("A005", "Evan", "evan@admin.com", "123")
    //     };

    //     customers = {
    //         Customer("C001", "TestUser", "testuser", "123"),
    //         Customer("C002", "Gina", "gina@user.com", "123"),
    //         Customer("C003", "Hassan", "hassan@user.com", "123"),
    //         Customer("C004", "Isha", "isha@user.com", "123"),
    //         Customer("C005", "Junaid", "junaid@user.com", "123")
    //     };

    //     flights = {
    //         Flight("PK301", "Karachi", "Lahore", 8, 1, 20, 4, 2025, 1020, 100),
    //         Flight("PK302", "Lahore", "Islamabad", 11, 2, 21, 4, 2025, 380, 80),
    //         Flight("PK303", "Karachi", "Islamabad", 14, 3, 22, 4, 2025, 1200, 90),
    //         Flight("PK304", "Islamabad", "Quetta", 17, 4, 23, 4, 2025, 700, 60),
    //         Flight("PK305", "Lahore", "Karachi", 20, 5, 24, 4, 2025, 1020, 110),
    //     };

    //     // Save default data to files
    //     saveAllData(admins, customers, flights);

    //     printLine(screenWidth, CYAN);
    //     printText("Default data created and saved to files", screenWidth, GREEN, true);
    //     printLine(screenWidth, CYAN);
    //     system("pause");
    // }

    bool exit = false;
    int choice = 0; // selects the option to choose
    // here choice = 0 ->Admin\\ and choice = 1->Customer\\ and choice = 2->Exit

    int maxChoices = 3; // used as an upper limit so choice cannot be higher than this
    // lower limit is always 0

    string menuOptions[4] = {"Admin", "Customer", "Save All Data", "Exit"};
    int key; // variable to take input from the user
    do
    {
        system("cls");
        getAirportManagementSystemText();
        printLine(screenWidth, CYAN);
        printText("Who Is Using?", screenWidth, WHITE, true);
        printLine(screenWidth, CYAN);

        for (int i = 0; i < 4; i++)
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
        }
        else if ((key == 's' || key == 'S' || key == 80) && (choice < maxChoices))
        {
            choice++;
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
            case 2: // save all data
                saveAllData(admins, customers, flights);
                system("pause");
                break;
            case 3: // exit
                exit = true;
                break;
            default:
                break;
            }
        }
    } while (exit == false);

    // Save all data before exiting
    saveAllData(admins, customers, flights);

    return 0;
}*/
