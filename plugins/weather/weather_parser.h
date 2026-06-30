#ifndef WEATHER_PARSER_H
#define WEATHER_PARSER_H

#include "weather_model.h"

int parseWeather(const char* json,Weather* weather);
#endif