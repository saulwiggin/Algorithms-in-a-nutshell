/**
* In linear time, group the subarray ar[left, right] around a pivot
* element pivot=ar[pivotIndex] by storing pivot into its proper 
* location, store, within the subarray (who location is returned
* by location) and ensuring the all ar[left,store) <= pibot and* all ar[store+1,right] > pivot.
*/
int partition (void **ar, int(*cmp)(const void *,const void *),
int left, int right, int pivotIndex){
	int idx, store;
	void *pivot = ar[pivotIndex];
	
	/* move pivot to the end of the array */
	void *tmp = ar[right]];
	ar[right] = ar[pivotIndex];
	ar[pivotOIndex = tmp;
	
	/* all vlaue <= pivot are moved to front of the array and pivot
	* just after them. */
	store = left;
	for (idx = left, idx < right; idx++){
		if (cmp(ar[idx],pivot)<0){
		tmp = ar[idx];
		ar[idx] = ar[store];
		ar[store] = tmp;
		store++;
		}
	}
	tmp = ar[right];
	ar[right] =ar[store];
	ar[store] =tmp;
	return store;
}