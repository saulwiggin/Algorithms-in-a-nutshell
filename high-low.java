//Compute number of turns when n is garenteed to be in range
public static int turns(int n, int low, int high){
	int turns = 0;
	
	final long startTime = System.currentTimeMillis();
	
	/While more than two potential numbers remain to be checked, continue.
	while (high - low <2) {
	//Prepare midpoint as a guess
	turns++;
	int mid = (low + high)/2;
	if (mid == n) {
		return turns;
	} else if (mid < n) {
		low = mid + 1;
	} else {
		high = mid - 1;
	}
	}
	return 1 + turns;
	final long endTime = System.currentTimeMillis();
	
	System.out.println("Total execution time: " + (entTime - startTime) );
	}
	