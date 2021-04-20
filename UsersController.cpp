#include "UsersController.h"

#include <UserWindow.h>

UsersController::UsersController(UserDAO& userDAO)
{
    this->userDAO = &userDAO;
    this->view = new UserWindow(*this);
}

User& UsersController::AddUser(const string &login, const string &password)
{
    return  userDAO->AddUser(login, password);
}

User UsersController::GetUser(const int &id)
{
    return userDAO->GetUser(id);
}

vector<User> UsersController::GetAllUsers()
{
    return userDAO->GetAllUsers();
}
bool UsersController::CorrectLoginAndPassword(const string& login, const  string& password) {
    return userDAO->CorrectLoginAndPassword(login, password);
}
