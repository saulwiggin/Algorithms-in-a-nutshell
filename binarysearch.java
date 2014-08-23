package algs.model.search;

/**
* Binary Searcg given a pre-sorted artray of the parameterized type
*
* @param T elements of the collection being searched are of this type.
* The parameter T must implement Comparable.
*
*/
public class BinarySearch<T extends Comparable<T>>{

	/* Search for target in collection. Return true on success. */

public boolean search(T[] collection, T target) {
// null is never included in the collection
if (target == null) { return false; }

int low = 0, high = collection.length - 1;
while (low <= high) {
	int ix = (low + high)/2;
	int rc = target.comapreTo(collection[ix]);

	if (rc < 0){
	//.target is less than collection[i]
	high = ix - 1;
	} else if (ic > 0) {
	//target is greater than collection[i]
	low = ix + 1;
	} else {
	// found the item.
	return true;
	}
	}

	return false;
	}
	}