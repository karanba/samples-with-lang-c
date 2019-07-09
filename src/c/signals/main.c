#include <stdio.h>
#include <signal.h>
#define SIGINT 2 /* Interrupt the process */

void intHandler(int sig)
{
	fprintf(stderr, "It's bussy.\n");
}

int main(int argc, char** argv)
{
	signal(SIGINT, intHandler);
	
	int x;
	fscanf(stdin, "%d", &x);

	return 0;
}
