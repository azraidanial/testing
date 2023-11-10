#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void my_signal_handler(int);

int main (int argc, char **argv[])
{
 struct sigaction psa;

 psa.sa_handler = my_signal_handler;
 sigaction(SIGINT, &psa, NULL); 
 sigaction(SIGTERM, &psa, NULL); 
 sigaction(SIGUSR1, &psa, NULL); 

 while(1)
 {
  printf("Hello World! from pid = %d\n", getpid());
  sleep(1);
 }
 
 return 0;
}

void my_signal_handler(int sig)
{
 printf("Received signal %d\n", sig);
 switch (sig)
 {
  case SIGINT:
   printf("Ignoring signal, I will continue.\n");
   break;

  case SIGTERM:
   printf("Cannot ignore signal, I will terminate now!\n");
   exit(sig);
   break;

  default:
   printf("Unknown signal! Ignored.\n");
   break;
 }

}

