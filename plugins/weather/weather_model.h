#ifndef WEATHER_MODEL_H
#define WEATHER_MODEL_H

typedef struct
{
    char location[64];
    float temperature;
    float feelsLike;
    int humidity;
    char description[128];
    float windSpeed;
} Weather;

#endif