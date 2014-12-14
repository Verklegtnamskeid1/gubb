#ifndef SQLITE_H
#define SQLITE_H
#include <QtSql>




class sqlite
{
public:
    sqlite();
    static const QString ASC;
    static const QString DESC;

    QHash<QString, QString> DefaultSort;
    QHash<QString,QString> EmptySearch;
    void test();
    void insert(QString TABLE, QHash<QString, QString> insert);

    QMap<int, QHash<QString, QString> > query(QString TABLE,
                       QHash<QString,QString> WHAT,
                       QHash<QString,QString> SORT,
                                              bool islike = true);

    void deleteid(QString TABLE, QString row, int id);


private:
   static const QStringList tables;
   static const QStringList PersonsTable;
   static const QStringList ComputersTable;
   static const QStringList OwnersTable;
   QHash<QString, QStringList> TablesDef;
   QString searchstring(QHash<QString,QString> WHAT);
   QString sortstring(QHash<QString,QString> SORT);


   /* Taflan Persons er
    * Persons_ID(int) Persons_Name(String) Person_Sex(String) Person_YoB(int) Person_YoD(int)
    *
    * Taflan Owners er
    * Computers_ID Persons_ID
    *
    * Taflan Computers er:
    * Computers_ID(int) Name(string) YearBuilt (int) Type (string) BuiltOrNot(bool)
*/
   QSqlDatabase db;
};

#endif // SQLITE_H
