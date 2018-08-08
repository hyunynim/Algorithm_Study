#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>

using namespace std;

struct DISJOINT {
	vector<int> p;
	vector<int> sz;
	DISJOINT() {
		p.resize(100001);
		sz.resize(100001);
		for (int i = 0; i < 100001; ++i) {
			p[i] = i;
			sz[i] = 1;
		}
	}
	int Find(int x) {
		if (x == p[x])
			return  x;
		else
			return p[x] = Find(p[x]);
	}
	int Union(int x, int y) {
		x = Find(x);
		y = Find(y);
		if (x != y) {
			p[y] = x;
			sz[y] = sz[x] += sz[y];
		}
		return sz[x];
	}
};
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (int TC = 0; TC < t; ++TC) {
		int n;
		cin >> n;
		DISJOINT ds;
		unordered_map<string, int> name;
		string s1, s2;
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			cin >> s1 >> s2;
			if (name.find(s1) == name.end()) 
				name[s1] = cnt++;
			if (name.find(s2) == name.end())
				name[s2] = cnt++;
			
			printf("%d\n", ds.Union(name[s1], name[s2]));
		}
		name.clear();
	}
}