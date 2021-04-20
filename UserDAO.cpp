#include "UserDAO.h"

#include <stdexcept>

UserDAO::UserDAO()
{
    AddUser("user1", "112345");
    AddUser("user2", "212345");
    AddUser("user3", "312345");
    AddUser("user4", "412345");
}
UserDAO::~UserDAO() {

}

User& UserDAO::AddUser(const string& login, const  string& password) {
    User* user = new User();
    user->setLogin(login);
    user->setPassword(password);
    user->setId(nextUserId++);
    QSqlQuery query;
    query.prepare("INSERT INTO Users(id, login, password) "
            "VALUES(:id, :login, :password);");

    query.bindValue(":id", user->getId());
    query.bindValue(":title", QString::fromStdString(user->getLogin()));
    query.bindValue(":text", QString::fromStdString(user->getLogin()));
    if (!query.exec())
    {
        qDebug() << "Кажется данные не вставляются, " + query.lastError().text();
    }
    return *user;
}

vector<User> UserDAO::GetAllUsers() {
    QString str = "SELECT * FROM Users;";
    QSqlQuery query;
    if (query.exec(str))
    {
        QSqlRecord record = query.record();
        int id = 0;
        QString login = "", password = "";

        while (query.next())
        {
            id = query.value(record.indexOf("id")).toInt();
            login = query.value(record.indexOf("login")).toString();
            password = query.value(record.indexOf("password")).toString();

            User *user = new User();
            user->setId(id);
            user->setLogin(login.toStdString());
            user->setPassword(password.toStdString());
            users.push_back(*user);
         }
    }
    return users;
}

User UserDAO::GetUser(const int& id) {
    QSqlQuery query;
    query.prepare("SELECT * FROM Users WHERE id=:id)");
    query.bindValue("id", id);
    if (query.exec())
    {
        QSqlRecord record = query.record();
        int id = 0;
        QString login = "", password = "";
            id = query.value(record.indexOf("id")).toInt();
            login = query.value(record.indexOf("login")).toString();
            password = query.value(record.indexOf("password")).toString();

            User *user = new User();
            user->setId(id);
            user->setLogin(login.toStdString());
            user->setPassword(password.toStdString());
    }
    throw logic_error("No user found!");
}
void UserDAO::DisplayAll() const {
    for(auto user: users) {
        user.Display();
    }
}
