#include<cstdio>
#include<vector>

using namespace std;

vector <int> cd;
int gcd;
int GCD(int a, int b) {
	if (b == 0)
		return a;
	return GCD(b, a%b);
}

void FindCd() {
	for (int i = 1; i <= gcd; ++i) {
		if (gcd % i == 0)
			cd.push_back(i);
	}
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	gcd = GCD(a, b);
	FindCd();
	for (int i = 0; i < cd.size(); ++i) {
		printf("%d %d %d\n", cd[i], a / cd[i], b / cd[i]);
	}
}