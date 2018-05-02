#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	vector <int> num;
	int n;
	scanf("%d", &n);
	int tmp;
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	printf("%d ", num[0]);
	for (int i = 1; i < num.size(); ++i) {
		if (num[i - 1] != num[i])
			printf("%d ", num[i]);
	}
}