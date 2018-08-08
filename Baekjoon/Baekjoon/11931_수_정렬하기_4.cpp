#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;


int main() {
	int n;
	scanf("%d", &n);
	vector<int> seq(n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &seq[i]);

	sort(seq.begin(), seq.end());
	for (auto i = seq.rbegin(); i != seq.rend(); ++i)
		printf("%d\n", *i);
}