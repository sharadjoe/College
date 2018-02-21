* Simplest dead child cleanup in a SIGCHLD handler. Prevent zombie processes
 * but don't actually do anything with the information that a child died.
 */
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
 
/* SIGCHLD handler. */
static void sigchld_hdl (int sig)
{
	/* Wait for all dead processes.
	 * We use a non-blocking call to be sure this signal handler will not
	 * block if a child was cleaned up in another part of the program. */
	while (waitpid(-1, NULL, WNOHANG) > 0) {
	}
}
 
int main (int argc, char *argv[])
{
	struct sigaction act;
	int i;
 
	memset (&act, 0, sizeof(act));
	act.sa_handler = sigchld_hdl;
 
	if (sigaction(SIGCHLD, &act, 0)) {
		perror ("sigaction");
		return 1;
	}
 
	/* Make some children. */
	for (i = 0; i < 50; i++) {
		switch (fork()) {
			case -1:
				perror ("fork");
				return 1;
			case 0:
				return 0;
		}
	}
 
	/* Wait until we get a sleep() call that is not interrupted by a signal. */
	while (sleep(1)) {
	}
 
	return 0;
}
