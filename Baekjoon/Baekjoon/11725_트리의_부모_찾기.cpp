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
//�ʹ� �����ϰ� ���� �̰� �ƴҵ�
//Vector �����Ҵ� �̿��Ϸ� �غôµ� �޸��ʰ� ��� ���Ƽ� ���� ����
//�θ� �����ϴ� ������ ������� ������� �� ������ �ٲ㼭 ä����
//�� ����� �θ� ����� �θ� ���߿� �־��� ��� ���� ����
//���� �̿��ϴ°� ���?
//�θ� 1�ξֵ���� ä���ְ� ť �̿��ؼ� ���� �ֵ���
//���� ť���� �׳� BFS�� �Ǿ����
//�θ� �������� Ȯ�������� ������ ���� �����س��� �θ� Ȯ�������� ������
//�ð��ʰ�
//�������� �ɷ��� ���� �������ߴµ� �ȵǰ���. �׳� 0��ä�� �ΰ� Ž���� �� ������ �ϴ� �������
//linked list + vector�� ��� �Ƿ���? -> Ʈ�� ��������
//�� �����Ų���� �θ� ä���
//���ƾ���
//�޸� �ʰ� �� �� �˾Ҵµ� vector array�� �ذ�;