int main(int argc, char **argv) {
	int i = 0;
	void *addrs[1000000];
	for (i = 0; i < 1000000; i++){
		addrs[i] = malloc(32);
	}
	for (i = 0; i < 1000000; i++){
		free(addrs[i]);
	}
	printf("Exit");
	exit(0);
}