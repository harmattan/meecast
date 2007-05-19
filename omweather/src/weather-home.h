/*
 * This file is part of Other Maemo Weather(omweather)
 *
 * Copyright (C) 2006 Vlad Vasiliev
 * Copyright (C) 2006 Pavel Fialko
 * 	for the code
 *        
 * Copyright (C) Superkaramba's Liquid Weather ++ team
 *	for ALL the artwork (icons)
 *        The maintainer (also the main author I believe)
 *        is Matthew <dmbkiwi@yahoo.com>
 *  http://liquidweather.net/icons.html#iconsets
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
*/

#ifndef _weather_home_h
#define _weather_home_h 1

#include "weather-home_common.h"
#include <locale.h>
#include <libintl.h>

#define APPLET_X_SIZE		200
#define APPLET_Y_SIZE		40
#define FONT_MAIN_SIZE_LARGE	14
#define FONT_MAIN_SIZE_MEDIUM	12
#define FONT_MAIN_SIZE_SMALL	10

WDB* create_weather_day_button(const char *text, const char *icon, const int icon_size, gboolean transparency, char font_size);
void delete_weather_day_button(gboolean after_all_destroy,WDB **day);
void weather_buttons_init(void);
void weather_buttons_fill(gboolean check_error);
void weather_com_destroy_parser( weather_com_parser *weather_com );
void update_weather(void);
void set_font_size(GtkWidget *widget, char font_size);
void create_panel(GtkWidget* panel, gint layout, gboolean transparency, gchar* st_name, char f_size);
weather_com_parser *weather_com_parser_new( const gchar * weather_com );
int parse_weather_com_xml(void);
int c2f(int temp);
void weather_window_popup_show(GtkWidget *widget,GdkEvent *event,gpointer user_data);
gboolean download_html(gpointer data);
void update_weather(void);
void free_memory(gboolean flag);
void swap_temperature(int *hi, int *low);
/* external functions */
extern void timer(void);
extern void weather_initialize_dbus(void);
extern void add_periodic_event(time_t last_update);
extern void remove_daytime_event(void);
extern void clean_download(void);
/* List times between two updates */
GSList *time_update_list = NULL;
gboolean not_event = FALSE;
int 	   boxs_offset [Max_count_weather_day];
guint flag_update=0;
gchar  path_large_icon[_POSIX_PATH_MAX];

typedef struct _HomeAppletHandler HomeAppletHandler;

struct _HomeAppletHandler {
    GObject parent;
    gchar *desktoppath;
    gchar *libraryfile;
    GtkEventBox *eventbox;
    gint x;
    gint y;
    gint width;
    gint height;
    gint minwidth;
    gint minheight;
    gint resizable_width;
    gint resizable_height;
};

#endif
