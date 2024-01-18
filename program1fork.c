
#include <stdio.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/wait.h> 
int main() 
{ 
 pid_t parent = getpid(); 
 pid_t pid = fork(); 
 
 if (pid == -1) 
 { 
 // error, failed to fork() 
prinÆž("fork failed\n"); 
 } 
 else if (pid > 0) 
 { 
 int status; 
prinÆž("Parent id: %d\n will be waiÆŸng for child to complete\n",getpid()); 
 waitpid(pid, &status, 0); 
 } 
 else 
 { 
 // we are the child 
prinÆž("child process1 id: %d\n",(int)pid); 
prinÆž("parent process1 id: %d\n",getppid()); 
 execl("/bin/ls", "/bin/ls", "-r", "-t", "-l", (char *) 0); 
 // execl("/home/manju","/home/manju","./a.out",NULL); 
 _exit(EXIT_FAILURE); // exec never returns 
 } 
}
