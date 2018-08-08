#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<functional>
#include<string>
#include<queue>
#include<stack>
#include<string.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int main() {
	int t;
	scanf("%d", &t);
	int a, b;
	for (int i = 0; i < t; ++i) {
		int sum = 0;
		scanf("%d", &a);
		if (a == 1)
			sum += 5000000;
		else if (2 <= a && a <= 3)
			sum += 3000000;
		else if (4 <= a && a <= 6)
			sum += 2000000;

		else if (7 <= a && a <= 10)
			sum += 500000;

		else if (11 <= a && a <= 15)
			sum += 300000;

		else if (16 <= a && a <= 21)
			sum += 100000;

		scanf("%d", &a);
		if (a == 1)
			sum += 5120000;
		else if (2 <= a && a <= 3)
			sum += 2560000;
		else if (4 <= a && a <= 7)
			sum += 1280000;

		else if (8 <= a && a <= 15)
			sum += 640000;

		else if (16 <= a && a <= 31)
			sum += 320000;

		printf("%d\n", sum);


	}
}
