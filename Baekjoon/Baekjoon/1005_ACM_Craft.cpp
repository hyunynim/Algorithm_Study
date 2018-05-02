#include<iostream>
#include<algorithm>
#include<string.h>
#include<vector>
using namespace std;

#define MAX_SIZE 1005
int n, k, time[MAX_SIZE] = { 0 };
int cache[MAX_SIZE];
vector<int> pior[MAX_SIZE];

int FindFin(int fin) {
	int & ref = cache[fin];
	if (ref != -1) return ref;
	ref = time[fin];
	for (int i = 0; i < pior[fin].size(); ++i) {
			ref = max(ref, FindFin(pior[fin][i]) + time[fin]);
	}
	return ref;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		memset(cache, -1, sizeof(cache));
		memset(time, 0, sizeof(time));
		scanf("%d %d", &n, &k);
		
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &time[j]);
		}
		
		int a, b;
		for (int j = 0; j < k; ++j) {
			scanf("%d %d", &a, &b);
			pior[b].push_back(a);
		}
		int fin;
		scanf("%d", &fin);
		printf("%d\n", FindFin(fin));
		for (int i = 1; i <= n; ++i)
			pior[i].clear();
	}
}

/*comment*/
//시간초과
//vector이용해서 탐색횟수 최소화
//맞음