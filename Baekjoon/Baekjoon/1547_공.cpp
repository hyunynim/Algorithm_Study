#include <iostream>

void ch(int & a, int & b) {
	int tmp = a;
	a = b;
	b = tmp;
}

int main() {
	int m;
	int a, b, cup[4] = { 0, 1, 2, 3 }, whereCup[4] = { 0, 1, 2, 3 };
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		ch(cup[whereCup[a]], cup[whereCup[b]]);
		ch(whereCup[a], whereCup[b]);
	}
	printf("%d", cup[1]);
}

/*comment*/
//컵의 위치를 따로 저장해줘야 했음