#include "computer.h"

Computer::Computer()
{

}
int Computer::getId() const
{
    return id;
}

void Computer::setId(int value)
{
    id = value;
}
std::string Computer::getName() const
{
    return name;
}

void Computer::setName(const std::string &value)
{
    name = value;
}
std::string Computer::getYearBuilt() const
{
    return yearBuilt;
}

void Computer::setYearBuilt(const std::string &value)
{
    yearBuilt = value;
}
int Computer::getType() const
{
    return type;
}

void Computer::setType(int value)
{
    type = value;
}
bool Computer::getWasBuilt() const
{
    return wasBuilt;
}

void Computer::setWasBuilt(bool value)
{
    wasBuilt = value;
}
