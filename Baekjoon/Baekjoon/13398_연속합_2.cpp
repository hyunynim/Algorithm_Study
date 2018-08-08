#include<iostream>
#include<vector>
#include<algorithm>
#define INF -1e9
using namespace std;
vector<int> ans[2];
vector <int> seq;
int n, tmp;

int getMax(int start, bool cont) {
	if (start < 0)
		return 0;
	else {
		int & ret = ans[cont][start];
		if (ret != (int)INF)
			return ret;
			ret = 0;
			ret += seq[start];
			if (cont)
				ret = max({ ret, getMax(start - 1, 1) + ret, getMax(start - 2, 0) + ret });

			else
				ret = max({ ret, getMax(start - 1, 0) + ret });
		
		return ret;
	}
}

int main() {
	scanf("%d", &n);
	seq.resize(n);
	ans[0].resize(n);
	ans[1].resize(n);
	for (int i = 0; i < n; i++) {
		ans[0][i] = (int)INF;
		ans[1][i] = (int)INF;
		scanf("%d", &seq[i]);
	}
	getMax(n - 1, 1);
	int res = INF;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < 2; ++j)
			res = max(res, ans[j][i]);
	}
	printf("%d", res);
}