#include <iostream>
#include "ConsoleManipulation.h"
#include <string>
#define YELLOW "\033[33m"
using namespace std;
int screenWidth = 20;


void print(string color, string text) {
    cout << color << text ;
}

int main() {
    gotoxy(60,14);
    cout << ".\n";
    system("pause");
}
// printText("+======================+", scre, YELLOW, true)