#include "Recipe.h"

QVector<ST_MENU>    MENUS;

Recipe::Recipe()
{
    db = QSqlDatabase::addDatabase("QSQLITE", "DB_RECIPE");
    QString build_path = BUILD_PATH;
    QString db_path = appPath + DB_NAME_RECIPE;
    db.setDatabaseName(db_path);

    LoadDatabase();
}


void Recipe::LoadDatabase(){
    if(!db.open()){
        qDebug() << "Load Recipe Database Fail";
        return;
    }

    QSqlQuery query(db);
    if(query.exec("SELECT * FROM recipe")){
        MENUS.clear();
        while(query.next()){
            QString menu_name = query.value("menu").toString();
            ST_MENU temp_menu;
            temp_menu.menu_name = menu_name;
            qDebug() << menu_name;

            V_RECIPE temp_recipe;
            for(int i=0; i<10; i++){
                QString str_act = QString().sprintf("act_%d", i+1);
                QString str_time = QString().sprintf("time_%d", i+1);
                if(query.value(str_act).isNull()){
                    break;
                }else{
                    ST_RECIPE_STEP temp_step;
                    temp_step.action = query.value(str_act).toString();
                    temp_step.action_time = query.value(str_time).toInt();
                    temp_recipe.push_back(temp_step);
                    qDebug() << temp_step.action << "  " << temp_step.action_time;
                }
            }
            temp_menu.recipe = temp_recipe;
            MENUS.push_back(temp_menu);
            qDebug() << endl;
        }
    }
}
