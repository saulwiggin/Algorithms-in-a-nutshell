public static void last(int[] n1, int[] n2, int[] sum) {
	int position = n1.length;
	int carry = 0;
	while (--position >= 0) {
		int total = n1[position] + n2[position] + carry;
		if (total > 9) {
			sum[position+1] = total-10;
			carry=1;
		} else {
			sum[position+1] = total;
			carry =0;
		}
	}
	sum[0] = carry;
}