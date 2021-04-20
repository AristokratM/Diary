#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>
#include <QListWidget>
#include <QPushButton>
#include "INotesController.h"
#include "IUsersController.h"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(INotesController& notesController, IUsersController& usersController, QWidget *parent = nullptr);
    ~MainWindow();
private slots:
//            void openLogin(INotesController& controller);
private:
    INotesController *notesController;

};
#endif // MAINWINDOW_H
