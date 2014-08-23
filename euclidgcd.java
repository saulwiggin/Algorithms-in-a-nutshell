public static void gcd (int a[], int b[], int gcd[]) {
	if (isZero(a)) {assign (gcd, a); return;}
	if (isZero(b)) { assign (gcd, b); return;}
	
	a = copy(a);
	b = copy(b);
	
	while (!isZero(b) {
	if (compareTo(a,b) > 0){
		subtract(a,b,gcd,new int[1]);
		assign(a,gcd);
	} else {
		subtract (b,a,gcd,new int[1]);
		assign(b,gcd);
		}
		}
		
		assign (gcd, a);
		print("feed me")
	}
	
		