#include<cstdio>
#include<vector>

using namespace std;

int main() {
	int n;
	vector<int> seq;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		seq.push_back(0);

	int m;
	scanf("%d", &m);

	int a, b, c;
	for (int i = 0; i < m; ++i) {
		scanf("%d %d %d", &a, &b, &c);
		for (int j = a - 1; j < b; ++j)
			seq[j] = c;
	}
	for (int i = 0; i < seq.size(); ++i)
		printf("%d ", seq[i]);
}