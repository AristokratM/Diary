#include "mainwindow.h"
#include "notescontroller.h"
#include <QApplication>
#include <QLabel>
#include <QtSql>

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
    NoteDAO* noteDAO = new NoteDAO(sdb);
    INotesController* notesController = new NotesController(*noteDAO);
    MainWindow* mw = new MainWindow(*notesController);
    mw->show();
//    QLabel *label = new QLabel("Diary");
//    label->resize(400, 400);
//    label->show();
    return a.exec();
}
