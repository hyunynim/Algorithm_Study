#include <cstdio>
#define _USE_MATH_DEFINES
#include <math.h>
#include <complex>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
typedef complex<double> base;
int res[2400005], resn;
void fft(vector <base> &a, bool invert) {
	int n = sz(a);
	for (int i = 1, j = 0; i<n; i++) {
		int bit = n >> 1;
		for (; j >= bit; bit >>= 1) j -= bit;
		j += bit;
		if (i < j) swap(a[i], a[j]);
	}
	for (int len = 2; len <= n; len <<= 1) {
		double ang = 2 * M_PI / len*(invert ? -1 : 1);
		base wlen(cos(ang), sin(ang));
		for (int i = 0; i<n; i += len) {
			base w(1);
			for (int j = 0; j<len / 2; j++) {
				base u = a[i + j], v = a[i + j + len / 2] * w;
				a[i + j] = u + v;
				a[i + j + len / 2] = u - v;
				w *= wlen;
			}
		}
	}
	if (invert) {
		for (int i = 0; i<n; i++) a[i] /= n;
	}
}
void multiply(const vector<int> &a, const vector<int> &b) {
	vector <base> fa(all(a)), fb(all(b));
	int n = 1;
	while (n < sz(a) + sz(b)) n <<= 1;
	fa.resize(n); fb.resize(n);
	fft(fa, false); fft(fb, false);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, true);
	for (int i = 0; i < n; i++) res[i] = (int)(fa[i].real() + (fa[i].real()>0 ? 0.5 : -0.5));
	for (int i = 0; i < n; i++) if (res[i] >= 10) res[i + 1] += res[i] / 10, res[i] %= 10;
	resn = n;
	while (resn > 1 && res[resn - 1] == 0) resn--;
}
int rn;
char A[500005], B[500005], R[2000005], tmp[500000];
int main() {
	scanf("%s", A);
	scanf("%s", B);
	scanf("%s", tmp);
	int n = strlen(A), m = strlen(B), N;
	vector <int> a, b;
	int as = 0, bs = 0, mi = 0;
	if (A[0] == '-') mi ^= 1, as++, n--;
	if (B[0] == '-') mi ^= 1, bs++, m--;
	N = max(n, m);
	for (int i = n - 1; i >= as; i--) a.push_back(A[i] - '0');
	for (int i = m - 1; i >= bs; i--) b.push_back(B[i] - '0');
	for (int i = n + 1; i <= N; i++) a.push_back(0);
	for (int i = m + 1; i <= N; i++) b.push_back(0);
	multiply(a, b);
	if (mi) R[rn++] = '-';
	for (int i = resn - 1; i >= 0; i--) R[rn++] = res[i] + '0';
//	puts(R);
	if(strlen(R) > strlen(tmp))
		printf("overflow");
	else {
		if (strcmp(R, tmp) > 0)
			printf("overflow");
		else
			printf("%s", R);
	}
}