/** 
* Average-case linear time recursive to find position of kth
* element in ar, which is modified as this computation proceeds. 
* Note 1 <= k <= right-left+1. This comparision function, cmp, is 
* needed to properly compare elements. Worst-case is quadratic, O(n^2).
*/
int selectKth (void **ar, int(*cmp)(const void *,const void *),
int k, int left, int right){
	int idx = selectPivotIndex (ar, left, right);
	int pivotIndex = partition(ar,left,right);
	if (left+k-1 == pivotIndex){return pivotIndex;}
	
	/* continue the loop, narrowing the range as ap[propriate. If we are within
	* the left-hand side of the pivot then k can stay the same. */
	if (left+k-1 < pivotIndex){
		return selectKth (ar,cmp, k, left, pivotIndex-1);
		} else {
		return selectKth (ar, cmp, k - (pivotIndex-left+1), pivotIndex+1, right);
		}
	}