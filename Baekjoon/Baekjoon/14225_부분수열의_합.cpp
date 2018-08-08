#include<cstdio>
#include<vector>

using namespace std;

vector<int> seq;
bool chk[2000005];

int main() {
	int n;
	scanf("%d", &n);
	seq.resize(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &seq[i]);
	}
	
	int sub = (1 << n) - 1;
	for (int k = (1 << n) - 1; k >= 0; --k) {
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (k & (1 << i))
				sum += seq[i];
		}
		chk[sum] = 1;
	}
	for (int i = 0; i <= 2000000; ++i) {
		if (!chk[i]) {
			printf("%d", i);
			return 0;
		}
	}
}