int main(int argc, char **argv) {
	int i = 0;
	for (i = 0; i < 10000000; i++){
		malloc(32);
	}
	printf('completed');
	exit(0);
}