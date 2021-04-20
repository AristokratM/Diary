#include "mainwindow.h"
#include "notescontroller.h"
#include <QApplication>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IClient* notesController = new Client();
    MainWindow* mw = new MainWindow(*notesController);
    mw->show();
    return a.exec();
}
