#include <stdio.h>

#include "weather_formatter.h"

void printWeather(Weather* weather)
{
    printf("\n");
    printf("Weather\n");
    printf("-----------------------------\n");
    printf("Temperature : %.1f C\n",weather->temperature);
    printf("Feels Like  : %.1f C\n",weather->feelsLike);
    printf("Humidity    : %d%%\n",weather->humidity);
    printf("Wind Speed  : %.1f km/h\n",weather->windSpeed);
    printf("Condition   : %s\n",weather->description);
    printf("\n");
}