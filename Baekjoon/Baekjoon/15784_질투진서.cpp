#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
	int n, tmp, charm, a, b;
	int max1 = 0, max2 = 0;
	scanf("%d %d %d", &n, &a, &b);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			scanf("%d", &tmp);
			if (i == a - 1) 
				max1 = max(max1, tmp);

			if (j == b - 1)
				max2 = max(max2, tmp);
			if (i == a - 1 && j == b - 1)
				charm = tmp;
		}
	}
	if (max1 == charm && max1 == max2)
		printf("HAPPY");
	else
		printf("ANGRY");
}