#include <stdlib.h>
#include <string.h>

#include <cjson/cJSON.h>
#include "weather_parser.h"

static void copyString(cJSON* root,const char* key,char* destination,const char* defaultValue)
{
    cJSON* item =cJSON_GetObjectItem(root, key);
    if(item && cJSON_IsString(item) && item->valuestring)
        strcpy(destination,item->valuestring);
    else
        strcpy(destination,defaultValue);
}

static float getFloat(cJSON* root,const char* key)
{
    cJSON* item = cJSON_GetObjectItem(root, key);
    if(item && cJSON_IsString(item))
        return atof(item->valuestring);

    return 0;
}

static int getInt(cJSON* root,const char* key)
{
    cJSON* item =cJSON_GetObjectItem(root, key);
    if(item && cJSON_IsString(item))
        return atoi(item->valuestring);

    return 0;
}

int parseWeather(const char* json,Weather* weather)
{
    cJSON* root = cJSON_Parse(json);
    if(root == NULL)
        return -1;
    cJSON* current = cJSON_GetArrayItem(cJSON_GetObjectItem(root,"current_condition"),0);
    if(current == NULL)
    {
        cJSON_Delete(root);
        return -1;
    }

    weather->temperature = getFloat(current,"temp_C");
    weather->feelsLike = getFloat(current,"FeelsLikeC");
    weather->humidity = getInt(current,"humidity");
    weather->windSpeed = getFloat(current,"windspeedKmph");

    cJSON* descArray = cJSON_GetObjectItem(current,"weatherDesc");

    if(descArray && cJSON_IsArray(descArray))
    {
        cJSON* first = cJSON_GetArrayItem(descArray,0);
        copyString(first,"value",weather->description,"Unknown");
    }
    else
        strcpy(weather->description,"Unknown");

    cJSON_Delete(root);
    return 0;
}