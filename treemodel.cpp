#include <QtGui>

 #include "treeitem.h"
 #include "treemodel.h"
 #include "database.h"

 TreeModel::TreeModel(const QString &data, QObject *parent)
     : QAbstractItemModel(parent)
 {
     QList<QVariant> rootData;
     rootData << "Icon" << "Title";
     rootItem = new TreeItem(rootData);
     QStringList rows = data.split(QString(":"));
     QStringList persons;
     QStringList computer;
     QStringList connection;
     persons << "Persons";
     computer << "Computer";

     setupModelData(persons, rootItem);
     setupModelData(computer, rootItem);






 }

 TreeModel::TreeModel(){}
 TreeModel::~TreeModel()
 {
     delete rootItem;
 }

 int TreeModel::columnCount(const QModelIndex &parent) const
 {
     if (parent.isValid())
         return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
     else
         return rootItem->columnCount();
 }

 QVariant TreeModel::data(const QModelIndex &index, int role) const
 {

     if (!index.isValid())
         return QVariant();
     TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
     if (role == Qt::DecorationRole)
     {
         int row = index.row();
         int parent = index.parent().row();

         int column = index.column();
         if (row == 0 && column == 0 && parent < 0)
         {

              return QPixmap(":/Icons/Computericon/lommi.png").scaledToWidth(32);
         }
         if (row == 1 && column == 0 && parent < 0)
             return QImage(":/Icons/Computericon/Computer_Icon.png").scaledToWidth(32);
         else
            return QVariant();
     }
     if (role == Qt::BackgroundRole)
     {

     }

     if (role != Qt::DisplayRole)
         return QVariant();


     return item->data(index.column());
 }

 Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
 {
     if (!index.isValid())
         return 0;

     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
 }

 QVariant TreeModel::headerData(int section, Qt::Orientation orientation,
                                int role) const
 {
     if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
         return rootItem->data(section);

     return QVariant();
 }

 QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent)
             const
 {
     if (!hasIndex(row, column, parent))
         return QModelIndex();

     TreeItem *parentItem;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<TreeItem*>(parent.internalPointer());

     TreeItem *childItem = parentItem->child(row);
     if (childItem)
         return createIndex(row, column, childItem);
     else
         return QModelIndex();
 }

 QModelIndex TreeModel::parent(const QModelIndex &index) const
 {
     if (!index.isValid())
         return QModelIndex();

     TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
     TreeItem *parentItem = childItem->parent();

     if (parentItem == rootItem)
         return QModelIndex();

     return createIndex(parentItem->row(), 0, parentItem);
 }

 int TreeModel::rowCount(const QModelIndex &parent) const
 {
     TreeItem *parentItem;
     if (parent.column() > 0)
         return 0;

     if (!parent.isValid())
         parentItem = rootItem;
     else
         parentItem = static_cast<TreeItem*>(parent.internalPointer());

     return parentItem->childCount();
 }

 void TreeModel::setupModelData(const QStringList &lines, TreeItem *parent)
 {
     QList<TreeItem*> parents;
     QList<int> indentations;
     parents << parent;
     indentations << 0;

     int number = 0;

     while (number < lines.count()) {
         int position = 0;
         while (position < lines[number].length()) {
             if (lines[number].mid(position, 1) != " ")
                 break;
             position++;
         }

         QString lineData = lines[number].mid(position).trimmed();

         if (!lineData.isEmpty()) {
             // Read the column data from the rest of the line.
             QStringList columnStrings = lineData.split("\t", QString::SkipEmptyParts);
             QList<QVariant> columnData;
             for (int column = 0; column < columnStrings.count(); ++column)
             {
                 columnData << columnStrings[column];
             }

             if (position > indentations.last()) {
                 // The last child of the current parent is now the new parent
                 // unless the current parent has no children.

                 if (parents.last()->childCount() > 0) {
                     parents << parents.last()->child(parents.last()->childCount()-1);
                     indentations << position;
                 }
             } else {
                 while (position < indentations.last() && parents.count() > 0) {
                     parents.pop_back();
                     indentations.pop_back();
                 }
             }

             // Append a new item to the current parent's list of children.
             parents.last()->appendChild(new TreeItem(columnData, parents.last()));
             int a = parents.count();
         }

         number++;
     }
 }
