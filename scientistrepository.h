#ifndef SCIENTISTREPOSITORY_H
#define SCIENTISTREPOSITORY_H

#include "scientist.h"
#include "baserepository.h"
#include <stdexcept>
#include <iostream>

class Scientistrepository : public Baserepository
{
public:
    ScientistRepository();
    ~ScientistRepository();

    void add(Scientist);
    void remove(std::string id);
    std::list<Scientist> search(std::string searchTerm);
    std::list<Scientist> list();
    // Returns a list ordered by column and modifier
    std::list<Scientist> list(std::string col,std::string mod);
private:
    std::list<Scientist> scientistList;
    void populateScientistList(std::list<Scientist> &scientistList, QSqlQuery query);
};

#endif // SCIENTISTREPOSITORY_H
