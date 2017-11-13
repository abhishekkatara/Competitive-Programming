#include <bits/stdc++.h>

using namespace std;

#define lld long long int


bool more(int a, int b, int c, int d, int e, int f){
	if (a >= d && b >= e && c >= f){
		return (a > d) || (b > e) || (c > f);
	}
	return false;
}

int main()
{
	int t, a, b, c, d, e, f, g, h, i;
	scanf("%d",&t);

	while(t--)
	{
		scanf("%d %d %d", &a, &b, &c);
		scanf("%d %d %d", &d, &e, &f);
		scanf("%d %d %d", &g, &h, &i);

		if (more(a, b, c, d, e, f) && more(d, e, f, g, h, i)) { // 1 2 3
			printf("yes\n"); continue;
		}

		if (more(d, e, f, g, h, i) && more(g, h, i, a, b, c)) { // 2 3 1
			printf("yes\n"); continue;
		}

		if (more(g, h, i, a, b, c) && more(a, b, c, d, e, f)) { // 3 1 2
			printf("yes\n"); continue;
		}

		if (more(g, h, i, d, e, f) && more(d, e, f, a, b, c)) { // 3 2 1
			printf("yes\n"); continue;
		}

		if (more(d, e, f, a, b, c) && more(a, b, c, g, h, i)) { // 2 1 3
			printf("yes\n"); continue;
		}

		if (more(a, b, c, g, h, i) && more(g, h, i, d, e, f)) { // 1 3 2
			printf("yes\n"); continue;
		}

		printf("no\n");
	}

	return 0;
}