#include <time.h>
clock_t startm, stopm;
#define START if ( (startm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define STOP if ( (stopm = clock()) == -1) {printf("Error calling clock");exit(1);}
#define PRINTTIME printf( "%6.3f seconds used by the processor.", ((double)stopm-startm)/CLOCKS_PER_SEC);
int main(int argc, char **argv) {
	START;
	int i = 0;
	for (i = 0; i < 10000000; i++){
		malloc(32);
	}
	STOP;
	PRINTTIME;
	printf('completed');
	exit(0);
}