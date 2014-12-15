#include "scienceservice.h"

ScienceService::ScienceService() {
    scientistRepository = ScientistRepository();
}

ScienceService::~ScienceService() {
}

void ScienceService::addScientist(Scientist scientist) {
    scientistRepository.add(scientist);
}

void ScienceService::removeScientist(std::string id) {
    scientistRepository.remove(id);
}

std::list<Scientist> ScienceService::getAllScientists() {
    return scientistRepository.list();
}

std::list<Scientist> ScienceService::getScientistsOrderedBy(std::string col, std::string mod) {
    return scientistRepository.list(col,mod);
}

std::list<Scientist> ScienceService::searchScientist(std::string searchTerm) {
    return scientistRepository.search(searchTerm);
}

void ScienceService::addComputer(Computer computer)
{
    computerRepository.add(computer);
}

void ScienceService::removeComputer(std::string id)
{
    computerRepository.remove(id);
}

std::list<Computer> ScienceService::searchComputer(std::string searchTerm)
{
    return computerRepository.search(searchTerm);
}

std::list<Computer> ScienceService::getAllComputers()
{
    return computerRepository.list();
}

std::list<Computer> ScienceService::getComputersOrderedBy(std::string col, std::string mod)
{
    return computerRepository.list(col, mod);
}

std::list<Computer> ScienceService::getAllComputersByScientistId(std::string id)
{
    return scientistComputerConnectionsRepository.getAllComputersByScientistId(id);
}

std::list<Scientist> ScienceService::getAllScientistsByComputerId(std::string id)
{
    return scientistComputerConnectionsRepository.getAllScientistsByComputerId(id);
}

bool ScienceService::addConnection(std::string sid, std::string cid)
{
    return scientistComputerConnectionsRepository.addConnection(sid, cid);
}

bool ScienceService::removeConnection(std::string sid, std::string cid)
{
    return scientistComputerConnectionsRepository.removeConnection(sid, cid);
}
