#ifndef MENUS_H
#define MENUS_H

// Long strings and ASCII art here below \/ \/

const std::string MAIN_MENU = "Please use the following commands to interface with this AWESOME DATABASE\n\n\
        add     : Add a record to the database\n\
        delete  : Remove a record from the database\n\
        filter  : Filter and dislay the records in the database\n\
        search  : Search and display the results\n\
        exit    : Exit the program";

const std::string ADD_MENU = "What would you like to add?\n\n\
        0       : Scientist\n\
        1       : Computer\n\
        2       : Connection between a scientist and a computer\n\
        exit    : Exit the menu";

const std::string DELETE_MENU = "What would you like to delete?\n\n\
        0       : Scientist\n\
        1       : Computer\n\
        2       : Connection between a scientist and a computer\n\
        exit    : Exit the menu";

const std::string FILTER_MENU = "What would you like to filter?\n\n\
        0       : Scientist\n\
        1       : Computer\n\
        exit    : Exit the menu";

const std::string SEARCH_MENU = "What would you like to search for?\n\n\
        0       : Scientist\n\
        1       : Computer\n\
        exit    : Exit the menu";

const std::string FILTER_COMMAND_MENU = "Enter a column name to order by\n\
along with an ascending(asc) or descending(desc) modifier\n\
Example: \"name desc\"";


const std::string GET_ALL_MENU = "Select an id for more details!\n\n\2 \n\
        1 \n\
        2 \n\
        ... \n\
        exit    : Exit the menu";

#endif // MENUS_H
