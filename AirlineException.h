// AirlineException.h
#ifndef AIRLINE_EXCEPTION_H
#define AIRLINE_EXCEPTION_H

#include <string>
#include <exception>
using namespace std;
class AirlineException : public exception {
private:
    string message;

public:
    AirlineException(const string& msg) : message(msg) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif