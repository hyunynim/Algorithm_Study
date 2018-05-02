#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n;
	vector <int> num;
	while (1) {
		scanf("%d", &n);
		if (n == 0)
			return 0;

		int tmp;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &tmp);
			if(num.empty() || tmp != num.back())
				num.push_back(tmp);
		}
		for (int j = 0; num.begin() + j != num.end(); ++j) {
			printf("%d ", num[j]);
		}
		printf("$\n");
		num.clear();
	}
}