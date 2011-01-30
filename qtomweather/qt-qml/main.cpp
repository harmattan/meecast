#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsWidget>
#include <QGraphicsLinearLayout>
#include <QDeclarativeComponent>
#include <QDeclarativeContext>
#include <QDeclarativeEngine>
#include <QDeclarativeView>
#include <QTranslator>
#include <QGraphicsGridLayout>
#include <exception>
#include <iostream>

#include "core.h"
#include "dataqml.h"
#include "configqml.h"
#include "qmllayoutitem.h"
#include "dataitem.h"
#include "datamodel.h"
#include "parserqt.h"
#include "databasesqlite.h"


#include <QtDebug>
#ifdef LOCALDEBUG
    #define CONFIG_PATH "config.xml"
    #define CONFIG_XSD_PATH "../core/data/config.xsd"
#else
    #define CONFIG_PATH "~/.config/omweather/config.xml"
    #define CONFIG_XSD_PATH "/usr/share/omweather/xsd/config.xsd"
#endif
//////////////////////////////////////////////////////////////////////////////

ConfigQml *
create_and_fill_config(){
    ConfigQml *config;
    std::cerr<<"Create ConfigQML class: " <<std::endl;
    try{
        config = new ConfigQml(CONFIG_PATH, CONFIG_XSD_PATH);
    }
    catch(const std::string &str){
        std::cerr<<"Error in ConfigQML class: "<< str <<std::endl;
        config = new ConfigQml();
    }
    catch(const char *str){
        std::cerr<<"Error in ConfigQML class: "<< str <<std::endl;
        config = new ConfigQml();
    }
    std::cerr<<"End of creating ConfigQML class: " <<std::endl;
    config->saveConfig("newconfig.xml");
    return config;
}
//////////////////////////////////////////////////////////////////////////////
bool
update_weather_forecast(std::vector<Core::Station*> StationsList){
    int i;
    Core::Station* station;
    for (i=0; i<StationsList.size();i++){
        station = StationsList.at(i);
     //   std::cerr<<"yyyyyy    "<< station->forecastURL()<<std::endl;
    }
}

int main(int argc, char* argv[])
{
    QApplication::setGraphicsSystem("native");
    QApplication app(argc, argv);



/*
    //Set up a graphics scene with a QGraphicsWidget and Layout
    QGraphicsView view;
    QGraphicsScene scene;
    QGraphicsWidget *widget = new QGraphicsWidget();
    QGraphicsGridLayout *layout = new QGraphicsGridLayout;
    layout->setSpacing(0);
    widget->setLayout(layout);
    scene.addItem(widget);
    view.setScene(&scene);
*/

    //Add the QML snippet into the layout

    Core::DatabaseSqlite *db = new Core::DatabaseSqlite("weather.com.db");

    db->open_database();
    Core::listdata * list = db->create_stations_list(18);
    Core::listdata::iterator cur;
    for (cur=list->begin(); cur<list->end(); cur++)
        std::cerr << (*cur).first << " - " << (*cur).second << std::endl;
    return 0;

    ConfigQml *config;
    DataItem *forecast_data = NULL;

    //Core::DataList data_list;
    //QmlLayoutItem* qml_layout_item;
    Core::DataParser* dp;
    Core::Data *temp_data = NULL;
    int i;

    std::vector<Core::Station*> StationsList;

    config = create_and_fill_config();
    std::cerr<<"iconpath = "<<config->prefix_path()<<std::endl;
    StationsList = config->stationsList();
    std::cerr<<"size "<<StationsList.size()<<std::endl;
    update_weather_forecast(StationsList);

    try{
        dp = new Core::DataParser("data.xml", "../core/data/data.xsd");
    }
    catch(const std::string &str){
        std::cerr<<"Error in DataParser class: "<< str <<std::endl;
        dp = new Core::DataParser();
        //return -1;
    }
    catch(const char *str){
        std::cerr<<"Error in DataParser class: "<< str <<std::endl;
        dp = new Core::DataParser();
        //return -1;
    }

    DataModel *model = new DataModel(new DataItem, qApp);
    i = 0;
    while  (temp_data = dp->data().GetDataForTime(time(NULL) + i)) {
        i = i + 3600*24;
        forecast_data = new DataItem(temp_data);
        model->appendRow(forecast_data);

    }

    QTranslator translator;
    translator.load("ru.qml", "i18n");
    app.installTranslator(&translator);

    QDeclarativeView qview;
    /*
    if (forecast_data){
        qview.rootContext()->setContextProperty("Forecast", forecast_data);
    }*/
    //std::cout << "temp = " << model->getRow(2) << std::endl;
    qview.rootContext()->setContextProperty("Forecast_model", model);
    qview.rootContext()->setContextProperty("Config", config);
    qview.setSource(QUrl(":weatherlayoutitem.qml"));
    qview.show();

/*
    qml_layout_item = new QmlLayoutItem(config, forecast_data);
    layout->addItem(&qml_layout_item->obj(),0,0);

    forecast_data =  create_and_fill_class_data_for_day_forecast();
    qml_layout_item = new QmlLayoutItem(config, forecast_data);
    layout->addItem(&qml_layout_item->obj(),0,1);



    widget->setGeometry(QRectF(0,0, 800,400));



    view.show();
*/

    return app.exec();
}
