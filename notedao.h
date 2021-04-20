#pragma once
#ifndef NOTEDAO_H
#define NOTEDAO_H
#include<string>
#include <vector>
#include "note.h"
#include <QtSql>
using namespace std;

class NoteDAO
{
public:
    NoteDAO(QSqlDatabase& sdb);
    ~NoteDAO();
    Note& AddNote(const string& title, const  string& text, const int& userId);
    Note GetNote(const int& id) ;
    vector<Note> GetAllNotes();
    vector<Note> GetAllNotesByUserId(const int& id);
    void DisplayAll() const;

private:
    int nextNoteId = 0;
    vector<Note> notes;
    QSqlDatabase sdb;
};

#endif // NOTEDAO_H
