#ifndef RECIPE_H
#define RECIPE_H

#include <QObject>
#include <QDebug>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#define DB_NAME_RECIPE  "DB/RECIPE"




class Recipe : public QObject
{
    Q_OBJECT
public:
    Recipe();


private:
    QSqlDatabase    db;

    void LoadDatabase();
};

#endif // RECIPE_H
