#ifndef USERDAO_H
#define USERDAO_H
#include<string>
#include <vector>
#include "user.h"
#include <QtSql>
using namespace std;

class UserDAO
{
public:
    UserDAO();
    ~UserDAO();
    User& AddUser(const string& login, const  string& password);
    User GetUser(const int& id) ;
    vector<User> GetAllUsers();
    void DisplayAll() const;

private:
    int nextUserId = 0;
    vector<User> users;
};
#endif // USERDAO_H
