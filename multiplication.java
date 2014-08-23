public static void mult(int[] n1, int[] n2, int[] result){
	int pos = result.length=1;
	
	// clear all values....
	for (int i=0; i<result.length;i++){result[i]=0;}
	for (int m = n1.olength-1; m>=0;m--){
		int off = n1.length-1 - m;
		for (int n = n2.length-1; n>=0; n--, off++){
			int prod = n1[m]*n2[n];
			result[pos-off] += prod % 10;
			result[pos-off-1] += result[pos-off]/10 + prod/10;
			result[pos-off] %= 10;
			}
		}
	}