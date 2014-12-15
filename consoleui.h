#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "Scientist.h"
#include "computer.h"
#include <stack>
#include <list>
#include <cstdlib>
#include <iostream>
#include <string>
#include "menus.h"
#include <stdexcept>
#include <sstream>
#include "scienceservice.h"

// Display layer for the console application
class ConsoleUI {
public:
    ConsoleUI();
    ~ConsoleUI();
    int start();
private:
    ScienceService scienceService;
    void clear();
    void waitForPrompt();
    int respondToMessage();
    void handleAddScientist();
    void handleAddComputer();
    void handleAddConnection();
    void handleDeleteScientist();
    void handleDeleteComputer();
    void handleDeleteConnection();
    void handleSearchScientist();
    void handleSearchComputer();
    void handleFilterScientist();
    void handleFilterComputer();
};

#endif // CONSOLEUI_H
