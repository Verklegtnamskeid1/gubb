#ifndef SK2DATA_H
#define SK2DATA_H
#include "main.h"
#include "sqlite.h"

class sk2data
{
public:
    sk2data();
    /* Remove */
    void RemoveComputer(int id);
    void RemoveConnection(int id);
    void RemovePerson(int id);

    /* Add */
    void AddComputer(QString name, int type, int yearbuilt, int builtornot);
    void AddConnection(int personid, int computerid);
    void AddPerson(QString name, int gender, int yearborn, int yeardead);

    /* Query */

    QVector<QHash<QString, QString> > QueryComputer(QString row="Computers_ID",
                                                  bool asc = true,
                                                  QString searchrow="",
                                                  QString searchstring="");
    QVector<QHash<QString, QString> > QueryConnection(QString row="Persons_ID",
                                                  bool asc = true,
                                                  QString searchrow="",
                                                  QString searchstring="");
    QVector<QHash<QString, QString> > QueryPerson(QString row="Persons_ID",
                                                  bool asc = true,
                                                  QString searchrow="",
                                                  QString searchstring="");

    void QueryComputer(int id); /* sækja id*/
    void QueryConnection(int id);
    void QueryPerson(int id);
private:
    sqlite connection;
};

#endif // SK2DATA_H
