#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void handle_sigterm(int, siginfo_t *, void *);

int main (int argc, char **argv[])
{
 struct sigaction psa = {
  .sa_handler = NULL,
  .sa_sigaction = handle_sigterm,
  .sa_mask = 0,
  .sa_flags = SA_SIGINFO,
  .sa_restorer = NULL
 };

 sigaction(SIGTERM, &psa, NULL); 

 while(1)
 {
  printf("Hello World! from pid = %d\n", getpid());
  sleep(1);
 }
 
 return 0;
}

void handle_sigterm(int sig, siginfo_t *info, void * _unused)
{
 printf("Received signal %d from process %u started by user %d.\n", sig, info->si_pid, info->si_uid);
 printf("Terminated, sorry!\n");
 exit(0);
}
