#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigint(int);
void handle_sigterm(int);
void handle_sigkill(int);

int main (int argc, char **argv[])
{
 int count;
 //signal(SIGINT, handle_sigint);
 signal(SIGINT, SIG_IGN);
 signal(SIGTERM, handle_sigterm);
 signal(SIGKILL, handle_sigkill);

 count = 0;

 while(1)
 {
  count++;
  printf("Hello World!\n");
  sleep(1);
  if(count % 10 == 0)
  {
   //raise signal
   raise(SIGINT);
  }

 }
 
 return 0;
}

void handle_sigint(int sig)
{
 printf("Received signal %d\n", sig);
}

void handle_sigterm(int sig)
{
 printf("Received signal %d\n", sig);
 printf("Terminated, sorry!\n");
 exit(0);
}

void handle_sigkill(int sig)
{
 printf("Received signal %d\n", sig);
 printf("Oh no, I got killed!\n");
 exit(0);
}
