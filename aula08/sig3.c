#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

#define NTIMES 50

static void Interrupt (int);
static int interrupt_count = 0;

int main(int argc, char *argv[])
{
    struct sigaction sigact;
    unsigned int i;

    /* altera a rotina de atendimento ao ^C */
    sigact.sa_handler = Interrupt;
    sigemptyset (&sigact.sa_mask);
    sigact.sa_flags = 0;
    if (sigaction(SIGINT, &sigact, NULL) < 0) { 
        perror("Rotina de atendimento não instalada\n");
        return EXIT_FAILURE;
    }

    /* contador */
    printf("PID = %u\n", getpid());
    i = 0;
    while (i <= NTIMES) { 
       printf("\r%08u ", i++);
       fflush(stdout);
       sleep(1);
    }
    printf("\n");
 
    return EXIT_SUCCESS;
}

static void Interrupt (int signum) {
    interrupt_count++;
    if (interrupt_count > 4) {
        signal(SIGINT, SIG_DFL);
    }
}