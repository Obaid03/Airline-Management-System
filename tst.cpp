#include <iostream>
#include "ConsoleManipulation.h"
#include <string>
#define YELLOW "\033[33m"
using namespace std;


int main() {
   string str = "Test";
    cout << toLowercase(str);
}

// printText("+======================+", scre, YELLOW, true)