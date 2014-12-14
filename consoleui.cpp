#include "main.h"
#include "consoleui.h"

ConsoleUI::ConsoleUI()
{
}

bool ConsoleUI::SearchASC()
{
    cout << "\nSort by accending or descending?" << endl
         << "1: Asscending" << endl
         << "2: Descending" << endl;

    QString input = cin.readLine();
    int inputid = input.toInt();
    switch(inputid)
    {
     case (2):
        return false;
    case(1): default:
            return true;

    }
}

QString ConsoleUI::DefineSearchPersons()
{
    cout << "\nHow shall I sort the results:" << endl
         << "0: By ID" << endl
         << "1: By name" << endl
         << "2: By gender" << endl
         << "3: By year born" << endl
         << "4: By year died" << endl
         << "";

    int SearchInput = cin.readLine().toInt();

    switch(SearchInput){
    case 0: return "Persons_ID";
        break;
    case 1: return "Persons_Name";
        break;
    case 2: return "Persons_Gender";
        break;
    case 3: return "Persons_YearBorn";
        break;
    case 4: return "Persons_YearDeath";
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

QString ConsoleUI::DefineSearchComputer()
{
    cout << "\nHow shall I sort the results:" << endl
         << "0: By ID" << endl
         << "1: By name" << endl
         << "2: By type" << endl
         << "3: By year built" << endl
         << "4: By whether it was built or not" << endl
         << "";

    int SearchInput = cin.readLine().toInt();

    switch(SearchInput){
    case 0: return "Computers_ID";
        break;
    case 1: return "Computers_Name";
        break;
    case 2: return "Computers_Type";
        break;
    case 3: return "Computers_YearBuilt";
        break;
    case 4: return "Computers_BuiltOrNot";
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

QString ConsoleUI::DefineSearchConnection()
{
    cout << "\nHow shall I sort the results:" << endl
         << "0: By person ID" << endl
         << "1: By computer ID" << endl;

    int SearchInput = cin.readLine().toInt();

    switch(SearchInput){
    case 0: return "Persons_ID";
        break;
    case 1: return "Computers_ID";
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

void ConsoleUI::Delete()
{
    cout << "What do you want to delete?" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection" << endl;
    int pickdelete = cin.readLine().toInt();

    cout << "What ID do you want to delete?" << endl;
    int deleteID = cin.readLine().toInt();

    switch(pickdelete){
    case 0: DeletePerson(deleteID);
        break;
    case 1: DeleteComputer(deleteID);
        break;
    case 2: DeleteConnection(deleteID);
        break;
    default:
        cout << "Invalid input." << endl;
        break;

    }
}

void ConsoleUI::DeletePerson(int deleteID)
{

}
void ConsoleUI::DeleteComputer(int deleteID)
{

}
void ConsoleUI::DeleteConnection(int deleteID)
{

}

void ConsoleUI::Print(QVector<QHash<QString, QString> > buffer)
{
 cout << "_______________________________________________________________________" << endl << endl;

    QString printorder = buffer[0]["PrintOrder"];
    QStringList col = printorder.split(":");
    int size = buffer[0]["RecordSize"].toInt();
    buffer[0].remove("PrintOrder");
    buffer[0].remove("RecordSize");

    for (int a = 0; a < size+1; a++)
    {
        auto item = buffer[a];
        int colcount = 0;
        foreach (QString colitem, col)
        {
            colcount++;
            cout << colitem << ": " << item[colitem] << "\t";
            if (colcount % 3 == 0) cout << "\n";
        }
        cout << "\n";
        cout << "---";
        cout << "\n";
    }

    cout << "_______________________________________________________________________" << endl;

}

void ConsoleUI::List()
{
    cout << "What list would you like to display" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection" << endl;
    int picklist = cin.readLine().toInt();

    switch(picklist){
    case 0: ListPerson();
        break;
    case 1: ListComputer();
        break;
    case 2: ListConnection();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

void ConsoleUI::ListPerson(QString searchrow, QString searchfor)
{
    QString row = DefineSearchPersons();
    bool asc = SearchASC();
    QVector<QHash<QString, QString> > buffer = gogn.QueryPerson(row, asc, searchrow, searchfor);

    Print(buffer);
}

void ConsoleUI::ListComputer(QString searchrow, QString searchfor)
{
    QString row = DefineSearchComputer();
    bool asc = SearchASC();

    QVector<QHash<QString, QString> > buffer = gogn.QueryComputer(row, asc, searchrow, searchfor);

    Print(buffer);
}

void ConsoleUI::ListConnection(QString searchrow, QString searchfor)
{
    QString row = DefineSearchConnection();
    bool asc = SearchASC();

    QVector<QHash<QString, QString> > buffer = gogn.QueryConnection(row, asc, searchrow, searchfor);

    Print(buffer);
}

void ConsoleUI::Add()
{

    cout << "\nInsert" << endl
         << "0: Person" << endl
         << "1: Computer" << endl
         << "2: Connection"<<endl;
    int input = cin.readLine().toInt();

    switch(input){
    case 0: AddPerson();
        break;
    case 1: AddComputer();
        break;
    case 2: AddConnection();
        break;

    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}

void ConsoleUI::AddComputer(){
    cout << "\nEnter name:" << endl;
    QString Computers_name = cin.readLine(); cout << "\nHow shall I sort the results:" << endl
                                                  << "0: By ID" << endl
                                                  << "1: By name" << endl
                                                  << "2: By gender" << endl
                                                  << "3: By year born" << endl
                                                  << "4: By year died" << endl
                                                  << "";

    cout << "\nEnter type: \n0: Electronic \n1: Mechanical \n2: Electro-mechanical \n3: Transistor \n4: Other" << endl;
    int Computers_type = cin.readLine().toInt();

    cout << "\nEnter year it was built:" << endl;
    int Computers_yearbuilt = cin.readLine().toInt();

    cout << "\nWas it built? (y/n Y/N):" << endl;
    int Computers_builtornot = cin.readLine().toInt();

    gogn.AddComputer(Computers_name, Computers_type, Computers_yearbuilt, Computers_builtornot);
}

void ConsoleUI::AddConnection()
{
    cout <<"\nEnter how you want to create a connection"<<endl
         << "0: By person ID" << endl
         << "1: By computer ID" << endl;

    int connect = cin.readLine().toInt();

    switch(connect){
    case 0: PersonConnection();
        break;
    case 1: ComputerConnection();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
    cout << endl;
}

void ConsoleUI::PersonConnection()
{
    cout << "Enter the Person's ID you want to connect to a computer." << endl;
    int PERSONID = cin.readLine().toInt();
    cout << "Now enter the computer's ID you want to connect to " << endl;
    int COMPUTERID = cin.readLine().toInt();
    gogn.AddConnection(PERSONID, COMPUTERID);
}

void ConsoleUI::ComputerConnection()
{
    cout << "Enter the Computer's ID you want to connect to a person." << endl;
    int COMPUTERID = cin.readLine().toInt();
    cout << "Now enter the person's ID you want to connect to " << endl;
    int PERSONID = cin.readLine().toInt();
    gogn.AddConnection(PERSONID, COMPUTERID);
}

void ConsoleUI::AddPerson()
{
    cout << "\nEnter name:" << endl;
    QString name = cin.readLine();

    if (name.isEmpty())
    {
        cout << "\nPlease type a name" << endl;
        return;
    }

    cout << "\nEnter gender (0 male, 1 female):" << endl;
    int gender= cin.readLine().toInt();
    QString genderstring = 0 ? "Female" : "Male";
    cout << endl << "Enter year born:" << endl;
    int yearborn = cin.readLine().toInt();

    QString yn;
    if (gender == 0) cout << "Is he dead? (y/n Y/N)" << endl;
    else cout << "Is she dead? (y/n Y/N)" << endl;
    yn = cin.readLine();
    int yeardead;

    if (yn == "Y" || yn == "y")
    {
        cout << "\nEnter year dead:"<< endl;
        yeardead = cin.readLine().toInt();
    }
    else
    {
        yeardead = -1;
    }

    if ((yearborn == yeardead || yeardead < yearborn) && yeardead != -1)
    {
        /* Afsakið hrokann en hér gerum við ráð fyrir því að fólk sem nær ekki að
         * að verða ársgamalt geti orðið frægt í tölvugeiranum */
        cout << "Year born and year dead are incorrect. Please fix. " << endl << endl;
        return;
    }

    if (yearborn < 1500 || (yeardead < 1500 && yeardead != -1) )
    {
        cout << "Please check if your years are correct! " << endl << endl;
    }

    yeardead = -1 ? yeardead : 0;


    QString yeardeadstring;

    if (yn == "Y" || yn == "y"){
        yeardeadstring = QString::number(yeardead);
    }
    else
    {
        yeardeadstring = "Still alive";
    }

    cout
         << "Name: " << name << endl
         << "Gender: "  << genderstring << endl
         << "Year born " << yearborn << endl
         << "Year dead: " << yeardeadstring << endl
         << "Do you wish to insert this entry: (y/n Y/N)" << endl;
    yn = cin.readLine();
    if (yn == "Y" || yn == "y")
    {
        gogn.AddPerson(name, gender, yearborn, yeardead);
        cout << "\nPerson added!" << endl;
    }
    else
        return;
}

void ConsoleUI::Search()
{
    cout << "What do you want to search for?" << endl
         << "0: A person" << endl
         << "1: A computer" << endl
         << "2: A connection" << endl;

    int SearchInput = cin.readLine().toInt();

    switch(SearchInput){
    case 0: SearchPerson();
        break;
    case 1: SearchComputer();
        break;
    case 2: SearchConnection();
        break;
    default:
        cout << "Invalid input." << endl;
        break;
    }
}

void ConsoleUI::SearchPerson()
{
    cout << "\nSearch" << endl
         << "0: in field ID" << endl
         << "1: in field name" << endl
         << "2: in field gender" << endl
         << "3: in field year born" << endl
         << "4: in field year died" << endl;

    int SearchInput = cin.readLine().toInt();

    QString row;
    switch (SearchInput){

    case 0:
        row = "Persons_ID";
        break;
    case 1:
        row = "Persons_Name";
        break;
    case 2:
        row = "Persons_Sex";
        break;
    case 3:
        row = "Persons_YearBorn";
        break;
    case 4:
        row = "Persons_YearDeath";
        break;
    default:
        cout << "Incorrect option";
        return;
    }
    cout << "Find: " << endl;
    QString searchstring = cin.readLine();

    ListPerson(row, searchstring);
}

void ConsoleUI::SearchComputer()
{
    cout << "\nSearch" << endl
         << "0: in field ID" << endl
         << "1: in field name" << endl
         << "2: in field type" << endl
         << "3: in field year built" << endl
         << "4: in field was it built or not?" << endl;

    int SearchInput = cin.readLine().toInt();
    QString row;

    switch(SearchInput)
    {
        case 0:
         row ="Computers_ID";
         break;
        case 1:
          row="Computers_Name";
          break;
        case 2:
          row="Computers_Type";
          break;
        case 3:
          row="Computers_YearBuilt";
          break;
        case 4:
          row="Computers_BuiltOrNot";
          break;
        default:
        cout << "Incorrect option";
        return;
    }

    cout << "Find: " << endl;
    QString searchstring = cin.readLine();
    ListComputer(row, searchstring);
}

void ConsoleUI::SearchConnection()
{
    cout << "\nSearch" << endl
         << "0: in field person ID" << endl
         << "1: in field computer ID" << endl;

    int SearchInput = cin.readLine().toInt();

    cout << "Find: " << endl;
    QString searchstring = cin.readLine();
    QString row;
    switch(SearchInput)
    {
        case 0:
           row  = "Persons_ID";
           break;
        case 1:
           row = "Computers_ID";
           break;
        default:
          cout << "Incorrect option";
          return;
    }
    ListConnection(row, searchstring);
}

void ConsoleUI::quitmsg()
{
    cout << endl;
    cout << "Goodbye! " << endl;
    cout << endl;
}


void ConsoleUI::start()
{
    while(1)
    {
    cout << "Welcome!" << endl
         << "Choose one of the following:" << endl
         << "1. List" << endl
         << "2. Search" << endl
         << "3. Insert " << endl
         << "4. Quit" << endl;
    int inputid = cin.readLine().toInt();

        switch(inputid)
        {
        case 1: List();
            break;
        case 2: Search();
            break;
        case 3: Add();
            break;

        case 4:
            quitmsg();
            return;
            break;
        default:
            cout << "Invalid input." << endl;
            break;
        }

    cout << endl;

    }
}

    QTextStream cout(stdout);
    QTextStream cin(stdin);
