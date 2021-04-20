#include "mainwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <qlabel.h>
#include <QList>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <loginwindow.h>
#include <QWidget>
#include "MainWidget.h"

MainWindow::MainWindow(INotesController& notesController, IUsersController& usersController, QWidget *parent)
        : QMainWindow(parent)
{
    setWindowTitle("Super-puper schodennyk");
    setGeometry(100, 100, 400, 500);
    setMinimumSize(200, 200);

    LoginWindow* loginWidget = new LoginWindow(this, usersController, notesController);
    MainWindow::setCentralWidget(loginWidget);
    loginWidget->show();
}



//void MainWindow::openLogin(IClient& controller){
//    if(controller.isLogined() == false){
//        setWindowTitle("pasasi");
//    }
//}

MainWindow::~MainWindow()
{

}
