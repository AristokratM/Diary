#include "loginwindow.h"
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <qlabel.h>
#include <QList>
#include <QVector>
#include <QFileDialog>
#include <QMessageBox>
#include <QWindow>
#include <QDialog>
#include "IUsersController.h"
#include "MainWidget.h"
#include "INotesController.h"



LoginWindow::LoginWindow(QMainWindow *parent, IUsersController& usersController, INotesController& notesController) : QWidget(parent)
{
    setWindowTitle("Login");
    setGeometry(100, 100, 400, 500);
    setMinimumSize(200, 200);
    int paddingX = 10;
    int paddingY = 10;

    this->parent = parent;
    this->usersController = &usersController;
    this->notesController = &notesController;

    inputLoginText = new QLineEdit("Username", this);
    inputLoginText->setGeometry(paddingX, paddingY, 70, 20);
    inputLoginText->setReadOnly(true);

    inputLogin = new QLineEdit(this);
    inputLogin->setGeometry(paddingX, paddingY+30, 100, 20);

    inputPasswordText = new QLineEdit("Password", this);
    inputPasswordText->setGeometry(paddingX, paddingY+60, 70, 20);
    inputPasswordText->setReadOnly(true);

    inputPassword = new QLineEdit(this);
    inputPassword->setGeometry(paddingX, paddingY+90, 100, 20);

    okButton = new QPushButton("Log in", this);
    okButton->setGeometry(paddingX, paddingY+120, 40, 20);
    connect(okButton, SIGNAL(released()), this, SLOT(loginCommand()));
}

void LoginWindow::loginCommand(){
    std::string login = inputLogin->text().toUtf8().constData();
    std::string password = inputPassword->text().toUtf8().constData();
    int userId = usersController->CorrectLoginAndPassword(login, password);
    if( userId != -1){
        //usersController->CorrectLoginAndPassword(login, password)
        //this->accept();
        MainWidget* widget = new MainWidget(*notesController, userId, this);
        widget->show();
        //MainWindow::setCentralWidget(loginWidget);
        parent->setCentralWidget(widget);
        close();
    } else {
        QMessageBox *msgBox = new QMessageBox(this);
            msgBox->setWindowModality(Qt::NonModal);
            msgBox->setInformativeText("Наступного разу точно вийде :) ");
            msgBox->setStandardButtons(QMessageBox::Ok);
            msgBox->setDefaultButton(QMessageBox::Ok);
            msgBox->show();
    }
}

LoginWindow::~LoginWindow(){
    delete inputLoginText;
    delete inputLogin;
    delete inputPasswordText;
    delete inputPassword;

    delete okButton;
}
