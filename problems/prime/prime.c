int is_prime(int N) {
	
	switch(N) {

		case 0:
			return 0;
		case 1:
			return 0;
		case 2:
			return 1;
		default:
			if (N > 2) {

				for (int i = N - 1; i > 1; i--) {

					if (N % i == 0) return 0;

				}
			}

			else if (N < 0) {

				N = -N;

				for (int i = N - 1; i > 1; i--) {

					if (N % i == 0) return 0;

				}

			return 1;
			
			}
	}
}
			
