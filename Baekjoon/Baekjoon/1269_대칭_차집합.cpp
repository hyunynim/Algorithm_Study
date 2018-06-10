#include<vector>
#include<algorithm>
#include<cstdio>

using namespace std;

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	vector<int> seq1(a);
	vector<int> seq2(b);

	for (int i = 0; i < a; ++i)
		scanf("%d", &seq1[i]);
	for (int i = 0; i < b; ++i)
		scanf("%d", &seq2[i]);
	sort(seq1.begin(), seq1.end());
	sort(seq2.begin(), seq2.end());
	int res1 = 0, res2 = 0;
	for (int i = 0; i < seq1.size(); ++i) {
		if (binary_search(seq2.begin(), seq2.end(), seq1[i]))
			res1++;
	}

	for (int i = 0; i < seq2.size(); ++i) {
		if (binary_search(seq1.begin(), seq1.end(), seq2[i]))
			res2++;
	}
	printf("%d", seq1.size() + seq2.size() - res1 - res2);
}