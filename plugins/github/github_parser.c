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

int parseGitHubRepo(const char* json,GitHubRepo* repo)
{
    cJSON* root = cJSON_Parse(json);

    if(root == NULL)
        return -1;

    copyString(root, "name",repo->name, "N/A");
    copyString(root, "description",repo->description, "N/A");
    copyString(root, "language",repo->language, "N/A");
    copyString(root, "homepage",repo->homepage, "N/A");

    repo->stars =getInt(root, "stargazers_count");
    repo->forks =getInt(root, "forks_count");
    repo->watchers =getInt(root, "watchers_count");
    repo->openIssues =getInt(root, "open_issues_count");

    cJSON* owner =
    cJSON_GetObjectItem(root, "owner");
    if(owner)
        copyString(owner,"login",repo->owner,"N/A");

    cJSON* license =cJSON_GetObjectItem(root,"license");
    if(license)
        copyString(license,"spdx_id",repo->license,"N/A");
    
    cJSON_Delete(root);
    return 0;
}

int parseGitHubIssues(const char* json,GitHubIssue issues[],int maxIssues)
{
    cJSON* root = cJSON_Parse(json);
    if(root == NULL)
        return -1;
    if(!cJSON_IsArray(root))
    {
        cJSON_Delete(root);
        return -1;
    }
    int count = cJSON_GetArraySize(root);
    if(count > maxIssues)
        count = maxIssues;
    for(int i = 0; i < count; i++)
    {
        cJSON* issue = cJSON_GetArrayItem(root, i);
        issues[i].number = getInt(issue, "number");

        copyString(issue,"title",issues[i].title,"N/A");
        copyString(issue,"state",issues[i].state,"N/A");
    }
    cJSON_Delete(root);
    return count;
}

int parseGitHubRelease(const char* json,GitHubRelease* release)
{
    cJSON* root = cJSON_Parse(json);
    if(root == NULL)
        return -1;
    copyString(root,"tag_name",release->tag,"N/A");
    copyString(root,"name",release->name,"N/A");
    copyString(root,"published_at",release->published,"N/A");
    copyString(root,"body",release->body,"No release notes.");

    cJSON_Delete(root);
    return 0;
}