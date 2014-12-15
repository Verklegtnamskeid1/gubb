#ifndef SCIENCESERVICE_H
#define SCIENCESERVICE_H

#include "Scientist.h"
#include "ScientistRepository.h"
#include "computer.h"
#include "computerrepository.h"
#include "scientistcomputerconnections.h"
#include "scientistcomputerconnectionsrepository.h"
#include <list>


// Domain layer, services the presentation layer
class ScienceService {
public:
    ScienceService();
    ~ScienceService();

    //Scientists
    void addScientist(Scientist scientist);
    void removeScientist(std::string id);
    std::list<Scientist> searchScientist(std::string searchTerm);
    std::list<Scientist> getAllScientists();
    std::list<Scientist> getScientistsOrderedBy(std::string col,std::string mod);

    //Computers
    void addComputer(Computer computer);
    void removeComputer(std::string id);
    std::list<Computer> searchComputer(std::string searchTerm);
    std::list<Computer> getAllComputers();
    std::list<Computer> getComputersOrderedBy(std::string col,std::string mod);

    //Connections
    std::list<Computer> getAllComputersByScientistId(std::string id);
    std::list<Scientist> getAllScientistsByComputerId(std::string id);
    bool addConnection(std::string sid, std::string cid);
    bool removeConnection(std::string sid, std::string cid);


private:
    ScientistRepository scientistRepository;
    ComputerRepository computerRepository;
    ScientistComputerConnectionsRepository scientistComputerConnectionsRepository;
};

#endif // SCIENCESERVICE_H
