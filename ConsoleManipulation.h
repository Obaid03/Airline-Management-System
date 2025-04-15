#ifndef CONSOLE_H
#define CONSOLE_H

#include <iostream>
using namespace std;

// The Airport Management Text that appears on top of login screen
void getAirportManagementSystemText();

bool isValidEmail(const string &email);

string toLowercase(string s);

ostream &printText(const string &textToPrint, int screenWidth, const string &color, bool isCenter);

ostream &printLine(int screenWidth, const string &color);

ostream &printLineD(int screenWidth, const string &color);

ostream &printLineS(int screenWidth, const string &color);

void gotoxy(int x, int y);

void hideCursor();

void clearScreen();

#endif
