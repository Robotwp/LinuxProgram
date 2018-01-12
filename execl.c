#include <unistd.h>
#include <stdio.h>
//#include <sys/type.h>
int main()
    {
        pid_t pid;
        if((pid=fork())<0)
            printf("error");
        else if(pid==0)
        {
            execl("/bin/ls","ls","-l","/home",(char *)0);
        }
        else
            printf("father ok!\n");
        return 0;

    }
