#include <string.h>

#include <cjson/cJSON.h>

#include "github_parser.h"


static void copyString(cJSON* root,const char* key,char* destination,const char* defaultValue)
{
    cJSON* item = cJSON_GetObjectItem(root, key);
    if(item && cJSON_IsString(item) && item->valuestring)
        strcpy(destination, item->valuestring);
    else
        strcpy(destination, defaultValue);
}

static int getInt(cJSON* root,const char* key)
{
    cJSON* item = cJSON_GetObjectItem(root, key);
    if(item && cJSON_IsNumber(item))
        return item->valueint;

    return 0;
}

int parseGitHubUser(const char* json,GitHubUser* user)
{
    cJSON* root = cJSON_Parse(json);

    if(root == NULL)
        return -1;

    copyString(root, "login", user->login, "N/A");
    copyString(root, "name", user->name, "N/A");
    copyString(root, "bio", user->bio, "N/A");
    copyString(root, "location", user->location, "N/A");

    user->followers = getInt(root, "followers");
    user->following = getInt(root, "following");
    user->publicRepos = getInt(root, "public_repos");

    cJSON_Delete(root);

    return 0;
}