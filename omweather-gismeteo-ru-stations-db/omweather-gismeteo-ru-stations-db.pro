#-------------------------------------------------
#
# Project created by QtCreator 2010-11-03T21:01:40
#
#-------------------------------------------------


TARGET = gismeteoru 
TEMPLATE = app



HEADERS += src/meego-main.h \
           src/hash.h

SOURCES += src/meego-main.c \
           src/hash.c

FORMS    +=

OTHER_FILES += \


CONFIG = link_pkgconfig -qt
PKGCONFIG += libxml-2.0 \
             glib-2.0

db.files = data/gismeteo.ru.db
db.path = /opt/com.meecast.omweather/share/db/

icon.files = data/gismeteo.ru.png
icon.path = /opt/com.meecast.omweather/share/copyright_icons/

source.files = data/gismeteom.ru.xml
source.path = /opt/com.meecast.omweather/share/sources/

#install
target.path = /opt/com.meecast.omweather/lib
INSTALLS += target db icon source


