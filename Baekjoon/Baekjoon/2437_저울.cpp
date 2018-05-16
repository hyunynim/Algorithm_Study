#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>

using namespace std;
int n, tmp, sumTmp = 0;
vector<int> weight, sum;

int GetSum(int left, int right) {
	if (left == right)
		return weight[left];
	if (left == 0) {
		return sum[right];
	}
	else if (right >= n)
		right = n - 1;

	return sum[right] - sum[left - 1];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		weight.push_back(tmp);
		sumTmp += tmp;
		sum.push_back(sumTmp);
	}
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		for (int j = i; j < n; ++j) {
			res.push_back(GetSum(i, j));
		}
	}
	int i = 0, num = 1;
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (int i = 0; i < res.size(); ++i)
		printf("%d\n", res[i]);

	while (1){
		if (res[i] != num)
			break;
		++i; ++num;
	}
	printf("%d", i);
}