#include "consoleui.h"
#include <iostream>
#include <string>
#include "menus.h"
#include <stdexcept>
#include <sstream>

ConsoleUI::ConsoleUI() {
    scienceService = ScienceService();
}

ConsoleUI::~ConsoleUI() {
}

int ConsoleUI::start() {
    // REPL
    while(true) {
        int response = respondToMessage();
        if( response == 0)
        {
            return 0;
        }
    }

    return 1;
}

void ConsoleUI::clear() {
    // Not pretty, but it is platform independant
    std::cout << std::string( 1, '\n' );
}

void ConsoleUI::waitForPrompt() {
    std::cout << "\nPress enter to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
}

int ConsoleUI::respondToMessage() {

    std::cout << MAIN_MENU << std::endl;

    std::string userRequest;
    std::cin >> userRequest;

    try {
        // Handle all available commands and throw error on unknown ones
        if(userRequest.find("add") != std::string::npos) {
            std::cout << ADD_MENU << std::endl;
            std::cin >> userRequest;
            if(userRequest.find("0")!= std::string::npos){
                handleAddScientist();
            }else if(userRequest.find("1")!= std::string::npos){
                handleAddComputer();
            }else if(userRequest.find("2")!= std::string::npos){
                handleAddConnection();
            }else if(userRequest.find("exit")!= std::string::npos){
                waitForPrompt();
                clear();
            }else{
                throw std::runtime_error( userRequest + " is not a valid command.");
            }

        } else if(userRequest.find("delete") != std::string::npos) {
            std::cout << DELETE_MENU << std::endl;
            std::cin >> userRequest;
            if(userRequest.find("0")!= std::string::npos){
                handleDeleteScientist();
            }else if(userRequest.find("1")!= std::string::npos){
                handleDeleteComputer();
            }else if(userRequest.find("2")!= std::string::npos){
                handleDeleteConnection();
            }else if(userRequest.find("exit")!= std::string::npos){
                waitForPrompt();
                clear();
            }else{
                throw std::runtime_error( userRequest + " is not a valid command.");
            }
        } else if(userRequest.find("filter") != std::string::npos) {
            std::cout << FILTER_MENU << std::endl;
            std::cin >> userRequest;
            if(userRequest.find("0")!= std::string::npos){
                handleFilterScientist();
            }else if(userRequest.find("1")!= std::string::npos){
                handleFilterComputer();
            }else if(userRequest.find("exit")!= std::string::npos){
                waitForPrompt();
                clear();
            }else{
                throw std::runtime_error( userRequest + " is not a valid command.");
            }
        } else if(userRequest.find("search") != std::string::npos) {
            std::cout << SEARCH_MENU << std::endl;
            std::cin >> userRequest;
            if(userRequest.find("0")!= std::string::npos){
                handleSearchScientist();
            }else if(userRequest.find("1")!= std::string::npos){
                handleSearchComputer();
            }else if(userRequest.find("exit")!= std::string::npos){
                waitForPrompt();
                clear();
            }else{
                throw std::runtime_error( userRequest + " is not a valid command.");
            }
        } else if (userRequest.find("exit") != std::string::npos) {
            return 0;
        } else {
            throw std::runtime_error( userRequest + " is not a valid command.");
        }
    } catch(std::runtime_error e) {
        clear();
        std::cout << "Command caused an error: " << e.what() << std::endl;
        std::cout << "Please try another command" << std::endl;
        waitForPrompt();
        clear();
    }

    return 1;
}

/*
 *
 * Private functions
 *
 */

void ConsoleUI::handleAddScientist(){
    clear();
    std::string input;
    Scientist additionalScientist = Scientist();
    std::cout << "Enter the name of the scientist: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    additionalScientist.setName(input);
    clear();
    std::cout << "Enter the date of birth of the scientist: ";
    std::cin >> input;
    additionalScientist.setDateOfBirth(input);
    clear();
    std::cout << "Enter the date of death of the scientist: ";
    std::cin >> input;
    additionalScientist.setDateOfDeath(input);
    clear();
    std::cout << "Enter the gender of the scientist: ";
    std::cin >> input;
    additionalScientist.setGender(input);
    scienceService.addScientist(additionalScientist);
    clear();
}

void ConsoleUI::handleAddComputer(){
    clear();
    std::string input;
    Computer additionalComputer = Computer();
    std::cout << "Enter the name of the computer: ";
    std::cin.ignore();
    std::getline(std::cin, input);
    additionalComputer.setName(input);
    clear();
    std::cout << "Enter year built: ";
    std::cin >> input;
    additionalComputer.setYearBuilt(input);
    clear();
    std::cout << "Enter type: ";
    std::cin >> input;
    additionalComputer.setType(atoi(input.c_str()));
    clear();
    std::cout << "Was the computer built? 1 for 'Yes' or 0 for 'No': ";
    std::cin >> input;
    additionalComputer.setWasBuilt(atoi(input.c_str()));
    scienceService.addComputer(additionalComputer);
    clear();
}

void ConsoleUI::handleAddConnection(){
    clear();
    std::string sidToAdd = "";
    std::string cidToAdd = "";
    std::cout << "Enter the id of the scientist to connect: ";
    std::cin >> sidToAdd;
    std::cout << "Enter the id of the computer to connect: ";
    std::cin >> cidToAdd;

    scienceService.addConnection(sidToAdd, cidToAdd);
    clear();
}

void ConsoleUI::handleDeleteScientist(){
    clear();
    std::string idToDelete = "";
    std::cout << "Enter the id of the scientist to delete: ";
    std::cin >> idToDelete;
    scienceService.removeScientist(idToDelete);
    clear();
}

void ConsoleUI::handleDeleteComputer(){
    clear();
    std::string idToDelete = "";
    std::cout << "Enter the id of the computer to delete: ";
    std::cin >> idToDelete;
    scienceService.removeComputer(idToDelete);
    clear();
}

void ConsoleUI::handleDeleteConnection(){
    clear();
    std::string sidToDelete = "";
    std::string cidToDelete = "";
    std::cout << "Enter the id of the scientist to disconnect: ";
    std::cin >> sidToDelete;
    std::cout << "Enter the id of the computer to disconnect: ";
    std::cin >> cidToDelete;

    scienceService.removeConnection(sidToDelete, cidToDelete);
    clear();
}

void ConsoleUI::handleSearchScientist(){
    clear();
    std::string searchTerm = "";
    std::cout << "Enter the search term: ";
    std::cin.ignore();
    std::getline(std::cin,searchTerm);
    clear();
    std::list<Scientist> l = scienceService.searchScientist(searchTerm);
    if(l.size() > 0) {
        for(std::list<Scientist>::iterator iter = l.begin(); iter != l.end(); iter ++) {
            std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getDateOfBirth() << "\t\t" << iter->getDateOfDeath() << "\t\t" << iter->getGender() << std::endl;
        }
    } else {
        std::cout << "No results found for the term: " << searchTerm << std::endl;
    }
    waitForPrompt();
    clear();
}

void ConsoleUI::handleSearchComputer(){
    clear();
    std::string searchTerm = "";
    std::cout << "Enter the search term: ";
    std::cin.ignore();
    std::getline(std::cin,searchTerm);
    clear();
    std::list<Computer> l = scienceService.searchComputer(searchTerm);
    if(l.size() > 0) {
        for(std::list<Computer>::iterator iter = l.begin(); iter != l.end(); iter ++) {
            std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getYearBuilt() << "\t\t" << iter->getType() << "\t\t" << iter->getWasBuilt() << std::endl;
        }
    } else {
        std::cout << "No results found for the term: " << searchTerm << std::endl;
    }
    waitForPrompt();
    clear();
}

void ConsoleUI::handleFilterScientist(){
    clear();
    std::string filterCol = "";
    std::string filterMod = "";
    std::cout << FILTER_COMMAND_MENU << std::endl;
    std::cin >> filterCol >> filterMod;
    clear();
    std::list<Scientist> l = scienceService.getScientistsOrderedBy(filterCol,filterMod);
    std::cout << "Name:\t\tDateOfBirth:\tDateOfDeath:\tGender:\n";
    for(std::list<Scientist>::iterator iter = l.begin(); iter != l.end(); iter ++) {
        std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getDateOfBirth() << "\t\t" << iter->getDateOfDeath() << "\t\t" << iter->getGender() << std::endl;
    }

    std::string userRequest;
    std::cout << GET_ALL_MENU << std::endl;
    while(std::cin >> userRequest){
        if(userRequest.find("exit") != std::string::npos){
            break;
        }
        clear();

        std::cout << "ID:\tName:\t\tDateOfBirth:\tDateOfDeath:\tGender:\n";
        for(std::list<Scientist>::iterator iter = l.begin(); iter != l.end(); iter ++) {
            std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getDateOfBirth() << "\t\t" << iter->getDateOfDeath() << "\t\t" << iter->getGender() << std::endl;
        }

        std::cout << GET_ALL_MENU << std::endl;
        std::list<Computer> l = scienceService.getAllComputersByScientistId(userRequest);
        for(std::list<Computer>::iterator iter = l.begin(); iter != l.end(); iter ++) {
            std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getYearBuilt() << "\t\t" << iter->getType() << "\t\t" << iter->getWasBuilt() << std::endl;
        }
    }

    waitForPrompt();
    clear();
}

void ConsoleUI::handleFilterComputer(){
    clear();
    std::string filterCol = "";
    std::string filterMod = "";
    std::cout << FILTER_COMMAND_MENU << std::endl;
    std::cin >> filterCol >> filterMod;
    clear();
    std::list<Computer> l = scienceService.getComputersOrderedBy(filterCol,filterMod);
    std::cout << "Name:\t\tYearBuilt:\tType:\tWasBuilt:\n";
    for(std::list<Computer>::iterator iter = l.begin(); iter != l.end(); iter ++) {
        std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getYearBuilt() << "\t\t" << iter->getType() << "\t\t" << iter->getWasBuilt() << std::endl;
    }

    std::string userRequest;
    std::cout << GET_ALL_MENU << std::endl;
    while(std::cin >> userRequest && userRequest.find("exit") != std::string::npos){
        clear();
        std::cout << GET_ALL_MENU << std::endl;
        std::list<Scientist> l = scienceService.getAllScientistsByComputerId(userRequest);
        for(std::list<Scientist>::iterator iter = l.begin(); iter != l.end(); iter ++) {
            std::cout << iter->getId() << "\t" << iter->getName() << "\t" << iter->getDateOfBirth() << "\t\t" << iter->getDateOfDeath() << "\t\t" << iter->getGender() << std::endl;
        }
    }


    waitForPrompt();
    clear();
}

