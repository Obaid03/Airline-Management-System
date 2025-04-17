#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>

// Importing Other Header Files
#include "Constants.h"

using namespace std;

// The Airport Management Text that appears on top of login screen
void getAirportManagementSystemText()
{
    cout << "\n           _      _ _              __  __                                                   _      _____           _                 \n     /\\   (_)    | (_)            |  \\/  |                                                 | |    / ____|         | |                \n    /  \\   _ _ __| |_ _ __   ___  | \\  / | __ _ _ __   __ _  __ _  ___ _ __ ___   ___ _ __ | |_  | (___  _   _ ___| |_ ___ _ __ ___  \n   / /\\ \\ | | '__| | | '_ \\ / _ \\ | |\\/| |/ _` | '_ \\ / _` |/ _` |/ _ \\ '_ ` _ \\ / _ \\ '_ \\| __|  \\___ \\| | | / __| __/ _ \\ '_ ` _ \\ \n  / ____ \\| | |  | | | | | |  __/ | |  | | (_| | | | | (_| | (_| |  __/ | | | | |  __/ | | | |_   ____) | |_| \\__ \\ ||  __/ | | | | | \n /_/    \\_\\_|_|  |_|_|_| |_|\\___| |_|  |_|\\__,_|_| |_|\\__,_|\\__, |\\___|_| |_| |_|\\___|_| |_|\\__| |_____/ \\__, |___/\\__\\___|_| |_| |_| \n                                                             __/ |                                        __/ |                      \n                                                            |___/                                        |___/                        \n\n"
         << endl;
}

bool isValidEmail(const string &email) {
    int atposition = -1, dotposition = -1;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') {
            if (atposition != -1) return false; 
            atposition = i;
        }
    }
    if (atposition <= 0 || atposition >= email.length() - 1) return false;
    for (int i = atposition + 1; i < email.length(); i++) {
        if (email[i] == '.') {
            if (i < email.length() - 1 && email[i + 1] != '.') {
                dotposition = i;
                break;
            }
        }
    }
    if (dotposition == -1) return false;          
    if (atposition > dotposition) return false;   
    return true;
}

string toLowercase(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] += 32;
        }
        
    }
    return s;
}

ostream &printText(const string &textToPrint, int screenWidth, const string &color, bool isCenter)
{
    int paddingBefore = isCenter ? (screenWidth - textToPrint.length()) / 2 : 0;
    int paddingAfter = screenWidth - (textToPrint.length() + paddingBefore);

    // Build the whole line first
    string fullLine = string(CYAN) + "|" + RESET +
                      string(paddingBefore, ' ') +
                      color + textToPrint + RESET +
                      string(paddingAfter, ' ') +
                      CYAN + "|" + RESET;

    cout << fullLine << endl;
    return cout;
}

//prints +----+
ostream &printLine(int screenWidth, const string &color)
{
    cout << color << "+" << string(screenWidth, '-') << "+" << RESET << endl;
    return cout;
}

//prints +===+
ostream &printLineD(int screenWidth, const string &color)
{
    cout << color << "+" << string(screenWidth, '=') << "+" << RESET << endl;
    return cout;
}

//prints spaces
ostream &printLineS(int screenWidth, const string &color)
{
    cout << color << "+" << string(screenWidth, ' ') << "+" << RESET << endl;
    return cout;
} // prints spaces

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void clearScreen()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD count;
    DWORD cellCount;

    GetConsoleScreenBufferInfo(hConsole, &csbi);
    cellCount = csbi.dwSize.X * csbi.dwSize.Y;

    FillConsoleOutputCharacter(hConsole, ' ', cellCount, {0, 0}, &count);
    FillConsoleOutputAttribute(hConsole, csbi.wAttributes, cellCount, {0, 0}, &count);
    SetConsoleCursorPosition(hConsole, {0, 0});
}
