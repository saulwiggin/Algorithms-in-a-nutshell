int main(int argc, char **argv) {
	int i = 0;
	for (i=0;i<10000000;i++){
		void *x = malloc(32);
		free(x);
	}
	printf ("complete");
	exit(0);
}
