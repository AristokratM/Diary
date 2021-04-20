#pragma once
#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QCalendarWidget>
#include <QListWidget>
#include <QPushButton>
#include "INotesController.h"

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    MainWidget(INotesController& notesController, int userId, QWidget *parent = nullptr);
    ~MainWidget();

    int getUserId() const;
    void setUserId(int value);

private slots:
    void handleButton();
    void refreshList();
    void resfreshNoteTextField();
    void saveFile();
private:
    int        userId;
    QTextEdit *inputFieldNoteText;
    QLineEdit *inputFieldNoteTitle;
    QLineEdit *titleLb;
    QLineEdit *textLb;
    QTextEdit *outputField;

    QListWidget *uiNotes;

    QPushButton *okButton;
    QPushButton *loadFileBtn;

    INotesController *notesController;
    vector<Note> listNotes;
};


#endif // MAINWIDGET_H
