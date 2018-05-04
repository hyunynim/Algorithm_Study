#include<cstdio>
#include<vector>
#include<algorithm>
#include<string.h>

using namespace std;

vector<int> seq;
int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a%b);
}
int maxGcd = 0;
void GetGCD(vector<int> picked, int toPick, int prev) {
	if (toPick == 0) {
		maxGcd = max(maxGcd, gcd(picked[0], picked[1]));
	}
	else {
		int next = picked.empty() ? 0 : prev + 1;
		for (int i = next; i < seq.size(); ++i) {
			picked.push_back(seq[i]);
			GetGCD(picked, toPick - 1, i);
			picked.pop_back();
		}
	}
}

int main() {
	int t;
	scanf("%d", &t);
	getchar();
	for (int i = 0; i < t; ++i) {
		char s[10000];
		fgets(s, 9999, stdin);
		for (char* tok = strtok(s, " "); tok; tok = strtok(NULL, " "))
			seq.push_back(atoi(tok));
		vector<int> vtmp;
		GetGCD(vtmp, 2, 0);
		printf("%d\n", maxGcd);
		maxGcd = 0;
		seq.clear();
		vtmp.clear();
	}
}