#include "History.h"

extern int CLOSE_HOUR;

History::History()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "DB_HISTORY");
    QString build_path = BUILD_PATH;
    QString db_path = appPath + DB_NAME_HISTORY;
    db.setDatabaseName(db_path);
    db.open();

//    AddResult("뼈", 10);
}


void History::AddResult(int menu, int increase){
    QString cur_date = GetCurDate();//QDate::currentDate().toString("yyyy.MM.dd");

    QSqlQuery query(db);
    QString query_str;
    query_str = "SELECT * FROM history WHERE date='" + cur_date + "'";
    query.exec(query_str);
//    qDebug() << query_str;

    if(query.next()){
        // date is exist
    }else{
        // date is not exist --> make new row
        query_str = "INSERT INTO history (date, menu1, menu2, menu3, menu4, menu5) VALUES ('" + cur_date + "',0,0,0,0,0)";
        query.exec(query_str);
//        qDebug() << query_str;
    }

    // adjust change
    int cur_value;
    QString menu_name = QString().sprintf("menu%d", menu);
    query_str = QString().sprintf("SELECT %s from history WHERE date = '%s'", menu_name.toStdString().data(), cur_date.toStdString().data());
    query.exec(query_str);
//    qDebug() << query_str;

    if(query.next()){
        cur_value = query.value(menu_name).toInt();
        cur_value += increase;

        query_str = QString().sprintf("UPDATE history SET %s = %d WHERE date = '%s'", menu_name.toStdString().data(), cur_value, cur_date.toStdString().data());
        query.exec(query_str);
    }
}

void History::AddResult(QString menu, int increase){
    for(int i=0; i<MENUS.size(); i++){
        if(MENUS[i].menu_name == menu){
            AddResult(i+1, increase);
        }
    }
}

int History::GetResult(int menu){
    QString cur_date = GetCurDate();//QDate::currentDate().toString("yyyy.MM.dd");

    QSqlQuery query(db);
    QString query_str;
    query_str = "SELECT * FROM history WHERE date='" + cur_date + "'";
    query.exec(query_str);
//    qDebug() << query_str;

    if(query.next()){
        // date is exist
    }else{
        // date is not exist --> return 0
        return 0;
    }

    // get value
    int cur_value;
    QString menu_name = QString().sprintf("menu%d", menu);
    query_str = QString().sprintf("SELECT %s from history WHERE date = '%s'", menu_name.toStdString().data(), cur_date.toStdString().data());
    query.exec(query_str);
//    qDebug() << query_str;

    if(query.next()){
        cur_value = query.value(menu_name).toInt();
    }
    return cur_value;
}

int History::GetResult(QString menu){
    for(int i=0; i<MENUS.size(); i++){
        if(MENUS[i].menu_name == menu){
            return GetResult(i+1);
        }
    }
}

QString History::GetCurDate(){
    QString cur_date;
    QDate date;
    int hour = QDateTime::currentDateTime().time().hour();
    if(hour < CLOSE_HOUR){
         date = QDate::currentDate().addDays(-1);
    }else{
        date = QDate::currentDate();
    }
    cur_date = date.toString("yyyy.MM.dd");
    return cur_date;
}
