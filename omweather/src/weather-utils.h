/* vim: set sw=4 ts=4 et: */
/*
 * This file is part of Other Maemo Weather(omweather)
 *
 * Copyright (C) 2006-2009 Vlad Vasiliev
 * Copyright (C) 2006-2009 Pavel Fialko
 * Copyright (C) 2008 Andrew Olmsted
 * 	for the code
 *        
 * Copyright (C) 2008 Andrew Zhilin
 *		      az@pocketpcrussia.com 
 *	for default icon set (Glance)
 *
 * This software is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2.1 of
 * the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU weather-config.h General Public
 * License along with this software; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA
 * 02110-1301 USA
*/
/*******************************************************************************/
#ifndef _weather_utils_h
#define _weather_utils_h 1
/*******************************************************************************/
#include "weather-common.h"
/*******************************************************************************/
float convert_wind_units(int to, float value);
float mb2inch(float pressure);
float mb2mm(float pressure);
void set_font(GtkWidget *widget, const gchar *description, const gint size);
gboolean draw_label_gradient(GtkWidget *widget, GdkEventExpose *event);
gboolean draw_top_gradient(GtkWidget *widget, GdkEventExpose *event);
gboolean draw_bottom_gradient(GtkWidget *widget, GdkEventExpose *event);
void set_background_color(GtkWidget *widget, GdkColor *bgc);
void set_font_color(GtkWidget *widget, guint16 red, guint16 green, guint16 blue);
void change_state_window(GtkWidget *window);
float c2f(float temp);
void swap_temperature(int *hi, int *low);
GtkWidget* lookup_widget(GtkWidget* widget, const gchar* widget_name);
#define GLADE_HOOKUP_OBJECT(component,widget,name) \
    g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
    g_object_set_data (G_OBJECT (component), name, widget)
GtkWidget* create_tool_item(const char *path, const char *image_name, int image_size);
GtkWidget* create_button_with_image(const char *path, const char *image_name,
				    int image_size, gboolean with_border,
				    gboolean toggled);
GtkWidget* create_tree_view(GtkListStore* list);
GtkWidget* create_scrolled_window_with_text(const char* text,
					    GtkJustification justification);
int create_icon_set_list(gchar *dir_path, GSList **store, gchar *type); /* scan dir */
					     /* and add names to the list */
void update_icons_set_base(const char *icon_set_name);
void free_icon_set_list(GSList *iconset);
GtkWidget *create_icon_widget(GdkPixbuf *icon_buffer, const char *icon_path, int icon_size, GSList **objects_list);
gint choose_wind_direction(gchar *buffer);
void write_log(char *string);
GtkWidget* create_button_with_2_line_text(const gchar *first_line_text, const gchar *second_line_text,
                                const gint first_line_text_size, const gint second_line_text_size);
gboolean browser_url(gchar *url);
void reload_omw_plugin(void);
GtkWidget *create_hildon_clutter_icon_animation(const char *icon_path, int icon_size, GSList **objects_list);
GHashTable* parse_animation_file(const gchar *filename, const gchar *encoding);
gchar* create_presets_image_path(gchar* image);
void load_style(void);

#if defined HILDONANIMATION
GHashTable *clear_animation_hash(GHashTable *hash);
#endif
/*******************************************************************************/
#endif
