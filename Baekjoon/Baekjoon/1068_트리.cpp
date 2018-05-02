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
//�� Ʋ������ ���ƾ��� �����ϰ� Ǯ��
//������ķ� �ٲ㺸�� ��Ʈ����ũ ����?
//�ð��ʰ� -> ���ѷ����� ������ case�� �ֳ�?
//��Ʈ == ������ ��� ���ܽ�Ŵ
//��Ʈ����ũ ���°�� �ð��� ȿ���� ���� �����ƺ��� n�� �� ã�ƾ��ؼ�
//�����迭 �̿� 
