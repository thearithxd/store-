#pragma once// User.h
#ifndef USER_H
#define USER_H

#include <string>

class User {
private:
    std::string username;
    std::string password;

public:
    User(std::string user = "rith", std::string pass = "123");

    bool authenticate(const std::string& user, const std::string& pass) const;
};

#endif // USER_H

