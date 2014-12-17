#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>
#include <QVariant>

// DTO for scientists
class Scientist {
public:
    Scientist();

    int getId() const;
    void setId(int value);

    std::string getName() const;
    void setName(const std::string &value);

    std::string getDateOfBirth() const;
    void setDateOfBirth(const std::string &value);

    std::string getDateOfDeath() const;
    void setDateOfDeath(const std::string &value);

   int getGender() const;
    void setGender(const int &value);

    QVariant getBlob() const;
    void setBlob(const QVariant &value);


private:
    int id;
    std::string name;
    std::string dateOfBirth;
    std::string dateOfDeath;
    int gender;
    QVariant blob;

};

#endif // SCIENTIST_H
