#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MIN = numeric_limits<int>::min();

int calc(const vector<int>& num) {
	int n = num.size(), res = MIN, psum = 0;
	for (int i = 0; i < n; ++i) {
		psum = max(psum, 0) + num[i];
		res = max(psum, res);
	}
	return res;
}

int main() {
	vector <int> num;
	int t, tmp;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	printf("%d", calc(num));
}