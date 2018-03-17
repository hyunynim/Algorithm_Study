#include <iostream>
#include <queue>

using namespace std;

int main() {
	int t, dec;
	queue <int> bin;

	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &dec);
		int ind = 0;
		while (dec > 0) {
			bin.push(dec % 2);
			dec /= 2;
		}
		while (bin.size() != 0) {
			if (bin.front() == 1)
				printf("%d ", ind);
			bin.pop();
			ind++;
		}
	}
}

/*comment*/
//lsb�� ��ġ�� 0�̹Ƿ� stack���� queue���°� �����ҵ�