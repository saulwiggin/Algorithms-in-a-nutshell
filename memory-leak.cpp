#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** Return string "abcdef" as "fabcde" */
char *cycle (char *s) {
	int n = strlen(s);
	char *u = malloc(n+1);
	strncpy (u, s+1, n-1);
	u[n-1] = s[0];
	u[n] = '\0';
	return u;
	}
	
int main (int argc, char **argv) {
		char *s = strdup("ThisStringHas25Characters");
		int num=0;
		
		for(;;){
			printf("%d\n", ++num);
			s=cycle(s);
		}
	}