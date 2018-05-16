#include<cstdio>
#include<vector>

using namespace std;
int n, m;
vector<int> seq, sum;

int GetSum(int left, int right) {
	if (left == 0) {
		return sum[right];
	}
	else if (right >= n)
		right = n - 1;

	return sum[right] - sum[left - 1];
}

int main() {
	int tmp, tmpSum = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
		tmpSum += tmp;
		sum.push_back(tmpSum);
	}

	int left = 0, right = 0, res = 0;
	tmp = GetSum(left, right);
	while (tmp < m) {
		right++;
		tmp = GetSum(left, right);
	}
	while (left < n) {
		if (tmp == m) {
			right++;
			res++;
			if (right >= n)
				break;
		}
		else if (tmp > m) {
			left++;
		}
		else {
			right++;
			if (right >= n)
				break;
		}
		tmp = GetSum(left, right);
	}

	printf("%d", res);
}