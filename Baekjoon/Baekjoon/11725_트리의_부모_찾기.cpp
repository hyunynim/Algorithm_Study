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
