#include<time.h>

clock_t begin, end;
double time_spent;

begin = clock();

int main(int argc, char **argv) {
	int i = 0;
	for (i=0;i<10000000;i++){
		void *x = malloc(32);
		free(x);
	}
	/* here, do your time-consuming job */
	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	printf ("complete in: %d", time_spent);
	exit(0);
}
