#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H
#include <QWindow>
#include <QWidget>
#include <QDialog>
#include <QLineEdit>
#include <QTextEdit>
#include "IUsersController.h"
#include "INotesController.h"
#include <QMainWindow>


class LoginWindow : public QWidget
{
    Q_OBJECT
private slots:
            void loginCommand();
private:
    QLineEdit *inputLoginText;
    QLineEdit *inputLogin;
    QLineEdit *inputPasswordText;
    QLineEdit *inputPassword;

    QPushButton *okButton;

    IUsersController *usersController;
    INotesController *notesController;

    QMainWindow *parent;
public:
    LoginWindow(QMainWindow *parent, IUsersController& usersController, INotesController& notesController);
    ~LoginWindow();
};

#endif // LOGINWINDOW_H
