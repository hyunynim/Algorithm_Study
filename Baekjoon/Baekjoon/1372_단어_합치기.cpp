#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <iostream>
#include <cassert>

#define pb(a) push_back(a)
#define sz(a) ((int)a.size())

using namespace std;
const int INF = 987654321;
const long long LINF = 9876543212345;

int n;
int overlap[15][15];
int cache[15][1 << 15];
string cache2[15][1 << 15];
vector<string> a;
vector<string> v;

void precalc()
{
	for (int i = 0; i<n; ++i) {
		for (int j = 0; j<n; ++j) {
			if (i == j) {
				overlap[i][j] = (int)v[i].size();
				continue;
			}
			for (int k = 0; k<sz(v[i]); ++k) {
				if (sz(v[i]) - k > sz(v[j]))continue;
				if (v[i].substr(k) == v[j].substr(0, sz(v[i]) - k)) {
					overlap[i][j] = sz(v[i]) - k;
					break;
				}
			}

		}
	}
}

int restore(int last, int state)
{
	//base case : 모든 문자열이 선택 됐는지 확인
	if (state == (1 << n) - 1)return 0;
	int& ret = cache[last][state];
	if (ret != -1)return ret;

	ret = 0;
	for (int i = 0; i<n; ++i) {
		//i번째 문자열이 이미 선택 됐는지?
		if ((state & (1 << i)) == 0) {
			int d = overlap[last][i] + restore(i, state + (1 << i));
			ret = max(ret, d);
		}
	}
	return ret;
}

string reconstruct(int last, int state)
{
	if (cache2[last][state] != "")return cache2[last][state];
	if (state == (1 << n) - 1) return "";
	bool first = true;
	string a;
	for (int i = 0; i<n; ++i) {
		if (state & (1 << i)) continue;
		int ifUsed = overlap[last][i] + restore(i, state + (1 << i));
		string x;
		if (restore(last, state) == ifUsed) {
			string x = v[i].substr(overlap[last][i]) + reconstruct(i, state + (1 << i));
			if (first) {
				a = x;
				first = false;
			}
			else {
				a = min(a, x);
			}
		}
	}
	return cache2[last][state] = a;
}

bool cmp(string a, string b)
{
	if (sz(a) != sz(b))return sz(a)<sz(b);
	return a<b;
}
char tmp[55];
int main()
{
	scanf("%d", &n);
	memset(cache, -1, sizeof(cache));
	v.clear();
	a.clear();
	for (int i = 0; i<n; ++i) {
		scanf("%s", tmp);
		a.pb(tmp);
	}
	sort(a.begin(), a.end(), cmp);
	for (int i = 0; i<n; ++i) {
		bool first = true;
		for (int j = i + 1; j<n; ++j) {
			if (a[j].find(a[i]) != string::npos) {
				first = false;
				break;
			}
		}
		if (first)v.pb(a[i]);
	}
	sort(v.begin(), v.end());
	n = sz(v);
	precalc();
	int m = 0;
	for (int i = 1; i<n; ++i) {
		if (restore(m, 1 << m) < restore(i, 1 << i))m = i;
	}
	printf("%s", (v[m] + reconstruct(m,1<<m)).c_str());

}