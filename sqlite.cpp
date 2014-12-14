#include "sqlite.h"
#include <iostream>
sqlite::sqlite()
{
    /* Skilgreina default */
    DefaultSort["sortby"] = QString("");
    DefaultSort["sortorder"] = ASC;
    TablesDef[QString("persons")] = {"Persons_ID", "Persons_Name",
                                      "Persons_Sex","Persons_YearBorn",
                                      "Persons_YearDeath"};
    TablesDef[QString("computers")] = {"Computers_ID", "Computers_Name",
                                        "Computers_YearBuilt", "Computers_Type",
                                        "Computers_Type", "Computers_BuiltOrNot"};
    TablesDef[QString("owners")] = {"Persons_ID", "Computers_ID"};

    /* Skilgreinir hvaða SQL dræver hún á að nota */
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Skil2.sqlite");

    if (db.isValid())
    {

        db.open();
        if (db.isOpen())
        {
            qDebug ("Database is open!");
            return;

        }
    }


}
QString sqlite::searchstring(QHash<QString,QString> WHAT)
{
    QString searchstring = "";
    int a = 0;
    foreach (QString string, WHAT.keys())
    {

            /* Þurfum bara eitt einsog er */
            searchstring = " WHERE UPPER(";
            searchstring = searchstring +  string + ") LIKE UPPER('%steve%')";

    }

    return searchstring;
}

QString sqlite::sortstring(QHash<QString,QString> SORT)
{
    QString sort = "";
    if (SORT["sortorder"] != ASC && SORT["sortorder"] != DESC) SORT["sortorder"] = ASC;
    if (SORT["sortby"] == "") sort = "";
    else sort = " ORDER BY "+ SORT["sortby"] + " COLLATE NOCASE " + SORT["sortorder"];

    return sort;
}

QMap<int, QHash<QString, QString> > sqlite::query(QString TABLE,
                   QHash<QString,QString> WHAT,
                   QHash<QString,QString> SORT,
                                   bool islike)
{
    QMap<int, QHash<QString, QString> > buffer;
    // Tjekka hvort sé valid tafla
    if (!tables.contains(TABLE))
    {
        qDebug() << "Table " << TABLE << " is not valid!";
        return buffer;
    }

    QString getstring = "";
    int a = 0;
    foreach (QString string, TablesDef[TABLE])
    {
        if (a == 0) getstring = string;
        else getstring = getstring + "," + string;
        a++;
    }

    QSqlQuery searchQuery;
    searchQuery = QSqlQuery(db);
    QString searchWHERE = "";
    foreach (QString string, WHAT.keys())
    {
           if (islike)
            searchWHERE = " WHERE UPPER ($$ID$$) LIKE UPPER ('%$$STRING$$%')";
           else {
               searchWHERE = " WHERE $$ID$$ = $$STRING$$";
           }

           searchWHERE.replace("$$ID$$", string);
           searchWHERE.replace("$$STRING$$", WHAT[string]);

    }

    QString sortSTRING = sortstring(SORT);
    QString SQL = "SELECT "+getstring+" FROM "+TABLE+searchWHERE+sortSTRING;
    searchQuery.clear();
    searchQuery.prepare(SQL);
    if (!searchQuery.exec())
    {
        qDebug() << "SQL QUERY ERROR:" << searchQuery.lastError().text();
        return buffer;
    }

    int c = 0;
    while(searchQuery.next())
    {
        QHash<QString, QString> buffer2;
        int d = 0;
        foreach (QString string, TablesDef[TABLE])
        {
            buffer2.insert(string, searchQuery.value(d).toString());
            d++;
        }
        buffer.insert(c, buffer2);
        c++;
    }
    buffer[0]["RecordSize"] = QString::number(c);
    return buffer;
}

/* DELETE */
void sqlite::deleteid(QString TABLE, QString row, int id)
{
    if (!tables.contains(TABLE))
    {
        qDebug() << "Table " << TABLE << " is not valid!";
        return;
    }

    if (!TablesDef[TABLE].contains(row))
    {
        qDebug() << "Invalid column " << row << " in table " << TABLE;
        return;
    }

    QString SQL = "DELETE FROM "+TABLE+ "WHERE "+row+"="+id;

    QSqlQuery searchQuery;
    searchQuery = QSqlQuery(db);
    searchQuery.clear();
    searchQuery.prepare(SQL);
    if (!searchQuery.exec())
    {
        qDebug() << "SQL QUERY ERROR:" << searchQuery.lastError().text();
        return;
    }
}


/* INSERT */
void sqlite::insert(QString TABLE, QHash<QString, QString> insert)
{
    if (!tables.contains(TABLE))
    {
        qDebug() << "Table " << TABLE << " is not valid!";
        return;
    }

    QString rows;
    int a = 0;
    foreach (QString string, insert.keys())
    {
       if (!TablesDef[TABLE].contains(string))
       {
           qDebug() << "Invalid column " << string << " in table " << TABLE;
           return;
       }


       if (a == 0) rows = " ("+string;
       else rows = rows + ", " + string;
        a++;
    }
    rows = rows + ") VALUES ";

    a= 0;
    foreach (QString string, insert.keys())
    {
        if (a == 0) rows = rows + "(" + QString(":")+string;
        else rows = rows + ", " + ":"+string;
        a++;
    }

    rows = rows + ")";

    QString sql = "INSERT INTO "+TABLE+rows;

    QSqlQuery searchQuery;
    searchQuery = QSqlQuery(db);
    searchQuery.clear();

    searchQuery.prepare(sql);
    foreach (QString string, insert.keys())
    {

        searchQuery.bindValue(":"+string, insert[string]);
    }

    searchQuery.exec();





}


const QString sqlite::ASC = QString("ASC");
const QString sqlite::DESC = QString("DESC");


const QStringList sqlite::tables = {"persons", "owners", "computers"};

