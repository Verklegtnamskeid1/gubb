#include "scientistrepository.h"
#include <stdexcept>
#include <string>
#include <iostream>

ScientistRepository::ScientistRepository() {
    createConnection();
}

ScientistRepository::~ScientistRepository() {
}

void ScientistRepository::add(Scientist scientist) {

    QSqlQuery query(db);
    query.prepare("INSERT INTO Scientists (Name, DateOfBirth, DateOfDeath, Gender) VALUES (:name,:dob,:dod,:gender)");
    query.bindValue(":name",    QString::fromStdString(scientist.getName()));
    query.bindValue(":dob",     QString::fromStdString(scientist.getDateOfBirth()));
    query.bindValue(":dod",     QString::fromStdString(scientist.getDateOfDeath()));
    query.bindValue(":gender",  QString::fromStdString(scientist.getGender()));

    query.exec();
}

void ScientistRepository::remove(std::string id) {
    QSqlQuery query(db);

    query.prepare("DELETE FROM Scientists WHERE id = :id");
    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();

    query.prepare("DELETE FROM ScientistComputerConnections WHERE s_ID = :id");
    query.bindValue(":id", std::atoi(id.c_str()));

    query.exec();
}

std::list<Scientist> ScientistRepository::list() {
    return list("","");
}

std::list<Scientist> ScientistRepository::list(std::string col, std::string mod) {

    std::list<Scientist> scientistList = std::list<Scientist>();

    QSqlQuery query(db);
    std::string orderBy = "";

    if(!col.empty()){
        mod = mod.empty() ? "ASC" : (mod.find("desc") != std::string::npos ? "DESC" : "ASC");
        orderBy = "order by " + col + " " + mod;

    }
    query.exec("SELECT * FROM Scientists " + QString::fromStdString(orderBy));

    populateScientistList(scientistList, query);

    return scientistList;

}

std::list<Scientist> ScientistRepository::search(std::string searchTerm) {
    // Naive search implementation, finds a substring in the name field
    std::list<Scientist> scientistList = std::list<Scientist>();

    QSqlQuery query(db);

    std::string q = "SELECT * FROM Scientists WHERE Name LIKE '%"+searchTerm+"%'";

    query.exec(QString::fromStdString(q));

    populateScientistList(scientistList, query);

    return scientistList;
}

void ScientistRepository::populateScientistList(std::list<Scientist> &scientistList, QSqlQuery query){
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
