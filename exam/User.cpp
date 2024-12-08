// User.cpp
#include "User.h"

User::User(std::string user, std::string pass) : username(user), password(pass) {}

bool User::authenticate(const std::string& user, const std::string& pass) const {
    return username == user && password == pass;
}
