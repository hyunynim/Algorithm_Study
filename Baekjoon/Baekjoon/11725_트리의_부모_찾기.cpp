#include <iostream>
#include <vector>

using namespace std;

void ch(int & a, int & b) {
	int tmp = a;
	a = b;
	b =tmp;
}

typedef struct Node {
	vector <Node> * child;
	int item;
	Node * parent;
} node;
int main() {
	int n;
	node head;
	
	head.item = 1;
	head.parent = NULL;

	scanf("%d", &n);
	int * num = new int[n + 2];
	for (int i = 0; i < n + 2; i++)
		num[i] = 0;
	num[1] = -1;

	int tmp1, tmp2;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d", &tmp1, &tmp2);
	}
	for (int i = 2; i <= n; i++)
		printf("%d\n", num[i]);
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
