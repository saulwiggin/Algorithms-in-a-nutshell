/**
* Sort array ar[left, right] using Qucksort method.
* The comparision function, cmp, is needed to properly compare elements. 
*/ 
void do_sort (void **ar, int(*cmp)(const void *, const void *),
				int left, int right) {
	int pivotIndex;
	if (right <= left) { return; }
	
	/* partition */
	pivotIndex = selectPivotIndex(