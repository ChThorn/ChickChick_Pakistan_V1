#ifndef HISTORY_H
#define HISTORY_H

#include <QObject>
#include <QDebug>
#include <QDate>

#include <QtSql/QSql>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

#include "GlobalHeader.h"

#define DB_NAME_HISTORY  "DB/HISTORY"

class History : public QObject
{
    Q_OBJECT
public:
    History();

    void AddResult(int menu, int increase);
    void AddResult(QString menu, int increase);

    int GetResult(int menu);
    int GetResult(QString menu);

private:
    QSqlDatabase    db;

    QString GetCurDate();

};

#endif // HISTORY_H
