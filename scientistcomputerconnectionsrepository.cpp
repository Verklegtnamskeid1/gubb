#include "scientistcomputerconnectionsrepository.h"

ScientistComputerConnectionsRepository::ScientistComputerConnectionsRepository()
{
    createConnection();
}

std::list<Computer> ScientistComputerConnectionsRepository::getAllComputersByScientistId(std::string id)
{
    std::list<Computer> computerList = std::list<Computer>();

    QSqlQuery query(db);

    query.prepare("SELECT c.* FROM Computers c "
                  "INNER JOIN ScientistComputerConnections scc "
                  "ON c.ID = scc.c_ID "
                  "WHERE scc.s_ID = :sid "
                  "ORDER BY c.Name");
    query.bindValue(":sid", QString::fromStdString(id));

    query.exec();

    populateComputerList(computerList, query);

    return computerList;
}

std::list<Scientist> ScientistComputerConnectionsRepository::getAllScientistsByComputerId(std::string id)
{
    std::list<Scientist> scientistList = std::list<Scientist>();
    QSqlQuery query(db);

    query.prepare("SELECT s.* FROM Scientists s "
                  "INNER JOIN ScientistComputerConnections scc "
                  "ON s.ID = scc.s_ID "
                  "WHERE scc.c_ID = :sid "
                  "ORDER BY s.Name");
    query.bindValue(":sid", QString::fromStdString(id));

    query.exec();

    populateScientistList(scientistList, query);

    return scientistList;
}

void ScientistComputerConnectionsRepository::populateComputerList(std::list<Computer> &computerList, QSqlQuery query){
    while(query.next()){
        Computer c = Computer();
        c.setId(query.value("ID").toInt());
        c.setName(query.value("Name").toString().toStdString());
        c.setYearBuilt(query.value("YearBuilt").toString().toStdString());
        c.setType(query.value("Type").toInt());
        c.setWasBuilt(query.value("WasBuilt").toInt());

        computerList.push_back(c);
    }
}

void ScientistComputerConnectionsRepository::populateScientistList(std::list<Scientist> &scientistList, QSqlQuery query)
{
    while(query.next()){
        Scientist s = Scientist();
        s.setId(query.value("ID").toInt());
        s.setName(query.value("Name").toString().toStdString());
        s.setDateOfBirth(query.value("DateOfBirth").toString().toStdString());
        s.setDateOfDeath(query.value("DateOfDeath").toString().toStdString());
        s.setGender(query.value("Gender").toString().toStdString());

        scientistList.push_back(s);
    }
}

bool ScientistComputerConnectionsRepository::addConnection(std::string sid, std::string cid)
{
    QSqlQuery query(db);

    int s = std::atoi(sid.c_str());
    int c = std::atoi(cid.c_str());

    query.prepare("INSERT INTO ScientistComputerConnections(s_ID, c_ID) VALUES(:sid, :cid)");
    query.bindValue(":sid", s);
    query.bindValue(":cid", c);

    bool result = query.exec();
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    return result;
}

bool ScientistComputerConnectionsRepository::removeConnection(std::string sid, std::string cid)
{
    QSqlQuery query(db);

    int s = std::atoi(sid.c_str());
    int c = std::atoi(cid.c_str());

    query.prepare("DELETE FROM ScientistComputerConnections "
                  "WHERE s_ID = :sid "
                  "AND c_ID = :cid");
    query.bindValue(":sid", s);
    query.bindValue(":cid", c);

    bool result = query.exec();
    qDebug() << query.lastError();
    qDebug() << query.lastQuery();
    return result;
}
