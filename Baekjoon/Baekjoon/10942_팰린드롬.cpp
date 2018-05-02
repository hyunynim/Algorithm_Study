#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
int isPel(vector <int> * num, int start, int end);
int cache[2001][2001];

int main() {
	int n, m, s, e, tmp;
	for (int i = 0; i < 2001; ++i) {
		for (int j = 0; j < 2001; ++j)
			cache[i][j] = -1;
	}
	vector <int> num;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &tmp);
		num.push_back(tmp);
	}
	
	scanf("%d", &m);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &s, &e);
		s--; e--;
		if (isPel(&num, s, e))
			printf("1\n");
		else
			printf("0\n");
	}
	
}

int isPel(vector <int> * num, int start, int end) {
	if (cache[start][end] == -1) {
		if (start == end) {
			cache[start][end] = 1;
			return 1;
		}
		else if (end - start == 1) {
			if ((*num)[start] == (*num)[end]) {
				cache[start][end] = 1;
			}
			else
				cache[start][end] = 0;
		}
		else {
			if ((*num)[start] == (*num)[end]) {
				cache[start][end] = isPel(num, start + 1, end - 1);
			}
			else {
				cache[start][end] = 0;
				return 0;
			}
		}
	}
	return cache[start][end];
}
/*comment*/
//+1인지 -1인지 체크해서 Up, Down 확인하여 풀어봤지만 시간초과
//sorted 상태인지 체크해서 풀어봤지만 제대로된 답이 안나옴
//갈아엎음
//스택의 성질 이용해서 그냥 쌩으로 비교
//시간초과
//그냥 쌩으로 비교했는데 시간초과
//DP + memoization 방식으로 바꿔버리기
//시간초과
//end - start == 1 일때 서로 다를경우 case분류를 안해줬음