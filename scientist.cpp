#include "scientist.h"

Scientist::Scientist() {
    name = "";
    dateOfBirth = "";
    dateOfDeath = "";
    gender = 0;

}

QVariant Scientist::getBlob() const
{
    return blob;
}

void Scientist::setBlob(const QVariant &value)
{
    blob = value;
}

std::string Scientist::getName() const
{
    return name;
}

void Scientist::setName(const std::string &value)
{
    name = value;
}
std::string Scientist::getDateOfBirth() const
{
    return dateOfBirth;
}

void Scientist::setDateOfBirth(const std::string &value)
{
    dateOfBirth = value;
}
std::string Scientist::getDateOfDeath() const
{
    return dateOfDeath;
}

void Scientist::setDateOfDeath(const std::string &value)
{
    dateOfDeath = value;
}
int Scientist::getGender() const
{
    return gender;
}

void Scientist::setGender(const int &value)
{
    gender = value;
}



int Scientist::getId() const
{
    return id;
}

void Scientist::setId(int value)
{
    id = value;
}


