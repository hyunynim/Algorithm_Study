#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;
vector<int> ans;

void calc(vector<int> & seq, vector<int> & oper) {
	int sum = seq[0];
	for (int i = 0; i < oper.size(); ++i) {
		switch (oper[i]) {
		case 0:
			sum += seq[i + 1];
			break;
		case 1:
			sum -= seq[i + 1];
			break;
		case 2:
			sum *= seq[i + 1];
			break;
		case 3:
			sum /= seq[i + 1];
			break;
		}
	}
	ans.push_back(sum);
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	vector<int> oper;
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);
	for (int i = 0; i < 4; ++i) {
		int num;
		scanf("%d", &num);
		for (int j = 0; j < num; ++j)
			oper.push_back(i);
	}

	do {
		calc(seq, oper);
	} while (next_permutation(oper.begin(), oper.end()));
	sort(ans.begin(), ans.end());
	printf("%d\n%d", ans.back(), ans.front());
}