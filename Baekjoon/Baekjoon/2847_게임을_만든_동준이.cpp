#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n, tmp;
	vector<int> seq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int res = 0;
	for (int i = seq.size() - 1; i > 0; --i) {
		while (seq[i - 1] >= seq[i]) {
			--seq[i - 1];
			++res;
		}
	}
	printf("%d", res);
}