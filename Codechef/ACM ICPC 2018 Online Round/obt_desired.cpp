#include <bits/stdc++.h>

using namespace std;

#define lld long long int


int main()
{
	int t, n, i, sig, mid;
	double mid2;
	scanf("%d", &t);

	while(t--)
	{
		scanf("%d %d", &n, &sig);
		if (n == 1 && sig > 0){
			printf("-1\n");
			continue;
		} else if (n == 1) {
			printf("1\n");
			continue;
		}

		if (n % 2 == 0) {
			mid = sig + 1;
			for (i=0; i<n/2; i++){
				printf("%d ", mid - sig);
			}
			for (i=0; i<n/2; i++){
				printf("%d ", mid + sig);
			}
			printf("\n");
			continue;
		}
		// odd case
		mid2 = (sqrt((double) n) / sqrt((double) n-1)) * (double) sig;
		mid = 2*sig;
		//printf("ff %lf %lf\n", mid2, mid);
		for (i=0; i<(n/2); i++){
			printf("%lf ", ((double)mid) - mid2);
		}
		printf("%lf ", (double)mid);
		for (i=0; i<n/2; i++){
			printf("%lf ", ((double)mid) + mid2);
		}
		printf("\n");
	}

	return 0;
}