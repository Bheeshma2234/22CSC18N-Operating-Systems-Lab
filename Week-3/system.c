#include <unistd.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
int main()
{
    pid_t child_pid;
    child_pid = fork(); 
    if (child_pid < 0)
    {
        printf("Fork failed\n");
        return 1;
    }
    else if (child_pid == 0)
    {
        printf("Child process successfully created!\n");
        printf("Child PID = %d, Parent PID = %d\n", 
               getpid(), getppid());
    }
    else
    {
        wait(NULL); 
        printf("Parent process successfully created!\n");
        printf("Parent PID = %d, Parent's Parent PID = %d\n", 
               getpid(), getppid());
    }
    return 0;
}
