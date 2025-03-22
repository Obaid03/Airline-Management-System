/*
//before writing code
git pull origin main

//after writing code
git add .
git commit -m "Your commit message"
git push origin main
*/


//test comment
//Hasnain test comment
#include <iostream>
#include "Flight.h"
#include "User.h"
using namespace std;


void addUser() {
    
}

void menu() {
    cout << "Testing" << endl;
    int temp;
    cout << "1.Admin, 2.User";
    cin >> temp;
    switch (temp)
    {
    case 1:
        /* code */
        break;
    
    case 2:
        cout << "1.Register new User\n2.Login User" ;
        cin >> temp;
        switch (temp)
        {
        case 1:
            /* code */
            break;
        
        default:
            break;
        }    
    
    default:
        break;
    }
    
    
}


int main() {
    cout << "Hello World" << endl;
}
