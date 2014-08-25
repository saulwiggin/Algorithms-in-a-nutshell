/** 
* Sort array ar[left,right] using medianSort method.
* The comparision function, cmp, is needed to properly compae elemtns. 
*/
void mediansort(void **ar, int(*cmp)(const void *, const void *),
				int left, int right){
	/* if the subarray to be sorted has 1 (or fewer!) elemnts, done. */
	if (right <= left) { return; }
	
	/* get midpoint and median element position (l<=k<=right-left-1). */
		int mid =(right - left + 1)/2;
		int me = selectKth (ar, cmp, mid+1, left, right);
		
		mediansort(ar, cmp, left, left+mid-1);
		mediansort(ar,cmp,left+mid+1, right);
		}
		