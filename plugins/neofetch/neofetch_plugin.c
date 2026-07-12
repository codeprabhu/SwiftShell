#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/utsname.h>
#include <unistd.h>

#include "neofetch_plugin.h"

static void neofetch_execute(int argc, char* argv[])
{
    struct utsname info;
    uname(&info);

    char hostname[256];
    gethostname(hostname, sizeof(hostname));

    FILE* fp;

    char cpu[256] = "Unknown";
    fp = fopen("/proc/cpuinfo", "r");
    if(fp)
    {
        char line[512];
        while(fgets(line,sizeof(line),fp))
        {
            if(strncmp(line,"model name",10) == 0)
            {
                char* colon = strchr(line,':');
                if(colon)
                {
                    strcpy(cpu, colon + 2);
                    cpu[strcspn(cpu,"\n")] = '\0';
                }
                break;
            }
        }
        fclose(fp);
    }

    long totalRam = 0;
    fp = fopen("/proc/meminfo","r");
    if(fp)
    {
        fscanf(fp,"MemTotal: %ld kB",&totalRam);
        fclose(fp);
    }

    const char* tree[] =
    {
    "          ／＞　 フ",
    "         | 　_　_|",
    "       ／` ミ＿xノ",
    "      /　　　　 |",
    "     /　 ヽ　　 ﾉ",
    "    │　　|　|　|",
    "／￣|　　 |　|　|",
    "| (￣ヽ＿_ヽ_)__)",
    "＼二つ"
    };

    const char* infoLines[] =
    {
        "",
        "---------------------------",
        "",
        "",
        "",
        "",
        "",
        "",
        "",
        ""
    };

    for(int i = 0; i < 11; i++)
    {
        printf("\n");
        printf("\033[32m%-30s\033[0m",tree[i]);

        switch(i)
        {
            case 0:
                printf("%s@swiftshell",hostname);
                break;

            case 1:
                printf("---------------------------");
                break;

            case 2:
                printf("OS        : %s",info.sysname);
                break;

            case 3:
                printf("Kernel    : %s",info.release);
                break;

            case 4:
                printf("Machine   : %s",info.machine);
                break;

            case 5:
                printf("Hostname  : %s",hostname);
                break;

            case 6:
                printf("CPU       : %.45s",cpu);
                break;

            case 7:
                printf("Memory    : %.2f GB",
                       totalRam / 1024.0 / 1024.0);
                break;

            case 8:
                printf("Shell     : SwiftShell");
                break;

            case 9:
                printf("License   : MIT");
                break;

            case 10:
                printf("Version   : v0.9");
                break;
        }
    }
    printf("\n");
    for(int i = 30; i <= 37; i++)
        printf("\033[%dm██\033[0m ",i);

    printf("\n");

    for(int i = 90; i <= 97; i++)
        printf("\033[%dm██\033[0m ",i);

    printf("\n\n");
}

Plugin neofetchPlugin =
{
    .name = "neofetch",
    .description = "SwiftShell system information",
    .execute = neofetch_execute
};