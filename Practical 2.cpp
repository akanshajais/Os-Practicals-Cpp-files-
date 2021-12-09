//practical 2 : Write a program to demonstrate fork where .........................

#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main()
{
    pid_t pid;
	/* fork a child process */
	pid = fork();
    if (pid < 0)
    {
		/* error occurred */
		fprintf(stderr, "Fork Failed!!!");
        return 1;
    }
    else if (pid == 0)
    {
		/* child process */
		execlp("/bin/ls","ls",NULL);
    }
    else
    {
		/* parent process */
		/* parent will wait for the child to complete */
		wait(NULL);
        printf("Parent process executed !!!!!");
    }
    return 0;
}
