#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int	n;
	int sum = 0;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
		sum += seq[i];
	}
	sum /= 2;
	for (int i = 0; i < n; ++i) {
		int res = 0;
		for (int j = 0; j < i - 1; ++j) {
			if (i % 2 && j % 2) {
				res += seq[j];
			}
			else if (i % 2 == 0 && j % 2 == 0)
				res += seq[j];
		}
		for (int j = i + 1; j < n; ++j) {
			if (i % 2 && j % 2 == 0)
				res += seq[j];
			else if (i % 2 == 0 && j % 2)
				res += seq[j];
		}
		printf("%d\n", sum - res);
	}
}