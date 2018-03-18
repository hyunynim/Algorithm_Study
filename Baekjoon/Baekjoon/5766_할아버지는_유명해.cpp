#include <stdio.h>
#include <vector>

using namespace std;

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	
	while (m != 0 && n != 0) {
		int numChk[10001] = { 0 };
		int **ranking = new int *[n];
		for (int i = 0; i < n; i++)
			ranking[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &ranking[i][j]);
				numChk[ranking[i][j]]++;
			}
		}
		int max = 0;
		vector <int> maxNum;
		for (int i = 1; i <= 10000; i++)
		{
			if (numChk[i] > max) {
				maxNum.clear();
				max = numChk[i];
				maxNum.push_back(numChk[i]);
			}
			else if (numChk[i] == max && max != 0) 
				maxNum.push_back(numChk[i]);
		}

		printf("%d\n", maxNum.size());

		scanf("%d %d", &n, &m);
	}
}