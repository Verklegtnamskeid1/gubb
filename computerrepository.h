#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include "baserepository.h"
#include "computer.h"

#include <stdexcept>
#include <iostream>

class ComputerRepository : public BaseRepository
{
public:
    ComputerRepository();
    ~ComputerRepository();

    void add(Computer);
    void remove(std::string id);
    std::list<Computer> search(std::string searchTerm);
    std::list<Computer> list();
    // Returns a list ordered by column and modifier
    std::list<Computer> list(std::string col,std::string mod);
private:
    std::list<Computer> computerList;
    void populateComputerList(std::list<Computer> &computerList, QSqlQuery query);
};

#endif // COMPUTERREPOSITORY_H
