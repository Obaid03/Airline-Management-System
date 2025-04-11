


//contains all functions to manipulate the terminal screen
#ifndef CONSOLE_H
#define CONSOLE_H
#include <iostream>
#include <windows.h>
using namespace std;

//The Airport Management Text that appears on top of login screen
void getAirportManagementSystemText() {
    cout << "\n           _      _ _              __  __                                                   _      _____           _                 \n     /\\   (_)    | (_)            |  \\/  |                                                 | |    / ____|         | |                \n    /  \\   _ _ __| |_ _ __   ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  \n   / /\\ \\ | | '__| | | '_ \\ / _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n  / ____ \\| | |  | | | | | |  __/ | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | \n /_/    \\_\\_|_|  |_|_|_| |_|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| \n                                                             __/ |                                        __/ |                      \n                                                            |___/                                        |___/                        \n\n" << endl;
}
void getCustomerText() {
    cout << "\n _____ _ \n / ____| | | \n | | _ _ ___| |_ ___ _ __ ___ ___ _ __ \n | | | | | / __| __/ _ \\| '_ ` _ \\ / _ \\ '__|\n | |___| |_| \\__ \\ || (_) | | | | | | __/ | \n \\_____\\__,_|___/\\__\\___/|_| |_| |_|\\___|_| \n \n \n\n";
}
void getAdminText() {
    cout << "\n_ _ \n /\\ | | (_) \n / \\ __| |_ __ ___ _ _ __ \n / /\\ \\ / _` | '_ ` _ \\| | '_ \\ \n / ____ \\ (_| | | | | | | | | | |\n /_/ \\_\\__,_|_| |_| |_|_|_| |_|\n";
}
void getPanelText() {
    cout << "\n _____ _ \n | __ \\ | |\n | |__) |_ _ _ __ ___| |\n | ___/ _` | '_ \\ / _ \\ |\n | | | (_| | | | | __/ |\n |_| \\__,_|_| |_|\\___|_|\n";
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
