#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "sk2data.h"

struct searchdef
{
    int sort;
    int sortby;

    searchdef(int sortget, int sortbyget):
        sort(sortget),
        sortby(sortbyget)
    {}
    searchdef()
    {}
};

class ConsoleUI
{
public:
    ConsoleUI();
    void start();
private:
    void List();
    void Search();
    void AddPerson();
    void Print(QVector<QHash<QString, QString> > buffer);
    void Delete();

    bool SearchASC();

    sk2data gogn;

    void quitmsg();
    QString DefineSearch();
    void ComputerConnection();
    void PersonConnection();
    void AddConnection();
    void AddComputer();
    void Add();
    void ListPerson(QString searchrow = "", QString searchfor = "");
    void ListComputer(QString searchrow = "", QString searchfor = "");
    void ListConnection(QString searchrow = "", QString searchfor = "");
    void DeletePerson(int deleteID);
    void DeleteComputer(int deleteID);
    void DeleteConnection(int deleteID);
    void SearchPerson();
    void SearchComputer();
    void SearchConnection();
    QString DefineSearchPersons();
    QString DefineSearchComputer();
    QString DefineSearchConnection();
};

extern QTextStream cout;
extern QTextStream cin;

#endif // CONSOLEUI_H
