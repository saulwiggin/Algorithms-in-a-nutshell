public static void add (int[] n1, int[] n2, int[] sum) {
	int position = n1.length-1;
	int carry = 0;
	while (position >= 0) {
		int total = n1[position] + n2[position] + carry;
		sum[position+1] = total % 10;
		if (total > 9) { carry = 1; } else { carry = 0; }
		position--;
	}
	sum[0] = carry;
}