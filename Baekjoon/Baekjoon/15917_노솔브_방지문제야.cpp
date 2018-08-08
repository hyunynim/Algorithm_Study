#include<cstdio>

int main() {
	int q, a;
	scanf("%d", &q);
	for (int i = 0; i<q; ++i) {
		scanf("%d", &a);
		if ((a & (-a)) == a)
			puts("1");
		else
			puts("0");
	}
}