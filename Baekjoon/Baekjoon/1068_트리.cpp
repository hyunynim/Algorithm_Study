#include<stdio.h>
#include<queue>
#include<vector>
using namespace std;


int main() {
	vector<int> child[51];
	int parent[51] = { 0 };
	int n, tmp, start;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		if (tmp == -1) {
			start = i;
			continue;
		}
		parent[i] = tmp;
		child[tmp].push_back(i);
	}
	int jmp, res = 0;
	scanf("%d", &jmp);
	if (start == jmp) {
		printf("0");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < child[i].size(); ++j) {
			if (child[i][j] == jmp)
				child[i][j] = -1;
		}
	}
	queue <int> bfs;
	
	bfs.push(start);
	int cur;
	while (bfs.size()) {
		cur = bfs.front();
		bfs.pop();
		if (child[cur].size()) {
			for (int i = 0; i < child[cur].size(); ++i) {
				if (child[cur][i] == -1) {
					if (child[parent[jmp]].size() == 1)
						res++;
					continue;
				}
				bfs.push(child[cur][i]);
			}
		}
		else
			res++;
	}
	if (cur == start)
		printf("1");
	else
		printf("%d", res);
}

/*comment*/
//걍 틀려버림 갈아엎음 무식하게 풀자
//인접행렬로 바꿔보자 비트마스크 연습?
//시간초과 -> 무한루프에 빠지는 case가 있나?
//루트 == 리프인 경우 제외시킴
//비트마스크 쓰는경우 시간적 효율이 별로 안좋아보임 n번 다 찾아야해서
//동적배열 이용 
