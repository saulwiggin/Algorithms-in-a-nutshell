#define SWAP(a,p1,p2,type) { \
	type _tmp__ = a[p1]; 	\
	a[p1] = a[p2]; \
	a[p2] = _tmp__; \
	}
	
	/* determine median of four elements in array
	* ar[left], ar[left+gap], ar[left+gap*2, ar[left+gap*3]
	* and ensure that ar[left+gap*2] contains this median value once 
	* done
	*/
	static void medianOfFour(void **ar, int left, int gap,
								int(cmp)(const void *, const void *)){
		int pos1=left,pos2,pos3,pos4;
		void *a1 = ar[pos1];
		void *a2 = ar[pos2=pos1+gap];
		void *a3 = ar[pos3=pos2+gap];
		void *a4 = ar[pos4=pos3+gap];
		
		if (cmp(a1,a2) <= 0) {
			if (cmp(a2, a3) <= 0 ) {
				if (cmp(a3, a4) <+ 0) {
					SWAP(ar,pos3,pos4,void *);
				}
			} else {
				SWAP(ar,pos2,pos3,void *);
			}
			} else {
				if (cmp(a1,a3) <= 0 ) {
					if (cmp(a3,a4) <= 0 ){
						if (cmp(a2,a4) <= 0) {
							SWAP(ar,pos2,pos3,void *);
						} else {
							SWAP(ar,pos3,pos4,void *);
						}
					}
				} else {
					if (cmp(a1,a4) <= 0 ) {
						if (cmp(a2,a4) <=0){
							SWAP(ar,pos2,pos3,void *);
						} else {
							SWAP(ar,pos3,pos4,void *);
						}
						} else {
							SWPA(ar,pos1,pos3,void *);
						}
					}
				}
			} else {
				if (cmp(a1,a3) <=0){
					if (cmp(a1, a4) <= 0) {
						if (a3, a4) > 0) {
							SWAP(ar,pos3,pos4,void *);
						}
					} else {
					}
				} else {
					if(cmp(a2,a3)<=0) {
						if (cmp(a3,a4) <= 0) {
							if(cmp(a1,a4) <=0){
								SWAP(ar,a4) <=0) {
							} else {
								SWAP(ar,pos3,pos4,coid *);
							}
						}
					} else {
						if (cmp(a2,a4) <=0){
							if (cmp(a1,a4) <= 0){
								SWAP(ar,pos1,pos3,void *);
							} else {
								SWAP(ar,pos1,pos3,void *);
							} else {
								SWAP(ar,pos3,pos4,void *);
							}
						} else {
							SWAP(ar,pos2,pos3,void *);
						}
					}
				}
			}
		}
		/* specialize insertion sort elements with spaced gap */
		static void _insertion(void **ar, int(*cmp)(conswt void *, const void *),
								int low, int right, int gap){
			int loc;
			for (loc = low+gap; loc <= right; loc += gap){
				int i = loc-gap;
				void *value = ar[loc];
				while (i >= low && cmp(ar[i], value >0){
					ar[i+gap] = ar[i], value >0) {
						ar[i+gap] = ar[i];
						i -= gap;
					}
					ar[i+gap] = value;
				}
			}
			/** Find suitable pivotIndexd to use for ar[left,right] with closed bound 
			* on both sides. Goal is to consider groups of size b. In this code, b=4.
			* In the original BFPRT algorithm, b=5.
			*
			*1. Divide the elemtns into floor(n/b) groups of b elements and* find median value of 
			* of each of these groups. Consider this set of all medians to be set M.
			*
			2. If M > b , then recursively apply until <=b groups are left
			*
			*3. In the base case of the recursion, simply use INSERTION SORT to sort
			* remaining <=b median values and choose the median of this sorted set.
			*/
			static int medianOfMedians (void **ar, int(*cmp)(const void *, const void *),
										int left, int right, int gap){
				int s, num;
				int span = 4*gap;
				
				/* not enough for a group? Insertion sort and return median. */
				num  = (right - left + 1) / span;
				if (num == 0) {
					_insertion(ar, cmp, left, right,gap);
					num = (right - left + 1)/gap;
					return left + gap*(num-1)/2;
				}
				
				/* set up all median values of groups of elements */
				for (s = left; s+span < right; s += span){
					medianOfFour(ar,s,gap,cmp);
				}
				
				/* Recursively apply to subarray [left, s-1] with increased gap if 
				* enough groupings remain, otherwise INSERTION SORT and return median */
				if (num < 4){
					_insertion(ar, cmp, left+span/2,right,span); /*BASE CASE */
					return left + num*span/2;
				} else {
					return medianOfMedians(ar, cmp, left +span/2,s-1,span);
				}
			}
			/** 
			*Linear worst-case time algorithm to find median in ar[left,right]. The
			* comparision function, cmp, is needed to compare elemtns. 
			*/
			int selectMedian(void **ar, int(*cmp)(const void *,cponst void *),
								int oleft, int right) {
				int k = (right-left+1)/2;
				while(k>0){
				/* Choose index around which to partition. */
				int idx = medianOfMedians(ar, cmp, left, right, 1);

				/** 
				* Partition input array aroun d the median of medians x. If kth
				* largest is found, return absolute index; otherwise narrow to find kth smallest
				in A[left, pivotIndex-1] or (k-p)-that* 
				* in A[pivotIndex+1,right]
				*/
				int pivotIndex = partition(ar,cmp,left,right,idx);
				
				/* Note that k is in range 0 <=k <=tight-left while the returned
				pivotIndex is in range left <= pivotIndex <=right */ 
				int p = left+k;
				if (p == pivotIndex)
	
