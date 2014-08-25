#include <stdio.h>

int f(int n) {
	print (" n %d[%u] \n", n, &n);
	return f(n+1);
	}
	
int main (int argc, char **argv) {
return f(0);
}