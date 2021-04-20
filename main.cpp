#include "mainwindow.h"
#include "notescontroller.h"
#include <QApplication>
#include <QLabel>
#include <QtSql>
#include "notescontroller.h"
#include "UsersController.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase sdb = QSqlDatabase::addDatabase("QSQLITE");
    sdb.setDatabaseName("Diary.sqlite");
    if (!sdb.open())
    {
        qDebug() << sdb.lastError().text();
    }

    if(!sdb.open())
    {
        qDebug() << "Что-то не так с соединением!";
        return -1;
    }
    NoteDAO* noteDAO = new NoteDAO();
    UserDAO* userDAO = new UserDAO();
    INotesController* notesController = new NotesController(*noteDAO);
    IUsersController* usersController = new UsersController(*userDAO);
    MainWindow* mw = new MainWindow(*notesController, *usersController);
    mw->show();
    return a.exec();
}
