#ifndef WEATHER_SERVICE_H
#define WEATHER_SERVICE_H

#include <string.h>

int getWeather(const char* city, char* response, size_t size);
#endif