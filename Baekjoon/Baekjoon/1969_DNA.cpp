#include<cstdio>
#include<vector>
#include<string>

using namespace std;


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int cnt[4][51] = { 0 };
	vector<string> dna;
	string strTmp;
	char msg[12345];
	for (int i = 0; i < n; ++i) {
		scanf("%s", msg);
		strTmp = msg;
		dna.push_back(strTmp);
		for (int j = 0; j < m; ++j) {
			switch (msg[j]) {
			case 'A':
				cnt[0][j]++;
				break;
			case 'C':
				cnt[1][j]++;
				break;
			case 'G':
				cnt[2][j]++;
				break;
			case 'T':
				cnt[3][j]++;
				break;
			}
		}
	}
	string minStr = "";
	for (int i = 0; i < m; ++i) {
		int maxC = 0;
		int maxI = 0;
		for (int j = 0; j < 4; ++j) {
			if (cnt[j][i] > maxC) {
				maxC = cnt[j][i];
				maxI = j;
			}
		}
		char c = 0;
		switch (maxI) {
		case 0:
			c = 'A';
			break;
		case 1:
			c = 'C';
			break;
		case 2:
			c = 'G';
			break;
		case 3:
			c = 'T';
			break;
		}
		minStr.push_back(c);
	}
	int sum = 0;
	for (int i = 0; i < n; ++i) {
		for (int k = 0; k < m; ++k) {
			if (dna[i][k] != minStr[k])
				++sum;
		}
	}
	printf("%s\n%d", minStr.c_str(), sum);
}