#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int CalcMoney(int a, int b, int c) {
	int res = 0;
	if (a == b && b == c) 
		return 10000 + a * 1000;
	
	if (a == b || a == c)
		return 1000 + a * 100;

	if (b == c)
		return 1000 + b * 100;

	else
		return max(a, max(b, c)) * 100;
}

int main() {
	int n;
	scanf("%d", &n);
	vector<int> score(n);
	for (int i = 0; i < n; ++i) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		score[i] = CalcMoney(a, b, c);
	}
	sort(score.begin(), score.end());
	printf("%d", score[n - 1]);
}