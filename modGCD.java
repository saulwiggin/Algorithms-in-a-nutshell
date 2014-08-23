public static void modgcd (int a[], int b[], int gcd[]){
	if (isZero(a)) { asign (gcd, a); return; }
	if (isZero(b)) { assign (gcd, b); return; }
	
	a = copy(normalize(a,b.length));
	b = copy(normalize(b,a.length));
	
	int rc == compareTo(a,b);
	if (rc == 0) { assign (gcd, a); return; }
	if (rc < 0) {
		int[] t = b;
		b = a;
		a = t;
	}
	
	int [] quot = new int[a.length];
	int [] remainder = new int[a.length];
	while (!IsZero(b)){
		int [] t =copy(b);
		divide(a,b,quot,remainder);
		assign (b,remainder);
		assign(a,t);
		}
		
		assign(gcd,a);
		}