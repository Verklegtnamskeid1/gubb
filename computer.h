#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>

class Computer
{
public:
    Computer();
    int getId() const;
    void setId(int value);

    std::string getName() const;
    void setName(const std::string &value);

    std::string getYearBuilt() const;
    void setYearBuilt(const std::string &value);

    int getType() const;
    void setType(int value);

    bool getWasBuilt() const;
    void setWasBuilt(bool value);

private:
    int id;
    std::string name;
    std::string yearBuilt;
    int type;
    bool wasBuilt;
};

#endif // COMPUTER_H
