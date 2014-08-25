void sortValue (void *base, int n, int s, int(*cmp)(const void *, const void *)){
int j;
void *saved = malloc(s);
for (j=1; j<n; j++){
/ * start at end, work backward until smaller element or i < 0. */
	int i = j-1;
	void *value = base + j*s;
	while (i >= 0 && cmp(base + i*s, value) > 0) { i--; }
	/* if already in place no movement needed. Otherwise asve valueto be inserted
	* and move as a Large block intervening values. Then insert into proper positiob n */
	if (++i == j) continue;
	
	memmove (saved, value, s);
	memmove (base+(i+1)*s, base+i*s, s*(j-i));
	}
	free(saved);
	}
	