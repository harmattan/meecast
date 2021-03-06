/* vim: set sw=4 ts=4 et: */
/* This file is part of Other Maemo Weather(omweather)
 *
 * Copyright (C) 2006-2009 Vlad Vasiliev
 * Copyright (C) 2006-2009 Pavel Fialko
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
#ifndef _weather_gps_h
#define _weather_gps_h 1
/*******************************************************************************/
#include "weather-common.h"
/*******************************************************************************/
#ifdef ENABLE_GPS
void initial_gps_connect(void);
void deinitial_gps_connect(void);
void initial_gps_control(void);
void deinitial_gps_control(void);
void delete_all_gps_stations(void);
void get_nearest_station( double lat, double lon, Station *result);
gdouble calculate_distance(gdouble lat1, gdouble lon1, gdouble lat2, gdouble lon2);
sqlite3* open_database(const char *path, const char *filename);
void close_database(sqlite3 *database);
GtkListStore* create_regions_list(sqlite3 *database, int country_id, int *region_count);
GtkListStore* create_stations_list(sqlite3 *database, gint region_id);
gboolean check_needing_of_gps_station(void);
void gps_location_changed(LocationGPSDevice * device, gpointer userdata);
#endif
/*******************************************************************************/
#endif
