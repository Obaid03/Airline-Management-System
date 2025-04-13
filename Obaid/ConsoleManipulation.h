


//contains all functions to manipulate the terminal screen
#ifndef CONSOLE_H
#define CONSOLE_H
#define RESET "\033[0m"
#define BLACK "\033[30m"   /* Black */
#define RED "\033[31m"     /* Red */
#define GREEN "\033[32m"   /* Green */
#define YELLOW "\033[33m"  /* Yellow */
#define BLUE "\033[34m"    /* Blue */
#define MAGENTA "\033[35m" /* Magenta */
#define CYAN "\033[36m"    /* Cyan */
#define WHITE "\033[37m"
#include <iostream>
#include <windows.h>
using namespace std;

//The Airport Management Text that appears on top of login screen
void getAirportManagementSystemText() {
    cout << "\n           _      _ _              __  __                                                   _      _____           _                 \n     /\\   (_)    | (_)            |  \\/  |                                                 | |    / ____|         | |                \n    /  \\   _ _ __| |_ _ __   ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  \n   / /\\ \\ | | '__| | | '_ \\ / _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n  / ____ \\| | |  | | | | | |  __/ | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | \n /_/    \\_\\_|_|  |_|_|_| |_|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| \n                                                             __/ |                                        __/ |                      \n                                                            |___/                                        |___/                        \n\n" << endl;
}

void printSpaces(int noOfSpaces) {
    for(int i = 0 ; i < noOfSpaces; i++) {
        cout << " ";
    }
}
void printLine(int noOfDashes){
    cout << BLUE << "+";
    for(int i = 0; i < noOfDashes; i++) {
        cout << "-";
    }
    cout << "+"<<endl;
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor() {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

#endif 
