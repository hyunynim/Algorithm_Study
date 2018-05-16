#include<stdio.h>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
	int n, m;
	
	while (1) {
		int numChk[10001] = { 0 };
		scanf("%d %d", &n, &m);
		vector<int> res;
		if (m == 0 && n == 0)
			return 0;
		int tmp;
		for (int i = 0; i < m*n; ++i) {
			scanf("%d", &tmp);
			numChk[tmp]++;
		}
		int maxCnt = 0;
		for (int i = 1; i <= 10000; ++i) {
			if (numChk[i] > maxCnt)
				maxCnt = numChk[i];
		}

		int secondCnt = 0;
		for (int i = 1; i <= 10000; ++i) {
			if (numChk[i] == maxCnt)
				continue;
			if (secondCnt < numChk[i] && numChk[i] != 0) {
				res.clear();
				res.push_back(numChk[i]);
				secondCnt = numChk[i];
			}
			else if (secondCnt == numChk[i])
				res.push_back(numChk[i]);
		}
		sort(res.begin(), res.end());
		for (int i = 0; i < res.size(); ++i)
			printf("%d ", res[i]);
		printf("\n");
		res.clear();
	}
}