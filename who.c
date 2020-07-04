#include <stdio.h>
#include <stdlib.h>
#include <sys/utsname.h>
#include <utmp.h>
#include <time.h>
int main(void)
{
    struct utmp *n;
    time_t timestamp;
    int i;
    char *a;
    setutent();
    n=getutent();
    while(n!=NULL)
    {
        if(n->ut_type==7)
        {
            printf("%-9s",n->ut_user);
            printf("%-12s",n->ut_line);
            timestamp = n->ut_tv.tv_sec;
            a = asctime(localtime(&timestamp));
            for(i=4;i<16;i++){
                printf("%c",a[i]);
            }
            printf(" (");
            printf("%s",n->ut_host);
            printf(")\n");
        }
        n=getutent();
    }
}
