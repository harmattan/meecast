#-------------------------------------------------
#
# Project created by QtCreator 2010-11-03T21:01:40
#
#-------------------------------------------------


TARGET = gismeteoru 
TEMPLATE = app



HEADERS += src/meego-main.h

SOURCES += src/meego-main.c


FORMS    +=

OTHER_FILES += \


CONFIG = link_pkgconfig -qt
PKGCONFIG += libxml-2.0 \
             glib-2.0

db.files = data/gismeteo.ru.db
db.path = /usr/share/omweather/db/

icon.files = data/gismeteo.ru.png
icon.path = /usr/share/omweather/copyright_icons/

source.files = data/gismeteo.ru.xml
source.path = /usr/share/omweather/sources/

#install
target.path = /usr/lib/omweather/
INSTALLS += target db icon source


