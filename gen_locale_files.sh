#!/bin/bash

ALL_LANGUAGES="ru_RU fi_FI fr_FR en_GB en_US it_IT de_DE es_ES es_MX pl_PL bg_BG lv_LV sk_SK sv_SV sr_SR"

xgettext  --from-code=UTF-8 --keyword=_ --keyword=Q_ --keyword=tr -f po/POTFILES.in -s -C -o po/omweather.pot
cd po
for language in $ALL_LANGUAGES; do
    echo -n "$language: "
    msgmerge -U $language.po omweather.pot
done
cd ..


for language in $ALL_LANGUAGES; do
    cp po/$language.po meecast/qt-qml/po/locale/$language
#   cp po/$language.po meecast/qt-qml/po/$language.po
done


cp -r po/*.po omweather/po
cp -r po/*.pot omweather/po

exit 0
