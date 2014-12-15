#ifndef SCIENTISTCOMPUTERCONNECTIONSREPOSITORY_H
#define SCIENTISTCOMPUTERCONNECTIONSREPOSITORY_H

#include "baserepository.h"
#include "computer.h"
#include "scientist.h"

#include <stdexcept>
#include <iostream>

class ScientistComputerConnectionsRepository : BaseRepository
{
public:
    ScientistComputerConnectionsRepository();

    std::list<Computer> getAllComputersByScientistId(std::string id);
    std::list<Scientist> getAllScientistsByComputerId(std::string id);
    bool addConnection(std::string sid, std::string cid);
    bool removeConnection(std::string sid, std::string cid);

private:
    void populateComputerList(std::list<Computer> &computerList, QSqlQuery query);
    void populateScientistList(std::list<Scientist> &scientistList, QSqlQuery query);
};

#endif // SCIENTISTCOMPUTERCONNECTIONSREPOSITORY_H
