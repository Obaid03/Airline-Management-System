//
// Created by muhammad-ibrahim on 3/23/25.
//

#ifndef USER_H
#define USER_H


class User {
private:
    string userID;
    string userName;
    string userEmail;
    string userPassword;

public:
    User(string userID, string userName, string userEmail, string userPassword) : userID(userID), userName(userName), userEmail(userEmail), userPassword(userPassword) {};
    

};

#endif //USER_H
