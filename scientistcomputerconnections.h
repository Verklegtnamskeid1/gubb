#ifndef SCIENTISTCOMPUTERCONNECTIONS_H
#define SCIENTISTCOMPUTERCONNECTIONS_H

#include <string>

class ScientistComputerConnections
{
public:
    ScientistComputerConnections();

    int getSid() const;
    void setSid(int value);

    int getCid() const;
    void setCid(int value);

private:
    int sid;
    int cid;
};

#endif // SCIENTISTCOMPUTERCONNECTIONS_H
