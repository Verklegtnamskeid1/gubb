#ifndef BASEREPOSITORY_H
#define BASEREPOSITORY_H

#include <QtSql>

class BaseRepository{
    protected:
        QSqlDatabase db;

        bool createConnection();
        QSqlDatabase getDatabaseConnection();

};

#endif // BASEREPOSITORY_H
