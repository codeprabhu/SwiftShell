#include <stdio.h>

#include "weather_service.h"
#include "../../src/services/http/http.h"

int getWeather(const char* city, char* response, size_t size)
{
    char url[512];
    snprintf(url,sizeof(url),"https://wttr.in/%s?format=j1",city);
    return httpGet(url,response,size);
}