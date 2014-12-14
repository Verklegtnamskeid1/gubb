#include "sk2data.h"
// QHash<int, QHash<QString, QString> >
sk2data::sk2data()
{
}

void sk2data::AddPerson(QString name, int gender, int yearborn, int yeardead)
{
    QHash<QString, QString> buffer;
    buffer.insert("Persons_Name", name);
    buffer.insert("Persons_Sex", QString::number(gender));
    buffer.insert("Persons_YearBorn", QString::number(yearborn));
    buffer.insert("Persons_YearDeath", QString::number(yeardead));
    connection.insert("persons", buffer);
}

void sk2data::AddComputer(QString name, int type, int yearbuilt, int builtornot)
{
    QHash<QString, QString> buffer;
    buffer.insert("Computers_Name", name);
    buffer.insert("Computers_Type", QString::number(type));
    buffer.insert("Computers_YearBuilt", QString::number(yearbuilt));
    buffer.insert("Computers_BuiltOrNot", QString::number(builtornot));
    connection.insert("computers", buffer);
}
void sk2data::AddConnection(int personid, int computerid)
{
    QHash<QString, QString> buffer;
    buffer.insert("Persons_ID", QString::number(personid));
    buffer.insert("Computers_ID", QString::number(computerid));
    connection.insert("owners", buffer);
}

QVector<QHash<QString, QString> > sk2data::QueryComputer(QString row,
                                                       bool asc,
                                                       QString searchrow,
                                                       QString searchstring)

{
    QVector<QHash<QString, QString> > map;



    QHash<QString, QString> sort;
    sort["sortby"] = row;
    if (asc) sort["sortorder"] = connection.ASC;
    else { sort["sordorder"] = connection.DESC;}

    sort["sortorder"] = row;
    QHash<QString,QString> searchhash;
    if (searchrow != "")
    {
        searchhash[searchrow] = searchstring;
    }


    QMap<int, QHash<QString, QString> > buffer =
             connection.query("computers", searchhash,
                            sort);

    QHash<QString, QString> printorder;
    printorder.insert("PrintOrder", "ID:Name:Year built:Type:Built?");
    printorder.insert("RecordSize", buffer[0]["RecordSize"]);

    map << printorder;

    foreach (auto item, buffer)
    {

        QString gender, yeardeath;
        QHash<QString, QString> result;

        //Electronic \n1: Mechanical \n2: Electro-mechanical \n3: Transistor \n4: Other
        QString typemachine = item["Computers_Type"];
        QString typemachinestring;
        if (typemachine == "0") typemachinestring = "Electronic";
        else if(typemachine =="1") typemachinestring = "Mechanical";
        else if(typemachine =="2") typemachinestring = "Electro-mechanical";
        else if(typemachine =="3") typemachinestring = "Transistor";
        else typemachinestring = "Other";
        QString built = "No";
        if (item["Computers_BuiltOrNot"] == "1") built = "Yes";



             result.insert("ID", item["Computers_ID"]);
             result.insert("Name", item["Computers_Name"]);
             result.insert("Year built", item["Computers_YearBuilt"]);
             result.insert("Type", typemachinestring);
             result.insert("Built?", built);




             map << result;

    }
    return map;
}

QVector<QHash<QString, QString> > sk2data::QueryConnection(QString row,
                                                       bool asc,
                                                       QString searchrow,
                                                       QString searchstring)
{
    QVector<QHash<QString, QString> > map;



    QHash<QString, QString> sort;
    sort["sortby"] = row;
    if (asc) sort["sortorder"] = connection.ASC;
    else { sort["sordorder"] = connection.DESC;}

    sort["sortorder"] = row;
    QHash<QString,QString> searchhash;
    if (searchrow != "")
    {
        searchhash[searchrow] = searchstring;
    }


    QMap<int, QHash<QString, QString> > buffer =
             connection.query("owners", searchhash,
                            sort);

    QHash<QString, QString> printorder;
    printorder.insert("PrintOrder", "Person ID:Computer ID:Person name:Computer name");
    printorder.insert("RecordSize", buffer[0]["RecordSize"]);

    map << printorder;

    foreach (auto item, buffer)
    {

        QString gender, yeardeath;
        QHash<QString, QString> result;


        QHash<QString,QString> personsearchhash;
        QHash<QString,QString> computersearchhash;
        personsearchhash["Persons_ID"] = item["Persons_ID"];
        computersearchhash["Computers_ID"] = item["Computers_ID"];

        QMap<int, QHash<QString, QString> > personbuffer =
            connection.query("persons", personsearchhash,
                       connection.DefaultSort, false);
        QMap<int, QHash<QString, QString> > computerbuffer =
            connection.query("computers", computersearchhash,
                       connection.DefaultSort, false);


             result.insert("Person ID", item["Persons_ID"]);
             result.insert("Computer ID", item["Computers_ID"]);
             result.insert("Person name", personbuffer[0]["Persons_Name"]);
             result.insert("Computer name", computerbuffer[0]["Computers_Name"]);


             map << result;

    }
    return map;
}

QVector<QHash<QString, QString> > sk2data::QueryPerson(QString row,
                                                       bool asc,
                                                       QString searchrow,
                                                       QString searchstring)
{
    QVector<QHash<QString, QString> > map;



    QHash<QString, QString> sort;
    sort["sortby"] = row;
    if (asc) sort["sortorder"] = connection.ASC;
    else { sort["sordorder"] = connection.DESC;}

    sort["sortorder"] = row;
    QHash<QString,QString> searchhash;
    if (searchrow != "")
    {
        searchhash[searchrow] = searchstring;
    }


    QMap<int, QHash<QString, QString> > buffer =
             connection.query("persons", searchhash,
                            sort);

    QHash<QString, QString> printorder;
    printorder.insert("PrintOrder", "ID:Name:Gender:Born:Died");
    printorder.insert("RecordSize", buffer[0]["RecordSize"]);

    map << printorder;


    foreach (auto item, buffer)
    {

        QString gender, yeardeath;
        QHash<QString, QString> result;

             result.insert("ID", item["Persons_ID"]);
             result.insert("Name", item["Persons_Name"]);

             if (item["Persons_Gender"] == "1")
             {
                result.insert("Gender", "Female");

              }
              else
              {
                result.insert("Gender", "Male");

              }

             result.insert("Born", item["Persons_YearBorn"]);
             if (item["Persons_YearDeath"] == "0")
             {
                result.insert("Died", "Alive");

             }
             else
             {
                result.insert("Died", item["Persons_YearDeath"]);

             }
             map << result;

    }
    return map;
}
