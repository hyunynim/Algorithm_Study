#include<cstdio>
#include<algorithm>

using namespace std;

double seq[532];

double sum(int s, int e) {
	double res = 0;
	for (int i = s; i <= e; ++i)
		res += seq[i];
	return res;
}

int main() {
	double n, m;
	scanf("%lf %lf", &n, &m);
	
	for (int i = 0; i < (int)n; ++i) {
		scanf("%lf", &seq[i]);
	}

	double ans = 10000000000.0;
	for (int i = m; i <= (int)n; ++i) {
		for (int j = 0; i + j - 1 < (int)n; ++j) {
			double avg = sum(j, i - 1 + j) / i;
			double tmp = 0;
			for (int k = j; k <= i - 1 + j; ++k) {
				tmp += (seq[k] - avg)*(seq[k] - avg);
			}
			tmp /= i;
			tmp = sqrt(tmp);
			ans = min(tmp, ans);
		}
	}
	printf("%.7lf", ans);
}