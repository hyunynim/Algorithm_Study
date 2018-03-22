#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, s, e, tmp;
	vector <int> num;
	vector <int> num_tmp;

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &s, &e);
		if (is_sorted(num.begin() + (s - 1), num.begin() + ((e - s) / 2))) {
			//정상이므로 뒤에 검사
			for (int i = e - 1; num.begin() + i != num.begin() + ((e - s) / 2 - 1); --i) {
				if (num.begin() + i != num.begin() + (e - 1 - i) + (s - 1))
				{
					printf("0\n");
					break;
				}
			}
			printf("1\n");
		}
		else
			printf("0\n");
		num_tmp.clear();
	}
}

/*comment*/
//+1인지 -1인지 체크해서 Up, Down 확인하여 풀어봤지만 시간초과
//sorted 상태인지 체크해서 풀어봤지만 제대로된 답이 안나옴
//갈아엎음
