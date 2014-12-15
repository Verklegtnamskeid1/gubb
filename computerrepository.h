#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include "baserepository.h"
#include "computer.h"
#include <list>

#include <stdexcept>
#include <iostream>
#include <QtSql>
using namespace std;

class computerrepository : public BaseRepository{
public:
    computerrepository();
    ~computerrepository();

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
