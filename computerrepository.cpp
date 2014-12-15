#include "computerrepository.h"

ComputerRepository::ComputerRepository() {
    createConnection();
}

ComputerRepository::~ComputerRepository() {
}

void ComputerRepository::add(Computer computer) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO Computers (Name, YearBuilt, Type, WasBuilt) VALUES (:name,:yb,:type,:wb)");
    query.bindValue(":name",    QString::fromStdString(computer.getName()));
    query.bindValue(":yb",      QString::fromStdString(computer.getYearBuilt()));
    query.bindValue(":type",    QString::number(computer.getType()));
    query.bindValue(":wb",      QString::number(computer.getWasBuilt()));

    query.exec();
}

void ComputerRepository::remove(std::string id) {
    QSqlQuery query(db);

    query.prepare("DELETE FROM Computers WHERE id = :id");
    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();

    query.prepare("DELETE FROM ScientistComputerConnections WHERE c_ID = :id");

    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();
}

std::list<Computer> ComputerRepository::list() {
    return list("","");
}

std::list<Computer> ComputerRepository::list(std::string col, std::string mod) {
    std::list<Computer> computerList = std::list<Computer>();

    QSqlQuery query(db);
    std::string orderBy = "";

    if(!col.empty()){
        mod = mod.empty() ? "ASC" : (mod.find("desc") != std::string::npos ? "DESC" : "ASC");
        orderBy = "order by " + col + " " + mod;

    }
    query.exec("SELECT * FROM Computers " + QString::fromStdString(orderBy));

    populateComputerList(computerList, query);

    return computerList;

}

std::list<Computer> ComputerRepository::search(std::string searchTerm) {
    // Naive search implementation, finds a substring in the name field
    std::list<Computer> computerList = std::list<Computer>();

    QSqlQuery query(db);

    std::string q = "SELECT * FROM Computers WHERE Name LIKE '%"+searchTerm+"%'";

    query.exec(QString::fromStdString(q));

    populateComputerList(computerList, query);

    return computerList;
}

void ComputerRepository::populateComputerList(std::list<Computer> &computerList, QSqlQuery query){
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
