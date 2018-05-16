#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, max = 0, tmp;
	vector<int> price;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		price.push_back(tmp);
		for (int j = 0; j < i; ++j) {
			if (price[i] - price[j] > max)
				max = price[i] - price[j];
		}
	}
	printf("%d", max);

}