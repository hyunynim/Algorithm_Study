#include<cstdio>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

vector<int> child[100001];
int parent[100001] = { 0 };
bool isChecked[100001] = { 0 };
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int a, b;
		scanf("%d %d", &a, &b);
		child[a].push_back(b);
		child[b].push_back(a);
	}
	queue<pair<int, int>> bfs;
	for (int i = 0; i < child[1].size(); ++i) {
		bfs.push(make_pair(1, child[1][i]));
	}
	int cur;
	while (bfs.size()) {
		cur = bfs.front().second;
		parent[cur] = bfs.front().first;
		isChecked[cur] = 1;
		bfs.pop();
		for (int i = 0; i < child[cur].size(); ++i) {
			if (isChecked[child[cur][i]]);
			else
				bfs.push(make_pair(cur, child[cur][i]));
		}
	}
	for (int i = 2; i <= n; ++i)
		printf("%d\n", parent[i]);
}

/*commnet*/
//너무 만만하게 봤음 이거 아닐듯
//Vector 동적할당 이용하려 해봤는데 메모리초과 뜰것 같아서 갈아 엎음
//부모를 저장하는 공간이 비어있지 않은경우 두 변수를 바꿔서 채워봄
//한 노드의 부모 노드의 부모가 나중에 주어질 경우 문제 생김
//정렬 이용하는건 어떨까?
//부모가 1인애들부터 채워넣고 큐 이용해서 쭉쭉 넣도록
//ㄴㄴ 큐쓰면 그냥 BFS가 되어버림
//부모가 누구인지 확실해지기 전까지 서로 연결해놓고 부모가 확실해지면 재조정
//시간초과
//같아진놈만 걸러서 따로 빼보려했는데 안되겠음. 그냥 0인채로 두고 탐색을 더 빠르게 하는 방법으로
//linked list + vector로 어떻게 되려나? -> 트리 직접구현
//쭉 연결시킨다음 부모 채우기
//갈아엎자
//메모리 초과 뜰 줄 알았는데 vector array로 해결;