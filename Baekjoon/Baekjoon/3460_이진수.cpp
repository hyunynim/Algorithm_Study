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
//lsb의 위치가 0이므로 stack보다 queue쓰는게 적합할듯