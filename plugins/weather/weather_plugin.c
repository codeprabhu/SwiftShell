#include <stdio.h>
#include <string.h>

#include "weather_plugin.h"
#include "weather_service.h"
#include "weather_parser.h"
#include "weather_formatter.h"
#include "weather_model.h"

#include "../../src/services/http/http.h"
#define HTTP_MAX_SIZE (1024*1024)

static void weather_execute(int argc,char** argv)
{
    if(argc < 2)
    {
        printf("Usage:\n");
        printf("weather <city>\n");
        return;
    }
    char response[HTTP_MAX_SIZE];
    Weather weather;
    if(getWeather(argv[1],response,sizeof(response)) != 0)
    {
        printf("Request failed.\n");
        return;
    }
    if(parseWeather(response,&weather) != 0)
    {
        printf("Failed to parse weather data.\n");
        return;
    }
    printWeather(&weather);
}

Plugin weatherPlugin =
{
    .name = "weather",
    .description = "Weather Forecast",
    .execute = weather_execute
};